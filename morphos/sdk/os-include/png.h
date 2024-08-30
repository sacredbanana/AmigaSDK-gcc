/*
	libpng.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2003-2004 The MorphOS Development Team, All Rights Reserved.
*/

#if !defined(__MORPHOS_SHAREDLIBS) || defined(__ixemul__)

#include_next <png.h>

#else

#ifndef PNG_H
#define PNG_H

#define PNGCONF_H

#include <libraries/png.h>
#include <proto/png.h>

#endif /* PNG_H */

#endif /* __MORPHOS_SHAREDLIBS */
