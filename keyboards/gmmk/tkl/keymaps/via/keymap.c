#include QMK_KEYBOARD_H
#include "rgb_matrix.h"

#ifdef DEBUG_GMMK
#include "printf.h"
#endif

#define _BL 0
#define _FN 1
#define _L2 2
#define _L3 3

#define SWITCH_MODE 0x1688
#define GUI_LOCK    0x1689

#ifdef VIA_OPENRGB_HYBRID
extern uint8_t is_orgb_mode;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = KEYMAP(     KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,          KC_F10,         KC_F11,     KC_F12, 
                        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,           KC_0,           KC_MINS,    KC_EQL,
                        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,           KC_LBRC,    KC_RBRC,
                        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,           KC_SCLN,        KC_QUOT,    KC_BSLS,
                        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,         KC_SLSH,        KC_RSFT,    KC_ENT,
                        KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,     KC_RALT,    MO(_FN),    KC_APP,     KC_RCTL,    KC_LEFT,    KC_DOWN,        KC_UP,          KC_RGHT,    KC_BSPC,
                        KC_NUBS,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_INS,     KC_HOME,    KC_PGUP,    KC_DEL,     KC_END,     KC_PGDN), 

    [_FN] = KEYMAP(     RESET,      KC_MYCM,    KC_WSCH,    KC_CALC,    KC_MSEL,    KC_MPRV,    KC_MNXT,    KC_MPLY,    KC_MSTP,    KC_MUTE,        KC_VOLD,        KC_VOLU,    LCTL(LSFT(KC_ESC)),
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
                        KC_TRNS,    SWITCH_MODE,KC_TRNS,    EEP_RST,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
                        KC_TRNS,    KC_TRNS,    RGB_TOG,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,
                        KC_TRNS,    GUI_LOCK,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_HUD,    RGB_VAD,        RGB_VAI,        RGB_HUI,    KC_TRNS,
                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_M_B,    RGB_M_R,    RGB_M_SW,   RGB_MOD,    RGB_RMOD),
    [_L2] = {[0 ... MATRIX_ROWS - 1] = {[0 ... MATRIX_COLS - 1] = KC_TRNS}},
    [_L3] = {[0 ... MATRIX_ROWS - 1] = {[0 ... MATRIX_COLS - 1] = KC_TRNS}}
};

void matrix_init_user(void)
{
}

void matrix_scan_user(void)
{
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case SWITCH_MODE:
        #ifdef VIA_OPENRGB_HYBRID
            if (record->event.pressed) {                
                is_orgb_mode = !is_orgb_mode;
            }
        #endif
        return false;

        case GUI_LOCK:
            /* win lock */
            if (record->event.pressed) {
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.no_gui = !keymap_config.no_gui;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();
            }

        return false;
    }        

    return true;
}
