#ifndef CLIB_EXEC_PROTOS_H
#define CLIB_EXEC_PROTOS_H

/*
	exec C prototypes

	Copyright © 2002-2020 The MorphOS Development Team, All Rights Reserved.
*/

#if defined(__ixemul__) && !defined(__IXEMUL_EXEC_MIXING_ALLOWED)
# error "Mixing ixemul and native library calls is not supported. Native application should be built with -noixemul"
#endif

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_MEMORY_H
# include <exec/memory.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef EXEC_DEVICES_H
# include <exec/devices.h>
#endif

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

ULONG Supervisor( ULONG (*CONST userFunction)(VOID) );

VOID InitCode( ULONG startClass, ULONG version );
VOID InitStruct( CONST APTR initTable, APTR memory, ULONG size );
struct Library *MakeLibrary( CONST APTR funcInit, CONST APTR structInit, ULONG (*CONST libInit)(VOID), ULONG dataSize, ULONG segList );
VOID MakeFunctions( APTR target, CONST APTR functionArray, CONST APTR funcDispBase );
struct Resident *FindResident( CONST_STRPTR name );
APTR InitResident( CONST struct Resident *resident, ULONG segList );

VOID Alert( ULONG alertNum );
VOID Debug( ULONG flags );

VOID Disable( VOID );
VOID Enable( VOID );
VOID Forbid( VOID );
VOID Permit( VOID );
ULONG SetSR( ULONG newSR, ULONG mask );
APTR SuperState( VOID );
VOID UserState( APTR sysStack );
struct Interrupt *SetIntVector( LONG intNumber, CONST struct Interrupt *interrupt );
VOID AddIntServer( LONG intNumber, struct Interrupt *interrupt );
VOID RemIntServer( LONG intNumber, struct Interrupt *interrupt );
VOID Cause( struct Interrupt *interrupt );

APTR Allocate( struct MemHeader *freeList, ULONG byteSize );
VOID Deallocate( struct MemHeader *freeList, APTR memoryBlock, ULONG byteSize );
APTR AllocMem( ULONG byteSize, ULONG requirements );
APTR AllocAbs( ULONG byteSize, APTR location );
VOID FreeMem( APTR memoryBlock, ULONG byteSize );
ULONG AvailMem( ULONG requirements );
struct MemList *AllocEntry( struct MemList *entry );
VOID FreeEntry( struct MemList *entry );

VOID Insert( struct List *list, struct Node *node, struct Node *pred );
VOID AddHead( struct List *list, struct Node *node );
VOID AddTail( struct List *list, struct Node *node );
VOID Remove( struct Node *node );
struct Node *RemHead( struct List *list );
struct Node *RemTail( struct List *list );
VOID Enqueue( struct List *list, struct Node *node );
struct Node *FindName( struct List *list, CONST_STRPTR name );

APTR AddTask( struct Task *task, CONST APTR initPC, CONST APTR finalPC );
VOID RemTask( struct Task *task );
struct Task *FindTask( CONST_STRPTR name );
BYTE SetTaskPri( struct Task *task, LONG priority );
ULONG SetSignal( ULONG newSignals, ULONG signalSet );
ULONG SetExcept( ULONG newSignals, ULONG signalSet );
ULONG Wait( ULONG signalSet );
VOID Signal( struct Task *task, ULONG signalSet );
BYTE AllocSignal( LONG signalNum );
VOID FreeSignal( LONG signalNum );
LONG AllocTrap( LONG trapNum );
VOID FreeTrap( LONG trapNum );

VOID AddPort( struct MsgPort *port );
VOID RemPort( struct MsgPort *port );
VOID PutMsg( struct MsgPort *port, struct Message *message );
struct Message *GetMsg( struct MsgPort *port );
VOID ReplyMsg( struct Message *message );
struct Message *WaitPort( struct MsgPort *port );
struct MsgPort *FindPort( CONST_STRPTR name );

VOID AddLibrary( struct Library *library );
VOID RemLibrary( struct Library *library );
struct Library *OldOpenLibrary( CONST_STRPTR libName );
VOID CloseLibrary( struct Library *library );
APTR SetFunction( struct Library *library, LONG funcOffset, ULONG (*CONST newFunction)(VOID) );
VOID SumLibrary( struct Library *library );

