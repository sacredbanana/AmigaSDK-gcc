#ifndef CLIB_ICON_PROTOS_H
#define CLIB_ICON_PROTOS_H

/*
**    $Id: icon_protos.h,v 1.12 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2001-2006 Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef   DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
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

VOID FreeFreeList( struct FreeList *freelist );
BOOL AddFreeList( struct FreeList *freelist, CONST_APTR mem, ULONG size );
struct DiskObject *GetDiskObject( CONST_STRPTR name );
BOOL PutDiskObject( CONST_STRPTR name, CONST struct DiskObject *diskobj );
VOID FreeDiskObject( struct DiskObject *diskobj );
STRPTR FindToolType( STRPTR *toolTypeArray, CONST_STRPTR typeName );
BOOL MatchToolValue( CONST_STRPTR typeString, CONST_STRPTR value );
STRPTR BumpRevision( STRPTR newname, CONST_STRPTR oldname );
/*--- functions in V36 or higher (Release 2.0) ---*/
struct DiskObject *GetDefDiskObject( LONG type );
BOOL PutDefDiskObject( CONST struct DiskObject *diskObject );
struct DiskObject *GetDiskObjectNew( CONST_STRPTR name );
/*--- functions in V37 or higher (Release 2.04) ---*/
BOOL DeleteDiskObject( CONST_STRPTR name );
/*--- functions in V44 or higher (Release 3.5) ---*/
struct DiskObject *DupDiskObjectA( CONST struct DiskObject *diskObject, CONST struct TagItem *tags );
struct DiskObject *DupDiskObject( CONST struct DiskObject *diskObject, Tag tag1, ... );
ULONG IconControlA( struct DiskObject *icon, CONST struct TagItem *tags );
ULONG IconControl( struct DiskObject *icon, Tag tag1, ... );
VOID DrawIconStateA( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, CONST struct TagItem *tags );
VOID DrawIconState( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, Tag tag1, ... );
BOOL GetIconRectangleA( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, struct Rectangle *rect, CONST struct TagItem *tags );
BOOL GetIconRectangle( struct RastPort *rp, CONST struct DiskObject *icon, CONST_STRPTR label, struct Rectangle *rect, Tag tag1, ... );
struct DiskObject *NewDiskObject( LONG type );
struct DiskObject *GetIconTagList( CONST_STRPTR name, CONST struct TagItem *tags );
struct DiskObject *GetIconTags( CONST_STRPTR name, Tag tag1, ... );
BOOL PutIconTagList( CONST_STRPTR name, CONST struct DiskObject *icon, CONST struct TagItem *tags );
BOOL PutIconTags( CONST_STRPTR name, CONST struct DiskObject *icon, Tag tag1, ... );
BOOL LayoutIconA( struct DiskObject *icon, struct Screen *screen, CONST struct TagItem *tags );
BOOL LayoutIcon( struct DiskObject *icon, struct Screen *screen, Tag tag1, ... );
VOID ChangeToSelectedIconColor( struct ColorRegister *cr );
/*--- functions in V51 or higher (Release 4.0) ---*/
STRPTR BumpRevisionLength( STRPTR newname, CONST_STRPTR oldname, uint32 maxlength );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_ICON_PROTOS_H */
