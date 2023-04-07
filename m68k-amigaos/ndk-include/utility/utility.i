	IFND UTILITY_UTILITY_I
UTILITY_UTILITY_I SET 1
**
**	$VER: utility.i 47.1 (3.8.2019)
**
**	utility.library include file
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

	IFND EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC

	IFND EXEC_LIBRARIES_I
	INCLUDE	"exec/libraries.i"
	ENDC

;---------------------------------------------------------------------------

UTILITYNAME MACRO
	DC.B 'utility.library',0
	ENDM

   STRUCTURE UtilityBase,LIB_SIZE
	UBYTE ub_Language
	UBYTE ub_Reserved

;---------------------------------------------------------------------------

	ENDC	; UTILITY_UTILITY_I
