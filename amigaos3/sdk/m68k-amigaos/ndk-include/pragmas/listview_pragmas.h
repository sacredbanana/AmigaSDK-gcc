#ifndef PRAGMAS_LISTVIEW_PRAGMAS_H
#define PRAGMAS_LISTVIEW_PRAGMAS_H

/*
**	$VER: listview_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_LISTVIEW_PROTOS_H
#include <clib/listview_protos.h>
#endif /* CLIB_LISTVIEW_PROTOS_H */

/* "listview.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall ListViewBase LISTVIEW_GetClass 1e 00

#endif /* PRAGMAS_LISTVIEW_PRAGMAS_H */
