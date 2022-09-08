/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#if   defined(KEYBOARD_keychron_q3_rev_0120)
#    include "rev_0120.h"
#elif defined(KEYBOARD_keychron_q3_rev_0121)
#    include "rev_0121.h"
#elif defined(KEYBOARD_keychron_q3_rev_0122)
#    include "rev_0122.h"
#elif defined(KEYBOARD_keychron_q3_rev_0123)
#    include "rev_0123.h"
#elif defined(KEYBOARD_keychron_q3_rev_0124)
#    include "rev_0124.h"
#elif defined(KEYBOARD_keychron_q3_rev_0125)
#    include "rev_0125.h"
#elif defined(KEYBOARD_keychron_q3_rev_0120_lhg)
#    include "rev_0120_lhg.h"
#endif
