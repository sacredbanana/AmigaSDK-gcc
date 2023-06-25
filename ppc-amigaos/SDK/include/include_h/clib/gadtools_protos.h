#ifndef CLIB_GADTOOLS_PROTOS_H
#define CLIB_GADTOOLS_PROTOS_H

/*
**    $Id: gadtools_protos.h,v 1.9 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef   LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
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

/*--- functions in V36 or higher (Release 2.0) ---*/

/* Gadget Functions */

struct Gadget *CreateGadgetA( ULONG kind, struct Gadget *gad, CONST struct NewGadget *ng, CONST struct TagItem *taglist );
struct Gadget *CreateGadget( ULONG kind, struct Gadget *gad, CONST struct NewGadget *ng, Tag tag1, ... );
VOID FreeGadgets( struct Gadget *gad );
VOID GT_SetGadgetAttrsA( struct Gadget *gad, struct Window *win, struct Requester *req, CONST struct TagItem *taglist );
VOID GT_SetGadgetAttrs( struct Gadget *gad, struct Window *win, struct Requester *req, Tag tag1, ... );

/* Menu functions */

struct Menu *CreateMenusA( CONST struct NewMenu *newmenu, CONST struct TagItem *taglist );
struct Menu *CreateMenus( CONST struct NewMenu *newmenu, Tag tag1, ... );
VOID FreeMenus( struct Menu *menu );
BOOL LayoutMenuItemsA( struct MenuItem *firstitem, APTR vi, CONST struct TagItem *taglist );
BOOL LayoutMenuItems( struct MenuItem *firstitem, APTR vi, Tag tag1, ... );
BOOL LayoutMenusA( struct Menu *firstmenu, APTR vi, CONST struct TagItem *taglist );
BOOL LayoutMenus( struct Menu *firstmenu, APTR vi, Tag tag1, ... );

/* Misc Event-Handling Functions */

struct IntuiMessage *GT_GetIMsg( struct MsgPort *iport );
VOID GT_ReplyIMsg( struct IntuiMessage *imsg );
VOID GT_RefreshWindow( struct Window *win, struct Requester *req );
VOID GT_BeginRefresh( struct Window *win );
VOID GT_EndRefresh( struct Window *win, LONG complete );
struct IntuiMessage *GT_FilterIMsg( CONST struct IntuiMessage *imsg );
struct IntuiMessage *GT_PostFilterIMsg( struct IntuiMessage *imsg );
struct Gadget *CreateContext( struct Gadget **glistptr );

/* Rendering Functions */

VOID DrawBevelBoxA( struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, CONST struct TagItem *taglist );
VOID DrawBevelBox( struct RastPort *rport, LONG left, LONG top, LONG width, LONG height, Tag tag1, ... );

/* Visuals Functions */

APTR GetVisualInfoA( struct Screen *screen, CONST struct TagItem *taglist );
APTR GetVisualInfo( struct Screen *screen, Tag tag1, ... );
VOID FreeVisualInfo( APTR vi );

/*--- functions in V39 or higher (Release 3) ---*/

LONG GT_GetGadgetAttrsA( struct Gadget *gad, struct Window *win, struct Requester *req, CONST struct TagItem *taglist );
LONG GT_GetGadgetAttrs( struct Gadget *gad, struct Window *win, struct Requester *req, Tag tag1, ... );



#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_GADTOOLS_PROTOS_H */
