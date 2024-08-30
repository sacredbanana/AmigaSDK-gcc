#ifndef GADGETS_GETCOLOR_H
#define GADGETS_GETCOLOR_H
/*
**	$VER: getcolor.h 47.1 (3.3.2020)
**	Includes Release 47.1
**
**	Definitions for the getcolor.gadget BOOPSI class
**
**	Copyright (C) 2020 Hyperion Entertainment CVBA.
**	    All Rights Reserved.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

/* Attributes defined by the getcolor.gadget class
 */
#define GETCOLOR_Dummy         (REACTION_Dummy + 0x43000)

#define GETCOLOR_TitleText     (GETCOLOR_Dummy+1)
    /* (STRPTR) Title of the color requester (default: None) (OM_NEW, OM_SET) */

#define GETCOLOR_Screen        (GETCOLOR_Dummy+2)
    /* (struct Screen *) Screen for pen allocation (default: None) (OM_NEW, OM_SET, OM_GET) */

#define GETCOLOR_Color         (GETCOLOR_Dummy+3)
    /* (ULONG) Currently selected color (default: 0 (black)) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_Red           (GETCOLOR_Dummy+4)
    /* (ULONG) Red component of current color (default: 0) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_Green         (GETCOLOR_Dummy+5)
    /* (ULONG) Green component of current color (default: 0) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_Blue          (GETCOLOR_Dummy+6)
    /* (ULONG) Blue component of current color (default: 0) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_Hue           (GETCOLOR_Dummy+7)
    /* (ULONG) Hue value of current color (default: 0) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_Saturation    (GETCOLOR_Dummy+8)
    /* (ULONG) Saturation value of current color (default: 0) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_Brightness    (GETCOLOR_Dummy+9)
    /* (ULONG) Brightness value of current color (default: 0) (OM_NEW, OM_SET, OM_GET, OM_NOTIFY) */

#define GETCOLOR_RGB           (GETCOLOR_Dummy+10)
    /* (struct ColorWheelRGB *) RGB components of current color (default: 0/0/0) (OM_NEW, OM_SET, OM_GET) */

#define GETCOLOR_HSB           (GETCOLOR_Dummy+11)
    /* (struct ColorWheelHSB *) HSB values of current color (default: 0/0/0) (OM_NEW, OM_SET, OM_GET) */

#define GETCOLOR_ColorWheel    (GETCOLOR_Dummy+12)
    /* (BOOL) Display a color wheel and a gradient slider? (default: TRUE) (OM_NEW, OM_SET) */

#define GETCOLOR_RGBSliders    (GETCOLOR_Dummy+13)
    /* (BOOL) Display red/green/blue sliders? (default: TRUE) (OM_NEW, OM_SET) */

#define GETCOLOR_HSBSliders    (GETCOLOR_Dummy+14)
    /* (BOOL) Display hue/saturation/brightness sliders? (default: TRUE) (OM_NEW, OM_SET) */

#define GETCOLOR_SwitchMode    (GETCOLOR_Dummy+15)
    /* (BOOL) Allow user to switch between RGB and HSB sliders? (default: TRUE) (OM_NEW, OM_SET) */

#define GETCOLOR_Initial       (GETCOLOR_Dummy+16)
    /* (UWORD) If SwitchMode is on, initial slider set to display (0 == RGB, 1 == HSB) (default: 0) (OM_NEW, OM_SET) */

#define GETCOLOR_ShowRGB       (GETCOLOR_Dummy+17)
    /* (BOOL) Display red/green/blue value indicators? (default: FALSE) (OM_NEW, OM_SET) */

#define GETCOLOR_ShowHSB       (GETCOLOR_Dummy+18)
    /* (BOOL) Display hue/saturation/brightness value indicators? (default: FALSE) (OM_NEW, OM_SET) */

#define GETCOLOR_SmallTextAttr (GETCOLOR_Dummy+19)
    /* (struct TextAttr *) Font for the RGB/HSB indicators (default: ReAction fallback font) (OM_NEW, OM_SET) */

/*****************************************************************************/

/*
 * getcolor.gadget methods
 */
#define GCOLOR_REQUEST (0x630001L)

/* The GCOLOR_REQUEST method should be called whenever you want to open
 * a color requester.
 */

struct gcRequest
{
    ULONG           MethodID;   /* GCOLOR_REQUEST */
    struct Window * gcr_Window; /* The window that will be locked when
                                   the requester is active.
                                   MUST be provided! */
};

/* Macro for calling the method easily */

#define RequestColor(obj, win) DoMethod(obj, GCOLOR_REQUEST, win)

/* ReAction synonym for End which can make layout groups easier to follow */

#ifndef GetColorEnd
#define GetColorEnd TAG_END)
#endif

#endif /* GADGETS_GETCOLOR_H */
