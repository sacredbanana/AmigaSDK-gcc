#ifndef  CLIB_DDEBUG_PROTOS_H
#define  CLIB_DDEBUG_PROTOS_H

/*
**	$VER: ddebug_protos.h 47.1 (27.10.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

/* debug support functions in ddebug.lib */

/* Note: both  __stdargs KCmpStr() and  __stdargs cmpstrexec() are also
 *       found in debug.lib!
 */
LONG  __stdargs KCmpStr( CONST_STRPTR a, CONST_STRPTR b );
LONG  __stdargs cmpstrexec( CONST_STRPTR a, CONST_STRPTR b );

LONG  __stdargs DGetNum( VOID );
LONG  __stdargs dgetnum( VOID );
VOID  __stdargs dputchar( LONG ch );
VOID  __stdargs dputch( LONG ch );
VOID  __stdargs DPutCh( LONG ch );
VOID  __stdargs dputc( LONG ch );
VOID  __stdargs DPutChar( LONG ch );
VOID  __stdargs dputstr( CONST_STRPTR string );
VOID  __stdargs dputs( CONST_STRPTR string );
VOID  __stdargs DPutS( CONST_STRPTR string );
VOID  __stdargs DPutStr( CONST_STRPTR string );
LONG  __stdargs dgetchar( VOID );
LONG  __stdargs dgetch( VOID );
LONG  __stdargs DGetCh( VOID );
LONG  __stdargs dgetc( VOID );
LONG  __stdargs DGetChar( VOID );
LONG  __stdargs DMayGetCh( VOID );
LONG  __stdargs DMayGetChar( VOID );
VOID  __stdargs DPutFmt( CONST_STRPTR formatString, CONST_APTR values );
VOID  __stdargs dprintf( CONST_STRPTR formatString, ... );
VOID  __stdargs DPrintF( CONST_STRPTR formatString, ... );
VOID  __stdargs DDoFmt( CONST_STRPTR formatString, CONST_APTR dataStream, CONST_APTR putChProc, APTR putChData );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_DDEBUG_PROTOS_H */
