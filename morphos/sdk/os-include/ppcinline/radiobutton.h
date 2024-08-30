/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_RADIOBUTTON_H
#define _PPCINLINE_RADIOBUTTON_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef RADIOBUTTON_BASE_NAME
#define RADIOBUTTON_BASE_NAME RadioButtonBase
#endif /* !RADIOBUTTON_BASE_NAME */

#define RADIOBUTTON_GetClass() \
	LP0(30, Class *, RADIOBUTTON_GetClass, \
		, RADIOBUTTON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetRadioButtonNodeAttrsA(__p0, __p1) \
	LP2NR(54, GetRadioButtonNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, RADIOBUTTON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeRadioButtonNode(__p0) \
	LP1NR(42, FreeRadioButtonNode, \
		struct Node *, __p0, a0, \
		, RADIOBUTTON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRadioButtonNodeAttrsA(__p0, __p1) \
	LP2NR(48, SetRadioButtonNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, RADIOBUTTON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocRadioButtonNodeA(__p0, __p1) \
	LP2(36, struct Node *, AllocRadioButtonNodeA, \
		ULONG , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, RADIOBUTTON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocRadioButtonNode(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocRadioButtonNodeA(__p0, (struct TagItem *)_tags);})

#define GetRadioButtonNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetRadioButtonNodeAttrsA(__p0, (struct TagItem *)_tags);})

#define SetRadioButtonNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetRadioButtonNodeAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_RADIOBUTTON_H */
