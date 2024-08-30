/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_VIRTUAL_H
#define _PPCINLINE_VIRTUAL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef VIRTUAL_BASE_NAME
#define VIRTUAL_BASE_NAME VirtualBase
#endif /* !VIRTUAL_BASE_NAME */

#define RefreshVirtualGadget(__p0, __p1, __p2, __p3) \
	LP4NR(36, RefreshVirtualGadget, \
		struct Gadget *, __p0, a0, \
		ULONG , __p1, a1, \
		struct Window *, __p2, a2, \
		struct Requester *, __p3, a3, \
		, VIRTUAL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VIRTUAL_GetClass() \
	LP0(30, struct IClass *, VIRTUAL_GetClass, \
		, VIRTUAL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RethinkVirtualSize(__p0, __p1, __p2, __p3, __p4) \
	LP5(42, BOOL , RethinkVirtualSize, \
		ULONG , __p0, a0, \
		ULONG , __p1, a1, \
		struct TextFont *, __p2, a2, \
		struct Screen *, __p3, a3, \
		struct LayoutLimits *, __p4, d0, \
		, VIRTUAL_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_VIRTUAL_H */
