/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PPC_H
#define _PPCINLINE_PPC_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PPC_BASE_NAME
#define PPC_BASE_NAME PPCLibBase
#endif /* !PPC_BASE_NAME */

#define PPCWriteLong(__p0, __p1) \
	LP2NR(162, PPCWriteLong, \
		ULONG *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCWriteByte(__p0, __p1) \
	LP2NR(228, PPCWriteByte, \
		UBYTE *, __p0, a0, \
		UBYTE , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCReplyMessage(__p0) \
	LP1(324, BOOL , PPCReplyMessage, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCFindTask(__p0) \
	LP1(102, void *, PPCFindTask, \
		char *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetPortListAttr(__p0, __p1) \
	LP2(396, ULONG , PPCGetPortListAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCSignalTask(__p0, __p1) \
	LP2NR(96, PPCSignalTask, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCSetAttrs(__p0) \
	LP1(414, BOOL , PPCSetAttrs, \
		struct TagItem *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCacheTrashE(__p0, __p1, __p2) \
	LP3NR(432, PPCCacheTrashE, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCObtainPort(__p0) \
	LP1(282, void *, PPCObtainPort, \
		struct TagItem *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCAllocVecPooled(__p0, __p1) \
	LP2(258, void *, PPCAllocVecPooled, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetMessageAttr(__p0, __p1) \
	LP2(306, ULONG , PPCGetMessageAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCloseLibrary(__p0) \
	LP1NR(444, PPCCloseLibrary, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCacheClearE(__p0, __p1, __p2) \
	LP3NR(342, PPCCacheClearE, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCAllocPooled(__p0, __p1) \
	LP2(246, void *, PPCAllocPooled, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCRunKernelObjectFPU(__p0, __p1) \
	LP2(150, DOUBLE , PPCRunKernelObjectFPU, \
		void *, __p0, , \
		struct ModuleArgs *, __p1, , \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCreatePort(__p0) \
	LP1(270, void *, PPCCreatePort, \
		struct TagItem *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCOpenLibrary(__p0, __p1) \
	LP2(438, void *, PPCOpenLibrary, \
		char *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCRunKernelObject(__p0, __p1) \
	LP2(114, ULONG , PPCRunKernelObject, \
		void *, __p0, a0, \
		struct ModuleArgs *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCreatePortList(__p0, __p1) \
	LP2(366, void *, PPCCreatePortList, \
		void **, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCreateMessage(__p0, __p1) \
	LP2(294, void *, PPCCreateMessage, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetTaskAttrs(__p0, __p1) \
	LP2(132, ULONG , PPCGetTaskAttrs, \
		void *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCWriteLongFlush(__p0, __p1) \
	LP2NR(204, PPCWriteLongFlush, \
		ULONG *, __p0, a0, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCacheInvalidE(__p0, __p1, __p2) \
	LP3NR(348, PPCCacheInvalidE, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDeleteMessage(__p0) \
	LP1NR(300, PPCDeleteMessage, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDeletePort(__p0) \
	LP1(276, BOOL , PPCDeletePort, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetAttrs(__p0) \
	LP1(138, ULONG , PPCGetAttrs, \
		struct TagItem *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCReadWord(__p0) \
	LP1(210, UWORD , PPCReadWord, \
		UWORD *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCreatePool(__p0, __p1, __p2) \
	LP3(234, void *, PPCCreatePool, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCWaitPortList(__p0) \
	LP1(390, void *, PPCWaitPortList, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCSetTaskAttrs(__p0, __p1) \
	LP2(192, ULONG , PPCSetTaskAttrs, \
		void *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCAddPortList(__p0, __p1) \
	LP2(378, BOOL , PPCAddPortList, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetObjectAttrs(__p0, __p1, __p2) \
	LP3(198, ULONG , PPCGetObjectAttrs, \
		void *, __p0, a0, \
		struct PPCObjectInfo *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCReadByte(__p0) \
	LP1(222, UBYTE , PPCReadByte, \
		UBYTE *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCFindTaskObject(__p0) \
	LP1(144, void *, PPCFindTaskObject, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCReadLong(__p0) \
	LP1(156, ULONG , PPCReadLong, \
		ULONG *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDeletePool(__p0) \
	LP1(240, BOOL , PPCDeletePool, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCSetPortListAttr(__p0, __p1, __p2) \
	LP3NR(402, PPCSetPortListAttr, \
		void *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCStopTask(__p0, __p1) \
	LP2(186, BOOL , PPCStopTask, \
		void *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCRemPortList(__p0, __p1) \
	LP2NR(384, PPCRemPortList, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetLibSymbol(__p0, __p1) \
	LP2(450, void *, PPCGetLibSymbol, \
		void *, __p0, a0, \
		char *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCLoadObject(__p0) \
	LP1(30, void *, PPCLoadObject, \
		char *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCRunObject(__p0, __p1) \
	LP2(42, ULONG , PPCRunObject, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCAllocVec(__p0, __p1) \
	LP2(60, void *, PPCAllocVec, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCLoadObjectTagList(__p0) \
	LP1(408, void *, PPCLoadObjectTagList, \
		struct TagItem *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCFreeVec(__p0) \
	LP1(66, void *, PPCFreeVec, \
		void *, __p0, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCStartTask(__p0, __p1) \
	LP2(180, BOOL , PPCStartTask, \
		void *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCSendMessage(__p0, __p1, __p2, __p3, __p4) \
	LP5(330, BOOL , PPCSendMessage, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		void *, __p2, a2, \
		ULONG , __p3, d0, \
		ULONG , __p4, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCFreePooled(__p0, __p1, __p2) \
	LP3NR(252, PPCFreePooled, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		ULONG , __p2, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCCreateTask(__p0, __p1) \
	LP2(84, void *, PPCCreateTask, \
		void *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCReleasePort(__p0) \
	LP1(288, BOOL , PPCReleasePort, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCAllocMem(__p0, __p1) \
	LP2(48, void *, PPCAllocMem, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDeletePortList(__p0) \
	LP1NR(372, PPCDeletePortList, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDeleteTask(__p0) \
	LP1(90, BOOL , PPCDeleteTask, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCGetMessage(__p0) \
	LP1(312, void *, PPCGetMessage, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCFreeMem(__p0, __p1) \
	LP2NR(54, PPCFreeMem, \
		void *, __p0, a1, \
		ULONG , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCWaitPort(__p0) \
	LP1(336, void *, PPCWaitPort, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCUnLoadObject(__p0) \
	LP1NR(36, PPCUnLoadObject, \
		void *, __p0, a0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCWriteWord(__p0, __p1) \
	LP2NR(216, PPCWriteWord, \
		UWORD *, __p0, a0, \
		UWORD , __p1, d0, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCFreeVecPooled(__p0, __p1) \
	LP2NR(264, PPCFreeVecPooled, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		, PPC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define PPCCreateTaskTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCCreateTask(__p0, (struct TagItem *)_tags);})

#define PPCCreatePortTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCCreatePort((struct TagItem *)_tags);})

#define PPCGetAttrsTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCGetAttrs((struct TagItem *)_tags);})

#define PPCStopTaskTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCStopTask(__p0, (struct TagItem *)_tags);})

#define PPCGetTaskAttrsTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCGetTaskAttrs(__p0, (struct TagItem *)_tags);})

#define PPCLoadObjectTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCLoadObjectTagList((struct TagItem *)_tags);})

#define PPCSetAttrsTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCSetAttrs((struct TagItem *)_tags);})

#define PPCGetObjectAttrsTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCGetObjectAttrs(__p0, __p1, (struct TagItem *)_tags);})

#define PPCObtainPortTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCObtainPort((struct TagItem *)_tags);})

#define PPCStartTaskTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCStartTask(__p0, (struct TagItem *)_tags);})

#define PPCSetTaskAttrsTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCSetTaskAttrs(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_PPC_H */
