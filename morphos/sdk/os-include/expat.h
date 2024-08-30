/*
	libexpat.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2012 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <expat.h>

#else

#ifndef EXPAT_H
#define EXPAT_H

#include <libraries/expat.h>
#include <proto/expat.h>

#endif /* EXPAT_H */

#endif /* __MORPHOS_SHAREDLIBS */
