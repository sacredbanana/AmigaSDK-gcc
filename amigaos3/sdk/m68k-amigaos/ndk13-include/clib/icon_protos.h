#ifndef CLIB_ICON_PROTOS_H
#define CLIB_ICON_PROTOS_H

/*
**	$VER: icon_protos.h 47.1 (30.11.2021)
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
#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
#endif
VOID    __stdargs FreeFreeList( struct FreeList *freelist );
BOOL    __stdargs AddFreeList( struct FreeList *freelist, CONST_APTR mem, ULONG size );
struct DiskObject *   __stdargs GetDiskObject( CONST_STRPTR name );
BOOL    __stdargs PutDiskObject( CONST_STRPTR name, CONST struct DiskObject *diskobj );
VOID    __stdargs FreeDiskObject( struct DiskObject *diskobj );
UBYTE *   __stdargs FindToolType( CONST_STRPTR *toolTypeArray, CONST_STRPTR typeName );
BOOL    __stdargs MatchToolValue( CONST_STRPTR typeString, CONST_STRPTR value );
STRPTR    __stdargs BumpRevision( STRPTR newname, CONST_STRPTR oldname );
APTR    __stdargs FreeAlloc( struct FreeList *free, ULONG len, ULONG type );
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
