#ifndef	IMAGES_LED_H
#define	IMAGES_LED_H

/*
**	$VER: led.h 47.3 (24.6.2021)
**	Includes Release 47.3
**
**	Definitions for the LED BOOPSI image class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*****************************************************************************/

#define LED_Dummy		(TAG_USER+0x04000000)

#define	LED_Pairs		(LED_Dummy+1)
    /* (WORD) Number of digit pairs (1-8) */

#define	LED_Values		(LED_Dummy+2)
    /* (WORD *) Array of digit pairs.  Must be LED_Pairs in size. */

#define	LED_Colon		(LED_Dummy+3)
    /* (BOOL) Colon on or off. Defaults to FALSE. */

#define	LED_Negative		(LED_Dummy+4)
    /* (BOOL) Negative sign on or off. Defaults to FALSE. */

#define	LED_Signed		(LED_Dummy+5)
    /* (BOOL) Leave space for negative sign. Defaults to FALSE. */

#define	LED_Time		(LED_Dummy+6)
    /* (BOOL) Leave space for colon. Defaults to TRUE. (V47.3) */

#define	LED_Hexadecimal		(LED_Dummy+7)
    /* (BOOL) Hexadecimal instead of decimal output. Defaults to FALSE.
       (V47.3) */

#define LED_Raw			(LED_Dummy+8)
    /* (BOOL) Raw mode. Defaults to FALSE. (V47.3) */

/*****************************************************************************/

#endif /* IMAGES_LED_H */
