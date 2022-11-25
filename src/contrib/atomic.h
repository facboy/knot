/*  Copyright (C) 2019 CZ.NIC, z.s.p.o. <knot-dns@labs.nic.cz>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/*!
 * \brief Multiplatform atomic operations.
 */

#pragma once

#ifdef HAVE_ATOMIC                   /* C11 */
 #define ATOMIC_SET(dst, val) __atomic_store_n(&(dst), (val), __ATOMIC_RELAXED)
 #define ATOMIC_GET(src)      __atomic_load_n(&(src), __ATOMIC_RELAXED)
 #define ATOMIC_ADD(dst, val) __atomic_add_fetch(&(dst), (val), __ATOMIC_RELAXED)
 #define ATOMIC_SUB(dst, val) __atomic_sub_fetch(&(dst), (val), __ATOMIC_RELAXED)
#elif HAVE_SYNC_ATOMIC               /* GCC, partial support only. */
 #define ATOMIC_SET(dst, val) ((dst) = (val))
 #define ATOMIC_GET(src)      __sync_fetch_and_or(&(src), 0)
 #define ATOMIC_ADD(dst, val) __sync_add_and_fetch(&(dst), (val))
 #define ATOMIC_SUB(dst, val) __sync_sub_and_fetch(&(dst), (val))
#else                                /* Fallback, non-atomic. */
 #define ATOMIC_SET(dst, val) ((dst) = (val))
 #define ATOMIC_GET(src)      (src)
 #define ATOMIC_ADD(dst, val) ((dst) += (val))
 #define ATOMIC_SUB(dst, val) ((dst) -= (val))
#endif
