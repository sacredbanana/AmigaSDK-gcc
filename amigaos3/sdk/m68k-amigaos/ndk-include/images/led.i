	IFND	IMAGES_LED_I
IMAGES_LED_I	SET	1

**
**	$VER: led.h 47.3 (24.6.2021)
**	Includes Release 47.3
**
**	Definitions for the LED BOOPSI image class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;*****************************************************************************

    IFND EXEC_TYPES_I
    INCLUDE "exec/types.i"
    ENDC

    IFND UTILITY_TAGITEM_H
    INCLUDE "utility/tagitem.i"
    ENDC

    IFND INTUITION_IMAGECLASS_I
    INCLUDE "intuition/imageclass.i"
    ENDC

;*****************************************************************************

LED_Dummy		equ	(TAG_USER+$04000000)

LED_Pairs		equ	(LED_Dummy+1)
    ; (WORD) Number of digit pairs (1-8)

LED_Values		equ	(LED_Dummy+2)
    ; (WORD *) Array of digit pairs.  Must be LED_Pairs in size.

LED_Colon		equ	(LED_Dummy+3)
    ; (BOOL) Colon on or off

LED_Negative		equ	(LED_Dummy+4)
    ; (BOOL) Negative sign on or off

LED_Signed		equ	(LED_Dummy+5)
    ; (BOOL) Leave space for negative sign

LED_Time		equ	(LED_Dummy+6)
    ; (BOOL) Leave space for colon. Defaults to TRUE. (V47.3)

LED_Hexadecimal		equ	(LED_Dummy+7)
    ; (BOOL) Hexadecimal instead of decimal output. Defaults to FALSE. (V47.3)

LED_Raw			equ	(LED_Dummy+8)
    ; (BOOL) Raw mode. Defaults to FALSE. (V47.3)

;*****************************************************************************

    ENDC	; IMAGES_LED_I
