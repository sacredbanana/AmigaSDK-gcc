#ifndef PRAGMAS_MATHIEEEDOUBTRANS_PRAGMAS_H
#define PRAGMAS_MATHIEEEDOUBTRANS_PRAGMAS_H

/*
**	$VER: mathieeedoubtrans_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_MATHIEEEDOUBTRANS_PROTOS_H
#include <clib/mathieeedoubtrans_protos.h>
#endif /* CLIB_MATHIEEEDOUBTRANS_PROTOS_H */

/* "mathieeedoubtrans.library" */
#pragma libcall MathIeeeDoubTransBase IEEEDPAtan 1e 001
#pragma libcall MathIeeeDoubTransBase IEEEDPSin 24 001
#pragma libcall MathIeeeDoubTransBase IEEEDPCos 2a 001
#pragma libcall MathIeeeDoubTransBase IEEEDPTan 30 001
#pragma libcall MathIeeeDoubTransBase IEEEDPSincos 36 0802
#pragma libcall MathIeeeDoubTransBase IEEEDPSinh 3c 001
#pragma libcall MathIeeeDoubTransBase IEEEDPCosh 42 001
#pragma libcall MathIeeeDoubTransBase IEEEDPTanh 48 001
#pragma libcall MathIeeeDoubTransBase IEEEDPExp 4e 001
#pragma libcall MathIeeeDoubTransBase IEEEDPLog 54 001
#pragma libcall MathIeeeDoubTransBase IEEEDPPow 5a 0202
#pragma libcall MathIeeeDoubTransBase IEEEDPSqrt 60 001
#pragma libcall MathIeeeDoubTransBase IEEEDPTieee 66 001
#pragma libcall MathIeeeDoubTransBase IEEEDPFieee 6c 001
#pragma libcall MathIeeeDoubTransBase IEEEDPAsin 72 001
#pragma libcall MathIeeeDoubTransBase IEEEDPAcos 78 001
#pragma libcall MathIeeeDoubTransBase IEEEDPLog10 7e 001

#endif /* PRAGMAS_MATHIEEEDOUBTRANS_PRAGMAS_H */
