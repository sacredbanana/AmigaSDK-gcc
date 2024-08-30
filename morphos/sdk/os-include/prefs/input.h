#ifndef PREFS_INPUT_H
#define PREFS_INPUT_H

/*
	input prefs definitions

	Copyright ? 2002-2016 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif


#pragma pack(2)


#define ID_INPT  MAKE_ID('I','N','P','T')

struct InputPrefs
{
	char           ip_Keymap[16];
	UWORD          ip_PointerTicks;
	struct timeval ip_DoubleClick;
	struct timeval ip_KeyRptDelay;
	struct timeval ip_KeyRptSpeed;
	WORD           ip_MouseAccel;
};



#pragma pack()

#endif /* PREFS_INPUT_H */
