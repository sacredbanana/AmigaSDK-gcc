#ifndef PRAGMAS_INPUT_PRAGMAS_H
#define PRAGMAS_INPUT_PRAGMAS_H

/*
**	$VER: input_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_INPUT_PROTOS_H
#include <clib/input_protos.h>
#endif /* CLIB_INPUT_PROTOS_H */

/* "input.device" */
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall InputBase PeekQualifier 2a 00

#endif /* PRAGMAS_INPUT_PRAGMAS_H */
