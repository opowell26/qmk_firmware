#pragma once
#include "opowell26.h"

enum custom_keycodes {
    // Layer Macros
    QWERTY = SAFE_RANGE,
    MAC,
    GAMING,
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);