/* Copyright 2019 raidzero
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

#define _______ KC_TRNS
#define x_____x KC_NO

#define SPCFN   LT(_NUMERIC, KC_SPC)    // function keys, numpad

#define RSFTT   RSFT_T(KC_ENT)          // shift on hold, enter on tap
#define TABW    LGUI_T(KC_TAB)          // win on hold, tab on tap
#define ESCW    LGUI_T(KC_ESC)          // win on hold, esc on tap

#define LOWER   TT(_LOWER)              // tap toggle lower
#define RAISE   TT(_RAISE)              // tap toggle raise
#define NMBRS   TT(_NUMERIC)            // tap toggle numeric

/* media keys */
#define MPP KC_MEDIA_PLAY_PAUSE
#define MPR KC_MEDIA_PREV_TRACK
#define MPN KC_MEDIA_NEXT_TRACK
#define VUP KC_AUDIO_VOL_UP
#define VDN KC_AUDIO_VOL_DOWN

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _NUMERIC
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  OSLYR = SAFE_RANGE,
  TLDSL
};

#if MATRIX_COLS == 6
// test matrix one side
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_half(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_Y,   KC_U, KC_I, KC_O, KC_P, KC_A,
    KC_S,   KC_D, KC_F, KC_G, KC_H, KC_J,
    KC_K,   KC_L, KC_Z, KC_X, KC_C, KC_V
  )
};

#elif MATRIX_COLS == 12

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc/W|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | WM/OS| Ctrl | Alt  | GUI  |Lower | Space / FN  | Raise|   /  | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
 [_QWERTY] = LAYOUT_full(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTT,
    _______,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,  SPCFN, SPCFN,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    //KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, RSFTT,
    //OSLYR,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SPCFN,   RAISE,   KC_SLSH, KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Lower - shifted characters on normal keyboard
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |  ~/  |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   ?  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_full(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  _______, _______, _______, TLDSL,   _______, _______, KC_UNDS,  KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, KC_QUES, KC_ENTER,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______
),

/* Raise - stuff that would not require modifiers on normal keyboards
(minus a few exceptions to make it easier to do math)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   +  |      |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | KBLYR|             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_full(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, KC_PLUS, _______, _______, _______, KC_ENTER,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______
),

/* numeric layer - and other helpful things
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  | F3   | F4   |      |      |      |      |  7   |   8  |  9   |  *   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F5  |  F6  | F7   | F8   |      |      |      |      |  4   |   5  |  6   |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F9  |  F10 | F11  | F12  |      |      |      |      |  1   |   2  |  3   |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MPR  |  MPP | MPN  | VDN  | VUP  |             |      |  0   |   .  |  =   |  -   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMERIC] = LAYOUT_full(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_KP_ASTERISK,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, KC_4, KC_5, KC_6, KC_KP_SLASH,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_KP_PLUS,
    MPR,     MPP,     MPN,     VDN,     VUP,     _______, _______,         _______, KC_0, KC_DOT, KC_KP_EQUAL, KC_KP_MINUS
)
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
      case TLDSL:
        if (record->event.pressed) {
          SEND_STRING("~/");
          return false;
        }
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
