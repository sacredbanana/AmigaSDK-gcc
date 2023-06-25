#ifndef CLIB_TEXTCLIP_PROTOS_H
#define CLIB_TEXTCLIP_PROTOS_H

/*
**    $Id: textclip_protos.h,v 1.8 2010-01-31 01:29:03 ssolie Exp $
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

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

LONG WriteClipVector( CONST_STRPTR vector, ULONG size );
LONG ReadClipVector( STRPTR *bufptr, ULONG *sizptr );
VOID DisposeClipVector( STRPTR vector );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_TEXTCLIP_PROTOS_H */
