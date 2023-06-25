#ifndef CLIB_LISTVIEW_H
#define CLIB_LISTVIEW_H
/*
**    $Id: listview_protos.h,v 1.7 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

Class * LISTVIEW_GetClass(VOID);


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* CLIB_LISTVIEW_PROTOS_H */
