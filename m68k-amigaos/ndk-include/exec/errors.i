	IFND	EXEC_ERRORS_I
EXEC_ERRORS_I	SET	1
**
**	$VER: errors.i 47.1 (28.6.2019)
**
**	Standard Device IO Errors (returned in io_Error)
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

IOERR_OPENFAIL		EQU -1	; device/unit failed to open
IOERR_ABORTED		EQU -2	; request terminated early [after AbortIO()]
IOERR_NOCMD		EQU -3	; command not supported by device
IOERR_BADLENGTH		EQU -4	; not a valid length (usually IO_LENGTH)
IOERR_BADADDRESS	EQU -5	; invalid address (misaligned or bad range)
IOERR_UNITBUSY		EQU -6	; device opens ok, but requested unit is busy
IOERR_SELFTEST		EQU -7  ; hardware failed self-test

ERR_OPENDEVICE		EQU  IOERR_OPENFAIL     ; Obsolete

	ENDC	; EXEC_ERRORS_I
