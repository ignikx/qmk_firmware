/* Copyright 2017 Cole Markham, WoodKeys.click
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,         KC_U,         KC_I,    KC_O,    KC_P, 
		KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,         KC_J,         KC_K,    KC_L,    LT(3,KC_MINS), 
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,         KC_M,         KC_COMM, KC_DOT,  KC_SLSH,       KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, LT(2,KC_BSPC), LT(1,KC_SPC), LT(4,KC_ENT), KC_DEL,  KC_RALT, KC_RCTL,       KC_ESC),
	[1] = LAYOUT(
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
		KC_TAB,  KC_NO,   KC_NO,   KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_MINS, 
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,  KC_MINS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PENT),
	[2] = LAYOUT(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10, 
		KC_TAB,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, 
		KC_CAPS, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,   KC_NLCK, KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_TRNS),
	[3] = LAYOUT(
		KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_PGUP, KC_UP,   KC_PGDN, KC_DEL, 
		KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, 
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS),
	[4] = LAYOUT(
		KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_DEL, 
		KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, 
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_D, KC_NO,   RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_B,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS)
};


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) { 
    if (index == 0) { 
      if (clockwise) {  
        rgblight_step(); 
      } else {  
        rgblight_step_reverse();  
      } 
    } else if (index == 1) { 
      if (clockwise) { 
        tap_code(KC_VOLU); /* volume up */
      } else {
        tap_code(KC_VOLD); /* volume down */
      } 
    }
}
#endif
