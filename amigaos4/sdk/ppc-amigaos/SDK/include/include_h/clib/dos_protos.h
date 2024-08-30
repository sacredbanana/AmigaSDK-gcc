
#ifdef __amigaos4__
  #error Include <proto/> header files, not <clib/> header files in OS4.
#endif 


#ifndef  CLIB_DOS_PROTOS_H
#define  CLIB_DOS_PROTOS_H

/*
**	$Id: dos_protos.h 40.99 2010-04-26 07:26:16 cwenzel Exp $
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef  DOS_RECORD_H
#include <dos/record.h>
#endif
#ifndef  DOS_RDARGS_H
#include <dos/rdargs.h>
#endif
#ifndef  DOS_DOSASL_H
#include <dos/dosasl.h>
#endif
#ifndef  DOS_VAR_H
#include <dos/var.h>
#endif
#ifndef  DOS_NOTIFY_H
#include <dos/notify.h>
#endif
#ifndef  DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef  DOS_EXALL_H
#include <dos/exall.h>
#endif
#ifndef  DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif
#ifndef  DOS_DOSTAGS_H
#include <dos/dostags.h>
#endif
#ifndef  DOS_MOUNT_H
#include <dos/mount.h>
#endif
#ifndef  DOS_DOSHUNKS_H
#include <dos/doshunks.h>
#endif
#ifndef  DOS_PATH_H
#include <dos/path.h>
#endif
#ifndef  DOS_ANCHORPATH_H
#include <dos/anchorpath.h>
#endif
#ifndef  DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef  DOS_ERRORS_H
#include <dos/errors.h>
#endif
BPTR Open( CONST_STRPTR name, LONG accessMode );
LONG Close( BPTR file );
LONG Read( BPTR file, APTR buffer, LONG length );
LONG Write( BPTR file, CONST APTR buffer, LONG length );
BPTR Input( VOID );
BPTR Output( VOID );
LONG OBSOLETESeek( BPTR file, LONG position, LONG offset );
LONG Delete( CONST_STRPTR name );
LONG Rename( CONST_STRPTR oldName, CONST_STRPTR newName );
BPTR Lock( CONST_STRPTR name, LONG type );
VOID UnLock( BPTR lock );
BPTR DupLock( BPTR lock );
LONG OBSOLETEExamine( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG OBSOLETEExNext( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG Info( BPTR lock, struct InfoData *parameterBlock );
BPTR CreateDir( CONST_STRPTR name );
BPTR SetCurrentDir( BPTR lock );
LONG IoErr( VOID );
struct MsgPort *OBSOLETECreateProc( CONST_STRPTR name, LONG pri, BPTR segList, LONG stackSize );
BPTR LoadSegOVL( CONST_STRPTR name, BPTR hunktab, BPTR scb );
VOID UnLoadSeg( BPTR seglist );
BPTR LoadSeg( CONST_STRPTR name );
struct MsgPort *OBSOLETEDeviceProc( CONST_STRPTR name );
LONG SetComment( CONST_STRPTR name, CONST_STRPTR comment );
LONG SetProtection( CONST_STRPTR name, ULONG protect );
struct DateStamp *DateStamp( struct DateStamp *date );
VOID Delay( ULONG timeout );
LONG WaitForChar( BPTR file, LONG timeout );
BPTR ParentDir( BPTR lock );
LONG IsInteractive( BPTR file );
LONG OBSOLETEExecute( CONST_STRPTR string, BPTR file, BPTR file2 );
/*--- functions in V36 or higher (Release 2.0) ---*/
/*	DOS Object creation/deletion */
APTR AllocDosObject( ULONG type, CONST struct TagItem *tags );
APTR AllocDosObjectTagList( ULONG type, CONST struct TagItem *tags );
APTR AllocDosObjectTags( ULONG type, ULONG tag1, ... );
VOID FreeDosObject( ULONG type, APTR ptr );
/*	Packet Level routines */
LONG DoPkt( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5 );
LONG DoPkt0( struct MsgPort *port, LONG action );
LONG DoPkt1( struct MsgPort *port, LONG action, LONG arg1 );
LONG DoPkt2( struct MsgPort *port, LONG action, LONG arg1, LONG arg2 );
LONG DoPkt3( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3 );
LONG DoPkt4( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4 );
VOID SendPkt( struct DosPacket *dp, struct MsgPort *port, struct MsgPort *replyport );

