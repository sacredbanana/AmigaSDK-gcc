#ifndef CLIB_GADTOOLS_PROTOS_H
#define CLIB_GADTOOLS_PROTOS_H

/*
	gadtools.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef LIBRARIES_GADTOOLS_H
# include <libraries/gadtools.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Gadget *CreateGadgetA( ULONG kind, struct Gadget *gad, CONST struct NewGadget *ng, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
struct Gadget *CreateGadget( ULONG kind, struct Gadget *gad, CONST struct NewGadget *ng, Tag tag1, ... );
#endif
VOID FreeGadgets( struct Gadget *gad );
VOID GT_SetGadgetAttrsA( struct Gadget *gad, struct Window *win, struct Requester *req, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
VOID GT_SetGadgetAttrs( struct Gadget *gad, struct Window *win, struct Requester *req, Tag tag1, ... );
#endif

struct Menu *CreateMenusA( CONST struct NewMenu *newmenu, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
struct Menu *CreateMenus( CONST struct NewMenu *newmenu, Tag tag1, ... );
#endif
VOID FreeMenus( struct Menu *menu );
BOOL LayoutMenuItemsA( struct MenuItem *firstitem, APTR vi, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
BOOL LayoutMenuItems( struct MenuItem *firstitem, APTR vi, Tag tag1, ... );
#endif
BOOL LayoutMenusA( struct Menu *firstmenu, APTR vi, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
BOOL LayoutMenus( struct Menu *firstmenu, APTR vi, Tag tag1, ... );
#endif

struct IntuiMessage *GT_GetIMsg( struct MsgPort *iport );
VOID GT_ReplyIMsg( struct IntuiMessage *imsg );
VOID GT_RefreshWindow( struct Window *win, struct Requester *req );
VOID GT_BeginRefresh( struct Window *win );
VOID GT_EndRefresh( struct Window *win, LONG complete );
struct IntuiMessage *GT_FilterIMsg( CONST struct IntuiMessage *imsg );
struct IntuiMessage *GT_PostFilterIMsg( struct IntuiMessage *imsg );
struct Gadget *CreateContext( struct Gadget **glistptr );

VOID DrawBevelBoxA( struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
VOID DrawBevelBox( struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, Tag tag1, ... );
#endif

APTR GetVisualInfoA( struct Screen *screen, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
APTR GetVisualInfo( struct Screen *screen, Tag tag1, ... );
#endif
VOID FreeVisualInfo( APTR vi );

LONG GT_GetGadgetAttrsA( struct Gadget *gad, struct Window *win, struct Requester *req, CONST struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
LONG GT_GetGadgetAttrs( struct Gadget *gad, struct Window *win, struct Requester *req, Tag tag1, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_GADTOOLS_PROTOS_H */
