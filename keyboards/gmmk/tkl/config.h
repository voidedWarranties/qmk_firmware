/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 13

/* key matrix pins */
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D4, D5, D6 }
#define MATRIX_COL_PINS { C1, C2, A0, A1, A2, A3, A6, A7, A8, A9, A10, A11, A12}

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODER_RESOLUTIONS { 2 }
#endif

#define DIODE_DIRECTION ROW2COL

/*
 * Feature
 */
#define USB_POLLING_INTERVAL_MS 1           /* 1000 Hz */
#define FORCE_NKRO                          /* default NRKO enabled */
#define DEBOUNCE 1                          /* Debounce time in ms */
#define RGB_DISABLE_WHEN_USB_SUSPENDED true /* rgb off when power off / suspend */

/*
 * Optimization
 */
#define LAYER_STATE_8BIT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
// #define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 1200
#define NO_DEBUG 1
// #define NO_PRINT 1

#include "config_led.h"
