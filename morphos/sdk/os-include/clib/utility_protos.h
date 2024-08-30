#ifndef CLIB_UTILITY_PROTOS_H
#define CLIB_UTILITY_PROTOS_H

/*
	utility.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef UTILITY_DATE_H
# include <utility/date.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef UTILITY_NAME_H
# include <utility/name.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct TagItem *FindTagItem( Tag tagVal, CONST struct TagItem *tagList );
ULONG GetTagData( Tag tagValue, ULONG defaultVal, CONST struct TagItem *tagList );
ULONG PackBoolTags( ULONG initialFlags, CONST struct TagItem *tagList, CONST struct TagItem *boolMap );
struct TagItem *NextTagItem( struct TagItem **tagListPtr );
VOID FilterTagChanges( struct TagItem *changeList, struct TagItem *originalList, ULONG apply );
VOID MapTags( struct TagItem *tagList, CONST struct TagItem *mapList, ULONG mapType );
struct TagItem *AllocateTagItems( ULONG numTags );
struct TagItem *CloneTagItems( CONST struct TagItem *tagList );
VOID FreeTagItems( struct TagItem *tagList );
VOID RefreshTagItemClones( struct TagItem *clone, CONST struct TagItem *original );
BOOL TagInArray( Tag tagValue, CONST Tag *tagArray );
ULONG FilterTagItems( struct TagItem *tagList, CONST Tag *filterArray, ULONG logic );

ULONG CallHookPkt( struct Hook *hook, APTR object, APTR paramPacket );

VOID Amiga2Date( ULONG seconds, struct ClockData *result );
ULONG Date2Amiga( CONST struct ClockData *date );
ULONG CheckDate( CONST struct ClockData *date );

LONG SMult32( LONG arg1, LONG arg2 );
ULONG UMult32( ULONG arg1, ULONG arg2 );

LONG SDivMod32( LONG dividend, LONG divisor );
ULONG UDivMod32( ULONG dividend, ULONG divisor );

LONG Stricmp( CONST_STRPTR string1, CONST_STRPTR string2 );
LONG Strnicmp( CONST_STRPTR string1, CONST_STRPTR string2, LONG length );
UBYTE ToUpper( ULONG character );
UBYTE ToLower( ULONG character );

VOID ApplyTagChanges( struct TagItem *list, CONST struct TagItem *changeList );

LONG SMult64( LONG arg1, LONG arg2 );
ULONG UMult64( ULONG arg1, ULONG arg2 );

ULONG PackStructureTags( APTR pack, CONST ULONG *packTable, CONST struct TagItem *tagList );
ULONG UnpackStructureTags( CONST APTR pack, CONST ULONG *packTable, struct TagItem *tagList );

BOOL AddNamedObject( struct NamedObject *nameSpace, struct NamedObject *object );
struct NamedObject *AllocNamedObjectA( CONST_STRPTR name, CONST struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
struct NamedObject *AllocNamedObject( CONST_STRPTR name, Tag tag1, ... );
#endif
LONG AttemptRemNamedObject( struct NamedObject *object );
struct NamedObject *FindNamedObject( struct NamedObject *nameSpace, CONST_STRPTR name, struct NamedObject *lastObject );
VOID FreeNamedObject( struct NamedObject *object );
STRPTR NamedObjectName( struct NamedObject *object );
VOID ReleaseNamedObject( struct NamedObject *object );
VOID RemNamedObject( struct NamedObject *object, struct Message *message );

ULONG GetUniqueID( VOID );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_UTILITY_PROTOS_H */
