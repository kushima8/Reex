#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>

#define FN  MO(1)

enum custom_keycodes {
    KC_MY_BTN1 = SAFE_RANGE,
    KC_MY_BTN2,
    KC_MY_BTN3,
    KC_MY_SCR,
    KC_TO_CLICKABLE_INC,
    KC_TO_CLICKABLE_DEC,
    KC_SCROLL_DIR_V,
    KC_SCROLL_DIR_H,
};


enum click_state {
    NONE = 0,
    WAITING,    // �}�E�X���C���[���L���ɂȂ�̂�҂B Wait for mouse layer to activate.
    CLICKABLE,  // �}�E�X���C���[�L���ɂȂ�N���b�N���͂�����B Mouse layer is enabled to take click input.
    CLICKING,   // �N���b�N���B Clicking.
    SCROLLING   // �X�N���[�����B Scrolling.
};

typedef union {
  uint32_t raw;
  struct {
    // int16_t to_clickable_time; // // ���̕b��(�番�̈�b)�AWAITING��ԂȂ�N���b�N���C���[���L���ɂȂ�B  For this number of seconds (milliseconds), if in WAITING state, the click layer is activated.
    int16_t to_clickable_movement;
    bool mouse_scroll_v_reverse;
    bool mouse_scroll_h_reverse;
  };
} user_config_t;

user_config_t user_config;

enum click_state state;     // ���݂̃N���b�N���͎�t�̏�� Current click input reception status
uint16_t click_timer;       // �^�C�}�[�B��Ԃɉ����Ď��ԂŔ��肷��B Timer. Time to determine the state of the system.

// uint16_t to_clickable_time = 50;   // ���̕b��(�番�̈�b)�AWAITING��ԂȂ�N���b�N���C���[���L���ɂȂ�B  For this number of seconds (milliseconds), if in WAITING state, the click layer is activated.
uint16_t to_reset_time = 1000; // ���̕b��(�番�̈�b)�ACLICKABLE��ԂȂ�N���b�N���C���[�������ɂȂ�B For this number of seconds (milliseconds), the click layer is disabled if in CLICKABLE state.

const uint16_t click_layer = 2;   // �}�E�X���͂��\�ɂȂ����ۂɗL���ɂȂ郌�C���[�BLayers enabled when mouse input is enabled

int16_t scroll_v_mouse_interval_counter;   // �����X�N���[���̓��͂��J�E���g����B�@Counting Vertical Scroll Inputs
int16_t scroll_h_mouse_interval_counter;   // �����X�N���[���̓��͂��J�E���g����B  Counts horizontal scrolling inputs.

int16_t scroll_v_threshold = 50;    // ����臒l�𒴂���x�ɐ����X�N���[�������s�����B Vertical scrolling is performed each time this threshold is exceeded.
int16_t scroll_h_threshold = 50;    // ����臒l�𒴂���x�ɐ����X�N���[�������s�����B Each time this threshold is exceeded, horizontal scrolling is performed.

int16_t after_click_lock_movement = 0;      // �N���b�N���͌�̈ړ��ʂ𑪒肷��ϐ��B Variable that measures the amount of movement after a click input.

int16_t mouse_record_threshold = 30;    // �|�C���^�[�̓������ꎞ�I�ɋL�^����t���[�����B Number of frames in which the pointer movement is temporarily recorded.
int16_t mouse_move_count_ratio = 5;     // �|�C���^�[�̓������Đ�����ۂ̈ړ��t���[���̌W���B The coefficient of the moving frame when replaying the pointer movement.

const uint16_t ignore_disable_mouse_layer_keys[] = {KC_LGUI, KC_LCTL};   // ���̔z��Ŏw�肳�ꂽ�L�[�̓}�E�X���C���[���ɉ������Ă��}�E�X���C���[���������Ȃ�

