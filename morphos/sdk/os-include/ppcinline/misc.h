/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MISC_H
#define _PPCINLINE_MISC_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MISC_BASE_NAME
#define MISC_BASE_NAME MiscBase
#endif /* !MISC_BASE_NAME */

#define AllocMiscResource(__p0, __p1) \
	LP2(6, UBYTE *, AllocMiscResource, \
		ULONG , __p0, d0, \
		CONST_STRPTR , __p1, a1, \
		, MISC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeMiscResource(__p0) \
	LP1NR(12, FreeMiscResource, \
		ULONG , __p0, d0, \
		, MISC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_MISC_H */
