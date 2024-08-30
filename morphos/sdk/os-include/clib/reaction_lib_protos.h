#ifndef CLIB_REACTION_LIB_PROTOS_H
#define CLIB_REACTION_LIB_PROTOS_H

/*
	reaction.lib C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct List *ChooserLabelsA( STRPTR * );
#if !defined(USE_INLINE_STDARG)
struct List *ChooserLabels( STRPTR, ... );
#endif
void FreeChooserLabels( struct List * );
struct List *RadioButtonsA( STRPTR * );
#if !defined(USE_INLINE_STDARG)
struct List *RadioButtons( STRPTR, ... );
#endif
void FreeRadioButtons( struct List * );
struct Window *OpenLayoutWindowTagList( struct Gadget *, struct Screen *, struct TagItem * );
#if !defined(USE_INLINE_STDARG)
struct Window *OpenLayoutWindowTags( struct Gadget *, struct Screen *, Tag, ... );
#endif
UWORD GetCode( struct IntuiMessage * );
struct ClassLibrary *OpenClass(STRPTR, ULONG);
STRPTR OpenLibs(APTR);
void CloseLibs(APTR);
ULONG LibDoGadgetMethodA( struct Gadget *, struct Window *, struct Requester *, Msg );
#if !defined(USE_INLINE_STDARG)
ULONG LibDoGadgetMethod( struct Gadget *, struct Window *, struct Requester *, Tag, ... );
#endif
ULONG GetAttrsA( Object *o, struct TagItem *t );
#if !defined(USE_INLINE_STDARG)
ULONG GetAttrs( Object *o, Tag t, ... );
#endif
struct List *BrowserNodesA( STRPTR * );
#if !defined(USE_INLINE_STDARG)
struct List *BrowserNodes( STRPTR, ... );
#endif
void FreeBrowserNodes( struct List * );
struct List *ClickTabsA( STRPTR * );
#if !defined(USE_INLINE_STDARG)
struct List *ClickTabs( STRPTR, ... );
#endif
void FreeClickTabs( struct List * );
struct Node *LBAddNodeA( struct Gadget *, struct Window *, struct Requester *, struct Node *, struct TagItem * );
ULONG LBEditNodeA( struct Gadget *, struct Window *, struct Requester *, struct Node *, struct TagItem * );
#if !defined(USE_INLINE_STDARG)
struct Node *LBAddNode( struct Gadget *lb, struct Window *w, struct Requester *r, struct Node *n, ULONG tag, ... );
#endif
#if !defined(USE_INLINE_STDARG)
ULONG LBEditNode( struct Gadget *lb, struct Window *w, struct Requester *r, struct Node *n, ULONG tag, ... );
#endif
ULONG LBRemNode( struct Gadget *, struct Window *, struct Requester *, struct Node * );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_REACTION_LIB_PROTOS_H */
