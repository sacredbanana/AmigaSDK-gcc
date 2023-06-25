
#ifdef __amigaos4__
 #error Include <proto/> header files, not <pragmas/> header files in OS4.
#endif 


#ifndef PRAGMAS_DOS_PRAGMAS_H
#define PRAGMAS_DOS_PRAGMAS_H

/*
**	$Id: dos_pragmas.h 40.99 2010-04-26 07:26:16 cwenzel Exp $
**
**	Direct ROM interface (pragma) definitions.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#if defined(LATTICE) || defined(__SASC) || defined(_DCC)
#ifndef __CLIB_PRAGMA_LIBCALL
#define __CLIB_PRAGMA_LIBCALL
#endif /* __CLIB_PRAGMA_LIBCALL */
#else /* __MAXON__, __STORM__ or AZTEC_C */
#ifndef __CLIB_PRAGMA_AMICALL
#define __CLIB_PRAGMA_AMICALL
#endif /* __CLIB_PRAGMA_AMICALL */
#endif /* */

#if defined(__SASC) || defined(__STORM__)
#ifndef __CLIB_PRAGMA_TAGCALL
#define __CLIB_PRAGMA_TAGCALL
#endif /* __CLIB_PRAGMA_TAGCALL */
#endif /* __MAXON__, __STORM__ or AZTEC_C */

#ifndef CLIB_DOS_PROTOS_H
#include <clib/dos_protos.h>
#endif /* CLIB_DOS_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Open 1e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Close 24 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Read 2a 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Write 30 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Input 36 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Output 3c 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETESeek 42 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Delete 48 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Rename 4e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Lock 54 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnLock 5a 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DupLock 60 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEExamine 66 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEExNext 6c 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Info 72 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CreateDir 78 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetCurrentDir 7e 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase IoErr 84 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETECreateProc 8a 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase LoadSegOVL 96 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnLoadSeg 9c 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- (1 function slot reserved here) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase LoadSeg a8 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEDeviceProc ae 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetComment b4 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetProtection ba 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DateStamp c0 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Delay c6 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WaitForChar cc 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ParentDir d2 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase IsInteractive d8 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEExecute de 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- functions in V36 or higher (Release 2.0) ---*/
/*	DOS Object creation/deletion */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AllocDosObject e4 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AllocDosObjectTagList e4 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase AllocDosObjectTags e4 2102
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FreeDosObject ea 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Packet Level routines */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DoPkt f0 765432107
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DoPkt0 f0 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DoPkt1 f0 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DoPkt2 f0 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DoPkt3 f0 5432105
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DoPkt4 f0 65432106
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SendPkt f6 32103
#endif /* __CLIB_PRAGMA_LIBCALL */

/*     Parameter added at V47, (for v50 release) backward compatible for processes. */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WaitPkt fc 101
#endif /* __CLIB_PRAGMA_LIBCALL */


