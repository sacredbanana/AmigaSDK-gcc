/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MATHFFP_H
#define _PPCINLINE_MATHFFP_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MATHFFP_BASE_NAME
#define MATHFFP_BASE_NAME MathBase
#endif /* !MATHFFP_BASE_NAME */

#define SPFloor(__p0) \
	LP1(90, FLOAT , SPFloor, \
		FLOAT , __p0, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPMul(__p0, __p1) \
	LP2(78, FLOAT , SPMul, \
		FLOAT , __p0, d1, \
		FLOAT , __p1, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPFlt(__p0) \
	LP1(36, FLOAT , SPFlt, \
		LONG , __p0, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPNeg(__p0) \
	LP1(60, FLOAT , SPNeg, \
		FLOAT , __p0, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPDiv(__p0, __p1) \
	LP2(84, FLOAT , SPDiv, \
		FLOAT , __p0, d1, \
		FLOAT , __p1, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPCeil(__p0) \
	LP1(96, FLOAT , SPCeil, \
		FLOAT , __p0, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPCmp(__p0, __p1) \
	LP2(42, LONG , SPCmp, \
		FLOAT , __p0, d1, \
		FLOAT , __p1, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPSub(__p0, __p1) \
	LP2(72, FLOAT , SPSub, \
		FLOAT , __p0, d1, \
		FLOAT , __p1, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPAbs(__p0) \
	LP1(54, FLOAT , SPAbs, \
		FLOAT , __p0, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPTst(__p0) \
	LP1(48, LONG , SPTst, \
		FLOAT , __p0, d1, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPFix(__p0) \
	LP1(30, LONG , SPFix, \
		FLOAT , __p0, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPAdd(__p0, __p1) \
	LP2(66, FLOAT , SPAdd, \
		FLOAT , __p0, d1, \
		FLOAT , __p1, d0, \
		, MATHFFP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_MATHFFP_H */
