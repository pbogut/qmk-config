/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#define EE_HANDS
// #define MASTER_RIGHT// EE_HANDS MASTER_RIGHT

#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP

// mouse support
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED

#define MOUSEKEY_DELAY          10
#define MOUSEKEY_TIME_TO_MAX    250
#define MOUSEKEY_MAX_SPEED      5

// save some memory
#define NO_ACTION_ONESHOT

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
/* #define SPLIT_USB_DETECT */
/* #define NO_USB_STARTUP_CHECK */
