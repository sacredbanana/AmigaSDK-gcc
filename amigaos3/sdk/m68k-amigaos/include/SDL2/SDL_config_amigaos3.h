/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>
  AmigaOS 3.x port (C) 2026

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL_config_amigaos3_h_
#define SDL_config_amigaos3_h_
#define SDL_config_h_

#include "SDL_platform.h"

#define SDL_MATH_AMIGAOS3_TABLES 1

/*
 * SDL2 configuration for AmigaOS 3.x on Motorola 68k.
 *
 * Target: 68030+ with CyberGraphX RTG.
 * Compiler: bebbo-gcc (GCC 6.5.0b), -std=gnu99, -noixemul.
 *
 * Reference: SDL_config_minimal.h, SDL2 OS4 port config.
 */

/* C library features available in bebbo-gcc libnix */
#define HAVE_STDARG_H   1
#define HAVE_STDDEF_H   1
#define HAVE_STDINT_H   1

/* libnix provides these (C89 runtime).
   IMPORTANT: SDL2 checks most HAVE_* with #ifdef / #if defined(),
   so "not available" means NOT DEFINED AT ALL, not defined to 0. */
/* HAVE_ALLOCA_H -- NOT defined (no alloca on AmigaOS) */
/* HAVE_ALLOCA -- NOT defined */
#define HAVE_MALLOC     1
#define HAVE_CALLOC     1
#define HAVE_REALLOC    1
#define HAVE_FREE       1
#define HAVE_MEMSET     1
#define HAVE_MEMCPY     1
#define HAVE_MEMMOVE    1
#define HAVE_MEMCMP     1
#define HAVE_STRLEN     1
/* HAVE_STRLCPY -- NOT defined (not in libnix) */
/* HAVE_STRLCAT -- NOT defined (not in libnix) */
#define HAVE_STRDUP     1
#define HAVE_STRCHR     1
#define HAVE_STRRCHR    1
#define HAVE_STRSTR     1
#define HAVE_STRTOL     1
#define HAVE_STRTOUL    1
/* HAVE_STRTOLL -- NOT defined (not in libnix) */
/* HAVE_STRTOULL -- NOT defined (not in libnix) */
#define HAVE_STRTOD     1
#define HAVE_ATOI       1
#define HAVE_ATOF       1
#define HAVE_STRCMP      1
#define HAVE_STRNCMP    1
#define HAVE_STRCASECMP 1
#define HAVE_STRNCASECMP 1
#define HAVE_SSCANF     1
/* HAVE_VSSCANF -- NOT defined */
#define HAVE_SNPRINTF   1
#define HAVE_VSNPRINTF  1

/* Math functions -- libnix has double versions but NOT float versions.
   SDL2 uses #if defined(HAVE_*) so unavailable = NOT DEFINED. */
#define HAVE_ACOS       1
/* HAVE_ACOSF -- NOT defined (no float math in libnix) */
#define HAVE_ASIN       1
/* HAVE_ASINF -- NOT defined */
#define HAVE_ATAN       1
/* HAVE_ATANF -- NOT defined */
#define HAVE_ATAN2      1
/* HAVE_ATAN2F -- NOT defined */
/*
 * m68k AmigaOS3 runtime note:
 * target testing showed the C library ceil() returns incorrect results.
 * Leave HAVE_CEIL undefined so SDL2 uses its portable fallback.
 */
/* HAVE_CEIL -- intentionally NOT defined on AmigaOS3 */
/* HAVE_CEILF -- NOT defined */
/* HAVE_COPYSIGN -- NOT defined */
/* HAVE_COPYSIGNF -- NOT defined */
/*
 * m68k AmigaOS3 runtime note:
 * do not use the C library cos(); SDL_cos() uses the AmigaOS3 lookup table.
 */
/* HAVE_COS -- intentionally NOT defined on AmigaOS3 */
/* HAVE_COSF -- NOT defined */
#define HAVE_EXP        1
/* HAVE_EXPF -- NOT defined */
#define HAVE_FABS       1
/* HAVE_FABSF -- NOT defined */
#define HAVE_FLOOR      1
/* HAVE_FLOORF -- NOT defined */
#define HAVE_FMOD       1
/* HAVE_FMODF -- NOT defined */
#define HAVE_LOG        1
/* HAVE_LOGF -- NOT defined */
/*
 * m68k AmigaOS3 runtime note:
 * target testing showed the C library log10() can cause a software failure.
 * Leave HAVE_LOG10 undefined so SDL2 uses SDL_uclibc_log10().
 */
