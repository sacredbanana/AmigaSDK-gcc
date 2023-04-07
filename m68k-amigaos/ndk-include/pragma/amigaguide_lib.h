#ifndef PRAGMA_AMIGAGUIDE_LIB_H
#define PRAGMA_AMIGAGUIDE_LIB_H

/*
**	$VER: amigaguide_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_AMIGAGUIDE_PROTOS_H
#include <clib/amigaguide_protos.h>
#endif /* CLIB_AMIGAGUIDE_PROTOS_H */

/* "amigaguide.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/
/* ARexx function host entry point */

/* Public entries */

#pragma amicall(AmigaGuideBase, 0x24, LockAmigaGuideBase(a0))
#pragma amicall(AmigaGuideBase, 0x2a, UnlockAmigaGuideBase(d0))
#pragma amicall(AmigaGuideBase, 0x36, OpenAmigaGuideA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x36, OpenAmigaGuide(a0,a1))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x3c, OpenAmigaGuideAsyncA(a0,d0))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x3c, OpenAmigaGuideAsync(a0,d0))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x42, CloseAmigaGuide(a0))
#pragma amicall(AmigaGuideBase, 0x48, AmigaGuideSignal(a0))
#pragma amicall(AmigaGuideBase, 0x4e, GetAmigaGuideMsg(a0))
#pragma amicall(AmigaGuideBase, 0x54, ReplyAmigaGuideMsg(a0))
#pragma amicall(AmigaGuideBase, 0x5a, SetAmigaGuideContextA(a0,d0,d1))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x5a, SetAmigaGuideContext(a0,d0,d1))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x60, SendAmigaGuideContextA(a0,d0))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x60, SendAmigaGuideContext(a0,d0))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x66, SendAmigaGuideCmdA(a0,d0,d1))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x66, SendAmigaGuideCmd(a0,d0,d1))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x6c, SetAmigaGuideAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x6c, SetAmigaGuideAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x72, GetAmigaGuideAttr(d0,a0,a1))
#pragma amicall(AmigaGuideBase, 0x7e, LoadXRef(a0,a1))
#pragma amicall(AmigaGuideBase, 0x84, ExpungeXRef())
#pragma amicall(AmigaGuideBase, 0x8a, AddAmigaGuideHostA(a0,d0,a1))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x8a, AddAmigaGuideHost(a0,d0,a1))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0x90, RemoveAmigaGuideHostA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(AmigaGuideBase, 0x90, RemoveAmigaGuideHost(a0,a1))
#endif /* __STORM__ */
#pragma amicall(AmigaGuideBase, 0xd2, GetAmigaGuideString(d0))

#endif /* PRAGMA_AMIGAGUIDE_LIB_H */
