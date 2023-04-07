	IFND	RESOURCES_BATTMEM_I
RESOURCES_BATTMEM_I	SET	1
**
**	$VER: battmem.i 47.1 (3.8.2019)
**
**	BattMem resource name strings.
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

BATTMEMNAME	MACRO
		dc.b	'battmem.resource',0
		ds.w	0
		ENDM

	ENDC	; RESOURCES_BATTMEM_I
