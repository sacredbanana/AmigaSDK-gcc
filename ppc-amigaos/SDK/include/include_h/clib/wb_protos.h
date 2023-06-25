#ifndef CLIB_WB_PROTOS_H
#define CLIB_WB_PROTOS_H

/*
**    $Id: wb_protos.h,v 1.12 2010-01-31 01:29:03 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef   WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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
VOID UpdateWorkbench( CONST_STRPTR name, ULONG lock, LONG action );

struct AppWindow *AddAppWindowA( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, struct TagItem *taglist );
struct AppWindow *AddAppWindow( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, Tag tag1, ... );

BOOL RemoveAppWindow( struct AppWindow *appWindow );

struct AppIcon *AddAppIconA( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, struct TagItem *taglist );
struct AppIcon *AddAppIcon( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, Tag tag1, ... );

BOOL RemoveAppIcon( struct AppIcon *appIcon );

struct AppMenuItem *AddAppMenuItemA( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, struct TagItem *taglist );
struct AppMenuItem *AddAppMenuItem( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, Tag tag1, ... );

BOOL RemoveAppMenuItem( struct AppMenuItem *appMenuItem );

/*--- functions in V39 or higher (Release 3) ---*/

ULONG WBInfo( BPTR lock, STRPTR name, struct Screen *screen );

/*--- functions in V44 or higher (Release 3.5) ---*/

BOOL OpenWorkbenchObjectA( STRPTR name, struct TagItem *tags );
BOOL OpenWorkbenchObject( STRPTR name, Tag tag1, ... );
BOOL CloseWorkbenchObjectA( STRPTR name, struct TagItem *tags );
BOOL CloseWorkbenchObject( STRPTR name, Tag tag1, ... );
BOOL WorkbenchControlA( STRPTR name, struct TagItem *tags );
BOOL WorkbenchControl( STRPTR name, Tag tag1, ... );
struct AppWindowDropZone *AddAppWindowDropZoneA( struct AppWindow *aw, ULONG id, ULONG userdata, struct TagItem *tags );
struct AppWindowDropZone *AddAppWindowDropZone( struct AppWindow *aw, ULONG id, ULONG userdata, Tag tag1, ... );
BOOL RemoveAppWindowDropZone( struct AppWindow *aw, struct AppWindowDropZone *dropZone );
BOOL ChangeWorkbenchSelectionA( STRPTR name, struct Hook *hook, struct TagItem *tags );
BOOL ChangeWorkbenchSelection( STRPTR name, struct Hook *hook, Tag tag1, ... );
BOOL MakeWorkbenchObjectVisibleA( STRPTR name, struct TagItem *tags );
BOOL MakeWorkbenchObjectVisible( STRPTR name, Tag tag1, ... );

/*--- functions in V50 or higher (Release 4) ---*/

ULONG WhichWorkbenchObjectA( struct Window *window, LONG x, LONG y, struct TagItem *tags );
ULONG WhichWorkbenchObject( struct Window *window, LONG x, LONG y, Tag tag1, ... );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_WB_PROTOS_H */
