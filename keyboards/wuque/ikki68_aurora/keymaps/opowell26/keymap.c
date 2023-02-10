#include QMK_KEYBOARD_H
#include "opowell26.h"

#define  LAYOUT_wrapper(...) LAYOUT_all(__VA_ARGS__)
#define LED_MODE_LOGO 0
#define LED_MODE_UNDER 1
#define LED_MODE_ALL 2
#define LED_MODE_OFF 3

enum user_keycodes {
    RGB_RNG = SAFE_RANGE  // Toggle between logo, backlight, both, off
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t led_mode : 8;
    };
} user_config_t;

void update_led_mode(void);
void persist_led_mode(void);

user_config_t user_config;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_RNG:
            if (record->event.pressed) {
                user_config.led_mode = (user_config.led_mode + 1) % 4;
                update_led_mode();
                persist_led_mode();
            }
            return false;
        default:
            return true;
    }
    return true;
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    update_led_mode();
}

void eeconfig_init_user(void) {
    user_config.raw      = 0;
    user_config.led_mode = LED_MODE_LOGO;
    eeconfig_update_user(user_config.raw);
    rgblight_enable();
}

void update_led_mode(void) {
    rgblight_setrgb(0, 0, 0);
    switch (user_config.led_mode) {
        case LED_MODE_LOGO:
            rgblight_set_effect_range(16, 4);
            rgblight_enable_noeeprom();
            break;
        case LED_MODE_UNDER:
            rgblight_set_effect_range(0, 16);
            rgblight_enable_noeeprom();
            break;
        case LED_MODE_ALL:
            rgblight_set_effect_range(0, RGBLED_NUM);
            rgblight_enable_noeeprom();
            break;
        default:
            rgblight_disable_noeeprom();
    }
}

void persist_led_mode(void) { eeconfig_update_user(user_config.raw); }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, KC_HOME, KC_PGUP,
        KC_ESC, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC,  KC_BSPC,         KC_END, KC_PGDN,
        KC_TAB, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,           KC_ENT,
        KC_LSFT, KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT, KC_RSFT,        KC_UP,
        KC_LALT, KC_LGUI, KC_LCTL, LOWER,                RAISE,              KC_SPACE, KC_RCTL, KC_RALT, KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_LOWER] = LAYOUT_wrapper(
        _______, _________________FROW_LEFT_________________,  _________________FROW_RGHT_________________,  KC_F11,  KC_F12, _______, _______,    _______, _______,
        _______,  _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______,             KC_DEL, KC_PGDN,
        KC_CAPS, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,          KC_BSLS,
        KC_LSFT, KC_LSFT, _________________LOWER_L3__________________, _________________LOWER_R3__________________, KC_RSFT, KC_RSFT,        KC_UP,
        KC_LALT, KC_LGUI, KC_LCTL, LOWER,                RAISE,              KC_SPACE, KC_RCTL, KC_RALT, KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_RAISE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______,
        _______,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______,             KC_DEL, KC_PGDN,
        KC_CAPS, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,          KC_BSLS,
        KC_LSFT, KC_LSFT, _________________RAISE_L3__________________, _________________RAISE_R3__________________, KC_RSFT, KC_RSFT,        KC_UP,
        KC_LALT, KC_LGUI, KC_LCTL, LOWER,                RAISE,              KC_SPACE, KC_RCTL, KC_RALT, KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             RGB_RNG, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             RGB_VAI,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______,             RGB_TOG, RGB_VAD, RGB_MOD
    )
};
