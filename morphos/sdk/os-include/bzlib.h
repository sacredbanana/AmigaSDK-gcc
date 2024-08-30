/*
 *  libbz2.a wrapper
 *
 *  Basically includes the MorphOS-style library headers here, so that
 *  code doesn't need to be changed to be portable.
 *
 *  Copyright © 2016 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef __MORPHOS_SHAREDLIBS

#include_next <bzlib.h>

#else

#ifndef _BZLIB_H
#define _BZLIB_H

#include <libraries/bz2.h>
#include <proto/bz2.h>

#endif /* _BZLIB_H */

#endif /* __MORPHOS_SHAREDLIBS */
