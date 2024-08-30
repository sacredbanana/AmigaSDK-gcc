#ifndef CLIB_DDEBUG_PROTOS_H
#define CLIB_DDEBUG_PROTOS_H

/*
**    $Id: ddebug_protos.h,v 1.7 2010-01-31 01:29:02 ssolie Exp $
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

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

VOID DDoFmt( CONST_STRPTR formatString, CONST APTR dataStream, CONST APTR putChProc, APTR putChData );
LONG DGetChar( VOID );
LONG dgetchar( VOID );
LONG dgetch( VOID );
LONG dgetc( VOID );
LONG DGetNum( VOID );
LONG dgetnum( VOID );
LONG DMayGetChar( VOID );
LONG DMayGetCh( VOID );
VOID DPutChar( LONG ch );
VOID dputchar( LONG ch );
VOID dputch( LONG ch );
VOID dputc( LONG ch );
VOID DPutCh( LONG ch );
VOID DPutFmt( CONST_STRPTR formatString, CONST APTR values );
VOID DVPrintF( CONST_STRPTR formatString, CONST APTR values );
VOID DPrintF( CONST_STRPTR formatString, ... );
VOID dprintf( CONST_STRPTR formatString, ... );
VOID DPutStr( CONST_STRPTR string );
VOID dputstr( CONST_STRPTR string );
VOID dputs( CONST_STRPTR string );
VOID DPutS( CONST_STRPTR string );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_DDEBUG_PROTOS_H */
