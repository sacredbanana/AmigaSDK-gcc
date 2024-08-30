/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_IFCONFIG_H
#define _PPCINLINE_IFCONFIG_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef IFCONFIG_BASE_NAME
#define IFCONFIG_BASE_NAME IfConfigBase
#endif /* !IFCONFIG_BASE_NAME */

#define IfConfigGetData(__p0, __p1, __p2) \
	LP3(78, ULONG , IfConfigGetData, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		struct ifconfig *, __p2, a0, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigStrError(__p0, __p1, __p2) \
	LP3(60, const UBYTE *, IfConfigStrError, \
		ULONG , __p0, d0, \
		char *, __p1, a0, \
		ULONG , __p2, d1, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigFreeList(__p0) \
	LP1NR(54, IfConfigFreeList, \
		struct List *, __p0, a0, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigFree(__p0) \
	LP1NR(42, IfConfigFree, \
		struct ifconfig *, __p0, a0, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigCreate(__p0, __p1) \
	LP2(72, struct ifconfig *, IfConfigCreate, \
		char *, __p0, a0, \
		ULONG , __p1, d0, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigGetTagInfo(__p0) \
	LP1(66, const struct ifc_confitem *, IfConfigGetTagInfo, \
		ULONG , __p0, d0, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigFind(__p0, __p1) \
	LP2(36, LONG , IfConfigFind, \
		const char *, __p0, a0, \
		struct ifconfig **, __p1, a1, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfConfigFindAll(__p0, __p1) \
	LP2(48, LONG , IfConfigFindAll, \
		struct List **, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, IFCONFIG_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_IFCONFIG_H */
