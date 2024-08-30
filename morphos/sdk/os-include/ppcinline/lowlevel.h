/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LOWLEVEL_H
#define _PPCINLINE_LOWLEVEL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LOWLEVEL_BASE_NAME
#define LOWLEVEL_BASE_NAME LowLevelBase
#endif /* !LOWLEVEL_BASE_NAME */

#define GetKey() \
	LP0(48, ULONG , GetKey, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemTimerInt(__p0) \
	LP1NR(84, RemTimerInt, \
		APTR , __p0, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define QueryKeys(__p0, __p1) \
	LP2NR(54, QueryKeys, \
		struct KeyQuery *, __p0, a0, \
		ULONG , __p1, d1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadJoyPort(__p0) \
	LP1(30, ULONG , ReadJoyPort, \
		ULONG , __p0, d0, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StartTimerInt(__p0, __p1, __p2) \
	LP3NR(96, StartTimerInt, \
		APTR , __p0, a1, \
		ULONG , __p1, d0, \
		LONG , __p2, d1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddKBInt(__p0, __p1) \
	LP2(60, APTR , AddKBInt, \
		CONST APTR , __p0, a0, \
		CONST APTR , __p1, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SystemControlA(__p0) \
	LP1(72, ULONG , SystemControlA, \
		CONST struct TagItem *, __p0, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StopTimerInt(__p0) \
	LP1NR(90, StopTimerInt, \
		APTR , __p0, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddTimerInt(__p0, __p1) \
	LP2(78, APTR , AddTimerInt, \
		CONST APTR , __p0, a0, \
		CONST APTR , __p1, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemVBlankInt(__p0) \
	LP1NR(114, RemVBlankInt, \
		APTR , __p0, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemKBInt(__p0) \
	LP1NR(66, RemKBInt, \
		APTR , __p0, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ElapsedTime(__p0) \
	LP1(102, ULONG , ElapsedTime, \
		struct EClockVal *, __p0, a0, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddVBlankInt(__p0, __p1) \
	LP2(108, APTR , AddVBlankInt, \
		CONST APTR , __p0, a0, \
		CONST APTR , __p1, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetJoyPortAttrsA(__p0, __p1) \
	LP2(132, BOOL , SetJoyPortAttrsA, \
		ULONG , __p0, d0, \
		CONST struct TagItem *, __p1, a1, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetLanguageSelection() \
	LP0(36, UBYTE , GetLanguageSelection, \
		, LOWLEVEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SystemControl(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SystemControlA((CONST struct TagItem *)_tags);})

#define SetJoyPortAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetJoyPortAttrsA(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_LOWLEVEL_H */
