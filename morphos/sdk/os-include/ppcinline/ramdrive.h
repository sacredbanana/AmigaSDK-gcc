/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_RAMDRIVE_H
#define _PPCINLINE_RAMDRIVE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef RAMDRIVE_BASE_NAME
#define RAMDRIVE_BASE_NAME RamdriveDevice
#endif /* !RAMDRIVE_BASE_NAME */

#define KillRAD(__p0) \
	LP1(48, STRPTR , KillRAD, \
		ULONG , __p0, d0, \
		, RAMDRIVE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define KillRAD0() \
	LP0(42, STRPTR , KillRAD0, \
		, RAMDRIVE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_RAMDRIVE_H */
