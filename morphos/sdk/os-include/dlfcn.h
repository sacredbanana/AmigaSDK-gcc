/*
	libdl.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2005 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <dlfcn.h>

#else

#ifndef _DLFCN_H_
#define _DLFCN_H_

#include <proto/dynload.h>

#endif /* _DLFCN_H_ */

#endif /* __MORPHOS_SHAREDLIBS */
