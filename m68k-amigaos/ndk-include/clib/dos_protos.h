#ifndef CLIB_DOS_PROTOS_H
#define CLIB_DOS_PROTOS_H

/*
**	$VER: dos_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
BPTR  __stdargs Open( CONST_STRPTR name, LONG accessMode );
LONG  __stdargs Close( BPTR file );
LONG  __stdargs Read( BPTR file, APTR buffer, LONG length );
LONG  __stdargs Write( BPTR file, CONST_APTR buffer, LONG length );
BPTR  __stdargs Input( VOID );
BPTR  __stdargs Output( VOID );
LONG  __stdargs Seek( BPTR file, LONG position, LONG offset );
LONG  __stdargs DeleteFile( CONST_STRPTR name );
LONG  __stdargs Rename( CONST_STRPTR oldName, CONST_STRPTR newName );
BPTR  __stdargs Lock( CONST_STRPTR name, LONG type );
VOID  __stdargs UnLock( BPTR lock );
BPTR  __stdargs DupLock( BPTR lock );
LONG  __stdargs Examine( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG  __stdargs ExNext( BPTR lock, struct FileInfoBlock *fileInfoBlock );
LONG  __stdargs Info( BPTR lock, struct InfoData *parameterBlock );
BPTR  __stdargs CreateDir( CONST_STRPTR name );
BPTR  __stdargs CurrentDir( BPTR lock );
LONG  __stdargs IoErr( VOID );
struct MsgPort * __stdargs CreateProc( CONST_STRPTR name, LONG pri, BPTR segList, LONG stackSize );
VOID  __stdargs Exit( LONG returnCode );
BPTR  __stdargs LoadSeg( CONST_STRPTR name );
VOID  __stdargs UnLoadSeg( BPTR seglist );
struct MsgPort * __stdargs DeviceProc( CONST_STRPTR name );
LONG  __stdargs SetComment( CONST_STRPTR name, CONST_STRPTR comment );
LONG  __stdargs SetProtection( CONST_STRPTR name, LONG protect );
struct DateStamp * __stdargs DateStamp( struct DateStamp *date );
VOID  __stdargs Delay( LONG timeout );
LONG  __stdargs WaitForChar( BPTR file, LONG timeout );
BPTR  __stdargs ParentDir( BPTR lock );
LONG  __stdargs IsInteractive( BPTR file );
LONG  __stdargs Execute( CONST_STRPTR string, BPTR file, BPTR file2 );
/*--- functions in V36 or higher (Release 2.0) ---*/
/*	DOS Object creation/deletion */
APTR  __stdargs AllocDosObject( ULONG type, CONST struct TagItem *tags );
APTR  __stdargs AllocDosObjectTagList( ULONG type, CONST struct TagItem *tags );
APTR  __stdargs AllocDosObjectTags( ULONG type, ULONG tag1type, ... );
VOID  __stdargs FreeDosObject( ULONG type, APTR ptr );
/*	Packet Level routines */
LONG  __stdargs DoPkt( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5 );
LONG  __stdargs DoPkt0( struct MsgPort *port, LONG action );
LONG  __stdargs DoPkt1( struct MsgPort *port, LONG action, LONG arg1 );
LONG  __stdargs DoPkt2( struct MsgPort *port, LONG action, LONG arg1, LONG arg2 );
LONG  __stdargs DoPkt3( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3 );
LONG  __stdargs DoPkt4( struct MsgPort *port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4 );
VOID  __stdargs SendPkt( struct DosPacket *dp, struct MsgPort *port, struct MsgPort *replyport );
struct DosPacket * __stdargs WaitPkt( VOID );
VOID  __stdargs ReplyPkt( struct DosPacket *dp, LONG res1, LONG res2 );
VOID  __stdargs AbortPkt( struct MsgPort *port, struct DosPacket *pkt );
/*	Record Locking */
BOOL  __stdargs LockRecord( BPTR fh, ULONG offset, ULONG length, ULONG mode, ULONG timeout );
BOOL  __stdargs LockRecords( CONST struct RecordLock *recArray, ULONG timeout );
BOOL  __stdargs UnLockRecord( BPTR fh, ULONG offset, ULONG length );
BOOL  __stdargs UnLockRecords( CONST struct RecordLock *recArray );
/*	Buffered File I/O */
BPTR  __stdargs SelectInput( BPTR fh );
BPTR  __stdargs SelectOutput( BPTR fh );
LONG  __stdargs FGetC( BPTR fh );
LONG  __stdargs FPutC( BPTR fh, LONG ch );
LONG  __stdargs UnGetC( BPTR fh, LONG character );
LONG  __stdargs FRead( BPTR fh, APTR block, ULONG blocklen, ULONG number );
LONG  __stdargs FWrite( BPTR fh, CONST_APTR block, ULONG blocklen, ULONG number );
STRPTR  __stdargs FGets( BPTR fh, STRPTR buf, ULONG buflen );
LONG  __stdargs FPuts( BPTR fh, CONST_STRPTR str );
VOID  __stdargs VFWritef( BPTR fh, CONST_STRPTR format, CONST LONG *argarray );
VOID  __stdargs FWritef( BPTR fh, CONST_STRPTR format, ... );
LONG  __stdargs VFPrintf( BPTR fh, CONST_STRPTR format, CONST_APTR argarray );
LONG  __stdargs FPrintf( BPTR fh, CONST_STRPTR format, ... );
LONG  __stdargs Flush( BPTR fh );
LONG  __stdargs SetVBuf( BPTR fh, STRPTR buff, LONG type, LONG size );
/*	DOS Object Management */
BPTR  __stdargs DupLockFromFH( BPTR fh );
BPTR  __stdargs OpenFromLock( BPTR lock );
BPTR  __stdargs ParentOfFH( BPTR fh );
BOOL  __stdargs ExamineFH( BPTR fh, struct FileInfoBlock *fib );
LONG  __stdargs SetFileDate( CONST_STRPTR name, CONST struct DateStamp *date );
LONG  __stdargs NameFromLock( BPTR lock, STRPTR buffer, LONG len );
LONG  __stdargs NameFromFH( BPTR fh, STRPTR buffer, LONG len );
WORD  __stdargs SplitName( CONST_STRPTR name, ULONG separator, STRPTR buf, LONG oldpos, LONG size );
LONG  __stdargs SameLock( BPTR lock1, BPTR lock2 );
LONG  __stdargs SetMode( BPTR fh, LONG mode );
LONG  __stdargs ExAll( BPTR lock, struct ExAllData *buffer, LONG size, LONG data, struct ExAllControl *control );
LONG  __stdargs ReadLink( struct MsgPort *port, BPTR lock, CONST_STRPTR path, STRPTR buffer, ULONG size );
LONG  __stdargs MakeLink( CONST_STRPTR name, LONG dest, LONG soft );
LONG  __stdargs ChangeMode( LONG type, BPTR fh, LONG newmode );
LONG  __stdargs SetFileSize( BPTR fh, LONG pos, LONG mode );
/*	Error Handling */
LONG  __stdargs SetIoErr( LONG result );
BOOL  __stdargs Fault( LONG code, CONST_STRPTR header, STRPTR buffer, LONG len );
BOOL  __stdargs PrintFault( LONG code, CONST_STRPTR header );
LONG  __stdargs ErrorReport( LONG code, LONG type, ULONG arg1, struct MsgPort *device );
/*	Process Management */
struct CommandLineInterface * __stdargs Cli( VOID );
struct Process * __stdargs CreateNewProc( CONST struct TagItem *tags );
struct Process * __stdargs CreateNewProcTagList( CONST struct TagItem *tags );
struct Process * __stdargs CreateNewProcTags( ULONG tag1type, ... );
LONG  __stdargs RunCommand( BPTR seg, LONG stack, CONST_STRPTR paramptr, LONG paramlen );
struct MsgPort * __stdargs GetConsoleTask( VOID );
struct MsgPort * __stdargs SetConsoleTask( struct MsgPort *task );
struct MsgPort * __stdargs GetFileSysTask( VOID );
struct MsgPort * __stdargs SetFileSysTask( struct MsgPort *task );
STRPTR  __stdargs GetArgStr( VOID );
STRPTR  __stdargs SetArgStr( STRPTR string );
struct Process * __stdargs FindCliProc( ULONG num );
ULONG  __stdargs MaxCli( VOID );
BOOL  __stdargs SetCurrentDirName( CONST_STRPTR name );
BOOL  __stdargs GetCurrentDirName( STRPTR buf, LONG len );
BOOL  __stdargs SetProgramName( CONST_STRPTR name );
BOOL  __stdargs GetProgramName( STRPTR buf, LONG len );
BOOL  __stdargs SetPrompt( CONST_STRPTR name );
BOOL  __stdargs GetPrompt( STRPTR buf, LONG len );
BPTR  __stdargs SetProgramDir( BPTR lock );
BPTR  __stdargs GetProgramDir( VOID );
/*	Device List Management */
LONG  __stdargs SystemTagList( CONST_STRPTR command, CONST struct TagItem *tags );
LONG  __stdargs System( CONST_STRPTR command, CONST struct TagItem *tags );
LONG  __stdargs SystemTags( CONST_STRPTR command, ULONG tag1type, ... );
LONG  __stdargs AssignLock( CONST_STRPTR name, BPTR lock );
BOOL  __stdargs AssignLate( CONST_STRPTR name, CONST_STRPTR path );
BOOL  __stdargs AssignPath( CONST_STRPTR name, CONST_STRPTR path );
BOOL  __stdargs AssignAdd( CONST_STRPTR name, BPTR lock );
LONG  __stdargs RemAssignList( CONST_STRPTR name, BPTR lock );
struct DevProc * __stdargs GetDeviceProc( CONST_STRPTR name, struct DevProc *dp );
VOID  __stdargs FreeDeviceProc( struct DevProc *dp );
struct DosList * __stdargs LockDosList( ULONG flags );
VOID  __stdargs UnLockDosList( ULONG flags );
struct DosList * __stdargs AttemptLockDosList( ULONG flags );
BOOL  __stdargs RemDosEntry( struct DosList *dlist );
LONG  __stdargs AddDosEntry( struct DosList *dlist );
struct DosList * __stdargs FindDosEntry( CONST struct DosList *dlist, CONST_STRPTR name, ULONG flags );
struct DosList * __stdargs NextDosEntry( CONST struct DosList *dlist, ULONG flags );
struct DosList * __stdargs MakeDosEntry( CONST_STRPTR name, LONG type );
VOID  __stdargs FreeDosEntry( struct DosList *dlist );
BOOL  __stdargs IsFileSystem( CONST_STRPTR name );
/*	Handler Interface */
BOOL  __stdargs Format( CONST_STRPTR filesystem, CONST_STRPTR volumename, ULONG dostype );
LONG  __stdargs Relabel( CONST_STRPTR drive, CONST_STRPTR newname );
LONG  __stdargs Inhibit( CONST_STRPTR name, LONG onoff );
LONG  __stdargs AddBuffers( CONST_STRPTR name, LONG number );
/*	Date, Time Routines */
LONG  __stdargs CompareDates( CONST struct DateStamp *date1, CONST struct DateStamp *date2 );
LONG  __stdargs DateToStr( struct DateTime *datetime );
LONG  __stdargs StrToDate( struct DateTime *datetime );
/*	Image Management */
BPTR  __stdargs InternalLoadSeg( BPTR fh, BPTR table, CONST LONG *funcarray, LONG *stack );
BOOL  __stdargs InternalUnLoadSeg( BPTR seglist, VOID (*freefunc)() );
BPTR  __stdargs NewLoadSeg( CONST_STRPTR file, CONST struct TagItem *tags );
BPTR  __stdargs NewLoadSegTagList( CONST_STRPTR file, CONST struct TagItem *tags );
BPTR  __stdargs NewLoadSegTags( CONST_STRPTR file, ULONG tag1type, ... );
LONG  __stdargs AddSegment( CONST_STRPTR name, BPTR seg, LONG system );
struct Segment * __stdargs FindSegment( CONST_STRPTR name, CONST struct Segment *seg, LONG system );
LONG  __stdargs RemSegment( struct Segment *seg );
/*	Command Support */
LONG  __stdargs CheckSignal( LONG mask );
struct RDArgs * __stdargs ReadArgs( CONST_STRPTR arg_template, LONG *array, struct RDArgs *args );
LONG  __stdargs FindArg( CONST_STRPTR keyword, CONST_STRPTR arg_template );
LONG  __stdargs ReadItem( CONST_STRPTR name, LONG maxchars, struct CSource *cSource );
LONG  __stdargs StrToLong( CONST_STRPTR string, LONG *value );
LONG  __stdargs MatchFirst( CONST_STRPTR pat, struct AnchorPath *anchor );
LONG  __stdargs MatchNext( struct AnchorPath *anchor );
VOID  __stdargs MatchEnd( struct AnchorPath *anchor );
LONG  __stdargs ParsePattern( CONST_STRPTR pat, UBYTE *patbuf, LONG patbuflen );
BOOL  __stdargs MatchPattern( CONST UBYTE *patbuf, CONST_STRPTR str );
VOID  __stdargs FreeArgs( struct RDArgs *args );
STRPTR  __stdargs FilePart( CONST_STRPTR path );
STRPTR  __stdargs PathPart( CONST_STRPTR path );
BOOL  __stdargs AddPart( STRPTR dirname, CONST_STRPTR filename, ULONG size );
/*	Notification */
BOOL  __stdargs StartNotify( struct NotifyRequest *notify );
VOID  __stdargs EndNotify( struct NotifyRequest *notify );
/*	Environment Variable functions */
BOOL  __stdargs SetVar( CONST_STRPTR name, CONST_STRPTR buffer, LONG size, LONG flags );
LONG  __stdargs GetVar( CONST_STRPTR name, STRPTR buffer, LONG size, LONG flags );
LONG  __stdargs DeleteVar( CONST_STRPTR name, ULONG flags );
struct LocalVar * __stdargs FindVar( CONST_STRPTR name, ULONG type );
LONG  __stdargs CliInitNewcli( struct DosPacket *dp );
LONG  __stdargs CliInitRun( struct DosPacket *dp );
LONG  __stdargs WriteChars( CONST_STRPTR buf, ULONG buflen );
LONG  __stdargs PutStr( CONST_STRPTR str );
LONG  __stdargs VPrintf( CONST_STRPTR format, CONST_APTR argarray );
LONG  __stdargs Printf( CONST_STRPTR format, ... );
/* these were unimplemented until dos 36.147 */
LONG  __stdargs ParsePatternNoCase( CONST_STRPTR pat, UBYTE *patbuf, LONG patbuflen );
BOOL  __stdargs MatchPatternNoCase( CONST UBYTE *patbuf, CONST_STRPTR str );
/* this was added for V37 dos, returned 0 before then. */
BOOL  __stdargs SameDevice( BPTR lock1, BPTR lock2 );

/* NOTE: the following entries did NOT exist before ks 36.303 (2.02) */
/* If you are going to use them, open dos.library with version 37 */

/* These calls were added for V39 dos: */
VOID  __stdargs ExAllEnd( BPTR lock, struct ExAllData *buffer, LONG size, LONG data, struct ExAllControl *control );
BOOL  __stdargs SetOwner( CONST_STRPTR name, LONG owner_info );
/* Added with dos 47.4 */
LONG  __stdargs VolumeRequestHook( CONST_STRPTR vol );
BPTR  __stdargs GetCurrentDir( VOID );
LONG  __stdargs PutErrStr( CONST_STRPTR str );
LONG  __stdargs ErrorOutput( VOID );
LONG  __stdargs SelectError( BPTR fh );
APTR  __stdargs DoShellMethodTagList( ULONG method, CONST struct TagItem *tags );
APTR  __stdargs DoShellMethod( ULONG method, ULONG tag1type, ... );
LONG  __stdargs ScanStackToken( BPTR seg, LONG defaultstack );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_DOS_PROTOS_H */
