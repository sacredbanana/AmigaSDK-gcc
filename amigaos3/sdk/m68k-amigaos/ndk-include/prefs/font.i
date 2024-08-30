	IFND	PREFS_FONT_I
PREFS_FONT_I	SET	1
**
**	$VER: font.i 47.1 (2.8.2019)
**
**	File format for font preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND GRAPHICS_TEXT_I
    INCLUDE "graphics/text.i"
    ENDC

;---------------------------------------------------------------------------

ID_FONT equ "FONT"


FONTNAMESIZE equ 128

   STRUCTURE FontPrefs,0
	STRUCT fp_Reserved,3*4
	UWORD  fp_Reserved2
	UWORD  fp_Type
	UBYTE  fp_FrontPen
	UBYTE  fp_BackPen
	UBYTE  fp_DrawMode
    UBYTE  fp_SpecialDrawMode
	STRUCT fp_TextAttr,ta_SIZEOF
	STRUCT fp_Name,FONTNAMESIZE
   LABEL FontPrefs_SIZEOF

; constants for FontPrefs.fp_Type
FP_WBFONT     equ 0
FP_SYSFONT    equ 1
FP_SCREENFONT equ 2

;---------------------------------------------------------------------------

	ENDC	; PREFS_FONT_I
