/*
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//////////////////////////////////////////////////////////////////////////////
// Configurations

#ifndef REEX_CPI_DEFAULT
#    define REEX_CPI_DEFAULT 500
#endif

#ifndef REEX_SCROLL_DIV_DEFAULT
#    define REEX_SCROLL_DIV_DEFAULT 4 // 4: 1/8 (1/2^(n-1))
#endif

#ifndef REEX_REPORTMOUSE_INTERVAL
#    define REEX_REPORTMOUSE_INTERVAL 8 // mouse report rate: 125Hz
#endif

#ifndef REEX_SCROLLBALL_INHIVITOR
#    define REEX_SCROLLBALL_INHIVITOR 50
#endif

#ifndef REEX_SCROLLSNAP_ENABLE
#    define REEX_SCROLLSNAP_ENABLE 1
#endif

#ifndef REEX_SCROLLSNAP_RESET_TIMER
#    define REEX_SCROLLSNAP_RESET_TIMER 100
#endif

#ifndef REEX_SCROLLSNAP_TENSION_THRESHOLD
#    define REEX_SCROLLSNAP_TENSION_THRESHOLD 12
#endif

//////////////////////////////////////////////////////////////////////////////
// Constants

#define REEX_TX_GETINFO_INTERVAL 500
#define REEX_TX_GETINFO_MAXTRY 10
#define REEX_TX_GETMOTION_INTERVAL 4


//////////////////////////////////////////////////////////////////////////////
// Types

enum reex_keycodes {
    KBC_RST = SAFE_RANGE, // Reex configuration: reset to default
    KBC_SAVE,             // Reex configuration: save to EEPROM

    CPI_I100, // CPI +100 CPI
    CPI_D100, // CPI -100 CPI
    CPI_I1K,  // CPI +1000 CPI
    CPI_D1K,  // CPI -1000 CPI

    // In scroll mode, motion from primary trackball is treated as scroll
    // wheel.
    SCRL_TO,  // Toggle scroll mode
    SCRL_MO,  // Momentary scroll mode
    SCRL_DVI, // Increment scroll divider
    SCRL_DVD, // Decrement scroll divider

    REEX_SAFE_RANGE,
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi : 7;
        uint8_t sdiv : 3; // scroll divider
    };
} reex_config_t;

typedef struct {
    uint8_t ballcnt; // count of balls: support only 0 or 1, for now
} reex_info_t;

typedef struct {
    int16_t x;
    int16_t y;
} reex_motion_t;

typedef uint8_t reex_cpi_t;

typedef struct {
    bool this_have_ball;
    bool that_enable;
    bool that_have_ball;

    reex_motion_t this_motion;
    reex_motion_t that_motion;

    uint8_t cpi_value;
    bool    cpi_changed;

    bool     scroll_mode;
    uint32_t scroll_mode_changed;
    uint8_t  scroll_div;

    uint32_t scroll_snap_last;
    int8_t   scroll_snap_tension_h;

    uint16_t       last_kc;
    keypos_t       last_pos;
    report_mouse_t last_mouse;
} reex_t;

typedef enum {
    REEX_ADJUST_PENDING   = 0,
    REEX_ADJUST_PRIMARY   = 1,
    REEX_ADJUST_SECONDARY = 2,
} reex_adjust_t;

//////////////////////////////////////////////////////////////////////////////
// Exported values (touch carefully)

extern reex_t reex;

//////////////////////////////////////////////////////////////////////////////
// Public API functions

/// reex_oled_render_ballinfo renders ball information to OLED.
/// It uses just 21 columns to show the info.
void reex_oled_render_ballinfo(void);

/// reex_oled_render_keyinfo renders last processed key information to OLED.
/// It shows column, row, key code, and key name (if available).
void reex_oled_render_keyinfo(void);

/// reex_get_scroll_mode gets current scroll mode.
bool reex_get_scroll_mode(void);

/// reex_set_scroll_mode modify scroll mode.
void reex_set_scroll_mode(bool mode);

// TODO: document
uint8_t reex_get_scroll_div(void);

// TODO: document
void reex_set_scroll_div(uint8_t div);

// TODO: document
uint8_t reex_get_cpi(void);

// TODO: document
void reex_set_cpi(uint8_t cpi);
