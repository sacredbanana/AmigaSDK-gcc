#ifndef PRAGMA_ICON_LIB_H
#define PRAGMA_ICON_LIB_H

/*
**	$VER: icon_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_ICON_PROTOS_H
#include <clib/icon_protos.h>
#endif /* CLIB_ICON_PROTOS_H */

/* "icon.library" */
/*	Use DiskObjects instead of obsolete WBObjects */
#pragma amicall(IconBase, 0x36, FreeFreeList(a0))
#pragma amicall(IconBase, 0x48, AddFreeList(a0,a1,a2))
#pragma amicall(IconBase, 0x4e, GetDiskObject(a0))
#pragma amicall(IconBase, 0x54, PutDiskObject(a0,a1))
#pragma amicall(IconBase, 0x5a, FreeDiskObject(a0))
#pragma amicall(IconBase, 0x60, FindToolType(a0,a1))
#pragma amicall(IconBase, 0x66, MatchToolValue(a0,a1))
#pragma amicall(IconBase, 0x6c, BumpRevision(a0,a1))
#pragma amicall(IconBase, 0x72, FreeAlloc(a0,a1,a2))
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(IconBase, 0x78, GetDefDiskObject(d0))
#pragma amicall(IconBase, 0x7e, PutDefDiskObject(a0))
#pragma amicall(IconBase, 0x84, GetDiskObjectNew(a0))
/*--- functions in V37 or higher (Release 2.04) ---*/
#pragma amicall(IconBase, 0x8a, DeleteDiskObject(a0))
/*--- functions in V44 or higher (Release 3.5) ---*/
#pragma amicall(IconBase, 0x90, FreeFree(a0,a1))
#pragma amicall(IconBase, 0x96, DupDiskObjectA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0x96, DupDiskObject(a0,a1))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0x9c, IconControlA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0x9c, IconControl(a0,a1))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0xa2, DrawIconStateA(a0,a1,a2,d0,d1,d2,a3))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0xa2, DrawIconState(a0,a1,a2,d0,d1,d2,a3))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0xa8, GetIconRectangleA(a0,a1,a2,a3,a4))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0xa8, GetIconRectangle(a0,a1,a2,a3,a4))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0xae, NewDiskObject(d0))
#pragma amicall(IconBase, 0xb4, GetIconTagList(a0,a1))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0xb4, GetIconTags(a0,a1))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0xba, PutIconTagList(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0xba, PutIconTags(a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0xc0, LayoutIconA(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(IconBase, 0xc0, LayoutIcon(a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(IconBase, 0xc6, ChangeToSelectedIconColor(a0))
#pragma amicall(IconBase, 0xcc, BumpRevisionLength(a0,a1,d0))

#endif /* PRAGMA_ICON_LIB_H */
