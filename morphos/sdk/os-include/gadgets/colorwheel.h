#ifndef GADGETS_COLORWHEEL_H
#define GADGETS_COLORWHEEL_H

/*
	colorwheel.gadget definitions (V45)

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


struct ColorWheelHSB
{
	ULONG cw_Hue;
	ULONG cw_Saturation;
	ULONG cw_Brightness;
};

struct ColorWheelRGB
{
	ULONG cw_Red;
	ULONG cw_Green;
	ULONG cw_Blue;
};


/* Attributes defined by colorwheel.gadget */

#define WHEEL_Dummy           (TAG_USER + 0x04000000)
#define WHEEL_Hue             (WHEEL_Dummy + 1)
#define WHEEL_Saturation      (WHEEL_Dummy + 2)
#define WHEEL_Brightness      (WHEEL_Dummy + 3)
#define WHEEL_HSB             (WHEEL_Dummy + 4)
#define WHEEL_Red             (WHEEL_Dummy + 5)
#define WHEEL_Green           (WHEEL_Dummy + 6)
#define WHEEL_Blue            (WHEEL_Dummy + 7)
#define WHEEL_RGB             (WHEEL_Dummy + 8)
#define WHEEL_Screen          (WHEEL_Dummy + 9)
#define WHEEL_Abbrv           (WHEEL_Dummy + 10)
#define WHEEL_Donation        (WHEEL_Dummy + 11)
#define WHEEL_BevelBox        (WHEEL_Dummy + 12)
#define WHEEL_GradientSlider  (WHEEL_Dummy + 13)
#define WHEEL_MaxPens         (WHEEL_Dummy + 14)


#pragma pack()

#endif /* GADGETS_COLORWHEEL_H */
