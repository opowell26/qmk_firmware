#pragma once
#include QMK_KEYBOARD_H
#include "version.h"
#include "process_records.h"
#include "wrappers.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,
    _MAC,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Aliases
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)