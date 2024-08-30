/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_AMIGAGUIDE_H
#define _PPCINLINE_AMIGAGUIDE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef AMIGAGUIDE_BASE_NAME
#define AMIGAGUIDE_BASE_NAME AmigaGuideBase
#endif /* !AMIGAGUIDE_BASE_NAME */

#define LoadXRef(__p0, __p1) \
	LP2(126, LONG , LoadXRef, \
		BPTR , __p0, a0, \
		STRPTR , __p1, a1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenAmigaGuideA(__p0, __p1) \
	LP2(54, APTR , OpenAmigaGuideA, \
		struct NewAmigaGuide *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenAmigaGuideAsyncA(__p0, __p1) \
	LP2(60, APTR , OpenAmigaGuideAsyncA, \
		struct NewAmigaGuide *, __p0, a0, \
		struct TagItem *, __p1, d0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AG_UpdateLink(__p0) \
	(((VOID (*)(CONST_STRPTR , void *))*(void**)((long)(AMIGAGUIDE_BASE_NAME) - 220))(__p0, (void*)(AMIGAGUIDE_BASE_NAME)))

#define SendAmigaGuideCmdA(__p0, __p1, __p2) \
	LP3(102, LONG , SendAmigaGuideCmdA, \
		APTR , __p0, a0, \
		STRPTR , __p1, d0, \
		struct TagItem *, __p2, d1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockAmigaGuideBase(__p0) \
	LP1(36, LONG , LockAmigaGuideBase, \
		APTR , __p0, a0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExpungeXRef() \
	LP0NR(132, ExpungeXRef, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveAmigaGuideHostA(__p0, __p1) \
	LP2(144, LONG , RemoveAmigaGuideHostA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AmigaGuideSignal(__p0) \
	LP1(72, ULONG , AmigaGuideSignal, \
		APTR , __p0, a0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddAmigaGuideHostA(__p0, __p1, __p2) \
	LP3(138, APTR , AddAmigaGuideHostA, \
		struct Hook *, __p0, a0, \
		STRPTR , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AG_LinkExists(__p0) \
	(((BOOL (*)(CONST_STRPTR , void *))*(void**)((long)(AMIGAGUIDE_BASE_NAME) - 226))(__p0, (void*)(AMIGAGUIDE_BASE_NAME)))

#define GetAmigaGuideAttr(__p0, __p1, __p2) \
	LP3(114, LONG , GetAmigaGuideAttr, \
		Tag , __p0, d0, \
		APTR , __p1, a0, \
		ULONG *, __p2, a1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetAmigaGuideContextA(__p0, __p1, __p2) \
	LP3(90, LONG , SetAmigaGuideContextA, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		struct TagItem *, __p2, d1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetAmigaGuideAttrsA(__p0, __p1) \
	LP2(108, LONG , SetAmigaGuideAttrsA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SendAmigaGuideContextA(__p0, __p1) \
	LP2(96, LONG , SendAmigaGuideContextA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, d0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetAmigaGuideString(__p0) \
	LP1(210, STRPTR , GetAmigaGuideString, \
		LONG , __p0, d0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReplyAmigaGuideMsg(__p0) \
	LP1NR(84, ReplyAmigaGuideMsg, \
		struct AmigaGuideMsg *, __p0, a0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetAmigaGuideMsg(__p0) \
	LP1(78, struct AmigaGuideMsg *, GetAmigaGuideMsg, \
		APTR , __p0, a0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockAmigaGuideBase(__p0) \
	LP1NR(42, UnlockAmigaGuideBase, \
		LONG , __p0, d0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseAmigaGuide(__p0) \
	LP1NR(66, CloseAmigaGuide, \
		APTR , __p0, a0, \
		, AMIGAGUIDE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define OpenAmigaGuideAsync(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenAmigaGuideAsyncA(__p0, (struct TagItem *)_tags);})

#define SetAmigaGuideAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetAmigaGuideAttrsA(__p0, (struct TagItem *)_tags);})

#define RemoveAmigaGuideHost(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RemoveAmigaGuideHostA(__p0, (struct TagItem *)_tags);})

#define SetAmigaGuideContext(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetAmigaGuideContextA(__p0, __p1, (struct TagItem *)_tags);})

#define SendAmigaGuideContext(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SendAmigaGuideContextA(__p0, (struct TagItem *)_tags);})

#define AddAmigaGuideHost(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddAmigaGuideHostA(__p0, __p1, (struct TagItem *)_tags);})

#define SendAmigaGuideCmd(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SendAmigaGuideCmdA(__p0, __p1, (struct TagItem *)_tags);})

#define OpenAmigaGuide(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenAmigaGuideA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_AMIGAGUIDE_H */
