#ifndef PRAGMAS_ICON_PRAGMAS_H
#define PRAGMAS_ICON_PRAGMAS_H

/*
**	$VER: icon_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_ICON_PROTOS_H
#include <clib/icon_protos.h>
#endif /* CLIB_ICON_PROTOS_H */

/* "icon.library" */
/*	Use DiskObjects instead of obsolete WBObjects */
#pragma libcall IconBase FreeFreeList 36 801
#pragma libcall IconBase AddFreeList 48 A9803
#pragma libcall IconBase GetDiskObject 4e 801
#pragma libcall IconBase PutDiskObject 54 9802
#pragma libcall IconBase FreeDiskObject 5a 801
#pragma libcall IconBase FindToolType 60 9802
#pragma libcall IconBase MatchToolValue 66 9802
#pragma libcall IconBase BumpRevision 6c 9802
#pragma libcall IconBase FreeAlloc 72 A9803
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall IconBase GetDefDiskObject 78 001
#pragma libcall IconBase PutDefDiskObject 7e 801
#pragma libcall IconBase GetDiskObjectNew 84 801
/*--- functions in V37 or higher (Release 2.04) ---*/
#pragma libcall IconBase DeleteDiskObject 8a 801
/*--- functions in V44 or higher (Release 3.5) ---*/
#pragma libcall IconBase FreeFree 90 9802
#pragma libcall IconBase DupDiskObjectA 96 9802
#if defined(__SASC_60)
#pragma tagcall IconBase DupDiskObject 96 9802
#endif /* __SASC_60 */
#pragma libcall IconBase IconControlA 9c 9802
#if defined(__SASC_60)
#pragma tagcall IconBase IconControl 9c 9802
#endif /* __SASC_60 */
#pragma libcall IconBase DrawIconStateA a2 B210A9807
#if defined(__SASC_60)
#pragma tagcall IconBase DrawIconState a2 B210A9807
#endif /* __SASC_60 */
#pragma libcall IconBase GetIconRectangleA a8 CBA9805
#if defined(__SASC_60)
#pragma tagcall IconBase GetIconRectangle a8 CBA9805
#endif /* __SASC_60 */
#pragma libcall IconBase NewDiskObject ae 001
#pragma libcall IconBase GetIconTagList b4 9802
#if defined(__SASC_60)
#pragma tagcall IconBase GetIconTags b4 9802
#endif /* __SASC_60 */
#pragma libcall IconBase PutIconTagList ba A9803
#if defined(__SASC_60)
#pragma tagcall IconBase PutIconTags ba A9803
#endif /* __SASC_60 */
#pragma libcall IconBase LayoutIconA c0 A9803
#if defined(__SASC_60)
#pragma tagcall IconBase LayoutIcon c0 A9803
#endif /* __SASC_60 */
#pragma libcall IconBase ChangeToSelectedIconColor c6 801
#pragma libcall IconBase BumpRevisionLength cc 09803

#endif /* PRAGMAS_ICON_PRAGMAS_H */
