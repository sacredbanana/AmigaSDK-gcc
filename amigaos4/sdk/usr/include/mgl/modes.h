/*
 * $Id: modes.h 391 2009-11-23 00:16:34Z HansR $
 *
 * $Date: 2009-11-23 03:16:34 +0300 (Mon, 23 Nov 2009) $
 * $Revision: 391 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef __MGL_MODES_H
#define __MGL_MODES_H

#include <warp3d/warp3d.h>

#define MGL_MAX_MODE 80

typedef struct
{
        GLint id;               // blackbox id used for mglCreateContextID()
        GLint width,height;     // screenmode size
        GLint bit_depth;        // depth of mode
        char  mode_name[MGL_MAX_MODE]; // name for this mode
} MGLScreenMode;

typedef struct
{
        ULONG width,height,depth;
        ULONG pixel_format;
        void *base_address;
        ULONG pitch;
} MGLLockInfo;

typedef GLboolean (*MGLScreenModeCallback)(MGLScreenMode *);

#endif
