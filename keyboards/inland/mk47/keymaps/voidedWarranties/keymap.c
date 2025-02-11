/* Copyright (C) 2023 jonylee@hfd
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

enum layers {
	_BASE,
	_SYMBOL,
	_FKEYS,
	_ADJUST,
	_NAV,
	_GAME,
};

#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define LYR_SMB MO(_SYMBOL)
#define LYR_FKS MO(_FKEYS)
#define LYR_ADJ MO(_ADJUST)
#define LYR_NAV LT(_NAV, KC_SCLN)
#define LYR_GAM TG(_GAME)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_mit(
        KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSPC,
        ESC_CTL,KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	LYR_NAV,KC_QUOT,
        KC_LSFT,KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_SLSH,KC_RSFT,
        KC_LCTL,LYR_ADJ,KC_LGUI,LYR_FKS,LYR_SMB,KC_SPC,		KC_ENT,	KC_LALT,LYR_SMB,KC_RALT,KC_RCTL
    ),

    [_SYMBOL] = LAYOUT_planck_mit(
        KC_GRV,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	_______,
        KC_TILD,KC_LPRN,KC_RPRN,KC_PLUS,KC_EQL,	KC_MINS,KC_UNDS,KC_LCBR,KC_RCBR,KC_LBRC,KC_RBRC,_______,
        KC_PIPE,KC_EXLM,KC_AT,	KC_HASH,KC_DLR,	KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,_______,KC_BSLS,_______,
        _______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______
    ),

    [_FKEYS] = LAYOUT_planck_mit(
        _______,KC_F1,	KC_F2,	KC_F3,	KC_F4,	MS_ACL0,MS_ACL1,MS_WHLL,MS_UP,	MS_WHLR,KC_DEL,	KC_INS,
        _______,KC_F5,	KC_F6,	KC_F7,	KC_F8,	MS_ACL2,MS_WHLD,MS_LEFT,MS_DOWN,MS_RGHT,MS_WHLU,_______,
        _______,KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PSCR,_______,MS_BTN3,_______,_______,_______,_______,
        _______,KC_F13,	KC_F14,	KC_F15,	KC_F16,	MS_BTN1,	MS_BTN2,_______,_______,_______,_______
    ),

    [_ADJUST] = LAYOUT_planck_mit(
        _______,RM_TOGG,RM_PREV,RM_NEXT,_______,_______,_______,KC_MPRV,KC_MPLY,KC_MSTP,KC_MNXT,_______,
        KC_ESC,	RM_HUED,RM_HUEU,RM_SATD,RM_SATU,_______,_______,KC_MUTE,KC_VOLD,KC_VOLU,KC_SCLN,_______,
        _______,RM_VALD,RM_VALU,RM_SPDD,RM_SPDU,_______,_______,KC_BRID,KC_BRIU,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,	_______,_______,_______,LYR_GAM,_______
    ),

    [_NAV] = LAYOUT_planck_mit(
        _______,_______,_______,_______,_______,_______,_______,_______,KC_PGDN,KC_PGUP,_______,_______,
        _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,	KC_RGHT,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______
    ),

    [_GAME] = LAYOUT_planck_mit(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        KC_ESC,	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______
    ),

/*
    [_LAYER] = LAYOUT_planck_mit(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,	_______,_______,_______,_______,_______
    ),
*/
/*
    [1] = LAYOUT_planck_mit(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RM_NEXT,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, RM_VALU, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, RM_VALD, KC_TRNS
    ),

    [2] = LAYOUT_planck_mit(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_CAPS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        KC_LCTL, KC_NO,   KC_LALT, KC_DEL,  KC_PGDN,     KC_SPC,       KC_PGUP, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT
    )
*/
};
// clang-format on

