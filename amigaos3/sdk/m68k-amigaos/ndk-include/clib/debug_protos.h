#ifndef  CLIB_DEBUG_PROTOS_H
#define  CLIB_DEBUG_PROTOS_H

/*
**	$VER: debug_protos.h 47.1 (30.11.2021)
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

/* debug support functions in debug.lib */

LONG  __stdargs KCmpStr( CONST_STRPTR a, CONST_STRPTR b );
LONG  __stdargs cmpstrexec( CONST_STRPTR a, CONST_STRPTR b );
LONG  __stdargs KGetChar( VOID );
LONG  __stdargs kgetc( VOID );
LONG  __stdargs kgetchar( VOID );
LONG  __stdargs kgetch( VOID );
LONG  __stdargs KGetCh( VOID );
LONG  __stdargs KGetNum( VOID );
LONG  __stdargs kgetnum( VOID );
LONG  __stdargs KMayGetChar( VOID );
LONG  __stdargs KMayGetCh( VOID );
VOID  __stdargs KPutFmt( CONST_STRPTR formatString, CONST_APTR values );
VOID  __stdargs KVPrintF( CONST_STRPTR formatString, CONST_APTR values );
VOID  __stdargs KPrintF( CONST_STRPTR formatString, ... );
VOID  __stdargs kprintf( CONST_STRPTR formatString, ... );
VOID  __stdargs KPutChar( LONG ch );
VOID  __stdargs kputc( LONG ch );
VOID  __stdargs kputchar( LONG ch );
VOID  __stdargs kputch( LONG ch );
VOID  __stdargs KPutCh( LONG ch );
VOID  __stdargs KPutStr( CONST_STRPTR string );
VOID  __stdargs kputs( CONST_STRPTR string );
VOID  __stdargs KPutS( CONST_STRPTR string );
VOID  __stdargs KDoFmt( CONST_STRPTR formatString, CONST_APTR dataStream, CONST_APTR putChProc, APTR putChData );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_DEBUG_PROTOS_H */
