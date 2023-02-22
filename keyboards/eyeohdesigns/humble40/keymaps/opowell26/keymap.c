#include "opowell26.h"

#define LAYOUT_humble40_base( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A \
    ) \
    LAYOUT_wrapper( \
        KC_ESC,  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, KC_BSPC,  \
        KC_TAB,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, KC_ENT, \
        KC_LSFT, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, KC_RSFT, \
        KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, RAISE, KC_RGUI, KC_RCTL \
    )
#define LAYOUT_humble40_base_wrapper(...) LAYOUT_humble40_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_humble40_base_wrapper(
        _________________QWERTY_L1_________________,           _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,           ________________QWERTY_40_R2_______________,
        _________________QWERTY_L3_________________,           _________________QWERTY_R3_________________
    ),
    [_GAMING] = LAYOUT_humble40_base_wrapper(
        _________________GAMING_L1_________________,           _________________GAMING_R1_________________,
        _________________GAMING_L2_________________,           _________________GAMING_R2_________________,
        _________________GAMING_L3_________________,           _________________GAMING_R3_________________
    ),
    [_MAC] = LAYOUT_humble40_base_wrapper(
        _________________QWERTY_L1_________________,           _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,           ________________QWERTY_40_R2_______________,
        _________________QWERTY_L3_________________,           _________________QWERTY_R3_________________
    ),

    [_LOWER] = LAYOUT_wrapper(
        KC_ESC,  _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_BSPC,
        KC_CAPS, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_BSLS,
        _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
                        KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, RAISE, KC_RGUI, KC_RCTL
    ),

    [_RAISE] = LAYOUT_wrapper(
        KC_ESC,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_BSPC,
        KC_CAPS, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
                        KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPACE, RAISE, KC_RGUI, KC_RCTL
    ),

    [_ADJUST] = LAYOUT_humble40_base_wrapper(
        _________________FROW_LEFT_________________,           _________________FROW_RGHT_________________,
        _________________ADJUST_L2_________________,           _________________ADJUST_R2_________________,
        ___________________BLANK___________________,           _________________QWERTY_R3_________________
    ),
};
