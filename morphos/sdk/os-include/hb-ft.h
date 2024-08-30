/*
	libharfbuzz.a wrapper

	Basically includes the MorphOS-style library headers here, so that
	code doesn't need to be changed to be portable.

	Copyright © 2016 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef __MORPHOS_SHAREDLIBS

#include_next <hb-ft.h>

#else

#ifndef HB_FT_H
#define HB_FT_H

#include <libraries/harfbuzz.h>
#include <proto/harfbuzz.h>

#endif /* HB_FT_H */

#endif /* __MORPHOS_SHAREDLIBS */
