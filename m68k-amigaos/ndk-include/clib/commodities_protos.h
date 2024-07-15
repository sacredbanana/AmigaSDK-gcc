#ifndef CLIB_COMMODITIES_PROTOS_H
#define CLIB_COMMODITIES_PROTOS_H

/*
**	$VER: commodities_protos.h 47.1 (30.11.2021)
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
#ifndef  EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef  LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif
#ifndef  DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef  DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif
/*--- functions in V36 or higher (Release 2.0) ---*/

/*  OBJECT UTILITIES */

CxObj * __stdargs CreateCxObj( ULONG type, LONG arg1, LONG arg2 );
CxObj * __stdargs CxBroker( CONST struct NewBroker *nb, LONG *error );
LONG  __stdargs ActivateCxObj( CxObj *co, LONG flag );
VOID  __stdargs DeleteCxObj( CxObj *co );
VOID  __stdargs DeleteCxObjAll( CxObj *co );
ULONG  __stdargs CxObjType( CONST CxObj *co );
LONG  __stdargs CxObjError( CONST CxObj *co );
VOID  __stdargs ClearCxObjError( CxObj *co );
LONG  __stdargs SetCxObjPri( CxObj *co, LONG pri );

/*  OBJECT ATTACHMENT */

VOID  __stdargs AttachCxObj( CxObj *headObj, CxObj *co );
VOID  __stdargs EnqueueCxObj( CxObj *headObj, CxObj *co );
VOID  __stdargs InsertCxObj( CxObj *headObj, CxObj *co, CxObj *pred );
VOID  __stdargs RemoveCxObj( CxObj *co );

/*  TYPE SPECIFIC */

VOID  __stdargs SetTranslate( CxObj *translator, struct InputEvent *events );
VOID  __stdargs SetFilter( CxObj *filter, CONST_STRPTR text );
VOID  __stdargs SetFilterIX( CxObj *filter, CONST IX *ix );
LONG  __stdargs ParseIX( CONST_STRPTR description, IX *ix );

/*  COMMON MESSAGE */

ULONG  __stdargs CxMsgType( CONST CxMsg *cxm );
APTR  __stdargs CxMsgData( CONST CxMsg *cxm );
LONG  __stdargs CxMsgID( CONST CxMsg *cxm );

/*  MESSAGE ROUTING */

VOID  __stdargs DivertCxMsg( CxMsg *cxm, CxObj *headObj, CxObj *returnObj );
VOID  __stdargs RouteCxMsg( CxMsg *cxm, CxObj *co );
VOID  __stdargs DisposeCxMsg( CxMsg *cxm );

/*  INPUT EVENT HANDLING */

BOOL  __stdargs InvertKeyMap( ULONG ansiCode, struct InputEvent *event, CONST struct KeyMap *km );
VOID  __stdargs AddIEvents( struct InputEvent *events );
/*--- functions in V38 or higher (Release 2.1) ---*/
/*  MORE INPUT EVENT HANDLING */
BOOL  __stdargs MatchIX( CONST struct InputEvent *event, CONST IX *ix );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_COMMODITIES_PROTOS_H */
