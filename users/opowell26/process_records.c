#include "opowell26.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // layer macros
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            break;
        case MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            break;
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            break;
    }
}