#include "opowell26.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        KC_ESC,  _________________QWERTY_L1_________________,           _________________QWERTY_R1_________________, KC_BSPC,
        KC_TAB,  _________________QWERTY_L2_________________,           ________________QWERTY_40_R2_______________, KC_ENT,
        KC_LSFT, _________________QWERTY_L3_________________,           _________________QWERTY_R3_________________, KC_RSFT,
                                        KC_LALT, KC_LCTL, LOWER,     KC_SPC, RAISE, KC_RGUI
        ),

    [_GAMING] = LAYOUT_wrapper(
        KC_ESC,  _________________QWERTY_L1_________________,           _________________QWERTY_R1_________________, KC_BSPC,
        KC_TAB,  _________________QWERTY_L2_________________,           _________________QWERTY_R2_________________, KC_ENT,
        KC_LSFT, _________________QWERTY_L3_________________,           _________________QWERTY_R3_________________, KC_RSFT,
                                       KC_LALT, KC_LCTL, KC_SPC,     KC_SPC, RAISE, KC_RGUI
    ),

    [_MAC] = LAYOUT_wrapper(
        KC_ESC,  _________________QWERTY_L1_________________,           _________________QWERTY_R1_________________, KC_BSPC,
        KC_TAB,  _________________QWERTY_L2_________________,           _________________QWERTY_R2_________________, KC_ENT,
        KC_LSFT, _________________QWERTY_L3_________________,           _________________QWERTY_R3_________________, KC_RSFT,
                                        KC_LALT, KC_LCTL, LOWER,     KC_SPC, RAISE, KC_RCTRL
    ),

    [_LOWER] = LAYOUT_wrapper(
        _______,  _________________LOWER_L1__________________,           _________________LOWER_R1__________________, KC_DEL,
        KC_CAPS, _________________LOWER_L2__________________,           _________________LOWER_R2__________________, KC_SCLN,
        KC_LSFT, _________________LOWER_L3__________________,           _________________LOWER_R3__________________, _______,
                                      _______, _______, _______,     _______, _______, _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        KC_TAB,  _________________RAISE_L1__________________,           _________________RAISE_R1__________________, _______,
        KC_NO,   _________________RAISE_L2__________________,           _________________RAISE_R2__________________, _______,
        KC_LSFT, _________________RAISE_L3__________________,           _________________RAISE_R3__________________, _______,
                                      _______, _______, _______,     _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        KC_TAB,  _________________ADJUST_L1_________________,           _________________ADJUST_R1_________________, KC_NO,
        KC_NO,   _________________ADJUST_L2_________________,           _________________ADJUST_R2_________________, KC_NO,
        KC_LSFT, _________________ADJUST_L3_________________,           _________________ADJUST_R3_________________, KC_NO,
                                      _______, _______, _______,     _______, _______, _______
    ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }
#endif
