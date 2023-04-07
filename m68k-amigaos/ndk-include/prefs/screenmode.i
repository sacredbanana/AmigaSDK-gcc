	IFND	PREFS_SCREENMODE_I
PREFS_SCREENMODE_I	SET	1
**
**	$VER: screenmode.i 47.1 (2.8.2019)
**
**	File format for screen mode preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

;---------------------------------------------------------------------------

ID_SCRM equ "SCRM"


   STRUCTURE ScreenModePrefs,0
	STRUCT smp_Reserved,4*4
	ULONG  smp_DisplayID
	UWORD  smp_Width
	UWORD  smp_Height
	UWORD  smp_Depth
	UWORD  smp_Control
   LABEL ScreenModePrefs_SIZEOF

; flags for ScreenModePrefs.smp_Control
	BITDEF	SM,AUTOSCROLL,0

;---------------------------------------------------------------------------

	ENDC	; PREFS_SCREENMODE_I
