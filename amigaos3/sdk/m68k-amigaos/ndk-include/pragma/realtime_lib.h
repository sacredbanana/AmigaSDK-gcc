#ifndef PRAGMA_REALTIME_LIB_H
#define PRAGMA_REALTIME_LIB_H

/*
**	$VER: realtime_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_REALTIME_PROTOS_H
#include <clib/realtime_protos.h>
#endif /* CLIB_REALTIME_PROTOS_H */

/* "realtime.library" */
/*--- functions in V37 or higher (Release 2.04) ---*/

/* Locks */

#pragma amicall(RealTimeBase, 0x1e, LockRealTime(d0))
#pragma amicall(RealTimeBase, 0x24, UnlockRealTime(a0))

/* Conductor */

#pragma amicall(RealTimeBase, 0x2a, CreatePlayerA(a0))
#if defined(__STORM__)
#pragma tagcall(RealTimeBase, 0x2a, CreatePlayer(a0))
#endif /* __STORM__ */
#pragma amicall(RealTimeBase, 0x30, DeletePlayer(a0))
#pragma amicall(RealTimeBase, 0x36, SetPlayerAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(RealTimeBase, 0x36, SetPlayerAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(RealTimeBase, 0x3c, SetConductorState(a0,d0,d1))
#pragma amicall(RealTimeBase, 0x42, ExternalSync(a0,d0,d1))
#pragma amicall(RealTimeBase, 0x48, NextConductor(a0))
#pragma amicall(RealTimeBase, 0x4e, FindConductor(a0))
#pragma amicall(RealTimeBase, 0x54, GetPlayerAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(RealTimeBase, 0x54, GetPlayerAttrs(a0,a1))
#endif /* __STORM__ */

#endif /* PRAGMA_REALTIME_LIB_H */
