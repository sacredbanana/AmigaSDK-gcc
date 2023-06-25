#ifndef CLIB_COMMODITIES_PROTOS_H
#define CLIB_COMMODITIES_PROTOS_H

/*
**    $Id: commodities_protos.h,v 1.8 2010-01-31 01:29:02 ssolie Exp $
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
#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef   LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif
#ifndef   DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef   DEVICES_KEYMAP_H
#include <devices/keymap.h>
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

/*--- functions in V36 or higher (Release 2.0) ---*/

/*  OBJECT UTILITIES */

CxObj *CreateCxObj( ULONG type, LONG arg1, LONG arg2 );
CxObj *CxBroker( CONST struct NewBroker *nb, LONG *error );
LONG ActivateCxObj( CxObj *co, LONG doIt );
VOID DeleteCxObj( CxObj *co );
VOID DeleteCxObjAll( CxObj *co );
ULONG CxObjType( CONST CxObj *co );
LONG CxObjError( CONST CxObj *co );
VOID ClearCxObjError( CxObj *co );
LONG SetCxObjPri( CxObj *co, LONG pri );

/*  OBJECT ATTACHMENT */

VOID AttachCxObj( CxObj *headObj, CxObj *co );
VOID EnqueueCxObj( CxObj *headObj, CxObj *co );
VOID InsertCxObj( CxObj *headObj, CxObj *co, CxObj *pred );
VOID RemoveCxObj( CxObj *co );

/*  TYPE SPECIFIC */

VOID SetTranslate( CxObj *translator, struct InputEvent *events );
VOID SetFilter( CxObj *filter, CONST_STRPTR text );
VOID SetFilterIX( CxObj *filter, CONST IX *ix );
LONG ParseIX( CONST_STRPTR description, IX *ix );

/*  COMMON MESSAGE */

ULONG CxMsgType( CONST CxMsg *cxm );
APTR CxMsgData( CONST CxMsg *cxm );
LONG CxMsgID( CONST CxMsg *cxm );

/*  MESSAGE ROUTING */

VOID DivertCxMsg( CxMsg *cxm, CxObj *headObj, CxObj *returnObj );
VOID RouteCxMsg( CxMsg *cxm, CxObj *co );
VOID DisposeCxMsg( CxMsg *cxm );

/*  INPUT EVENT HANDLING */

BOOL InvertKeyMap( ULONG ansiCode, struct InputEvent *event, CONST struct KeyMap *km );
VOID AddIEvents( struct InputEvent *events );
/*--- functions in V38 or higher (Release 2.1) ---*/
/*  MORE INPUT EVENT HANDLING */
BOOL MatchIX( CONST struct InputEvent *event, CONST IX *ix );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_COMMODITIES_PROTOS_H */
