	IFND	DEVICES_INPUT_I
DEVICES_INPUT_I SET	1
**
**	$VER: input.i 47.1 (28.6.2019)
**
**	input device command definitions 
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

   IFND	    EXEC_IO_I
   INCLUDE     "exec/io.i"
   ENDC

   DEVINIT

   DEVCMD	IND_ADDHANDLER
   DEVCMD	IND_REMHANDLER
   DEVCMD	IND_WRITEEVENT
   DEVCMD	IND_SETTHRESH
   DEVCMD	IND_SETPERIOD
   DEVCMD	IND_SETMPORT
   DEVCMD	IND_SETMTYPE
   DEVCMD	IND_SETMTRIG

IND_ADDEVENT	EQU 24	; V47 similar to WRITEEVNT, but includes keyboard repeat functions 

	ENDC	; DEVICES_INPUT_I
