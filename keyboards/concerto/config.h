/*
Copyright 2021 @opowell26

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define MANUFACTURER    opowell26
#define PRODUCT         Concerto

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { F7, B3, B5, E6, B4, B6, B2, B1 }
#define MATRIX_COL_PINS { F4, F5, F6, D7, C6, D4 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