int16_t mouse_movement;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    // ,--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------.
        KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,         KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_RSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,SFT_T(KC_ENT),
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_LCTL ,FN      ,KC_LALT                   ,KC_SPC  ,         KC_SPC                    ,KC_RALT ,KC_RGUI ,FN
    // `--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+---------------------'
    ),
    [1] = LAYOUT(
    // ,--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------.
        KC_TRNS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,         KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_F12  ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,RGB_TOG ,RGB_HUI ,RGB_SAI ,RGB_VAI ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,RGB_MOD ,RGB_HUD ,RGB_SAD ,RGB_VAD,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_TRNS ,KC_TRNS ,KC_TRNS                   ,KC_TRNS ,         KC_TRNS                   ,KC_TRNS ,KC_TRNS ,KC_TRNS
    // `--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------'
    ),
    [2] = LAYOUT(
    // ,-------------------+-------------------+----------+----------+--------+--------|        |--------+--------+----------+----------+-------------------+--------------------.
        KC_TRNS            ,KC_TRNS            ,KC_TRNS   ,KC_TRNS   ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,KC_TRNS   ,KC_TRNS   ,KC_TRNS            ,KC_TRNS             ,
    // |-------------------+-------------------+----------+----------+--------+--------|        |--------+--------+----------+----------+-------------------+--------------------|
        KC_TRNS            ,KC_TRNS            ,KC_TRNS   ,KC_TRNS   ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,KC_TRNS   ,KC_TRNS   ,KC_TRNS            ,KC_TRNS             ,
    // |-------------------+-------------------+----------+----------+--------+--------|        |--------+--------+----------+----------+-------------------+--------------------|
        KC_TRNS            ,KC_TRNS            ,KC_TRNS   ,KC_TRNS   ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,KC_MY_BTN1,KC_MY_BTN2,KC_MY_SCR          ,KC_TRNS             ,
    // |-------------------+-------------------+----------+----------+--------+--------|        |--------+--------+----------+----------+-------------------+--------------------|
        KC_TRNS            ,KC_TRNS            ,KC_TRNS   ,KC_TRNS   ,KC_TRNS ,KC_TRNS ,         KC_TRNS ,KC_TRNS ,KC_TRNS   ,KC_TRNS   ,KC_SCROLL_DIR_V    ,KC_SCROLL_DIR_H     ,
    // |-------------------+-------------------+----------+----------+--------+--------|        |--------+--------+----------+----------+-------------------+--------------------|
        KC_TRNS            ,KC_TRNS            ,KC_TRNS                       ,KC_TRNS ,         KC_TRNS                     ,KC_TRNS   ,KC_TO_CLICKABLE_INC,KC_TO_CLICKABLE_DEC
    // `-------------------+-------------------+----------+----------+--------+--------|        |--------+--------+----------+----------+-------------------+--------------------'
    ),
    [3] = LAYOUT(
    // ,--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------.
        KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,         KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,         KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_RSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,SFT_T(KC_ENT),
    // |--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+-------------|
        KC_LCTL ,KC_TRNS ,KC_LALT                   ,KC_SPC  ,         KC_SPC                    ,KC_RALT ,KC_RGUI ,KC_TRNS
    // `--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+---------------------'
    )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    reex_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    reex_oled_render_keyinfo();
    reex_oled_render_ballinfo();
}
#endif

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.to_clickable_movement = 50;
    user_config.mouse_scroll_v_reverse = false;
    user_config.mouse_scroll_h_reverse = false;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

// �N���b�N�p�̃��C���[��L���ɂ���B�@Enable layers for clicks
void enable_click_layer(void) {
    layer_on(click_layer);
    click_timer = timer_read();
    state = CLICKABLE;
}

// �N���b�N�p�̃��C���[�𖳌��ɂ���B Disable layers for clicks.
void disable_click_layer(void) {
    state = NONE;
    layer_off(click_layer);
    scroll_v_mouse_interval_counter = 0;
    scroll_h_mouse_interval_counter = 0;
}

// ���O�̐�ΐ���Ԃ��֐��B Functions that return absolute numbers.
int16_t my_abs(int16_t num) {
    if (num < 0) {
        num = -num;
    }

    return num;
}

// ���O�̕�����Ԃ��֐��B Function to return the sign.
int16_t mmouse_move_y_sign(int16_t num) {
    if (num < 0) {
        return -1;
    }

    return 1;
}

