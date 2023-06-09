#ifndef PRAGMAS_CARDRES_PRAGMAS_H
#define PRAGMAS_CARDRES_PRAGMAS_H

/*
**    $VER: cardres_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_CARDRES_PROTOS_H
#include <clib/cardres_protos.h>
#endif /* CLIB_CARDRES_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource OwnCard 6 901
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource ReleaseCard c 0902
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource GetCardMap 12 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource BeginCardAccess 18 901
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource EndCardAccess 1e 901
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource ReadCardStatus 24 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardResetRemove 2a 0902
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardMiscControl 30 1902
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardAccessSpeed 36 0902
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardProgramVoltage 3c 0902
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardResetCard 42 901
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CopyTuple 48 018904
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource DeviceTuple 4e 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource IfAmigaXIP 54 A01
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardForceChange 5a 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardChangeCount 60 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CardResource CardInterface 66 00
#endif /* __CLIB_PRAGMA_LIBCALL */

#endif /* PRAGMAS_CARDRES_PRAGMAS_H */
