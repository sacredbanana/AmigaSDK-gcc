#ifndef PRAGMAS_MATHIEEESINGTRANS_PRAGMAS_H
#define PRAGMAS_MATHIEEESINGTRANS_PRAGMAS_H

/*
**	$VER: mathieeesingtrans_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_MATHIEEESINGTRANS_PROTOS_H
#include <clib/mathieeesingtrans_protos.h>
#endif /* CLIB_MATHIEEESINGTRANS_PROTOS_H */

/* "mathieeesingtrans.library" */
#pragma libcall MathIeeeSingTransBase IEEESPAtan 1e 001
#pragma libcall MathIeeeSingTransBase IEEESPSin 24 001
#pragma libcall MathIeeeSingTransBase IEEESPCos 2a 001
#pragma libcall MathIeeeSingTransBase IEEESPTan 30 001
#pragma libcall MathIeeeSingTransBase IEEESPSincos 36 0802
#pragma libcall MathIeeeSingTransBase IEEESPSinh 3c 001
#pragma libcall MathIeeeSingTransBase IEEESPCosh 42 001
#pragma libcall MathIeeeSingTransBase IEEESPTanh 48 001
#pragma libcall MathIeeeSingTransBase IEEESPExp 4e 001
#pragma libcall MathIeeeSingTransBase IEEESPLog 54 001
#pragma libcall MathIeeeSingTransBase IEEESPPow 5a 0102
#pragma libcall MathIeeeSingTransBase IEEESPSqrt 60 001
#pragma libcall MathIeeeSingTransBase IEEESPTieee 66 001
#pragma libcall MathIeeeSingTransBase IEEESPFieee 6c 001
#pragma libcall MathIeeeSingTransBase IEEESPAsin 72 001
#pragma libcall MathIeeeSingTransBase IEEESPAcos 78 001
#pragma libcall MathIeeeSingTransBase IEEESPLog10 7e 001

#endif /* PRAGMAS_MATHIEEESINGTRANS_PRAGMAS_H */
