#ifndef CLIB_BATTCLOCK_PROTOS_H
#define CLIB_BATTCLOCK_PROTOS_H

/*
	battclock.resource C prototypes

	Copyright © 2018 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID ResetBattClock( VOID );
ULONG ReadBattClock( VOID );
VOID WriteBattClock( ULONG time );
ULONG ReadUTCBattClock( VOID );
VOID WriteUTCBattClock( ULONG time );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_BATTCLOCK_PROTOS_H */
