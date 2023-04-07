#ifndef CLIB_REXXSYSLIB_PROTOS_H
#define CLIB_REXXSYSLIB_PROTOS_H

/*
**	$VER: rexxsyslib_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*--- functions in V33 or higher (Release 1.2) ---*/
#ifndef  REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif
#ifndef  REXX_REXXIO_H
#include <rexx/rexxio.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif

UBYTE * __stdargs CreateArgstring( CONST_STRPTR string, ULONG length );
VOID  __stdargs DeleteArgstring( UBYTE *argstring );
ULONG  __stdargs LengthArgstring( CONST UBYTE *argstring );
struct RexxMsg * __stdargs CreateRexxMsg( struct MsgPort *port, CONST_STRPTR extension, CONST_STRPTR host );
VOID  __stdargs DeleteRexxMsg( struct RexxMsg *packet );
VOID  __stdargs ClearRexxMsg( struct RexxMsg *msgptr, ULONG count );
BOOL  __stdargs FillRexxMsg( struct RexxMsg *msgptr, ULONG count, ULONG mask );
BOOL  __stdargs IsRexxMsg( CONST struct RexxMsg *msgptr );


VOID  __stdargs LockRexxBase( ULONG resource );
VOID  __stdargs UnlockRexxBase( ULONG resource );

/*--- function in V45 or higher (Release 3.9) ---*/

struct MsgPort * __stdargs CreateRexxHostPort( CONST_STRPTR basename );
VOID  __stdargs DeleteRexxHostPort( struct MsgPort *port );
LONG  __stdargs GetRexxVarFromMsg( CONST_STRPTR var, CONST struct RexxMsg *msgptr, STRPTR value );
LONG  __stdargs SetRexxVarFromMsg( CONST_STRPTR var, struct RexxMsg *msgptr, CONST_STRPTR value );
struct RexxMsg * __stdargs LaunchRexxScript( CONST_STRPTR script, struct MsgPort *replyport, CONST_STRPTR extension, BPTR input, BPTR output );
VOID  __stdargs FreeRexxMsg( struct RexxMsg *msgptr );

/*--- function in V47 or higher (Release 3.2) ---*/

LONG  __stdargs GetRexxBufferFromMsg( CONST_STRPTR var, CONST struct RexxMsg *msgptr, STRPTR buffer, ULONG buffer_size );


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_REXXSYSLIB_PROTOS_H */
