#ifndef CLIB_BATTMEM_PROTOS_H
#define CLIB_BATTMEM_PROTOS_H

/*
	battmem.resource C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID ObtainBattSemaphore( VOID );
VOID ReleaseBattSemaphore( VOID );
ULONG ReadBattMem( APTR buffer, ULONG offset, ULONG length );
ULONG WriteBattMem( CONST APTR buffer, ULONG offset, ULONG length );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_BATTMEM_PROTOS_H */
