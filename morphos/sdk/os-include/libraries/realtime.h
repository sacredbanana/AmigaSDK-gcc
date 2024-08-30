#ifndef LIBRARIES_REALTIME_H
#define LIBRARIES_REALTIME_H

/*
	realtime.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#pragma pack(2)


#define TICK_FREQ  1200


struct Conductor
{
	struct Node    cdt_Link;
	UWORD          cdt_Reserved0;
	struct MinList cdt_Players;
	ULONG          cdt_ClockTime;
	ULONG          cdt_StartTime;
	ULONG          cdt_ExternalTime;
	ULONG          cdt_MaxExternalTime;
	ULONG          cdt_Metronome;
	UWORD          cdt_Reserved1;
	UWORD          cdt_Flags;
	UBYTE          cdt_State;
};


#define CONDUCTB_EXTERNAL  0
#define CONDUCTB_GOTTICK   1
#define CONDUCTB_METROSET  2
#define CONDUCTB_PRIVATE   3

#define CONDUCTF_EXTERNAL  (1<<CONDUCTB_EXTERNAL)
#define CONDUCTF_GOTTICK   (1<<CONDUCTB_GOTTICK)
#define CONDUCTF_METROSET  (1<<CONDUCTB_METROSET)
#define CONDUCTF_PRIVATE   (1<<CONDUCTB_PRIVATE)


#define CONDSTATE_STOPPED      0
#define CONDSTATE_PAUSED       1
#define CONDSTATE_LOCATE       2
#define CONDSTATE_RUNNING      3

#define CONDSTATE_METRIC      -1
#define CONDSTATE_SHUTTLE     -2
#define CONDSTATE_LOCATE_SET  -3


struct Player
{
	struct Node       pl_Link;
	BYTE              pl_Reserved0;
	BYTE              pl_Reserved1;
	struct Hook      *pl_Hook;
	struct Conductor *pl_Source;
	struct Task      *pl_Task;
	LONG              pl_MetricTime;
	LONG              pl_AlarmTime;
	APTR              pl_UserData;
	UWORD             pl_PlayerID;
	UWORD             pl_Flags;
};


#define PLAYERB_READY      0
#define PLAYERB_ALARMSET   1
#define PLAYERB_QUIET      2
#define PLAYERB_CONDUCTED  3
#define PLAYERB_EXTSYNC    4

#define PLAYERF_READY      (1<<PLAYERB_READY)
#define PLAYERF_ALARMSET   (1<<PLAYERB_ALARMSET)
#define PLAYERF_QUIET      (1<<PLAYERB_QUIET)
#define PLAYERF_CONDUCTED  (1<<PLAYERB_CONDUCTED)
#define PLAYERF_EXTSYNC    (1<<PLAYERB_EXTSYNC)


#define PLAYER_Base          (TAG_USER + 64)
#define PLAYER_Hook          (PLAYER_Base + 1)
#define PLAYER_Name          (PLAYER_Base + 2)
#define PLAYER_Priority      (PLAYER_Base + 3)
#define PLAYER_Conductor     (PLAYER_Base + 4)
#define PLAYER_Ready         (PLAYER_Base + 5)

#define PLAYER_AlarmSigTask  (PLAYER_Base + 6)

#define PLAYER_Conducted     (PLAYER_Base + 7)

#define PLAYER_AlarmSigBit   (PLAYER_Base + 8)

#define PLAYER_Quiet         (PLAYER_Base + 9)

#define PLAYER_UserData      (PLAYER_Base + 10)
#define PLAYER_ID            (PLAYER_Base + 11)

#define PLAYER_AlarmTime     (PLAYER_Base + 12)
#define PLAYER_Alarm         (PLAYER_Base + 13)

#define PLAYER_ExtSync       (PLAYER_Base + 14)
#define PLAYER_ErrorCode     (PLAYER_Base + 15)


#define PM_TICK      0
#define PM_STATE     1
#define PM_POSITION  2
#define PM_SHUTTLE   3


struct pmTime
{
	ULONG pmt_Method;
	ULONG pmt_Time;
};

struct pmState
{
	ULONG pms_Method;
	ULONG pms_OldState;
};


#define RT_CONDUCTORS  0


#define RTE_NOMEMORY     801
#define RTE_NOCONDUCTOR  802
#define RTE_NOTIMER      803
#define RTE_PLAYING      804


struct RealTimeBase
{
	struct Library rtb_LibNode;
	UBYTE          rtb_Reserved0[2];

	ULONG          rtb_Time;
	ULONG          rtb_TimeFrac;
	UWORD          rtb_Reserved1;
	WORD           rtb_TickErr;
};


#define RealTime_TickErr_Min  -705
#define RealTime_TickErr_Max   705


#pragma pack()

#endif /* LIBRARIES_REALTIME_H */
