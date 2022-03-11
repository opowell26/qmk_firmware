/* Copyright 2022 Olivia Powell (@opowell26)
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

#pragma once

#include "quantum.h"
#include "oled_driver.h"

void render_oled_layers(void);
void render_oled_wpm(uint8_t padding);
// oled_rotation_t oled_init_keymap(oled_rotation_t rotation);

#ifdef OLED_DISPLAY_128X64
#    define OLED_RENDER_KEYLOGGER         "Keylogger: "

#    define OLED_RENDER_LAYOUT_NAME       "Layout: "
#    define OLED_RENDER_LAYOUT_QWERTY     "Qwerty"
#    define OLED_RENDER_LAYOUT_MAC        "Mac"
#    define OLED_RENDER_LAYOUT_GAMING     "Gaming"

#    define OLED_RENDER_LAYER_NAME        "Layer:"
#    define OLED_RENDER_LAYER_LOWER       "Lower"
#    define OLED_RENDER_LAYER_RAISE       "Raise"
#    define OLED_RENDER_LAYER_ADJUST      "Adjust"

#    define OLED_RENDER_WPM_COUNTER       "WPM: "
#else
#    define OLED_RENDER_KEYLOGGER         "KLogr"

#    define OLED_RENDER_LAYOUT_NAME       "Lyout"
#    define OLED_RENDER_LAYOUT_QWERTY     "QWRTY"
#    define OLED_RENDER_LAYOUT_MAC        "Mac"
#    define OLED_RENDER_LAYOUT_GAMING     "Gaming"

#    define OLED_RENDER_LAYER_NAME        "LAYER"
#    define OLED_RENDER_LAYER_LOWER       "Lower"
#    define OLED_RENDER_LAYER_RAISE       "Raise"
#    define OLED_RENDER_LAYER_ADJUST      "Adjst"

#    define OLED_RENDER_WPM_COUNTER       "WPM: "

#endif

#if defined(OLED_PONYTA)
void render_oled_pet(uint8_t col, )
