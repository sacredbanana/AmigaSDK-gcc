#ifndef PRAGMA_CARDRES_LIB_H
#define PRAGMA_CARDRES_LIB_H

/*
**	$VER: cardres_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_CARDRES_PROTOS_H
#include <clib/cardres_protos.h>
#endif /* CLIB_CARDRES_PROTOS_H */

/* "card.resource" */
#pragma amicall(CardResource, 0x6, OwnCard(a1))
#pragma amicall(CardResource, 0xc, ReleaseCard(a1,d0))
#pragma amicall(CardResource, 0x12, GetCardMap())
#pragma amicall(CardResource, 0x18, BeginCardAccess(a1))
#pragma amicall(CardResource, 0x1e, EndCardAccess(a1))
#pragma amicall(CardResource, 0x24, ReadCardStatus())
#pragma amicall(CardResource, 0x2a, CardResetRemove(a1,d0))
#pragma amicall(CardResource, 0x30, CardMiscControl(a1,d1))
#pragma amicall(CardResource, 0x36, CardAccessSpeed(a1,d0))
#pragma amicall(CardResource, 0x3c, CardProgramVoltage(a1,d0))
#pragma amicall(CardResource, 0x42, CardResetCard(a1))
#pragma amicall(CardResource, 0x48, CopyTuple(a1,a0,d1,d0))
#pragma amicall(CardResource, 0x4e, DeviceTuple(a0,a1))
#pragma amicall(CardResource, 0x54, IfAmigaXIP(a2))
#pragma amicall(CardResource, 0x5a, CardForceChange())
#pragma amicall(CardResource, 0x60, CardChangeCount())
#pragma amicall(CardResource, 0x66, CardInterface())

#endif /* PRAGMA_CARDRES_LIB_H */
