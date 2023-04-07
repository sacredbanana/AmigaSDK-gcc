#ifndef PRAGMAS_MATHTRANS_PRAGMAS_H
#define PRAGMAS_MATHTRANS_PRAGMAS_H

/*
**	$VER: mathtrans_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_MATHTRANS_PROTOS_H
#include <clib/mathtrans_protos.h>
#endif /* CLIB_MATHTRANS_PROTOS_H */

/* "mathtrans.library" */
#pragma libcall MathTransBase SPAtan 1e 001
#pragma libcall MathTransBase SPSin 24 001
#pragma libcall MathTransBase SPCos 2a 001
#pragma libcall MathTransBase SPTan 30 001
#pragma libcall MathTransBase SPSincos 36 0102
#pragma libcall MathTransBase SPSinh 3c 001
#pragma libcall MathTransBase SPCosh 42 001
#pragma libcall MathTransBase SPTanh 48 001
#pragma libcall MathTransBase SPExp 4e 001
#pragma libcall MathTransBase SPLog 54 001
#pragma libcall MathTransBase SPPow 5a 0102
#pragma libcall MathTransBase SPSqrt 60 001
#pragma libcall MathTransBase SPTieee 66 001
#pragma libcall MathTransBase SPFieee 6c 001
/*--- functions in V31 or higher (Release 1.1) ---*/
#pragma libcall MathTransBase SPAsin 72 001
#pragma libcall MathTransBase SPAcos 78 001
#pragma libcall MathTransBase SPLog10 7e 001

#endif /* PRAGMAS_MATHTRANS_PRAGMAS_H */
