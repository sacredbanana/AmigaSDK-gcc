#ifndef CLIB_SPEEDBAR_PROTOS_H
#define CLIB_SPEEDBAR_PROTOS_H

/*
**	$VER: speedbar_protos.h 47.1 (30.11.2021)
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
#ifndef  GADGETS_SPEEDBAR_H
#include <gadgets/speedbar.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs SPEEDBAR_GetClass( VOID );
struct Node * __stdargs AllocSpeedButtonNodeA( ULONG number, struct TagItem *tags );
struct Node * __stdargs AllocSpeedButtonNode( ULONG number, ... );
VOID  __stdargs FreeSpeedButtonNode( struct Node *node );
VOID  __stdargs SetSpeedButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetSpeedButtonNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetSpeedButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetSpeedButtonNodeAttrs( struct Node *node, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_SPEEDBAR_PROTOS_H */
