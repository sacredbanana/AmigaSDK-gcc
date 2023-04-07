#ifndef CLIB_PENMAP_PROTOS_H
#define CLIB_PENMAP_PROTOS_H

/*
**	$VER: penmap_protos.h 47.1 (30.11.2021)
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
#ifndef  IMAGES_PENMAP_H
#include <images/penmap.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs PENMAP_GetClass( VOID );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_PENMAP_PROTOS_H */