/*     Parameter added at V47, (for v50 release) backward compatible for processes. */
struct DosPacket *WaitPkt( struct MsgPort *task_replyport );


LONG ReplyPkt( struct DosPacket *dp, LONG res1, LONG res2 );
/*	Record Locking */
LONG LockRecord( BPTR fh, ULONG offset, ULONG length, ULONG mode, ULONG timeout );
LONG LockRecords( struct RecordLock *recArray, ULONG timeout );
LONG UnLockRecord( BPTR fh, ULONG offset, ULONG length );
LONG UnLockRecords( struct RecordLock *recArray );
/*	Buffered File I/O */
BPTR SelectInput( BPTR fh );
BPTR SelectOutput( BPTR fh );
LONG FGetC( BPTR fh );
LONG FPutC( BPTR fh, LONG ch );
LONG FUnGetC( BPTR fh, LONG character );
ULONG FRead( BPTR fh, APTR block, ULONG blocklen, ULONG number );
ULONG FWrite( BPTR fh, CONST APTR block, ULONG blocklen, ULONG number );
STRPTR FGets( BPTR fh, STRPTR buf, ULONG buflen );
LONG FPuts( BPTR fh, CONST_STRPTR str );
LONG VFPrintf( BPTR fh, CONST_STRPTR format, CONST APTR argarray );
LONG FPrintf( BPTR fh, CONST_STRPTR format, ULONG arg1, ... );
LONG FFlush( BPTR fh );
LONG OBSOLETESetVBuf( BPTR fh, STRPTR buff, LONG type, LONG size );
/*	DOS Object Management */
BPTR DupLockFromFH( BPTR fh );
BPTR OpenFromLock( BPTR lock );
BPTR ParentOfFH( BPTR fh );
LONG OBSOLETEExamineFH( BPTR fh, struct FileInfoBlock *fib );
LONG SetDate( CONST_STRPTR name, CONST struct DateStamp *date );
LONG NameFromLock( BPTR lock, STRPTR buffer, LONG len );
LONG NameFromFH( BPTR fh, STRPTR buffer, LONG len );
WORD SplitName( CONST_STRPTR name, ULONG seperator, STRPTR buf, LONG oldpos, LONG size );
LONG SameLock( BPTR lock1, BPTR lock2 );
LONG SetMode( BPTR fh, LONG mode );
LONG OBSOLETEExAll( BPTR lock, struct ExAllData *buffer, LONG size, LONG data, struct ExAllControl *control );
LONG ReadSoftLink( struct MsgPort *port, BPTR lock, CONST_STRPTR path, STRPTR buffer, ULONG size );
LONG MakeLink( CONST_STRPTR name, APTR dest, LONG soft );
LONG ChangeMode( LONG type, BPTR fh, LONG newmode );
LONG OBSOLETESetFileSize( BPTR fh, LONG pos, LONG mode );
/*	Error Handling */
LONG SetIoErr( LONG result );
LONG Fault( LONG code, CONST_STRPTR header, STRPTR buffer, LONG len );
LONG PrintFault( LONG code, CONST_STRPTR header );
LONG ErrorReport( LONG code, LONG type, ULONG arg1, struct MsgPort *device );
/*	Process Management */
struct CommandLineInterface *Cli( VOID );
struct Process *CreateNewProc( CONST struct TagItem *tags );
struct Process *CreateNewProcTagList( CONST struct TagItem *tags );
struct Process *CreateNewProcTags( ULONG tag1, ... );
LONG RunCommand( BPTR seg, ULONG stack, CONST_STRPTR paramptr, LONG paramlen );
struct MsgPort *GetConsolePort( VOID );
struct MsgPort *SetConsolePort( CONST struct MsgPort *port );
struct MsgPort *GetFileSysPort( VOID );
struct MsgPort *SetFileSysPort( CONST struct MsgPort *port );
STRPTR GetArgStr( VOID );
STRPTR SetArgStr( CONST_STRPTR string );
struct Process *FindCliProc( ULONG num );
ULONG MaxCli( VOID );
LONG SetCliCurrentDirName( CONST_STRPTR name );
LONG GetCliCurrentDirName( STRPTR buf, LONG len );
LONG SetCliProgramName( CONST_STRPTR name );
LONG GetCliProgramName( STRPTR buf, LONG len );
LONG SetCliPrompt( CONST_STRPTR name );
LONG GetCliPrompt( STRPTR buf, LONG len );
BPTR SetProgramDir( BPTR lock );
BPTR GetProgramDir( VOID );
/*	Device List Management */
LONG SystemTagList( CONST_STRPTR command, CONST struct TagItem *tags );
LONG System( CONST_STRPTR command, CONST struct TagItem *tags );
LONG SystemTags( CONST_STRPTR command, ULONG tag1, ... );
LONG AssignLock( CONST_STRPTR name, BPTR lock );
LONG AssignLate( CONST_STRPTR name, CONST_STRPTR path );
LONG AssignPath( CONST_STRPTR name, CONST_STRPTR path );
LONG AssignAdd( CONST_STRPTR name, BPTR lock );
LONG RemAssignList( CONST_STRPTR name, BPTR lock );
struct DevProc *GetDeviceProc( CONST_STRPTR name, struct DevProc *dp );
VOID FreeDeviceProc( struct DevProc *dp );
struct DosList *LockDosList( ULONG flags );
VOID UnLockDosList( ULONG flags );
struct DosList *AttemptLockDosList( ULONG flags );
LONG RemDosEntry( struct DosList *dlist );
LONG AddDosEntry( struct DosList *dlist );
struct DosList *FindDosEntry( CONST struct DosList *dlist, CONST_STRPTR name, ULONG flags );
struct DosList *NextDosEntry( CONST struct DosList *dlist, ULONG flags );
struct DosList *MakeDosEntry( CONST_STRPTR name, LONG type );
VOID FreeDosEntry( struct DosList *dlist );
LONG IsFileSystem( CONST_STRPTR name );
/*	Handler Interface */
LONG Format( CONST_STRPTR filesystem, CONST_STRPTR volumename, ULONG dostype, ULONG flags );
LONG Relabel( CONST_STRPTR drive, CONST_STRPTR newname );
LONG Inhibit( CONST_STRPTR name, LONG onoff );
LONG AddBuffers( CONST_STRPTR name, LONG number );
/*	Date, Time Routines */
LONG CompareDates( CONST struct DateStamp *date1, CONST struct DateStamp *date2 );
LONG DateToStr( struct DateTime *datetime );
LONG StrToDate( struct DateTime *datetime );
/*	Image Management */
BPTR InternalLoadSeg( BPTR fh, BPTR table, CONST LONG *funcarray );
LONG InternalUnLoadSeg( BPTR seglist, VOID (*freefunc)() );
BPTR NewLoadSeg( CONST_STRPTR file, CONST struct TagItem *tags );
BPTR NewLoadSegTagList( CONST_STRPTR file, CONST struct TagItem *tags );
BPTR NewLoadSegTags( CONST_STRPTR file, ULONG tag1, ... );
LONG AddSegment( CONST_STRPTR name, BPTR seg, LONG type );
struct DosResidentSeg *FindSegment( CONST_STRPTR name, CONST struct DosResidentSeg *seg, LONG type );
LONG RemSegment( struct DosResidentSeg *seg );
/*	Command Support */
ULONG CheckSignal( ULONG mask );
struct RDArgs *ReadArgs( CONST_STRPTR arg_template, LONG *array, struct RDArgs *args );
LONG FindArg( CONST_STRPTR arg_template, CONST_STRPTR keyword );
LONG ReadItem( STRPTR buffer, LONG maxchars, struct CSource *cSource );
LONG StrToLong( CONST_STRPTR string, LONG *value );
LONG MatchFirst( CONST_STRPTR pat, struct AnchorPath *anchor );
LONG MatchNext( struct AnchorPath *anchor );
VOID MatchEnd( struct AnchorPath *anchor );
LONG ParsePattern( CONST_STRPTR pat, STRPTR buf, LONG buflen );
LONG MatchPattern( CONST_STRPTR pat, CONST_STRPTR str );
VOID FreeArgs( struct RDArgs *args );
STRPTR StartPart( CONST_STRPTR path );
CONST_STRPTR FilePart( CONST_STRPTR path );
STRPTR PathPart( CONST_STRPTR path );
LONG AddPart( STRPTR dest_dirname, CONST_STRPTR filename, ULONG size );
/*	Notification */
LONG StartNotify( struct NotifyRequest *notify );
LONG EndNotify( struct NotifyRequest *notify );
/*	Environment Variable functions */
LONG SetVar( CONST_STRPTR name, CONST_STRPTR buffer, LONG size, ULONG flags );
LONG GetVar( CONST_STRPTR name, STRPTR buffer, LONG size, ULONG flags );
LONG DeleteVar( CONST_STRPTR name, ULONG flags );
struct LocalVar *FindVar( CONST_STRPTR name, ULONG type );
LONG CliInitNewcli( struct DosPacket *dp );
LONG CliInitRun( struct DosPacket *dp );
LONG WriteChars( CONST_STRPTR buf, ULONG buflen );
LONG PutStr( CONST_STRPTR str );
LONG VPrintf( CONST_STRPTR format, CONST APTR argarray );
LONG Printf( CONST_STRPTR format, ULONG arg1, ... );
/* these were unimplemented until dos 36.147 */
LONG ParsePatternNoCase( CONST_STRPTR pat, STRPTR buf, LONG buflen );
LONG MatchPatternNoCase( CONST_STRPTR pat, CONST_STRPTR str );
/* this was added for V37 dos, returned 0 before then. */
LONG SameDevice( BPTR lock1, BPTR lock2 );
/* These calls were added for V39 dos: */
VOID OBSOLETEExAllEnd( BPTR lock, struct ExAllData *buffer, LONG size, LONG data, struct ExAllControl *control );
LONG OBSOLETESetOwner( CONST_STRPTR name, ULONG owner_info );

