#pragma once

// Resuable 
#define ___________________BLANK___________________   _______, _______, _______, _______, _______

#define ________________NUMBER_LEFT________________   KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________   KC_6,    KC_7,    KC_8,    KC_9,    KC_0

// Layouts
#define _________________QWERTY_L1_________________   KC_Q, KC_W, KC_E, KC_R, KC_T
#define _________________QWERTY_L2_________________   KC_A, KC_S, KC_D, KC_F, KC_G
#define _________________QWERTY_L3_________________   KC_Z, KC_X, KC_C, KC_V, KC_B

#define _________________QWERTY_R1_________________   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________LOWER_L1__________________   _______, _______, KC_UP,   _______, _______
#define _________________LOWER_L2__________________   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN
#define _________________LOWER_L3__________________   KC_HOME, _______, _______, KC_LBRC, KC_LCBR

#define _________________LOWER_R1__________________   KC_EXLM, KC_AT,   KC_HASH, KC_TILD, _______
#define _________________LOWER_R2__________________   KC_RPRN, KC_EQL,  KC_GRV,  KC_MINS, KC_SCLN
#define _________________LOWER_R3__________________   KC_RCBR, KC_RBRC, _______, _______, KC_END

#define _________________RAISE_L1__________________   ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________   _______, KC_AMPR, KC_DLR,  KC_PERC, KC_ASTR
#define _________________RAISE_L3__________________   ___________________BLANK___________________

#define _________________RAISE_R1__________________   ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END

#define _________________ADJUST_L1_________________   ___________________BLANK___________________
#define _________________ADJUST_L2_________________   _______, _______, _______, GAMING, _______
#define _________________ADJUST_L3_________________   ___________________BLANK___________________

#define _________________ADJUST_R1_________________   _______, _______, _______, DEBUG,   RESET
#define _________________ADJUST_R2_________________   _______, MAC,     QWERTY,  _______, _______
#define _________________ADJUST_R3_________________   ___________________BLANK___________________

#define _________________NUMPAD_R1_________________   _______, KC_7, KC_8, KC_9, KC_0
#define _________________NUMPAD_R2_________________   _______, KC_4, KC_5, KC_6, _______
#define _________________NUMPAD_R3_________________   _______, KC_1, KC_2, KC_3, _______

#define _________________GAMING_L1_________________   KC_Q, KC_W, KC_E, KC_R, KC_T,
#define _________________GAMING_L2_________________   KC_A, KC_S, KC_D, KC_F, KC_G,
#define _________________GAMING_L3_________________   KC_Z, KC_X, KC_C, KC_V, KC_B,

#define _________________GAMING_R1_________________   KC_Y, KC_U, KC_I,    KC_O,   KC_P,
#define _________________GAMING_R2_________________   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
#define _________________GAMING_R3_________________   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,

#define _________________GAMING_FL_________________   KC_1,    KC_2,    KC_3,  KC_4,   KC_F5,
#define _________________GAMING_FR_________________   KC_VOLD, KC_VOLU, KC_F9, KC_F10, KC_F11, 

#define _________________FROW_LEFT_________________   KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _________________FROW_RGHT_________________   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)