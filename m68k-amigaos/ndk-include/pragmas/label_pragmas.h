#ifndef PRAGMAS_LABEL_PRAGMAS_H
#define PRAGMAS_LABEL_PRAGMAS_H

/*
**	$VER: label_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_LABEL_PROTOS_H
#include <clib/label_protos.h>
#endif /* CLIB_LABEL_PROTOS_H */

/* "label.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall LabelBase LABEL_GetClass 1e 00

#endif /* PRAGMAS_LABEL_PRAGMAS_H */
