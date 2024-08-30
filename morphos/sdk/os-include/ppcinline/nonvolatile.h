/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_NONVOLATILE_H
#define _PPCINLINE_NONVOLATILE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef NONVOLATILE_BASE_NAME
#define NONVOLATILE_BASE_NAME NVBase
#endif /* !NONVOLATILE_BASE_NAME */

#define GetNVInfo(__p0) \
	LP1(54, struct NVInfo *, GetNVInfo, \
		LONG , __p0, d1, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetCopyNV(__p0, __p1, __p2) \
	LP3(30, APTR , GetCopyNV, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		LONG , __p2, d1, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetNVProtection(__p0, __p1, __p2, __p3) \
	LP4(66, BOOL , SetNVProtection, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		LONG , __p2, d2, \
		LONG , __p3, d1, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeNVData(__p0) \
	LP1NR(36, FreeNVData, \
		APTR , __p0, a0, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetNVList(__p0, __p1) \
	LP2(60, struct MinList *, GetNVList, \
		CONST_STRPTR , __p0, a0, \
		LONG , __p1, d1, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StoreNV(__p0, __p1, __p2, __p3, __p4) \
	LP5(42, UWORD , StoreNV, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST APTR , __p2, a2, \
		ULONG , __p3, d0, \
		LONG , __p4, d1, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteNV(__p0, __p1, __p2) \
	LP3(48, BOOL , DeleteNV, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		LONG , __p2, d1, \
		, NONVOLATILE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_NONVOLATILE_H */
