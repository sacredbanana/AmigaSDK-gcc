#ifndef CLIB_ALIB_STDIO_PROTOS_H
#define CLIB_ALIB_STDIO_PROTOS_H

/*
	amiga.lib stdio C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#ifdef __PPC__

#warning No stdio funcs in MorphOS libabox.a, use libnix functions instead...

#else

#ifndef  EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __PPC__ */

#endif /* CLIB_ALIB_STDIO_PROTOS_H */
