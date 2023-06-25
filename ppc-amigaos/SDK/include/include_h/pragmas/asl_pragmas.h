#ifndef PRAGMAS_ASL_PRAGMAS_H
#define PRAGMAS_ASL_PRAGMAS_H

/*
**    $VER: asl_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_ASL_PROTOS_H
#include <clib/asl_protos.h>
#endif /* CLIB_ASL_PROTOS_H */

/*--- functions in V36 or higher (Release 2.0) ---*/

/* OBSOLETE -- Please use the generic requester functions instead */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase AllocFileRequest 1e 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase FreeFileRequest 24 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase RequestFile 2a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase AllocAslRequest 30 8002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall AslBase AllocAslRequestTags 30 8002
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase FreeAslRequest 36 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase AslRequest 3c 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall AslBase AslRequestTags 3c 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase AbortAslRequest 4e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall AslBase ActivateAslRequest 54 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#endif /* PRAGMAS_ASL_PRAGMAS_H */
