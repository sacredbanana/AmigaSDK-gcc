// Specific definitions for AmigaOS -*- C++ -*-

// Copyright (C) 2000-2015 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file bits/os_defines.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{iosfwd}
 */

#ifndef _GLIBCXX_OS_DEFINES
#define _GLIBCXX_OS_DEFINES 1

// System-specific #define, typedefs, corrections, etc, go here.  This
// file will come before all others.

// No ioctl() on AmigaOS
#define _GLIBCXX_NO_IOCTL 1

#ifdef __NEWLIB__
#define _GLIBCXX_USE_C99_STDINT_TR1 1
#define _GLIBCXX_USE_C99 1
#endif

#undef __STRICT_ANSI__
/* GCC defines this macro if, and only if, the -ansi switch, or a
 * -std switch specifying strict conformance to some version of ISO C
 * or ISO C++, was specified when GCC was invoked. This macro exists
 * primarily to direct GNU libc's header files to restrict their
 * definitions to the minimal set found in the 1989 C standard. If
 * -std is set to > c++98 when building with clib2, configure will be
 * tricked into believing that existing C99 features are missing. */

#endif