VOID AddDevice( struct Device *device );
VOID RemDevice( struct Device *device );
BYTE OpenDevice( CONST_STRPTR devName, ULONG unit, struct IORequest *ioRequest, ULONG flags );
VOID CloseDevice( struct IORequest *ioRequest );
BYTE DoIO( struct IORequest *ioRequest );
VOID SendIO( struct IORequest *ioRequest );
struct IORequest *CheckIO( struct IORequest *ioRequest );
BYTE WaitIO( struct IORequest *ioRequest );
VOID AbortIO( struct IORequest *ioRequest );

VOID AddResource( APTR resource );
VOID RemResource( APTR resource );
APTR OpenResource( CONST_STRPTR resName );

APTR RawDoFmt( CONST_STRPTR formatString, CONST APTR dataStream, VOID (*CONST putChProc)(VOID), APTR putChData );
ULONG GetCC( VOID );
ULONG TypeOfMem( CONST APTR address );
ULONG Procure( struct SignalSemaphore *sigSem, struct SemaphoreMessage *bidMsg );
VOID Vacate( struct SignalSemaphore *sigSem, struct SemaphoreMessage *bidMsg );
struct Library *OpenLibrary( CONST_STRPTR libName, ULONG version );

VOID InitSemaphore( struct SignalSemaphore *sigSem );
VOID ObtainSemaphore( struct SignalSemaphore *sigSem );
VOID ReleaseSemaphore( struct SignalSemaphore *sigSem );
ULONG AttemptSemaphore( struct SignalSemaphore *sigSem );
VOID ObtainSemaphoreList( struct List *sigSem );
VOID ReleaseSemaphoreList( struct List *sigSem );
struct SignalSemaphore *FindSemaphore( STRPTR name );
VOID AddSemaphore( struct SignalSemaphore *sigSem );
VOID RemSemaphore( struct SignalSemaphore *sigSem );
VOID ObtainSemaphoreShared( struct SignalSemaphore *sigSem );
ULONG AttemptSemaphoreShared( struct SignalSemaphore *sigSem );

ULONG SumKickData( VOID );

VOID AddMemList( ULONG size, ULONG attributes, LONG pri, APTR base, CONST_STRPTR name );
VOID CopyMem( CONST APTR source, APTR dest, ULONG size );
VOID CopyMemQuick( CONST APTR source, APTR dest, ULONG size );

VOID CacheClearU( VOID );
VOID CacheClearE( APTR address, ULONG length, ULONG caches );
ULONG CacheControl( ULONG cacheBits, ULONG cacheMask );

APTR CreateIORequest( CONST struct MsgPort *port, ULONG size );
VOID DeleteIORequest( APTR iorequest );
struct MsgPort *CreateMsgPort( VOID );
VOID DeleteMsgPort( struct MsgPort *port );

APTR AllocVec( ULONG byteSize, ULONG requirements );
VOID FreeVec( APTR memoryBlock );

APTR CreatePool( ULONG requirements, ULONG puddleSize, ULONG threshSize );
VOID DeletePool( APTR poolHeader );
APTR AllocPooled( APTR poolHeader, ULONG memSize );
VOID FreePooled( APTR poolHeader, APTR memory, ULONG memSize );

VOID ColdReboot( VOID );
VOID StackSwap( struct StackSwapStruct *newStack );

APTR CachePreDMA( CONST APTR address, ULONG *length, ULONG flags );
VOID CachePostDMA( CONST APTR address, ULONG *length, ULONG flags );

VOID AddMemHandler( struct Interrupt *memhand );
VOID RemMemHandler( struct Interrupt *memhand );

ULONG ObtainQuickVector( APTR interruptCode );


/*** Undocumented functions ***/

VOID RawIOInit( VOID );
UBYTE RawMayGetChar( VOID );
VOID RawPutChar( UBYTE MyChar );

APTR TaggedOpenLibrary( LONG LibTag );

ULONG ReadGayle( VOID );


/*** V50 ***/

