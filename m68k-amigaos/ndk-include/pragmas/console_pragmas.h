#ifndef PRAGMAS_CONSOLE_PRAGMAS_H
#define PRAGMAS_CONSOLE_PRAGMAS_H

/*
**	$VER: console_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_CONSOLE_PROTOS_H
#include <clib/console_protos.h>
#endif /* CLIB_CONSOLE_PROTOS_H */

/* "console.device" */
#pragma libcall ConsoleDevice CDInputHandler 2a 9802
#pragma libcall ConsoleDevice RawKeyConvert 30 A19804
/*--- functions in V36 or higher (Release 2.0) ---*/

#endif /* PRAGMAS_CONSOLE_PRAGMAS_H */
