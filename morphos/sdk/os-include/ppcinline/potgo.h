/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POTGO_H
#define _PPCINLINE_POTGO_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POTGO_BASE_NAME
#define POTGO_BASE_NAME PotgoBase
#endif /* !POTGO_BASE_NAME */

#define AllocPotBits(__p0) \
	LP1(6, UWORD , AllocPotBits, \
		ULONG , __p0, d0, \
		, POTGO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreePotBits(__p0) \
	LP1NR(12, FreePotBits, \
		ULONG , __p0, d0, \
		, POTGO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WritePotgo(__p0, __p1) \
	LP2NR(18, WritePotgo, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, POTGO_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_POTGO_H */
