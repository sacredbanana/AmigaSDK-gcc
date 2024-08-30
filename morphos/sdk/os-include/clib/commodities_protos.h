#ifndef CLIB_COMMODITIES_PROTOS_H
#define CLIB_COMMODITIES_PROTOS_H

/*
	commodities.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef LIBRARIES_COMMODITIES_H
# include <libraries/commodities.h>
#endif

#ifndef DEVICES_INPUTEVENT_H
# include <devices/inputevent.h>
#endif

#ifndef DEVICES_KEYMAP_H
# include <devices/keymap.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CxObj *CreateCxObj( ULONG type, LONG arg1, LONG arg2 );
CxObj *CxBroker( CONST struct NewBroker *nb, LONG *error );
LONG ActivateCxObj( CxObj *co, LONG doIt );
VOID DeleteCxObj( CxObj *co );
VOID DeleteCxObjAll( CxObj *co );
ULONG CxObjType( CONST CxObj *co );
LONG CxObjError( CONST CxObj *co );
VOID ClearCxObjError( CxObj *co );
LONG SetCxObjPri( CxObj *co, LONG pri );

VOID AttachCxObj( CxObj *headObj, CxObj *co );
VOID EnqueueCxObj( CxObj *headObj, CxObj *co );
VOID InsertCxObj( CxObj *headObj, CxObj *co, CxObj *pred );
VOID RemoveCxObj( CxObj *co );

VOID SetTranslate( CxObj *translator, struct InputEvent *events );
VOID SetFilter( CxObj *filter, CONST_STRPTR text );
VOID SetFilterIX( CxObj *filter, CONST IX *ix );
LONG ParseIX( CONST_STRPTR description, IX *ix );

ULONG CxMsgType( CONST CxMsg *cxm );
APTR CxMsgData( CONST CxMsg *cxm );
LONG CxMsgID( CONST CxMsg *cxm );

VOID DivertCxMsg( CxMsg *cxm, CxObj *headObj, CxObj *returnObj );
VOID RouteCxMsg( CxMsg *cxm, CxObj *co );
VOID DisposeCxMsg( CxMsg *cxm );

BOOL InvertKeyMap( ULONG ansiCode, struct InputEvent *event, CONST struct KeyMap *km );
VOID AddIEvents( struct InputEvent *events );
BOOL MatchIX( CONST struct InputEvent *event, CONST IX *ix );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_COMMODITIES_PROTOS_H */
