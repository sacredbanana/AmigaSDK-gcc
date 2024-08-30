/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_ASL_H
#define _PPCINLINE_ASL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef ASL_BASE_NAME
#define ASL_BASE_NAME AslBase
#endif /* !ASL_BASE_NAME */

#define AbortAslRequest(__p0) \
	LP1NR(78, AbortAslRequest, \
		APTR , __p0, a0, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RequestFile(__p0) \
	LP1(42, BOOL , RequestFile, \
		struct FileRequester *, __p0, a0, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AslRequest(__p0, __p1) \
	LP2(60, BOOL , AslRequest, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeFileRequest(__p0) \
	LP1NR(36, FreeFileRequest, \
		struct FileRequester *, __p0, a0, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeAslRequest(__p0) \
	LP1NR(54, FreeAslRequest, \
		APTR , __p0, a0, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocFileRequest() \
	LP0(30, struct FileRequester *, AllocFileRequest, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocAslRequest(__p0, __p1) \
	LP2(48, APTR , AllocAslRequest, \
		ULONG , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ActivateAslRequest(__p0) \
	LP1NR(84, ActivateAslRequest, \
		APTR , __p0, a0, \
		, ASL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocAslRequestTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocAslRequest(__p0, (struct TagItem *)_tags);})

#define AslRequestTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AslRequest(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_ASL_H */
