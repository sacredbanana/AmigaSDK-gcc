#ifndef  INTERNAL_CLIB_LANGUAGE_PROTOS_H
#define  INTERNAL_CLIB_LANGUAGE_PROTOS_H

/*
**	$Id: language_protos.h,v 1.1 2008-09-15 13:17:39 sarcher Exp $
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001-2005 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  INTERNAL_LANGUAGEDRIVERS_H
#include <internal/languagedrivers.h>
#endif
ULONG LG_GetDriverInfo( VOID );
ULONG LG_ConvToLower( ULONG character );
ULONG LG_ConvToUpper( ULONG character );
ULONG LG_GetCodeSet( VOID );
CONST_STRPTR LG_GetLocaleStr( ULONG stringNum );
LONG LG_IsAlNum( ULONG character );
LONG LG_IsAlpha( ULONG character );
LONG LG_IsCntrl( ULONG character );
LONG LG_IsDigit( ULONG character );
LONG LG_IsGraph( ULONG character );
LONG LG_IsLower( ULONG character );
LONG LG_IsPrint( ULONG character );
LONG LG_IsPunct( ULONG character );
LONG LG_IsSpace( ULONG character );
LONG LG_IsUpper( ULONG character );
LONG LG_IsXDigit( ULONG character );
ULONG LG_StrConvert( CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type );
LONG LG_StrnCmp( CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type );
LONG LG_IsBlank( ULONG character );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* INTERNAL_CLIB_LANGUAGE_PROTOS_H */
