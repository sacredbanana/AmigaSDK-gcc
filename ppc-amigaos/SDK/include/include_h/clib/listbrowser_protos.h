#ifndef CLIB_LISTBROWSER_PROTOS_H
#define CLIB_LISTBROWSER_PROTOS_H

/*
**    $Id: listbrowser_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef   GADGETS_LISTBROWSER_H
#include <gadgets/listbrowser.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

struct IClass *LISTBROWSER_GetClass( VOID );
struct Node *AllocListBrowserNodeA( const ULONG columns, struct TagItem *tags );
struct Node *AllocListBrowserNode( const ULONG columns, ... );
VOID FreeListBrowserNode( const struct Node *node );
VOID SetListBrowserNodeAttrsA( struct Node *node, const struct TagItem *tags );
VOID SetListBrowserNodeAttrs( struct Node *node, ... );
VOID GetListBrowserNodeAttrsA( const struct Node *node, struct TagItem *tags );
VOID GetListBrowserNodeAttrs( const struct Node *node, ... );
VOID ListBrowserSelectAll( const struct List *list );
VOID ShowListBrowserNodeChildren( const struct Node *node, const LONG depth );
VOID HideListBrowserNodeChildren( const struct Node *node );
VOID ShowAllListBrowserChildren( const struct List *list );
VOID HideAllListBrowserChildren( const struct List *list );
VOID FreeListBrowserList( const struct List *list );
/* Functions in V45 */
struct ColumnInfo *AllocLBColumnInfoA( const ULONG columns, const struct TagItem *tags );
struct ColumnInfo *AllocLBColumnInfo( const ULONG columns, ... );
LONG SetLBColumnInfoAttrsA( struct ColumnInfo *columninfo, const struct TagItem *tags );
LONG SetLBColumnInfoAttrs( struct ColumnInfo *columninfo, ... );
LONG GetLBColumnInfoAttrsA( const struct ColumnInfo *columninfo, struct TagItem *tags );
LONG GetLBColumnInfoAttrs( const struct ColumnInfo *columninfo, ... );
VOID FreeLBColumnInfo( const struct ColumnInfo *columninfo );
VOID ListBrowserClearAll( const struct List *list );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_LISTBROWSER_PROTOS_H */
