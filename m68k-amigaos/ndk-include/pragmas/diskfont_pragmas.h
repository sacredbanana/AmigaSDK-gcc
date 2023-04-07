#ifndef PRAGMAS_DISKFONT_PRAGMAS_H
#define PRAGMAS_DISKFONT_PRAGMAS_H

/*
**	$VER: diskfont_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_DISKFONT_PROTOS_H
#include <clib/diskfont_protos.h>
#endif /* CLIB_DISKFONT_PROTOS_H */

/* "diskfont.library" */
#pragma libcall DiskfontBase OpenDiskFont 1e 801
#pragma libcall DiskfontBase AvailFonts 24 10803
/*--- functions in V34 or higher (Release 1.3) ---*/
#pragma libcall DiskfontBase NewFontContents 2a 9802
#pragma libcall DiskfontBase DisposeFontContents 30 901
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall DiskfontBase NewScaledDiskFont 36 9802
/*--- functions in V45 or higher (Release 3.9) ---*/
#pragma libcall DiskfontBase GetDiskFontCtrl 3c 001
#pragma libcall DiskfontBase SetDiskFontCtrlA 42 801
#if defined(__SASC_60)
#pragma tagcall DiskfontBase SetDiskFontCtrl 42 801
#endif /* __SASC_60 */
/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma libcall DiskfontBase EOpenEngine 48 801
#pragma libcall DiskfontBase ECloseEngine 4e 801
#pragma libcall DiskfontBase ESetInfoA 54 9802
#if defined(__SASC_60)
#pragma tagcall DiskfontBase ESetInfo 54 9802
#endif /* __SASC_60 */
#pragma libcall DiskfontBase EObtainInfoA 5a 9802
#if defined(__SASC_60)
#pragma tagcall DiskfontBase EObtainInfo 5a 9802
#endif /* __SASC_60 */
#pragma libcall DiskfontBase EReleaseInfoA 60 9802
#if defined(__SASC_60)
#pragma tagcall DiskfontBase EReleaseInfo 60 9802
#endif /* __SASC_60 */
#pragma libcall DiskfontBase OpenOutlineFont 66 09803
#pragma libcall DiskfontBase CloseOutlineFont 6c 9802
#pragma libcall DiskfontBase WriteFontContents 72 A9803
#pragma libcall DiskfontBase WriteDiskFontHeaderA 78 A9803
#if defined(__SASC_60)
#pragma tagcall DiskfontBase WriteDiskFontHeader 78 A9803
#endif /* __SASC_60 */
#pragma libcall DiskfontBase ObtainCharsetInfo 7e 21003

#endif /* PRAGMAS_DISKFONT_PRAGMAS_H */
