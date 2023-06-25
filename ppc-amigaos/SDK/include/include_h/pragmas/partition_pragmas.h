#ifndef PRAGMAS_PARTITION_PRAGMAS_H
#define PRAGMAS_PARTITION_PRAGMAS_H

/*
**    $VER: partition_pragmas.h 54.16 (22.08.2022)
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

#ifndef CLIB_PARTITION_PROTOS_H
#include <clib/partition_protos.h>
#endif /* CLIB_PARTITION_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall PartitionBase PARTITION_GetClass 1e 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(PartitionBase, 0x1e, PARTITION_GetClass())
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall PartitionBase AllocPartitionNodeA 24 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(PartitionBase, 0x24, AllocPartitionNodeA(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall PartitionBase AllocPartitionNode 24 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
 #ifdef __CLIB_PRAGMA_AMICALL
  #pragma tagcall(PartitionBase, 0x24, AllocPartitionNode(a0))
 #endif /* __CLIB_PRAGMA_AMICALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall PartitionBase FreePartitionNode 2a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(PartitionBase, 0x2a, FreePartitionNode(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall PartitionBase SetPartitionNodeAttrsA 30 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(PartitionBase, 0x30, SetPartitionNodeAttrsA(a0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall PartitionBase SetPartitionNodeAttrs 30 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
 #ifdef __CLIB_PRAGMA_AMICALL
  #pragma tagcall(PartitionBase, 0x30, SetPartitionNodeAttrs(a0,a1))
 #endif /* __CLIB_PRAGMA_AMICALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall PartitionBase GetPartitionNodeAttrsA 36 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(PartitionBase, 0x36, GetPartitionNodeAttrsA(a0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall PartitionBase GetPartitionNodeAttrs 36 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
 #ifdef __CLIB_PRAGMA_AMICALL
  #pragma tagcall(PartitionBase, 0x36, GetPartitionNodeAttrs(a0,a1))
 #endif /* __CLIB_PRAGMA_AMICALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#endif /* PRAGMAS_PARTITION_PRAGMAS_H */
