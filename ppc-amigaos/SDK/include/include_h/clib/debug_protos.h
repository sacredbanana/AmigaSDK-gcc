#ifndef CLIB_DEBUG_PROTOS_H
#define CLIB_DEBUG_PROTOS_H

/*
**    $Id: debug_protos.h,v 1.7 2010-01-31 01:29:02 ssolie Exp $
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

LONG KCmpStr( CONST_STRPTR a, CONST_STRPTR b );
LONG cmpstrexec( CONST_STRPTR a, CONST_STRPTR b );
LONG KGetChar( VOID );
LONG kgetc( VOID );
LONG kgetchar( VOID );
LONG kgetch( VOID );
LONG KGetCh( VOID );
LONG KGetNum( VOID );
LONG kgetnum( VOID );
LONG KMayGetChar( VOID );
LONG KMayGetCh( VOID );
VOID KPutFmt( CONST_STRPTR formatString, CONST APTR values );
VOID KVPrintF( CONST_STRPTR formatString, CONST APTR values );
VOID KPrintF( CONST_STRPTR formatString, ... );
VOID kprintf( CONST_STRPTR formatString, ... );
VOID KPutChar( LONG ch );
VOID kputc( LONG ch );
VOID kputchar( LONG ch );
VOID kputch( LONG ch );
VOID KPutCh( LONG ch );
VOID KPutStr( CONST_STRPTR string );
VOID kputs( CONST_STRPTR string );
VOID KPutS( CONST_STRPTR string );
VOID KDoFmt( CONST_STRPTR formatString, CONST APTR dataStream, CONST APTR putChProc, APTR putChData );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_DEBUG_PROTOS_H */
