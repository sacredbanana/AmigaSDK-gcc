#ifndef CLIB_CLICKTAB_PROTOS_H
#define CLIB_CLICKTAB_PROTOS_H

/*
	clicktab.gadget C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

Class *CLICKTAB_GetClass( VOID );
struct Node *AllocClickTabNodeA( struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Node *AllocClickTabNode( Tag firstTag, ... );
#endif
VOID FreeClickTabNode( struct Node *node );
VOID SetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID SetClickTabNodeAttrs( struct Node *node, ... );
#endif
VOID GetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID GetClickTabNodeAttrs( struct Node *node, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_CLICKTAB_PROTOS_H */
