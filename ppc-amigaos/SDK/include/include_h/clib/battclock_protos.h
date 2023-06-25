#ifndef CLIB_BATTCLOCK_PROTOS_H
#define CLIB_BATTCLOCK_PROTOS_H

/*
**    $Id: battclock_protos.h,v 1.8 2010-01-31 01:28:56 ssolie Exp $
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

VOID ResetBattClock( VOID );
ULONG ReadBattClock( VOID );
VOID WriteBattClock( ULONG time );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_BATTCLOCK_PROTOS_H */
