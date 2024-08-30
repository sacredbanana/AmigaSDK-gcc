/*
	libtiff.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2003-2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <tiff.h>

#else

#ifndef _TIFF_
#define _TIFF_

#include <libraries/tiff.h>

#endif /* _TIFF_ */

#endif /* __MORPHOS_SHAREDLIBS */
