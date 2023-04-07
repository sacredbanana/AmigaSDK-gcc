	IFND	DEVICES_CIA_I
DEVICES_CIA_I	SET	1
**
**	$VER: cia.i 47.1 (3.8.2019)
**
**	cia resource name strings.
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

CIAANAME	MACRO
		DC.B	'ciaa.resource',0
		ENDM

CIABNAME	MACRO
		DC.B	'ciab.resource',0
		ENDM

	ENDC	; DEVICES_CIA_I
