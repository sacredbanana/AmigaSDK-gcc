#ifndef CLIB_REXXSYSLIB_PROTOS_H
#define CLIB_REXXSYSLIB_PROTOS_H

/*
**    $Id: rexxsyslib_protos.h,v 1.12 2010-01-31 01:29:03 ssolie Exp $
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
#ifndef   REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif
#ifndef   REXX_REXXIO_H
#include <rexx/rexxio.h>
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

/*--- functions in V33 or higher (Release 1.2) ---*/
STRPTR CreateArgstring( CONST_STRPTR string, ULONG length );
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
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_REXXSYSLIB_PROTOS_H */
