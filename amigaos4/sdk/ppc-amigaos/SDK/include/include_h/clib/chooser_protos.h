#ifndef CLIB_CHOOSER_PROTOS_H
#define CLIB_CHOOSER_PROTOS_H

/*
**    $Id: chooser_protos.h,v 1.7 2010-01-31 01:29:00 ssolie Exp $
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

Class *CHOOSER_GetClass( VOID );
struct Node *AllocChooserNodeA( struct TagItem *tags );
struct Node *AllocChooserNode( Tag firstTag, ... );
VOID FreeChooserNode( struct Node *node );
VOID SetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID SetChooserNodeAttrs( struct Node *node, ... );
VOID GetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID GetChooserNodeAttrs( struct Node *node, ... );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CHOOSER_PROTOS_H */
