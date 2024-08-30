/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_REQTOOLS_H
#define _PPCINLINE_REQTOOLS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef REQTOOLS_BASE_NAME
#define REQTOOLS_BASE_NAME ReqToolsBase
#endif /* !REQTOOLS_BASE_NAME */

#define rtSpread(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6NR(132, rtSpread, \
		ULONG *, __p0, a0, \
		ULONG *, __p1, a1, \
		ULONG , __p2, d0, \
		ULONG , __p3, d1, \
		ULONG , __p4, d2, \
		ULONG , __p5, d3, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtLockWindow(__p0) \
	LP1(156, APTR , rtLockWindow, \
		struct Window *, __p0, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtPaletteRequestA(__p0, __p1, __p2) \
	LP3(102, LONG , rtPaletteRequestA, \
		char *, __p0, a2, \
		struct rtReqInfo *, __p1, a3, \
		struct TagItem *, __p2, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtReqHandlerA(__p0, __p1, __p2) \
	LP3(108, ULONG , rtReqHandlerA, \
		struct rtHandlerInfo *, __p0, a1, \
		ULONG , __p1, d0, \
		struct TagItem *, __p2, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtCloseWindowSafely(__p0) \
	LP1NR(150, rtCloseWindowSafely, \
		struct Window *, __p0, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtFreeFileList(__p0) \
	LP1NR(60, rtFreeFileList, \
		struct rtFileList *, __p0, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtSetWaitPointer(__p0) \
	LP1NR(114, rtSetWaitPointer, \
		struct Window *, __p0, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtGetStringA(__p0, __p1, __p2, __p3, __p4) \
	LP5(72, ULONG , rtGetStringA, \
		UBYTE *, __p0, a1, \
		ULONG , __p1, d0, \
		char *, __p2, a2, \
		struct rtReqInfo *, __p3, a3, \
		struct TagItem *, __p4, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtFontRequestA(__p0, __p1, __p2) \
	LP3(96, ULONG , rtFontRequestA, \
		struct rtFontRequester *, __p0, a1, \
		char *, __p1, a3, \
		struct TagItem *, __p2, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define rtGetLongA(__p0, __p1, __p2, __p3) \
	LP4(78, ULONG , rtGetLongA, \
		ULONG *, __p0, a1, \
		char *, __p1, a2, \
		struct rtReqInfo *, __p2, a3, \
		struct TagItem *, __p3, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtSetReqPosition(__p0, __p1, __p2, __p3) \
	LP4NR(126, rtSetReqPosition, \
		ULONG , __p0, d0, \
		struct NewWindow *, __p1, a0, \
		struct Screen *, __p2, a1, \
		struct Window *, __p3, a2, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtFileRequestA(__p0, __p1, __p2, __p3) \
	LP4(54, APTR , rtFileRequestA, \
		struct rtFileRequester *, __p0, a1, \
		char *, __p1, a2, \
		char *, __p2, a3, \
		struct TagItem *, __p3, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtFreeRequest(__p0) \
	LP1NR(36, rtFreeRequest, \
		APTR , __p0, a1, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtScreenModeRequestA(__p0, __p1, __p2) \
	LP3(144, ULONG , rtScreenModeRequestA, \
		struct rtScreenModeRequester *, __p0, a1, \
		char *, __p1, a3, \
		struct TagItem *, __p2, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtGetVScreenSize(__p0, __p1, __p2) \
	LP3(120, ULONG , rtGetVScreenSize, \
		struct Screen *, __p0, a0, \
		ULONG *, __p1, a1, \
		ULONG *, __p2, a2, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtAllocRequestA(__p0, __p1) \
	LP2(30, APTR , rtAllocRequestA, \
		ULONG , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtFreeReqBuffer(__p0) \
	LP1NR(42, rtFreeReqBuffer, \
		APTR , __p0, a1, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtUnlockWindow(__p0, __p1) \
	LP2NR(162, rtUnlockWindow, \
		struct Window *, __p0, a0, \
		APTR , __p1, a1, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtEZRequestA(__p0, __p1, __p2, __p3, __p4) \
	LP5(66, ULONG , rtEZRequestA, \
		char *, __p0, a1, \
		char *, __p1, a2, \
		struct rtReqInfo *, __p2, a3, \
		APTR , __p3, a4, \
		struct TagItem *, __p4, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define rtChangeReqAttrA(__p0, __p1) \
	LP2(48, LONG , rtChangeReqAttrA, \
		APTR , __p0, a1, \
		struct TagItem *, __p1, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define rtScreenToFrontSafely(__p0) \
	LP1NR(138, rtScreenToFrontSafely, \
		struct Screen *, __p0, a0, \
		, REQTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define rtAllocRequest(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtAllocRequestA(__p0, (struct TagItem *)_tags);})

#define rtPaletteRequest(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtPaletteRequestA(__p0, __p1, (struct TagItem *)_tags);})

#define rtFontRequest(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtFontRequestA(__p0, __p1, (struct TagItem *)_tags);})

#define rtReqHandler(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtReqHandlerA(__p0, __p1, (struct TagItem *)_tags);})

#define rtFileRequest(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtFileRequestA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define rtGetLong(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtGetLongA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define rtGetString(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtGetStringA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define rtEZRequest(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtEZRequestA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define rtChangeReqAttr(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtChangeReqAttrA(__p0, (struct TagItem *)_tags);})

#define rtScreenModeRequest(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtScreenModeRequestA(__p0, __p1, (struct TagItem *)_tags);})

#define rtEZRequestTags(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	rtEZRequestA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_REQTOOLS_H */