#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReplyPkt 102 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- (1 function slot reserved here) ---*/
/*	Record Locking */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase LockRecord 10e 5432105
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase LockRecords 114 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnLockRecord 11a 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnLockRecords 120 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Buffered File I/O */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SelectInput 126 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SelectOutput 12c 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FGetC 132 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FPutC 138 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FUnGetC 13e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FRead 144 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FWrite 14a 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FGets 150 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FPuts 156 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase VFPrintf 162 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase FPrintf 162 32103
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FFlush 168 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETESetVBuf 16e 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	DOS Object Management */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DupLockFromFH 174 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OpenFromLock 17a 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ParentOfFH 180 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEExamineFH 186 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetDate 18c 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NameFromLock 192 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NameFromFH 198 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SplitName 19e 5432105
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SameLock 1a4 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetMode 1aa 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEExAll 1b0 5432105
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReadSoftLink 1b6 5432105
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MakeLink 1bc 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ChangeMode 1c2 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETESetFileSize 1c8 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Error Handling */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetIoErr 1ce 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Fault 1d4 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase PrintFault 1da 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ErrorReport 1e0 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Process Management */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Cli 1ec 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CreateNewProc 1f2 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CreateNewProcTagList 1f2 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase CreateNewProcTags 1f2 101
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase RunCommand 1f8 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetConsolePort 1fe 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetConsolePort 204 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetFileSysPort 20a 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetFileSysPort 210 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetArgStr 216 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetArgStr 21c 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindCliProc 222 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MaxCli 228 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetCliCurrentDirName 22e 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetCliCurrentDirName 234 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetCliProgramName 23a 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetCliProgramName 240 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetCliPrompt 246 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetCliPrompt 24c 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetProgramDir 252 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetProgramDir 258 00
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Device List Management */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SystemTagList 25e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase System 25e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase SystemTags 25e 2102
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AssignLock 264 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AssignLate 26a 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AssignPath 270 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AssignAdd 276 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase RemAssignList 27c 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetDeviceProc 282 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FreeDeviceProc 288 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase LockDosList 28e 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnLockDosList 294 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AttemptLockDosList 29a 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase RemDosEntry 2a0 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddDosEntry 2a6 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindDosEntry 2ac 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NextDosEntry 2b2 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MakeDosEntry 2b8 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FreeDosEntry 2be 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase IsFileSystem 2c4 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Handler Interface */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Format 2ca 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Relabel 2d0 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Inhibit 2d6 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddBuffers 2dc 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Date, Time Routines */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CompareDates 2e2 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DateToStr 2e8 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase StrToDate 2ee 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Image Management */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase InternalLoadSeg 2f4 98003
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase InternalUnLoadSeg 2fa 9102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NewLoadSeg 300 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NewLoadSegTagList 300 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase NewLoadSegTags 300 2102
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddSegment 306 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindSegment 30c 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase RemSegment 312 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Command Support */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CheckSignal 318 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReadArgs 31e 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindArg 324 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReadItem 32a 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase StrToLong 330 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MatchFirst 336 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MatchNext 33c 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MatchEnd 342 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ParsePattern 348 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MatchPattern 34e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- (1 function slot reserved here) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FreeArgs 35a 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase StartPart 360 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FilePart 366 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase PathPart 36c 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddPart 372 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Notification */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase StartNotify 378 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase EndNotify 37e 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*	Environment Variable functions */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetVar 384 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetVar 38a 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DeleteVar 390 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindVar 396 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CliInitNewcli 3a2 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CliInitRun 3a8 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WriteChars 3ae 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase PutStr 3b4 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase VPrintf 3ba 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase Printf 3ba 2102
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
/*--- (1 function slot reserved here) ---*/
/* these were unimplemented until dos 36.147 */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ParsePatternNoCase 3c6 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MatchPatternNoCase 3cc 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
/* this was added for V37 dos, returned 0 before then. */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SameDevice 3d8 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
/* These calls were added for V39 dos: */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETEExAllEnd 3de 5432105
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase OBSOLETESetOwner 3e4 2102
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetEntryData 3ea 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReadLineItem 3f0 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase ReadLineItemTags 3f0 32103
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
/*--- (1 function slot reserved here) ---*/
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetCurrentDir 402 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NonBlockingModifyDosEntry 408 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SecondsToDateStamp 40e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DateStampToSeconds 414 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FixDateStamp 41a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddDates 420 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SubtractDates 426 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddSegmentTagList 42c 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ParseCapturePattern 432 109804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CapturePattern 438 A09804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReleaseCapturedExpressions 43e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindTrackedAddress 444 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase TrackAddressList 44a 2A190806
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase TrackSegmentList 450 190804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnTrackAddress 456 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase UnTrackSegmentList 45c 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetExitData 462 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase PutErrStr 468 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ErrorOutput 46e 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SelectErrorOutput 474 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase MountDevice 47a A9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase MountDeviceTags 47a A9803
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetProcWindow 480 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FindSegmentStackSize 486 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CalculateSegmentChecksum 48c 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AllocSegList 492 109804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetSegListInfo 498 8002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase GetSegListInfoTags 498 8002
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddSegListTail 49e 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DevNameFromLock 4a4 432104
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetProcMsgPort 4aa 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WaitForData 4b0 21003
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetBlockingMode 4b6 1002
#endif /* __CLIB_PRAGMA_LIBCALL */
/*  Shell Path handling Functions v50.51 */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetCurrentCmdPathList 4bc 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AllocateCmdPathList 4c2 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FreeCmdPathList 4c8 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase RemoveCmdPathNode 4ce 0802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AddCmdPathNode 4d4 10803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SearchCmdPathList 4da BA9804
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase SearchCmdPathListTags 4da BA9804
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ScanVars 4e0 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetProcSegList 4e6 0802
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 50.66 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase HexToLong 4ec 2102
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetDeviceProcFlags 4f2 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DosControl 4f8 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase DosControlTags 4f8 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CreateDirTree 4fe 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NotifyVar 504 432104
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 50.80 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetDiskFileSystemData 50a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FreeDiskFileSystemData 510 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.03 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FOpen 516 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FClose 51c 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FOpenFromLock 522 2102
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 54.81 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DupCmdPathList 528 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.12 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase TimedDosRequester 52e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase TimedDosRequesterTags 52e 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
/*  */
/* --- added 51.13 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase RenameDosEntry 534 2102
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.29 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DismountDevice 53a A9803
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.32 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DupFileHandle 540 101
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DevNameFromFH 546 432104
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.43 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AssignAddToList 54c 32103
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.45 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetFileHandleAttr 552 8002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase SetFileHandleAttrTags 552 8002
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

/* -- added 51.46 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FileSystemAttr 558 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase FileSystemAttrTags 558 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

/* -- added 51.47 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FReadLine 55e 2102
#endif /* __CLIB_PRAGMA_LIBCALL */

