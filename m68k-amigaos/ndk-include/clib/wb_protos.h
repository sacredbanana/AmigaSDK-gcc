#ifndef CLIB_WB_PROTOS_H
#define CLIB_WB_PROTOS_H

/*
**	$VER: wb_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*--- functions in V36 or higher (Release 2.0) ---*/
#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

VOID  __stdargs UpdateWorkbench( CONST_STRPTR name, BPTR lock, LONG action );

struct AppWindow * __stdargs AddAppWindowA( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, CONST struct TagItem *taglist );
struct AppWindow * __stdargs AddAppWindow( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, ... );

BOOL  __stdargs RemoveAppWindow( struct AppWindow *appWindow );

struct AppIcon * __stdargs AddAppIconA( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, CONST struct TagItem *taglist );
struct AppIcon * __stdargs AddAppIcon( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, ... );

BOOL  __stdargs RemoveAppIcon( struct AppIcon *appIcon );

struct AppMenuItem * __stdargs AddAppMenuItemA( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, CONST struct TagItem *taglist );
struct AppMenuItem * __stdargs AddAppMenuItem( ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort *msgport, ... );

BOOL  __stdargs RemoveAppMenuItem( struct AppMenuItem *appMenuItem );

/*--- functions in V39 or higher (Release 3.0) ---*/


ULONG  __stdargs WBInfo( BPTR lock, CONST_STRPTR name, struct Screen *screen );

/*--- functions in V44 or higher (Release 3.5) ---*/
BOOL  __stdargs OpenWorkbenchObjectA( CONST_STRPTR name, CONST struct TagItem *tags );
BOOL  __stdargs OpenWorkbenchObject( CONST_STRPTR name, ... );
BOOL  __stdargs CloseWorkbenchObjectA( CONST_STRPTR name, CONST struct TagItem *tags );
BOOL  __stdargs CloseWorkbenchObject( CONST_STRPTR name, ... );
BOOL  __stdargs WorkbenchControlA( CONST_STRPTR name, CONST struct TagItem *tags );
BOOL  __stdargs WorkbenchControl( CONST_STRPTR name, ... );
struct AppWindowDropZone * __stdargs AddAppWindowDropZoneA( struct AppWindow *aw, ULONG id, ULONG userdata, CONST struct TagItem *tags );
struct AppWindowDropZone * __stdargs AddAppWindowDropZone( struct AppWindow *aw, ULONG id, ULONG userdata, ... );
BOOL  __stdargs RemoveAppWindowDropZone( struct AppWindow *aw, struct AppWindowDropZone *dropZone );
BOOL  __stdargs ChangeWorkbenchSelectionA( CONST_STRPTR name, struct Hook *hook, CONST struct TagItem *tags );
BOOL  __stdargs ChangeWorkbenchSelection( CONST_STRPTR name, struct Hook *hook, ... );
BOOL  __stdargs MakeWorkbenchObjectVisibleA( CONST_STRPTR name, CONST struct TagItem *tags );
BOOL  __stdargs MakeWorkbenchObjectVisible( CONST_STRPTR name, ... );

/*--- functions in V47 or higher (Release 3.2) ---*/
ULONG  __stdargs WhichWorkbenchObjectA( struct Window *window, LONG x, LONG y, CONST struct TagItem *tags );
ULONG  __stdargs WhichWorkbenchObject( struct Window *window, LONG x, LONG y, ... );


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_WB_PROTOS_H */
