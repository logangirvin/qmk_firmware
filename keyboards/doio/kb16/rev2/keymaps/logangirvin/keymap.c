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
    MUSIC,
    KRITA,
    GAME,
    CALL,
    CODE
};

enum my_keycodes {
  GO_HOME = SAFE_RANGE,
  GO_EXPLORE,
  GO_LIBRARY,
  GO_SETTINGS
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
                PROGRAMMABLE_BUTTON_5,    PROGRAMMABLE_BUTTON_6,    PROGRAMMABLE_BUTTON_7,    PROGRAMMABLE_BUTTON_8,     TO(MUSIC),
                PROGRAMMABLE_BUTTON_9,    PROGRAMMABLE_BUTTON_10,   PROGRAMMABLE_BUTTON_11,   PROGRAMMABLE_BUTTON_12,    KC_MUTE,
                PROGRAMMABLE_BUTTON_13,   PROGRAMMABLE_BUTTON_14,   PROGRAMMABLE_BUTTON_15,   PROGRAMMABLE_BUTTON_16
            ),

/* choose your own key bindings per program
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ k │ ; │ j │ + │   │Ply│ │TO1│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ m │ s │ r │   │
       ├───┼───┼───┼───┤
       │ f │ q │   │   │      ┌───┐
       ├───┼───┼───┼───┤      │Mut│
       │ gh│ ge│ gl│ g.│      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0                         1                         2                         3                         4      */
    [MUSIC] = LAYOUT(
                KC_K,    KC_SEMICOLON,    KC_J,    KC_PLUS,     KC_MPLY,
                KC_M,    KC_S,    KC_R,    XXXXXXX,     TO(KRITA),
                KC_F,    KC_Q,   XXXXXXX,   XXXXXXX,    KC_MUTE,
                GO_HOME,   GO_EXPLORE,   GO_LIBRARY,   GO_SETTINGS
            ),

/* choose your own key bindings per program
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ca0│ca1│ca2│ca3│   │Ply│ │whl│ zoom
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ m │c0 │csz│cz │
       ├───┼───┼───┼───┤
       │csa│ch │ l │ p │      ┌───┐
       ├───┼───┼───┼───┤      │456│ rotate canvas
       │ e │ ct│ t │ b │      └───┘ hold canvas
       └───┴───┴───┴───┘
*/
    /*  Row:    0                         1                         2                         3                         4      */
    [KRITA] = LAYOUT(
                LCA(KC_0),    LCA(KC_1),    LCA(KC_2),    LCA(KC_3),     KC_MPLY,
                KC_M,    LCTL(KC_0),    RCS(KC_Z),   LCTL(KC_Z),     TO(GAME),
                RCS(KC_A),    LCTL(KC_H),   KC_L,   KC_P,    KC_SPACE,
                KC_E,   LCTL(KC_T),   KC_T,   KC_B
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
    [GAME] = LAYOUT(
                KC_ESCAPE, KC_1, KC_2, KC_3, KC_TRNS,
                KC_TAB, KC_Q, KC_W, KC_E, TO(CALL),
                KC_R, KC_A, KC_S, KC_D, KC_GRAVE,
                KC_LEFT_SHIFT, KC_LEFT_SHIFT, KC_SPACE, KC_SPACE
            ),

/* Telework shortcuts (SAD)
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ Ec│ Ec│ V │ A │   │   │ │   │
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ D │   │   │   │
       ├───┼───┼───┼───┤
       │s+`│   │   │ H │      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │s+t│   │ Tv│ M │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4       */
    [CALL] = LAYOUT(
                RCS(KC_H), RCS(KC_H), RCS(KC_U), RCS(KC_S), KC_TRNS,
                RCS(KC_D), _______, _______, _______, TO(CODE),
                LSFT(KC_GRAVE), _______, _______, RCS(KC_K), KC_MUTE,
                LSFT(KC_TAB), _______, RCS(KC_O), RCS(KC_M)
            ),

/*
    //    ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
    //    │Spi│Spd│   │   │   │   │ │TO0│
    //    ├───┼───┼───┼───┤   └───┘ └───┘
    //    │Sai│Sad│   │   │
    //    ├───┼───┼───┼───┤
    //    │Tog│Mod│Hui│   │      ┌───┐
    //    ├───┼───┼───┼───┤      │   │
    //    │   │Vai│Hud│Vad│      └───┘
    //    └───┴───┴───┴───┘
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │dbg│stp│ re│flh│   │Ply│ │TO0│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │   │   │   │   │
       ├───┼───┼───┼───┤
       │cnt│ovr│ in│out│      ┌───┐
       ├───┼───┼───┼───┤      │   │
       │   │   │   │   │      └───┘
       └───┴───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4        */
    [CODE] = LAYOUT(
                // RGB_SPI, RGB_SPD, _______, QK_BOOT, KC_TRNS,
                // RGB_SAI, RGB_SAD, _______, _______, TO(_BASE),
                // RGB_TOG, RGB_MOD, RGB_HUI, _______, KC_TRNS,
                // _______, RGB_VAI, RGB_HUD, RGB_VAD

                KC_F5, LSFT(KC_F5), RCS(KC_F5), QK_BOOT, KC_TRNS,
                _______, _______, _______, _______, TO(_BASE),
                KC_F5, KC_F10, KC_F11, LSFT(KC_F11), KC_TRNS,
                _______, _______, _______, _______
            ),
};

