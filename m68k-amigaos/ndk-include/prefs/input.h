#ifndef PREFS_INPUT_H
#define PREFS_INPUT_H
/*
**	$VER: input.h 47.1 (2.8.2019)
**
**	File format for input preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif


/*****************************************************************************/


#define ID_INPT MAKE_ID('I','N','P','T')


struct InputPrefs
{
    char	   ip_Keymap[16];
    UWORD	   ip_PointerTicks;
    TimeVal_Type   ip_DoubleClick;
    TimeVal_Type   ip_KeyRptDelay;
    TimeVal_Type   ip_KeyRptSpeed;
    WORD	   ip_MouseAccel;
};


/*****************************************************************************/


#endif /* PREFS_INPUT_H */
