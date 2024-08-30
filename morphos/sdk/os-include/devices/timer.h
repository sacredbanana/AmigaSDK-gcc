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


#ifndef _SYS_TIME_H_
struct timeval
{
	ULONG tv_secs;
	ULONG tv_micro;
};
#else
# define tv_secs tv_sec
# define tv_micro tv_usec
#endif /* !_SYS_TIME_H_ */

struct EClockVal
{
	ULONG ev_hi;
	ULONG ev_lo;
};

struct timerequest
{
	struct IORequest tr_node;
	struct timeval   tr_time;
};


#define TR_ADDREQUEST    (CMD_NONSTD)
#define TR_GETSYSTIME    (CMD_NONSTD + 1)
#define TR_SETSYSTIME    (CMD_NONSTD + 2)
#define TR_GETUTCSYSTIME (CMD_NONSTD + 3)
#define TR_SETUTCSYSTIME (CMD_NONSTD + 4)


#pragma pack()

#endif /* DEVICES_TIMER_H */
