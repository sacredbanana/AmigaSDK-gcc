/*
 * $Id: clip.h 283 2008-05-11 13:37:14Z tfrieden $
 *
 * $Date: 2008-05-11 17:37:14 +0400 (Sun, 11 May 2008) $
 * $Revision: 283 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */


#ifndef _CLIP_H
#define _CLIP_H

#include "mgl/mgltypes.h"

void        hc_CodePoint(GLcontext context, MGLVertex *v);
GLboolean   hc_DecideFrontface(GLcontext context, MGLVertex *a, MGLVertex *b, MGLVertex *c, GLuint outcode);


#endif



