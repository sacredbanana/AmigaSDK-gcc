#ifndef PRAGMAS_WB_PRAGMAS_H
#define PRAGMAS_WB_PRAGMAS_H

/*
**    $VER: wb_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_WB_PROTOS_H
#include <clib/wb_protos.h>
#endif /* CLIB_WB_PROTOS_H */

/*--- functions in V36 or higher (Release 2.0) ---*/

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase UpdateWorkbench 1e 09803
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase AddAppWindowA 30 A981005
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase AddAppWindow 30 A981005
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase RemoveAppWindow 36 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase AddAppIconA 3c CBA981007
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase AddAppIcon 3c CBA981007
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase RemoveAppIcon 42 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase AddAppMenuItemA 48 A981005
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase AddAppMenuItem 48 A981005
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase RemoveAppMenuItem 4e 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/*--- functions in V39 or higher (Release 3) ---*/

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase WBInfo 5a A9803
#endif /* __CLIB_PRAGMA_LIBCALL */

/*--- functions in V44 or higher (Release 3.5) ---*/

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase OpenWorkbenchObjectA 60 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase OpenWorkbenchObject 60 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase CloseWorkbenchObjectA 66 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase CloseWorkbenchObject 66 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase WorkbenchControlA 6c 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase WorkbenchControl 6c 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase AddAppWindowDropZoneA 72 910804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase AddAppWindowDropZone 72 910804
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase RemoveAppWindowDropZone 78 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase ChangeWorkbenchSelectionA 7e A9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase ChangeWorkbenchSelection 7e A9803
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase MakeWorkbenchObjectVisibleA 84 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase MakeWorkbenchObjectVisible 84 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

/*--- functions in V50 or higher (Release 4) ---*/

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall WorkbenchBase WhichWorkbenchObjectA 8a 910804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall WorkbenchBase WhichWorkbenchObject 8a 910804
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#endif /* PRAGMAS_WB_PRAGMAS_H */
