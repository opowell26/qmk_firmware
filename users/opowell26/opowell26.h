#pragma once
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "process_records.h"
#include "wrappers.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,
    _MAC,
    _GAMING,
    _LOWER,
    _RAISE,
    _FN,
    _ADJUST,
};


bool          mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed);
bool          mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
void          matrix_init_keymap(void);
void          matrix_init_secret(void);
void          shutdown_keymap(void);
void          suspend_power_down_keymap(void);
void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
void          matrix_scan_secret(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
void          eeconfig_init_keymap(void);
bool          hasAllBitsInMask(uint8_t value, uint8_t mask);
