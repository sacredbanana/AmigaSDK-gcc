#ifndef PRAGMAS_SLIDER_PRAGMAS_H
#define PRAGMAS_SLIDER_PRAGMAS_H

/*
**	$VER: slider_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_SLIDER_PROTOS_H
#include <clib/slider_protos.h>
#endif /* CLIB_SLIDER_PROTOS_H */

/* "slider.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall SliderBase SLIDER_GetClass 1e 00

#endif /* PRAGMAS_SLIDER_PRAGMAS_H */
