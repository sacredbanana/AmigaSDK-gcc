#ifndef CLIB_SKETCHBOARD_PROTOS_H
#define CLIB_SKETCHBOARD_PROTOS_H

/*
**	$VER: sketchboard_protos.h 47.1 (30.11.2021)
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
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  GADGETS_SKETCHBOARD_H
#include <gadgets/sketchboard.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs SKETCHBOARD_GetClass( VOID );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_SKETCHBOARD_PROTOS_H */
