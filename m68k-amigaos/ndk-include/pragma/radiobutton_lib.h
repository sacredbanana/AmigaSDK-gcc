#ifndef PRAGMA_RADIOBUTTON_LIB_H
#define PRAGMA_RADIOBUTTON_LIB_H

/*
**	$VER: radiobutton_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_RADIOBUTTON_PROTOS_H
#include <clib/radiobutton_protos.h>
#endif /* CLIB_RADIOBUTTON_PROTOS_H */

/* "radiobutton.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(RadioButtonBase, 0x1e, RADIOBUTTON_GetClass())
#pragma amicall(RadioButtonBase, 0x24, AllocRadioButtonNodeA(d0,a0))
#if defined(__STORM__)
#pragma tagcall(RadioButtonBase, 0x24, AllocRadioButtonNode(d0,a0))
#endif /* __STORM__ */
#pragma amicall(RadioButtonBase, 0x2a, FreeRadioButtonNode(a0))
#pragma amicall(RadioButtonBase, 0x30, SetRadioButtonNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(RadioButtonBase, 0x30, SetRadioButtonNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(RadioButtonBase, 0x36, GetRadioButtonNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(RadioButtonBase, 0x36, GetRadioButtonNodeAttrs(a0,a1))
#endif /* __STORM__ */

#endif /* PRAGMA_RADIOBUTTON_LIB_H */
