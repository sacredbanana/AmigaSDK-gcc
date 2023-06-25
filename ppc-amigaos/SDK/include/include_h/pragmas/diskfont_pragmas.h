#ifndef PRAGMAS_DISKFONT_PRAGMAS_H
#define PRAGMAS_DISKFONT_PRAGMAS_H

/*
**    $VER: diskfont_pragmas.h 54.16 (22.08.2022)
**
**    Direct ROM interface (pragma) definitions.
**
**    Copyright (C) 2001-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*
 * NOTE: These 68k platform specific #pragma header files are unlikely to see
 *       further updates with the AmigaOS4 update and following development
 *       efforts. If you can, please switch to native PowerPC development.
 */
#ifdef __amigaos4__
#error Include <proto/> header files, not <pragmas/> header files in OS4.
#endif

#if defined(LATTICE) || defined(__SASC) || defined(_DCC)
#ifndef __CLIB_PRAGMA_LIBCALL
#define __CLIB_PRAGMA_LIBCALL
#endif /* __CLIB_PRAGMA_LIBCALL */
#else /* __MAXON__, __STORM__ or AZTEC_C */
#ifndef __CLIB_PRAGMA_AMICALL
#define __CLIB_PRAGMA_AMICALL
#endif /* __CLIB_PRAGMA_AMICALL */
#endif /* */

#if defined(__SASC) || defined(__STORM__)
#ifndef __CLIB_PRAGMA_TAGCALL
#define __CLIB_PRAGMA_TAGCALL
#endif /* __CLIB_PRAGMA_TAGCALL */
#endif /* __MAXON__, __STORM__ or AZTEC_C */

#ifndef CLIB_DISKFONT_PROTOS_H
#include <clib/diskfont_protos.h>
#endif /* CLIB_DISKFONT_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase OpenDiskFont 1e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase AvailFonts 24 10803
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V34 or higher (Release 1.3) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase NewFontContents 2a 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase DisposeFontContents 30 901
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase NewScaledDiskFont 36 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V45 or higher (Beta release for developers only) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase GetDiskFontCtrl 3c 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase SetDiskFontCtrlA 42 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DiskfontBase SetDiskFontCtrl 42 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
/*--- functions in V46 or higher (Beta release for developers only) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase EOpenEngine 48 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase ECloseEngine 4e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase ESetInfoA 54 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DiskfontBase ESetInfo 54 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase EObtainInfoA 5a 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DiskfontBase EObtainInfo 5a 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase EReleaseInfoA 60 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DiskfontBase EReleaseInfo 60 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase OpenOutlineFont 66 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase CloseOutlineFont 6c 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase WriteFontContents 72 A9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase WriteDiskFontHeaderA 78 A9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DiskfontBase WriteDiskFontHeader 78 A9803
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase ObtainCharsetInfo 7e 21003
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V49 or higher (Beta release for developers only) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase ObtainTTextAttr 84 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DiskfontBase FreeTTextAttr 8a 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#endif /* PRAGMAS_DISKFONT_PRAGMAS_H */
