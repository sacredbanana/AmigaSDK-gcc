/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_TOUCHPAD_H
#define _PPCINLINE_TOUCHPAD_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef TOUCHPAD_BASE_NAME
#define TOUCHPAD_BASE_NAME TouchpadBase
#endif /* !TOUCHPAD_BASE_NAME */

#define RemoveTouchpad(__p0, __p1) \
	(((void (*)(void *, APTR , struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 34))((void*)(TOUCHPAD_BASE_NAME), __p0, __p1))

#define AddTouchpad(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 28))((void*)(TOUCHPAD_BASE_NAME), __p0))

#define FeedTouchpad(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(void *, APTR , UBYTE *, UBYTE *, ULONG , struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 40))((void*)(TOUCHPAD_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define ObtainTouchpad(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 46))((void*)(TOUCHPAD_BASE_NAME), __p0))

#define GetTouchpadAttr(__p0, __p1) \
	(((ULONG (*)(void *, APTR , struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 58))((void*)(TOUCHPAD_BASE_NAME), __p0, __p1))

#define SetTouchpadAttr(__p0, __p1) \
	(((ULONG (*)(void *, APTR , struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 64))((void*)(TOUCHPAD_BASE_NAME), __p0, __p1))

#define ReleaseTouchpad(__p0, __p1) \
	(((void (*)(void *, APTR , struct TagItem *))*(void**)((long)(TOUCHPAD_BASE_NAME) - 52))((void*)(TOUCHPAD_BASE_NAME), __p0, __p1))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define ReleaseTouchpadTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ReleaseTouchpad(__p0, (struct TagItem *)_tags);})

#define GetTouchpadAttrTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetTouchpadAttr(__p0, (struct TagItem *)_tags);})

#define FeedTouchpadTags(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	FeedTouchpad(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define RemoveTouchpadTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RemoveTouchpad(__p0, (struct TagItem *)_tags);})

#define AddTouchpadTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddTouchpad((struct TagItem *)_tags);})

#define SetTouchpadAttrTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetTouchpadAttr(__p0, (struct TagItem *)_tags);})

#define ObtainTouchpadTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ObtainTouchpad((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_TOUCHPAD_H */
