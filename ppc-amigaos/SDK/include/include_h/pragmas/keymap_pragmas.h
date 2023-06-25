#ifndef PRAGMAS_KEYMAP_PRAGMAS_H
#define PRAGMAS_KEYMAP_PRAGMAS_H

/*
**    $VER: keymap_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_KEYMAP_PROTOS_H
#include <clib/keymap_protos.h>
#endif /* CLIB_KEYMAP_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
/*--- functions in V36 or higher (Release 2.0) ---*/
 #pragma libcall KeymapBase SetKeyMapDefault    1e 801
 #pragma libcall KeymapBase AskKeyMapDefault    24 00
 #pragma libcall KeymapBase MapRawKey           2a A19804
 #pragma libcall KeymapBase MapANSI             30 A190805
/*--- functions in V50 or higher (Release 4.0 beta) ---*/
 #pragma libcall KeymapBase OpenKeyMapHandleA   36 9802
 #pragma libcall KeymapBase CloseKeyMapHandle   3c 801
 #pragma libcall KeymapBase ObtainKeyMapInfoA   42 9802
 #pragma libcall KeymapBase ReleaseKeyMapInfoA  48 9802
/*--- functions in V51 or higher (Release 4.0 beta2) ---*/
 #pragma libcall KeymapBase ObtainRawKeyInfoA   52 801
 #ifdef __CLIB_PRAGMA_TAGCALL
  #pragma  tagcall KeymapBase OpenKeyMapHandle  36 9802
  #pragma  tagcall KeymapBase ObtainKeyMapInfo  42 9802
  #pragma  tagcall KeymapBase ReleaseKeyMapInfo 48 9802
  #pragma  tagcall KeymapBase ObtainRawKeyInfo  52 801
 #endif /* __CLIB_PRAGMA_TAGCALL */
#endif /* __CLIB_PRAGMA_LIBCALL */

#endif /* PRAGMAS_KEYMAP_PRAGMAS_H */
