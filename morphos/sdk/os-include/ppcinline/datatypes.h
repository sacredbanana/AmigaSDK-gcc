/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DATATYPES_H
#define _PPCINLINE_DATATYPES_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DATATYPES_BASE_NAME
#define DATATYPES_BASE_NAME DataTypesBase
#endif /* !DATATYPES_BASE_NAME */

#define DoDTDomainA(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(306, ULONG , DoDTDomainA, \
		Object *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		struct RastPort *, __p3, a3, \
		ULONG , __p4, d0, \
		struct IBox *, __p5, a4, \
		struct TagItem *, __p6, a5, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockDataType(__p0) \
	LP1NR(240, LockDataType, \
		struct DataType *, __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisposeDTObject(__p0) \
	LP1NR(54, DisposeDTObject, \
		Object *, __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDTMethods(__p0) \
	LP1(102, ULONG *, GetDTMethods, \
		Object *, __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StartDragSelect(__p0) \
	LP1(300, ULONG , StartDragSelect, \
		Object *, __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseDTDrawInfo(__p0, __p1) \
	LP2NR(132, ReleaseDTDrawInfo, \
		Object *, __p0, a0, \
		APTR , __p1, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindTriggerMethod(__p0, __p1, __p2) \
	LP3(264, struct DTMethod *, FindTriggerMethod, \
		struct DTMethod *, __p0, a0, \
		STRPTR , __p1, a1, \
		ULONG , __p2, d0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainDataTypeA(__p0, __p1, __p2) \
	LP3(36, struct DataType *, ObtainDataTypeA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		struct TagItem *, __p2, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewDTObjectA(__p0, __p1) \
	LP2(48, Object *, NewDTObjectA, \
		APTR , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CopyDTTriggerMethods(__p0, __p1, __p2) \
	LP3(276, struct DTMethod *, CopyDTTriggerMethods, \
		struct DTMethod *, __p0, a0, \
		struct DTMethod *, __p1, a1, \
		struct DTMethod *, __p2, a2, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SaveDTObjectA(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(294, ULONG , SaveDTObjectA, \
		Object *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		STRPTR , __p3, a3, \
		ULONG , __p4, d0, \
		BOOL , __p5, d1, \
		struct TagItem *, __p6, a4, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDTTriggerMethods(__p0) \
	LP1(108, struct DTMethods *, GetDTTriggerMethods, \
		Object *, __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindMethod(__p0, __p1) \
	LP2(258, ULONG *, FindMethod, \
		ULONG *, __p0, a0, \
		ULONG , __p1, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindToolNodeA(__p0, __p1) \
	LP2(246, struct ToolNode *, FindToolNodeA, \
		struct List *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDTAttrsA(__p0, __p1) \
	LP2(66, ULONG , GetDTAttrsA, \
		Object *, __p0, a0, \
		struct TagItem *, __p1, a2, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CopyDTMethods(__p0, __p1, __p2) \
	LP3(270, ULONG *, CopyDTMethods, \
		ULONG *, __p0, a0, \
		ULONG *, __p1, a1, \
		ULONG *, __p2, a2, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoDTMethodA(__p0, __p1, __p2, __p3) \
	LP4(90, ULONG , DoDTMethodA, \
		Object *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		Msg , __p3, a3, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeDTMethods(__p0) \
	LP1NR(282, FreeDTMethods, \
		APTR , __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoAsyncLayout(__p0, __p1) \
	LP2(84, ULONG , DoAsyncLayout, \
		Object *, __p0, a0, \
		struct gpLayout *, __p1, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDTString(__p0) \
	LP1(138, STRPTR , GetDTString, \
		ULONG , __p0, d0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainDTDrawInfoA(__p0, __p1) \
	LP2(120, APTR , ObtainDTDrawInfoA, \
		Object *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetDTAttrsA(__p0, __p1, __p2, __p3) \
	LP4(60, ULONG , SetDTAttrsA, \
		Object *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		struct TagItem *, __p3, a3, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDTTriggerMethodDataFlags(__p0) \
	LP1(288, ULONG , GetDTTriggerMethodDataFlags, \
		ULONG , __p0, d0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddDTObject(__p0, __p1, __p2, __p3) \
	LP4(72, LONG , AddDTObject, \
		struct Window *, __p0, a0, \
		struct Requester *, __p1, a1, \
		Object *, __p2, a2, \
		LONG , __p3, d0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LaunchToolA(__p0, __p1, __p2) \
	LP3(252, ULONG , LaunchToolA, \
		struct Tool *, __p0, a0, \
		STRPTR , __p1, a1, \
		struct TagItem *, __p2, a2, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseDataType(__p0) \
	LP1NR(42, ReleaseDataType, \
		struct DataType *, __p0, a0, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveDTObject(__p0, __p1) \
	LP2(96, LONG , RemoveDTObject, \
		struct Window *, __p0, a0, \
		Object *, __p1, a1, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PrintDTObjectA(__p0, __p1, __p2, __p3) \
	LP4(114, ULONG , PrintDTObjectA, \
		Object *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		struct dtPrint *, __p3, a3, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawDTObjectA(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9(126, LONG , DrawDTObjectA, \
		struct RastPort *, __p0, a0, \
		Object *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		struct TagItem *, __p8, a2, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RefreshDTObjectA(__p0, __p1, __p2, __p3) \
	LP4NR(78, RefreshDTObjectA, \
		Object *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		struct TagItem *, __p3, a3, \
		, DATATYPES_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define FindToolNode(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	FindToolNodeA(__p0, (struct TagItem *)_tags);})

#define ObtainDTDrawInfo(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ObtainDTDrawInfoA(__p0, (struct TagItem *)_tags);})

#define LaunchTool(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LaunchToolA(__p0, __p1, (struct TagItem *)_tags);})

#define DrawDTObject(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DrawDTObjectA(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, (struct TagItem *)_tags);})

#define SaveDTObject(__p0, __p1, __p2, __p3, __p4, __p5, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SaveDTObjectA(__p0, __p1, __p2, __p3, __p4, __p5, (struct TagItem *)_tags);})

#define DoDTDomain(__p0, __p1, __p2, __p3, __p4, __p5, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DoDTDomainA(__p0, __p1, __p2, __p3, __p4, __p5, (struct TagItem *)_tags);})

#define GetDTAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetDTAttrsA(__p0, (struct TagItem *)_tags);})

#define DoDTMethod(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DoDTMethodA(__p0, __p1, __p2, (Msg )_tags);})

#define RefreshDTObjects(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RefreshDTObjectA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define SetDTAttrs(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetDTAttrsA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define ObtainDataType(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ObtainDataTypeA(__p0, __p1, (struct TagItem *)_tags);})

#define NewDTObject(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewDTObjectA(__p0, (struct TagItem *)_tags);})

#define PrintDTObject(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PrintDTObjectA(__p0, __p1, __p2, (struct dtPrint *)_tags);})

#define RefreshDTObject(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RefreshDTObjectA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_DATATYPES_H */
