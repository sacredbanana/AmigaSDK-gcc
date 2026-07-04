#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

/*
	timer.device include (V52)

	Copyright © 2002-2018 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#pragma pack(2)


#define UNIT_MICROHZ       0
#define UNIT_VBLANK        1
#define UNIT_ECLOCK        2
#define UNIT_WAITUNTIL     3
#define UNIT_WAITECLOCK    4
/*** V50 ***/
#define UNIT_CPUCLOCK      5
#define UNIT_WAITCPUCLOCK  6
/*** V52 ***/
#define UNIT_WAITUTC       7


#define TIMERNAME  "timer.device"

/*
  New in SDK 3.20 onwards: The timer.device uses "struct TimeVal" consistently,
  rather than trying to align it to <sys/time.h> "struct timeval". These
  structures have always been different (for example, the seconds value is
  unsigned for timer.device but is signed for sys/time.h). This caused
  inconsistencies and outright miscompilation of code when both headers were
  included, entirely depending on the order in which the headers were included.
  There is a compatibility define from timeval to TimeVal, which will be
  removed if <sys/time.h> is also included. This means that some old code that
  compiled before may refer to structure fields that do not really exist, and
  will thus fail to compile with new SDK. It is highly recommended to use the
  structures consistently without mixing them. To identify if the timer.device
  structure name is the new TimeVal, you can check for the following define:
*/
#define DEVICES_TIMER_H_TIMEVAL_CAMELCASE 1

struct TimeVal
{
	ULONG tv_secs;
	ULONG tv_micro;
};
#if !defined(_SYS__TIMEVAL_H_) && !defined(_SYS_TIME_H_) && !defined(DEVICES_TIMER_H_TIMEVAL_ALIAS)
#define DEVICES_TIMER_H_TIMEVAL_ALIAS
#define timeval TimeVal
#endif

struct EClockVal
{
	ULONG ev_hi;
	ULONG ev_lo;
};

struct timerequest
{
	struct IORequest tr_node;
	struct TimeVal   tr_time;
};


#define TR_ADDREQUEST    (CMD_NONSTD)
#define TR_GETSYSTIME    (CMD_NONSTD + 1)
#define TR_SETSYSTIME    (CMD_NONSTD + 2)
#define TR_GETUTCSYSTIME (CMD_NONSTD + 3)
#define TR_SETUTCSYSTIME (CMD_NONSTD + 4)


#pragma pack()

#endif /* DEVICES_TIMER_H */
