/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DOS_H
#define _PPCINLINE_DOS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DOS_BASE_NAME
#define DOS_BASE_NAME DOSBase
#endif /* !DOS_BASE_NAME */

#define Open(__p0, __p1) \
	LP2(30, BPTR , Open, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Close(__p0) \
	LP1(36, LONG , Close, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Read(__p0, __p1, __p2) \
	LP3(42, LONG , Read, \
		BPTR , __p0, d1, \
		APTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Write(__p0, __p1, __p2) \
	LP3(48, LONG , Write, \
		BPTR , __p0, d1, \
		CONST APTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Input() \
	LP0(54, BPTR , Input, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Output() \
	LP0(60, BPTR , Output, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Seek(__p0, __p1, __p2) \
	LP3(66, LONG , Seek, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteFile(__p0) \
	LP1(72, LONG , DeleteFile, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Rename(__p0, __p1) \
	LP2(78, LONG , Rename, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Lock(__p0, __p1) \
	LP2(84, BPTR , Lock, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnLock(__p0) \
	LP1NR(90, UnLock, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DupLock(__p0) \
	LP1(96, BPTR , DupLock, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Examine(__p0, __p1) \
	LP2(102, LONG , Examine, \
		BPTR , __p0, d1, \
		struct FileInfoBlock *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExNext(__p0, __p1) \
	LP2(108, LONG , ExNext, \
		BPTR , __p0, d1, \
		struct FileInfoBlock *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Info(__p0, __p1) \
	LP2(114, LONG , Info, \
		BPTR , __p0, d1, \
		struct InfoData *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateDir(__p0) \
	LP1(120, BPTR , CreateDir, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CurrentDir(__p0) \
	LP1(126, BPTR , CurrentDir, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IoErr() \
	LP0(132, LONG , IoErr, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateProc(__p0, __p1, __p2, __p3) \
	LP4(138, struct MsgPort *, CreateProc, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		BPTR , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Exit(__p0) \
	LP1NR(144, Exit, \
		LONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LoadSeg(__p0) \
	LP1(150, BPTR , LoadSeg, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnLoadSeg(__p0) \
	LP1NR(156, UnLoadSeg, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeviceProc(__p0) \
	LP1(174, struct MsgPort *, DeviceProc, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetComment(__p0, __p1) \
	LP2(180, LONG , SetComment, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetProtection(__p0, __p1) \
	LP2(186, LONG , SetProtection, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DateStamp(__p0) \
	LP1(192, struct DateStamp *, DateStamp, \
		struct DateStamp *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Delay(__p0) \
	LP1NR(198, Delay, \
		LONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WaitForChar(__p0, __p1) \
	LP2(204, LONG , WaitForChar, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParentDir(__p0) \
	LP1(210, BPTR , ParentDir, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsInteractive(__p0) \
	LP1(216, LONG , IsInteractive, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Execute(__p0, __p1, __p2) \
	LP3(222, LONG , Execute, \
		CONST_STRPTR , __p0, d1, \
		BPTR , __p1, d2, \
		BPTR , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocDosObject(__p0, __p1) \
	LP2(228, APTR , AllocDosObject, \
		ULONG , __p0, d1, \
		CONST struct TagItem *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocDosObjectTagList(__p0, __p1) \
	LP2(228, APTR , AllocDosObjectTagList, \
		ULONG , __p0, d1, \
		CONST struct TagItem *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeDosObject(__p0, __p1) \
	LP2NR(234, FreeDosObject, \
		ULONG , __p0, d1, \
		APTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoPkt(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(240, LONG , DoPkt, \
		struct MsgPort *, __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		LONG , __p4, d5, \
		LONG , __p5, d6, \
		LONG , __p6, d7, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoPkt0(__p0, __p1) \
	LP2(240, LONG , DoPkt0, \
		struct MsgPort *, __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoPkt1(__p0, __p1, __p2) \
	LP3(240, LONG , DoPkt1, \
		struct MsgPort *, __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoPkt2(__p0, __p1, __p2, __p3) \
	LP4(240, LONG , DoPkt2, \
		struct MsgPort *, __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoPkt3(__p0, __p1, __p2, __p3, __p4) \
	LP5(240, LONG , DoPkt3, \
		struct MsgPort *, __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		LONG , __p4, d5, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoPkt4(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(240, LONG , DoPkt4, \
		struct MsgPort *, __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		LONG , __p4, d5, \
		LONG , __p5, d6, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SendPkt(__p0, __p1, __p2) \
	LP3NR(246, SendPkt, \
		struct DosPacket *, __p0, d1, \
		struct MsgPort *, __p1, d2, \
		struct MsgPort *, __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WaitPkt() \
	LP0(252, struct DosPacket *, WaitPkt, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReplyPkt(__p0, __p1, __p2) \
	LP3NR(258, ReplyPkt, \
		struct DosPacket *, __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AbortPkt(__p0, __p1) \
	LP2NR(264, AbortPkt, \
		struct MsgPort *, __p0, d1, \
		struct DosPacket *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockRecord(__p0, __p1, __p2, __p3, __p4) \
	LP5(270, BOOL , LockRecord, \
		BPTR , __p0, d1, \
		ULONG , __p1, d2, \
		ULONG , __p2, d3, \
		ULONG , __p3, d4, \
		ULONG , __p4, d5, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockRecords(__p0, __p1) \
	LP2(276, BOOL , LockRecords, \
		struct RecordLock *, __p0, d1, \
		ULONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnLockRecord(__p0, __p1, __p2) \
	LP3(282, BOOL , UnLockRecord, \
		BPTR , __p0, d1, \
		ULONG , __p1, d2, \
		ULONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnLockRecords(__p0) \
	LP1(288, BOOL , UnLockRecords, \
		struct RecordLock *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SelectInput(__p0) \
	LP1(294, BPTR , SelectInput, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SelectOutput(__p0) \
	LP1(300, BPTR , SelectOutput, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FGetC(__p0) \
	LP1(306, LONG , FGetC, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FPutC(__p0, __p1) \
	LP2(312, LONG , FPutC, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnGetC(__p0, __p1) \
	LP2(318, LONG , UnGetC, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FRead(__p0, __p1, __p2, __p3) \
	LP4(324, LONG , FRead, \
		BPTR , __p0, d1, \
		APTR , __p1, d2, \
		ULONG , __p2, d3, \
		ULONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FWrite(__p0, __p1, __p2, __p3) \
	LP4(330, LONG , FWrite, \
		BPTR , __p0, d1, \
		CONST APTR , __p1, d2, \
		ULONG , __p2, d3, \
		ULONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FGets(__p0, __p1, __p2) \
	LP3(336, STRPTR , FGets, \
		BPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		ULONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FPuts(__p0, __p1) \
	LP2(342, LONG , FPuts, \
		BPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VFWritef(__p0, __p1, __p2) \
	LP3NR(348, VFWritef, \
		BPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		CONST LONG *, __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VFPrintf(__p0, __p1, __p2) \
	LP3(354, LONG , VFPrintf, \
		BPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		CONST APTR , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Flush(__p0) \
	LP1(360, LONG , Flush, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetVBuf(__p0, __p1, __p2, __p3) \
	LP4(366, LONG , SetVBuf, \
		BPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DupLockFromFH(__p0) \
	LP1(372, BPTR , DupLockFromFH, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenFromLock(__p0) \
	LP1(378, BPTR , OpenFromLock, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParentOfFH(__p0) \
	LP1(384, BPTR , ParentOfFH, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExamineFH(__p0, __p1) \
	LP2(390, BOOL , ExamineFH, \
		BPTR , __p0, d1, \
		struct FileInfoBlock *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFileDate(__p0, __p1) \
	LP2(396, LONG , SetFileDate, \
		CONST_STRPTR , __p0, d1, \
		CONST struct DateStamp *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NameFromLock(__p0, __p1, __p2) \
	LP3(402, LONG , NameFromLock, \
		BPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NameFromFH(__p0, __p1, __p2) \
	LP3(408, LONG , NameFromFH, \
		BPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SplitName(__p0, __p1, __p2, __p3, __p4) \
	LP5(414, WORD , SplitName, \
		CONST_STRPTR , __p0, d1, \
		ULONG , __p1, d2, \
		STRPTR , __p2, d3, \
		LONG , __p3, d4, \
		LONG , __p4, d5, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SameLock(__p0, __p1) \
	LP2(420, LONG , SameLock, \
		BPTR , __p0, d1, \
		BPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetMode(__p0, __p1) \
	LP2(426, LONG , SetMode, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExAll(__p0, __p1, __p2, __p3, __p4) \
	LP5(432, LONG , ExAll, \
		BPTR , __p0, d1, \
		struct ExAllData *, __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		struct ExAllControl *, __p4, d5, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadLink(__p0, __p1, __p2, __p3, __p4) \
	LP5(438, LONG , ReadLink, \
		struct MsgPort *, __p0, d1, \
		BPTR , __p1, d2, \
		CONST_STRPTR , __p2, d3, \
		STRPTR , __p3, d4, \
		ULONG , __p4, d5, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeLink(__p0, __p1, __p2) \
	LP3(444, LONG , MakeLink, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeMode(__p0, __p1, __p2) \
	LP3(450, LONG , ChangeMode, \
		LONG , __p0, d1, \
		BPTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFileSize(__p0, __p1, __p2) \
	LP3(456, LONG , SetFileSize, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetIoErr(__p0) \
	LP1(462, LONG , SetIoErr, \
		LONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Fault(__p0, __p1, __p2, __p3) \
	LP4(468, BOOL , Fault, \
		LONG , __p0, d1, \
		STRPTR , __p1, d2, \
		STRPTR , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PrintFault(__p0, __p1) \
	LP2(474, BOOL , PrintFault, \
		LONG , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ErrorReport(__p0, __p1, __p2, __p3) \
	LP4(480, LONG , ErrorReport, \
		LONG , __p0, d1, \
		LONG , __p1, d2, \
		ULONG , __p2, d3, \
		struct MsgPort *, __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Cli() \
	LP0(492, struct CommandLineInterface *, Cli, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateNewProc(__p0) \
	LP1(498, struct Process *, CreateNewProc, \
		CONST struct TagItem *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateNewProcTagList(__p0) \
	LP1(498, struct Process *, CreateNewProcTagList, \
		CONST struct TagItem *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RunCommand(__p0, __p1, __p2, __p3) \
	LP4(504, LONG , RunCommand, \
		BPTR , __p0, d1, \
		LONG , __p1, d2, \
		CONST_STRPTR , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetConsoleTask() \
	LP0(510, struct MsgPort *, GetConsoleTask, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetConsoleTask(__p0) \
	LP1(516, struct MsgPort *, SetConsoleTask, \
		CONST struct MsgPort *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetFileSysTask() \
	LP0(522, struct MsgPort *, GetFileSysTask, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFileSysTask(__p0) \
	LP1(528, struct MsgPort *, SetFileSysTask, \
		CONST struct MsgPort *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetArgStr() \
	LP0(534, STRPTR , GetArgStr, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetArgStr(__p0) \
	LP1(540, BOOL , SetArgStr, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindCliProc(__p0) \
	LP1(546, struct Process *, FindCliProc, \
		ULONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MaxCli() \
	LP0(552, ULONG , MaxCli, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetCurrentDirName(__p0) \
	LP1(558, BOOL , SetCurrentDirName, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetCurrentDirName(__p0, __p1) \
	LP2(564, BOOL , GetCurrentDirName, \
		STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetProgramName(__p0) \
	LP1(570, BOOL , SetProgramName, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetProgramName(__p0, __p1) \
	LP2(576, BOOL , GetProgramName, \
		STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetPrompt(__p0) \
	LP1(582, BOOL , SetPrompt, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetPrompt(__p0, __p1) \
	LP2(588, BOOL , GetPrompt, \
		STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetProgramDir(__p0) \
	LP1(594, BPTR , SetProgramDir, \
		BPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetProgramDir() \
	LP0(600, BPTR , GetProgramDir, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SystemTagList(__p0, __p1) \
	LP2(606, LONG , SystemTagList, \
		CONST_STRPTR , __p0, d1, \
		CONST struct TagItem *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define System(__p0, __p1) \
	LP2(606, LONG , System, \
		CONST_STRPTR , __p0, d1, \
		CONST struct TagItem *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AssignLock(__p0, __p1) \
	LP2(612, LONG , AssignLock, \
		CONST_STRPTR , __p0, d1, \
		BPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AssignLate(__p0, __p1) \
	LP2(618, BOOL , AssignLate, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AssignPath(__p0, __p1) \
	LP2(624, BOOL , AssignPath, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AssignAdd(__p0, __p1) \
	LP2(630, BOOL , AssignAdd, \
		CONST_STRPTR , __p0, d1, \
		BPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemAssignList(__p0, __p1) \
	LP2(636, LONG , RemAssignList, \
		CONST_STRPTR , __p0, d1, \
		BPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDeviceProc(__p0, __p1) \
	LP2(642, struct DevProc *, GetDeviceProc, \
		CONST_STRPTR , __p0, d1, \
		struct DevProc *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeDeviceProc(__p0) \
	LP1NR(648, FreeDeviceProc, \
		struct DevProc *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockDosList(__p0) \
	LP1(654, struct DosList *, LockDosList, \
		ULONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnLockDosList(__p0) \
	LP1NR(660, UnLockDosList, \
		ULONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttemptLockDosList(__p0) \
	LP1(666, struct DosList *, AttemptLockDosList, \
		ULONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemDosEntry(__p0) \
	LP1(672, BOOL , RemDosEntry, \
		struct DosList *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddDosEntry(__p0) \
	LP1(678, LONG , AddDosEntry, \
		struct DosList *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindDosEntry(__p0, __p1, __p2) \
	LP3(684, struct DosList *, FindDosEntry, \
		CONST struct DosList *, __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		ULONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NextDosEntry(__p0, __p1) \
	LP2(690, struct DosList *, NextDosEntry, \
		CONST struct DosList *, __p0, d1, \
		ULONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeDosEntry(__p0, __p1) \
	LP2(696, struct DosList *, MakeDosEntry, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeDosEntry(__p0) \
	LP1NR(702, FreeDosEntry, \
		struct DosList *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsFileSystem(__p0) \
	LP1(708, BOOL , IsFileSystem, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Format(__p0, __p1, __p2) \
	LP3(714, BOOL , Format, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		ULONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Relabel(__p0, __p1) \
	LP2(720, LONG , Relabel, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Inhibit(__p0, __p1) \
	LP2(726, LONG , Inhibit, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddBuffers(__p0, __p1) \
	LP2(732, LONG , AddBuffers, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CompareDates(__p0, __p1) \
	LP2(738, LONG , CompareDates, \
		CONST struct DateStamp *, __p0, d1, \
		CONST struct DateStamp *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DateToStr(__p0) \
	LP1(744, LONG , DateToStr, \
		struct DateTime *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StrToDate(__p0) \
	LP1(750, LONG , StrToDate, \
		struct DateTime *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InternalLoadSeg(__p0, __p1, __p2, __p3) \
	LP4(756, BPTR , InternalLoadSeg, \
		BPTR , __p0, d0, \
		BPTR , __p1, a0, \
		CONST LONG *, __p2, a1, \
		LONG *, __p3, a2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InternalUnLoadSeg(__p0, __p1) \
	LP2FP(762, BOOL , InternalUnLoadSeg, \
		BPTR , __p0, d1, \
		__ft, __p1, a1, \
		, DOS_BASE_NAME, VOID (*CONST  __ft) __CLIB_PROTOTYPE((STRPTR,ULONG)) , 0, 0, 0, 0, 0, 0)

#define NewLoadSeg(__p0, __p1) \
	LP2(768, BPTR , NewLoadSeg, \
		CONST_STRPTR , __p0, d1, \
		CONST struct TagItem *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewLoadSegTagList(__p0, __p1) \
	LP2(768, BPTR , NewLoadSegTagList, \
		CONST_STRPTR , __p0, d1, \
		CONST struct TagItem *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddSegment(__p0, __p1, __p2) \
	LP3(774, LONG , AddSegment, \
		CONST_STRPTR , __p0, d1, \
		BPTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindSegment(__p0, __p1, __p2) \
	LP3(780, struct Segment *, FindSegment, \
		CONST_STRPTR , __p0, d1, \
		CONST struct Segment *, __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemSegment(__p0) \
	LP1(786, LONG , RemSegment, \
		struct Segment *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CheckSignal(__p0) \
	LP1(792, LONG , CheckSignal, \
		LONG , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadArgs(__p0, __p1, __p2) \
	LP3(798, struct RDArgs *, ReadArgs, \
		CONST_STRPTR , __p0, d1, \
		LONG *, __p1, d2, \
		struct RDArgs *, __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindArg(__p0, __p1) \
	LP2(804, LONG , FindArg, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadItem(__p0, __p1, __p2) \
	LP3(810, LONG , ReadItem, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		struct CSource *, __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StrToLong(__p0, __p1) \
	LP2(816, LONG , StrToLong, \
		CONST_STRPTR , __p0, d1, \
		LONG *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MatchFirst(__p0, __p1) \
	LP2(822, LONG , MatchFirst, \
		CONST_STRPTR , __p0, d1, \
		struct AnchorPath *, __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MatchNext(__p0) \
	LP1(828, LONG , MatchNext, \
		struct AnchorPath *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MatchEnd(__p0) \
	LP1NR(834, MatchEnd, \
		struct AnchorPath *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParsePattern(__p0, __p1, __p2) \
	LP3(840, LONG , ParsePattern, \
		CONST_STRPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MatchPattern(__p0, __p1) \
	LP2(846, BOOL , MatchPattern, \
		CONST_STRPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeArgs(__p0) \
	LP1NR(858, FreeArgs, \
		struct RDArgs *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FilePart(__p0) \
	LP1(870, STRPTR , FilePart, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PathPart(__p0) \
	LP1(876, STRPTR , PathPart, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddPart(__p0, __p1, __p2) \
	LP3(882, BOOL , AddPart, \
		STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		ULONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StartNotify(__p0) \
	LP1(888, BOOL , StartNotify, \
		struct NotifyRequest *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EndNotify(__p0) \
	LP1NR(894, EndNotify, \
		struct NotifyRequest *, __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetVar(__p0, __p1, __p2, __p3) \
	LP4(900, BOOL , SetVar, \
		CONST_STRPTR , __p0, d1, \
		CONST_STRPTR , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetVar(__p0, __p1, __p2, __p3) \
	LP4(906, LONG , GetVar, \
		CONST_STRPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteVar(__p0, __p1) \
	LP2(912, LONG , DeleteVar, \
		CONST_STRPTR , __p0, d1, \
		ULONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindVar(__p0, __p1) \
	LP2(918, struct LocalVar *, FindVar, \
		CONST_STRPTR , __p0, d1, \
		ULONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CliInitNewcli(__p0) \
	LP1(930, LONG , CliInitNewcli, \
		struct DosPacket *, __p0, a0, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CliInitRun(__p0) \
	LP1(936, LONG , CliInitRun, \
		struct DosPacket *, __p0, a0, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteChars(__p0, __p1) \
	LP2(942, LONG , WriteChars, \
		CONST_STRPTR , __p0, d1, \
		ULONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PutStr(__p0) \
	LP1(948, LONG , PutStr, \
		CONST_STRPTR , __p0, d1, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VPrintf(__p0, __p1) \
	LP2(954, LONG , VPrintf, \
		CONST_STRPTR , __p0, d1, \
		CONST APTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ParsePatternNoCase(__p0, __p1, __p2) \
	LP3(966, LONG , ParsePatternNoCase, \
		CONST_STRPTR , __p0, d1, \
		UBYTE *, __p1, d2, \
		LONG , __p2, d3, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MatchPatternNoCase(__p0, __p1) \
	LP2(972, BOOL , MatchPatternNoCase, \
		CONST_STRPTR , __p0, d1, \
		STRPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SameDevice(__p0, __p1) \
	LP2(984, BOOL , SameDevice, \
		BPTR , __p0, d1, \
		BPTR , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExAllEnd(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(990, ExAllEnd, \
		BPTR , __p0, d1, \
		struct ExAllData *, __p1, d2, \
		LONG , __p2, d3, \
		LONG , __p3, d4, \
		struct ExAllControl *, __p4, d5, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetOwner(__p0, __p1) \
	LP2(996, BOOL , SetOwner, \
		CONST_STRPTR , __p0, d1, \
		LONG , __p1, d2, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddSegmentTagList(__p0) \
	LP1(1002, LONG , AddSegmentTagList, \
		struct TagItem *, __p0, a0, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindSegmentTagList(__p0) \
	LP1(1008, struct Segment *, FindSegmentTagList, \
		struct TagItem *, __p0, a0, \
		, DOS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Seek64(__p0, __p1, __p2) \
	(((QUAD (*)(void *, BPTR , QUAD , LONG ))*(void**)((long)(DOS_BASE_NAME) - 1066))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define SetFileSize64(__p0, __p1, __p2) \
	(((QUAD (*)(void *, BPTR , QUAD , LONG ))*(void**)((long)(DOS_BASE_NAME) - 1072))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define LockRecord64(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(void *, BPTR , UQUAD , UQUAD , ULONG , ULONG ))*(void**)((long)(DOS_BASE_NAME) - 1078))((void*)(DOS_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define LockRecords64(__p0, __p1) \
	(((LONG (*)(void *, struct RecordLock64 *, ULONG ))*(void**)((long)(DOS_BASE_NAME) - 1084))((void*)(DOS_BASE_NAME), __p0, __p1))

#define UnLockRecord64(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , UQUAD , UQUAD ))*(void**)((long)(DOS_BASE_NAME) - 1090))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define UnLockRecords64(__p0) \
	(((LONG (*)(void *, struct RecordLock64 *))*(void**)((long)(DOS_BASE_NAME) - 1096))((void*)(DOS_BASE_NAME), __p0))

#define Examine64(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , struct FileInfoBlock *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1144))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define Examine64TagList(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , struct FileInfoBlock *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1144))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define ExNext64(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , struct FileInfoBlock *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1150))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define ExNext64TagList(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , struct FileInfoBlock *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1150))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define ExamineFH64(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , struct FileInfoBlock *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1156))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define ExamineFH64TagList(__p0, __p1, __p2) \
	(((LONG (*)(void *, BPTR , struct FileInfoBlock *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1156))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define NewReadLink(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(void *, struct MsgPort *, BPTR , CONST_STRPTR , UBYTE *, LONG ))*(void**)((long)(DOS_BASE_NAME) - 1114))((void*)(DOS_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define GetFileSysAttr(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, CONST_STRPTR , LONG , APTR , LONG ))*(void**)((long)(DOS_BASE_NAME) - 1120))((void*)(DOS_BASE_NAME), __p0, __p1, __p2, __p3))

#define GetSegListAttr(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, BPTR , LONG , APTR , LONG ))*(void**)((long)(DOS_BASE_NAME) - 1126))((void*)(DOS_BASE_NAME), __p0, __p1, __p2, __p3))

#define SetDosObjectAttr(__p0, __p1, __p2) \
	(((LONG (*)(void *, ULONG , APTR , struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1132))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define SetDosObjectAttrTagList(__p0, __p1, __p2) \
	(((LONG (*)(void *, ULONG , APTR , struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1132))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define GetDosObjectAttr(__p0, __p1, __p2) \
	(((LONG (*)(void *, ULONG , APTR , struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1138))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define GetDosObjectAttrTagList(__p0, __p1, __p2) \
	(((LONG (*)(void *, ULONG , APTR , struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1138))((void*)(DOS_BASE_NAME), __p0, __p1, __p2))

#define ReleaseCLINumber(__p0) \
	(((void (*)(void *, LONG ))*(void**)((long)(DOS_BASE_NAME) - 1162))((void*)(DOS_BASE_NAME), __p0))

#define QueryCLIDataTagList(__p0) \
	(((struct CLIData *(*)(void *, struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1168))((void*)(DOS_BASE_NAME), __p0))

#define FreeCLIData(__p0) \
	(((void (*)(void *, struct CLIData *))*(void**)((long)(DOS_BASE_NAME) - 1174))((void*)(DOS_BASE_NAME), __p0))

#define GetSegListAttrTagList(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(void *, BPTR , LONG , APTR , LONG , struct TagItem *))*(void**)((long)(DOS_BASE_NAME) - 1180))((void*)(DOS_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocDosObjectTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocDosObject(__p0, (CONST struct TagItem *)_tags);})

#define FWritef(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	VFWritef(__p0, __p1, (CONST LONG *)_tags);})

#define FPrintf(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	VFPrintf(__p0, __p1, (CONST APTR )_tags);})

#define CreateNewProcTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateNewProc((CONST struct TagItem *)_tags);})

#define SystemTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SystemTagList(__p0, (CONST struct TagItem *)_tags);})

#define NewLoadSegTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewLoadSeg(__p0, (CONST struct TagItem *)_tags);})

#define Printf(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	VPrintf(__p0, (CONST APTR )_tags);})

#define AddSegmentTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddSegmentTagList((struct TagItem *)_tags);})

#define FindSegmentTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	FindSegmentTagList((struct TagItem *)_tags);})

#define Examine64Tags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Examine64(__p0, __p1, (struct TagItem *)_tags);})

#define ExNext64Tags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ExNext64(__p0, __p1, (struct TagItem *)_tags);})

#define ExamineFH64Tags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ExamineFH64(__p0, __p1, (struct TagItem *)_tags);})

#define SetDosObjectAttrTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetDosObjectAttr(__p0, __p1, (struct TagItem *)_tags);})

#define GetDosObjectAttrTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetDosObjectAttr(__p0, __p1, (struct TagItem *)_tags);})

#define QueryCLIDataTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	QueryCLIDataTagList((struct TagItem *)_tags);})

#define GetSegListAttrTags(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetSegListAttrTagList(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_DOS_H */
