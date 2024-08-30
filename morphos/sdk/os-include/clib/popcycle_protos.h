#ifndef CLIB_POPCYCLE_PROTOS_H
#define CLIB_POPCYCLE_PROTOS_H

/*
	popcycle.gadget C prototypes

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

Class *POPCYCLE_GetClass( VOID );
struct Node *AllocPopCycleNodeA( struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Node *AllocPopCycleNode( Tag firstTag, ... );
#endif
VOID FreePopCycleNode( struct Node *node );
VOID SetPopCycleNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID SetPopCycleNodeAttrs( struct Node *node, ... );
#endif
VOID GetPopCycleNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID GetPopCycleNodeAttrs( struct Node *node, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_POPCYCLE_PROTOS_H */
