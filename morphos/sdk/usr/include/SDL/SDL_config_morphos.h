/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2009 Sam Lantinga

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

#ifndef _SDL_config_morphos_h
#define _SDL_config_morphos_h

/* This is a set of defines to configure the SDL features */

#include <stdint.h>

#ifndef __ppc__
#define __ppc__ 1
#endif

#define SDL_HAS_64BIT_TYPE	1

/* Useful headers */
#define STDC_HEADERS	1
#undef HAVE_STDIO_H
#define HAVE_STRING_H	1
#define HAVE_CTYPE_H	1
#define HAVE_MATH_H	1
//#define HAVE_SIGNAL_H	1

/* C library functions */
#define HAVE_MALLOC	1
#define HAVE_CALLOC	1
#define HAVE_REALLOC	1
#define HAVE_FREE	1
#define HAVE_ALLOCA	1
#define HAVE_ABS	1
#define HAVE_MEMSET	1
#define HAVE_MEMCPY	1
#define HAVE_MEMMOVE	1
#define HAVE_MEMCMP	1
#define HAVE_STRLEN	1
#define HAVE_STRCHR	1
#define HAVE_STRRCHR	1
#define HAVE_STRSTR	1
#define HAVE_ITOA	1
#define HAVE_STRTOL	1
#define HAVE_STRTOD	1
#define HAVE_ATOI	1
#define HAVE_ATOF	1
#define HAVE_STRCMP	1
#define HAVE_STRNCMP	1
#define HAVE_SSCANF	1

/* Enable various audio drivers */
#define SDL_AUDIO_DRIVER_AHI	1

/* Enable various cdrom drivers */
#define SDL_CDROM_AMIGA		1

/* Enable various input drivers */
#define SDL_JOYSTICK_AMIGA	1

/* Enable various shared object loading systems */
#define SDL_LOADSO_AMIGA	1

/* Enable various threading systems */
#define SDL_THREAD_AMIGA	1

/* Enable various timer systems */
#define SDL_TIMER_AMIGA	1

/* Enable various video drivers */
#define SDL_VIDEO_DRIVER_CYBERGRAPHICS	1

/* Enable OpenGL support */
#define SDL_VIDEO_OPENGL	1

/* Enable assembly routines */
#define SDL_ASSEMBLY_ROUTINES	1
#ifdef __PPC__
#define SDL_ALTIVEC_BLITTERS	1
#endif

/* AHI driver external */
extern int has_obtained_spec;

#define VECTOR_ULONG_TYPEDEF
#define VECTOR_LONG_TYPEDEF
#define VECTOR_UWORD_TYPEDEF
#define VECTOR_WORD_TYPEDEF
#define VECTOR_UBYTE_TYPEDEF
#define VECTOR_BYTE_TYPEDEF
#define VECTOR_FLOAT_TYPEDEF

/* Other externals */
#if defined(__POWERSDL_INTERNAL)
#include "Library.h"
#include "SDL_cgxasm.h"

extern struct SDL_Library *PowerSDLBase;

#if !defined(NO_AMIGADEBUG)
#include "mydebug.h"
#endif
#endif

#if (__GNUC__ > 2)
#define HAVE_ALTIVEC_H 1
#endif

#endif /* _SDL_config_morphos_h */
