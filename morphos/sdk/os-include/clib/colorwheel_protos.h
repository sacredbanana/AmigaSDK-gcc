#ifndef CLIB_COLORWHEEL_PROTOS_H
#define CLIB_COLORWHEEL_PROTOS_H

/*
	colorwheel.gadget C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef GADGETS_COLORWHEEL_H
# include <gadgets/colorwheel.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID ConvertHSBToRGB( struct ColorWheelHSB *hsb, struct ColorWheelRGB *rgb );
VOID ConvertRGBToHSB( struct ColorWheelRGB *rgb, struct ColorWheelHSB *hsb );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_COLORWHEEL_PROTOS_H */
