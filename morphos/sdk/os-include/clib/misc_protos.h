#ifndef CLIB_MISC_PROTOS_H
#define CLIB_MISC_PROTOS_H

/*
	misc.resource C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

UBYTE *AllocMiscResource( ULONG unitNum, CONST_STRPTR name );
VOID FreeMiscResource( ULONG unitNum );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_MISC_PROTOS_H */
