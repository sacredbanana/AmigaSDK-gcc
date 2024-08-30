/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_KEYMAP_H
#define _PPCINLINE_KEYMAP_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef KEYMAP_BASE_NAME
#define KEYMAP_BASE_NAME KeymapBase
#endif /* !KEYMAP_BASE_NAME */

#define SetKeyMapDefault(__p0) \
	LP1NR(30, SetKeyMapDefault, \
		CONST struct KeyMap *, __p0, a0, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AskKeyMapDefault() \
	LP0(36, struct KeyMap *, AskKeyMapDefault, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MapRawKey(__p0, __p1, __p2, __p3) \
	LP4(42, WORD , MapRawKey, \
		CONST struct InputEvent *, __p0, a0, \
		STRPTR , __p1, a1, \
		LONG , __p2, d1, \
		CONST struct KeyMap *, __p3, a2, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MapANSI(__p0, __p1, __p2, __p3, __p4) \
	LP5(48, LONG , MapANSI, \
		CONST_STRPTR , __p0, a0, \
		LONG , __p1, d0, \
		STRPTR , __p2, a1, \
		LONG , __p3, d1, \
		CONST struct KeyMap *, __p4, a2, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MapRawKeyUCS4(__p0, __p1, __p2, __p3) \
	LP4(54, WORD , MapRawKeyUCS4, \
		CONST struct InputEvent *, __p0, a0, \
		WSTRPTR , __p1, a1, \
		LONG , __p2, d1, \
		CONST struct KeyMap *, __p3, a2, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MapUCS4(__p0, __p1, __p2, __p3, __p4) \
	LP5(60, LONG , MapUCS4, \
		CONST_WSTRPTR , __p0, a0, \
		LONG , __p1, d0, \
		STRPTR , __p2, a1, \
		LONG , __p3, d1, \
		CONST struct KeyMap *, __p4, a2, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ToANSI(__p0, __p1) \
	LP2(66, char , ToANSI, \
		WCHAR , __p0, a0, \
		CONST struct KeyMap *, __p1, a1, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ToUCS4(__p0, __p1) \
	LP2(72, WCHAR , ToUCS4, \
		char , __p0, a0, \
		CONST struct KeyMap *, __p1, a1, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetKeyMapCodepage(__p0) \
	LP1(78, CONST_STRPTR , GetKeyMapCodepage, \
		CONST struct KeyMap *, __p0, a0, \
		, KEYMAP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_KEYMAP_H */
