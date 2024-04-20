#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,    KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
              KC_LGUI, KC_LALT, KC_LCTL, MO(1), KC_SPC,    KC_ENT, MO(2), KC_RCTL, KC_RALT, KC_RGUI
	),
	[1] = LAYOUT(
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                        KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL,
	    KC_TAB, KC_6, KC_7, KC_8, KC_9, KC_0,                                 KC_6, KC_7, KC_8, KC_LPRN, KC_RPRN, KC_PIPE,
	    KC_TRNS, KC_EQL, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, KC_TRNS,         KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_TRNS,
	                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS
	),
	[2] = LAYOUT(
	    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                                 KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LCTL(KC_BSPC), KC_BSPC,
	    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                                              KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC,
	    KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS,         KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS,
	                                  KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[3] = LAYOUT(
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,                   KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO,
	    KC_NO, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO,     KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
	                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// this is for turning off the state led from the board
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}

//// this is how to control what's on the display
//bool oled_task_user() {
//    char str[80];
//    sprintf(str, "%d    %08x  ", default_layer_state, layer_state);
//    oled_write_P(PSTR(str), false);
////    oled_write_P(PSTR("  "), false);
//
//    oled_write_P(PSTR("WIN  "), layer_state_is(0));
//    oled_write_P(PSTR("MACOS"), layer_state_is(1));
//    oled_write_P(PSTR("CHARS"), layer_state_is(2));
//    oled_write_P(PSTR("NAV  "), layer_state_is(3));
//    oled_write_P(PSTR("ADJ  "), layer_state_is(4));
//    default_layer_debug();
//    return false;
//}
