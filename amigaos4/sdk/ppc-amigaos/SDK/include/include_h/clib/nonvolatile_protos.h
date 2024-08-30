#ifndef CLIB_NONVOLATILE_PROTOS_H
#define CLIB_NONVOLATILE_PROTOS_H

/*
**    $Id: nonvolatile_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
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
#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   LIBRARIES_NONVOLATILE_H
#include <libraries/nonvolatile.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

/*--- functions in V40 or higher (Release 3.1) ---*/
APTR GetCopyNV( CONST_STRPTR appName, CONST_STRPTR itemName, LONG killRequesters );
VOID FreeNVData( APTR data );
UWORD StoreNV( CONST_STRPTR appName, CONST_STRPTR itemName, CONST APTR data, ULONG length, LONG killRequesters );
BOOL DeleteNV( CONST_STRPTR appName, CONST_STRPTR itemName, LONG killRequesters );
struct NVInfo *GetNVInfo( LONG killRequesters );
struct MinList *GetNVList( CONST_STRPTR appName, LONG killRequesters );
BOOL SetNVProtection( CONST_STRPTR appName, CONST_STRPTR itemName, LONG mask, LONG killRequesters );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_NONVOLATILE_PROTOS_H */
