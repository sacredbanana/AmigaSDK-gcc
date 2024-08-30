#ifndef CLIB_DATATYPES_PROTOS_H
#define CLIB_DATATYPES_PROTOS_H

/*
**    $Id: datatypes_protos.h,v 1.10 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef   INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef   DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
#endif
#ifndef   DATATYPES_DATATYPES_H
#include <datatypes/datatypes.h>
#endif
#ifndef   REXX_STORAGE_H
#include <rexx/storage.h>
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

/*--- functions in V40 or higher (Release 3.1) ---*/

/* Public entries */

struct DataType *ObtainDataTypeA( ULONG type, APTR handle, CONST struct TagItem *attrs );
struct DataType *ObtainDataType( ULONG type, APTR handle, Tag tag1, ... );
VOID ReleaseDataType( struct DataType *dt );
Object *NewDTObjectA( CONST_STRPTR name, CONST struct TagItem *attrs );
Object *NewDTObject( CONST_STRPTR name, Tag tag1, ... );
VOID DisposeDTObject( Object *o );
ULONG SetDTAttrsA( Object *o, struct Window *win, struct Requester *req, CONST struct TagItem *attrs );
ULONG SetDTAttrs( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
ULONG GetDTAttrsA( Object *o, CONST struct TagItem *attrs );
ULONG GetDTAttrs( Object *o, Tag tag1, ... );
LONG AddDTObject( struct Window *win, struct Requester *req, Object *o, LONG pos );
VOID RefreshDTObjectA( Object *o, struct Window *win, struct Requester *req, CONST struct TagItem *attrs );
VOID RefreshDTObjects( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
VOID RefreshDTObject( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
ULONG DoAsyncLayout( Object *o, struct gpLayout *gpl );
ULONG DoDTMethodA( Object *o, struct Window *win, struct Requester *req, Msg msg );
ULONG DoDTMethod( Object *o, struct Window *win, struct Requester *req, ULONG data, ... );
LONG RemoveDTObject( struct Window *win, Object *o );
ULONG *GetDTMethods( Object *object );
struct DTMethods *GetDTTriggerMethods( Object *object );
ULONG PrintDTObjectA( Object *o, struct Window *w, struct Requester *r, struct dtPrint *msg );
ULONG PrintDTObject( Object *o, struct Window *w, struct Requester *r, ULONG data, ... );
APTR ObtainDTDrawInfoA( Object *o, CONST struct TagItem *attrs );
APTR ObtainDTDrawInfo( Object *o, Tag tag1, ... );
LONG DrawDTObjectA( struct RastPort *rp, Object *o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, CONST struct TagItem *attrs );
LONG DrawDTObject( struct RastPort *rp, Object *o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, Tag tag1, ... );
VOID ReleaseDTDrawInfo( Object *o, APTR handle );
CONST_STRPTR GetDTString( ULONG id );
/*--- functions in V45 or higher (3rd party release) ---*/
ULONG *FindMethod( ULONG *methods, ULONG searchmethodid );
struct DTMethod *FindTriggerMethod( struct DTMethod *dtm, CONST_STRPTR command, ULONG method );
ULONG *CopyDTMethods( ULONG *methods, ULONG *include, ULONG *exclude );
struct DTMethod *CopyDTTriggerMethods( struct DTMethod *methods, struct DTMethod *include, struct DTMethod *exclude );
VOID *FreeDTMethods( APTR methods );
ULONG SaveDTObjectA( Object *o, struct Window *win, struct Requester *req, CONST_STRPTR file, ULONG mode, LONG saveicon, CONST struct TagItem *attrs );
ULONG StartDragSelect( Object *o );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_DATATYPES_PROTOS_H */
