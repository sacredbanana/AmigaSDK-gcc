#ifndef PRAGMA_DISKFONT_LIB_H
#define PRAGMA_DISKFONT_LIB_H

/*
**	$VER: diskfont_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_DISKFONT_PROTOS_H
#include <clib/diskfont_protos.h>
#endif /* CLIB_DISKFONT_PROTOS_H */

/* "diskfont.library" */
#pragma amicall(DiskfontBase, 0x1e, OpenDiskFont(a0))
#pragma amicall(DiskfontBase, 0x24, AvailFonts(a0,d0,d1))
/*--- functions in V34 or higher (Release 1.3) ---*/
#pragma amicall(DiskfontBase, 0x2a, NewFontContents(a0,a1))
#pragma amicall(DiskfontBase, 0x30, DisposeFontContents(a1))
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(DiskfontBase, 0x36, NewScaledDiskFont(a0,a1))
/*--- functions in V45 or higher (Release 3.9) ---*/
#pragma amicall(DiskfontBase, 0x3c, GetDiskFontCtrl(d0))
#pragma amicall(DiskfontBase, 0x42, SetDiskFontCtrlA(a0))
#if defined(__STORM__)
#pragma tagcall(DiskfontBase, 0x42, SetDiskFontCtrl(a0))
#endif /* __STORM__ */
/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma amicall(DiskfontBase, 0x48, EOpenEngine(a0))
#pragma amicall(DiskfontBase, 0x4e, ECloseEngine(a0))
#pragma amicall(DiskfontBase, 0x54, ESetInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(DiskfontBase, 0x54, ESetInfo(a0,a1))
#endif /* __STORM__ */
#pragma amicall(DiskfontBase, 0x5a, EObtainInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(DiskfontBase, 0x5a, EObtainInfo(a0,a1))
#endif /* __STORM__ */
#pragma amicall(DiskfontBase, 0x60, EReleaseInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(DiskfontBase, 0x60, EReleaseInfo(a0,a1))
#endif /* __STORM__ */
#pragma amicall(DiskfontBase, 0x66, OpenOutlineFont(a0,a1,d0))
#pragma amicall(DiskfontBase, 0x6c, CloseOutlineFont(a0,a1))
#pragma amicall(DiskfontBase, 0x72, WriteFontContents(a0,a1,a2))
#pragma amicall(DiskfontBase, 0x78, WriteDiskFontHeaderA(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(DiskfontBase, 0x78, WriteDiskFontHeader(a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(DiskfontBase, 0x7e, ObtainCharsetInfo(d0,d1,d2))

#endif /* PRAGMA_DISKFONT_LIB_H */
