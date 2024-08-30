/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CONSOLE_H
#define _PPCINLINE_CONSOLE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CONSOLE_BASE_NAME
#define CONSOLE_BASE_NAME ConsoleDevice
#endif /* !CONSOLE_BASE_NAME */



#define RawKeyConvert(__p0, __p1, __p2, __p3) \
	LP4(48, LONG , RawKeyConvert, \
		CONST struct InputEvent *, __p0, a0, \
		STRPTR , __p1, a1, \
		LONG , __p2, d1, \
		CONST struct KeyMap *, __p3, a2, \
		, CONSOLE_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define CDInputHandler(__p0, __p1) \
	LP2(42, struct InputEvent *, CDInputHandler, \
		CONST struct InputEvent *, __p0, a0, \
		struct Library *, __p1, a1, \
		, CONSOLE_BASE_NAME, 0, 0, 0, 0, 0, 0)


#endif /* !_PPCINLINE_CONSOLE_H */