LONG GetEntryData( VOID );
LONG ReadLineItem( STRPTR buffer, LONG maxchars, CONST struct TagItem *tags );
LONG ReadLineItemTags( STRPTR buffer, LONG maxchars, ULONG tag1, ... );
BPTR GetCurrentDir( VOID );
LONG NonBlockingModifyDosEntry( struct DosList *dl, LONG mode, APTR arg1, APTR arg2 );
struct DateStamp *SecondsToDateStamp( ULONG seconds, struct DateStamp *ds );
ULONG DateStampToSeconds( CONST struct DateStamp *ds );
LONG FixDateStamp( struct DateStamp *ds );
LONG AddDates( struct DateStamp *to, CONST struct DateStamp *from );
LONG SubtractDates( struct DateStamp *to, CONST struct DateStamp *from );
LONG AddSegmentTagList( CONST_STRPTR name, LONG type, CONST struct TagItem *tags );
LONG ParseCapturePattern( CONST_STRPTR pat, STRPTR dst, LONG length, LONG casesen );
LONG CapturePattern( CONST_STRPTR pat, CONST_STRPTR str, LONG casesen, struct CapturedExpression **cap );
VOID ReleaseCapturedExpressions( struct CapturedExpression *first );
VOID FindTrackedAddress( CONST APTR address, struct Hook *hook );
LONG TrackAddressList( CONST_STRPTR name, BPTR segment, CONST APTR extra_info, LONG extra_info_size, CONST struct AddressAndSize *aas, LONG num_pairs );
LONG TrackSegmentList( CONST_STRPTR name, BPTR segment, CONST APTR extra_info, LONG extra_info_size );
VOID UnTrackAddress( APTR address );
VOID UnTrackSegmentList( BPTR segment );
LONG GetExitData( VOID );
LONG PutErrStr( CONST_STRPTR str );
BPTR ErrorOutput( VOID );
BPTR SelectErrorOutput( BPTR fh );
LONG MountDevice( CONST_STRPTR name, LONG type, CONST struct TagItem *tags );
LONG MountDeviceTags( CONST_STRPTR name, LONG type, ULONG tag1, ... );
APTR SetProcWindow( CONST APTR win );
ULONG FindSegmentStackSize( BPTR segment );
ULONG CalculateSegmentChecksum( BPTR segment );
BPTR AllocSegList( CONST APTR entry, CONST APTR data, ULONG datalen, ULONG identkey );
LONG GetSegListInfo( BPTR seglist, CONST struct TagItem *tags );
LONG GetSegListInfoTags( BPTR seglist, ULONG tag1, ... );
LONG AddSegListTail( BPTR bseglist_head, BPTR bseg_new );
LONG DevNameFromLock( BPTR lock, STRPTR buffer, LONG buflen, LONG mode );
struct MsgPort *GetProcMsgPort( CONST struct Process *proc );
LONG WaitForData( BPTR stream, LONG data_direction, LONG timeout );
LONG SetBlockingMode( BPTR stream, LONG new_blocking_mode );
/*  Shell Path handling Functions v50.51 */
struct PathNode *SetCurrentCmdPathList( struct PathNode *pn );
struct PathNode *AllocateCmdPathList( BPTR first_lock );
VOID FreeCmdPathList( struct PathNode *pn );
struct PathNode *RemoveCmdPathNode( struct PathNode *pn, BPTR lock );
struct PathNode *AddCmdPathNode( struct PathNode *pn, BPTR lock, LONG where );
LONG SearchCmdPathList( CONST struct PathNode *pn, CONST struct Hook *h, CONST_STRPTR name, CONST struct TagItem *tags );
LONG SearchCmdPathListTags( CONST struct PathNode *pn, CONST struct Hook *h, CONST_STRPTR name, ULONG tag1, ... );
LONG ScanVars( CONST struct Hook *hook, ULONG flags, CONST APTR userdata );
BPTR GetProcSegList( CONST struct Process *proc, ULONG flags );

