#ifndef PRAGMAS_CHECKBOX_PRAGMAS_H
#define PRAGMAS_CHECKBOX_PRAGMAS_H

/*
**	$VER: checkbox_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_CHECKBOX_PROTOS_H
#include <clib/checkbox_protos.h>
#endif /* CLIB_CHECKBOX_PROTOS_H */

/* "checkbox.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall CheckBoxBase CHECKBOX_GetClass 1e 00

#endif /* PRAGMAS_CHECKBOX_PRAGMAS_H */
