#ifndef CLIB_DOS_PROTOS_H
#define CLIB_DOS_PROTOS_H

/*
	dos.library C prototypes (V50)

	Copyright © 2002-2020 The MorphOS Development Team, All Rights Reserved.
*/

#if defined(__ixemul__) && !defined(__IXEMUL_EXEC_MIXING_ALLOWED)
# error "Mixing ixemul and native library calls is not supported. Native application should be built with -noixemul"
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef DOS_DOSEXTENS_H
# include <dos/dosextens.h>
#endif

#ifndef DOS_RECORD_H
# include <dos/record.h>
#endif

#ifndef DOS_RDARGS_H
# include <dos/rdargs.h>
#endif

#ifndef DOS_DOSASL_H
# include <dos/dosasl.h>
#endif

#ifndef DOS_VAR_H
# include <dos/var.h>
#endif

#ifndef DOS_NOTIFY_H
# include <dos/notify.h>
#endif

#ifndef DOS_DATETIME_H
# include <dos/datetime.h>
#endif

#ifndef DOS_EXALL_H
# include <dos/exall.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

BPTR Open( CONST_STRPTR name, LONG accessMode );
LONG Close( BPTR file );
LONG Read( BPTR file, APTR buffer, LONG length );
LONG Write( BPTR file, CONST APTR buffer, LONG length );
BPTR Input( VOID );
BPTR Output( VOID );
LONG Seek( BPTR file, LONG position, LONG offset );
LONG DeleteFile( CONST_STRPTR name );
LONG Rename( CONST_STRPTR oldName, CONST_STRPTR newName );
BPTR Lock( CONST_STRPTR name, LONG type );
VOID UnLock( BPTR lock );
BPTR DupLock( BPTR lock );
LONG Examine( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG ExNext( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG Info( BPTR lock, struct InfoData *parameterBlock );
BPTR CreateDir( CONST_STRPTR name );
BPTR CurrentDir( BPTR lock );
LONG IoErr( VOID );
struct MsgPort *CreateProc( CONST_STRPTR name, LONG pri, BPTR segList, LONG stackSize );
VOID Exit( LONG returnCode );
BPTR LoadSeg( CONST_STRPTR name );
VOID UnLoadSeg( BPTR seglist );
struct MsgPort *DeviceProc( CONST_STRPTR name );
LONG SetComment( CONST_STRPTR name, CONST_STRPTR comment );
LONG SetProtection( CONST_STRPTR name, LONG protect );
struct DateStamp *DateStamp( struct DateStamp *date );
VOID Delay( LONG timeout );
LONG WaitForChar( BPTR file, LONG timeout );
BPTR ParentDir( BPTR lock );
LONG IsInteractive( BPTR file );
LONG Execute( CONST_STRPTR string, BPTR file, BPTR file2 );

APTR AllocDosObject( ULONG type, CONST struct TagItem *tags );
APTR AllocDosObjectTagList( ULONG type, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
APTR AllocDosObjectTags( ULONG type, ULONG tag1type, ... );
#endif
VOID FreeDosObject( ULONG type, APTR ptr );

LONG DoPkt( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5 );
LONG DoPkt0( struct MsgPort *port, LONG action );
LONG DoPkt1( struct MsgPort *port, LONG action, LONG arg1 );
LONG DoPkt2( struct MsgPort *port, LONG action, LONG arg1, LONG arg2 );
LONG DoPkt3( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3 );
LONG DoPkt4( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4 );
VOID SendPkt( struct DosPacket *dp, struct MsgPort *port, struct MsgPort *replyport );
struct DosPacket *WaitPkt( VOID );
VOID ReplyPkt( struct DosPacket *dp, LONG res1, LONG res2 );
VOID AbortPkt( struct MsgPort *port, struct DosPacket *pkt );

BOOL LockRecord( BPTR fh, ULONG offset, ULONG length, ULONG mode, ULONG timeout );
BOOL LockRecords( struct RecordLock *recArray, ULONG timeout );
BOOL UnLockRecord( BPTR fh, ULONG offset, ULONG length );
BOOL UnLockRecords( struct RecordLock *recArray );

BPTR SelectInput( BPTR fh );
BPTR SelectOutput( BPTR fh );
LONG FGetC( BPTR fh );
LONG FPutC( BPTR fh, LONG ch );
LONG UnGetC( BPTR fh, LONG character );
LONG FRead( BPTR fh, APTR block, ULONG blocklen, ULONG number );
LONG FWrite( BPTR fh, CONST APTR block, ULONG blocklen, ULONG number );
STRPTR FGets( BPTR fh, STRPTR buf, ULONG buflen );
LONG FPuts( BPTR fh, CONST_STRPTR str );
VOID VFWritef( BPTR fh, CONST_STRPTR format, CONST LONG *argarray );
#if !defined(USE_INLINE_STDARG)
VOID FWritef( BPTR fh, CONST_STRPTR format, ... );
#endif
LONG VFPrintf( BPTR fh, CONST_STRPTR format, CONST APTR argarray );
#if !defined(USE_INLINE_STDARG)
LONG FPrintf( BPTR fh, CONST_STRPTR format, ... );
#endif
LONG Flush( BPTR fh );
LONG SetVBuf( BPTR fh, STRPTR buff, LONG type, LONG size );

BPTR DupLockFromFH( BPTR fh );
BPTR OpenFromLock( BPTR lock );
BPTR ParentOfFH( BPTR fh );
BOOL ExamineFH( BPTR fh, struct FileInfoBlock *fib );
LONG SetFileDate( CONST_STRPTR name, CONST struct DateStamp *date );
LONG NameFromLock( BPTR lock, STRPTR buffer, LONG len );
LONG NameFromFH( BPTR fh, STRPTR buffer, LONG len );
WORD SplitName( CONST_STRPTR name, ULONG separator, STRPTR buf, LONG oldpos, LONG size );
LONG SameLock( BPTR lock1, BPTR lock2 );
LONG SetMode( BPTR fh, LONG mode );
LONG ExAll( BPTR lock, struct ExAllData *buffer, LONG size, LONG data, struct ExAllControl *control );
LONG ReadLink( struct MsgPort *port, BPTR lock, CONST_STRPTR path, STRPTR buffer, ULONG size );
LONG MakeLink( CONST_STRPTR name, LONG dest, LONG soft );
LONG ChangeMode( LONG type, BPTR fh, LONG newmode );
LONG SetFileSize( BPTR fh, LONG pos, LONG mode );

LONG SetIoErr( LONG result );
BOOL Fault( LONG code, STRPTR header, STRPTR buffer, LONG len );
BOOL PrintFault( LONG code, CONST_STRPTR header );
LONG ErrorReport( LONG code, LONG type, ULONG arg1, struct MsgPort *device );

struct CommandLineInterface *Cli( VOID );
struct Process *CreateNewProc( CONST struct TagItem *tags );
struct Process *CreateNewProcTagList( CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Process *CreateNewProcTags( ULONG tag1type, ... );
#endif
LONG RunCommand( BPTR seg, LONG stack, CONST_STRPTR paramptr, LONG paramlen );
struct MsgPort *GetConsoleTask( VOID );
struct MsgPort *SetConsoleTask( CONST struct MsgPort *task );
struct MsgPort *GetFileSysTask( VOID );
struct MsgPort *SetFileSysTask( CONST struct MsgPort *task );
STRPTR GetArgStr( VOID );
BOOL SetArgStr( CONST_STRPTR string );
struct Process *FindCliProc( ULONG num );
ULONG MaxCli( VOID );
BOOL SetCurrentDirName( CONST_STRPTR name );
BOOL GetCurrentDirName( STRPTR buf, LONG len );
BOOL SetProgramName( CONST_STRPTR name );
BOOL GetProgramName( STRPTR buf, LONG len );
BOOL SetPrompt( CONST_STRPTR name );
BOOL GetPrompt( STRPTR buf, LONG len );
BPTR SetProgramDir( BPTR lock );
BPTR GetProgramDir( VOID );

LONG SystemTagList( CONST_STRPTR command, CONST struct TagItem *tags );
LONG System( CONST_STRPTR command, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG SystemTags( CONST_STRPTR command, ULONG tag1type, ... );
#endif
LONG AssignLock( CONST_STRPTR name, BPTR lock );
BOOL AssignLate( CONST_STRPTR name, CONST_STRPTR path );
BOOL AssignPath( CONST_STRPTR name, CONST_STRPTR path );
BOOL AssignAdd( CONST_STRPTR name, BPTR lock );
LONG RemAssignList( CONST_STRPTR name, BPTR lock );
struct DevProc *GetDeviceProc( CONST_STRPTR name, struct DevProc *dp );
VOID FreeDeviceProc( struct DevProc *dp );
struct DosList *LockDosList( ULONG flags );
VOID UnLockDosList( ULONG flags );
struct DosList *AttemptLockDosList( ULONG flags );
BOOL RemDosEntry( struct DosList *dlist );
LONG AddDosEntry( struct DosList *dlist );
struct DosList *FindDosEntry( CONST struct DosList *dlist, CONST_STRPTR name, ULONG flags );
struct DosList *NextDosEntry( CONST struct DosList *dlist, ULONG flags );
struct DosList *MakeDosEntry( CONST_STRPTR name, LONG type );
VOID FreeDosEntry( struct DosList *dlist );
BOOL IsFileSystem( CONST_STRPTR name );

BOOL Format( CONST_STRPTR filesystem, CONST_STRPTR volumename, ULONG dostype );
LONG Relabel( CONST_STRPTR drive, CONST_STRPTR newname );
LONG Inhibit( CONST_STRPTR name, LONG onoff );
LONG AddBuffers( CONST_STRPTR name, LONG number );

LONG CompareDates( CONST struct DateStamp *date1, CONST struct DateStamp *date2 );
LONG DateToStr( struct DateTime *datetime );
LONG StrToDate( struct DateTime *datetime );

BPTR InternalLoadSeg( BPTR fh, BPTR table, CONST LONG *funcarray, LONG *stack );
BOOL InternalUnLoadSeg( BPTR seglist, VOID (*CONST freefunc) __CLIB_PROTOTYPE((STRPTR,ULONG)) );
BPTR NewLoadSeg( CONST_STRPTR file, CONST struct TagItem *tags );
BPTR NewLoadSegTagList( CONST_STRPTR file, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
BPTR NewLoadSegTags( CONST_STRPTR file, ULONG tag1type, ... );
#endif
LONG AddSegment( CONST_STRPTR name, BPTR seg, LONG system );
struct Segment *FindSegment( CONST_STRPTR name, CONST struct Segment *seg, LONG system );
LONG RemSegment( struct Segment *seg );

LONG CheckSignal( LONG mask );
struct RDArgs *ReadArgs( CONST_STRPTR arg_template, LONG *array, struct RDArgs *args );
LONG FindArg( CONST_STRPTR keyword, CONST_STRPTR arg_template );
LONG ReadItem( CONST_STRPTR name, LONG maxchars, struct CSource *cSource );
LONG StrToLong( CONST_STRPTR string, LONG *value );
LONG MatchFirst( CONST_STRPTR pat, struct AnchorPath *anchor );
LONG MatchNext( struct AnchorPath *anchor );
VOID MatchEnd( struct AnchorPath *anchor );
LONG ParsePattern( CONST_STRPTR pat, STRPTR buf, LONG buflen );
BOOL MatchPattern( CONST_STRPTR pat, STRPTR str );
VOID FreeArgs( struct RDArgs *args );
STRPTR FilePart( CONST_STRPTR path );
STRPTR PathPart( CONST_STRPTR path );
BOOL AddPart( STRPTR dirname, CONST_STRPTR filename, ULONG size );

BOOL StartNotify( struct NotifyRequest *notify );
VOID EndNotify( struct NotifyRequest *notify );

BOOL SetVar( CONST_STRPTR name, CONST_STRPTR buffer, LONG size, LONG flags );
LONG GetVar( CONST_STRPTR name, STRPTR buffer, LONG size, LONG flags );
LONG DeleteVar( CONST_STRPTR name, ULONG flags );
struct LocalVar *FindVar( CONST_STRPTR name, ULONG type );
LONG CliInitNewcli( struct DosPacket *dp );
LONG CliInitRun( struct DosPacket *dp );
LONG WriteChars( CONST_STRPTR buf, ULONG buflen );
LONG PutStr( CONST_STRPTR str );
LONG VPrintf( CONST_STRPTR format, CONST APTR argarray );
#if !defined(USE_INLINE_STDARG)
LONG Printf( CONST_STRPTR format, ... );
#endif

LONG ParsePatternNoCase( CONST_STRPTR pat, UBYTE *buf, LONG buflen );
BOOL MatchPatternNoCase( CONST_STRPTR pat, STRPTR str );

BOOL SameDevice( BPTR lock1, BPTR lock2 );

VOID ExAllEnd( BPTR lock, struct ExAllData *buffer, LONG size, LONG data, struct ExAllControl *control );
BOOL SetOwner( CONST_STRPTR name, LONG owner_info );

/*** V50 ***/

LONG AddSegmentTagList(struct TagItem *);
LONG AddSegmentTags(ULONG tag1, ...);
struct Segment *FindSegmentTagList(struct TagItem *);
struct Segment *FindSegmentTags(ULONG tag1, ...);

/*** V51 ***/

QUAD Seek64( BPTR file, QUAD pos, LONG mode );
QUAD SetFileSize64( BPTR fh, QUAD pos, LONG mode );
LONG LockRecord64( BPTR fh, UQUAD offset, UQUAD length, ULONG mode, ULONG timeout );
LONG LockRecords64( struct RecordLock64 *recArray, ULONG timeout );
LONG UnLockRecord64( BPTR fh, UQUAD offset, UQUAD length );
LONG UnLockRecords64( struct RecordLock64 *recArray );
LONG Examine64( BPTR lock, struct FileInfoBlock *fib, struct TagItem *tags );
LONG Examine64TagList( BPTR lock, struct FileInfoBlock *fib, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG Examine64Tags( BPTR lock, struct FileInfoBlock *fib, ... );
#endif
LONG ExNext64( BPTR lock, struct FileInfoBlock *fib, struct TagItem *tags );
LONG ExNext64TagList( BPTR lock, struct FileInfoBlock *fib, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG ExNext64Tags( BPTR lock, struct FileInfoBlock *fib, ... );
#endif
LONG ExamineFH64( BPTR file, struct FileInfoBlock *fib, struct TagItem *tags );
LONG ExamineFH64TagList( BPTR file, struct FileInfoBlock *fib, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG ExamineFH64Tags( BPTR file, struct FileInfoBlock *fib, ... );
#endif
LONG NewReadLink( struct MsgPort *port, BPTR lock, CONST_STRPTR path, UBYTE *buffer, LONG buffer_size );
LONG GetFileSysAttr( CONST_STRPTR devicename, LONG attr, APTR storage, LONG storage_size );
LONG GetSegListAttr( BPTR seglist, LONG attr, APTR storage, LONG storage_size );
LONG SetDosObjectAttr( ULONG type, APTR ptr, struct TagItem *tags );
LONG SetDosObjectAttrTagList( ULONG type, APTR ptr, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG SetDosObjectAttrTags( ULONG type, APTR ptr, ... );
#endif
LONG GetDosObjectAttr( ULONG type, APTR ptr, struct TagItem *tags );
LONG GetDosObjectAttrTagList( ULONG type, APTR ptr, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG GetDosObjectAttrTags( ULONG type, APTR ptr, ... );
#endif

/*** V51.51 ***/
void ReleaseCLINumber( LONG clinum );
struct CLIData *QueryCLIDataTagList( struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct CLIData *QueryCLIDataTags( ULONG tag1, ... );
#endif
void FreeCLIData( struct CLIData *data );
/*** V51.52 ***/
LONG GetSegListAttrTagList( BPTR seglist, LONG attr, APTR storage, LONG storage_size, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG GetSegListAttrTags( BPTR seglist, LONG attr, APTR storage, LONG storage_size, ULONG tag1, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_DOS_PROTOS_H */
