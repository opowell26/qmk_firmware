/* Copyright 2021 opowell26
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


// 1u backspace layout
#define LAYOUT( \
    K000, K042, K001, K037, K002, K038,  		K003, K043, K004, K044, K034, K005, K045, K046, \
	K006, K036, K007, K031, K008, K032,  		K009, K039, K010, K040, K011, K041, \
	K012, K030, K013, K025, K014, K026,  		K015, K033, K016, K022, K028, K017, K035, \
	K018, K024,  			K019, K020,  		K021, K027, 				K023, K029 \
) { \
    { K000, K001, K002, K003, K004, K005 }, \
    { K006, K007, K008, K009, K010, K011 }, \
    { K012, K013, K014, K015, K016, K017 }, \
    { K018, K019, K020, K021, K022, K023 }, \
    { K024, K025, K026, K027, K028, K029 }, \
    { K030, KC_NO, KC_NO, K033, K034, K035 }, \
    { K036, K031, K032, K039, K040, K041, }, \
    { K042, K037, K038, K043, K044, K045 } \
}
