#ifndef CLIB_CIAB_PROTOS_H
#define CLIB_CIAB_PROTOS_H

/*
**    $Id: ciab_protos.h,v 1.7 2010-01-31 01:29:01 ssolie Exp $
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
#ifndef   EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
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

struct Interrupt *AddICRBVector( LONG iCRBit, struct Interrupt *interrupt );
VOID RemICRBVector( LONG iCRBit, struct Interrupt *interrupt );
WORD AbleICRB( LONG mask );
WORD SetICRB( LONG mask );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CIAB_PROTOS_H */
