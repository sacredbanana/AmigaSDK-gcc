#ifndef PRAGMA_LOWLEVEL_LIB_H
#define PRAGMA_LOWLEVEL_LIB_H

/*
**	$VER: lowlevel_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_LOWLEVEL_PROTOS_H
#include <clib/lowlevel_protos.h>
#endif /* CLIB_LOWLEVEL_PROTOS_H */

/* "lowlevel.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/

/* CONTROLLER HANDLING */

#pragma amicall(LowLevelBase, 0x1e, ReadJoyPort(d0))

/* LANGUAGE HANDLING */

#pragma amicall(LowLevelBase, 0x24, GetLanguageSelection())

/* KEYBOARD HANDLING */

#pragma amicall(LowLevelBase, 0x30, GetKey())
#pragma amicall(LowLevelBase, 0x36, QueryKeys(a0,d1))
#pragma amicall(LowLevelBase, 0x3c, AddKBInt(a0,a1))
#pragma amicall(LowLevelBase, 0x42, RemKBInt(a1))

/* SYSTEM HANDLING */

#pragma amicall(LowLevelBase, 0x48, SystemControlA(a1))
#if defined(__STORM__)
#pragma tagcall(LowLevelBase, 0x48, SystemControl(a1))
#endif /* __STORM__ */

/* TIMER HANDLING */

#pragma amicall(LowLevelBase, 0x4e, AddTimerInt(a0,a1))
#pragma amicall(LowLevelBase, 0x54, RemTimerInt(a1))
#pragma amicall(LowLevelBase, 0x5a, StopTimerInt(a1))
#pragma amicall(LowLevelBase, 0x60, StartTimerInt(a1,d0,d1))
#pragma amicall(LowLevelBase, 0x66, ElapsedTime(a0))

/* VBLANK HANDLING */

#pragma amicall(LowLevelBase, 0x6c, AddVBlankInt(a0,a1))
#pragma amicall(LowLevelBase, 0x72, RemVBlankInt(a1))

/* Private LVOs for use by nonvolatile.library */


/* MORE CONTROLLER HANDLING */

#pragma amicall(LowLevelBase, 0x84, SetJoyPortAttrsA(d0,a1))
#if defined(__STORM__)
#pragma tagcall(LowLevelBase, 0x84, SetJoyPortAttrs(d0,a1))
#endif /* __STORM__ */

/* Reserved entries */


#endif /* PRAGMA_LOWLEVEL_LIB_H */
