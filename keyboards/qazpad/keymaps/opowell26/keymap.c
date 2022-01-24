#include QMK_KEYBOARD_H
#include "opowell26.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define MT_RSHFT_DOT MT(MOD_RSFT, KC_DOT)
#define MT_LSHFT_Z MT(MOD_LSFT, KC_Z)

enum {
    TD_Q_ESC = 0,
    TD_A_TAB,
    TD_P_BKSP,
    TD_ENT_QUOT
};

enum custom_keycodes {
    KC_SWAP_CTL_GUI
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [TD_P_BKSP] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),
  [TD_ENT_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_QUOT)
};
    // KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC,
    // KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, LT(3,KC_ENT),
    // KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    // KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        TD(TD_Q_ESC),   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   TD(TD_P_BKSP), ________NUMPAD_R1________,
        TD(TD_A_TAB),   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   TD(TD_ENT_QUOT), ________NUMPAD_R2________,
        MT_LSHFT_Z,     KC_NO,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, MT_RSHFT_DOT, ________NUMPAD_R3________,
        KC_LALT,  KC_LGUI,  KC_LCTRL, KC_NO, LOWER, KC_SPACE, RAISE, KC_RALT, KC_RCTL, KC_SLSH, KC_UP, KC_RIGHT
    ),
    [_LOWER] = LAYOUT_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______,
        _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______, _______, _______,
        _______, KC_HOME, _______, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______,  KC_END, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT_wrapper(
        _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______,
        _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______, _______, _______,
        _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, _______, _______, _______,
        _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, _______, _______, _______,
        _______, _______, _______, _______, KC_SWAP_CTL_GUI, _________________ADJUST_R3_________________, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SWAP_CTL_GUI:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
            }
    }
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
     switch (get_highest_layer(layer_state)) {
        case _RAISE:
            uprintf("Raise \n");
            break;
        case _LOWER:
            uprintf("Lower \n");
            break;
        case _ADJUST:
            uprintf("Adjust \n");
            break;
        default:
            uprintf("Default multi layer \n");
    }
    #endif
    return true;
};
