	IFND	PREFS_INPUT_I
PREFS_INPUT_I	SET	1
**
**	$VER: input.i 47.1 (2.8.2019)
**
**	File format for input preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND DEVICES_TIMER_I
    INCLUDE "devices/timer.i"
    ENDC

;---------------------------------------------------------------------------

ID_INPT equ "INPT"


   STRUCTURE InputPrefs,0
	STRUCT ip_Keymap,16
	UWORD  ip_PointerTicks
	STRUCT ip_DoubleClick,TV_SIZE
	STRUCT ip_KeyRptDelay,TV_SIZE
	STRUCT ip_KeyRptSpeed,TV_SIZE
	WORD   ip_MouseAccel
   LABEL InputPrefs_SIZEOF

;---------------------------------------------------------------------------

	ENDC	; PREFS_INPUT_I
