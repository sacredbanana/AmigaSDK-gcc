#ifndef CLIB_CIA_PROTOS_H
#define CLIB_CIA_PROTOS_H

/*
**    $Id: cia_protos.h,v 1.8 2010-01-31 01:29:00 ssolie Exp $
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

struct Interrupt *AddICRVector( struct Library *resource, LONG iCRBit, struct Interrupt *interrupt );
VOID RemICRVector( struct Library *resource, LONG iCRBit, struct Interrupt *interrupt );
WORD AbleICR( struct Library *resource, LONG mask );
WORD SetICR( struct Library *resource, LONG mask );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CIA_PROTOS_H */
