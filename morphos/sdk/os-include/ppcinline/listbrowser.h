/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LISTBROWSER_H
#define _PPCINLINE_LISTBROWSER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LISTBROWSER_BASE_NAME
#define LISTBROWSER_BASE_NAME ListBrowserBase
#endif /* !LISTBROWSER_BASE_NAME */

#define ShowAllListBrowserChildren(__p0) \
	LP1NR(78, ShowAllListBrowserChildren, \
		struct List *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeListBrowserNode(__p0) \
	LP1NR(42, FreeListBrowserNode, \
		struct Node *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ListBrowserSelectAll(__p0) \
	LP1NR(60, ListBrowserSelectAll, \
		struct List *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ListBrowserClearAll(__p0) \
	LP1NR(120, ListBrowserClearAll, \
		struct List *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocListBrowserNodeA(__p0, __p1) \
	LP2(36, struct Node *, AllocListBrowserNodeA, \
		ULONG , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetListBrowserNodeAttrsA(__p0, __p1) \
	LP2NR(48, SetListBrowserNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define HideAllListBrowserChildren(__p0) \
	LP1NR(84, HideAllListBrowserChildren, \
		struct List *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define HideListBrowserNodeChildren(__p0) \
	LP1NR(72, HideListBrowserNodeChildren, \
		struct Node *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LISTBROWSER_GetClass() \
	LP0(30, struct IClass *, LISTBROWSER_GetClass, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetListBrowserNodeAttrsA(__p0, __p1) \
	LP2NR(54, GetListBrowserNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetLBColumnInfoAttrsA(__p0, __p1) \
	LP2(108, LONG , GetLBColumnInfoAttrsA, \
		struct ColumnInfo *, __p0, a1, \
		struct TagItem *, __p1, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeListBrowserList(__p0) \
	LP1NR(90, FreeListBrowserList, \
		struct List *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetLBColumnInfoAttrsA(__p0, __p1) \
	LP2(102, LONG , SetLBColumnInfoAttrsA, \
		struct ColumnInfo *, __p0, a1, \
		struct TagItem *, __p1, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeLBColumnInfo(__p0) \
	LP1NR(114, FreeLBColumnInfo, \
		struct ColumnInfo *, __p0, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocLBColumnInfoA(__p0, __p1) \
	LP2(96, struct ColumnInfo *, AllocLBColumnInfoA, \
		ULONG , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ShowListBrowserNodeChildren(__p0, __p1) \
	LP2NR(66, ShowListBrowserNodeChildren, \
		struct Node *, __p0, a0, \
		LONG , __p1, d0, \
		, LISTBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SetListBrowserNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetListBrowserNodeAttrsA(__p0, (struct TagItem *)_tags);})

#define AllocLBColumnInfo(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocLBColumnInfoA(__p0, (struct TagItem *)_tags);})

#define SetLBColumnInfoAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetLBColumnInfoAttrsA(__p0, (struct TagItem *)_tags);})

#define GetLBColumnInfoAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetLBColumnInfoAttrsA(__p0, (struct TagItem *)_tags);})

#define AllocListBrowserNode(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocListBrowserNodeA(__p0, (struct TagItem *)_tags);})

#define GetListBrowserNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetListBrowserNodeAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_LISTBROWSER_H */
