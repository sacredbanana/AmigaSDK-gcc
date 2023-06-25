#ifndef DOS_INTERFACE_DEF_H
#define DOS_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.24.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef DOS_RECORD_H
#include <dos/record.h>
#endif
#ifndef DOS_RDARGS_H
#include <dos/rdargs.h>
#endif
#ifndef DOS_DOSASL_H
#include <dos/dosasl.h>
#endif
#ifndef DOS_VAR_H
#include <dos/var.h>
#endif
#ifndef DOS_NOTIFY_H
#include <dos/notify.h>
#endif
#ifndef DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef DOS_EXALL_H
#include <dos/exall.h>
#endif
#ifndef DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif
#ifndef DOS_DOSTAGS_H
#include <dos/dostags.h>
#endif
#ifndef DOS_MOUNT_H
#include <dos/mount.h>
#endif
#ifndef DOS_DOSHUNKS_H
#include <dos/doshunks.h>
#endif
#ifndef DOS_PATH_H
#include <dos/path.h>
#endif
#ifndef DOS_ANCHORPATH_H
#include <dos/anchorpath.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct DOSIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DOSIFace *Self);
	ULONG APICALL (*Release)(struct DOSIFace *Self);
	APTR Expunge_UNIMPLEMENTED;
	APTR Clone_UNIMPLEMENTED;
	BPTR APICALL (*Open)(struct DOSIFace *Self, CONST_STRPTR name, LONG accessMode);
	LONG APICALL (*Close)(struct DOSIFace *Self, BPTR file);
	LONG APICALL (*Read)(struct DOSIFace *Self, BPTR file, APTR buffer, LONG length);
	LONG APICALL (*Write)(struct DOSIFace *Self, BPTR file, CONST_APTR buffer, LONG length);
	BPTR APICALL (*Input)(struct DOSIFace *Self);
	BPTR APICALL (*Output)(struct DOSIFace *Self);
	DEPRECATED LONG APICALL (*OBSOLETESeek)(struct DOSIFace *Self, BPTR file, LONG position, LONG offset);
	LONG APICALL (*Delete)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*Rename)(struct DOSIFace *Self, CONST_STRPTR oldName, CONST_STRPTR newName);
	BPTR APICALL (*Lock)(struct DOSIFace *Self, CONST_STRPTR name, LONG type);
	VOID APICALL (*UnLock)(struct DOSIFace *Self, BPTR lock);
	BPTR APICALL (*DupLock)(struct DOSIFace *Self, BPTR lock);
	DEPRECATED LONG APICALL (*OBSOLETEExamine)(struct DOSIFace *Self, BPTR lock, struct FileInfoBlock * fileInfoBlock);
	DEPRECATED LONG APICALL (*OBSOLETEExNext)(struct DOSIFace *Self, BPTR lock, struct FileInfoBlock * fileInfoBlock);
	LONG APICALL (*Info)(struct DOSIFace *Self, BPTR lock, struct InfoData * parameterBlock);
	BPTR APICALL (*CreateDir)(struct DOSIFace *Self, CONST_STRPTR name);
	BPTR APICALL (*SetCurrentDir)(struct DOSIFace *Self, BPTR lock);
	LONG APICALL (*IoErr)(struct DOSIFace *Self);
	DEPRECATED struct MsgPort * APICALL (*OBSOLETECreateProc)(struct DOSIFace *Self, CONST_STRPTR name, LONG pri, BPTR segList, LONG stackSize);
	DEPRECATED VOID APICALL (*OBSOLETEExit)(struct DOSIFace *Self, LONG returnCode);
	DEPRECATED BPTR APICALL (*OBSOLETELoadSeg)(struct DOSIFace *Self, CONST_STRPTR name, BPTR hunktab, BPTR stream);
	LONG APICALL (*UnLoadSeg)(struct DOSIFace *Self, BPTR seglist);
	int32 APICALL (*PRIVATEDoPkt32)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5, LONG arg6, LONG arg7);
	BPTR APICALL (*LoadSeg)(struct DOSIFace *Self, CONST_STRPTR name);
	DEPRECATED struct MsgPort * APICALL (*OBSOLETEDeviceProc)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*SetComment)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR comment);
	LONG APICALL (*SetProtection)(struct DOSIFace *Self, CONST_STRPTR name, ULONG protect);
	struct DateStamp * APICALL (*DateStamp)(struct DOSIFace *Self, struct DateStamp * date);
	VOID APICALL (*Delay)(struct DOSIFace *Self, ULONG timeout);
	LONG APICALL (*WaitForChar)(struct DOSIFace *Self, BPTR file, LONG timeout);
	BPTR APICALL (*ParentDir)(struct DOSIFace *Self, BPTR lock);
	LONG APICALL (*IsInteractive)(struct DOSIFace *Self, BPTR file);
	DEPRECATED LONG APICALL (*OBSOLETEExecute)(struct DOSIFace *Self, CONST_STRPTR string, BPTR file, BPTR file2);
	APTR APICALL (*AllocDosObject)(struct DOSIFace *Self, ULONG type, const struct TagItem * tags);
	APTR APICALL (*AllocDosObjectTagList)(struct DOSIFace *Self, ULONG type, const struct TagItem * tags);
	APTR APICALL (*AllocDosObjectTags)(struct DOSIFace *Self, ULONG type, ...);
	VOID APICALL (*FreeDosObject)(struct DOSIFace *Self, ULONG type, APTR ptr);
	LONG APICALL (*DoPkt)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5);
	LONG APICALL (*DoPkt0)(struct DOSIFace *Self, struct MsgPort * port, LONG action);
	LONG APICALL (*DoPkt1)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1);
	LONG APICALL (*DoPkt2)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2);
	LONG APICALL (*DoPkt3)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3);
	LONG APICALL (*DoPkt4)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4);
	VOID APICALL (*SendPkt)(struct DOSIFace *Self, struct DosPacket * dp, struct MsgPort * port, struct MsgPort * replyport);
	struct DosPacket * APICALL (*WaitPkt)(struct DOSIFace *Self, struct MsgPort * task_replyport);
	LONG APICALL (*ReplyPkt)(struct DOSIFace *Self, struct DosPacket * dp, LONG res1, LONG res2);
	APTR Reserved2_UNIMPLEMENTED;
	DEPRECATED LONG APICALL (*OBSOLETELockRecord)(struct DOSIFace *Self, BPTR fh, ULONG offset, ULONG length, ULONG mode, ULONG timeout);
	LONG APICALL (*LockRecords)(struct DOSIFace *Self, struct RecordLock * recArray, ULONG timeout);
	DEPRECATED LONG APICALL (*OBSOLETEUnLockRecord)(struct DOSIFace *Self, BPTR fh, ULONG offset, ULONG length);
	LONG APICALL (*UnLockRecords)(struct DOSIFace *Self, struct RecordLock * recArray);
	BPTR APICALL (*SelectInput)(struct DOSIFace *Self, BPTR fh);
	BPTR APICALL (*SelectOutput)(struct DOSIFace *Self, BPTR fh);
	LONG APICALL (*FGetC)(struct DOSIFace *Self, BPTR fh);
	LONG APICALL (*FPutC)(struct DOSIFace *Self, BPTR fh, LONG ch);
	LONG APICALL (*FUnGetC)(struct DOSIFace *Self, BPTR fh, LONG character);
	ULONG APICALL (*FRead)(struct DOSIFace *Self, BPTR fh, APTR block, ULONG blocklen, ULONG number);
	ULONG APICALL (*FWrite)(struct DOSIFace *Self, BPTR fh, CONST_APTR block, ULONG blocklen, ULONG number);
	STRPTR APICALL (*FGets)(struct DOSIFace *Self, BPTR fh, STRPTR buf, ULONG buflen);
	LONG APICALL (*FPuts)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR str);
	DEPRECATED VOID APICALL (*OBSOLETEVFWritef)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, LONG * argarray);
	DEPRECATED VOID APICALL (*OBSOLETEFWritef)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, ...);
	LONG APICALL (*VFPrintf)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, CONST_APTR argarray);
	LONG APICALL (*FPrintf)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, ...);
	LONG APICALL (*FFlush)(struct DOSIFace *Self, BPTR fh);
	DEPRECATED LONG APICALL (*OBSOLETESetVBuf)(struct DOSIFace *Self, BPTR fh, STRPTR buff, LONG type, LONG size);
	BPTR APICALL (*DupLockFromFH)(struct DOSIFace *Self, BPTR fh);
	BPTR APICALL (*OpenFromLock)(struct DOSIFace *Self, BPTR lock);
	BPTR APICALL (*ParentOfFH)(struct DOSIFace *Self, BPTR fh);
	DEPRECATED LONG APICALL (*OBSOLETEExamineFH)(struct DOSIFace *Self, BPTR fh, struct FileInfoBlock * fib);
	LONG APICALL (*SetDate)(struct DOSIFace *Self, CONST_STRPTR name, const struct DateStamp * date);
	LONG APICALL (*NameFromLock)(struct DOSIFace *Self, BPTR lock, STRPTR buffer, LONG len);
	LONG APICALL (*NameFromFH)(struct DOSIFace *Self, BPTR fh, STRPTR buffer, LONG len);
	LONG APICALL (*SplitName)(struct DOSIFace *Self, CONST_STRPTR name, LONG separator, STRPTR buf, LONG oldpos, LONG size);
	LONG APICALL (*SameLock)(struct DOSIFace *Self, BPTR lock1, BPTR lock2);
	LONG APICALL (*SetMode)(struct DOSIFace *Self, BPTR fh, LONG mode);
	DEPRECATED LONG APICALL (*OBSOLETEExAll)(struct DOSIFace *Self, BPTR lock, struct ExAllData * buffer, LONG size, LONG data, struct ExAllControl * control);
	LONG APICALL (*ReadSoftLink)(struct DOSIFace *Self, struct MsgPort * port, BPTR lock, CONST_STRPTR path, STRPTR buffer, ULONG size);
	LONG APICALL (*MakeLink)(struct DOSIFace *Self, CONST_STRPTR name, APTR dest, LONG soft);
	LONG APICALL (*ChangeMode)(struct DOSIFace *Self, LONG type, BPTR fh, LONG newmode);
	DEPRECATED LONG APICALL (*OBSOLETESetFileSize)(struct DOSIFace *Self, BPTR fh, LONG pos, LONG mode);
	LONG APICALL (*SetIoErr)(struct DOSIFace *Self, LONG result);
	LONG APICALL (*Fault)(struct DOSIFace *Self, LONG code, CONST_STRPTR header, STRPTR buffer, LONG len);
	LONG APICALL (*PrintFault)(struct DOSIFace *Self, LONG code, CONST_STRPTR header);
	LONG APICALL (*ErrorReport)(struct DOSIFace *Self, LONG code, LONG type, ULONG arg1, struct MsgPort * device);
	LONG APICALL (*PRIVATERequester)(struct DOSIFace *Self, CONST_STRPTR s1, CONST_STRPTR s2, CONST_STRPTR s3, LONG idcmp);
	struct CommandLineInterface * APICALL (*Cli)(struct DOSIFace *Self);
	struct Process * APICALL (*CreateNewProc)(struct DOSIFace *Self, const struct TagItem * tags);
	struct Process * APICALL (*CreateNewProcTagList)(struct DOSIFace *Self, const struct TagItem * tags);
	struct Process * APICALL (*CreateNewProcTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*RunCommand)(struct DOSIFace *Self, BPTR seg, ULONG stack, CONST_STRPTR paramptr, LONG paramlen);
	struct MsgPort * APICALL (*GetConsolePort)(struct DOSIFace *Self);
	struct MsgPort * APICALL (*SetConsolePort)(struct DOSIFace *Self, const struct MsgPort * port);
	struct MsgPort * APICALL (*GetFileSysPort)(struct DOSIFace *Self);
	struct MsgPort * APICALL (*SetFileSysPort)(struct DOSIFace *Self, const struct MsgPort * port);
	STRPTR APICALL (*GetArgStr)(struct DOSIFace *Self);
	STRPTR APICALL (*SetArgStr)(struct DOSIFace *Self, CONST_STRPTR string);
	struct Process * APICALL (*FindCliProc)(struct DOSIFace *Self, ULONG num);
	ULONG APICALL (*MaxCli)(struct DOSIFace *Self);
	LONG APICALL (*SetCliCurrentDirName)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*GetCliCurrentDirName)(struct DOSIFace *Self, STRPTR buf, LONG len);
	LONG APICALL (*SetCliProgramName)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*GetCliProgramName)(struct DOSIFace *Self, STRPTR buf, LONG len);
	LONG APICALL (*SetCliPrompt)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*GetCliPrompt)(struct DOSIFace *Self, STRPTR buf, LONG len);
	BPTR APICALL (*SetProgramDir)(struct DOSIFace *Self, BPTR lock);
	BPTR APICALL (*GetProgramDir)(struct DOSIFace *Self);
	LONG APICALL (*SystemTagList)(struct DOSIFace *Self, CONST_STRPTR command, const struct TagItem * tags);
	LONG APICALL (*System)(struct DOSIFace *Self, CONST_STRPTR command, const struct TagItem * tags);
	LONG APICALL (*SystemTags)(struct DOSIFace *Self, CONST_STRPTR command, ...);
	LONG APICALL (*AssignLock)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock);
	LONG APICALL (*AssignLate)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR path);
	LONG APICALL (*AssignPath)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR path);
	LONG APICALL (*AssignAdd)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock);
	LONG APICALL (*RemAssignList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock);
	struct DevProc * APICALL (*GetDeviceProc)(struct DOSIFace *Self, CONST_STRPTR name, struct DevProc * dp);
	VOID APICALL (*FreeDeviceProc)(struct DOSIFace *Self, struct DevProc * dp);
	struct DosList * APICALL (*LockDosList)(struct DOSIFace *Self, ULONG flags);
	VOID APICALL (*UnLockDosList)(struct DOSIFace *Self, ULONG flags);
	struct DosList * APICALL (*AttemptLockDosList)(struct DOSIFace *Self, ULONG flags);
	LONG APICALL (*RemDosEntry)(struct DOSIFace *Self, struct DosList * dlist);
	LONG APICALL (*AddDosEntry)(struct DOSIFace *Self, struct DosList * dlist);
	struct DosList * APICALL (*FindDosEntry)(struct DOSIFace *Self, const struct DosList * dlist, CONST_STRPTR name, ULONG flags);
	struct DosList * APICALL (*NextDosEntry)(struct DOSIFace *Self, const struct DosList * dlist, ULONG flags);
	struct DosList * APICALL (*MakeDosEntry)(struct DOSIFace *Self, CONST_STRPTR name, LONG type);
	VOID APICALL (*FreeDosEntry)(struct DOSIFace *Self, struct DosList * dlist);
	LONG APICALL (*IsFileSystem)(struct DOSIFace *Self, CONST_STRPTR name);
	int32 APICALL (*Format)(struct DOSIFace *Self, CONST_STRPTR filesystem, CONST_STRPTR volumename, uint32 dostype, uint32 flags);
	LONG APICALL (*Relabel)(struct DOSIFace *Self, CONST_STRPTR drive, CONST_STRPTR newname);
	LONG APICALL (*Inhibit)(struct DOSIFace *Self, CONST_STRPTR name, LONG onoff);
	LONG APICALL (*AddBuffers)(struct DOSIFace *Self, CONST_STRPTR name, LONG number);
	LONG APICALL (*CompareDates)(struct DOSIFace *Self, const struct DateStamp * date1, const struct DateStamp * date2);
	LONG APICALL (*DateToStr)(struct DOSIFace *Self, struct DateTime * datetime);
	LONG APICALL (*StrToDate)(struct DOSIFace *Self, struct DateTime * datetime);
	DEPRECATED BPTR APICALL (*OBSOLETEInternalLoadSeg)(struct DOSIFace *Self, BPTR fh, BPTR table, const LONG * funcarray);
	DEPRECATED LONG APICALL (*OBSOLETEInternalUnLoadSeg)(struct DOSIFace *Self, BPTR seglist, VOID (*freefunc )());
	BPTR APICALL (*OBSOLETENewLoadSeg)(struct DOSIFace *Self, CONST_STRPTR file, const struct TagItem * tags);
	BPTR APICALL (*OBSOLETENewLoadSegTagList)(struct DOSIFace *Self, CONST_STRPTR file, const struct TagItem * tags);
	BPTR APICALL (*OBSOLETENewLoadSegTags)(struct DOSIFace *Self, CONST_STRPTR file, ...);
	LONG APICALL (*AddSegment)(struct DOSIFace *Self, CONST_STRPTR name, BPTR seg, LONG type);
	struct DosResidentSeg * APICALL (*FindSegment)(struct DOSIFace *Self, CONST_STRPTR name, const struct DosResidentSeg * seg, LONG sys);
	LONG APICALL (*RemSegment)(struct DOSIFace *Self, struct DosResidentSeg * seg);
	ULONG APICALL (*CheckSignal)(struct DOSIFace *Self, ULONG mask);
	struct RDArgs * APICALL (*ReadArgs)(struct DOSIFace *Self, CONST_STRPTR arg_template, LONG * array, struct RDArgs * args);
	LONG APICALL (*FindArg)(struct DOSIFace *Self, CONST_STRPTR arg_template, CONST_STRPTR keyword);
	LONG APICALL (*ReadItem)(struct DOSIFace *Self, STRPTR buffer, LONG maxchars, struct CSource * cSource);
	LONG APICALL (*StrToLong)(struct DOSIFace *Self, CONST_STRPTR string, LONG * value);
	LONG APICALL (*MatchFirst)(struct DOSIFace *Self, CONST_STRPTR pat, struct AnchorPath * anchor);
	LONG APICALL (*MatchNext)(struct DOSIFace *Self, struct AnchorPath * anchor);
	VOID APICALL (*MatchEnd)(struct DOSIFace *Self, struct AnchorPath * anchor);
	LONG APICALL (*ParsePattern)(struct DOSIFace *Self, CONST_STRPTR pat, STRPTR buf, LONG buflen);
	LONG APICALL (*MatchPattern)(struct DOSIFace *Self, CONST_STRPTR pat, CONST_STRPTR str);
	APTR Reserved3_UNIMPLEMENTED;
	VOID APICALL (*FreeArgs)(struct DOSIFace *Self, struct RDArgs * args);
	STRPTR APICALL (*StartPart)(struct DOSIFace *Self, CONST_STRPTR path);
	CONST_STRPTR APICALL (*FilePart)(struct DOSIFace *Self, CONST_STRPTR path);
	STRPTR APICALL (*PathPart)(struct DOSIFace *Self, CONST_STRPTR path);
	LONG APICALL (*AddPart)(struct DOSIFace *Self, STRPTR destdirname, CONST_STRPTR filename, ULONG size);
	LONG APICALL (*StartNotify)(struct DOSIFace *Self, struct NotifyRequest * notify);
	LONG APICALL (*EndNotify)(struct DOSIFace *Self, struct NotifyRequest * notify);
	LONG APICALL (*SetVar)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR buffer, LONG size, ULONG flags);
	LONG APICALL (*GetVar)(struct DOSIFace *Self, CONST_STRPTR name, STRPTR buffer, LONG size, ULONG flags);
	LONG APICALL (*DeleteVar)(struct DOSIFace *Self, CONST_STRPTR name, ULONG flags);
	struct LocalVar * APICALL (*FindVar)(struct DOSIFace *Self, CONST_STRPTR name, ULONG type);
	LONG APICALL (*PRIVATECliInit)(struct DOSIFace *Self, struct DosPacket * dp);
	LONG APICALL (*CliInitNewcli)(struct DOSIFace *Self, struct DosPacket * dp);
	LONG APICALL (*CliInitRun)(struct DOSIFace *Self, struct DosPacket * dp);
	LONG APICALL (*WriteChars)(struct DOSIFace *Self, CONST_STRPTR buf, ULONG buflen);
	LONG APICALL (*PutStr)(struct DOSIFace *Self, CONST_STRPTR str);
	LONG APICALL (*VPrintf)(struct DOSIFace *Self, CONST_STRPTR format, CONST_APTR argarray);
	LONG APICALL (*Printf)(struct DOSIFace *Self, CONST_STRPTR format, ...);
	APTR Reserved5_UNIMPLEMENTED;
	LONG APICALL (*ParsePatternNoCase)(struct DOSIFace *Self, CONST_STRPTR pat, STRPTR buf, LONG buflen);
	LONG APICALL (*MatchPatternNoCase)(struct DOSIFace *Self, CONST_STRPTR pat, CONST_STRPTR str);
	STRPTR APICALL (*PRIVATEDosGetString)(struct DOSIFace *Self, LONG num);
	LONG APICALL (*SameDevice)(struct DOSIFace *Self, BPTR lock1, BPTR lock2);
	DEPRECATED VOID APICALL (*OBSOLETEExAllEnd)(struct DOSIFace *Self, BPTR lock, struct ExAllData * buffer, LONG size, LONG data, struct ExAllControl * control);
	DEPRECATED LONG APICALL (*OBSOLETESetOwner)(struct DOSIFace *Self, CONST_STRPTR name, ULONG owner_info);
	LONG APICALL (*GetEntryData)(struct DOSIFace *Self);
	LONG APICALL (*ReadLineItem)(struct DOSIFace *Self, STRPTR buffer, LONG maxchars, const struct TagItem * taglist);
	LONG APICALL (*ReadLineItemTags)(struct DOSIFace *Self, STRPTR buffer, LONG maxchars, ...);
	LONG APICALL (*PRIVATEInternalRunCommand)(struct DOSIFace *Self, BPTR seg, ULONG stksize, CONST_STRPTR args, LONG arglen);
	BPTR APICALL (*GetCurrentDir)(struct DOSIFace *Self);
	LONG APICALL (*NonBlockingModifyDosEntry)(struct DOSIFace *Self, struct DosList * dl, LONG mode, APTR arg1, APTR arg2);
	struct DateStamp * APICALL (*SecondsToDateStamp)(struct DOSIFace *Self, ULONG seconds, struct DateStamp * ds);
	ULONG APICALL (*DateStampToSeconds)(struct DOSIFace *Self, const struct DateStamp * ds);
	LONG APICALL (*FixDateStamp)(struct DOSIFace *Self, struct DateStamp * ds);
	LONG APICALL (*AddDates)(struct DOSIFace *Self, struct DateStamp * to, const struct DateStamp * from);
	LONG APICALL (*SubtractDates)(struct DOSIFace *Self, struct DateStamp * to, const struct DateStamp * from);
	LONG APICALL (*AddSegmentTagList)(struct DOSIFace *Self, CONST_STRPTR name, LONG type, const struct TagItem * tags);
	LONG APICALL (*ParseCapturePattern)(struct DOSIFace *Self, CONST_STRPTR pat, STRPTR dst, LONG length, LONG casesen);
	LONG APICALL (*CapturePattern)(struct DOSIFace *Self, CONST_STRPTR pat, CONST_STRPTR str, LONG casesen, struct CapturedExpression ** cap);
	VOID APICALL (*ReleaseCapturedExpressions)(struct DOSIFace *Self, struct CapturedExpression * first);
	VOID APICALL (*FindTrackedAddress)(struct DOSIFace *Self, CONST_APTR address, struct Hook * hook);
	LONG APICALL (*TrackAddressList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR segment, CONST_APTR extra_info, LONG extra_info_size, const struct AddressAndSize * aas, LONG num_pairs);
	LONG APICALL (*TrackSegmentList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR segment, CONST_APTR extra_info, LONG extra_info_size);
	VOID APICALL (*UnTrackAddress)(struct DOSIFace *Self, APTR address);
	VOID APICALL (*UnTrackSegmentList)(struct DOSIFace *Self, BPTR segment);
	LONG APICALL (*GetExitData)(struct DOSIFace *Self);
	LONG APICALL (*PutErrStr)(struct DOSIFace *Self, CONST_STRPTR str);
	BPTR APICALL (*ErrorOutput)(struct DOSIFace *Self);
	BPTR APICALL (*SelectErrorOutput)(struct DOSIFace *Self, BPTR fh);
	LONG APICALL (*MountDevice)(struct DOSIFace *Self, CONST_STRPTR name, LONG type, const struct TagItem * tags);
	LONG APICALL (*MountDeviceTags)(struct DOSIFace *Self, CONST_STRPTR name, LONG type, ...);
	APTR APICALL (*SetProcWindow)(struct DOSIFace *Self, CONST_APTR win);
	ULONG APICALL (*FindSegmentStackSize)(struct DOSIFace *Self, BPTR segment);
	ULONG APICALL (*CalculateSegmentChecksum)(struct DOSIFace *Self, BPTR segment);
	BPTR APICALL (*AllocSegList)(struct DOSIFace *Self, CONST_APTR entry, CONST_APTR data, ULONG datalen, ULONG identkey);
	LONG APICALL (*GetSegListInfo)(struct DOSIFace *Self, BPTR seglist, const struct TagItem * tags);
	LONG APICALL (*GetSegListInfoTags)(struct DOSIFace *Self, BPTR seglist, ...);
	LONG APICALL (*AddSegListTail)(struct DOSIFace *Self, BPTR bseglist_head, BPTR bseg_new);
	LONG APICALL (*DevNameFromLock)(struct DOSIFace *Self, BPTR lock, STRPTR buffer, LONG buflen, LONG mode);
	struct MsgPort * APICALL (*GetProcMsgPort)(struct DOSIFace *Self, const struct Process * proc);
	LONG APICALL (*WaitForData)(struct DOSIFace *Self, BPTR stream, LONG data_direction, LONG timeout);
	LONG APICALL (*SetBlockingMode)(struct DOSIFace *Self, BPTR stream, LONG new_blocking_mode);
	struct PathNode * APICALL (*SetCurrentCmdPathList)(struct DOSIFace *Self, struct PathNode * pn);
	struct PathNode * APICALL (*AllocateCmdPathList)(struct DOSIFace *Self, BPTR first_lock);
	VOID APICALL (*FreeCmdPathList)(struct DOSIFace *Self, struct PathNode * pn);
	struct PathNode * APICALL (*RemoveCmdPathNode)(struct DOSIFace *Self, struct PathNode * pn, BPTR lock);
	struct PathNode * APICALL (*AddCmdPathNode)(struct DOSIFace *Self, struct PathNode * pn, BPTR lock, LONG where);
	LONG APICALL (*SearchCmdPathList)(struct DOSIFace *Self, const struct PathNode * pn, const struct Hook * h, CONST_STRPTR name, const struct TagItem * tags);
	LONG APICALL (*SearchCmdPathListTags)(struct DOSIFace *Self, const struct PathNode * pn, const struct Hook * h, CONST_STRPTR name, ...);
	LONG APICALL (*ScanVars)(struct DOSIFace *Self, const struct Hook * hook, ULONG flags, CONST_APTR userdata);
	BPTR APICALL (*GetProcSegList)(struct DOSIFace *Self, const struct Process * proc, ULONG flags);
	LONG APICALL (*HexToLong)(struct DOSIFace *Self, CONST_STRPTR string, ULONG * value_ptr);
	struct DevProc * APICALL (*GetDeviceProcFlags)(struct DOSIFace *Self, CONST_STRPTR name, struct DevProc * odp, ULONG flags);
	LONG APICALL (*DosControl)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*DosControlTags)(struct DOSIFace *Self, ...);
	BPTR APICALL (*CreateDirTree)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*NotifyVar)(struct DOSIFace *Self, CONST_STRPTR name, const struct Hook * hook, LONG flags, CONST_APTR userdata);
	struct FileSystemData * APICALL (*GetDiskFileSystemData)(struct DOSIFace *Self, CONST_STRPTR name);
	VOID APICALL (*FreeDiskFileSystemData)(struct DOSIFace *Self, struct FileSystemData * fsd);
	BPTR APICALL (*FOpen)(struct DOSIFace *Self, CONST_STRPTR name, LONG mode, LONG bufsize);
	LONG APICALL (*FClose)(struct DOSIFace *Self, BPTR scb);
	BPTR APICALL (*FOpenFromLock)(struct DOSIFace *Self, BPTR lock, LONG bufsize);
	struct PathNode * APICALL (*DupCmdPathList)(struct DOSIFace *Self, const struct PathNode * source);
	LONG APICALL (*TimedDosRequester)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*TimedDosRequesterTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*RenameDosEntry)(struct DOSIFace *Self, struct DosList * dlist, CONST_STRPTR newname);
	LONG APICALL (*DismountDevice)(struct DOSIFace *Self, CONST_STRPTR name, ULONG flags, APTR reserved);
	BPTR APICALL (*DupFileHandle)(struct DOSIFace *Self, BPTR scb);
	LONG APICALL (*DevNameFromFH)(struct DOSIFace *Self, BPTR scb, STRPTR buffer, LONG buflen, LONG mode);
	LONG APICALL (*AssignAddToList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock, LONG endpos);
	LONG APICALL (*SetFileHandleAttr)(struct DOSIFace *Self, BPTR fh, const struct TagItem * tags);
	LONG APICALL (*SetFileHandleAttrTags)(struct DOSIFace *Self, BPTR fh, ...);
	LONG APICALL (*FileSystemAttr)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*FileSystemAttrTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*FReadLine)(struct DOSIFace *Self, BPTR fh, struct FReadLineData * frld);
	ULONG APICALL (*CopyStringBSTRToC)(struct DOSIFace *Self, BSTR bsrc, STRPTR dst, ULONG siz);
	ULONG APICALL (*CopyStringCToBSTR)(struct DOSIFace *Self, CONST_STRPTR src, BSTR bdest, ULONG siz);
	int64 APICALL (*GetFilePosition)(struct DOSIFace *Self, BPTR fh);
	int32 APICALL (*ChangeFilePosition)(struct DOSIFace *Self, BPTR file, int64 position, int32 offset);
	int32 APICALL (*ChangeFileSize)(struct DOSIFace *Self, BPTR fh, int64 pos, int32 mode);
	int64 APICALL (*GetFileSize)(struct DOSIFace *Self, BPTR fh);
	int64 APICALL (*DoPkt64)(struct DOSIFace *Self, struct MsgPort * sendport, int32 type, int32 arg1, int64 arg2, int32 arg3, int32 arg4, int64 arg5);
	int64 APICALL (*PRIVATEDoPkt64)(struct DOSIFace *Self, struct MsgPort * sendport, int32 type, int32 arg1, int64 arg2, int32 arg3, int32 arg4, int64 arg5);
	APTR Reserved8_UNIMPLEMENTED;
	APTR Reserved9_UNIMPLEMENTED;
	APTR Reserved10_UNIMPLEMENTED;
	LONG APICALL (*ProcessScan)(struct DOSIFace *Self, const struct Hook * hook, CONST_APTR userdata, ULONG reserved);
	LONG APICALL (*NotifyDosListChange)(struct DOSIFace *Self, struct Process * process, ULONG signalnum, ULONG reserved);
	LONG APICALL (*NotifyProcListChange)(struct DOSIFace *Self, struct Process * process, ULONG signalnum, ULONG reserved);
	LONG APICALL (*GetDiskInfo)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*GetDiskInfoTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*WriteProtectVolume)(struct DOSIFace *Self, CONST_STRPTR name, LONG on_off, ULONG passkey, LONG reserved);
	struct ExamineData * APICALL (*ExamineObject)(struct DOSIFace *Self, const struct TagItem * ctags);
	struct ExamineData * APICALL (*ExamineObjectTags)(struct DOSIFace *Self, ...);
	struct ExamineData * APICALL (*ExamineDir)(struct DOSIFace *Self, APTR context);
	APTR APICALL (*ObtainDirContext)(struct DOSIFace *Self, const struct TagItem * ctags);
	APTR APICALL (*ObtainDirContextTags)(struct DOSIFace *Self, ...);
	VOID APICALL (*ReleaseDirContext)(struct DOSIFace *Self, APTR contx);
	LONG APICALL (*GetOwnerInfo)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*GetOwnerInfoTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*SetOwnerInfo)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*SetOwnerInfoTags)(struct DOSIFace *Self, ...);
	BPTR APICALL (*LockTagList)(struct DOSIFace *Self, const struct TagItem * tags);
	BPTR APICALL (*LockTags)(struct DOSIFace *Self, ...);
	ULONG APICALL (*GetPID)(struct DOSIFace *Self, const struct Process * process, LONG which);
	LONG APICALL (*FlushVolume)(struct DOSIFace *Self, CONST_STRPTR name);
	struct ConsoleWindowData * APICALL (*ObtainConsoleData)(struct DOSIFace *Self, const struct TagItem * ctags);
	struct ConsoleWindowData * APICALL (*ObtainConsoleDataTags)(struct DOSIFace *Self, ...);
	VOID APICALL (*ReleaseConsoleData)(struct DOSIFace *Self, struct ConsoleWindowData * data);
	LONG APICALL (*Serialize)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*NameFromPort)(struct DOSIFace *Self, struct MsgPort * port, STRPTR buffer, LONG buflen, LONG add_colon);
	LONG APICALL (*DevNameFromPort)(struct DOSIFace *Self, struct MsgPort * port, STRPTR buffer, LONG buflen, LONG add_colon);
	LONG APICALL (*SameFH)(struct DOSIFace *Self, BPTR scb1, BPTR scb2);
	int32 APICALL (*LockRecord)(struct DOSIFace *Self, BPTR fh, int64 offset, int64 length, uint32 mode, uint32 timeout);
	int32 APICALL (*UnLockRecord)(struct DOSIFace *Self, BPTR fh, int64 offset, int64 length);
	int32 APICALL (*IsFileSystemPort)(struct DOSIFace *Self, struct MsgPort * port);
	int32 APICALL (*InhibitPort)(struct DOSIFace *Self, struct MsgPort * port, int32 state);
	int32 APICALL (*FormatPort)(struct DOSIFace *Self, struct MsgPort * port, CONST_STRPTR volumename, uint32 dostype, uint32 flags);
	int32 APICALL (*SerializePort)(struct DOSIFace *Self, struct MsgPort * port);
	int32 APICALL (*FlushVolumePort)(struct DOSIFace *Self, struct MsgPort * port);
	LONG APICALL (*FileHandleScan)(struct DOSIFace *Self, const struct Hook * hook, CONST_APTR userdata, ULONG reserved);
	struct FileSystemVectorPort * APICALL (*GetFileSystemVectorPort)(struct DOSIFace *Self, struct MsgPort * port, uint32 min_version);
	int32 APICALL (*ResolvePath)(struct DOSIFace *Self, struct MsgPort * port, CONST_STRPTR path, BPTR inlock, STRPTR out, uint32 outlen, BPTR * outdir, uint32 * slcount);
	int32 APICALL (*WriteProtectVolumePort)(struct DOSIFace *Self, struct MsgPort * port, int32 on_off, uint32 passkey, int32 reserved);
	int32 APICALL (*AsyncIO)(struct DOSIFace *Self, const struct TagItem * tags);
	int32 APICALL (*AsyncIOTags)(struct DOSIFace *Self, ...);
	int32 APICALL (*WaitForChildExit)(struct DOSIFace *Self, uint32 pid);
	int32 APICALL (*CheckForChildExit)(struct DOSIFace *Self, uint32 pid);
	APTR Reserved15_UNIMPLEMENTED;
	APTR Reserved16_UNIMPLEMENTED;
	APTR Reserved17_UNIMPLEMENTED;
	APTR Reserved18_UNIMPLEMENTED;
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* DOS_INTERFACE_DEF_H */