#ifndef PRAGMA_CONSOLE_LIB_H
#define PRAGMA_CONSOLE_LIB_H

/*
**	$VER: console_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_CONSOLE_PROTOS_H
#include <clib/console_protos.h>
#endif /* CLIB_CONSOLE_PROTOS_H */

/* "console.device" */
#pragma amicall(ConsoleDevice, 0x2a, CDInputHandler(a0,a1))
#pragma amicall(ConsoleDevice, 0x30, RawKeyConvert(a0,a1,d1,a2))
/*--- functions in V36 or higher (Release 2.0) ---*/

#endif /* PRAGMA_CONSOLE_LIB_H */
