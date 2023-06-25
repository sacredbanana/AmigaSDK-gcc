#ifndef CLIB_TRANSLATOR_PROTOS_H
#define CLIB_TRANSLATOR_PROTOS_H

/*
**    $Id: translator_protos.h,v 1.8 2010-01-31 01:29:03 ssolie Exp $
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

LONG Translate( CONST_STRPTR inputString, LONG inputLength, STRPTR outputBuffer, LONG bufferSize );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_TRANSLATOR_PROTOS_H */
