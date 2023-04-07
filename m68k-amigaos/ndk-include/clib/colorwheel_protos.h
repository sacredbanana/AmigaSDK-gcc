#ifndef CLIB_COLORWHEEL_PROTOS_H
#define CLIB_COLORWHEEL_PROTOS_H

/*
**	$VER: colorwheel_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  GADGETS_COLORWHEEL_H
#include <gadgets/colorwheel.h>
#endif
/*--- functions in V39 or higher (Release 3.0) ---*/

/* Public entries */

VOID  __stdargs ConvertHSBToRGB( CONST struct ColorWheelHSB *hsb, struct ColorWheelRGB *rgb );
VOID  __stdargs ConvertRGBToHSB( CONST struct ColorWheelRGB *rgb, struct ColorWheelHSB *hsb );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_COLORWHEEL_PROTOS_H */
