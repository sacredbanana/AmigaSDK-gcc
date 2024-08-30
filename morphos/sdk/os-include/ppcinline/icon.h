/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_ICON_H
#define _PPCINLINE_ICON_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef ICON_BASE_NAME
#define ICON_BASE_NAME IconBase
#endif /* !ICON_BASE_NAME */

#define PutDiskObject(__p0, __p1) \
	LP2(84, BOOL , PutDiskObject, \
		CONST STRPTR , __p0, a0, \
		CONST struct DiskObject *, __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MatchToolValue(__p0, __p1) \
	LP2(102, BOOL , MatchToolValue, \
		CONST STRPTR , __p0, a0, \
		CONST STRPTR , __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IconControlA(__p0, __p1) \
	LP2(156, ULONG , IconControlA, \
		struct DiskObject *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteDiskObject(__p0) \
	LP1(138, BOOL , DeleteDiskObject, \
		CONST STRPTR , __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeToSelectedIconColor(__p0) \
	LP1NR(198, ChangeToSelectedIconColor, \
		struct ColorRegister *, __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeDiskObject(__p0) \
	LP1NR(90, FreeDiskObject, \
		struct DiskObject *, __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddFreeList(__p0, __p1, __p2) \
	LP3(72, BOOL , AddFreeList, \
		struct FreeList *, __p0, a0, \
		CONST APTR , __p1, a1, \
		ULONG , __p2, a2, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeFreeList(__p0) \
	LP1NR(54, FreeFreeList, \
		struct FreeList *, __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDiskObject(__p0) \
	LP1(78, struct DiskObject *, GetDiskObject, \
		CONST STRPTR , __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BumpRevision(__p0, __p1) \
	LP2(108, STRPTR , BumpRevision, \
		STRPTR , __p0, a0, \
		CONST STRPTR , __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDiskObjectNew(__p0) \
	LP1(132, struct DiskObject *, GetDiskObjectNew, \
		CONST STRPTR , __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawIconStateA(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(162, DrawIconStateA, \
		struct RastPort *, __p0, a0, \
		CONST struct DiskObject *, __p1, a1, \
		CONST STRPTR , __p2, a2, \
		LONG , __p3, d0, \
		LONG , __p4, d1, \
		ULONG , __p5, d2, \
		CONST struct TagItem *, __p6, a3, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PutIconTagList(__p0, __p1, __p2) \
	LP3(186, BOOL , PutIconTagList, \
		CONST STRPTR , __p0, a0, \
		CONST struct DiskObject *, __p1, a1, \
		CONST struct TagItem *, __p2, a2, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DupDiskObjectA(__p0, __p1) \
	LP2(150, struct DiskObject *, DupDiskObjectA, \
		CONST struct DiskObject *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewDiskObject(__p0) \
	LP1(174, struct DiskObject *, NewDiskObject, \
		LONG , __p0, d0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetIconRectangleA(__p0, __p1, __p2, __p3, __p4) \
	LP5(168, BOOL , GetIconRectangleA, \
		struct RastPort *, __p0, a0, \
		CONST struct DiskObject *, __p1, a1, \
		CONST STRPTR , __p2, a2, \
		struct Rectangle *, __p3, a3, \
		CONST struct TagItem *, __p4, a4, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindToolType(__p0, __p1) \
	LP2(96, UBYTE *, FindToolType, \
		CONST STRPTR *, __p0, a0, \
		CONST STRPTR , __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetIconTagList(__p0, __p1) \
	LP2(180, struct DiskObject *, GetIconTagList, \
		CONST STRPTR , __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LayoutIconA(__p0, __p1, __p2) \
	LP3(192, BOOL , LayoutIconA, \
		struct DiskObject *, __p0, a0, \
		struct Screen *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PutDefDiskObject(__p0) \
	LP1(126, BOOL , PutDefDiskObject, \
		CONST struct DiskObject *, __p0, a0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDefDiskObject(__p0) \
	LP1(120, struct DiskObject *, GetDefDiskObject, \
		LONG , __p0, d0, \
		, ICON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define DupDiskObject(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DupDiskObjectA(__p0, (CONST struct TagItem *)_tags);})

#define PutIconTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PutIconTagList(__p0, __p1, (CONST struct TagItem *)_tags);})

#define DrawIconState(__p0, __p1, __p2, __p3, __p4, __p5, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DrawIconStateA(__p0, __p1, __p2, __p3, __p4, __p5, (CONST struct TagItem *)_tags);})

#define GetIconTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetIconTagList(__p0, (CONST struct TagItem *)_tags);})

#define LayoutIcon(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LayoutIconA(__p0, __p1, (struct TagItem *)_tags);})

#define IconControl(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	IconControlA(__p0, (CONST struct TagItem *)_tags);})

#define GetIconRectangle(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetIconRectangleA(__p0, __p1, __p2, __p3, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_ICON_H */
