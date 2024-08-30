#ifndef CLIB_ALIB_STDIO_PROTOS_H
#define CLIB_ALIB_STDIO_PROTOS_H

/*
**    $Id: alib_stdio_protos.h,v 1.10 2010-01-31 01:28:54 ssolie Exp $
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

/****************************************************************************\
*                                                                            *
* NOTE: many of the functions traditionally found in amiga.lib have been     *
*       moved into the memory resident operating system with AmigaOS4. This  *
*       includes functionality which is available only as 68k assembly code  *
*       in the original amiga.lib implementation. You are advised to check   *
*       the API definitions of the libraries named in the sections commented *
*       out below and to use the functionality available rather than the old *
*       amiga.lib code.                                                      *
*                                                                            *
\****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

/* stdio functions that duplicate those in a typical C library (dos.library) */
#if !defined(__amigaos4__)
LONG printf( CONST_STRPTR fmt, ... );
LONG sprintf( CONST_STRPTR buffer, CONST_STRPTR fmt, ... );
LONG fclose( LONG stream );
LONG fgetc( LONG stream );
LONG fprintf( LONG stream, CONST_STRPTR fmt, ... );
LONG fputc( LONG c, LONG stream );
LONG fputs( CONST_STRPTR s, LONG stream );
LONG getchar( VOID );
LONG putchar( ULONG c );
LONG puts( CONST_STRPTR s );
#endif /* __amigaos4__ */


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_ALIB_STDIO_PROTOS_H */
