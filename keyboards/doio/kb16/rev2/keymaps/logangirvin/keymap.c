/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// OLED animation
#include "./lib/bongocat/bongocat.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _FN,
    _FN1,
    _FN2
};

// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* choose your own key bindings per program
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ 1 │ 2 │ 3 │ 4 │   │Ply│ │TO1│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ 5 │ 6 │ 7 │ 8 │
       ├───┼───┼───┼───┤
       │ 9 │ 10│ 11│ 12│      ┌───┐
       ├───┼───┼───┼───┤      │Mut│
       │ 13│ 14│ 15│ 16│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0                         1                         2                         3                         4      */
    [_BASE] = LAYOUT(
                PROGRAMMABLE_BUTTON_1,    PROGRAMMABLE_BUTTON_2,    PROGRAMMABLE_BUTTON_3,    PROGRAMMABLE_BUTTON_4,     KC_MPLY,
                PROGRAMMABLE_BUTTON_5,    PROGRAMMABLE_BUTTON_6,    PROGRAMMABLE_BUTTON_7,    PROGRAMMABLE_BUTTON_8,     TO(_FN),
                PROGRAMMABLE_BUTTON_9,    PROGRAMMABLE_BUTTON_10,   PROGRAMMABLE_BUTTON_11,   PROGRAMMABLE_BUTTON_12,    KC_MUTE,
                PROGRAMMABLE_BUTTON_13,   PROGRAMMABLE_BUTTON_14,   PROGRAMMABLE_BUTTON_15,   PROGRAMMABLE_BUTTON_16
            ),

/* Emulates left hand gaming
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │esc│ 1 │ 2 │ 3 │   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ tb│ Q │ W │ E │
       ├───┼───┼───┼───┤
       │ R │ A │ S │ D │      ┌───┐
       ├───┼───┼───┼───┤      │ ` │
       │ sf│ sf│ sp│ sp│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4       */
    [_FN] = LAYOUT(
                KC_ESCAPE, KC_1, KC_2, KC_3, KC_TRNS,
                KC_TAB, KC_Q, KC_W, KC_E, TO(_FN1),
                KC_R, KC_A, KC_S, KC_D, KC_GRAVE,
                KC_LEFT_SHIFT, KC_LEFT_SHIFT, KC_SPACE, KC_SPACE
            ),

/* Telework shortcuts (SAD)
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ Ec│ Ec│ V │ A │   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ D │   │   │   │
       ├───┼───┼───┼───┤
       │   │   │   │ H │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │   │ Tv│ M │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4       */
    [_FN1] = LAYOUT(
                RCS(KC_H), RCS(KC_H), RCS(KC_U), RCS(KC_S), KC_TRNS,
                RCS(KC_D), _______, _______, _______, TO(_FN2),
                _______, _______, _______, RCS(KC_K), KC_MUTE,
                _______, _______, RCS(KC_O), RCS(KC_M)
            ),

/*
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │Spi│Spd│   │   │   │   │ │TO0│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │Sai│Sad│   │   │
       ├───┼───┼───┼───┤
       │Tog│Mod│Hui│   │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │Vai│Hud│Vad│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4        */
    [_FN2] = LAYOUT(
                RGB_SPI, RGB_SPD, _______, QK_BOOT, KC_TRNS,
                RGB_SAI, RGB_SAD, _______, _______, TO(_BASE),
                RGB_TOG, RGB_MOD, RGB_HUI, _______, KC_TRNS,
                _______, RGB_VAI, RGB_HUD, RGB_VAD
            ),
};

void keyboard_post_init_user(void) {
  // Call the post init code.
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_enable_noeeprom(); // enables Rgb, without saving settings
  rgb_matrix_mode_noeeprom(2); // 1 = static
#endif
}


#ifdef OLED_ENABLE
    uint8_t last_mode = 1;
    bool oled_task_user(void) {
        switch (biton32(layer_state)) {
            case _BASE:
                if (last_mode != _BASE) {
                    last_mode = _BASE;
                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("Macros"), false);
                    oled_render();
                }
                break;
            case _FN:
                render_bongocat();
                break;
            case _FN1:
                if (last_mode != _FN1) {
                    last_mode = _FN1;
                    oled_clear();
                    oled_set_cursor(28, 0);
                    oled_write_P(PSTR("Calls"), false);
                    oled_render();
                }
                break;
            case _FN2:
                if (last_mode != _FN2) {
                    last_mode = _FN2;
                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("Lights"), false);
                    oled_render();
                }
                break;
            default:
        }
        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_FN]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN1]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN2]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
