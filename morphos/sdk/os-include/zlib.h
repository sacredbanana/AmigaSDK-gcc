/*
	libz.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2003-2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <zlib.h>

#else

#ifndef ZLIB_H
#define ZLIB_H

#define ZCONF_H

#include <libraries/z.h>
#include <proto/z.h>

#endif /* ZLIB_H */

#endif /* __MORPHOS_SHAREDLIBS */
