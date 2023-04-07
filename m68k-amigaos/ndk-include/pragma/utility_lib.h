#ifndef PRAGMA_UTILITY_LIB_H
#define PRAGMA_UTILITY_LIB_H

/*
**	$VER: utility_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_UTILITY_PROTOS_H
#include <clib/utility_protos.h>
#endif /* CLIB_UTILITY_PROTOS_H */

/* "utility.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/

/* Tag item functions */

#pragma amicall(UtilityBase, 0x1e, FindTagItem(d0,a0))
#pragma amicall(UtilityBase, 0x24, GetTagData(d0,d1,a0))
#pragma amicall(UtilityBase, 0x2a, PackBoolTags(d0,a0,a1))
#pragma amicall(UtilityBase, 0x30, NextTagItem(a0))
#pragma amicall(UtilityBase, 0x36, FilterTagChanges(a0,a1,d0))
#pragma amicall(UtilityBase, 0x3c, MapTags(a0,a1,d0))
#pragma amicall(UtilityBase, 0x42, AllocateTagItems(d0))
#pragma amicall(UtilityBase, 0x48, CloneTagItems(a0))
#pragma amicall(UtilityBase, 0x4e, FreeTagItems(a0))
#pragma amicall(UtilityBase, 0x54, RefreshTagItemClones(a0,a1))
#pragma amicall(UtilityBase, 0x5a, TagInArray(d0,a0))
#pragma amicall(UtilityBase, 0x60, FilterTagItems(a0,a1,d0))

/* Hook functions */

#pragma amicall(UtilityBase, 0x66, CallHookPkt(a0,a2,a1))
/*--- (1 function slot reserved here) ---*/

/* Date functions */

/*--- (1 function slot reserved here) ---*/
#pragma amicall(UtilityBase, 0x78, Amiga2Date(d0,a0))
#pragma amicall(UtilityBase, 0x7e, Date2Amiga(a0))
#pragma amicall(UtilityBase, 0x84, CheckDate(a0))

/* 32 bit integer muliply functions */

#pragma amicall(UtilityBase, 0x8a, SMult32(d0,d1))
#pragma amicall(UtilityBase, 0x90, UMult32(d0,d1))

/* 32 bit integer division funtions. The quotient and the remainder are */
/* returned respectively in d0 and d1 */

#pragma amicall(UtilityBase, 0x96, SDivMod32(d0,d1))
#pragma amicall(UtilityBase, 0x9c, UDivMod32(d0,d1))
/*--- functions in V37 or higher (Release 2.04) ---*/

/* International string routines */

#pragma amicall(UtilityBase, 0xa2, Stricmp(a0,a1))
#pragma amicall(UtilityBase, 0xa8, Strnicmp(a0,a1,d0))
#pragma amicall(UtilityBase, 0xae, ToUpper(d0))
#pragma amicall(UtilityBase, 0xb4, ToLower(d0))
/*--- functions in V39 or higher (Release 3.0) ---*/

/* More tag Item functions */

#pragma amicall(UtilityBase, 0xba, ApplyTagChanges(a0,a1))
/*--- (1 function slot reserved here) ---*/

/* 64 bit integer muliply functions. The results are 64 bit quantities */
/* returned in D0 and D1 */

#pragma amicall(UtilityBase, 0xc6, SMult64(d0,d1))
#pragma amicall(UtilityBase, 0xcc, UMult64(d0,d1))

/* Structure to Tag and Tag to Structure support routines */

#pragma amicall(UtilityBase, 0xd2, PackStructureTags(a0,a1,a2))
#pragma amicall(UtilityBase, 0xd8, UnpackStructureTags(a0,a1,a2))

/* New, object-oriented NameSpaces */

#pragma amicall(UtilityBase, 0xde, AddNamedObject(a0,a1))
#pragma amicall(UtilityBase, 0xe4, AllocNamedObjectA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(UtilityBase, 0xe4, AllocNamedObject(a0,a1))
#endif /* __STORM__ */
#pragma amicall(UtilityBase, 0xea, AttemptRemNamedObject(a0))
#pragma amicall(UtilityBase, 0xf0, FindNamedObject(a0,a1,a2))
#pragma amicall(UtilityBase, 0xf6, FreeNamedObject(a0))
#pragma amicall(UtilityBase, 0xfc, NamedObjectName(a0))
#pragma amicall(UtilityBase, 0x102, ReleaseNamedObject(a0))
#pragma amicall(UtilityBase, 0x108, RemNamedObject(a0,a1))

/* Unique ID generator */

#pragma amicall(UtilityBase, 0x10e, GetUniqueID())

/*--- (4 function slots reserved here) ---*/

/*--- functions in V47 or higher (Release 3.2) ---*/

/* Reserved vectors for Os4, not populated. */
/*--- (2 function slots reserved here) ---*/

#pragma amicall(UtilityBase, 0x138, VSNPrintf(a0,d0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(UtilityBase, 0x138, SNPrintf(a0,d0,a1,a2))
#endif /* __STORM__ */

/* Reserved vectors for Os4, not populated. */
/*--- (19 function slots reserved here) ---*/

/* Reserved vector for internal use. */
/*--- (1 function slot reserved here) ---*/

#pragma amicall(UtilityBase, 0x1b6, Strncpy(a1,a0,d0))
#pragma amicall(UtilityBase, 0x1bc, Strncat(a1,a0,d0))

/* 64 bit integer division functions. The input is a 64 bit dividiend in d1:d0 */
/* with top 32 bits in 32 and a divisor in d2. Results are the quotient in d0 */
/* and a remainder in d1 */

#pragma amicall(UtilityBase, 0x1c2, SDivMod64(d1,d0,d2))
#pragma amicall(UtilityBase, 0x1c8, UDivMod64(d1,d0,d2))

#endif /* PRAGMA_UTILITY_LIB_H */
