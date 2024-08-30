#ifndef CLIB_CHOOSER_PROTOS_H
#define CLIB_CHOOSER_PROTOS_H

/*
**	$VER: chooser_protos.h 47.1 (30.11.2021)
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
#ifndef  GADGETS_CHOOSER_H
#include <gadgets/chooser.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs CHOOSER_GetClass( VOID );
struct Node * __stdargs AllocChooserNodeA( struct TagItem *tags );
struct Node * __stdargs AllocChooserNode( Tag firstTag, ... );
VOID  __stdargs FreeChooserNode( struct Node *node );
VOID  __stdargs SetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetChooserNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetChooserNodeAttrs( struct Node *node, ... );
ULONG  __stdargs ShowChooser( Object *o, struct Window *w, ULONG xpos, ULONG ypos );
VOID  __stdargs HideChooser( Object *o, struct Window *w );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_CHOOSER_PROTOS_H */
