#ifndef GADGETS_GRADIENTSLIDER_H
#define GADGETS_GRADIENTSLIDER_H
/*
**	$VER: gradientslider.h 47.1 (30.7.2019)
**
**	Definitions for the gradientslider BOOPSI class
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**
*/

/*****************************************************************************/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*****************************************************************************/

#define GRAD_Dummy	 (TAG_USER+0x05000000)
#define GRAD_MaxVal	 (GRAD_Dummy+1)     /* max value of slider	   */
#define GRAD_CurVal	 (GRAD_Dummy+2)     /* current value of slider	   */
#define GRAD_SkipVal	 (GRAD_Dummy+3)     /* "body click" move amount    */
#define GRAD_KnobPixels  (GRAD_Dummy+4)     /* size of knob in pixels	   */
#define GRAD_PenArray	 (GRAD_Dummy+5)     /* pen colors		   */

/*****************************************************************************/

#endif /* GADGETS_GRADIENTSLIDER_H */
