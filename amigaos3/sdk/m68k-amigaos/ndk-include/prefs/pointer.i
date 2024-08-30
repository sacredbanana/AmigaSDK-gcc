	IFND PREFS_POINTER_I
PREFS_POINTER_I		SET	1
**
**	$VER: pointer.i 47.1 (2.8.2019)
**
**	File format for pointer preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

	IFND EXEC_TYPES_I
	INCLUDE "exec/types.i"
	ENDC

	IFND LIBRARIES_IFFPARSE_I
	INCLUDE "libraries/iffparse.i"
	ENDC

;---------------------------------------------------------------------------

ID_PNTR		equ	'PNTR'

;---------------------------------------------------------------------------

    STRUCTURE PointerPrefs,0
	STRUCT	pp_Reserved,4*4
	UWORD	pp_Which				; 0=NORMAL, 1=BUSY
	UWORD	pp_Size					; see "intuition/pointerclass.i"
	UWORD	pp_Width				; Width in pixels
	UWORD	pp_Height				; Height in pixels
	UWORD	pp_Depth				; Depth
	UWORD	pp_YSize				; YSize
	WORD	pp_X, pp_Y				; Hotspot

	; Color Table:  numEntries = (1 << pp_Depth) - 1
	; Sprite data follows

    LABEL PointerPrefs_SIZEOF

;---------------------------------------------------------------------------

; constants for PointerPrefs.pp_Which
WBP_NORMAL	equ	0
WBP_BUSY	equ	1

;---------------------------------------------------------------------------

    STRUCTURE RGBTable,0
	UBYTE	rgbt_Red
	UBYTE	rgbt_Green
	UBYTE	rgbt_Blue
    LABEL RGBTable_SIZEOF

;---------------------------------------------------------------------------

	ENDC	; PREFS_POINTER_I