// ���݃N���b�N���\�ȏ�Ԃ��B Is it currently clickable?
bool is_clickable_mode(void) {
    return state == CLICKABLE || state == CLICKING || state == SCROLLING;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    switch (keycode) {
        case KC_MY_BTN1:
        case KC_MY_BTN2:
        case KC_MY_BTN3:
        {
            report_mouse_t currentReport = pointing_device_get_report();

            // �ǂ��̃r�b�g��Ώۂɂ��邩�B Which bits are to be targeted?
            uint8_t btn = 1 << (keycode - KC_MY_BTN1);
            
            if (record->event.pressed) {
                // �r�b�gOR�͉��Z�q�̍��ӂƉE�ӂ̓����ʒu�ɂ���r�b�g���r���āA�����̃r�b�g�̂ǂ��炩���u1�v�̏ꍇ�Ɂu1�v�ɂ��܂��B
                // Bit OR compares bits in the same position on the left and right sides of the operator and sets them to "1" if either of both bits is "1".
                currentReport.buttons |= btn;
                state = CLICKING;
                after_click_lock_movement = 30;
            } else {
                // �r�b�gAND�͉��Z�q�̍��ӂƉE�ӂ̓����ʒu�ɂ���r�b�g���r���āA�����̃r�b�g�����Ɂu1�v�̏ꍇ�����u1�v�ɂ��܂��B
                // Bit AND compares the bits in the same position on the left and right sides of the operator and sets them to "1" only if both bits are "1" together.
                currentReport.buttons &= ~btn;
            }

            enable_click_layer();

            pointing_device_set_report(currentReport);
            pointing_device_send();
            return false;
        }

        case KC_MY_SCR:
            if (record->event.pressed) {
                state = SCROLLING;
            } else {
                enable_click_layer();   // �X�N���[���L�[�𗣂������ɍēx�N���b�N���C���[��L���ɂ���B Enable click layer again when the scroll key is released.
            }
         return false;
        
        case KC_TO_CLICKABLE_INC:
            if (record->event.pressed) {
                user_config.to_clickable_movement += 5; // user_config.to_clickable_time += 10;
                eeconfig_update_user(user_config.raw);
            }
            return false;

        case KC_TO_CLICKABLE_DEC:
            if (record->event.pressed) {

                user_config.to_clickable_movement -= 5; // user_config.to_clickable_time -= 10;

                if (user_config.to_clickable_movement < 5)
                {
                    user_config.to_clickable_movement = 5;
                }

                // if (user_config.to_clickable_time < 10) {
                //     user_config.to_clickable_time = 10;
                // }

                eeconfig_update_user(user_config.raw);
            }
            return false;
        
        case KC_SCROLL_DIR_V:
            if (record->event.pressed) {
                user_config.mouse_scroll_v_reverse = !user_config.mouse_scroll_v_reverse;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        
        case KC_SCROLL_DIR_H:
            if (record->event.pressed) {
                user_config.mouse_scroll_h_reverse = !user_config.mouse_scroll_h_reverse;
                eeconfig_update_user(user_config.raw);
            }
            return false;

         default:
            if  (record->event.pressed) {
                
                if (state == CLICKING || state == SCROLLING)
                {
                    enable_click_layer();
                    return false;
                }
                
                for (int i = 0; i < sizeof(ignore_disable_mouse_layer_keys) / sizeof(ignore_disable_mouse_layer_keys[0]); i++)
                {
                    if (keycode == ignore_disable_mouse_layer_keys[i])
                    {
                        enable_click_layer();
                        return true;
                    }
                }

                disable_click_layer();
            }
        
    }
   
    return true;
}


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int16_t current_x = mouse_report.x;
    int16_t current_y = mouse_report.y;
    int16_t current_h = 0;
    int16_t current_v = 0;

    if (current_x != 0 || current_y != 0) {
        
        switch (state) {
            case CLICKABLE:
                click_timer = timer_read();
                break;

            case CLICKING:
                after_click_lock_movement -= my_abs(current_x) + my_abs(current_y);

                if (after_click_lock_movement > 0) {
                    current_x = 0;
                    current_y = 0;
                }

                break;

            case SCROLLING:
            {
                int8_t rep_v = 0;
                int8_t rep_h = 0;

                // �����X�N���[���̕��̊��x�����߂�B Increase sensitivity toward vertical scrolling.
                if (my_abs(current_y) * 2 > my_abs(current_x)) {

                    scroll_v_mouse_interval_counter += current_y;
                    while (my_abs(scroll_v_mouse_interval_counter) > scroll_v_threshold) {
                        if (scroll_v_mouse_interval_counter < 0) {
                            scroll_v_mouse_interval_counter += scroll_v_threshold;
                            rep_v += scroll_v_threshold;
                        } else {
                            scroll_v_mouse_interval_counter -= scroll_v_threshold;
                            rep_v -= scroll_v_threshold;
                        }
                        
                    }
                } else {

                    scroll_h_mouse_interval_counter += current_x;

                    while (my_abs(scroll_h_mouse_interval_counter) > scroll_h_threshold) {
                        if (scroll_h_mouse_interval_counter < 0) {
                            scroll_h_mouse_interval_counter += scroll_h_threshold;
                            rep_h += scroll_h_threshold;
                        } else {
                            scroll_h_mouse_interval_counter -= scroll_h_threshold;
                            rep_h -= scroll_h_threshold;
                        }
                    }
                }

                current_h = rep_h / scroll_h_threshold * (user_config.mouse_scroll_h_reverse ? -1 : 1);
                current_v = -rep_v / scroll_v_threshold * (user_config.mouse_scroll_v_reverse ? -1 : 1);
                current_x = 0;
                current_y = 0;
            }
                break;

            case WAITING:
                /*
                if (timer_elapsed(click_timer) > user_config.to_clickable_time) {
                    enable_click_layer();
                }
                */

                mouse_movement += my_abs(current_x) + my_abs(current_y);

                if (mouse_movement >= user_config.to_clickable_movement)
                {
                    mouse_movement = 0;
                    enable_click_layer();
                }
                break;

            default:
                click_timer = timer_read();
                state = WAITING;
                mouse_movement = 0;
        }
    }
    else
    {
        switch (state) {
            case CLICKING:
            case SCROLLING:

                break;

            case CLICKABLE:
                if (timer_elapsed(click_timer) > to_reset_time) {
                    disable_click_layer();
                }
                break;

             case WAITING:
                if (timer_elapsed(click_timer) > 50) {
                    mouse_movement = 0;
                    state = NONE;
                }
                break;

            default:
                mouse_movement = 0;
                state = NONE;
        }
    }

    mouse_report.x = current_x;
    mouse_report.y = current_y;
    mouse_report.h = current_h;
    mouse_report.v = current_v;

    return mouse_report;
}

