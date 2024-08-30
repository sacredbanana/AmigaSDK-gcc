#ifndef CLIB_DOS_PROTOS_H
#define CLIB_DOS_PROTOS_H

/*
**	$VER: dos_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef  DOS_RECORD_H
#include <dos/record.h>
#endif
#ifndef  DOS_RDARGS_H
#include <dos/rdargs.h>
#endif
#ifndef  DOS_DOSASL_H
#include <dos/dosasl.h>
#endif
#ifndef  DOS_VAR_H
#include <dos/var.h>
#endif
#ifndef  DOS_NOTIFY_H
#include <dos/notify.h>
#endif
#ifndef  DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef  DOS_EXALL_H
#include <dos/exall.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
BPTR    __stdargs Open( CONST_STRPTR name, LONG accessMode );
LONG    __stdargs Close( BPTR file );
LONG    __stdargs Read( BPTR file, APTR buffer, LONG length );
LONG    __stdargs Write( BPTR file, CONST_APTR buffer, LONG length );
BPTR    __stdargs Input( VOID );
BPTR    __stdargs Output( VOID );
LONG    __stdargs Seek( BPTR file, LONG position, LONG offset );
LONG    __stdargs DeleteFile( CONST_STRPTR name );
LONG    __stdargs Rename( CONST_STRPTR oldName, CONST_STRPTR newName );
BPTR    __stdargs Lock( CONST_STRPTR name, LONG type );
VOID    __stdargs UnLock( BPTR lock );
BPTR    __stdargs DupLock( BPTR lock );
LONG    __stdargs Examine( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG    __stdargs ExNext( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG    __stdargs Info( BPTR lock, struct InfoData *parameterBlock );
BPTR    __stdargs CreateDir( CONST_STRPTR name );
BPTR    __stdargs CurrentDir( BPTR lock );
LONG    __stdargs IoErr( VOID );
struct MsgPort *   __stdargs CreateProc( CONST_STRPTR name, LONG pri, BPTR segList, LONG stackSize );
VOID    __stdargs Exit( LONG returnCode );
BPTR    __stdargs LoadSeg( CONST_STRPTR name );
VOID    __stdargs UnLoadSeg( BPTR seglist );
struct MsgPort *   __stdargs DeviceProc( CONST_STRPTR name );
LONG    __stdargs SetComment( CONST_STRPTR name, CONST_STRPTR comment );
LONG    __stdargs SetProtection( CONST_STRPTR name, LONG protect );
struct DateStamp *   __stdargs DateStamp( struct DateStamp *date );
VOID    __stdargs Delay( LONG timeout );
LONG    __stdargs WaitForChar( BPTR file, LONG timeout );
BPTR    __stdargs ParentDir( BPTR lock );
LONG    __stdargs IsInteractive( BPTR file );
LONG    __stdargs Execute( CONST_STRPTR string, BPTR file, BPTR file2 );
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
