	IFND GADGETS_GRADIENTSLIDER_I
GADGETS_GRADIENTSLIDER_I	SET	1

**	$VER: gradientslider.i 47.1 (30.7.2019)
**
**	Definitions for the gradientslider BOOPSI class
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.

;---------------------------------------------------------------------------

    IFND UTILITY_TAGITEM_I
    INCLUDE "utility/tagitem.i"
    ENDC

;---------------------------------------------------------------------------

GRAD_Dummy	 equ (TAG_USER+$05000000)
GRAD_MaxVal	 equ (GRAD_Dummy+1)	; max value of slider
GRAD_CurVal	 equ (GRAD_Dummy+2)	; current value of slider
GRAD_SkipVal	 equ (GRAD_Dummy+3)	; "body click" move amount
GRAD_KnobPixels  equ (GRAD_Dummy+4)	; size of knob in pixels
GRAD_PenArray	 equ (GRAD_Dummy+5)	; pen colors				   */

;---------------------------------------------------------------------------

	ENDC	; GADGETS_GRADIENTSLIDER_I
