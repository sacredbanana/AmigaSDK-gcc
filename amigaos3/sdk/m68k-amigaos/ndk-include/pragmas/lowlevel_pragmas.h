#ifndef PRAGMAS_LOWLEVEL_PRAGMAS_H
#define PRAGMAS_LOWLEVEL_PRAGMAS_H

/*
**	$VER: lowlevel_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_LOWLEVEL_PROTOS_H
#include <clib/lowlevel_protos.h>
#endif /* CLIB_LOWLEVEL_PROTOS_H */

/* "lowlevel.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/

/* CONTROLLER HANDLING */

#pragma libcall LowLevelBase ReadJoyPort 1e 001

/* LANGUAGE HANDLING */

#pragma libcall LowLevelBase GetLanguageSelection 24 00

/* KEYBOARD HANDLING */

#pragma libcall LowLevelBase GetKey 30 00
#pragma libcall LowLevelBase QueryKeys 36 1802
#pragma libcall LowLevelBase AddKBInt 3c 9802
#pragma libcall LowLevelBase RemKBInt 42 901

/* SYSTEM HANDLING */

#pragma libcall LowLevelBase SystemControlA 48 901
#if defined(__SASC_60)
#pragma tagcall LowLevelBase SystemControl 48 901
#endif /* __SASC_60 */

/* TIMER HANDLING */

#pragma libcall LowLevelBase AddTimerInt 4e 9802
#pragma libcall LowLevelBase RemTimerInt 54 901
#pragma libcall LowLevelBase StopTimerInt 5a 901
#pragma libcall LowLevelBase StartTimerInt 60 10903
#pragma libcall LowLevelBase ElapsedTime 66 801

/* VBLANK HANDLING */

#pragma libcall LowLevelBase AddVBlankInt 6c 9802
#pragma libcall LowLevelBase RemVBlankInt 72 901

/* Private LVOs for use by nonvolatile.library */


/* MORE CONTROLLER HANDLING */

#pragma libcall LowLevelBase SetJoyPortAttrsA 84 9002
#if defined(__SASC_60)
#pragma tagcall LowLevelBase SetJoyPortAttrs 84 9002
#endif /* __SASC_60 */

/* Reserved entries */


#endif /* PRAGMAS_LOWLEVEL_PRAGMAS_H */
