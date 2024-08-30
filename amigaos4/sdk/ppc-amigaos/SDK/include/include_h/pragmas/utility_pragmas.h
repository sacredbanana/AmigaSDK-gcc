#ifndef PRAGMAS_UTILITY_PRAGMAS_H
#define PRAGMAS_UTILITY_PRAGMAS_H

/*
**    $VER: utility_pragmas.h 53.29 (10.8.2015)
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

#ifndef CLIB_UTILITY_PROTOS_H
#include <clib/utility_protos.h>
#endif /* CLIB_UTILITY_PROTOS_H */

/*--- functions in V36 or higher (Release 2.0) ---*/

/* Tag item functions */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FindTagItem 1e 8002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase GetTagData 24 81003
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase PackBoolTags 2a 98003
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase NextTagItem 30 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FilterTagChanges 36 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase MapTags 3c 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase AllocateTagItems 42 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase CloneTagItems 48 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FreeTagItems 4e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase RefreshTagItemClones 54 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase TagInArray 5a 8002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FilterTagItems 60 09803
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Hook functions */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase CallHookPkt 66 9A803
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- (1 function slot reserved here) ---*/

/* Date functions */

/*--- (1 function slot reserved here) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Amiga2Date 78 8002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Date2Amiga 7e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase CheckDate 84 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/* 32 bit integer muliply functions */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase SMult32 8a 1002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase UMult32 90 1002
#endif /* __CLIB_PRAGMA_LIBCALL */

/* 32 bit integer division funtions. The quotient and the remainder are */
/* returned respectively in d0 and d1 */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase SDivMod32 96 1002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase UDivMod32 9c 1002
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V37 or higher (Release 2.04) ---*/

/* International string routines */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Stricmp a2 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Strnicmp a8 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase ToUpper ae 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase ToLower b4 001
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V39 or higher (Release 3) ---*/

/* More tag Item functions */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase ApplyTagChanges ba 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- (1 function slot reserved here) ---*/

/* 64 bit integer muliply functions. The results are 64 bit quantities */
/* returned in D0 and D1 */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase SMult64 c6 1002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase UMult64 cc 1002
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Structure to Tag and Tag to Structure support routines */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase PackStructureTags d2 A9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase UnpackStructureTags d8 A9803
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Object-oriented NameSpaces */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase AddNamedObject de 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase AllocNamedObjectA e4 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall UtilityBase AllocNamedObject e4 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase AttemptRemNamedObject ea 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FindNamedObject f0 A9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FreeNamedObject f6 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase NamedObjectName fc 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase ReleaseNamedObject 102 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase RemNamedObject 108 9802
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Unique ID generator */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase GetUniqueID 10e 00
#endif /* __CLIB_PRAGMA_LIBCALL */

/*--- (4 function slots reserved here) ---*/

/*--- functions in V50 or higher (Beta release for developers only) ---*/

/* String manipulation and formatting */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Strlcpy 12c 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Strlcat 132 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase VSNPrintf 138 A90804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall UtilityBase SNPrintf 138 A90804
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase VASPrintf 13e 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall UtilityBase ASPrintf 13e 9802
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

/* Skip lists */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase CreateSkipList 144 0802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase DeleteSkipList 14a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase InsertSkipNode 150 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FindSkipNode 156 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase RemoveSkipNode 15c 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase GetFirstSkipNode 162 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase GetNextSkipNode 168 9802
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Splay trees */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase CreateSplayTree 16e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase DeleteSplayTree 174 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase InsertSplayNode 17a 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FindSplayNode 180 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase RemoveSplayNode 186 9802
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Fill memory with a constant byte */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase SetMem 18c 10803
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Find a list node by name (case-insensitive) */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase FindNameNC 192 9802
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Pseudo-random number generation */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase Random 198 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/* Message digest calculation */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase MessageDigest_SHA_Init 19e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase MessageDigest_SHA_Update 1a4 09803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UtilityBase MessageDigest_SHA_Final 1aa 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#endif /* PRAGMAS_UTILITY_PRAGMAS_H */
