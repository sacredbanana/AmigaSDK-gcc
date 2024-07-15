#ifndef CLIB_DATATYPES_PROTOS_H
#define CLIB_DATATYPES_PROTOS_H

/*
**	$VER: datatypes_protos.h 47.1 (30.11.2021)
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
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DATATYPES_DATATYPES_H
#include <datatypes/datatypes.h>
#endif
#ifndef  DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/

/* Public entries */

struct DataType * __stdargs ObtainDataTypeA( ULONG type, APTR handle, CONST struct TagItem *attrs );
struct DataType * __stdargs ObtainDataType( ULONG type, APTR handle, ... );
VOID  __stdargs ReleaseDataType( struct DataType *dt );
Object * __stdargs NewDTObjectA( CONST_STRPTR name, CONST struct TagItem *attrs );
Object * __stdargs NewDTObject( CONST_STRPTR name, ... );
VOID  __stdargs DisposeDTObject( Object *o );
ULONG  __stdargs SetDTAttrsA( Object *o, struct Window *win, struct Requester *req, CONST struct TagItem *attrs );
ULONG  __stdargs SetDTAttrs( Object *o, struct Window *win, struct Requester *req, ... );
ULONG  __stdargs GetDTAttrsA( Object *o, CONST struct TagItem *attrs );
ULONG  __stdargs GetDTAttrs( Object *o, ... );
LONG  __stdargs AddDTObject( struct Window *win, struct Requester *req, Object *o, LONG pos );
VOID  __stdargs RefreshDTObjectA( Object *o, struct Window *win, struct Requester *req, CONST struct TagItem *attrs );
VOID  __stdargs RefreshDTObjects( Object *o, struct Window *win, struct Requester *req, ... );
VOID  __stdargs RefreshDTObject( Object *o, struct Window *win, struct Requester *req, ... );
ULONG  __stdargs DoAsyncLayout( Object *o, struct gpLayout *gpl );
ULONG  __stdargs DoDTMethodA( Object *o, struct Window *win, struct Requester *req, Msg msg );
ULONG  __stdargs DoDTMethod( Object *o, struct Window *win, struct Requester *req, ULONG data, ... );
LONG  __stdargs RemoveDTObject( struct Window *win, Object *o );
ULONG * __stdargs GetDTMethods( CONST Object *object );
struct DTMethods * __stdargs GetDTTriggerMethods( Object *object );
ULONG  __stdargs PrintDTObjectA( Object *o, struct Window *w, struct Requester *r, struct dtPrint *msg );
ULONG  __stdargs PrintDTObject( Object *o, struct Window *w, struct Requester *r, ULONG data, ... );
STRPTR  __stdargs GetDTString( ULONG id );
/*--- functions in V45 or higher ---*/
ULONG * __stdargs FindMethod( CONST ULONG *methods, ULONG searchmethodid );
struct DTMethod * __stdargs FindTriggerMethod( CONST struct DTMethod *dtm, CONST_STRPTR command, ULONG method );
ULONG * __stdargs CopyDTMethods( CONST ULONG *methods, CONST ULONG *include, CONST ULONG *exclude );
struct DTMethod * __stdargs CopyDTTriggerMethods( CONST struct DTMethod *methods, CONST struct DTMethod *include, CONST struct DTMethod *exclude );
VOID * __stdargs FreeDTMethods( APTR methods );
ULONG  __stdargs GetDTTriggerMethodDataFlags( ULONG triggermethod );
ULONG  __stdargs SaveDTObjectA( Object *o, struct Window *win, struct Requester *req, CONST_STRPTR file, ULONG mode, LONG saveicon, struct TagItem *attrs );
ULONG  __stdargs SaveDTObject( Object *o, struct Window *win, struct Requester *req, CONST_STRPTR file, ULONG mode, LONG saveicon, ... );
ULONG  __stdargs StartDragSelect( Object *o );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_DATATYPES_PROTOS_H */