/* -- added 51.61 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CopyStringBSTRToC 564 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CopyStringCToBSTR 56a 32103
#endif /* __CLIB_PRAGMA_LIBCALL */


/* --- added 51.75 --- */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ProcessScan 5a6 32103
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NotifyDosListChange 5ac 32103
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 51.80 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NotifyProcListChange 5b2 32103
#endif /* __CLIB_PRAGMA_LIBCALL */

/* -- added 51.96 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetDiskInfo 5b8 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase GetDiskInfoTags 5b8 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

/* -- added 51.100 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WriteProtectVolume 5be 432104
#endif /* __CLIB_PRAGMA_LIBCALL */

/* -- added 51.104 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ExamineObject 5c4 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase ExamineObjectTags 5c4 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ExamineDir 5ca 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ObtainDirContext 5d0 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase ObtainDirContextTags 5d0 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReleaseDirContext 5d6 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetOwnerInfo 5dc 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase GetOwnerInfoTags 5dc 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SetOwnerInfo 5e2 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase SetOwnerInfoTags 5e2 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase LockTagList 5e8 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase LockTags 5e8 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetPID 5ee 0802
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FlushVolume 5f4 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ObtainConsoleData 5fa 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase ObtainConsoleDataTags 5fa 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ReleaseConsoleData 600 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase Serialize 606 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase NameFromPort 60c 109804
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase DevNameFromPort 612 109804
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SameFH 618 2102
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase IsFileSystemPort 61e 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase InhibitPort 624 0802
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FormatPort 62a 109804
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase SerializePort 630 801
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FlushVolumePort 636 801
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 53.129 --- */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase FileHandleScan 63c 32103
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 53.136 --- */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase GetFileSystemVectorPort 642 0802
#endif /* __CLIB_PRAGMA_LIBCALL */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase ResolvePath 648 3B2A19807
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- added 53.149 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WriteProtectVolumePort 64e 432104
#endif /* __CLIB_PRAGMA_LIBCALL */

/* ---  added 54.76 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase AsyncIO 654 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall DOSBase AsyncIOTags 654 801
 #endif /* __CLIB_PRAGMA_LIBCALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

/* --- Added 54.94 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase WaitForChildExit 65a 101
#endif /* __CLIB_PRAGMA_LIBCALL */

/* --- Added 54.107 --- */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall DOSBase CheckForChildExit 660 101
#endif /* __CLIB_PRAGMA_LIBCALL */
/*--- (4 function slots reserved here) ---*/

#endif /* PRAGMAS_DOS_PRAGMAS_H */
