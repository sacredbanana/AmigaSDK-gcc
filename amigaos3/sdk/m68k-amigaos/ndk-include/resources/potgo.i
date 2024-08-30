	IFND	RESOURCES_POTGO_I
RESOURCES_POTGO_I	EQU	1
**
**	$VER: potgo.i 47.1 (3.8.2019)
**
**	potgo resource name
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**
POTGONAME MACRO
		dc.b	'potgo.resource',0
		ds.w	0
	ENDM

	ENDC	; RESOURCES_POTGO_I
