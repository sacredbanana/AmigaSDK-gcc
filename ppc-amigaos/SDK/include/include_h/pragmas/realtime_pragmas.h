#ifndef PRAGMAS_REALTIME_PRAGMAS_H
#define PRAGMAS_REALTIME_PRAGMAS_H

/*
**    $VER: realtime_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_REALTIME_PROTOS_H
#include <clib/realtime_protos.h>
#endif /* CLIB_REALTIME_PROTOS_H */

/*--- functions in V37 or higher (Release 2.04) ---*/

/* Locks */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase LockRealTime 1e 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase UnlockRealTime 24 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Conductor */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase CreatePlayerA 2a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall RealTimeBase CreatePlayer 2a 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase DeletePlayer 30 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase SetPlayerAttrsA 36 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall RealTimeBase SetPlayerAttrs 36 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase SetConductorState 3c 10803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase ExternalSync 42 10803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase NextConductor 48 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase FindConductor 4e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall RealTimeBase GetPlayerAttrsA 54 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall RealTimeBase GetPlayerAttrs 54 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#endif /* PRAGMAS_REALTIME_PRAGMAS_H */
