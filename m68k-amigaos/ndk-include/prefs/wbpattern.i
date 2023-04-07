	IFND	PREFS_WBPATTERN_I
PREFS_WBPATTERN_I	SET	1
**
**	$VER: wbpattern.i 47.1 (2.8.2019)
**
**	File format for wbpattern preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

	IFND EXEC_TYPES_I
	INCLUDE "exec/types.i"
	ENDC

;---------------------------------------------------------------------------

ID_PTRN		equ	'PTRN'

;---------------------------------------------------------------------------

    STRUCTURE WBPatternPrefs,0
	STRUCT	wbp_Reserved,(4*4)
	UWORD	wbp_Which			; Which pattern is it
	UWORD	wbp_Flags
	BYTE 	wbp_Revision			; Must be set to zero
	BYTE 	wbp_Depth			; Depth of pattern
	UWORD	wbp_DataLength			; Length of following data
    LABEL WBPatternPrefs_SIZEOF

;---------------------------------------------------------------------------

; constants for WBPatternPrefs.wbp_Which
WBP_ROOT	equ	0
WBP_DRAWER	equ	1
WBP_SCREEN	equ	2

; wbp_Flags values
    BITDEF WBP,PATTERN,0
	; Data contains a pattern

    BITDEF WBP,NOREMAP,4
	; Don't remap the pattern

WBPF_DITHER_MASK	equ	$0300	;mask for dithering flags

; PDTA_DitherQuality: see pictureclass.h
WBPF_DITHER_DEF		equ	$0000	;dither quality: default
WBPF_DITHER_BAD		equ	$0100	;dither quality: 0
WBPF_DITHER_GOOD	equ	$0200	;dither quality: 2
WBPF_DITHER_BEST	equ	$0300	;dither quality: 4

*
* The following were added in V47
* How to place graphics.

WBPF_PLACEMENT_MASK		equ	$3000
WBPF_PLACEMENT_TILE		equ	$0000
WBPF_PLACEMENT_CENTER		equ	$1000
WBPF_PLACEMENT_SCALE		equ	$2000
WBPF_PLACEMENT_SCALEGOOD	equ	$3000

*
* Alignment of the image for pattern
* currently ignored
*
WBPF_ALIGNMENT_MASK		equ	$c000
WBPF_ALIGNMENT_MIDDLE 		equ	$0000
WBPF_ALIGNMENT_LEFTTOP		equ	$4000
WBPF_ALIGNMENT_RIGHTBOTTOM	equ	$8000

* OBP_Precision: see pictureclass.h 
WBPF_PRECISION_DEF		equ	$0000
WBPF_PRECISION_ICON		equ	$0400
WBPF_PRECISION_IMAGE		equ	$0800
WBPF_PRECISION_EXACT		equ	$0C00

;---------------------------------------------------------------------------

MAXDEPTH	equ	3			;  Max depth supported (8 colors)
DEFPATDEPTH	equ	2			;  Depth of default patterns

;  Pattern width & height:
PAT_WIDTH	equ	16
PAT_HEIGHT	equ	16

;---------------------------------------------------------------------------

	ENDC	; PREFS_WBPATTERN_I
