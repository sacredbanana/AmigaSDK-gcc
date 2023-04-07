	IFND	LIBRARIES_EXPANSION_I
LIBRARIES_EXPANSION_I	SET	1
**
**	$VER: expansion.i 47.1 (8.11.2021)
**
**	External definitions for expansion.library
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND	EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC	;EXEC_TYPES_I



EXPANSIONNAME	MACRO
		dc.b	'expansion.library',0
		ENDM


;flag for the AddDosNode() call
	BITDEF	ADN,STARTPROC,0

	ENDC	;LIBRARIES_EXPANSION_I
