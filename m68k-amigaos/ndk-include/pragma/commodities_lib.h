#ifndef PRAGMA_COMMODITIES_LIB_H
#define PRAGMA_COMMODITIES_LIB_H

/*
**	$VER: commodities_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_COMMODITIES_PROTOS_H
#include <clib/commodities_protos.h>
#endif /* CLIB_COMMODITIES_PROTOS_H */

/* "commodities.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/

/*  OBJECT UTILITIES */

#pragma amicall(CxBase, 0x1e, CreateCxObj(d0,a0,a1))
#pragma amicall(CxBase, 0x24, CxBroker(a0,d0))
#pragma amicall(CxBase, 0x2a, ActivateCxObj(a0,d0))
#pragma amicall(CxBase, 0x30, DeleteCxObj(a0))
#pragma amicall(CxBase, 0x36, DeleteCxObjAll(a0))
#pragma amicall(CxBase, 0x3c, CxObjType(a0))
#pragma amicall(CxBase, 0x42, CxObjError(a0))
#pragma amicall(CxBase, 0x48, ClearCxObjError(a0))
#pragma amicall(CxBase, 0x4e, SetCxObjPri(a0,d0))

/*  OBJECT ATTACHMENT */

#pragma amicall(CxBase, 0x54, AttachCxObj(a0,a1))
#pragma amicall(CxBase, 0x5a, EnqueueCxObj(a0,a1))
#pragma amicall(CxBase, 0x60, InsertCxObj(a0,a1,a2))
#pragma amicall(CxBase, 0x66, RemoveCxObj(a0))

/*  TYPE SPECIFIC */

#pragma amicall(CxBase, 0x72, SetTranslate(a0,a1))
#pragma amicall(CxBase, 0x78, SetFilter(a0,a1))
#pragma amicall(CxBase, 0x7e, SetFilterIX(a0,a1))
#pragma amicall(CxBase, 0x84, ParseIX(a0,a1))

/*  COMMON MESSAGE */

#pragma amicall(CxBase, 0x8a, CxMsgType(a0))
#pragma amicall(CxBase, 0x90, CxMsgData(a0))
#pragma amicall(CxBase, 0x96, CxMsgID(a0))

/*  MESSAGE ROUTING */

#pragma amicall(CxBase, 0x9c, DivertCxMsg(a0,a1,a2))
#pragma amicall(CxBase, 0xa2, RouteCxMsg(a0,a1))
#pragma amicall(CxBase, 0xa8, DisposeCxMsg(a0))

/*  INPUT EVENT HANDLING */

#pragma amicall(CxBase, 0xae, InvertKeyMap(d0,a0,a1))
#pragma amicall(CxBase, 0xb4, AddIEvents(a0))

/* FOR USE ONLY BY CONTROLLER PROGRAM */

/*--- functions in V38 or higher (Release 2.1) ---*/
/*  MORE INPUT EVENT HANDLING */
#pragma amicall(CxBase, 0xcc, MatchIX(a0,a1))

/* Reserved entries */


#endif /* PRAGMA_COMMODITIES_LIB_H */
