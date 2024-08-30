#ifndef CLIB_LAYOUT_PROTOS_H
#define CLIB_LAYOUT_PROTOS_H

/*
	layout.gadget C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef GADGETS_LAYOUT_H
# include <gadgets/layout.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

Class *LAYOUT_GetClass( VOID );
BOOL ActivateLayoutGadget( struct Gadget *gadget, struct Window *window, struct Requester *requester, ULONG object );
VOID FlushLayoutDomainCache( struct Gadget *gadget );
BOOL RethinkLayout( struct Gadget *gadget, struct Window *window, struct Requester *requester, LONG refresh );
VOID LayoutLimits( struct Gadget *gadget, struct LayoutLimits *limits, struct TextFont *font, struct Screen *screen );

Class *PAGE_GetClass( VOID );
ULONG SetPageGadgetAttrsA( struct Gadget *gadget, Object *object, struct Window *window, struct Requester *requester, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG SetPageGadgetAttrs( struct Gadget *gadget, Object *object, struct Window *window, struct Requester *requester, ... );
#endif
VOID RefreshPageGadget( struct Gadget *gadget, Object *object, struct Window *window, struct Requester *requester );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_LAYOUT_PROTOS_H */
