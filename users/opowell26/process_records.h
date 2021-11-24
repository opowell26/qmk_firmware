#pragma once
#include "opowell26.h"

enum userspace_custom_keycodes {
    // Layer Macros
    KC_QWERTY = SAFE_RANGE,
    KC_MAC,
    KC_GAMING,
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)

#define QWERTY  KC_QWERTY
#define MAC     KC_MAC
#define GAMING  KC_GAMING

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
