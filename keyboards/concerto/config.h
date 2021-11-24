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
