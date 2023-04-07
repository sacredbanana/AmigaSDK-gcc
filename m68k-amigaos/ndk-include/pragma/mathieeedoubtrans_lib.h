#ifndef PRAGMA_MATHIEEEDOUBTRANS_LIB_H
#define PRAGMA_MATHIEEEDOUBTRANS_LIB_H

/*
**	$VER: mathieeedoubtrans_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_MATHIEEEDOUBTRANS_PROTOS_H
#include <clib/mathieeedoubtrans_protos.h>
#endif /* CLIB_MATHIEEEDOUBTRANS_PROTOS_H */

/* "mathieeedoubtrans.library" */
#pragma amicall(MathIeeeDoubTransBase, 0x1e, IEEEDPAtan(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x24, IEEEDPSin(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x2a, IEEEDPCos(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x30, IEEEDPTan(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x36, IEEEDPSincos(a0,d0))
#pragma amicall(MathIeeeDoubTransBase, 0x3c, IEEEDPSinh(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x42, IEEEDPCosh(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x48, IEEEDPTanh(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x4e, IEEEDPExp(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x54, IEEEDPLog(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x5a, IEEEDPPow(d2,d0))
#pragma amicall(MathIeeeDoubTransBase, 0x60, IEEEDPSqrt(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x66, IEEEDPTieee(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x6c, IEEEDPFieee(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x72, IEEEDPAsin(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x78, IEEEDPAcos(d0))
#pragma amicall(MathIeeeDoubTransBase, 0x7e, IEEEDPLog10(d0))

#endif /* PRAGMA_MATHIEEEDOUBTRANS_LIB_H */
