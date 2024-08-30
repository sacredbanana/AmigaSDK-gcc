/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_EXEC_H
#define _PPCINLINE_EXEC_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef EXEC_BASE_NAME
#define EXEC_BASE_NAME SysBase
#endif /* !EXEC_BASE_NAME */

#define Supervisor(__p0) \
	LP1FP(30, ULONG , Supervisor, \
		__ft, __p0, a5, \
		, EXEC_BASE_NAME, ULONG (*CONST  __ft)(VOID) , 0, 0, 0, 0, 0, 0)

#define InitCode(__p0, __p1) \
	LP2NR(72, InitCode, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitStruct(__p0, __p1, __p2) \
	LP3NR(78, InitStruct, \
		CONST APTR , __p0, a1, \
		APTR , __p1, a2, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeLibrary(__p0, __p1, __p2, __p3, __p4) \
	LP5FP(84, struct Library *, MakeLibrary, \
		CONST APTR , __p0, a0, \
		CONST APTR , __p1, a1, \
		__ft, __p2, a2, \
		ULONG , __p3, d0, \
		ULONG , __p4, d1, \
		, EXEC_BASE_NAME, ULONG (*CONST  __ft)(VOID), 0, 0, 0, 0, 0, 0)

#define MakeFunctions(__p0, __p1, __p2) \
	LP3NR(90, MakeFunctions, \
		APTR , __p0, a0, \
		CONST APTR , __p1, a1, \
		CONST APTR , __p2, a2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindResident(__p0) \
	LP1(96, struct Resident *, FindResident, \
		CONST_STRPTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitResident(__p0, __p1) \
	LP2(102, APTR , InitResident, \
		CONST struct Resident *, __p0, a1, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Alert(__p0) \
	LP1NR(108, Alert, \
		ULONG , __p0, d7, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Debug(__p0) \
	LP1NR(114, Debug, \
		ULONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Disable() \
	LP0NR(120, Disable, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Enable() \
	LP0NR(126, Enable, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Forbid() \
	LP0NR(132, Forbid, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Permit() \
	LP0NR(138, Permit, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetSR(__p0, __p1) \
	LP2(144, ULONG , SetSR, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SuperState() \
	LP0(150, APTR , SuperState, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UserState(__p0) \
	LP1NR(156, UserState, \
		APTR , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetIntVector(__p0, __p1) \
	LP2(162, struct Interrupt *, SetIntVector, \
		LONG , __p0, d0, \
		CONST struct Interrupt *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddIntServer(__p0, __p1) \
	LP2NR(168, AddIntServer, \
		LONG , __p0, d0, \
		struct Interrupt *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemIntServer(__p0, __p1) \
	LP2NR(174, RemIntServer, \
		LONG , __p0, d0, \
		struct Interrupt *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Cause(__p0) \
	LP1NR(180, Cause, \
		struct Interrupt *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Allocate(__p0, __p1) \
	LP2(186, APTR , Allocate, \
		struct MemHeader *, __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Deallocate(__p0, __p1, __p2) \
	LP3NR(192, Deallocate, \
		struct MemHeader *, __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocMem(__p0, __p1) \
	LP2(198, APTR , AllocMem, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocAbs(__p0, __p1) \
	LP2(204, APTR , AllocAbs, \
		ULONG , __p0, d0, \
		APTR , __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeMem(__p0, __p1) \
	LP2NR(210, FreeMem, \
		APTR , __p0, a1, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AvailMem(__p0) \
	LP1(216, ULONG , AvailMem, \
		ULONG , __p0, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocEntry(__p0) \
	LP1(222, struct MemList *, AllocEntry, \
		struct MemList *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeEntry(__p0) \
	LP1NR(228, FreeEntry, \
		struct MemList *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Insert(__p0, __p1, __p2) \
	LP3NR(234, Insert, \
		struct List *, __p0, a0, \
		struct Node *, __p1, a1, \
		struct Node *, __p2, a2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddHead(__p0, __p1) \
	LP2NR(240, AddHead, \
		struct List *, __p0, a0, \
		struct Node *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddTail(__p0, __p1) \
	LP2NR(246, AddTail, \
		struct List *, __p0, a0, \
		struct Node *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Remove(__p0) \
	LP1NR(252, Remove, \
		struct Node *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemHead(__p0) \
	LP1(258, struct Node *, RemHead, \
		struct List *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemTail(__p0) \
	LP1(264, struct Node *, RemTail, \
		struct List *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Enqueue(__p0, __p1) \
	LP2NR(270, Enqueue, \
		struct List *, __p0, a0, \
		struct Node *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindName(__p0, __p1) \
	LP2(276, struct Node *, FindName, \
		struct List *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddTask(__p0, __p1, __p2) \
	LP3(282, APTR , AddTask, \
		struct Task *, __p0, a1, \
		CONST APTR , __p1, a2, \
		CONST APTR , __p2, a3, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemTask(__p0) \
	LP1NR(288, RemTask, \
		struct Task *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindTask(__p0) \
	LP1(294, struct Task *, FindTask, \
		CONST_STRPTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetTaskPri(__p0, __p1) \
	LP2(300, BYTE , SetTaskPri, \
		struct Task *, __p0, a1, \
		LONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetSignal(__p0, __p1) \
	LP2(306, ULONG , SetSignal, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetExcept(__p0, __p1) \
	LP2(312, ULONG , SetExcept, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Wait(__p0) \
	LP1(318, ULONG , Wait, \
		ULONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Signal(__p0, __p1) \
	LP2NR(324, Signal, \
		struct Task *, __p0, a1, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocSignal(__p0) \
	LP1(330, BYTE , AllocSignal, \
		LONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeSignal(__p0) \
	LP1NR(336, FreeSignal, \
		LONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocTrap(__p0) \
	LP1(342, LONG , AllocTrap, \
		LONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeTrap(__p0) \
	LP1NR(348, FreeTrap, \
		LONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddPort(__p0) \
	LP1NR(354, AddPort, \
		struct MsgPort *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemPort(__p0) \
	LP1NR(360, RemPort, \
		struct MsgPort *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PutMsg(__p0, __p1) \
	LP2NR(366, PutMsg, \
		struct MsgPort *, __p0, a0, \
		struct Message *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetMsg(__p0) \
	LP1(372, struct Message *, GetMsg, \
		struct MsgPort *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReplyMsg(__p0) \
	LP1NR(378, ReplyMsg, \
		struct Message *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WaitPort(__p0) \
	LP1(384, struct Message *, WaitPort, \
		struct MsgPort *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindPort(__p0) \
	LP1(390, struct MsgPort *, FindPort, \
		CONST_STRPTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddLibrary(__p0) \
	LP1NR(396, AddLibrary, \
		struct Library *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemLibrary(__p0) \
	LP1NR(402, RemLibrary, \
		struct Library *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OldOpenLibrary(__p0) \
	LP1(408, struct Library *, OldOpenLibrary, \
		CONST_STRPTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseLibrary(__p0) \
	LP1NR(414, CloseLibrary, \
		struct Library *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFunction(__p0, __p1, __p2) \
	LP3FP(420, APTR , SetFunction, \
		struct Library *, __p0, a1, \
		LONG , __p1, a0, \
		__ft, __p2, d0, \
		, EXEC_BASE_NAME, ULONG (*CONST  __ft)(VOID) , 0, 0, 0, 0, 0, 0)

#define SumLibrary(__p0) \
	LP1NR(426, SumLibrary, \
		struct Library *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddDevice(__p0) \
	LP1NR(432, AddDevice, \
		struct Device *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemDevice(__p0) \
	LP1NR(438, RemDevice, \
		struct Device *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenDevice(__p0, __p1, __p2, __p3) \
	LP4(444, BYTE , OpenDevice, \
		CONST_STRPTR , __p0, a0, \
		ULONG , __p1, d0, \
		struct IORequest *, __p2, a1, \
		ULONG , __p3, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseDevice(__p0) \
	LP1NR(450, CloseDevice, \
		struct IORequest *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoIO(__p0) \
	LP1(456, BYTE , DoIO, \
		struct IORequest *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SendIO(__p0) \
	LP1NR(462, SendIO, \
		struct IORequest *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CheckIO(__p0) \
	LP1(468, struct IORequest *, CheckIO, \
		struct IORequest *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WaitIO(__p0) \
	LP1(474, BYTE , WaitIO, \
		struct IORequest *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AbortIO(__p0) \
	LP1NR(480, AbortIO, \
		struct IORequest *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddResource(__p0) \
	LP1NR(486, AddResource, \
		APTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemResource(__p0) \
	LP1NR(492, RemResource, \
		APTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenResource(__p0) \
	LP1(498, APTR , OpenResource, \
		CONST_STRPTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RawDoFmt(__p0, __p1, __p2, __p3) \
	LP4FP(522, APTR , RawDoFmt, \
		CONST_STRPTR , __p0, a0, \
		CONST APTR , __p1, a1, \
		__ft, __p2, a2, \
		APTR , __p3, a3, \
		, EXEC_BASE_NAME, VOID (*CONST  __ft)(VOID), 0, 0, 0, 0, 0, 0)

#define GetCC() \
	LP0(528, ULONG , GetCC, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TypeOfMem(__p0) \
	LP1(534, ULONG , TypeOfMem, \
		CONST APTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Procure(__p0, __p1) \
	LP2(540, ULONG , Procure, \
		struct SignalSemaphore *, __p0, a0, \
		struct SemaphoreMessage *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Vacate(__p0, __p1) \
	LP2NR(546, Vacate, \
		struct SignalSemaphore *, __p0, a0, \
		struct SemaphoreMessage *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenLibrary(__p0, __p1) \
	LP2(552, struct Library *, OpenLibrary, \
		CONST_STRPTR , __p0, a1, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitSemaphore(__p0) \
	LP1NR(558, InitSemaphore, \
		struct SignalSemaphore *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainSemaphore(__p0) \
	LP1NR(564, ObtainSemaphore, \
		struct SignalSemaphore *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseSemaphore(__p0) \
	LP1NR(570, ReleaseSemaphore, \
		struct SignalSemaphore *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttemptSemaphore(__p0) \
	LP1(576, ULONG , AttemptSemaphore, \
		struct SignalSemaphore *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainSemaphoreList(__p0) \
	LP1NR(582, ObtainSemaphoreList, \
		struct List *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseSemaphoreList(__p0) \
	LP1NR(588, ReleaseSemaphoreList, \
		struct List *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindSemaphore(__p0) \
	LP1(594, struct SignalSemaphore *, FindSemaphore, \
		STRPTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddSemaphore(__p0) \
	LP1NR(600, AddSemaphore, \
		struct SignalSemaphore *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemSemaphore(__p0) \
	LP1NR(606, RemSemaphore, \
		struct SignalSemaphore *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainSemaphoreShared(__p0) \
	LP1NR(678, ObtainSemaphoreShared, \
		struct SignalSemaphore *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttemptSemaphoreShared(__p0) \
	LP1(720, ULONG , AttemptSemaphoreShared, \
		struct SignalSemaphore *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SumKickData() \
	LP0(612, ULONG , SumKickData, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddMemList(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(618, AddMemList, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		LONG , __p2, d2, \
		APTR , __p3, a0, \
		CONST_STRPTR , __p4, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CopyMem(__p0, __p1, __p2) \
	LP3NR(624, CopyMem, \
		CONST APTR , __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CopyMemQuick(__p0, __p1, __p2) \
	LP3NR(630, CopyMemQuick, \
		CONST APTR , __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheClearU() \
	LP0NR(636, CacheClearU, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheClearE(__p0, __p1, __p2) \
	LP3NR(642, CacheClearE, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheControl(__p0, __p1) \
	LP2(648, ULONG , CacheControl, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateIORequest(__p0, __p1) \
	LP2(654, APTR , CreateIORequest, \
		CONST struct MsgPort *, __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteIORequest(__p0) \
	LP1NR(660, DeleteIORequest, \
		APTR , __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateMsgPort() \
	LP0(666, struct MsgPort *, CreateMsgPort, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteMsgPort(__p0) \
	LP1NR(672, DeleteMsgPort, \
		struct MsgPort *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocVec(__p0, __p1) \
	LP2(684, APTR , AllocVec, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeVec(__p0) \
	LP1NR(690, FreeVec, \
		APTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreatePool(__p0, __p1, __p2) \
	LP3(696, APTR , CreatePool, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeletePool(__p0) \
	LP1NR(702, DeletePool, \
		APTR , __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocPooled(__p0, __p1) \
	LP2(708, APTR , AllocPooled, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreePooled(__p0, __p1, __p2) \
	LP3NR(714, FreePooled, \
		APTR , __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ColdReboot() \
	LP0NR(726, ColdReboot, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StackSwap(__p0) \
	LP1NR(732, StackSwap, \
		struct StackSwapStruct *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CachePreDMA(__p0, __p1, __p2) \
	LP3(762, APTR , CachePreDMA, \
		CONST APTR , __p0, a0, \
		ULONG *, __p1, a1, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CachePostDMA(__p0, __p1, __p2) \
	LP3NR(768, CachePostDMA, \
		CONST APTR , __p0, a0, \
		ULONG *, __p1, a1, \
		ULONG , __p2, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddMemHandler(__p0) \
	LP1NR(774, AddMemHandler, \
		struct Interrupt *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemMemHandler(__p0) \
	LP1NR(780, RemMemHandler, \
		struct Interrupt *, __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainQuickVector(__p0) \
	LP1(786, ULONG , ObtainQuickVector, \
		APTR , __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RawIOInit() \
	LP0NR(504, RawIOInit, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RawMayGetChar() \
	LP0(510, UBYTE , RawMayGetChar, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RawPutChar(__p0) \
	LP1NR(516, RawPutChar, \
		UBYTE , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TaggedOpenLibrary(__p0) \
	LP1(810, APTR , TaggedOpenLibrary, \
		LONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadGayle() \
	LP0(816, ULONG , ReadGayle, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewGetTaskAttrsA(__p0, __p1, __p2, __p3, __p4) \
	LP5(738, ULONG , NewGetTaskAttrsA, \
		struct Task *, __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		ULONG , __p3, d1, \
		struct TagItem *, __p4, a2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewSetTaskAttrsA(__p0, __p1, __p2, __p3, __p4) \
	LP5(744, ULONG , NewSetTaskAttrsA, \
		struct Task *, __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		ULONG , __p3, d1, \
		struct TagItem *, __p4, a2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewCreateLibrary(__p0) \
	LP1(798, struct Library *, NewCreateLibrary, \
		struct TagItem *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewSetFunction(__p0, __p1, __p2, __p3) \
	LP4(792, APTR , NewSetFunction, \
		struct Library *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		struct TagItem *, __p3, a2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewPPCStackSwap(__p0, __p1, __p2) \
	LP3(804, ULONG , NewPPCStackSwap, \
		struct StackSwapStruct *, __p0, a0, \
		APTR , __p1, a1, \
		struct PPCStackSwapArgs *, __p2, a2, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VNewRawDoFmt(__p0, __p1, __p2, __p3) \
	(((STRPTR (*)(void *, CONST_STRPTR , APTR (*)(APTR, UBYTE), STRPTR , va_list ))*(void**)((long)(EXEC_BASE_NAME) - 820))((void*)(EXEC_BASE_NAME), __p0, __p1, __p2, __p3))

#if !defined(__STRICT_ANSI__)
#define NewRawDoFmt(__p0, __p1, ...) \
	(((STRPTR (*)(void *, CONST_STRPTR , APTR (*)(APTR, UBYTE), STRPTR , ...))*(void**)((long)(EXEC_BASE_NAME) - 922))((void*)(EXEC_BASE_NAME), __p0, __p1, __VA_ARGS__))
#endif

#define CacheFlushDataArea(__p0, __p1) \
	LP2NR(828, CacheFlushDataArea, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheInvalidInstArea(__p0, __p1) \
	LP2NR(834, CacheInvalidInstArea, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheInvalidDataArea(__p0, __p1) \
	LP2NR(840, CacheInvalidDataArea, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheFlushDataInstArea(__p0, __p1) \
	LP2NR(846, CacheFlushDataInstArea, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CacheTrashCacheArea(__p0, __p1) \
	LP2NR(852, CacheTrashCacheArea, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocTaskPooled(__p0) \
	LP1(858, APTR , AllocTaskPooled, \
		ULONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeTaskPooled(__p0, __p1) \
	LP2NR(864, FreeTaskPooled, \
		APTR , __p0, a1, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocVecTaskPooled(__p0) \
	LP1(870, APTR , AllocVecTaskPooled, \
		ULONG , __p0, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeVecTaskPooled(__p0) \
	LP1NR(876, FreeVecTaskPooled, \
		APTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FlushPool(__p0) \
	LP1NR(882, FlushPool, \
		APTR , __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FlushTaskPool() \
	LP0NR(888, FlushTaskPool, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocVecPooled(__p0, __p1) \
	LP2(894, APTR , AllocVecPooled, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeVecPooled(__p0, __p1) \
	LP2NR(900, FreeVecPooled, \
		APTR , __p0, a0, \
		APTR , __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewGetSystemAttrsA(__p0, __p1, __p2, __p3) \
	LP4(906, ULONG , NewGetSystemAttrsA, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		struct TagItem *, __p3, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewSetSystemAttrsA(__p0, __p1, __p2, __p3) \
	LP4(912, ULONG , NewSetSystemAttrsA, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		struct TagItem *, __p3, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewCreateTaskA(__p0) \
	LP1(918, struct Task *, NewCreateTaskA, \
		struct TagItem *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocateAligned(__p0, __p1, __p2, __p3) \
	(((APTR (*)(void *, struct MemHeader *, ULONG , ULONG , ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 928))((void*)(EXEC_BASE_NAME), __p0, __p1, __p2, __p3))

#define AllocMemAligned(__p0, __p1, __p2, __p3) \
	(((APTR (*)(void *, ULONG , ULONG , ULONG , ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 934))((void*)(EXEC_BASE_NAME), __p0, __p1, __p2, __p3))

#define AllocVecAligned(__p0, __p1, __p2, __p3) \
	(((APTR (*)(void *, ULONG , ULONG , ULONG , ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 940))((void*)(EXEC_BASE_NAME), __p0, __p1, __p2, __p3))

#define AddExecNotify(__p0) \
	(((VOID (*)(void *, struct Hook *))*(void**)((long)(EXEC_BASE_NAME) - 946))((void*)(EXEC_BASE_NAME), __p0))

#define RemExecNotify(__p0) \
	(((VOID (*)(void *, struct Hook *))*(void**)((long)(EXEC_BASE_NAME) - 952))((void*)(EXEC_BASE_NAME), __p0))

#define FindExecNode(__p0, __p1) \
	LP2(960, struct Node *, FindExecNode, \
		ULONG , __p0, d0, \
		CONST_STRPTR , __p1, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddExecNodeA(__p0, __p1) \
	LP2(966, APTR , AddExecNodeA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocVecDMA(__p0, __p1) \
	LP2(972, APTR , AllocVecDMA, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeVecDMA(__p0) \
	LP1NR(978, FreeVecDMA, \
		APTR , __p0, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocPooledAligned(__p0, __p1, __p2, __p3) \
	(((APTR (*)(void *, APTR , ULONG , ULONG , ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 982))((void*)(EXEC_BASE_NAME), __p0, __p1, __p2, __p3))

#define AddResident(__p0) \
	(((LONG (*)(void *, struct Resident *))*(void**)((long)(EXEC_BASE_NAME) - 988))((void*)(EXEC_BASE_NAME), __p0))

#define FindTaskByPID(__p0) \
	(((struct Task *(*)(void *, ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 994))((void*)(EXEC_BASE_NAME), __p0))





#define DumpTaskState(__p0) \
	LP1NR(1026, DumpTaskState, \
		struct Task *, __p0, a0, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddExecNotifyType(__p0, __p1) \
	(((void (*)(void *, struct Hook *, LONG ))*(void**)((long)(EXEC_BASE_NAME) - 1030))((void*)(EXEC_BASE_NAME), __p0, __p1))

#define ShutdownA(__p0) \
	(((ULONG (*)(void *, struct TagItem *))*(void**)((long)(EXEC_BASE_NAME) - 1036))((void*)(EXEC_BASE_NAME), __p0))


#define AvailPool(__p0, __p1) \
	(((ULONG (*)(void *, APTR , ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 1048))((void*)(EXEC_BASE_NAME), __p0, __p1))


#define PutMsgHead(__p0, __p1) \
	(((void (*)(void *, struct MsgPort *, struct Message *))*(void**)((long)(EXEC_BASE_NAME) - 1060))((void*)(EXEC_BASE_NAME), __p0, __p1))

#define NewGetTaskPIDAttrsA(__p0, __p1, __p2, __p3, __p4) \
	LP5(1068, ULONG , NewGetTaskPIDAttrsA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		struct TagItem *, __p4, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewSetTaskPIDAttrsA(__p0, __p1, __p2, __p3, __p4) \
	LP5(1074, ULONG , NewSetTaskPIDAttrsA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		struct TagItem *, __p4, a1, \
		, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define TLSAllocA(__p0) \
	(((ULONG (*)(void *, struct TagItem *))*(void**)((long)(EXEC_BASE_NAME) - 1084))((void*)(EXEC_BASE_NAME), __p0))

#define TLSFree(__p0) \
	(((LONG (*)(void *, ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 1090))((void*)(EXEC_BASE_NAME), __p0))

#define TLSGetValue(__p0) \
	(((APTR (*)(void *, ULONG ))*(void**)((long)(EXEC_BASE_NAME) - 1096))((void*)(EXEC_BASE_NAME), __p0))

#define TLSSetValue(__p0, __p1) \
	(((LONG (*)(void *, ULONG , APTR ))*(void**)((long)(EXEC_BASE_NAME) - 1102))((void*)(EXEC_BASE_NAME), __p0, __p1))

#define TLSCallDestructors(__p0) \
	(((VOID (*)(void *, struct Task *))*(void**)((long)(EXEC_BASE_NAME) - 1108))((void*)(EXEC_BASE_NAME), __p0))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define NewGetTaskAttrs(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewGetTaskAttrsA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define NewSetTaskAttrs(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewSetTaskAttrsA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define NewCreateLibraryTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewCreateLibrary((struct TagItem *)_tags);})

#define NewGetSystemAttrs(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewGetSystemAttrsA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define NewSetSystemAttrs(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewSetSystemAttrsA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define NewCreateTask(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewCreateTaskA((struct TagItem *)_tags);})

#define AddExecNode(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddExecNodeA(__p0, (struct TagItem *)_tags);})



#define NewGetTaskPIDAttrs(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewGetTaskPIDAttrsA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define NewSetTaskPIDAttrs(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewSetTaskPIDAttrsA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})


#define TLSAlloc(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	TLSAllocA((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_EXEC_H */
