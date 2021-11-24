/* Copyright 2021 Olivia Powell (@opowell26)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "opowell26.h"

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak)) void matrix_init_keymap(void) {}

// Call user matrix init, then call the keymap's init function
void matrix_init_user(void) { matrix_init_keymap(); }

__attribute__((weak)) void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matix
// scan function
void matrix_scan_user(void) { matrix_scan_keymap(); }

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

__attribute__((weak)) void startup_keymap(void) {}

__attribute__((weak)) void shutdown_keymap(void) {}


// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }


layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);
    return state;
}
