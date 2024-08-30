/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DISK_H
#define _PPCINLINE_DISK_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DISK_BASE_NAME
#define DISK_BASE_NAME DiskBase
#endif /* !DISK_BASE_NAME */

#define FreeUnit(__p0) \
	LP1NR(12, FreeUnit, \
		LONG , __p0, d0, \
		, DISK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GiveUnit() \
	LP0NR(24, GiveUnit, \
		, DISK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetUnitID(__p0) \
	LP1(30, LONG , GetUnitID, \
		LONG , __p0, d0, \
		, DISK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetUnit(__p0) \
	LP1(18, struct DiscResourceUnit *, GetUnit, \
		struct DiscResourceUnit *, __p0, a1, \
		, DISK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadUnitID(__p0) \
	LP1(36, LONG , ReadUnitID, \
		LONG , __p0, d0, \
		, DISK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocUnit(__p0) \
	LP1(6, BOOL , AllocUnit, \
		LONG , __p0, d0, \
		, DISK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_DISK_H */
