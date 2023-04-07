#ifndef CLIB_REACTION_LIB_PROTOS_H
#define CLIB_REACTION_LIB_PROTOS_H

/*
**	$VER: reaction_lib_protos.h 47.1 (29.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_NODES_H
#include <exec/nodes.h>
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
struct Node * __stdargs LBAddNodeA( struct Gadget *gad, struct Window *win, struct Requester *req, struct Node *node, CONST struct TagItem *tags );
struct Node * __stdargs LBAddNode( struct Gadget *gad, struct Window *win, struct Requester *req, struct Node *node, ... );
ULONG  __stdargs LBEditNodeA( struct Gadget *gad, struct Window *win, struct Requester *req, struct Node *node, CONST struct TagItem *tags );
ULONG  __stdargs LBEditNode( struct Gadget *gad, struct Window *win, struct Requester *req, struct Node *node, ... );
ULONG  __stdargs LBRemNode( struct Gadget *gad, struct Window *win, struct Requester *req, struct Node *node );
struct List * __stdargs ClickTabsA( STRPTR *text_array );
struct List * __stdargs ClickTabs( STRPTR first_text, ... );
VOID  __stdargs FreeClickTabs( struct List *list );
struct List * __stdargs BrowserNodesA( STRPTR *text_array );
struct List * __stdargs BrowserNodes( STRPTR first_text, ... );
VOID  __stdargs FreeBrowserNodes( struct List *list );
struct List * __stdargs ChooserLabelsA( STRPTR *text_array );
struct List * __stdargs ChooserLabels( STRPTR first_text, ... );
VOID  __stdargs FreeChooserLabels( struct List *list );
struct List * __stdargs RadioButtonsA( STRPTR *text_array );
struct List * __stdargs RadioButtons( STRPTR first_text, ... );
VOID  __stdargs FreeRadioButtons( struct List *list );
ULONG  __stdargs GetAttrsA( Object *o, CONST struct TagItem *tags );
ULONG  __stdargs GetAttrs( Object *o, ... );
UWORD  __stdargs GetCode( CONST struct IntuiMessage *imsg );
ULONG  __stdargs LibDoGadgetMethodA( struct Gadget *gadget, struct Window *window, struct Requester *requester, Msg message );
ULONG  __stdargs LibDoGadgetMethod( struct Gadget *gadget, struct Window *window, struct Requester *requester, ... );
struct Window * __stdargs OpenLayoutWindowTagList( struct Gadget *layout, struct Screen *screen, CONST struct TagItem *tags );
struct Window * __stdargs OpenLayoutWindowTags( struct Gadget *layout, struct Screen *screen, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_REACTION_LIB_PROTOS_H */
