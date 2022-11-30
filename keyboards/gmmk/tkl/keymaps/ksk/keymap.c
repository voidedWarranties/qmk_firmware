#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _SYMBOL,
    _FKEYS,
    _ADJUST,
    _NAV,
};

#define TAB_PRV C(S(KC_TAB))
#define TAB_NXT C(KC_TAB)
#define TAB_CLS C(KC_W)
#define TAB_UND C(S(KC_T))
#define TAB_NEW C(KC_T)
#define TAB_RLD C(KC_R)
#define TAB_BCK A(KC_LEFT)
#define TAB_FWD A(KC_RIGHT)

#define COPY C(KC_C)
#define PASTE C(KC_V)
#define CUT C(KC_X)

#define LYR_NAV LT(_NAV, KC_SCLN)
#define LYR_FKS LT(_FKEYS, KC_SLSH)
#define LYR_SMB LT(_SYMBOL, KC_SPC)
#define LYR_ADJ MO(_ADJUST)

#define ESC_CTL MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi(   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,           KC_BSPC,    _______,
                             ESC_CTL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,           LYR_NAV,        KC_QUOT,    _______,
                             KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,         LYR_FKS,        KC_RSFT,    KC_ENT,
                             KC_LCTL,    KC_LGUI,    KC_LALT,    LYR_SMB,    KC_RALT,    LYR_ADJ,    KC_APP,     KC_RCTL,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX),

    [_NAV] = LAYOUT_ansi(    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             _______,    TAB_BCK,    TAB_FWD,    _______,    TAB_RLD,    TAB_NEW,    COPY,       TAB_UND,    KC_PGDN,    KC_PGUP,        PASTE,          _______,    _______,
                             _______,    TAB_PRV,    TAB_NXT,    TAB_CLS,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,        _______,        _______,    _______,
                             _______,    _______,    CUT,        _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
                             _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX),

    [_FKEYS] = LAYOUT_ansi(  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_ACL0,    KC_ACL1,    KC_WH_L,    KC_MS_U,    KC_WH_R,        KC_DEL,         KC_INS,     _______,
                             _______,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_ACL2,    KC_WH_D,    KC_MS_L,    KC_MS_D,    KC_MS_R,        KC_WH_U,        _______,    _______,
                             _______,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,     KC_F16,     KC_BTN3,        _______,        _______,    KC_PSCR,
                             _______,    _______,    _______,    KC_BTN1,    KC_BTN2,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX),

    [_SYMBOL] = LAYOUT_ansi( XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,           KC_0,           _______,    _______,
                             KC_TILD,    KC_LPRN,    KC_RPRN,    KC_PLUS,    KC_EQL,     KC_MINS,    KC_UNDS,    KC_LCBR,    KC_RCBR,    KC_LBRC,        KC_RBRC,        _______,    _______,
                             KC_PIPE,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,        KC_BSLS,        _______,    _______,
                             _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX),

    [_ADJUST] = LAYOUT_ansi( XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             RGB_TOG,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_VAD,    RGB_VAI,    _______,    _______,    _______,        _______,        _______,    _______,
                             RGB_SPD,    RGB_SPI,    RGB_RMOD,   RGB_MOD,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
                             _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
                             _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX),

    /*
    [_NEW] = KEYMAP(    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,
                        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX),

    // original keymap
    [_BL] = KEYMAP(     KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,          KC_F10,         KC_F11,     KC_F12,
                        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,           KC_0,           KC_MINS,    KC_EQL,
                        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,           KC_LBRC,    KC_RBRC,
                        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,           KC_SCLN,        KC_QUOT,    KC_BSLS,
                        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,         KC_SLSH,        KC_RSFT,    KC_ENT,
                        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_RALT,    MO(_FN),    KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,        KC_UP,          KC_RGHT,    KC_BSPC,
                        KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_INS,     KC_HOME,    KC_PGUP,    KC_DEL,     KC_END,     KC_PGDN),
    */
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGB_MATRIX_ENABLE
    if (record->event.pressed) return true;

    switch (keycode) {
    case RGB_TOG:
        rgb_matrix_toggle_noeeprom();
        return false;
    case RGB_HUD:
        rgb_matrix_decrease_hue_noeeprom();
        return false;
    case RGB_HUI:
        rgb_matrix_increase_hue_noeeprom();
        return false;
    case RGB_SAD:
        rgb_matrix_decrease_sat_noeeprom();
        return false;
    case RGB_SAI:
        rgb_matrix_increase_sat_noeeprom();
        return false;
    case RGB_VAD:
        rgb_matrix_decrease_val_noeeprom();
        return false;
    case RGB_VAI:
        rgb_matrix_increase_val_noeeprom();
        return false;
    case RGB_SPD:
        rgb_matrix_decrease_speed_noeeprom();
        return false;
    case RGB_SPI:
        rgb_matrix_increase_speed_noeeprom();
        return false;
    case RGB_RMOD:
        rgb_matrix_step_reverse_noeeprom();
        return false;
    case RGB_MOD:
        rgb_matrix_step_noeeprom();
        return false;
    }
#endif // RGB_MATRIX_ENABLE

    return true;
}
