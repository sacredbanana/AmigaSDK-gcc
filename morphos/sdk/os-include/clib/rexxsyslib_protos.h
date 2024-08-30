#ifndef CLIB_REXXSYSLIB_PROTOS_H
#define CLIB_REXXSYSLIB_PROTOS_H

/*
	rexxsyslib.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef REXX_RXSLIB_H
# include <rexx/rxslib.h>
#endif

#ifndef REXX_REXXIO_H
# include <rexx/rexxio.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

UBYTE *CreateArgstring( CONST_STRPTR string, ULONG length );
VOID DeleteArgstring( STRPTR argstring );
ULONG LengthArgstring( CONST_STRPTR argstring );
struct RexxMsg *CreateRexxMsg( CONST struct MsgPort *port, CONST_STRPTR extension, CONST_STRPTR host );
VOID DeleteRexxMsg( struct RexxMsg *packet );
VOID ClearRexxMsg( struct RexxMsg *msgptr, ULONG count );
BOOL FillRexxMsg( struct RexxMsg *msgptr, ULONG count, ULONG mask );
BOOL IsRexxMsg( CONST struct RexxMsg *msgptr );

VOID LockRexxBase( ULONG resource );
VOID UnlockRexxBase( ULONG resource );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_REXXSYSLIB_PROTOS_H */
