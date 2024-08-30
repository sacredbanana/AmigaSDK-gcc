#ifndef PRAGMA_DOS_LIB_H
#define PRAGMA_DOS_LIB_H

/*
**	$VER: dos_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_DOS_PROTOS_H
#include <clib/dos_protos.h>
#endif /* CLIB_DOS_PROTOS_H */

/* "dos.library" */
#pragma amicall(DOSBase, 0x1e, Open(d1,d2))
#pragma amicall(DOSBase, 0x24, Close(d1))
#pragma amicall(DOSBase, 0x2a, Read(d1,d2,d3))
#pragma amicall(DOSBase, 0x30, Write(d1,d2,d3))
#pragma amicall(DOSBase, 0x36, Input())
#pragma amicall(DOSBase, 0x3c, Output())
#pragma amicall(DOSBase, 0x42, Seek(d1,d2,d3))
#pragma amicall(DOSBase, 0x48, DeleteFile(d1))
#pragma amicall(DOSBase, 0x4e, Rename(d1,d2))
#pragma amicall(DOSBase, 0x54, Lock(d1,d2))
#pragma amicall(DOSBase, 0x5a, UnLock(d1))
#pragma amicall(DOSBase, 0x60, DupLock(d1))
#pragma amicall(DOSBase, 0x66, Examine(d1,d2))
#pragma amicall(DOSBase, 0x6c, ExNext(d1,d2))
#pragma amicall(DOSBase, 0x72, Info(d1,d2))
#pragma amicall(DOSBase, 0x78, CreateDir(d1))
#pragma amicall(DOSBase, 0x7e, CurrentDir(d1))
#pragma amicall(DOSBase, 0x84, IoErr())
#pragma amicall(DOSBase, 0x8a, CreateProc(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x90, Exit(d1))
#pragma amicall(DOSBase, 0x96, LoadSeg(d1))
#pragma amicall(DOSBase, 0x9c, UnLoadSeg(d1))
#pragma amicall(DOSBase, 0xae, DeviceProc(d1))
#pragma amicall(DOSBase, 0xb4, SetComment(d1,d2))
#pragma amicall(DOSBase, 0xba, SetProtection(d1,d2))
#pragma amicall(DOSBase, 0xc0, DateStamp(d1))
#pragma amicall(DOSBase, 0xc6, Delay(d1))
#pragma amicall(DOSBase, 0xcc, WaitForChar(d1,d2))
#pragma amicall(DOSBase, 0xd2, ParentDir(d1))
#pragma amicall(DOSBase, 0xd8, IsInteractive(d1))
#pragma amicall(DOSBase, 0xde, Execute(d1,d2,d3))
/*--- functions in V36 or higher (Release 2.0) ---*/
/*	DOS Object creation/deletion */
#pragma amicall(DOSBase, 0xe4, AllocDosObject(d1,d2))
#pragma amicall(DOSBase, 0xe4, AllocDosObjectTagList(d1,d2))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0xe4, AllocDosObjectTags(d1,d2))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0xea, FreeDosObject(d1,d2))
/*	Packet Level routines */
#pragma amicall(DOSBase, 0xf0, DoPkt(d1,d2,d3,d4,d5,d6,d7))
#pragma amicall(DOSBase, 0xf0, DoPkt0(d1,d2))
#pragma amicall(DOSBase, 0xf0, DoPkt1(d1,d2,d3))
#pragma amicall(DOSBase, 0xf0, DoPkt2(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0xf0, DoPkt3(d1,d2,d3,d4,d5))
#pragma amicall(DOSBase, 0xf0, DoPkt4(d1,d2,d3,d4,d5,d6))
#pragma amicall(DOSBase, 0xf6, SendPkt(d1,d2,d3))
#pragma amicall(DOSBase, 0xfc, WaitPkt())
#pragma amicall(DOSBase, 0x102, ReplyPkt(d1,d2,d3))
#pragma amicall(DOSBase, 0x108, AbortPkt(d1,d2))
/*	Record Locking */
#pragma amicall(DOSBase, 0x10e, LockRecord(d1,d2,d3,d4,d5))
#pragma amicall(DOSBase, 0x114, LockRecords(d1,d2))
#pragma amicall(DOSBase, 0x11a, UnLockRecord(d1,d2,d3))
#pragma amicall(DOSBase, 0x120, UnLockRecords(d1))
/*	Buffered File I/O */
#pragma amicall(DOSBase, 0x126, SelectInput(d1))
#pragma amicall(DOSBase, 0x12c, SelectOutput(d1))
#pragma amicall(DOSBase, 0x132, FGetC(d1))
#pragma amicall(DOSBase, 0x138, FPutC(d1,d2))
#pragma amicall(DOSBase, 0x13e, UnGetC(d1,d2))
#pragma amicall(DOSBase, 0x144, FRead(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x14a, FWrite(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x150, FGets(d1,d2,d3))
#pragma amicall(DOSBase, 0x156, FPuts(d1,d2))
#pragma amicall(DOSBase, 0x15c, VFWritef(d1,d2,d3))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x15c, FWritef(d1,d2,d3))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0x162, VFPrintf(d1,d2,d3))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x162, FPrintf(d1,d2,d3))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0x168, Flush(d1))
#pragma amicall(DOSBase, 0x16e, SetVBuf(d1,d2,d3,d4))
/*	DOS Object Management */
#pragma amicall(DOSBase, 0x174, DupLockFromFH(d1))
#pragma amicall(DOSBase, 0x17a, OpenFromLock(d1))
#pragma amicall(DOSBase, 0x180, ParentOfFH(d1))
#pragma amicall(DOSBase, 0x186, ExamineFH(d1,d2))
#pragma amicall(DOSBase, 0x18c, SetFileDate(d1,d2))
#pragma amicall(DOSBase, 0x192, NameFromLock(d1,d2,d3))
#pragma amicall(DOSBase, 0x198, NameFromFH(d1,d2,d3))
#pragma amicall(DOSBase, 0x19e, SplitName(d1,d2,d3,d4,d5))
#pragma amicall(DOSBase, 0x1a4, SameLock(d1,d2))
#pragma amicall(DOSBase, 0x1aa, SetMode(d1,d2))
#pragma amicall(DOSBase, 0x1b0, ExAll(d1,d2,d3,d4,d5))
#pragma amicall(DOSBase, 0x1b6, ReadLink(d1,d2,d3,d4,d5))
#pragma amicall(DOSBase, 0x1bc, MakeLink(d1,d2,d3))
#pragma amicall(DOSBase, 0x1c2, ChangeMode(d1,d2,d3))
#pragma amicall(DOSBase, 0x1c8, SetFileSize(d1,d2,d3))
/*	Error Handling */
#pragma amicall(DOSBase, 0x1ce, SetIoErr(d1))
#pragma amicall(DOSBase, 0x1d4, Fault(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x1da, PrintFault(d1,d2))
#pragma amicall(DOSBase, 0x1e0, ErrorReport(d1,d2,d3,d4))
/*--- (1 function slot reserved here) ---*/
/*	Process Management */
#pragma amicall(DOSBase, 0x1ec, Cli())
#pragma amicall(DOSBase, 0x1f2, CreateNewProc(d1))
#pragma amicall(DOSBase, 0x1f2, CreateNewProcTagList(d1))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x1f2, CreateNewProcTags(d1))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0x1f8, RunCommand(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x1fe, GetConsoleTask())
#pragma amicall(DOSBase, 0x204, SetConsoleTask(d1))
#pragma amicall(DOSBase, 0x20a, GetFileSysTask())
#pragma amicall(DOSBase, 0x210, SetFileSysTask(d1))
#pragma amicall(DOSBase, 0x216, GetArgStr())
#pragma amicall(DOSBase, 0x21c, SetArgStr(d1))
#pragma amicall(DOSBase, 0x222, FindCliProc(d1))
#pragma amicall(DOSBase, 0x228, MaxCli())
#pragma amicall(DOSBase, 0x22e, SetCurrentDirName(d1))
#pragma amicall(DOSBase, 0x234, GetCurrentDirName(d1,d2))
#pragma amicall(DOSBase, 0x23a, SetProgramName(d1))
#pragma amicall(DOSBase, 0x240, GetProgramName(d1,d2))
#pragma amicall(DOSBase, 0x246, SetPrompt(d1))
#pragma amicall(DOSBase, 0x24c, GetPrompt(d1,d2))
#pragma amicall(DOSBase, 0x252, SetProgramDir(d1))
#pragma amicall(DOSBase, 0x258, GetProgramDir())
/*	Device List Management */
#pragma amicall(DOSBase, 0x25e, SystemTagList(d1,d2))
#pragma amicall(DOSBase, 0x25e, System(d1,d2))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x25e, SystemTags(d1,d2))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0x264, AssignLock(d1,d2))
#pragma amicall(DOSBase, 0x26a, AssignLate(d1,d2))
#pragma amicall(DOSBase, 0x270, AssignPath(d1,d2))
#pragma amicall(DOSBase, 0x276, AssignAdd(d1,d2))
#pragma amicall(DOSBase, 0x27c, RemAssignList(d1,d2))
#pragma amicall(DOSBase, 0x282, GetDeviceProc(d1,d2))
#pragma amicall(DOSBase, 0x288, FreeDeviceProc(d1))
#pragma amicall(DOSBase, 0x28e, LockDosList(d1))
#pragma amicall(DOSBase, 0x294, UnLockDosList(d1))
#pragma amicall(DOSBase, 0x29a, AttemptLockDosList(d1))
#pragma amicall(DOSBase, 0x2a0, RemDosEntry(d1))
#pragma amicall(DOSBase, 0x2a6, AddDosEntry(d1))
#pragma amicall(DOSBase, 0x2ac, FindDosEntry(d1,d2,d3))
#pragma amicall(DOSBase, 0x2b2, NextDosEntry(d1,d2))
#pragma amicall(DOSBase, 0x2b8, MakeDosEntry(d1,d2))
#pragma amicall(DOSBase, 0x2be, FreeDosEntry(d1))
#pragma amicall(DOSBase, 0x2c4, IsFileSystem(d1))
/*	Handler Interface */
#pragma amicall(DOSBase, 0x2ca, Format(d1,d2,d3))
#pragma amicall(DOSBase, 0x2d0, Relabel(d1,d2))
#pragma amicall(DOSBase, 0x2d6, Inhibit(d1,d2))
#pragma amicall(DOSBase, 0x2dc, AddBuffers(d1,d2))
/*	Date, Time Routines */
#pragma amicall(DOSBase, 0x2e2, CompareDates(d1,d2))
#pragma amicall(DOSBase, 0x2e8, DateToStr(d1))
#pragma amicall(DOSBase, 0x2ee, StrToDate(d1))
/*	Image Management */
#pragma amicall(DOSBase, 0x2f4, InternalLoadSeg(d0,a0,a1,a2))
#pragma amicall(DOSBase, 0x2fa, InternalUnLoadSeg(d1,a1))
#pragma amicall(DOSBase, 0x300, NewLoadSeg(d1,d2))
#pragma amicall(DOSBase, 0x300, NewLoadSegTagList(d1,d2))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x300, NewLoadSegTags(d1,d2))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0x306, AddSegment(d1,d2,d3))
#pragma amicall(DOSBase, 0x30c, FindSegment(d1,d2,d3))
#pragma amicall(DOSBase, 0x312, RemSegment(d1))
/*	Command Support */
#pragma amicall(DOSBase, 0x318, CheckSignal(d1))
#pragma amicall(DOSBase, 0x31e, ReadArgs(d1,d2,d3))
#pragma amicall(DOSBase, 0x324, FindArg(d1,d2))
#pragma amicall(DOSBase, 0x32a, ReadItem(d1,d2,d3))
#pragma amicall(DOSBase, 0x330, StrToLong(d1,d2))
#pragma amicall(DOSBase, 0x336, MatchFirst(d1,d2))
#pragma amicall(DOSBase, 0x33c, MatchNext(d1))
#pragma amicall(DOSBase, 0x342, MatchEnd(d1))
#pragma amicall(DOSBase, 0x348, ParsePattern(d1,d2,d3))
#pragma amicall(DOSBase, 0x34e, MatchPattern(d1,d2))
/* Not currently implemented. */
#pragma amicall(DOSBase, 0x35a, FreeArgs(d1))
/*--- (1 function slot reserved here) ---*/
#pragma amicall(DOSBase, 0x366, FilePart(d1))
#pragma amicall(DOSBase, 0x36c, PathPart(d1))
#pragma amicall(DOSBase, 0x372, AddPart(d1,d2,d3))
/*	Notification */
#pragma amicall(DOSBase, 0x378, StartNotify(d1))
#pragma amicall(DOSBase, 0x37e, EndNotify(d1))
/*	Environment Variable functions */
#pragma amicall(DOSBase, 0x384, SetVar(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x38a, GetVar(d1,d2,d3,d4))
#pragma amicall(DOSBase, 0x390, DeleteVar(d1,d2))
#pragma amicall(DOSBase, 0x396, FindVar(d1,d2))
#pragma amicall(DOSBase, 0x3a2, CliInitNewcli(a0))
#pragma amicall(DOSBase, 0x3a8, CliInitRun(a0))
#pragma amicall(DOSBase, 0x3ae, WriteChars(d1,d2))
#pragma amicall(DOSBase, 0x3b4, PutStr(d1))
#pragma amicall(DOSBase, 0x3ba, VPrintf(d1,d2))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x3ba, Printf(d1,d2))
#endif /* __STORM__ */
/* new in dos V47 */
/* these were unimplemented until dos 36.147 */
#pragma amicall(DOSBase, 0x3c6, ParsePatternNoCase(d1,d2,d3))
#pragma amicall(DOSBase, 0x3cc, MatchPatternNoCase(d1,d2))
/* this was added for V37 dos, returned 0 before then. */
#pragma amicall(DOSBase, 0x3d8, SameDevice(d1,d2))