/* --- added 50.66 --- */
LONG HexToLong( CONST_STRPTR string, ULONG *value_ptr );
struct DevProc *GetDeviceProcFlags( CONST_STRPTR name, struct DevProc *odp, ULONG flags );
LONG DosControl( CONST struct TagItem *tags );
LONG DosControlTags( ULONG tag1, ... );
BPTR CreateDirTree( CONST_STRPTR tree );
LONG NotifyVar( CONST_STRPTR name, CONST struct Hook *hook, LONG flags, CONST APTR userdata );

/* --- added 50.80 --- */
struct FileSystemData *GetDiskFileSystemData( CONST_STRPTR name );
VOID FreeDiskFileSystemData( struct FileSystemData *fsd );

/* --- added 51.03 --- */
BPTR FOpen( CONST_STRPTR name, LONG mode, LONG bufsize );
LONG FClose( BPTR scb );
BPTR FOpenFromLock( BPTR lock, LONG bufsize );

/* --- added 54.81 --- */
struct PathNode *DupCmdPathList( CONST struct PathNode *source );

/* --- added 51.12 --- */
LONG TimedDosRequester( CONST struct TagItem *tags );
LONG TimedDosRequesterTags( ULONG tag1, ... );
/*  */
/* --- added 51.13 --- */
LONG RenameDosEntry( struct DosList *dlist, CONST_STRPTR newname );

