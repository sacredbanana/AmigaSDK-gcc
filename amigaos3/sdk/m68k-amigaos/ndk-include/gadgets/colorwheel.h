#ifndef GADGETS_COLORWHEEL_H
#define GADGETS_COLORWHEEL_H
/*
**	$VER: colorwheel.h 47.3 (3.10.2019)
**
**	Definitions for the colorwheel BOOPSI class
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*****************************************************************************/


/* For use with the WHEEL_HSB tag */
struct ColorWheelHSB
{
    ULONG cw_Hue;
    ULONG cw_Saturation;
    ULONG cw_Brightness;
};

/* For use with the WHEEL_RGB tag */
struct ColorWheelRGB
{
    ULONG cw_Red;
    ULONG cw_Green;
    ULONG cw_Blue;
};

/*****************************************************************************/

#define WHEEL_Dummy	     (TAG_USER+0x04000000)
#define WHEEL_Hue	     (WHEEL_Dummy+1)   /* set/get Hue		   */
#define WHEEL_Saturation     (WHEEL_Dummy+2)   /* set/get Saturation	    */
#define WHEEL_Brightness     (WHEEL_Dummy+3)   /* set/get Brightness	    */
#define WHEEL_HSB	     (WHEEL_Dummy+4)   /* set/get ColorWheelHSB     */
#define WHEEL_Red	     (WHEEL_Dummy+5)   /* set/get Red		    */
#define WHEEL_Green	     (WHEEL_Dummy+6)   /* set/get Green	    */
#define WHEEL_Blue	     (WHEEL_Dummy+7)   /* set/get Blue		    */
#define WHEEL_RGB	     (WHEEL_Dummy+8)   /* set/get ColorWheelRGB     */
#define WHEEL_Screen	     (WHEEL_Dummy+9)   /* init screen/enviroment    */
#define WHEEL_Abbrv	     (WHEEL_Dummy+10)  /* "GCBMRY" if English	    */
#define WHEEL_Donation	     (WHEEL_Dummy+11)  /* colors donated by app     */
#define WHEEL_BevelBox	     (WHEEL_Dummy+12)  /* inside a bevel box	    */
#define WHEEL_GradientSlider (WHEEL_Dummy+13)  /* attached gradient slider  */
#define WHEEL_MaxPens	     (WHEEL_Dummy+14)  /* max # of pens to allocate */
#define WHEEL_KeepAspect     (WHEEL_Dummy+15)  /* OS4ONLY */

/*****************************************************************************/

#endif /* GADGETS_COLORWHEEL_H */
