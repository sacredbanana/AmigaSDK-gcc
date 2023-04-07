#ifndef CLIB_RADIOBUTTON_PROTOS_H
#define CLIB_RADIOBUTTON_PROTOS_H

/*
**	$VER: radiobutton_protos.h 47.1 (30.11.2021)
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
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  GADGETS_RADIOBUTTON_H
#include <gadgets/radiobutton.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs RADIOBUTTON_GetClass( VOID );
struct Node * __stdargs AllocRadioButtonNodeA( ULONG columns, struct TagItem *tags );
struct Node * __stdargs AllocRadioButtonNode( ULONG columns, ... );
VOID  __stdargs FreeRadioButtonNode( struct Node *node );
VOID  __stdargs SetRadioButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetRadioButtonNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetRadioButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetRadioButtonNodeAttrs( struct Node *node, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_RADIOBUTTON_PROTOS_H */
