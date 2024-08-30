/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2006 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/

#ifndef _SDL_config_amiga_h
#define _SDL_config_amiga_h

#include "SDL_platform.h"
#include <exec/types.h>

#ifndef _HAVE_STDINT_H
/* This is a set of defines to configure the SDL features */

#ifndef _INT8_T_DECLARED
typedef signed char         			int8_t;
#define _INT8_T_DECLARED
#endif

#ifndef _UINT8_T_DECLARED
typedef unsigned char       			uint8_t;
#define _UINT8_T_DECLARED
#endif

#ifndef _INT16_T_DECLARED
typedef signed short        			int16_t;
#define _INT16_T_DECLARED
#endif

#ifndef _UINT16_T_DECLARED
typedef unsigned short      			uint16_t;
#define _UINT16_T_DECLARED
#endif

#ifndef _INT32_T_DECLARED
typedef signed int          			int32_t;
#define _INT32_T_DECLARED
#endif

#ifndef _UINT32_T_DECLARED
typedef unsigned int					uint32_t;
#define _UINT32_T_DECLARED
#endif

#ifndef size_t
//typedef unsigned int        size_t;
#endif

#ifndef _UINTPTR_T_DECLARED
typedef unsigned int					uintptr_t;
#define _UINTPTR_T_DECLARED
#endif

#ifndef _INT64_T_DECLARED
typedef signed long long				int64_t;
#define _INT64_T_DECLARED
#endif

#ifndef _UINT64_T_DECLARED
typedef unsigned long long				uint64_t;
#define _UINT64_T_DECLARED
#endif

#endif /* _HAVE_STDINT_H */

#define SDL_HAS_64BIT_TYPE				1
#define SDL_BYTEORDER					SDL_BIG_ENDIAN

//#define HAVE_LIBC						1

/* Useful headers */
#define HAVE_SYS_TYPES_H				1
#define HAVE_STDIO_H					1
#define STDC_HEADERS					1
#define HAVE_STDLIB_H					1
#define HAVE_STDARG_H					1
#define HAVE_MALLOC_H					1
#define HAVE_MEMORY_H					1
#define HAVE_STRING_H					1
#define HAVE_STRINGS_H					1
//#define HAVE_INTTYPES_H				1
#define HAVE_STDINT_H					1
#define HAVE_CTYPE_H					1
#define HAVE_MATH_H						1
//#define HAVE_SIGNAL_H		0

/* C library functions */
#define HAVE_MALLOC						1
#define HAVE_CALLOC						1
#define HAVE_REALLOC					1
#define HAVE_FREE						1
#define HAVE_ALLOCA						1
#define HAVE_GETENV						1
#define HAVE_PUTENV						1
#define HAVE_UNSETENV					1
#define HAVE_QSORT						1
#define HAVE_ABS						1
#define HAVE_BCOPY						1
#define HAVE_MEMSET						1
#define HAVE_MEMCPY						1
#define HAVE_MEMMOVE					1
#define SDL_revcpy						memmove
#define HAVE_MEMCMP						1
#define HAVE_STRLEN						1
#define HAVE_STRLCAT					1
#define HAVE_STRDUP						1
#define HAVE__STRUPR					1
#define HAVE__STRLWR					1
#define HAVE_INDEX						1
#define HAVE_STRCHR						1
#define HAVE_STRRCHR					1
#define HAVE_STRSTR						1
#define HAVE_ITOA						1
#define HAVE__LTOA						1
#define HAVE__UITOA						1
#define HAVE__ULTOA						1
#define HAVE_STRTOL						1
#define HAVE__I64TOA					1
#define HAVE__UI64TOA					1
#define HAVE_STRTOLL					1
#define HAVE_STRTOD						1
#define HAVE_ATOI						1
#define HAVE_ATOF						1
#define HAVE_STRCMP						1
#define HAVE_STRNCMP					1
#define HAVE_STRICMP					1
#define HAVE_STRCASECMP					1
#define HAVE_SSCANF						1
#define HAVE_SNPRINTF					1
#define HAVE_VSNPRINTF					1
#define HAVE_SETJMP						1
#define HAVE_CLOCK_GETTIME				1

/* Enable various audio drivers */
#define SDL_AUDIO_DRIVER_AHI			1
//#define SDL_AUDIO_DRIVER_DISK			1
//#define SDL_AUDIO_DRIVER_DUMMY			1

/* Enable various cdrom drivers */
//#define SDL_CDROM_DISABLED				1
//#define SDL_CDROM_AMIGA				1
#define SDL_CDROM_DUMMY					1

/* Enable various input drivers */
#define SDL_JOYSTICK_AMIGA				1

/* Enable various shared object loading systems */
//#define SDL_LOADSO_AMIGA				1

/* Enable various threading systems */
#define SDL_THREAD_AMIGA				1

/* Enable various timer systems */
#define SDL_TIMER_AMIGA					1

/* Enable various video drivers */
#define SDL_VIDEO_DRIVER_CYBERGRAPHICS	1

/* Enable OpenGL support */
//#define SDL_VIDEO_OPENGL				1

#define __MEM_AMIGA						1

/* Enable assembly routines where available */
#define SDL_ASSEMBLY_ROUTINES			1

#define SDL_AMIGA_NOWINDOW				0x10000

#ifdef __cplusplus
extern "C" {
#endif
void SDL_AmigaLockWindow(void);
void SDL_AmigaUnlockWindow(void);
struct Window * SDL_AmigaWindowAddr(void);
#ifdef __cplusplus
}
#endif
#endif /* _SDL_config_amiga_h */
