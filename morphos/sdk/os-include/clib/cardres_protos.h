#ifndef CLIB_CARDRES_PROTOS_H
#define CLIB_CARDRES_PROTOS_H

/*
	card.resource C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_RESIDENT_H
# include <exec/resident.h>
#endif

#ifndef RESOURCES_CARD_H
# include <resources/card.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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
#endif /* __cplusplus */


#endif /* CLIB_CARDRES_PROTOS_H */
