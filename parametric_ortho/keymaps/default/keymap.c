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

#define TAPPING_TOGGLE 2

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ARROWS,
    _NUMERIC,
    _OSWM
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  OSLYR = SAFE_RANGE,
  TLDSL
};

#define SPCFN   LT(_NUMERIC, KC_SPC)    // function keys, numpad
#define SUESC   RGUI_T(KC_ESC)          // super when held, esc when tapped
#define AARWS  LT(_ARROWS, KC_A)       // arrow layer when held, a when tapped

#define RSFTT   RSFT_T(KC_ENT)          // shift on hold, enter on tap
#define TABW    LGUI_T(KC_TAB)          // win on hold, tab on tap
#define ESCW    LGUI_T(KC_ESC)          // win on hold, esc on tap

#define LOWER   TT(_LOWER)              // tap toggle lower
#define RAISE   TT(_RAISE)              // tap toggle raise
#define NMBRS   TT(_NUMERIC)            // tap toggle numeric
#define OSLYR   MO(_OSWM)               // OS/WM layer

/* media keys */
#define MPP KC_MEDIA_PLAY_PAUSE
#define MPR KC_MEDIA_PREV_TRACK
#define MPN KC_MEDIA_NEXT_TRACK
#define VUP KC_AUDIO_VOL_UP
#define VDN KC_AUDIO_VOL_DOWN

// i3 macros
// workspaces
#define I31     LGUI(KC_1)
#define I32     LGUI(KC_2)
#define I33     LGUI(KC_3)
#define I34     LGUI(KC_4)
#define I35     LGUI(KC_5)
#define I36     LGUI(KC_6)
#define I37     LGUI(KC_7)
#define I38     LGUI(KC_8)
#define I39     LGUI(KC_9)
#define I30     LGUI(KC_0)
// other
#define I3X     SGUI(KC_Q)              // quit active app
#define I3LM    LGUI(KC_LBRC)           // workspace to the left
#define I3RM    LGUI(KC_RBRC)           // workspace to the right
#define I3PWR   LGUI(KC_SCROLLLOCK)     // power menu
#define DISP    SGUI(KC_D)              // monitor selection mode

// macos helpers
#define MSW     LGUI(KC_GRV)            // switch window (show scratchpad on i3)
#define PASTE   SGUI(LALT(KC_V))        // paste w/o formatting


/*
#ifdef TEST_SIDE
// test matrix one side
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_half(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_Y,   KC_U, KC_I, KC_O, KC_P, KC_A,
    KC_S,   KC_D, KC_F, KC_G, KC_H, KC_J,
    KC_K,   KC_L, KC_Z, KC_X, KC_C, KC_V
  )
};

#else
*/
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
 [_QWERTY] = LAYOUT_split(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    SUESC,   AARWS,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFTT,
    OSLYR,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,  SPCFN, SPCFN,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    //KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, RSFTT,
    //OSLYR,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SPCFN,   SPCFN, RAISE,   KC_SLSH, KC_LEFT, KC_DOWN,   KC_RGHT
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
[_LOWER] = LAYOUT_split(
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
 * |      |      |      |      |      |      |      |   +  |      |      |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | KBLYR|             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_split(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, KC_PLUS, _______, _______, KC_SLSH, KC_ENTER,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Arrows
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = LAYOUT_split(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
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
[_NUMERIC] = LAYOUT_split(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_KP_ASTERISK,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, KC_4, KC_5, KC_6, KC_KP_SLASH,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_KP_PLUS,
    MPR,     MPP,     MPN,     VDN,     VUP,     _______, _______,         _______, KC_0, KC_DOT, KC_KP_EQUAL, KC_KP_MINUS
),

/* i3wm/macos
 * ,-----------------------------------------------------------------------------------.
 * |  MSW | ws1  | ws2  | ws3  | ws4  | ws5  | ws6  | ws7  | ws8  | ws9  | ws0  | prsc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |      |      | DISP |      |      |      |      |      | wslm | wsrm | power|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |______|      | I3X  |      |PASTE |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_OSWM] = LAYOUT_split(
    MSW,     I31,     I32,     I33,     I34,     I35,     I36,     I37,     I38,     I39,     I30,     KC_PSCR,
    KC_CAPS, _______, _______, DISP,    _______, _______, _______, _______, _______, I3LM,    I3RM,    I3PWR,
    _______, _______, I3X,     _______, PASTE,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


};
//#endif

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
