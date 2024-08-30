#ifndef GADGETS_GRADIENTSLIDER_H
#define GADGETS_GRADIENTSLIDER_H

/*
	gradientslider.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


/* Attributes defined by gradientslider.gadget */

#define GRAD_Dummy       (TAG_USER + 0x05000000)
#define GRAD_MaxVal      (GRAD_Dummy + 1)
#define GRAD_CurVal      (GRAD_Dummy + 2)
#define GRAD_SkipVal     (GRAD_Dummy + 3)
#define GRAD_KnobPixels  (GRAD_Dummy + 4)
#define GRAD_PenArray    (GRAD_Dummy + 5)


#endif /* GADGETS_GRADIENTSLIDER_H */
