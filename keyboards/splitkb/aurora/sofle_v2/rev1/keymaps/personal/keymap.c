#include QMK_KEYBOARD_H

enum layers {
    _WIN = 0,
    _MAC,
    _SYM,
    _NAV,
    _FUNCTIONS,
    _ADJUST,
};
//
// Aliases for readability
#define SWITCH_TO_WIN   DF(_WIN)
#define SWITCH_TO_MAC   DF(_MAC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, /* ---- */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
	KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, /* ---- */ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
	KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, /* ---- */ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, /* ---- */ KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
	KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, MO(_SYM), /* ---- */ MO(_NAV), KC_ENT, KC_RCTL, KC_RALT, MO(_FUNCTIONS)
    ),

    [_MAC] = LAYOUT(
	KC_ESC, KC_2, KC_1, KC_3, KC_4, KC_5, /* ---- */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
	KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, /* ---- */ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
	KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, /* ---- */ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, /* ---- */ KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
	KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(_SYM), /* ---- */ MO(_NAV), KC_ENT, KC_RCTL, KC_RALT, MO(_FUNCTIONS)
    ),
    [_SYM] = LAYOUT(
	KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /* ---- */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, /* ---- */ KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_DEL,
	KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, /* ---- */ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
	KC_TRNS, KC_EQL, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, KC_TRNS, /* ---- */ KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_TRNS,
	KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, /* ---- */ MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_NAV] = LAYOUT(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* ---- */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_INS, KC_PSCR, KC_APP, KC_NO, KC_NO, /* ---- */ KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LCTL(KC_BSPC), KC_BSPC,
	KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_CAPS, /* ---- */ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC,
	KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS, /* ---- */ KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), /* ---- */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FUNCTIONS] = LAYOUT(
	_______,  _______ ,  _______,  _______,  _______, _______, /* ---- */ _______, _______, _______, _______, _______, _______,
	_______,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /* ---- */ _______, _______, _______, _______, _______, _______,
	_______,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, /* ---- */ _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
	_______,  KC_F11, KC_F12, _______, _______, _______, _______, /* ---- */ _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, /* ---- */ _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
	KC_NO, SWITCH_TO_WIN, SWITCH_TO_MAC, KC_NO, KC_NO, KC_NO, /* ---- */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* ---- */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, /* ---- */ KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO,
	KC_NO, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO, /* ---- */ KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /* ---- */ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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

void render_custom_layers(void) {
    // char str[80];
    // sprintf(str, "%d", default_layer_state);
    //sprintf(str, "%d    %08x", default_layer_state, layer_state);
    // oled_write_P(PSTR(str), false);

    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(" W"), default_layer_state == _WIN + 1);
    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(" M"), default_layer_state == _MAC + 1);
    oled_write_P(PSTR("\n"), false);

    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(">S"), layer_state_is(_SYM));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(">N"), layer_state_is(_NAV));
    // oled_write_P(PSTR("\n"), false);
    // oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(">F"), layer_state_is(_FUNCTIONS));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(">A"), layer_state_is(_ADJUST));
    default_layer_debug();
}

void _render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void _render_logo_text(void) {
    oled_write_P(PSTR("sofle"), false);
}

void _render_kb_LED_state(void) {
    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("N ") : PSTR("  "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("C ") : PSTR("  "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("S ") : PSTR("  "), false);
}

void _render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
	oled_write_P(gui_on_1, false);
    } else {
	oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
	oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
	oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
	oled_write_P(off_on_1, false);
    } else {
	oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
	oled_write_P(alt_on_1, false);
    } else {
	oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
	oled_write_P(gui_on_2, false);
    } else {
	oled_write_P(gui_off_2, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
	oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
	oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
	oled_write_P(off_on_2, false);
    } else {
	oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
	oled_write_P(alt_on_2, false);
    } else {
	oled_write_P(alt_off_2, false);
    }
}

void _render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
	oled_write_P(ctrl_on_1, false);
    } else {
	oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
	oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
	oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
	oled_write_P(off_on_1, false);
    } else {
	oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
	oled_write_P(shift_on_1, false);
    } else {
	oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
	oled_write_P(ctrl_on_2, false);
    } else {
	oled_write_P(ctrl_off_2, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
	oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
	oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
	oled_write_P(off_on_2, false);
    } else {
	oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
	oled_write_P(shift_on_2, false);
    } else {
	oled_write_P(shift_off_2, false);
    }
}

// this is how to control what's on the display
bool oled_task_user() {
    render_custom_layers();
    _render_space();
    _render_logo_text();
    _render_space();
    _render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    _render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    _render_space();
    _render_kb_LED_state();
    return false;
}
