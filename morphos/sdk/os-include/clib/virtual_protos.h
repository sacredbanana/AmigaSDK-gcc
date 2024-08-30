#ifndef CLIB_VIRTUAL_PROTOS_H
#define CLIB_VIRTUAL_PROTOS_H

/*
	virtual.gadget C prototypes

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

struct IClass *VIRTUAL_GetClass( VOID );
VOID RefreshVirtualGadget( struct Gadget *gadget, ULONG obj, struct Window *window, struct Requester *requester );
BOOL RethinkVirtualSize( ULONG virt_obj, ULONG rootlayout, struct TextFont *font, struct Screen *screen, struct LayoutLimits *layoutlimits );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_VIRTUAL_PROTOS_H */