/* HAVE_LOG10 -- intentionally NOT defined on AmigaOS3 */
/* HAVE_LOG10F -- NOT defined */
/* HAVE_LROUND -- NOT defined */
/* HAVE_LROUNDF -- NOT defined */
#define HAVE_POW        1
/* HAVE_POWF -- NOT defined */
/* HAVE_ROUND -- NOT defined */
/* HAVE_ROUNDF -- NOT defined */
/* HAVE_SCALBN -- NOT defined */
/* HAVE_SCALBNF -- NOT defined */
/*
 * m68k AmigaOS3 runtime note:
 * do not use the C library sin(); SDL_sin() uses the AmigaOS3 lookup table.
 */
/* HAVE_SIN -- intentionally NOT defined on AmigaOS3 */
/* HAVE_SINF -- NOT defined */
#define HAVE_SQRT       1
/* HAVE_SQRTF -- NOT defined */
#define HAVE_TAN        1
/* HAVE_TANF -- NOT defined */
/* HAVE_TRUNC -- NOT defined */
/* HAVE_TRUNCF -- NOT defined */

/* POSIX features NOT available in libnix / AmigaOS 3.x */
/* HAVE_GETENV -- NOT defined (no POSIX getenv) */
/* HAVE_SETENV -- NOT defined */
/* HAVE_PUTENV -- NOT defined */
/* HAVE_UNSETENV -- NOT defined */
#define HAVE_QSORT      1
#define HAVE_ABS        1
#define HAVE_CTYPE_H    1
#define HAVE_MATH_H     1
#define HAVE_FLOAT_H    1
#define HAVE_LIMITS_H   1
/* HAVE_SIGNAL_H -- intentionally NOT defined (no POSIX signals on AmigaOS) */
/* HAVE_ICONV_H -- intentionally NOT defined */
/* HAVE_ICONV -- intentionally NOT defined */
/* HAVE_SYS_TYPES_H -- intentionally NOT defined */
#define HAVE_STDIO_H    1
#define HAVE_STRING_H   1
/* HAVE_WCHAR_H -- intentionally NOT defined */
/* HAVE_INTTYPES_H -- intentionally NOT defined */
/* HAVE_STRINGS_H -- intentionally NOT defined */
/* HAVE_MPROTECT -- intentionally NOT defined */
/* HAVE_SIGACTION -- intentionally NOT defined */

/* Byte order -- 68k is big-endian */
#define SDL_BYTEORDER   SDL_BIG_ENDIAN

/* Atomics -- 68020+ has CAS instruction via our SDL_spinlock.c path.
   GCC builtins (__sync_*) generate external function calls on 68k that
   don't exist in any library. Must NOT be defined at all. */
/* HAVE_GCC_ATOMICS -- intentionally NOT defined */
/* HAVE_GCC_SYNC_LOCK_TEST_AND_SET -- intentionally NOT defined */

/* Dynamic API -- disabled in src/dynapi/SDL_dynapi.h via __AMIGAOS3__ check */

/* --- VIDEO DRIVERS --- */
#define SDL_VIDEO_DRIVER_AMIGAOS3   1
#if !defined(WARPUP)
#if !defined(SDL_AMIGAOS3_SW_ONLY)
#define SDL_VIDEO_OPENGL            1   /* minigl.library backend (68k) */
#endif
#endif
#define SDL_VIDEO_DRIVER_DUMMY      1   /* fallback */

/* --- AUDIO DRIVERS --- */
#define SDL_AUDIO_DRIVER_AHI        1
#define SDL_AUDIO_DRIVER_PAULA      1
#define SDL_AUDIO_DRIVER_DUMMY      1   /* fallback */

/* --- RENDER DRIVERS --- */
#define SDL_VIDEO_RENDER_SW         1   /* software renderer */

/* --- THREADING --- */
#define SDL_THREAD_AMIGAOS3         1

/* --- TIMER --- */
#define SDL_TIMER_AMIGAOS3          1

/* --- JOYSTICK --- */
#define SDL_JOYSTICK_AMIGAOS3       1

/* --- HAPTIC --- */
#define SDL_HAPTIC_DISABLED         1

/* --- HIDAPI --- */
#define SDL_HIDAPI_DISABLED         1

/* --- SENSOR --- */
#define SDL_SENSOR_DISABLED         1

/* --- LOADSO --- */
#define SDL_LOADSO_DISABLED         1

/* --- FILESYSTEM --- */
#define SDL_FILESYSTEM_AMIGAOS3     1

/* --- POWER --- */
#define SDL_POWER_DISABLED          1

/* --- LOCALE --- */
#define SDL_LOCALE_DISABLED         1

/* --- MISC --- */
#define SDL_MISC_DISABLED           1

#endif /* SDL_config_amigaos3_h_ */
