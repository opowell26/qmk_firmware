#include "opowell26.h"
#include "version.h"

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


// Defines actions for my global custom keycodes. Defined in opowell26.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    process_record_user_oled(keycode, record);
#endif  // OLED

    switch (keycode) {
        case KC_QWERTY ... KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
            }
            break;
    }
    return process_record_keymap(keycode, record);
};