void keyboard_post_init_user(void) {
  // Call the post init code.
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_enable_noeeprom(); // enables Rgb, without saving settings
  rgb_matrix_mode_noeeprom(2); // 1 = static
#endif
}

static bool debug = false;
static bool last_debug = false;

static uint8_t led_value = 0;
static uint8_t pulse_delta = 1;
static uint8_t wait = 0;

#ifdef OLED_ENABLE
    uint8_t last_mode = 1;
    bool oled_task_user(void) {
        if (led_value == 255) {
            pulse_delta = -1;
        } else if (led_value == 0) {
            pulse_delta = 1;
        }
        wait += 1;
        if (wait % 16 == 0) {
            led_value += pulse_delta;
            wait = 0;
        }
        switch (biton32(layer_state)) {
            case _BASE:
                if (last_mode != _BASE) {
                    last_mode = _BASE;
                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("Macros"), false);
                    oled_render();
                    rgb_matrix_mode(2);
                }
                break;
            case MUSIC:
                if (last_mode != MUSIC) {
                    last_mode = MUSIC;
                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("Music"), false);
                    oled_render();
                }
                break;
            case KRITA:
                if (last_mode != KRITA) {
                    last_mode = KRITA;
                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("Krita"), false);
                    oled_render();
                }
                break;
            case GAME:
                if (last_mode != GAME) {
                    last_mode = GAME;

                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("Gayme"), false);
                    oled_render();
                    rgb_matrix_mode(RGB_MATRIX_CUSTOM_gaming);

                }
                // render_bongocat();
                break;
            case CALL:
                if (last_mode != CALL) {
                    last_mode = CALL;
                    oled_clear();
                    oled_set_cursor(28, 0);
                    oled_write_P(PSTR("Calls"), false);
                    oled_render();
                    rgb_matrix_mode(RGB_MATRIX_CUSTOM_chatting);
                }
                break;
            case CODE:
                if (last_mode != CODE) {
                    last_mode = CODE;
                    oled_clear();
                    oled_set_cursor(27, 0);
                    oled_write_P(PSTR("code"), false);
                    oled_render();
                    rgb_matrix_mode(RGB_MATRIX_CUSTOM_none);
                    
                    for (uint8_t i = 0; i < 16; i++) {
                        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
                    }
                } else if (debug != last_debug) {
                    last_debug = debug;
                    if (debug) {
                        rgb_matrix_set_color(0, 0x00, 0x00, 0x00);
                        rgb_matrix_set_color(1, 0xff, 0x00, 0x00);
                        rgb_matrix_set_color(2, 0xff, 0xff, 0x00);
                        rgb_matrix_set_color(3, 0x00, 0x00, 0x00);

                        rgb_matrix_set_color(8, 0x00, led_value, 0x00);
                        rgb_matrix_set_color(9, led_value, led_value, 0x00);
                        rgb_matrix_set_color(10, 0x00, 0x00, led_value);
                        rgb_matrix_set_color(11, 0x88, 0x88, 0x88);
                    } else {
                        rgb_matrix_set_color(0, 0x00, 0xff, 0x00);
                        rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
                        rgb_matrix_set_color(2, 0x00, 0x00, 0x00);
                        rgb_matrix_set_color(3, 0x00, 0x00, 0x00);

                        rgb_matrix_set_color(8, 0x00, 0x00, 0x00);
                        rgb_matrix_set_color(9, 0x00, 0x00, 0x00);
                        rgb_matrix_set_color(10, 0x00, 0x00, 0x00);
                        rgb_matrix_set_color(11, 0x00, 0x00, 0x00);
                    }
                } else if (debug) {
                    rgb_matrix_set_color(8, 0x00, led_value, 0x00);
                    rgb_matrix_set_color(9, led_value, led_value, 0x00);
                    rgb_matrix_set_color(10, 0x00, 0x00, led_value);
                    rgb_matrix_set_color(11, led_value / 2, led_value / 2, led_value / 2);
                }
                break;
            default:
        }
        return true;
    }
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F5:
        case LSFT(KC_F5):
            if (record->event.pressed) {
                // toggle mute
                debug = !debug;
            } else {
                // Do something else when release
            }
            return true;
        case GO_HOME:
            SEND_STRING("gh");
            return false;
        case GO_EXPLORE:
            SEND_STRING("ge");
            return false;
        case GO_LIBRARY:
            SEND_STRING("gl");
            return false;
        case GO_SETTINGS:
            SEND_STRING("g.");
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MUSIC] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [KRITA] = { ENCODER_CCW_CW(KC_LEFT_BRACKET, KC_RIGHT_BRACKET), ENCODER_CCW_CW(KC_EQUAL, KC_MINUS), ENCODER_CCW_CW(KC_4, KC_6) }, 
    [GAME]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [CALL]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [CODE]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
