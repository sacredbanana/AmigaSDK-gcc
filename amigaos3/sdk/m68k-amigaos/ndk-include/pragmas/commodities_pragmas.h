#ifndef PRAGMAS_COMMODITIES_PRAGMAS_H
#define PRAGMAS_COMMODITIES_PRAGMAS_H

/*
**	$VER: commodities_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_COMMODITIES_PROTOS_H
#include <clib/commodities_protos.h>
#endif /* CLIB_COMMODITIES_PROTOS_H */

/* "commodities.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/

/*  OBJECT UTILITIES */

#pragma libcall CxBase CreateCxObj 1e 98003
#pragma libcall CxBase CxBroker 24 0802
#pragma libcall CxBase ActivateCxObj 2a 0802
#pragma libcall CxBase DeleteCxObj 30 801
#pragma libcall CxBase DeleteCxObjAll 36 801
#pragma libcall CxBase CxObjType 3c 801
#pragma libcall CxBase CxObjError 42 801
#pragma libcall CxBase ClearCxObjError 48 801
#pragma libcall CxBase SetCxObjPri 4e 0802

/*  OBJECT ATTACHMENT */

#pragma libcall CxBase AttachCxObj 54 9802
#pragma libcall CxBase EnqueueCxObj 5a 9802
#pragma libcall CxBase InsertCxObj 60 A9803
#pragma libcall CxBase RemoveCxObj 66 801

/*  TYPE SPECIFIC */

#pragma libcall CxBase SetTranslate 72 9802
#pragma libcall CxBase SetFilter 78 9802
#pragma libcall CxBase SetFilterIX 7e 9802
#pragma libcall CxBase ParseIX 84 9802

/*  COMMON MESSAGE */

#pragma libcall CxBase CxMsgType 8a 801
#pragma libcall CxBase CxMsgData 90 801
#pragma libcall CxBase CxMsgID 96 801

/*  MESSAGE ROUTING */

#pragma libcall CxBase DivertCxMsg 9c A9803
#pragma libcall CxBase RouteCxMsg a2 9802
#pragma libcall CxBase DisposeCxMsg a8 801

/*  INPUT EVENT HANDLING */

#pragma libcall CxBase InvertKeyMap ae 98003
#pragma libcall CxBase AddIEvents b4 801

/* FOR USE ONLY BY CONTROLLER PROGRAM */

/*--- functions in V38 or higher (Release 2.1) ---*/
/*  MORE INPUT EVENT HANDLING */
#pragma libcall CxBase MatchIX cc 9802

/* Reserved entries */


#endif /* PRAGMAS_COMMODITIES_PRAGMAS_H */
