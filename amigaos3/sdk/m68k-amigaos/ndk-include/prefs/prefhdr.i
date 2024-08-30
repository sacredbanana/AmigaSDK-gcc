	IFND	PREFS_PREFHDR_I
PREFS_PREFHDR_I	SET	1
**
**	$VER: prefhdr.i 47.1 (2.8.2019)
**
**	File format for preferences header
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

;---------------------------------------------------------------------------

ID_PREF	equ "PREF"
ID_PRHD	equ "PRHD"

;---------------------------------------------------------------------------

   STRUCTURE PrefHeader,0
	UBYTE	ph_Version	; version of following data
	UBYTE	ph_Type		; type of following data
	ULONG	ph_Flags	; always set to 0 for now
   LABEL PrefHeader_SIZEOF

;---------------------------------------------------------------------------

	ENDC	; PREFS_PREFHDR_I
