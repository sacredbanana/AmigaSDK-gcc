#ifndef CLIB_ICON_PROTOS_H
#define CLIB_ICON_PROTOS_H

/*
	icon.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef WORKBENCH_WORKBENCH_H
# include <workbench/workbench.h>
#endif

#ifndef DATATYPES_PICTURECLASS_H
# include <datatypes/pictureclass.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID FreeFreeList( struct FreeList *freelist );
BOOL AddFreeList( struct FreeList *freelist, CONST APTR mem, ULONG size );
struct DiskObject *GetDiskObject( CONST STRPTR name );
BOOL PutDiskObject( CONST STRPTR name, CONST struct DiskObject *diskobj );
VOID FreeDiskObject( struct DiskObject *diskobj );
UBYTE *FindToolType( CONST STRPTR *toolTypeArray, CONST STRPTR typeName );
BOOL MatchToolValue( CONST STRPTR typeString, CONST STRPTR value );
STRPTR BumpRevision( STRPTR newname, CONST STRPTR oldname );
struct DiskObject *GetDefDiskObject( LONG type );
BOOL PutDefDiskObject( CONST struct DiskObject *diskObject );
struct DiskObject *GetDiskObjectNew( CONST STRPTR name );
BOOL DeleteDiskObject( CONST STRPTR name );

/*** V44 ***/

struct DiskObject *DupDiskObjectA( CONST struct DiskObject *diskObject, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct DiskObject *DupDiskObject( CONST struct DiskObject *diskObject, ... );
#endif
ULONG IconControlA( struct DiskObject *icon, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG IconControl( struct DiskObject *icon, ... );
#endif
VOID DrawIconStateA( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID DrawIconState( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, ... );
#endif
BOOL GetIconRectangleA( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, struct Rectangle *rect, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL GetIconRectangle( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, struct Rectangle *rect, ... );
#endif
struct DiskObject *NewDiskObject( LONG type );
struct DiskObject *GetIconTagList( CONST STRPTR name, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct DiskObject *GetIconTags( CONST STRPTR name, ... );
#endif
BOOL PutIconTagList( CONST STRPTR name, CONST struct DiskObject *icon, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL PutIconTags( CONST STRPTR name, CONST struct DiskObject *icon, ... );
#endif
BOOL LayoutIconA( struct DiskObject *icon, struct Screen *screen, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BOOL LayoutIcon( struct DiskObject *icon, struct Screen *screen, ... );
#endif
VOID ChangeToSelectedIconColor( struct ColorRegister *cr );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_ICON_PROTOS_H */
