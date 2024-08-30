/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CARDRES_H
#define _PPCINLINE_CARDRES_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CARDRES_BASE_NAME
#define CARDRES_BASE_NAME CardResource
#endif /* !CARDRES_BASE_NAME */

#define EndCardAccess(__p0) \
	LP1(30, BOOL , EndCardAccess, \
		struct CardHandle *, __p0, a1, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardProgramVoltage(__p0, __p1) \
	LP2(60, LONG , CardProgramVoltage, \
		struct CardHandle *, __p0, a1, \
		ULONG , __p1, d0, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CopyTuple(__p0, __p1, __p2, __p3) \
	LP4(72, BOOL , CopyTuple, \
		CONST struct CardHandle *, __p0, a1, \
		UBYTE *, __p1, a0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d0, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardMiscControl(__p0, __p1) \
	LP2(48, UBYTE , CardMiscControl, \
		struct CardHandle *, __p0, a1, \
		ULONG , __p1, d1, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardChangeCount() \
	LP0(96, ULONG , CardChangeCount, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardResetRemove(__p0, __p1) \
	LP2(42, BOOL , CardResetRemove, \
		struct CardHandle *, __p0, a1, \
		ULONG , __p1, d0, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardInterface() \
	LP0(102, ULONG , CardInterface, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OwnCard(__p0) \
	LP1(6, struct CardHandle *, OwnCard, \
		struct CardHandle *, __p0, a1, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardForceChange() \
	LP0(90, BOOL , CardForceChange, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BeginCardAccess(__p0) \
	LP1(24, BOOL , BeginCardAccess, \
		struct CardHandle *, __p0, a1, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardResetCard(__p0) \
	LP1(66, BOOL , CardResetCard, \
		struct CardHandle *, __p0, a1, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetCardMap() \
	LP0(18, struct CardMemoryMap *, GetCardMap, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadCardStatus() \
	LP0(36, UBYTE , ReadCardStatus, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeviceTuple(__p0, __p1) \
	LP2(78, ULONG , DeviceTuple, \
		CONST UBYTE *, __p0, a0, \
		struct DeviceTData *, __p1, a1, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseCard(__p0, __p1) \
	LP2NR(12, ReleaseCard, \
		struct CardHandle *, __p0, a1, \
		ULONG , __p1, d0, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CardAccessSpeed(__p0, __p1) \
	LP2(54, ULONG , CardAccessSpeed, \
		struct CardHandle *, __p0, a1, \
		ULONG , __p1, d0, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IfAmigaXIP(__p0) \
	LP1(84, struct Resident *, IfAmigaXIP, \
		CONST struct CardHandle *, __p0, a2, \
		, CARDRES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_CARDRES_H */
