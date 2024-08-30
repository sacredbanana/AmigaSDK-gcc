#ifndef CLIB_SKETCHBOARD_PROTOS_H
#define CLIB_SKETCHBOARD_PROTOS_H

/*
**    $Id: sketchboard_protos.h,v 1.6 2010-01-31 01:29:03 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**    All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

Class * SKETCHBOARD_GetClass(void);

#endif /*  CLIB_SKETCHBOARD_PROTOS_H  */
