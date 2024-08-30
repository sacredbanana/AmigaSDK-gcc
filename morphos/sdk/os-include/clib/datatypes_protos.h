#ifndef CLIB_DATATYPES_PROTOS_H
#define CLIB_DATATYPES_PROTOS_H

/*
	datatypes.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DATATYPES_DATATYPESCLASS_H
# include <datatypes/datatypesclass.h>
#endif

#ifndef DATATYPES_DATATYPES_H
# include <datatypes/datatypes.h>
#endif

#ifndef REXX_STORAGE_H
# include <rexx/storage.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct DataType *ObtainDataTypeA( ULONG type, APTR handle, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
struct DataType *ObtainDataType( ULONG type, APTR handle, Tag tag1, ... );
#endif
VOID ReleaseDataType( struct DataType *dt );
Object *NewDTObjectA( APTR name, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
Object *NewDTObject( APTR name, Tag tag1, ... );
#endif
VOID DisposeDTObject( Object *o );
ULONG SetDTAttrsA( Object *o, struct Window *win, struct Requester *req, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
ULONG SetDTAttrs( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
#endif
ULONG GetDTAttrsA( Object *o, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
ULONG GetDTAttrs( Object *o, Tag tag1, ... );
#endif
LONG AddDTObject( struct Window *win, struct Requester *req, Object *o, LONG pos );
VOID RefreshDTObjectA( Object *o, struct Window *win, struct Requester *req, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
VOID RefreshDTObjects( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
#endif
#if !defined(USE_INLINE_STDARG)
VOID RefreshDTObject( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
#endif
ULONG DoAsyncLayout( Object *o, struct gpLayout *gpl );
ULONG DoDTMethodA( Object *o, struct Window *win, struct Requester *req, Msg msg );
#if !defined(USE_INLINE_STDARG)
ULONG DoDTMethod( Object *o, struct Window *win, struct Requester *req, ULONG data, ... );
#endif
LONG RemoveDTObject( struct Window *win, Object *o );
ULONG *GetDTMethods( Object *object );
struct DTMethods *GetDTTriggerMethods( Object *object );
ULONG PrintDTObjectA( Object *o, struct Window *w, struct Requester *r, struct dtPrint *msg );
#if !defined(USE_INLINE_STDARG)
ULONG PrintDTObject( Object *o, struct Window *w, struct Requester *r, ULONG data, ... );
#endif
APTR ObtainDTDrawInfoA( Object *o, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
APTR ObtainDTDrawInfo( Object *o, Tag tag1, ... );
#endif
LONG DrawDTObjectA( struct RastPort *rp, Object *o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
LONG DrawDTObject( struct RastPort *rp, Object *o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, Tag tag1, ... );
#endif
VOID ReleaseDTDrawInfo( Object *o, APTR handle );
STRPTR GetDTString( ULONG id );


/*
 * functions in V45 or higher
 */
void             LockDataType( struct DataType * );
struct ToolNode *FindToolNodeA( struct List *, struct TagItem * );
#if !defined(USE_INLINE_STDARG)
struct ToolNode *FindToolNode( struct List *, Tag, ... );
#endif
ULONG            LaunchToolA( struct Tool *, STRPTR, struct TagItem * );
#if !defined(USE_INLINE_STDARG)
ULONG            LaunchTool( struct Tool *, STRPTR, Tag, ... );
#endif
ULONG           *FindMethod( ULONG *, ULONG );
struct DTMethod *FindTriggerMethod( struct DTMethod *, STRPTR, ULONG );
ULONG           *CopyDTMethods( ULONG *, ULONG *, ULONG * );
struct DTMethod *CopyDTTriggerMethods( struct DTMethod *, struct DTMethod *, struct DTMethod * );
VOID             FreeDTMethods( APTR );
ULONG            GetDTTriggerMethodDataFlags( ULONG );
ULONG            SaveDTObjectA( Object *, struct Window *, struct Requester *, STRPTR, ULONG, BOOL, struct TagItem * );
#if !defined(USE_INLINE_STDARG)
ULONG            SaveDTObject( Object *, struct Window *, struct Requester *, STRPTR, ULONG, BOOL, Tag, ... );
#endif
ULONG            StartDragSelect( Object * );
ULONG            DoDTDomainA( Object *, struct Window *, struct Requester *, struct RastPort *, ULONG, struct IBox *, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
ULONG            DoDTDomain( Object *, struct Window *, struct Requester *, struct RastPort *, ULONG, struct IBox *, Tag, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_DATATYPES_PROTOS_H */
