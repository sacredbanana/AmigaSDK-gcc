#ifndef PRAGMAS_REALTIME_PRAGMAS_H
#define PRAGMAS_REALTIME_PRAGMAS_H

/*
**	$VER: realtime_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_REALTIME_PROTOS_H
#include <clib/realtime_protos.h>
#endif /* CLIB_REALTIME_PROTOS_H */

/* "realtime.library" */
/*--- functions in V37 or higher (Release 2.04) ---*/

/* Locks */

#pragma libcall RealTimeBase LockRealTime 1e 001
#pragma libcall RealTimeBase UnlockRealTime 24 801

/* Conductor */

#pragma libcall RealTimeBase CreatePlayerA 2a 801
#if defined(__SASC_60)
#pragma tagcall RealTimeBase CreatePlayer 2a 801
#endif /* __SASC_60 */
#pragma libcall RealTimeBase DeletePlayer 30 801
#pragma libcall RealTimeBase SetPlayerAttrsA 36 9802
#if defined(__SASC_60)
#pragma tagcall RealTimeBase SetPlayerAttrs 36 9802
#endif /* __SASC_60 */
#pragma libcall RealTimeBase SetConductorState 3c 10803
#pragma libcall RealTimeBase ExternalSync 42 10803
#pragma libcall RealTimeBase NextConductor 48 801
#pragma libcall RealTimeBase FindConductor 4e 801
#pragma libcall RealTimeBase GetPlayerAttrsA 54 9802
#if defined(__SASC_60)
#pragma tagcall RealTimeBase GetPlayerAttrs 54 9802
#endif /* __SASC_60 */

#endif /* PRAGMAS_REALTIME_PRAGMAS_H */
