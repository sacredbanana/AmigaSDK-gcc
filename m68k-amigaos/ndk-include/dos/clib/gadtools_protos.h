#ifndef CLIB_GADTOOLS_PROTOS_H
#define CLIB_GADTOOLS_PROTOS_H

/*
**	$VER: gadtools_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
#endif

/*--- functions in V36 or higher (Release 2.0) ---*/

/* Gadget Functions */

struct Gadget * __stdargs CreateGadgetA( ULONG kind, struct Gadget *gad, struct NewGadget *ng, CONST struct TagItem *taglist );
struct Gadget * __stdargs CreateGadget( ULONG kind, struct Gadget *gad, struct NewGadget *ng, ... );
VOID  __stdargs FreeGadgets( struct Gadget *gad );
VOID  __stdargs GT_SetGadgetAttrsA( struct Gadget *gad, struct Window *win, struct Requester *req, CONST struct TagItem *taglist );
VOID  __stdargs GT_SetGadgetAttrs( struct Gadget *gad, struct Window *win, struct Requester *req, ... );

/* Menu functions */

struct Menu * __stdargs CreateMenusA( CONST struct NewMenu *newmenu, struct TagItem *taglist );
struct Menu * __stdargs CreateMenus( CONST struct NewMenu *newmenu, ... );
VOID  __stdargs FreeMenus( struct Menu *menu );
BOOL  __stdargs LayoutMenuItemsA( struct MenuItem *firstitem, APTR vi, CONST struct TagItem *taglist );
BOOL  __stdargs LayoutMenuItems( struct MenuItem *firstitem, APTR vi, ... );
BOOL  __stdargs LayoutMenusA( struct Menu *firstmenu, APTR vi, CONST struct TagItem *taglist );
BOOL  __stdargs LayoutMenus( struct Menu *firstmenu, APTR vi, ... );

/* Misc Event-Handling Functions */

struct IntuiMessage * __stdargs GT_GetIMsg( struct MsgPort *iport );
VOID  __stdargs GT_ReplyIMsg( struct IntuiMessage *imsg );
VOID  __stdargs GT_RefreshWindow( struct Window *win, struct Requester *req );
VOID  __stdargs GT_BeginRefresh( struct Window *win );
VOID  __stdargs GT_EndRefresh( struct Window *win, LONG complete );
struct IntuiMessage * __stdargs GT_FilterIMsg( CONST struct IntuiMessage *imsg );
struct IntuiMessage * __stdargs GT_PostFilterIMsg( struct IntuiMessage *imsg );
struct Gadget * __stdargs CreateContext( struct Gadget **glistptr );

/* Rendering Functions */

VOID  __stdargs DrawBevelBoxA( struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, CONST struct TagItem *taglist );
VOID  __stdargs DrawBevelBox( struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, ... );

/* Visuals Functions */

APTR  __stdargs GetVisualInfoA( struct Screen *screen, CONST struct TagItem *taglist );
APTR  __stdargs GetVisualInfo( struct Screen *screen, ... );
VOID  __stdargs FreeVisualInfo( APTR vi );

/* New in V47 */

/*--- functions in V47 or higher (Release 3.2) ---*/
LONG  __stdargs SetDesignFontA( APTR vi, struct TextAttr *tattr, CONST struct TagItem *tags );
LONG  __stdargs SetDesignFont( APTR vi, struct TextAttr *tattr, ... );
LONG  __stdargs ScaleGadgetRectA( struct NewGadget *ng, CONST struct TagItem *tags );
LONG  __stdargs ScaleGadgetRect( struct NewGadget *ng, ... );


/*--- functions in V39 or higher (Release 3.0) ---*/

LONG  __stdargs GT_GetGadgetAttrsA( struct Gadget *gad, struct Window *win, struct Requester *req, CONST struct TagItem *taglist );
LONG  __stdargs GT_GetGadgetAttrs( struct Gadget *gad, struct Window *win, struct Requester *req, ... );


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_GADTOOLS_PROTOS_H */
