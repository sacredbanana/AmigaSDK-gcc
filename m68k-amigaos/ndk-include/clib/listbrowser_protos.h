#ifndef CLIB_LISTBROWSER_PROTOS_H
#define CLIB_LISTBROWSER_PROTOS_H

/*
**	$VER: listbrowser_protos.h 47.1 (30.11.2021)
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
#ifndef  GADGETS_LISTBROWSER_H
#include <gadgets/listbrowser.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/
Class * __stdargs LISTBROWSER_GetClass( VOID );
struct Node * __stdargs AllocListBrowserNodeA( ULONG columns, struct TagItem *tags );
struct Node * __stdargs AllocListBrowserNode( ULONG columns, ... );
VOID  __stdargs FreeListBrowserNode( struct Node *node );
VOID  __stdargs SetListBrowserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetListBrowserNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetListBrowserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetListBrowserNodeAttrs( struct Node *node, ... );
VOID  __stdargs ListBrowserSelectAll( struct List *list );
VOID  __stdargs ShowListBrowserNodeChildren( struct Node *node, LONG depth );
VOID  __stdargs HideListBrowserNodeChildren( struct Node *node );
VOID  __stdargs ShowAllListBrowserChildren( struct List *list );
VOID  __stdargs HideAllListBrowserChildren( struct List *list );
VOID  __stdargs FreeListBrowserList( struct List *list );
/*--- functions in V45 or higher (Release 3.9) ---*/
struct ColumnInfo * __stdargs AllocLBColumnInfoA( ULONG columns, struct TagItem *tags );
struct ColumnInfo * __stdargs AllocLBColumnInfo( ULONG columns, ... );
LONG  __stdargs SetLBColumnInfoAttrsA( struct ColumnInfo *columninfo, struct TagItem *tags );
LONG  __stdargs SetLBColumnInfoAttrs( struct ColumnInfo *columninfo, ... );
LONG  __stdargs GetLBColumnInfoAttrsA( struct ColumnInfo *columninfo, struct TagItem *tags );
LONG  __stdargs GetLBColumnInfoAttrs( struct ColumnInfo *columninfo, ... );
VOID  __stdargs FreeLBColumnInfo( struct ColumnInfo *columninfo );
VOID  __stdargs ListBrowserClearAll( struct List *list );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LISTBROWSER_PROTOS_H */
