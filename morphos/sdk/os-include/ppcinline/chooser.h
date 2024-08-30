/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CHOOSER_H
#define _PPCINLINE_CHOOSER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CHOOSER_BASE_NAME
#define CHOOSER_BASE_NAME ChooserBase
#endif /* !CHOOSER_BASE_NAME */

#define AllocChooserNodeA(__p0) \
	LP1(36, struct Node *, AllocChooserNodeA, \
		struct TagItem *, __p0, a0, \
		, CHOOSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CHOOSER_GetClass() \
	LP0(30, Class *, CHOOSER_GetClass, \
		, CHOOSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetChooserNodeAttrsA(__p0, __p1) \
	LP2NR(54, GetChooserNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CHOOSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetChooserNodeAttrsA(__p0, __p1) \
	LP2NR(48, SetChooserNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CHOOSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeChooserNode(__p0) \
	LP1NR(42, FreeChooserNode, \
		struct Node *, __p0, a0, \
		, CHOOSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocChooserNode(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocChooserNodeA((struct TagItem *)_tags);})

#define GetChooserNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetChooserNodeAttrsA(__p0, (struct TagItem *)_tags);})

#define SetChooserNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetChooserNodeAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CHOOSER_H */
