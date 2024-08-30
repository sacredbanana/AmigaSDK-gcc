/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PCIIDS_H
#define _PPCINLINE_PCIIDS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PCIIDS_BASE_NAME
#define PCIIDS_BASE_NAME PCIIDSBase
#endif /* !PCIIDS_BASE_NAME */

#define PCIIDS_GetVendorName(__p0) \
	(((CONST_STRPTR (*)(void *, ULONG ))*(void**)((long)(PCIIDS_BASE_NAME) - 28))((void*)(PCIIDS_BASE_NAME), __p0))

#define PCIIDS_GetClassName(__p0) \
	(((CONST_STRPTR (*)(void *, ULONG ))*(void**)((long)(PCIIDS_BASE_NAME) - 46))((void*)(PCIIDS_BASE_NAME), __p0))

#define PCIIDS_GetProgIfName(__p0, __p1, __p2) \
	(((CONST_STRPTR (*)(void *, ULONG , ULONG , ULONG ))*(void**)((long)(PCIIDS_BASE_NAME) - 58))((void*)(PCIIDS_BASE_NAME), __p0, __p1, __p2))

#define PCIIDS_LoadFile(__p0) \
	(((LONG (*)(void *, CONST_STRPTR ))*(void**)((long)(PCIIDS_BASE_NAME) - 64))((void*)(PCIIDS_BASE_NAME), __p0))

#define PCIIDS_GetDeviceName(__p0, __p1) \
	(((CONST_STRPTR (*)(void *, ULONG , ULONG ))*(void**)((long)(PCIIDS_BASE_NAME) - 34))((void*)(PCIIDS_BASE_NAME), __p0, __p1))

#define PCIIDS_GetSubClassName(__p0, __p1) \
	(((CONST_STRPTR (*)(void *, ULONG , ULONG ))*(void**)((long)(PCIIDS_BASE_NAME) - 52))((void*)(PCIIDS_BASE_NAME), __p0, __p1))

#define PCIIDS_GetSubDeviceName(__p0, __p1, __p2, __p3) \
	(((CONST_STRPTR (*)(void *, ULONG , ULONG , ULONG , ULONG ))*(void**)((long)(PCIIDS_BASE_NAME) - 40))((void*)(PCIIDS_BASE_NAME), __p0, __p1, __p2, __p3))

#endif /* !_PPCINLINE_PCIIDS_H */
