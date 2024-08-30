/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_UTILITY_H
#define _PPCINLINE_UTILITY_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef UTILITY_BASE_NAME
#define UTILITY_BASE_NAME UtilityBase
#endif /* !UTILITY_BASE_NAME */

#define UMult64(__p0, __p1) \
	LP2(204, ULONG , UMult64, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocNamedObjectA(__p0, __p1) \
	LP2(228, struct NamedObject *, AllocNamedObjectA, \
		CONST_STRPTR , __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NextTagItem(__p0) \
	LP1(48, struct TagItem *, NextTagItem, \
		struct TagItem **, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloneTagItems(__p0) \
	LP1(72, struct TagItem *, CloneTagItems, \
		CONST struct TagItem *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Date2Amiga(__p0) \
	LP1(126, ULONG , Date2Amiga, \
		CONST struct ClockData *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SMult32(__p0, __p1) \
	LP2(138, LONG , SMult32, \
		LONG , __p0, d0, \
		LONG , __p1, d1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FilterTagChanges(__p0, __p1, __p2) \
	LP3NR(54, FilterTagChanges, \
		struct TagItem *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		ULONG , __p2, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindNamedObject(__p0, __p1, __p2) \
	LP3(240, struct NamedObject *, FindNamedObject, \
		struct NamedObject *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		struct NamedObject *, __p2, a2, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddNamedObject(__p0, __p1) \
	LP2(222, BOOL , AddNamedObject, \
		struct NamedObject *, __p0, a0, \
		struct NamedObject *, __p1, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ToLower(__p0) \
	LP1(180, UBYTE , ToLower, \
		ULONG , __p0, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PackBoolTags(__p0, __p1, __p2) \
	LP3(42, ULONG , PackBoolTags, \
		ULONG , __p0, d0, \
		CONST struct TagItem *, __p1, a0, \
		CONST struct TagItem *, __p2, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseNamedObject(__p0) \
	LP1NR(258, ReleaseNamedObject, \
		struct NamedObject *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RefreshTagItemClones(__p0, __p1) \
	LP2NR(84, RefreshTagItemClones, \
		struct TagItem *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttemptRemNamedObject(__p0) \
	LP1(234, LONG , AttemptRemNamedObject, \
		struct NamedObject *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ToUpper(__p0) \
	LP1(174, UBYTE , ToUpper, \
		ULONG , __p0, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ApplyTagChanges(__p0, __p1) \
	LP2NR(186, ApplyTagChanges, \
		struct TagItem *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Stricmp(__p0, __p1) \
	LP2(162, LONG , Stricmp, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FilterTagItems(__p0, __p1, __p2) \
	LP3(96, ULONG , FilterTagItems, \
		struct TagItem *, __p0, a0, \
		CONST Tag *, __p1, a1, \
		ULONG , __p2, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindTagItem(__p0, __p1) \
	LP2(30, struct TagItem *, FindTagItem, \
		Tag , __p0, d0, \
		CONST struct TagItem *, __p1, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetTagData(__p0, __p1, __p2) \
	LP3(36, ULONG , GetTagData, \
		Tag , __p0, d0, \
		ULONG , __p1, d1, \
		CONST struct TagItem *, __p2, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SDivMod32(__p0, __p1) \
	LP2(150, LONG , SDivMod32, \
		LONG , __p0, d0, \
		LONG , __p1, d1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UDivMod32(__p0, __p1) \
	LP2(156, ULONG , UDivMod32, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SMult64(__p0, __p1) \
	LP2(198, LONG , SMult64, \
		LONG , __p0, d0, \
		LONG , __p1, d1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeTagItems(__p0) \
	LP1NR(78, FreeTagItems, \
		struct TagItem *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnpackStructureTags(__p0, __p1, __p2) \
	LP3(216, ULONG , UnpackStructureTags, \
		CONST APTR , __p0, a0, \
		CONST ULONG *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocateTagItems(__p0) \
	LP1(66, struct TagItem *, AllocateTagItems, \
		ULONG , __p0, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UMult32(__p0, __p1) \
	LP2(144, ULONG , UMult32, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NamedObjectName(__p0) \
	LP1(252, STRPTR , NamedObjectName, \
		struct NamedObject *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeNamedObject(__p0) \
	LP1NR(246, FreeNamedObject, \
		struct NamedObject *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PackStructureTags(__p0, __p1, __p2) \
	LP3(210, ULONG , PackStructureTags, \
		APTR , __p0, a0, \
		CONST ULONG *, __p1, a1, \
		CONST struct TagItem *, __p2, a2, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MapTags(__p0, __p1, __p2) \
	LP3NR(60, MapTags, \
		struct TagItem *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		ULONG , __p2, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Amiga2Date(__p0, __p1) \
	LP2NR(120, Amiga2Date, \
		ULONG , __p0, d0, \
		struct ClockData *, __p1, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CheckDate(__p0) \
	LP1(132, ULONG , CheckDate, \
		CONST struct ClockData *, __p0, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemNamedObject(__p0, __p1) \
	LP2NR(264, RemNamedObject, \
		struct NamedObject *, __p0, a0, \
		struct Message *, __p1, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetUniqueID() \
	LP0(270, ULONG , GetUniqueID, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TagInArray(__p0, __p1) \
	LP2(90, BOOL , TagInArray, \
		Tag , __p0, d0, \
		CONST Tag *, __p1, a0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Strnicmp(__p0, __p1, __p2) \
	LP3(168, LONG , Strnicmp, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		LONG , __p2, d0, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CallHookPkt(__p0, __p1, __p2) \
	LP3(102, ULONG , CallHookPkt, \
		struct Hook *, __p0, a0, \
		APTR , __p1, a2, \
		APTR , __p2, a1, \
		, UTILITY_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocNamedObject(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocNamedObjectA(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_UTILITY_H */
