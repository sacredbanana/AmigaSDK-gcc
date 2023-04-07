#ifndef PRAGMA_GETFILE_LIB_H
#define PRAGMA_GETFILE_LIB_H

/*
**	$VER: getfile_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_GETFILE_PROTOS_H
#include <clib/getfile_protos.h>
#endif /* CLIB_GETFILE_PROTOS_H */

/* "getfile.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(GetFileBase, 0x1e, GETFILE_GetClass())

#endif /* PRAGMA_GETFILE_LIB_H */
