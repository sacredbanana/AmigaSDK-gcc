#ifndef CLIB_CHOOSER_PROTOS_H
#define CLIB_CHOOSER_PROTOS_H

/*
	chooser.gadget C prototypes

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

Class *CHOOSER_GetClass( VOID );
struct Node *AllocChooserNodeA( struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Node *AllocChooserNode( Tag firstTag, ... );
#endif
VOID FreeChooserNode( struct Node *node );
VOID SetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID SetChooserNodeAttrs( struct Node *node, ... );
#endif
VOID GetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID GetChooserNodeAttrs( struct Node *node, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_CHOOSER_PROTOS_H */
