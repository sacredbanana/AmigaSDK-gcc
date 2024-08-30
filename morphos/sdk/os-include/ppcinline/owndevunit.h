/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_OWNDEVUNIT_H
#define _PPCINLINE_OWNDEVUNIT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef OWNDEVUNIT_BASE_NAME
#define OWNDEVUNIT_BASE_NAME OwnDevUnitBase
#endif /* !OWNDEVUNIT_BASE_NAME */

#define FreeDevUnit(__p0, __p1) \
	LP2NR(42, FreeDevUnit, \
		UBYTE *, __p0, a0, \
		ULONG , __p1, d0, \
		, OWNDEVUNIT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockDevUnit(__p0, __p1, __p2, __p3) \
	LP4(30, UBYTE *, LockDevUnit, \
		UBYTE *, __p0, a0, \
		ULONG , __p1, d0, \
		UBYTE *, __p2, a1, \
		UBYTE , __p3, d1, \
		, OWNDEVUNIT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttemptDevUnit(__p0, __p1, __p2, __p3) \
	LP4(36, UBYTE *, AttemptDevUnit, \
		UBYTE *, __p0, a0, \
		ULONG , __p1, d0, \
		UBYTE *, __p2, a1, \
		UBYTE , __p3, d1, \
		, OWNDEVUNIT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AvailDevUnit(__p0, __p1) \
	LP2(54, BOOL , AvailDevUnit, \
		UBYTE *, __p0, a0, \
		ULONG , __p1, d0, \
		, OWNDEVUNIT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NameDevUnit(__p0, __p1, __p2) \
	LP3NR(48, NameDevUnit, \
		UBYTE *, __p0, a0, \
		ULONG , __p1, d0, \
		UBYTE *, __p2, a1, \
		, OWNDEVUNIT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_OWNDEVUNIT_H */
