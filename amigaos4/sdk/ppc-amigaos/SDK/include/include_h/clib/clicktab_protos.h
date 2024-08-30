#ifndef CLIB_CLICKTAB_PROTOS_H
#define CLIB_CLICKTAB_PROTOS_H

/*
**    $Id: clicktab_protos.h,v 1.7 2010-01-31 01:29:01 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
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

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

Class *CLICKTAB_GetClass( VOID );
struct Node *AllocClickTabNodeA( struct TagItem *tags );
struct Node *AllocClickTabNode( Tag firstTag, ... );
VOID FreeClickTabNode( struct Node *node );
VOID SetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID SetClickTabNodeAttrs( struct Node *node, ... );
VOID GetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID GetClickTabNodeAttrs( struct Node *node, ... );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CLICKTAB_PROTOS_H */
