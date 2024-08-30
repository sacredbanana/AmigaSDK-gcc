/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MAGICBEACON_H
#define _PPCINLINE_MAGICBEACON_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MAGICBEACON_BASE_NAME
#define MAGICBEACON_BASE_NAME MagicBeaconBase
#endif /* !MAGICBEACON_BASE_NAME */

#define MagicBeacon_ApplicationRegisterTagList(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(MAGICBEACON_BASE_NAME) - 28))((void*)(MAGICBEACON_BASE_NAME), __p0))

#define MagicBeacon_ApplicationUnregister(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(MAGICBEACON_BASE_NAME) - 34))((void*)(MAGICBEACON_BASE_NAME), __p0))

#define MagicBeacon_GetAttrsTagList(__p0, __p1, __p2) \
	(((IPTR (*)(void *, APTR , APTR , struct TagItem *))*(void**)((long)(MAGICBEACON_BASE_NAME) - 40))((void*)(MAGICBEACON_BASE_NAME), __p0, __p1, __p2))

#define MagicBeacon_GetAttr(__p0, __p1, __p2) \
	(((IPTR (*)(void *, APTR , APTR , IPTR ))*(void**)((long)(MAGICBEACON_BASE_NAME) - 46))((void*)(MAGICBEACON_BASE_NAME), __p0, __p1, __p2))

#define MagicBeacon_BeaconSendTagList(__p0, __p1) \
	(((IPTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(MAGICBEACON_BASE_NAME) - 52))((void*)(MAGICBEACON_BASE_NAME), __p0, __p1))

#define MagicBeacon_BeaconObtain(__p0) \
	(((APTR (*)(void *, APTR ))*(void**)((long)(MAGICBEACON_BASE_NAME) - 58))((void*)(MAGICBEACON_BASE_NAME), __p0))

#define MagicBeacon_BeaconDispose(__p0, __p1) \
	(((void (*)(void *, APTR , APTR ))*(void**)((long)(MAGICBEACON_BASE_NAME) - 64))((void*)(MAGICBEACON_BASE_NAME), __p0, __p1))




















#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define MagicBeacon_ApplicationRegisterTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MagicBeacon_ApplicationRegisterTagList((struct TagItem *)_tags);})

#define MagicBeacon_GetAttrsTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MagicBeacon_GetAttrsTagList(__p0, __p1, (struct TagItem *)_tags);})

#define MagicBeacon_BeaconSendTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MagicBeacon_BeaconSendTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_MAGICBEACON_H */
