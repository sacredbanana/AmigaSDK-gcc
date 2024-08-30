#ifndef CLIB_RADIOBUTTON_PROTOS_H
#define CLIB_RADIOBUTTON_PROTOS_H

/*
	radiobutton.gadget C prototypes

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

Class *RADIOBUTTON_GetClass( VOID );
struct Node *AllocRadioButtonNodeA( ULONG columns, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Node *AllocRadioButtonNode( ULONG columns, Tag firstTag, ... );
#endif
VOID FreeRadioButtonNode( struct Node *node );
VOID SetRadioButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID SetRadioButtonNodeAttrs( struct Node *node, ... );
#endif
VOID GetRadioButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID GetRadioButtonNodeAttrs( struct Node *node, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_RADIOBUTTON_PROTOS_H */
