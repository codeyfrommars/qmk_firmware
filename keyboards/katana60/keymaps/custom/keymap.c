/* Copyright 2017 Baris Tosun
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

typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

user_config_t user_config;


enum fnh_layers {
	BASE,
	TOGGLE,
	BLEFT,
	CAPS
};


// Windows based definitions.
#define K_SPCFN LT(SYMB, KC_SPACE) // Tap for space, hold for symbols layer
#define K_PRVWD LCTL(KC_LEFT)      // Previous word
#define K_NXTWD LCTL(KC_RIGHT)     // Next word
#define K_LSTRT KC_HOME            // Start of line
#define K_LEND  KC_END             // End of line
#define UNDO    LCTL(KC_Z)         // UNDO
#define CUT     LCTL(KC_X)         // CUT
#define COPY    LCTL(KC_C)         // COPY
#define PASTE   LCTL(KC_V)         // PASTE


#define BASE 0 // Default
#define NUMB 1 // Numbers
#define SYMB 2 // Symbols
#define CURS 3 // Text Editing

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT( /*BASE*/
	KC_ESC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, TG(TOGGLE), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, MO(3), KC_A, KC_S, KC_D, KC_F, KC_G, /*PGDN*/KC_HOME, /*PGUP*/KC_END, KC_H, KC_J, KC_K, KC_L, KC_QUOT, /*ENTER*/MO(3), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /*HOME*/KC_PGDN, KC_DEL, /*END*/KC_PGUP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(2), KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, KC_ENT, KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RCTL),

	
	[TOGGLE] = LAYOUT( /*TOGGLE*/
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS /*center key*/, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, RGB_VAD, KC_TRNS, RGB_VAI, KC_TRNS, KC_1, KC_2, KC_3, KC_PENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_0, KC_0, KC_PDOT, KC_PENT, KC_TRNS),
	
	[BLEFT] = LAYOUT( /*BOTTOM LEFT*/
	RESET, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	
	[CAPS] = LAYOUT( /*CAPS LOCK*/
	KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, /*UP*/KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, /*LEFT*/KC_TRNS, /*DOWN*/KC_LEFT, /*RIGHT*/KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case BASE:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void eeconfig_init_user(void) {  // EEPROM is getting reset! 
  user_config.rgb_layer_change = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv(300,58.7,150);  // Set pink
  //rgblight_sethsv(0,0,85); //set white
  rgblight_mode(1); // set to solid by default
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case TOGGLE:
		rgblight_sethsv_noeeprom(0,0,150);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(300,58.7,150);
        break;
    }
  return state;
}

void matrix_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Set default layer, if enabled
  if (user_config.rgb_layer_change) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(300,58.7,150); 
	rgblight_mode_noeeprom(1);}
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
