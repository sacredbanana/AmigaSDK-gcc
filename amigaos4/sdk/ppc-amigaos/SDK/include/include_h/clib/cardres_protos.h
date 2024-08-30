#ifndef CLIB_CARDRES_PROTOS_H
#define CLIB_CARDRES_PROTOS_H

/*
**    $Id: cardres_protos.h,v 1.8 2010-01-31 01:28:59 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   EXEC_RESIDENT_H
#include <exec/resident.h>
#endif
#ifndef   RESOURCES_CARD_H
#include <resources/card.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

struct CardHandle *OwnCard( struct CardHandle *handle );
VOID ReleaseCard( struct CardHandle *handle, ULONG flags );
struct CardMemoryMap *GetCardMap( VOID );
BOOL BeginCardAccess( struct CardHandle *handle );
BOOL EndCardAccess( struct CardHandle *handle );
UBYTE ReadCardStatus( VOID );
BOOL CardResetRemove( struct CardHandle *handle, ULONG flag );
UBYTE CardMiscControl( struct CardHandle *handle, ULONG control_bits );
ULONG CardAccessSpeed( struct CardHandle *handle, ULONG nanoseconds );
LONG CardProgramVoltage( struct CardHandle *handle, ULONG voltage );
BOOL CardResetCard( struct CardHandle *handle );
BOOL CopyTuple( CONST struct CardHandle *handle, UBYTE *buffer, ULONG tuplecode, ULONG size );
ULONG DeviceTuple( CONST UBYTE *tuple_data, struct DeviceTData *storage );
struct Resident *IfAmigaXIP( CONST struct CardHandle *handle );
BOOL CardForceChange( VOID );
ULONG CardChangeCount( VOID );
ULONG CardInterface( VOID );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CARDRES_PROTOS_H */
