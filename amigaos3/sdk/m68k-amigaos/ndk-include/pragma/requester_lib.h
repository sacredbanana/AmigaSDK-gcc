#ifndef PRAGMA_REQUESTER_LIB_H
#define PRAGMA_REQUESTER_LIB_H

/*
**	$VER: requester_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_REQUESTER_PROTOS_H
#include <clib/requester_protos.h>
#endif /* CLIB_REQUESTER_PROTOS_H */

/* "requester.class" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(RequesterBase, 0x1e, REQUESTER_GetClass())

#endif /* PRAGMA_REQUESTER_LIB_H */
