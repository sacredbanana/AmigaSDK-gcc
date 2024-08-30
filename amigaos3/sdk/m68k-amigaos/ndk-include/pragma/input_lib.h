#ifndef PRAGMA_INPUT_LIB_H
#define PRAGMA_INPUT_LIB_H

/*
**	$VER: input_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_INPUT_PROTOS_H
#include <clib/input_protos.h>
#endif /* CLIB_INPUT_PROTOS_H */

/* "input.device" */
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(InputBase, 0x2a, PeekQualifier())

#endif /* PRAGMA_INPUT_LIB_H */
