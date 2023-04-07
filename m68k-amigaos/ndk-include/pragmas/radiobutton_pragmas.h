#ifndef PRAGMAS_RADIOBUTTON_PRAGMAS_H
#define PRAGMAS_RADIOBUTTON_PRAGMAS_H

/*
**	$VER: radiobutton_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_RADIOBUTTON_PROTOS_H
#include <clib/radiobutton_protos.h>
#endif /* CLIB_RADIOBUTTON_PROTOS_H */

/* "radiobutton.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall RadioButtonBase RADIOBUTTON_GetClass 1e 00
#pragma libcall RadioButtonBase AllocRadioButtonNodeA 24 8002
#if defined(__SASC_60)
#pragma tagcall RadioButtonBase AllocRadioButtonNode 24 8002
#endif /* __SASC_60 */
#pragma libcall RadioButtonBase FreeRadioButtonNode 2a 801
#pragma libcall RadioButtonBase SetRadioButtonNodeAttrsA 30 9802
#if defined(__SASC_60)
#pragma tagcall RadioButtonBase SetRadioButtonNodeAttrs 30 9802
#endif /* __SASC_60 */
#pragma libcall RadioButtonBase GetRadioButtonNodeAttrsA 36 9802
#if defined(__SASC_60)
#pragma tagcall RadioButtonBase GetRadioButtonNodeAttrs 36 9802
#endif /* __SASC_60 */

#endif /* PRAGMAS_RADIOBUTTON_PRAGMAS_H */
