#ifndef CLIB_TIMER_PROTOS_H
#define CLIB_TIMER_PROTOS_H

/*
**    $Id: timer_protos.h,v 1.10 2010-01-31 01:29:03 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   DEVICES_TIMER_H
#include <devices/timer.h>
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

VOID AddTime( struct TimeVal *dest, struct TimeVal *src );
VOID SubTime( struct TimeVal *dest, struct TimeVal *src );
LONG CmpTime( struct TimeVal *dest, struct TimeVal *src );
ULONG ReadEClock( struct EClockVal *dest );
VOID GetSysTime( struct TimeVal *dest );
/* New in V50 */
VOID GetUpTime( struct TimeVal *dest );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_TIMER_PROTOS_H */
