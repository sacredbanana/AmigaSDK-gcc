/*
	libjpeg.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2003-2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <jpeglib.h>

#else

#ifndef JPEGLIB_H
#define JPEGLIB_H

#define JCONFIG_INCLUDED

#include <libraries/jfif.h>
#include <proto/jfif.h>

#endif /* JPEGLIB_H */

#endif /* __MORPHOS_SHAREDLIBS */
