#ifndef PRAGMAS_CARDRES_PRAGMAS_H
#define PRAGMAS_CARDRES_PRAGMAS_H

/*
**	$VER: cardres_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_CARDRES_PROTOS_H
#include <clib/cardres_protos.h>
#endif /* CLIB_CARDRES_PROTOS_H */

/* "card.resource" */
#pragma libcall CardResource OwnCard 6 901
#pragma libcall CardResource ReleaseCard c 0902
#pragma libcall CardResource GetCardMap 12 00
#pragma libcall CardResource BeginCardAccess 18 901
#pragma libcall CardResource EndCardAccess 1e 901
#pragma libcall CardResource ReadCardStatus 24 00
#pragma libcall CardResource CardResetRemove 2a 0902
#pragma libcall CardResource CardMiscControl 30 1902
#pragma libcall CardResource CardAccessSpeed 36 0902
#pragma libcall CardResource CardProgramVoltage 3c 0902
#pragma libcall CardResource CardResetCard 42 901
#pragma libcall CardResource CopyTuple 48 018904
#pragma libcall CardResource DeviceTuple 4e 9802
#pragma libcall CardResource IfAmigaXIP 54 A01
#pragma libcall CardResource CardForceChange 5a 00
#pragma libcall CardResource CardChangeCount 60 00
#pragma libcall CardResource CardInterface 66 00

#endif /* PRAGMAS_CARDRES_PRAGMAS_H */
