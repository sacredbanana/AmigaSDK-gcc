	IFND	PREFS_PALETTE_I
PREFS_PALETTE_I	SET	1
**
**	$VER: palette.i 47.1 (2.8.2019)
**
**	File format for palette preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND INTUITION_INTUITION_I
    INCLUDE "intuition/intuition.i"
    ENDC

;---------------------------------------------------------------------------

ID_PALT equ "PALT"

   STRUCTURE PalettePrefs,0
	STRUCT pap_Reserved,4*4		; System reserved
	STRUCT pap_4ColorPens,32*2
	STRUCT pap_8ColorPens,32*2
	STRUCT pap_Colors,32*cs_SIZEOF  ; Used as full 16-bit RGB values
   LABEL PalettePrefs_SIZEOF

;---------------------------------------------------------------------------

	ENDC	; PREFS_PALETTE_I
