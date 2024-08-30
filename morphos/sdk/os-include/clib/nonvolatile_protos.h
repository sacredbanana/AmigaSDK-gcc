#ifndef CLIB_NONVOLATILE_PROTOS_H
#define CLIB_NONVOLATILE_PROTOS_H

/*
	nonvolatile.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef LIBRARIES_NONVOLATILE_H
# include <libraries/nonvolatile.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR GetCopyNV( CONST_STRPTR appName, CONST_STRPTR itemName, LONG killRequesters );
VOID FreeNVData( APTR data );
UWORD StoreNV( CONST_STRPTR appName, CONST_STRPTR itemName, CONST APTR data, ULONG length, LONG killRequesters );
BOOL DeleteNV( CONST_STRPTR appName, CONST_STRPTR itemName, LONG killRequesters );
struct NVInfo *GetNVInfo( LONG killRequesters );
struct MinList *GetNVList( CONST_STRPTR appName, LONG killRequesters );
BOOL SetNVProtection( CONST_STRPTR appName, CONST_STRPTR itemName, LONG mask, LONG killRequesters );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_NONVOLATILE_PROTOS_H */
