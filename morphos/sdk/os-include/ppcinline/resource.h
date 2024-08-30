/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_RESOURCE_H
#define _PPCINLINE_RESOURCE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef RESOURCE_BASE_NAME
#define RESOURCE_BASE_NAME ResourceBase
#endif /* !RESOURCE_BASE_NAME */

#define RL_CloseResource(__p0) \
	LP1NR(36, RL_CloseResource, \
		RESOURCEFILE , __p0, a0, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_OpenResource(__p0, __p1, __p2) \
	LP3(30, RESOURCEFILE , RL_OpenResource, \
		APTR , __p0, a0, \
		struct Screen *, __p1, a1, \
		struct Catalog *, __p2, a2, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_SetResourceScreen(__p0, __p1) \
	LP2(72, BOOL , RL_SetResourceScreen, \
		RESOURCEFILE , __p0, a0, \
		struct Screen *, __p1, a1, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_NewObjectA(__p0, __p1, __p2) \
	LP3(42, Object *, RL_NewObjectA, \
		RESOURCEFILE , __p0, a0, \
		RESOURCEID , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_DisposeObject(__p0, __p1) \
	LP2NR(48, RL_DisposeObject, \
		RESOURCEFILE , __p0, a0, \
		Object *, __p1, a1, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_GetObjectArray(__p0, __p1, __p2) \
	LP3(66, Object **, RL_GetObjectArray, \
		RESOURCEFILE , __p0, a0, \
		Object *, __p1, a1, \
		RESOURCEID , __p2, d0, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_DisposeGroup(__p0, __p1) \
	LP2NR(60, RL_DisposeGroup, \
		RESOURCEFILE , __p0, a0, \
		Object **, __p1, a1, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RL_NewGroupA(__p0, __p1, __p2) \
	LP3(54, Object **, RL_NewGroupA, \
		RESOURCEFILE , __p0, a0, \
		RESOURCEID , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, RESOURCE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define RL_NewGroup(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RL_NewGroupA(__p0, __p1, (struct TagItem *)_tags);})

#define RL_NewObject(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RL_NewObjectA(__p0, __p1, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_RESOURCE_H */
