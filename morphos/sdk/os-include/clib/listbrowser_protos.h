#ifndef CLIB_LISTBROWSER_PROTOS_H
#define CLIB_LISTBROWSER_PROTOS_H

/*
	listbrowser.gadget C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef GADGETS_LISTBROWSER_H
# include <gadgets/listbrowser.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct IClass *LISTBROWSER_GetClass( VOID );
struct Node *AllocListBrowserNodeA( ULONG columns, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Node *AllocListBrowserNode( ULONG columns, ... );
#endif
VOID FreeListBrowserNode( struct Node *node );
VOID SetListBrowserNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID SetListBrowserNodeAttrs( struct Node *node, ... );
#endif
VOID GetListBrowserNodeAttrsA( struct Node *node, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
VOID GetListBrowserNodeAttrs( struct Node *node, ... );
#endif
VOID ListBrowserSelectAll( struct List *list );
VOID ShowListBrowserNodeChildren( struct Node *node, LONG depth );
VOID HideListBrowserNodeChildren( struct Node *node );
VOID ShowAllListBrowserChildren( struct List *list );
VOID HideAllListBrowserChildren( struct List *list );
VOID FreeListBrowserList( struct List *list );

/*** V45 ***/
struct ColumnInfo *AllocLBColumnInfoA( ULONG columns, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct ColumnInfo *AllocLBColumnInfo( ULONG columns, ... );
#endif
LONG SetLBColumnInfoAttrsA( struct ColumnInfo *columninfo, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG SetLBColumnInfoAttrs( struct ColumnInfo *columninfo, ... );
#endif
LONG GetLBColumnInfoAttrsA( struct ColumnInfo *columninfo, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG GetLBColumnInfoAttrs( struct ColumnInfo *columninfo, ... );
#endif
VOID FreeLBColumnInfo( struct ColumnInfo *columninfo );
VOID ListBrowserClearAll( struct List *list );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_LISTBROWSER_PROTOS_H */
