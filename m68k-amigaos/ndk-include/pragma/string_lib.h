#ifndef PRAGMA_STRING_LIB_H
#define PRAGMA_STRING_LIB_H

/*
**	$VER: string_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_STRING_PROTOS_H
#include <clib/string_protos.h>
#endif /* CLIB_STRING_PROTOS_H */

/* "string.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(StringBase, 0x1e, STRING_GetClass())

#endif /* PRAGMA_STRING_LIB_H */
