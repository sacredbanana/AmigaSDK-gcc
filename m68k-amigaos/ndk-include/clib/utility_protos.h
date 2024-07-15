#ifndef CLIB_UTILITY_PROTOS_H
#define CLIB_UTILITY_PROTOS_H

/*
**	$VER: utility_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_DATE_H
#include <utility/date.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  UTILITY_NAME_H
#include <utility/name.h>
#endif
/*--- functions in V36 or higher (Release 2.0) ---*/

/* Tag item functions */

struct TagItem * __stdargs FindTagItem( Tag tagVal, CONST struct TagItem *tagList );
ULONG  __stdargs GetTagData( Tag tagValue, ULONG defaultVal, CONST struct TagItem *tagList );
ULONG  __stdargs PackBoolTags( ULONG initialFlags, CONST struct TagItem *tagList, CONST struct TagItem *boolMap );
struct TagItem * __stdargs NextTagItem( struct TagItem **tagListPtr );
VOID  __stdargs FilterTagChanges( struct TagItem *changeList, struct TagItem *originalList, ULONG apply );
VOID  __stdargs MapTags( struct TagItem *tagList, CONST struct TagItem *mapList, ULONG mapType );
struct TagItem * __stdargs AllocateTagItems( ULONG numTags );
struct TagItem * __stdargs CloneTagItems( CONST struct TagItem *tagList );
VOID  __stdargs FreeTagItems( struct TagItem *tagList );
VOID  __stdargs RefreshTagItemClones( struct TagItem *clone, CONST struct TagItem *original );
BOOL  __stdargs TagInArray( Tag tagValue, CONST Tag *tagArray );
ULONG  __stdargs FilterTagItems( struct TagItem *tagList, CONST Tag *filterArray, ULONG logic );

/* Hook functions */

ULONG  __stdargs CallHookPkt( struct Hook *hook, APTR object, APTR paramPacket );

/* Date functions */

VOID  __stdargs Amiga2Date( ULONG seconds, struct ClockData *result );
ULONG  __stdargs Date2Amiga( CONST struct ClockData *date );
ULONG  __stdargs CheckDate( CONST struct ClockData *date );

/* 32 bit integer muliply functions */

LONG  __stdargs SMult32( LONG arg1, LONG arg2 );
ULONG  __stdargs UMult32( ULONG arg1, ULONG arg2 );

/* 32 bit integer division funtions. The quotient and the remainder are */
/* returned respectively in d0 and d1 */

LONG  __stdargs SDivMod32( LONG dividend, LONG divisor );
ULONG  __stdargs UDivMod32( ULONG dividend, ULONG divisor );
/*--- functions in V37 or higher (Release 2.04) ---*/

/* International string routines */

LONG  __stdargs Stricmp( CONST_STRPTR string1, CONST_STRPTR string2 );
LONG  __stdargs Strnicmp( CONST_STRPTR string1, CONST_STRPTR string2, LONG length );
UBYTE  __stdargs ToUpper( ULONG character );
UBYTE  __stdargs ToLower( ULONG character );
/*--- functions in V39 or higher (Release 3.0) ---*/

/* More tag Item functions */

VOID  __stdargs ApplyTagChanges( struct TagItem *list, CONST struct TagItem *changeList );

/* 64 bit integer muliply functions. The results are 64 bit quantities */
/* returned in D0 and D1 */

LONG  __stdargs SMult64( LONG arg1, LONG arg2 );
ULONG  __stdargs UMult64( ULONG arg1, ULONG arg2 );

/* Structure to Tag and Tag to Structure support routines */

ULONG  __stdargs PackStructureTags( APTR pack, CONST ULONG *packTable, CONST struct TagItem *tagList );
ULONG  __stdargs UnpackStructureTags( CONST_APTR pack, CONST ULONG *packTable, struct TagItem *tagList );

/* New, object-oriented NameSpaces */

BOOL  __stdargs AddNamedObject( struct NamedObject *nameSpace, struct NamedObject *object );
struct NamedObject * __stdargs AllocNamedObjectA( CONST_STRPTR name, CONST struct TagItem *tagList );
struct NamedObject * __stdargs AllocNamedObject( CONST_STRPTR name, ... );
LONG  __stdargs AttemptRemNamedObject( struct NamedObject *object );
struct NamedObject * __stdargs FindNamedObject( struct NamedObject *nameSpace, CONST_STRPTR name, CONST struct NamedObject *lastObject );
VOID  __stdargs FreeNamedObject( struct NamedObject *object );
STRPTR  __stdargs NamedObjectName( struct NamedObject *object );
VOID  __stdargs ReleaseNamedObject( struct NamedObject *object );
VOID  __stdargs RemNamedObject( struct NamedObject *object, struct Message *message );

/* Unique ID generator */

ULONG  __stdargs GetUniqueID( VOID );


/*--- functions in V47 or higher (Release 3.2) ---*/

/* Reserved vectors for Os4, not populated. */

LONG  __stdargs VSNPrintf( STRPTR buffer, ULONG bufsize, CONST_STRPTR fmt, CONST_APTR data );
LONG  __stdargs SNPrintf( STRPTR buffer, ULONG bufsize, CONST_STRPTR fmt, ... );

/* Reserved vectors for Os4, not populated. */

/* Reserved vector for internal use. */

STRPTR  __stdargs Strncpy( STRPTR dst, CONST_STRPTR src, ULONG size );
STRPTR  __stdargs Strncat( STRPTR dst, CONST_STRPTR src, ULONG size );

/* 64 bit integer division functions. The input is a 64 bit dividiend in d1:d0 */
/* with top 32 bits in 32 and a divisor in d2. Results are the quotient in d0 */
/* and a remainder in d1 */

LONG  __stdargs SDivMod64( LONG hi, LONG lo, LONG divisor );
ULONG  __stdargs UDivMod64( ULONG hi, ULONG lo, ULONG divisor );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_UTILITY_PROTOS_H */
