#ifndef  INTERNAL_CLIB_CHARSET_PROTOS_H
#define  INTERNAL_CLIB_CHARSET_PROTOS_H

/*
**	$Id: charset_protos.h,v 1.1 2008-09-15 13:17:39 sarcher Exp $
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
ULONG CS_GetDriverInfo( VOID );
ULONG CS_ConvToLower( ULONG character );
ULONG CS_ConvToUpper( ULONG character );
LONG CS_IsAlNum( ULONG character );
LONG CS_IsAlpha( ULONG character );
LONG CS_IsCntrl( ULONG character );
LONG CS_IsDigit( ULONG character );
LONG CS_IsGraph( ULONG character );
LONG CS_IsLower( ULONG character );
LONG CS_IsPrint( ULONG character );
LONG CS_IsPunct( ULONG character );
LONG CS_IsSpace( ULONG character );
LONG CS_IsUpper( ULONG character );
LONG CS_IsXDigit( ULONG character );
ULONG CS_StrConvert( CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type );
LONG CS_StrnCmp( CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type );
LONG CS_IsBlank( ULONG character );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* INTERNAL_CLIB_CHARSET_PROTOS_H */
