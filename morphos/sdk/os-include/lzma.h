/*
	liblzma.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2010 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <lzma.h>

#else

#ifndef LZMA_H
#define LZMA_H

#include <libraries/lzma.h>
#include <proto/lzma.h>

#endif /* LZMA_H */

#endif /* __MORPHOS_SHAREDLIBS */