ULONG NewGetTaskAttrsA( struct Task *task, APTR data, ULONG dataSize, ULONG type, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG NewGetTaskAttrs( struct Task *task, APTR data, ULONG dataSize, ULONG type, ... );
#endif

ULONG NewSetTaskAttrsA( struct Task *task, APTR data, ULONG dataSize, ULONG type, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG NewSetTaskAttrs( struct Task *task, APTR data, ULONG dataSize, ULONG type, ... );
#endif

struct Library *NewCreateLibrary( struct TagItem *Tags );
#if !defined(USE_INLINE_STDARG)
struct Library *NewCreateLibraryTags( ULONG tag1, ...);
#endif

APTR NewSetFunction( struct Library *MyLibrary, APTR MyFunction, LONG Offset, struct TagItem *Tags );

ULONG NewPPCStackSwap( struct StackSwapStruct *newStack, APTR MyFunction, struct PPCStackSwapArgs *Args );

STRPTR VNewRawDoFmt( CONST_STRPTR FmtString, APTR (*PutChProc)(APTR, UBYTE), STRPTR PutChData, va_list args );
STRPTR NewRawDoFmt( CONST_STRPTR FmtString, APTR (*PutChProc)(APTR, UBYTE), STRPTR PutChData, ... );

VOID CacheFlushDataArea( APTR Address, ULONG Size );
VOID CacheInvalidInstArea( APTR Address, ULONG Size );
VOID CacheInvalidDataArea( APTR Address, ULONG Size );
VOID CacheFlushDataInstArea( APTR Address, ULONG Size );
VOID CacheTrashCacheArea( APTR Address, ULONG Size );

APTR AllocTaskPooled( ULONG Size );
VOID FreeTaskPooled( APTR Address, ULONG Size );

APTR AllocVecTaskPooled( ULONG Size );
VOID FreeVecTaskPooled( APTR Address );

VOID FlushPool( APTR poolHeader );
VOID FlushTaskPool( VOID );

APTR AllocVecPooled( APTR poolHeader, ULONG memSize );
VOID FreeVecPooled( APTR poolHeader, APTR memory );

ULONG NewGetSystemAttrsA( APTR MyData, ULONG MySize, ULONG MyType, struct TagItem *MyTags );
#if !defined(USE_INLINE_STDARG)
ULONG NewGetSystemAttrs( APTR MyData, ULONG MySize, ULONG MyType, ... );
#endif

ULONG NewSetSystemAttrsA( APTR MyData, ULONG MySize, ULONG MyType, struct TagItem *MyTags );
#if !defined(USE_INLINE_STDARG)
ULONG NewSetSystemAttrs( APTR MyData, ULONG MySize, ULONG MyType, ... );
#endif

struct Task *NewCreateTaskA( struct TagItem *MyTags );
#if !defined(USE_INLINE_STDARG)
struct Task *NewCreateTask( Tag tag1, ... );
#endif

APTR AllocateAligned( struct MemHeader *memHeader, ULONG byteSize, ULONG alignSize, ULONG alignOffset );
APTR AllocMemAligned( ULONG byteSize, ULONG attributes, ULONG alignSize, ULONG alignOffset );
APTR AllocVecAligned( ULONG byteSize, ULONG attributes, ULONG alignSize, ULONG alignOffset );

VOID AddExecNotify( struct Hook *hook );
VOID RemExecNotify( struct Hook *hook );
struct Node *FindExecNode( ULONG type, CONST_STRPTR name );
APTR AddExecNodeA( APTR innode, struct TagItem *Tags );
#if !defined(USE_INLINE_STDARG)
APTR AddExecNode( APTR innode, ... );
#endif

APTR AllocVecDMA( ULONG byteSize, ULONG requirements );
VOID FreeVecDMA( APTR memoryBlock );

APTR AllocPooledAligned( APTR poolHeader, ULONG byteSize, ULONG alignSize, ULONG alignOffset );

LONG AddResident( struct Resident *resident );

struct Task *FindTaskByPID( ULONG processID );


void DumpTaskState( struct Task *task );

void AddExecNotifyType( struct Hook *hook, LONG Type );

ULONG ShutdownA( struct TagItem *MyTags );


ULONG AvailPool( APTR poolHeader, ULONG flags );


void PutMsgHead( struct MsgPort *port, struct Message *message );

ULONG NewGetTaskPIDAttrsA( ULONG pid, APTR data, ULONG dataSize, ULONG type, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG NewGetTaskPIDAttrs( ULONG pid, APTR data, ULONG dataSize, ULONG type, ... );
#endif

ULONG NewSetTaskPIDAttrsA( ULONG pid, APTR data, ULONG dataSize, ULONG type, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG NewSetTaskPIDAttrs( ULONG pid, APTR data, ULONG dataSize, ULONG type, ... );
#endif


/* TLS support functions (added in V51.46) */
ULONG TLSAllocA( struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
ULONG TLSAlloc( ULONG tag1, ... );
#endif
LONG TLSFree( ULONG idx );
APTR TLSGetValue( ULONG idx );
LONG TLSSetValue( ULONG idx, APTR value );
VOID TLSCallDestructors( struct Task *task );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifndef NewMinList
#define NewMinList(minlist)  NewList((struct List *)(minlist))
#endif


#endif /* CLIB_EXEC_PROTOS_H */
