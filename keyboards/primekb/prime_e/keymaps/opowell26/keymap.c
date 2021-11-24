#include QMK_KEYBOARD_H
#include "print.h"
#include "opowell26.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        KC_ESC, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_DEL, KC_BSPC,
        KC_TAB, _________________QWERTY_L2_________________, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LSFT, _________________QWERTY_L3_________________, MO(_FN), _________________QWERTY_R3_________________, KC_RSFT,
        KC_LGUI, KC_LALT, KC_LCTRL, LOWER,                                                   KC_SPACE, RAISE, KC_RALT, KC_RCTRL
    ),

    [_MAC] = LAYOUT_wrapper(
        KC_ESC, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_DEL, KC_BSPC,
        KC_TAB, _________________QWERTY_L2_________________, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LSFT, _________________QWERTY_L3_________________, MO(_FN), _________________QWERTY_R3_________________, KC_RSFT,
        KC_LCTRL, KC_LALT, KC_LGUI, LOWER,                                                   KC_SPACE, RAISE, KC_RALT, KC_RCTRL
    ),
    [_GAMING] = LAYOUT_wrapper(
        KC_ESC, _________________GAMING_L1_________________, _________________GAMING_R1_________________, KC_DEL, KC_BSPC,
        KC_TAB, _________________GAMING_L2_________________, _________________GAMING_R2_________________, KC_ENT,
        KC_LSFT, _________________GAMING_L3_________________, MO(_FN), _________________GAMING_R3_________________, KC_RSFT,
        KC_LGUI, KC_LALT, KC_LCTRL, LOWER,                                                   KC_SPACE, RAISE, KC_RALT, KC_RCTRL
    ),
    [_LOWER] = LAYOUT_wrapper(
        _______, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______,
        KC_CAPS, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_BSLS,
        _______, _________________LOWER_L3__________________, _______, _________________LOWER_R3__________________, _______,
        _______, _______, _______, _______,                                                     _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_wrapper(
        _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______,
        _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________, _______, _________________RAISE_R3__________________, _______,
        _______,_______,_______,_______,                                                 _______,_______,_______,_______
    ),
    [_FN] = LAYOUT_wrapper(
        _______, _________________FROW_LEFT_________________, _________________FROW_RGHT_________________, KC_F11, KC_F12,
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________, _______, ___________________BLANK___________________, _______,
        _______,_______,_______,_______,                                                 _______,_______,_______,_______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, _______, _______,
        _______, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, _______,
        _______, _________________ADJUST_L3_________________, _______, _________________ADJUST_R3_________________, _______,
        _______, _______, _______, _______,                                           _______, _______, _______, _______
    )
};
