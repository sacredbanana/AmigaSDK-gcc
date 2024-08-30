#ifndef PRAGMA_MATHFFP_LIB_H
#define PRAGMA_MATHFFP_LIB_H

/*
**	$VER: mathffp_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_MATHFFP_PROTOS_H
#include <clib/mathffp_protos.h>
#endif /* CLIB_MATHFFP_PROTOS_H */

/* "mathffp.library" */
#pragma amicall(MathBase, 0x1e, SPFix(d0))
#pragma amicall(MathBase, 0x24, SPFlt(d0))
#pragma amicall(MathBase, 0x2a, SPCmp(d1,d0))
#pragma amicall(MathBase, 0x30, SPTst(d1))
#pragma amicall(MathBase, 0x36, SPAbs(d0))
#pragma amicall(MathBase, 0x3c, SPNeg(d0))
#pragma amicall(MathBase, 0x42, SPAdd(d1,d0))
#pragma amicall(MathBase, 0x48, SPSub(d1,d0))
#pragma amicall(MathBase, 0x4e, SPMul(d1,d0))
#pragma amicall(MathBase, 0x54, SPDiv(d1,d0))
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma amicall(MathBase, 0x5a, SPFloor(d0))
#pragma amicall(MathBase, 0x60, SPCeil(d0))

#endif /* PRAGMA_MATHFFP_LIB_H */
