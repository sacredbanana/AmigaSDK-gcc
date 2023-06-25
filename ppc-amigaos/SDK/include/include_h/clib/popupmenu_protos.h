#ifndef CLIB_POPUPMENU_PROTOS_H
#define CLIB_POPUPMENU_PROTOS_H


/*
**    $Id: popupmenu_protos.h,v 1.6 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**    All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   CLASSES_POPUPMENU_H
#include <classes/popupmenu.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

Class * POPUPMENU_GetClass(void);
Class * POPUPMENU_GetItemClass(void);
APTR POPUPMENU_MakeMXListA(ULONG * ids);
APTR POPUPMENU_MakeMXList(ULONG ids, ...);
VOID POPUPMENU_FreeIDList(APTR idlist);
APTR POPUPMENU_MakeIDListA(struct TagItem * tags);
APTR POPUPMENU_MakeIDList(Tag tags, ...);

#endif /*  CLIB_POPUPMENU_PROTOS_H  */
