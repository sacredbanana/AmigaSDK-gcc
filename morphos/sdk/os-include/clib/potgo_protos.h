#ifndef CLIB_POTGO_PROTOS_H
#define CLIB_POTGO_PROTOS_H

/*
	potgo.resource C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

UWORD AllocPotBits( ULONG bits );
VOID FreePotBits( ULONG bits );
VOID WritePotgo( ULONG word, ULONG mask );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_POTGO_PROTOS_H */
