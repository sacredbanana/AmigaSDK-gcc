	IFND	PREFS_ASL_I
PREFS_ASL_I	SET	1
**
**	$VER: asl.i 47.1 (2.8.2019)
**
**	File format for ASL ("application support library") preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND LIBRARIES_ASL_I
    INCLUDE "libraries/asl.i"
    ENDC

;---------------------------------------------------------------------------

ID_ASL equ "ASL "

   STRUCTURE AslPrefs,0
      STRUCT ap_Reserved,4*4

	; These members correspond directly to the associated
	; members of the 'AslSemaphore' data structure defined
	; in the <libraries/asl.h> header file by the same names.

	UBYTE	ap_SortBy
	UBYTE	ap_SortDrawers
	UBYTE	ap_SortOrder

	UBYTE	ap_SizePosition

	WORD	ap_RelativeLeft
	WORD	ap_RelativeTop

	UBYTE	ap_RelativeWidth
	UBYTE	ap_RelativeHeight

   LABEL AslPrefs_SIZEOF

;---------------------------------------------------------------------------

	ENDC	; PREFS_ASL_I
