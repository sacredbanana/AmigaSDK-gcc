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

VOID AddTime( struct TimeVal *dest, CONST struct TimeVal *src );
VOID SubTime( struct TimeVal *dest, CONST struct TimeVal *src );
LONG CmpTime( CONST struct TimeVal *dest, CONST struct TimeVal *src );
ULONG ReadEClock( struct EClockVal *dest );
VOID GetSysTime( struct TimeVal *dest );

/*** V50 ***/
ULONG ReadCPUClock( UQUAD *dest );
/*** V51 ***/
VOID GetUpTime( struct TimeVal *dest );
/*** V52 ***/
VOID GetUTCSysTime( struct TimeVal *dest );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_TIMER_PROTOS_H */
