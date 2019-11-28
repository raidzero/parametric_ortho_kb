/* Copyright 2019 raidzero
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT_split( \
    l00, l01, l02, l03, l04, l05, r00, r01, r02, r03, r04, r05, \
    l10, l11, l12, l13, l14, l15, r10, r11, r12, r13, r14, r15, \
    l20, l21, l22, l23, l24, l25, r20, r21, r22, r23, r24, r25, \
    l30, l31, l32, l33, l34, l35, r30, r31, r32, r33, r34, r35 \
) \
{ \
  { l00, l01, l02, l03, l04, l05 }, \
  { l10, l11, l12, l13, l14, l15 }, \
  { l20, l21, l22, l23, l24, l25 }, \
  { l30, l31, l32, l33, l34, l35 }, \
  { r00, r01, r02, r03, r04, r05 }, \
  { r10, r11, r12, r13, r14, r15 }, \
  { r20, r21, r22, r23, r24, r25 }, \
  { r30, r31, r32, r33, r34, r35 } \
}

// for testing each half as standalone boards
#define LAYOUT_half( \
	k00, k01, k02, k03, k04, k05, \
	k10, k11, k12, k13, k14, k15, \
	k20, k21, k22, k23, k24, k25, \
	k30, k31, k32, k33, k34, k35 \
) \
{ \
	{ k00, k01, k02, k03, k04, k05 }, \
	{ k10, k11, k12, k13, k14, k15 }, \
	{ k20, k21, k22, k23, k24, k25 }, \
	{ k30, k31, k32, k33, k34, k35 } \
}
