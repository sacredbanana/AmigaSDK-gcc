#ifndef PRAGMAS_FUELGAUGE_PRAGMAS_H
#define PRAGMAS_FUELGAUGE_PRAGMAS_H

/*
**	$VER: fuelgauge_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_FUELGAUGE_PROTOS_H
#include <clib/fuelgauge_protos.h>
#endif /* CLIB_FUELGAUGE_PROTOS_H */

/* "fuelgauge.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall FuelGaugeBase FUELGAUGE_GetClass 1e 00

#endif /* PRAGMAS_FUELGAUGE_PRAGMAS_H */
