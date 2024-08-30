/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_REALTIME_H
#define _PPCINLINE_REALTIME_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef REALTIME_BASE_NAME
#define REALTIME_BASE_NAME RealTimeBase
#endif /* !REALTIME_BASE_NAME */

#define FindConductor(__p0) \
	LP1(78, struct Conductor *, FindConductor, \
		CONST_STRPTR , __p0, a0, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetPlayerAttrsA(__p0, __p1) \
	LP2(84, ULONG , GetPlayerAttrsA, \
		CONST struct Player *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetConductorState(__p0, __p1, __p2) \
	LP3(60, LONG , SetConductorState, \
		struct Player *, __p0, a0, \
		ULONG , __p1, d0, \
		LONG , __p2, d1, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExternalSync(__p0, __p1, __p2) \
	LP3(66, BOOL , ExternalSync, \
		struct Player *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetPlayerAttrsA(__p0, __p1) \
	LP2(54, BOOL , SetPlayerAttrsA, \
		struct Player *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NextConductor(__p0) \
	LP1(72, struct Conductor *, NextConductor, \
		CONST struct Conductor *, __p0, a0, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeletePlayer(__p0) \
	LP1NR(48, DeletePlayer, \
		struct Player *, __p0, a0, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockRealTime(__p0) \
	LP1(30, APTR , LockRealTime, \
		ULONG , __p0, d0, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockRealTime(__p0) \
	LP1NR(36, UnlockRealTime, \
		APTR , __p0, a0, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreatePlayerA(__p0) \
	LP1(42, struct Player *, CreatePlayerA, \
		CONST struct TagItem *, __p0, a0, \
		, REALTIME_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SetPlayerAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetPlayerAttrsA(__p0, (CONST struct TagItem *)_tags);})

#define CreatePlayer(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreatePlayerA((CONST struct TagItem *)_tags);})

#define GetPlayerAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetPlayerAttrsA(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_REALTIME_H */
