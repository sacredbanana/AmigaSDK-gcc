/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MATHIEEESINGBAS_H
#define _PPCINLINE_MATHIEEESINGBAS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MATHIEEESINGBAS_BASE_NAME
#define MATHIEEESINGBAS_BASE_NAME MathIeeeSingBasBase
#endif /* !MATHIEEESINGBAS_BASE_NAME */

#define IEEESPSub(__p0, __p1) \
	LP2(72, FLOAT , IEEESPSub, \
		FLOAT , __p0, d0, \
		FLOAT , __p1, d1, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPAbs(__p0) \
	LP1(54, FLOAT , IEEESPAbs, \
		FLOAT , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPTst(__p0) \
	LP1(48, LONG , IEEESPTst, \
		FLOAT , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPFix(__p0) \
	LP1(30, LONG , IEEESPFix, \
		FLOAT , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPAdd(__p0, __p1) \
	LP2(66, FLOAT , IEEESPAdd, \
		FLOAT , __p0, d0, \
		FLOAT , __p1, d1, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPFloor(__p0) \
	LP1(90, FLOAT , IEEESPFloor, \
		FLOAT , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPMul(__p0, __p1) \
	LP2(78, FLOAT , IEEESPMul, \
		FLOAT , __p0, d0, \
		FLOAT , __p1, d1, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPFlt(__p0) \
	LP1(36, FLOAT , IEEESPFlt, \
		LONG , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPNeg(__p0) \
	LP1(60, FLOAT , IEEESPNeg, \
		FLOAT , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPDiv(__p0, __p1) \
	LP2(84, FLOAT , IEEESPDiv, \
		FLOAT , __p0, d0, \
		FLOAT , __p1, d1, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPCeil(__p0) \
	LP1(96, FLOAT , IEEESPCeil, \
		FLOAT , __p0, d0, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IEEESPCmp(__p0, __p1) \
	LP2(42, LONG , IEEESPCmp, \
		FLOAT , __p0, d0, \
		FLOAT , __p1, d1, \
		, MATHIEEESINGBAS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_MATHIEEESINGBAS_H */
