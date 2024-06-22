#ifndef CLIB_NONVOLATILE_PROTOS_H
#define CLIB_NONVOLATILE_PROTOS_H

/*
**	$VER: nonvolatile_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  LIBRARIES_NONVOLATILE_H
#include <libraries/nonvolatile.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
APTR  __stdargs GetCopyNV( CONST_STRPTR appName, CONST_STRPTR itemName, LONG killRequesters );
VOID  __stdargs FreeNVData( APTR data );
UWORD  __stdargs StoreNV( CONST_STRPTR appName, CONST_STRPTR itemName, CONST_APTR data, ULONG length, LONG killRequesters );
BOOL  __stdargs DeleteNV( CONST_STRPTR appName, CONST_STRPTR itemName, LONG killRequesters );
struct NVInfo * __stdargs GetNVInfo( LONG killRequesters );
struct MinList * __stdargs GetNVList( CONST_STRPTR appName, LONG killRequesters );
BOOL  __stdargs SetNVProtection( CONST_STRPTR appName, CONST_STRPTR itemName, LONG mask, LONG killRequesters );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_NONVOLATILE_PROTOS_H */
