#ifndef PRAGMA_INTEGER_LIB_H
#define PRAGMA_INTEGER_LIB_H

/*
**	$VER: integer_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_INTEGER_PROTOS_H
#include <clib/integer_protos.h>
#endif /* CLIB_INTEGER_PROTOS_H */

/* "integer.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(IntegerBase, 0x1e, INTEGER_GetClass())

#endif /* PRAGMA_INTEGER_LIB_H */
