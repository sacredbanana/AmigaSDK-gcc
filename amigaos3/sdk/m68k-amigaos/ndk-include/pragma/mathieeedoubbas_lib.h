#ifndef PRAGMA_MATHIEEEDOUBBAS_LIB_H
#define PRAGMA_MATHIEEEDOUBBAS_LIB_H

/*
**	$VER: mathieeedoubbas_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_MATHIEEEDOUBBAS_PROTOS_H
#include <clib/mathieeedoubbas_protos.h>
#endif /* CLIB_MATHIEEEDOUBBAS_PROTOS_H */

/* "mathieeedoubbas.library" */
#pragma amicall(MathIeeeDoubBasBase, 0x1e, IEEEDPFix(d0))
#pragma amicall(MathIeeeDoubBasBase, 0x24, IEEEDPFlt(d0))
#pragma amicall(MathIeeeDoubBasBase, 0x2a, IEEEDPCmp(d0,d2))
#pragma amicall(MathIeeeDoubBasBase, 0x30, IEEEDPTst(d0))
#pragma amicall(MathIeeeDoubBasBase, 0x36, IEEEDPAbs(d0))
#pragma amicall(MathIeeeDoubBasBase, 0x3c, IEEEDPNeg(d0))
#pragma amicall(MathIeeeDoubBasBase, 0x42, IEEEDPAdd(d0,d2))
#pragma amicall(MathIeeeDoubBasBase, 0x48, IEEEDPSub(d0,d2))
#pragma amicall(MathIeeeDoubBasBase, 0x4e, IEEEDPMul(d0,d2))
#pragma amicall(MathIeeeDoubBasBase, 0x54, IEEEDPDiv(d0,d2))
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma amicall(MathIeeeDoubBasBase, 0x5a, IEEEDPFloor(d0))
#pragma amicall(MathIeeeDoubBasBase, 0x60, IEEEDPCeil(d0))

#endif /* PRAGMA_MATHIEEEDOUBBAS_LIB_H */