/* NOTE: the following entries did NOT exist before ks 36.303 (2.02) */
/* If you are going to use them, open dos.library with version 37 */

/* These calls were added for V39 dos: */
#pragma amicall(DOSBase, 0x3de, ExAllEnd(d1,d2,d3,d4,d5))
#pragma amicall(DOSBase, 0x3e4, SetOwner(d1,d2))
/* These were added in dos 36.147 */
/*--- (2 function slots reserved here) ---*/
/* Added with dos 47.4 */
#pragma amicall(DOSBase, 0x3f6, VolumeRequestHook(d1))
#pragma amicall(DOSBase, 0x402, GetCurrentDir())
/*--- (16 function slots reserved here) ---*/
#pragma amicall(DOSBase, 0x468, PutErrStr(d1))
#pragma amicall(DOSBase, 0x46e, ErrorOutput())
#pragma amicall(DOSBase, 0x474, SelectError(d1))
/*--- (1 function slot reserved here) ---*/
#pragma amicall(DOSBase, 0x480, DoShellMethodTagList(d0,a0))
#if defined(__STORM__)
#pragma tagcall(DOSBase, 0x480, DoShellMethod(d0,a0))
#endif /* __STORM__ */
#pragma amicall(DOSBase, 0x486, ScanStackToken(d1,d2))

#endif /* PRAGMA_DOS_LIB_H */
