#ifndef PRAGMAS_NONVOLATILE_PRAGMAS_H
#define PRAGMAS_NONVOLATILE_PRAGMAS_H

/*
**	$VER: nonvolatile_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_NONVOLATILE_PROTOS_H
#include <clib/nonvolatile_protos.h>
#endif /* CLIB_NONVOLATILE_PROTOS_H */

/* "nonvolatile.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall NVBase GetCopyNV 1e 19803
#pragma libcall NVBase FreeNVData 24 801
#pragma libcall NVBase StoreNV 2a 10A9805
#pragma libcall NVBase DeleteNV 30 19803
#pragma libcall NVBase GetNVInfo 36 101
#pragma libcall NVBase GetNVList 3c 1802
#pragma libcall NVBase SetNVProtection 42 129804

#endif /* PRAGMAS_NONVOLATILE_PRAGMAS_H */
