#ifndef CLIB_SPEEDBAR_PROTOS_H
#define CLIB_SPEEDBAR_PROTOS_H

/*
	speedbar.gadget C prototypes

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

Class *SPEEDBAR_GetClass( VOID );
struct Node *AllocSpeedButtonNodeA( ULONG number, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Node *AllocSpeedButtonNode( ULONG number, Tag firstTag, ... );
#endif
VOID FreeSpeedButtonNode( struct Node *node );
VOID SetSpeedButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID SetSpeedButtonNodeAttrs( struct Node *node, ... );
#endif
VOID GetSpeedButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID GetSpeedButtonNodeAttrs( struct Node *node, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_SPEEDBAR_PROTOS_H */
