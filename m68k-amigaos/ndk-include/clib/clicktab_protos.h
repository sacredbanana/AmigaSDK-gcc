#ifndef CLIB_CLICKTAB_PROTOS_H
#define CLIB_CLICKTAB_PROTOS_H

/*
**	$VER: clicktab_protos.h 47.1 (30.11.2021)
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
#ifndef  GADGETS_CLICKTAB_H
#include <gadgets/clicktab.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs CLICKTAB_GetClass( VOID );
struct Node * __stdargs AllocClickTabNodeA( struct TagItem *tags );
struct Node * __stdargs AllocClickTabNode( Tag firstTag, ... );
VOID  __stdargs FreeClickTabNode( struct Node *node );
VOID  __stdargs SetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetClickTabNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetClickTabNodeAttrs( struct Node *node, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_CLICKTAB_PROTOS_H */