/* --- added 51.29 --- */
LONG DismountDevice( CONST_STRPTR name, ULONG flags, APTR reserved );

/* --- added 51.32 --- */
BPTR DupFileHandle( BPTR scb );
LONG DevNameFromFH( BPTR scb, STRPTR buffer, LONG buflen, LONG mode );

/* --- added 51.43 --- */
LONG AssignAddToList( CONST_STRPTR name, BPTR lock, LONG endpos );

/* --- added 51.45 --- */
LONG SetFileHandleAttr( BPTR fh, CONST struct TagItem *tags );
LONG SetFileHandleAttrTags( BPTR fh, ULONG tag1, ... );

/* -- added 51.46 --- */
LONG FileSystemAttr( CONST struct TagItem *tags );
LONG FileSystemAttrTags( ULONG tag1, ... );

/* -- added 51.47 --- */
LONG FReadLine( BPTR fh, struct FReadLineData *frld );

/* -- added 51.61 --- */
ULONG CopyStringBSTRToC( BSTR bsrc, STRPTR dst, ULONG siz );
ULONG CopyStringCToBSTR( CONST_STRPTR src, BSTR bdest, ULONG siz );


/* --- added 51.75 --- */

LONG ProcessScan( CONST struct Hook *hook, CONST APTR userdata, ULONG reserved );
LONG NotifyDosListChange( struct Process *process, ULONG signalnum, ULONG reserved );

