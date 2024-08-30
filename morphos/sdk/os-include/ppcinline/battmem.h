/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_BATTMEM_H
#define _PPCINLINE_BATTMEM_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef BATTMEM_BASE_NAME
#define BATTMEM_BASE_NAME BattMemBase
#endif /* !BATTMEM_BASE_NAME */

#define ReadBattMem(__p0, __p1, __p2) \
	LP3(18, ULONG , ReadBattMem, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, BATTMEM_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainBattSemaphore() \
	LP0NR(6, ObtainBattSemaphore, \
		, BATTMEM_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseBattSemaphore() \
	LP0NR(12, ReleaseBattSemaphore, \
		, BATTMEM_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteBattMem(__p0, __p1, __p2) \
	LP3(24, ULONG , WriteBattMem, \
		CONST APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, BATTMEM_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_BATTMEM_H */
