/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_COMMODITIES_H
#define _PPCINLINE_COMMODITIES_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef COMMODITIES_BASE_NAME
#define COMMODITIES_BASE_NAME CxBase
#endif /* !COMMODITIES_BASE_NAME */

#define CreateCxObj(__p0, __p1, __p2) \
	LP3(30, CxObj *, CreateCxObj, \
		ULONG , __p0, d0, \
		LONG , __p1, a0, \
		LONG , __p2, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CxBroker(__p0, __p1) \
	LP2(36, CxObj *, CxBroker, \
		CONST struct NewBroker *, __p0, a0, \
		LONG *, __p1, d0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ActivateCxObj(__p0, __p1) \
	LP2(42, LONG , ActivateCxObj, \
		CxObj *, __p0, a0, \
		LONG , __p1, d0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteCxObj(__p0) \
	LP1NR(48, DeleteCxObj, \
		CxObj *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteCxObjAll(__p0) \
	LP1NR(54, DeleteCxObjAll, \
		CxObj *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CxObjType(__p0) \
	LP1(60, ULONG , CxObjType, \
		CONST CxObj *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CxObjError(__p0) \
	LP1(66, LONG , CxObjError, \
		CONST CxObj *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearCxObjError(__p0) \
	LP1NR(72, ClearCxObjError, \
		CxObj *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetCxObjPri(__p0, __p1) \
	LP2(78, LONG , SetCxObjPri, \
		CxObj *, __p0, a0, \
		LONG , __p1, d0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttachCxObj(__p0, __p1) \
	LP2NR(84, AttachCxObj, \
		CxObj *, __p0, a0, \
		CxObj *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EnqueueCxObj(__p0, __p1) \
	LP2NR(90, EnqueueCxObj, \
		CxObj *, __p0, a0, \
		CxObj *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InsertCxObj(__p0, __p1, __p2) \
	LP3NR(96, InsertCxObj, \
		CxObj *, __p0, a0, \
		CxObj *, __p1, a1, \
		CxObj *, __p2, a2, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveCxObj(__p0) \
	LP1NR(102, RemoveCxObj, \
		CxObj *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetTranslate(__p0, __p1) \
	LP2NR(114, SetTranslate, \
		CxObj *, __p0, a0, \
		struct InputEvent *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFilter(__p0, __p1) \
	LP2NR(120, SetFilter, \
		CxObj *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFilterIX(__p0, __p1) \
	LP2NR(126, SetFilterIX, \
		CxObj *, __p0, a0, \
		CONST IX *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParseIX(__p0, __p1) \
	LP2(132, LONG , ParseIX, \
		CONST_STRPTR , __p0, a0, \
		IX *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CxMsgType(__p0) \
	LP1(138, ULONG , CxMsgType, \
		CONST CxMsg *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CxMsgData(__p0) \
	LP1(144, APTR , CxMsgData, \
		CONST CxMsg *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CxMsgID(__p0) \
	LP1(150, LONG , CxMsgID, \
		CONST CxMsg *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DivertCxMsg(__p0, __p1, __p2) \
	LP3NR(156, DivertCxMsg, \
		CxMsg *, __p0, a0, \
		CxObj *, __p1, a1, \
		CxObj *, __p2, a2, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RouteCxMsg(__p0, __p1) \
	LP2NR(162, RouteCxMsg, \
		CxMsg *, __p0, a0, \
		CxObj *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisposeCxMsg(__p0) \
	LP1NR(168, DisposeCxMsg, \
		CxMsg *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InvertKeyMap(__p0, __p1, __p2) \
	LP3(174, BOOL , InvertKeyMap, \
		ULONG , __p0, d0, \
		struct InputEvent *, __p1, a0, \
		CONST struct KeyMap *, __p2, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddIEvents(__p0) \
	LP1NR(180, AddIEvents, \
		struct InputEvent *, __p0, a0, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)




#define MatchIX(__p0, __p1) \
	LP2(204, BOOL , MatchIX, \
		CONST struct InputEvent *, __p0, a0, \
		CONST IX *, __p1, a1, \
		, COMMODITIES_BASE_NAME, 0, 0, 0, 0, 0, 0)




#endif /* !_PPCINLINE_COMMODITIES_H */
