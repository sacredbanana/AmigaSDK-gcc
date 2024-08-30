#ifndef PRAGMAS_MATHFFP_PRAGMAS_H
#define PRAGMAS_MATHFFP_PRAGMAS_H

/*
**	$VER: mathffp_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_MATHFFP_PROTOS_H
#include <clib/mathffp_protos.h>
#endif /* CLIB_MATHFFP_PROTOS_H */

/* "mathffp.library" */
#pragma libcall MathBase SPFix 1e 001
#pragma libcall MathBase SPFlt 24 001
#pragma libcall MathBase SPCmp 2a 0102
#pragma libcall MathBase SPTst 30 101
#pragma libcall MathBase SPAbs 36 001
#pragma libcall MathBase SPNeg 3c 001
#pragma libcall MathBase SPAdd 42 0102
#pragma libcall MathBase SPSub 48 0102
#pragma libcall MathBase SPMul 4e 0102
#pragma libcall MathBase SPDiv 54 0102
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma libcall MathBase SPFloor 5a 001
#pragma libcall MathBase SPCeil 60 001

#endif /* PRAGMAS_MATHFFP_PRAGMAS_H */
