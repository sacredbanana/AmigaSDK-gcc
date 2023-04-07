#ifndef CLIB_ICON_PROTOS_H
#define CLIB_ICON_PROTOS_H

/*
**	$VER: icon_protos.h 47.1 (30.11.2021)
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
#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
#endif
VOID  __stdargs FreeFreeList( struct FreeList *freelist );
BOOL  __stdargs AddFreeList( struct FreeList *freelist, CONST_APTR mem, ULONG size );
struct DiskObject * __stdargs GetDiskObject( CONST_STRPTR name );
BOOL  __stdargs PutDiskObject( CONST_STRPTR name, CONST struct DiskObject *diskobj );
VOID  __stdargs FreeDiskObject( struct DiskObject *diskobj );
UBYTE * __stdargs FindToolType( CONST_STRPTR *toolTypeArray, CONST_STRPTR typeName );
BOOL  __stdargs MatchToolValue( CONST_STRPTR typeString, CONST_STRPTR value );
STRPTR  __stdargs BumpRevision( STRPTR newname, CONST_STRPTR oldname );
APTR  __stdargs FreeAlloc( struct FreeList *free, ULONG len, ULONG type );
/*--- functions in V36 or higher (Release 2.0) ---*/
struct DiskObject * __stdargs GetDefDiskObject( LONG type );
BOOL  __stdargs PutDefDiskObject( CONST struct DiskObject *diskObject );
struct DiskObject * __stdargs GetDiskObjectNew( CONST_STRPTR name );
/*--- functions in V37 or higher (Release 2.04) ---*/
BOOL  __stdargs DeleteDiskObject( CONST_STRPTR name );
/*--- functions in V44 or higher (Release 3.5) ---*/
VOID  __stdargs FreeFree( struct FreeList *fl, APTR address );
struct DiskObject * __stdargs DupDiskObjectA( CONST struct DiskObject *diskObject, CONST struct TagItem *tags );
struct DiskObject * __stdargs DupDiskObject( CONST struct DiskObject *diskObject, ... );
ULONG  __stdargs IconControlA( struct DiskObject *icon, CONST struct TagItem *tags );
ULONG  __stdargs IconControl( struct DiskObject *icon, ... );
VOID  __stdargs DrawIconStateA( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, CONST struct TagItem *tags );
VOID  __stdargs DrawIconState( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, ... );
BOOL  __stdargs GetIconRectangleA( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, struct Rectangle *rect, CONST struct TagItem *tags );
BOOL  __stdargs GetIconRectangle( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, struct Rectangle *rect, ... );
struct DiskObject * __stdargs NewDiskObject( LONG type );
struct DiskObject * __stdargs GetIconTagList( CONST_STRPTR name, CONST struct TagItem *tags );
struct DiskObject * __stdargs GetIconTags( CONST_STRPTR name, ... );
BOOL  __stdargs PutIconTagList( CONST_STRPTR name, CONST struct DiskObject *icon, CONST struct TagItem *tags );
BOOL  __stdargs PutIconTags( CONST_STRPTR name, CONST struct DiskObject *icon, ... );
BOOL  __stdargs LayoutIconA( struct DiskObject *icon, struct Screen *screen, struct TagItem *tags );
BOOL  __stdargs LayoutIcon( struct DiskObject *icon, struct Screen *screen, ... );
VOID  __stdargs ChangeToSelectedIconColor( struct ColorRegister *cr );
STRPTR  __stdargs BumpRevisionLength( STRPTR newname, CONST_STRPTR oldname, ULONG maxLength );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_ICON_PROTOS_H */
