#ifndef CLIB_TIMER_PROTOS_H
#define CLIB_TIMER_PROTOS_H

/*
	timer.device C prototypes (V52)

	Copyright © 2002-2018 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID AddTime( struct timeval *dest, CONST struct timeval *src );
VOID SubTime( struct timeval *dest, CONST struct timeval *src );
LONG CmpTime( CONST struct timeval *dest, CONST struct timeval *src );
ULONG ReadEClock( struct EClockVal *dest );
VOID GetSysTime( struct timeval *dest );

/*** V50 ***/
ULONG ReadCPUClock( UQUAD *dest );
/*** V51 ***/
VOID GetUpTime( struct timeval *dest );
/*** V52 ***/
VOID GetUTCSysTime( struct timeval *dest );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_TIMER_PROTOS_H */
