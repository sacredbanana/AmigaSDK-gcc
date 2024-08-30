/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_EXPANSION_H
#define _PPCINLINE_EXPANSION_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef EXPANSION_BASE_NAME
#define EXPANSION_BASE_NAME ExpansionBase
#endif /* !EXPANSION_BASE_NAME */

#define WriteExpansionByte(__p0, __p1, __p2) \
	LP3NR(114, WriteExpansionByte, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ConfigChain(__p0) \
	LP1NR(66, ConfigChain, \
		APTR , __p0, a0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadExpansionByte(__p0, __p1) \
	LP2(96, UBYTE , ReadExpansionByte, \
		CONST APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeDosNode(__p0) \
	LP1(144, struct DeviceNode *, MakeDosNode, \
		CONST APTR , __p0, a0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeExpansionMem(__p0, __p1) \
	LP2NR(90, FreeExpansionMem, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemConfigDev(__p0) \
	LP1NR(108, RemConfigDev, \
		struct ConfigDev *, __p0, a0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ConfigBoard(__p0, __p1) \
	LP2NR(60, ConfigBoard, \
		APTR , __p0, a0, \
		struct ConfigDev *, __p1, a1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindConfigDev(__p0, __p1, __p2) \
	LP3(72, struct ConfigDev *, FindConfigDev, \
		CONST struct ConfigDev *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddConfigDev(__p0) \
	LP1NR(30, AddConfigDev, \
		struct ConfigDev *, __p0, a0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetCurrentBinding(__p0, __p1) \
	LP2(138, ULONG , GetCurrentBinding, \
		CONST struct CurrentBinding *, __p0, a0, \
		ULONG , __p1, d0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetCurrentBinding(__p0, __p1) \
	LP2NR(132, SetCurrentBinding, \
		struct CurrentBinding *, __p0, a0, \
		ULONG , __p1, d0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadExpansionRom(__p0, __p1) \
	LP2NR(102, ReadExpansionRom, \
		CONST APTR , __p0, a0, \
		struct ConfigDev *, __p1, a1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseConfigBinding() \
	LP0NR(126, ReleaseConfigBinding, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddDosNode(__p0, __p1, __p2) \
	LP3(150, BOOL , AddDosNode, \
		LONG , __p0, d0, \
		ULONG , __p1, d1, \
		struct DeviceNode *, __p2, a0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeConfigDev(__p0) \
	LP1NR(84, FreeConfigDev, \
		struct ConfigDev *, __p0, a0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocExpansionMem(__p0, __p1) \
	LP2(54, APTR , AllocExpansionMem, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocConfigDev() \
	LP0(48, struct ConfigDev *, AllocConfigDev, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddBootNode(__p0, __p1, __p2, __p3) \
	LP4(36, BOOL , AddBootNode, \
		LONG , __p0, d0, \
		ULONG , __p1, d1, \
		struct DeviceNode *, __p2, a0, \
		struct ConfigDev *, __p3, a1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocBoardMem(__p0) \
	LP1NR(42, AllocBoardMem, \
		ULONG , __p0, d0, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeBoardMem(__p0, __p1) \
	LP2NR(78, FreeBoardMem, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainConfigBinding() \
	LP0NR(120, ObtainConfigBinding, \
		, EXPANSION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_EXPANSION_H */
