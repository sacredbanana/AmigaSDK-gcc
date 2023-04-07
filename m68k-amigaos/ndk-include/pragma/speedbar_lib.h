#ifndef PRAGMA_SPEEDBAR_LIB_H
#define PRAGMA_SPEEDBAR_LIB_H

/*
**	$VER: speedbar_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_SPEEDBAR_PROTOS_H
#include <clib/speedbar_protos.h>
#endif /* CLIB_SPEEDBAR_PROTOS_H */

/* "speedbar.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(SpeedBarBase, 0x1e, SPEEDBAR_GetClass())
#pragma amicall(SpeedBarBase, 0x24, AllocSpeedButtonNodeA(d0,a0))
#if defined(__STORM__)
#pragma tagcall(SpeedBarBase, 0x24, AllocSpeedButtonNode(d0,a0))
#endif /* __STORM__ */
#pragma amicall(SpeedBarBase, 0x2a, FreeSpeedButtonNode(a0))
#pragma amicall(SpeedBarBase, 0x30, SetSpeedButtonNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(SpeedBarBase, 0x30, SetSpeedButtonNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(SpeedBarBase, 0x36, GetSpeedButtonNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(SpeedBarBase, 0x36, GetSpeedButtonNodeAttrs(a0,a1))
#endif /* __STORM__ */

#endif /* PRAGMA_SPEEDBAR_LIB_H */
