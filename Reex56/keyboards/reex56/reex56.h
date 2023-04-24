/*
Copyright 2021 @Yowkees
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

#include "quantum.h"
#include "lib/reex/reex.h"

// clang-format off

#define LAYOUT( \
        L00, L01, L02, L03, L10, L11,           R00, R01, R02, R03, R10, R11, \
        L12, L13, L20, L21, L22, L23,           R12, R13, R20, R21, R22, R23, \
        L30, L31, L32, L33, L40, L41,           R30, R31, R32, R33, R40, R41, \
        L42, L50, L51, L52, L53, L60,           R42, R50, R51, R52, R53, R60, \
        L61, L62, L63,           L70,           R61,           R62, R63, R70  \
    ) \
    { \
        { L00,   L01,   L02,   L03,   L50,   L51,   L52,   L53 },   \
        { L10,   L11,   L12,   L13,   L60,   L61,   L62,   L63 },   \
        { L20,   L21,   L22,   L23,   L70,   KC_NO, KC_NO, KC_NO },   \
        { L30,   L31,   L32,   L33,   KC_NO, KC_NO, KC_NO, KC_NO },   \
        { L40,   L41,   L42,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
        { R00,   R01,   R02,   R03,   R50,   R51,   R52,   R53 },   \
        { R10,   R11,   R12,   R13,   R60,   R61,   R62,   R63 },   \
        { R20,   R21,   R22,   R23,   R70,   KC_NO, KC_NO, KC_NO }, \
        { R30,   R31,   R32,   R33,   KC_NO, KC_NO, KC_NO, KC_NO }, \
        { R40,   R41,   R42,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
    }