/* --- added 51.80 --- */
LONG NotifyProcListChange( struct Process *process, ULONG signalnum, ULONG reserved );

/* -- added 51.96 --- */
LONG GetDiskInfo( CONST struct TagItem *tags );
LONG GetDiskInfoTags( ULONG tag1, ... );

/* -- added 51.100 --- */
LONG WriteProtectVolume( CONST_STRPTR name, LONG on_off, ULONG passkey, LONG reserved );

/* -- added 51.104 --- */
struct ExamineData *ExamineObject( CONST struct TagItem *ctags );
struct ExamineData *ExamineObjectTags( ULONG tag1, ... );

struct ExamineData *ExamineDir( APTR context );

APTR ObtainDirContext( CONST struct TagItem *ctags );
APTR ObtainDirContextTags( ULONG tag1, ... );

VOID ReleaseDirContext( APTR contx );

LONG GetOwnerInfo( CONST struct TagItem *tags );
LONG GetOwnerInfoTags( ULONG tag1, ... );

LONG SetOwnerInfo( CONST struct TagItem *tags );
LONG SetOwnerInfoTags( ULONG tag1, ... );

BPTR LockTagList( CONST struct TagItem *tags );
BPTR LockTags( ULONG tag1, ... );

LONG GetPID( struct Process *proc, LONG which );

LONG FlushVolume( CONST_STRPTR name );

struct ConsoleWindowData *ObtainConsoleData( CONST struct TagItem *tags );
struct ConsoleWindowData *ObtainConsoleDataTags( ULONG tag1, ... );

VOID ReleaseConsoleData( struct ConsoleWindowData *data );

LONG Serialize( CONST_STRPTR name );

LONG NameFromPort( struct MsgPort *p, STRPTR buffer, LONG buflen, LONG add_colon );

LONG DevNameFromPort( struct MsgPort *p, STRPTR buffer, LONG buflen, LONG add_colon );

LONG SameFH( BPTR scb1, BPTR scb2 );

LONG IsFileSystemPort( struct MsgPort *port );

LONG InhibitPort( struct MsgPort *port, int32 state );

LONG FormatPort( struct MsgPort *port, STRPTR volname, ULONG dostype, ULONG flags );

LONG SerializePort( struct MsgPort *port );

LONG FlushVolumePort( struct MsgPort *port );

/* --- added 53.129 --- */

LONG FileHandleScan( CONST struct Hook *hook, CONST APTR userdata, ULONG reserved );

/* --- added 53.136 --- */

struct FileSystemVectorPort *GetFileSystemVectorPort( struct MsgPort *port, uint32 min_version );

int32 ResolvePath( struct MsgPort *port, CONST_STRPTR path, BPTR inlock, STRPTR outbuf, uint32 outbufsize, BPTR *outdir, uint32 *sl );

/* --- added 53.149 --- */
int32 WriteProtectVolumePort( struct MsgPort *port, int32 on_off, uint32 passkey, int32 reserved );

/* ---  added 54.76 --- */
int32 AsyncIO( CONST struct TagItem *tags );
int32 AsyncIOTags( uint32 tag1, ... );

/* --- Added 54.94 --- */
int32 WaitForChildExit( uint32 pid );

/* --- Added 54.107 --- */
int32 CheckForChildExit( uint32 pid );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_DOS_PROTOS_H */
