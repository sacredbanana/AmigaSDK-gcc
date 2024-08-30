#ifndef CLIB_WB_PROTOS_H
#define CLIB_WB_PROTOS_H

/*
	workbench.library C prototypes

	Copyright © 2002-2016 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef DOS_DOSEXTENS_H
# include <dos/dosextens.h>
#endif

#ifndef WORKBENCH_WORKBENCH_H
# include <workbench/workbench.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct AppWindow *AddAppWindowA( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
struct AppWindow *AddAppWindow( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, Tag tag1, ... );
#endif

BOOL RemoveAppWindow( struct AppWindow *appWindow );

struct AppIcon *AddAppIconA( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
struct AppIcon *AddAppIcon( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, Tag tag1, ... );
#endif

BOOL RemoveAppIcon( struct AppIcon *appIcon );

struct AppMenuItem *AddAppMenuItemA( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
struct AppMenuItem *AddAppMenuItem( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, Tag tag1, ... );
#endif

BOOL RemoveAppMenuItem( struct AppMenuItem *appMenuItem );

VOID WBInfo( BPTR lock, STRPTR name, struct Screen *screen );

/*** V44 ***/

BOOL OpenWorkbenchObjectA( STRPTR name, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL OpenWorkbenchObject( STRPTR name, ... );
#endif
BOOL CloseWorkbenchObjectA( STRPTR name, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL CloseWorkbenchObject( STRPTR name, ... );
#endif
BOOL WorkbenchControlA( STRPTR name, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL WorkbenchControl( STRPTR name, ... );
#endif
struct AppWindowDropZone *AddAppWindowDropZoneA( struct AppWindow *aw, ULONG id, ULONG userdata, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct AppWindowDropZone *AddAppWindowDropZone( struct AppWindow *aw, ULONG id, ULONG userdata, ... );
#endif
BOOL RemoveAppWindowDropZone( struct AppWindow *aw, struct AppWindowDropZone *dropZone );
BOOL ChangeWorkbenchSelectionA( STRPTR name, struct Hook *hook, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL ChangeWorkbenchSelection( STRPTR name, struct Hook *hook, ... );
#endif
BOOL MakeWorkbenchObjectVisibleA( STRPTR name, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL MakeWorkbenchObjectVisible( STRPTR name, ... );
#endif

BOOL ManageDesktopObjectA(CONST_STRPTR name, LONG action, const struct TagItem *tags);

#if !defined(USE_INLINE_STDARG)
BOOL ManageDesktopObjectTags(CONST_STRPTR name, LONG action, ...);
#endif

BOOL CreateDrawerA(CONST_STRPTR drawer, const struct TagItem *tags);
BOOL CreateIconA(CONST_STRPTR name, const struct TagItem *tags);

#if !defined(USE_INLINE_STDARG)
BOOL CreateDrawerTags(CONST_STRPTR drawer, ...);
BOOL CreateIconTags(CONST_STRPTR name, ...);
#endif

/* These are private to Ambient. Do not use.
 */
struct AppWindow *AppWindowObtain(struct Window *win);
VOID AppWindowRelease(VOID);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_WB_PROTOS_H */
