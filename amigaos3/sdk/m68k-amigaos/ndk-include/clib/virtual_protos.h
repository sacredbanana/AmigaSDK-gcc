#ifndef CLIB_VIRTUAL_PROTOS_H
#define CLIB_VIRTUAL_PROTOS_H

/*
**	$VER: virtual_protos.h 47.1 (30.11.2021)
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
#ifndef  GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif
#ifndef  GADGETS_VIRTUAL_H
#include <gadgets/virtual.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs VIRTUAL_GetClass( VOID );
VOID  __stdargs RefreshVirtualGadget( struct Gadget *gadget, Object *obj, struct Window *window, struct Requester *requester );
BOOL  __stdargs RethinkVirtualSize( Object *virt_obj, Object *rootlayout, struct TextFont *font, struct Screen *screen, struct LayoutLimits *layoutlimits );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_VIRTUAL_PROTOS_H */
