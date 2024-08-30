#ifndef PRAGMAS_AMIGAGUIDE_PRAGMAS_H
#define PRAGMAS_AMIGAGUIDE_PRAGMAS_H

/*
**	$VER: amigaguide_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_AMIGAGUIDE_PROTOS_H
#include <clib/amigaguide_protos.h>
#endif /* CLIB_AMIGAGUIDE_PROTOS_H */

/* "amigaguide.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/
/* ARexx function host entry point */

/* Public entries */

#pragma libcall AmigaGuideBase LockAmigaGuideBase 24 801
#pragma libcall AmigaGuideBase UnlockAmigaGuideBase 2a 001
#pragma libcall AmigaGuideBase OpenAmigaGuideA 36 9802
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase OpenAmigaGuide 36 9802
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase OpenAmigaGuideAsyncA 3c 0802
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase OpenAmigaGuideAsync 3c 0802
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase CloseAmigaGuide 42 801
#pragma libcall AmigaGuideBase AmigaGuideSignal 48 801
#pragma libcall AmigaGuideBase GetAmigaGuideMsg 4e 801
#pragma libcall AmigaGuideBase ReplyAmigaGuideMsg 54 801
#pragma libcall AmigaGuideBase SetAmigaGuideContextA 5a 10803
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase SetAmigaGuideContext 5a 10803
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase SendAmigaGuideContextA 60 0802
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase SendAmigaGuideContext 60 0802
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase SendAmigaGuideCmdA 66 10803
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase SendAmigaGuideCmd 66 10803
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase SetAmigaGuideAttrsA 6c 9802
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase SetAmigaGuideAttrs 6c 9802
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase GetAmigaGuideAttr 72 98003
#pragma libcall AmigaGuideBase LoadXRef 7e 9802
#pragma libcall AmigaGuideBase ExpungeXRef 84 00
#pragma libcall AmigaGuideBase AddAmigaGuideHostA 8a 90803
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase AddAmigaGuideHost 8a 90803
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase RemoveAmigaGuideHostA 90 9802
#if defined(__SASC_60)
#pragma tagcall AmigaGuideBase RemoveAmigaGuideHost 90 9802
#endif /* __SASC_60 */
#pragma libcall AmigaGuideBase GetAmigaGuideString d2 001

#endif /* PRAGMAS_AMIGAGUIDE_PRAGMAS_H */
