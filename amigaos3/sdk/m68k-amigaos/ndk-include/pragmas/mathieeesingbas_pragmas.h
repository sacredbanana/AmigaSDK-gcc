#ifndef PRAGMAS_MATHIEEESINGBAS_PRAGMAS_H
#define PRAGMAS_MATHIEEESINGBAS_PRAGMAS_H

/*
**	$VER: mathieeesingbas_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_MATHIEEESINGBAS_PROTOS_H
#include <clib/mathieeesingbas_protos.h>
#endif /* CLIB_MATHIEEESINGBAS_PROTOS_H */

/* "mathieeesingbas.library" */
#pragma libcall MathIeeeSingBasBase IEEESPFix 1e 001
#pragma libcall MathIeeeSingBasBase IEEESPFlt 24 001
#pragma libcall MathIeeeSingBasBase IEEESPCmp 2a 1002
#pragma libcall MathIeeeSingBasBase IEEESPTst 30 001
#pragma libcall MathIeeeSingBasBase IEEESPAbs 36 001
#pragma libcall MathIeeeSingBasBase IEEESPNeg 3c 001
#pragma libcall MathIeeeSingBasBase IEEESPAdd 42 1002
#pragma libcall MathIeeeSingBasBase IEEESPSub 48 1002
#pragma libcall MathIeeeSingBasBase IEEESPMul 4e 1002
#pragma libcall MathIeeeSingBasBase IEEESPDiv 54 1002
#pragma libcall MathIeeeSingBasBase IEEESPFloor 5a 001
#pragma libcall MathIeeeSingBasBase IEEESPCeil 60 001

#endif /* PRAGMAS_MATHIEEESINGBAS_PRAGMAS_H */
