/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CIA_H
#define _PPCINLINE_CIA_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CIA_BASE_NAME
#define CIA_BASE_NAME LibBase
#endif /* !CIA_BASE_NAME */

#define SetICR(__p0, __p1) \
	LP2UB(24, WORD , SetICR, \
		struct Library *, __p0, a6, \
		LONG , __p1, d0, \
		 0, 0, 0, 0, 0, 0)

#define AbleICR(__p0, __p1) \
	LP2UB(18, WORD , AbleICR, \
		struct Library *, __p0, a6, \
		LONG , __p1, d0, \
		 0, 0, 0, 0, 0, 0)

#define RemICRVector(__p0, __p1, __p2) \
	LP3NRUB(12, RemICRVector, \
		struct Library *, __p0, a6, \
		LONG , __p1, d0, \
		struct Interrupt *, __p2, a1, \
		 0, 0, 0, 0, 0, 0)

#define AddICRVector(__p0, __p1, __p2) \
	LP3UB(6, struct Interrupt *, AddICRVector, \
		struct Library *, __p0, a6, \
		LONG , __p1, d0, \
		struct Interrupt *, __p2, a1, \
		 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_CIA_H */
