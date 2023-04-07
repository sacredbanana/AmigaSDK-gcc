	IFND	WORKBENCH_STARTUP_I
WORKBENCH_STARTUP_I	EQU	1
**
**	$VER: startup.i 47.1 (3.8.2019)
**
**	workbench startup definitions
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND	EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC

	IFND	EXEC_PORTS_I
	INCLUDE	"exec/ports.i"
	ENDC

	IFND	DOS_DOS_I
	INCLUDE	"dos/dos.i"
	ENDC

 STRUCTURE WBStartup,0
	STRUCT	sm_Message,MN_SIZE	; a standard message structure
	APTR	sm_Process		; the process descriptor for you
	BPTR	sm_Segment		; a descriptor for your code
	LONG	sm_NumArgs		; the number of elements in ArgList
	APTR	sm_ToolWindow		; description of window
	APTR	sm_ArgList		; the arguments themselves
	LABEL	sm_SIZEOF

 STRUCTURE WBArg,0
	BPTR	wa_Lock			; a lock descriptor
	APTR	wa_Name			; a string relative to that lock
	LABEL	wa_SIZEOF

	ENDC	; WORKBENCH_STARTUP_I

