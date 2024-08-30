/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DATEBROWSER_H
#define _PPCINLINE_DATEBROWSER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DATEBROWSER_BASE_NAME
#define DATEBROWSER_BASE_NAME DateBrowserBase
#endif /* !DATEBROWSER_BASE_NAME */

#define JulianWeekDay(__p0, __p1, __p2) \
	LP3(36, UWORD , JulianWeekDay, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		LONG , __p2, d2, \
		, DATEBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define JulianLeapYear(__p0) \
	LP1(48, BOOL , JulianLeapYear, \
		LONG , __p0, d0, \
		, DATEBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DATEBROWSER_GetClass() \
	LP0(30, Class *, DATEBROWSER_GetClass, \
		, DATEBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define JulianMonthDays(__p0, __p1) \
	LP2(42, UWORD , JulianMonthDays, \
		ULONG , __p0, d0, \
		LONG , __p1, d1, \
		, DATEBROWSER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_DATEBROWSER_H */
