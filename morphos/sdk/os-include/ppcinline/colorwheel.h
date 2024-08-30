/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_COLORWHEEL_H
#define _PPCINLINE_COLORWHEEL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef COLORWHEEL_BASE_NAME
#define COLORWHEEL_BASE_NAME ColorWheelBase
#endif /* !COLORWHEEL_BASE_NAME */

#define ConvertHSBToRGB(__p0, __p1) \
	LP2NR(30, ConvertHSBToRGB, \
		struct ColorWheelHSB *, __p0, a0, \
		struct ColorWheelRGB *, __p1, a1, \
		, COLORWHEEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ConvertRGBToHSB(__p0, __p1) \
	LP2NR(36, ConvertRGBToHSB, \
		struct ColorWheelRGB *, __p0, a0, \
		struct ColorWheelHSB *, __p1, a1, \
		, COLORWHEEL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_COLORWHEEL_H */
