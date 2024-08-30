#ifndef CLIB_EXEC_PROTOS_H
#define CLIB_EXEC_PROTOS_H

/*
**	$VER: exec_protos.h 47.5 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_EXECBASE_H
#include <exec/execbase.h>
#endif
#ifndef  EXEC_TASKS_H
#include <exec/tasks.h>
#endif
#ifndef  EXEC_MEMORY_H
#include <exec/memory.h>
#endif
#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  EXEC_DEVICES_H
#include <exec/devices.h>
#endif
#ifndef  EXEC_IO_H
#include <exec/io.h>
#endif
#ifndef  EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif
#ifndef  EXEC_RESIDENT_H
#include <exec/resident.h>
#endif
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
/*------ misc ---------------------------------------------------------*/
ULONG    __stdargs Supervisor( ULONG (*userFunction)() );
/*------ special patchable hooks to internal exec activity ------------*/
/*------ module creation ----------------------------------------------*/
VOID    __stdargs InitCode( ULONG startClass, ULONG version );
VOID    __stdargs InitStruct( CONST_APTR initTable, APTR memory, ULONG size );
struct Library *   __stdargs MakeLibrary( CONST_APTR funcInit, CONST_APTR structInit, ULONG (*libInit)(), ULONG dataSize, ULONG segList );
VOID    __stdargs MakeFunctions( APTR target, CONST_APTR functionArray, ULONG funcDispBase );
struct Resident *   __stdargs FindResident( CONST_STRPTR name );
APTR    __stdargs InitResident( CONST struct Resident *resident, ULONG segList );
/*------ diagnostics --------------------------------------------------*/
VOID    __stdargs Alert( ULONG alertNum );
VOID    __stdargs Debug( ULONG flags );
/*------ interrupts ---------------------------------------------------*/
VOID    __stdargs Disable( VOID );
VOID    __stdargs Enable( VOID );
VOID    __stdargs Forbid( VOID );
VOID    __stdargs Permit( VOID );
ULONG    __stdargs SetSR( ULONG newSR, ULONG mask );
APTR    __stdargs SuperState( VOID );
VOID    __stdargs UserState( APTR sysStack );
struct Interrupt *   __stdargs SetIntVector( LONG intNumber, struct Interrupt *interrupt );
VOID    __stdargs AddIntServer( LONG intNumber, struct Interrupt *interrupt );
VOID    __stdargs RemIntServer( LONG intNumber, struct Interrupt *interrupt );
VOID    __stdargs Cause( CONST struct Interrupt *interrupt );
/*------ memory allocation --------------------------------------------*/
APTR    __stdargs Allocate( struct MemHeader *freeList, ULONG byteSize );
VOID    __stdargs Deallocate( struct MemHeader *freeList, APTR memoryBlock, ULONG byteSize );
APTR    __stdargs AllocMem( ULONG byteSize, ULONG requirements );
APTR    __stdargs AllocAbs( ULONG byteSize, APTR location );
VOID    __stdargs FreeMem( APTR memoryBlock, ULONG byteSize );
ULONG    __stdargs AvailMem( ULONG requirements );
struct MemList *   __stdargs AllocEntry( CONST struct MemList *entry );
VOID    __stdargs FreeEntry( struct MemList *entry );
/*------ lists --------------------------------------------------------*/
VOID    __stdargs Insert( struct List *list, struct Node *node, struct Node *pred );
VOID    __stdargs InsertMinNode( struct MinList *minlist, struct MinNode *minnode, struct MinNode *minpred );
VOID    __stdargs AddHead( struct List *list, struct Node *node );
VOID    __stdargs AddHeadMinList( struct MinList *minlist, struct MinNode *minnode );
VOID    __stdargs AddTail( struct List *list, struct Node *node );
VOID    __stdargs AddTailMinList( struct MinList *minlist, struct MinNode *minnode );
VOID    __stdargs Remove( struct Node *node );
VOID    __stdargs RemoveMinNode( struct MinNode *minnode );
struct Node *   __stdargs RemHead( struct List *list );
struct MinNode *   __stdargs RemHeadMinList( struct MinList *minlist );
struct Node *   __stdargs RemTail( struct List *list );
struct MinNode *   __stdargs RemTailMinList( struct MinList *minlist );
VOID    __stdargs Enqueue( struct List *list, struct Node *node );
struct Node *   __stdargs FindName( struct List *list, CONST_STRPTR name );
/*------ tasks --------------------------------------------------------*/
APTR    __stdargs AddTask( struct Task *task, APTR initPC, APTR finalPC );
VOID    __stdargs RemTask( struct Task *task );
struct Task *   __stdargs FindTask( CONST_STRPTR name );
BYTE    __stdargs SetTaskPri( struct Task *task, LONG priority );
ULONG    __stdargs SetSignal( ULONG newSignals, ULONG signalSet );
ULONG    __stdargs SetExcept( ULONG newSignals, ULONG signalSet );
ULONG    __stdargs Wait( ULONG signalSet );
VOID    __stdargs Signal( struct Task *task, ULONG signalSet );
BYTE    __stdargs AllocSignal( LONG signalNum );
VOID    __stdargs FreeSignal( LONG signalNum );
LONG    __stdargs AllocTrap( LONG trapNum );
VOID    __stdargs FreeTrap( LONG trapNum );
/*------ messages -----------------------------------------------------*/
VOID    __stdargs AddPort( struct MsgPort *port );
VOID    __stdargs RemPort( struct MsgPort *port );
VOID    __stdargs PutMsg( struct MsgPort *port, struct Message *message );
struct Message *   __stdargs GetMsg( struct MsgPort *port );
VOID    __stdargs ReplyMsg( struct Message *message );
struct Message *   __stdargs WaitPort( struct MsgPort *port );
struct MsgPort *   __stdargs FindPort( CONST_STRPTR name );
/*------ libraries ----------------------------------------------------*/
VOID    __stdargs AddLibrary( struct Library *library );
VOID    __stdargs RemLibrary( struct Library *library );
struct Library *   __stdargs OldOpenLibrary( CONST_STRPTR libName );
VOID    __stdargs CloseLibrary( struct Library *library );
APTR    __stdargs SetFunction( struct Library *library, LONG funcOffset, ULONG (*newFunction)() );
VOID    __stdargs SumLibrary( struct Library *library );
/*------ devices ------------------------------------------------------*/
VOID    __stdargs AddDevice( struct Device *device );
VOID    __stdargs RemDevice( struct Device *device );
BYTE    __stdargs OpenDevice( CONST_STRPTR devName, ULONG unit, struct IORequest *ioRequest, ULONG flags );
VOID    __stdargs CloseDevice( struct IORequest *ioRequest );
BYTE    __stdargs DoIO( struct IORequest *ioRequest );
VOID    __stdargs SendIO( struct IORequest *ioRequest );
struct IORequest *   __stdargs CheckIO( CONST struct IORequest *ioRequest );
BYTE    __stdargs WaitIO( struct IORequest *ioRequest );
VOID    __stdargs AbortIO( struct IORequest *ioRequest );
/*------ resources ----------------------------------------------------*/
VOID    __stdargs AddResource( APTR resource );
VOID    __stdargs RemResource( APTR resource );
APTR    __stdargs OpenResource( CONST_STRPTR resName );
/*------ private diagnostic support -----------------------------------*/
/*------ misc ---------------------------------------------------------*/
APTR    __stdargs RawDoFmt( CONST_STRPTR formatString, APTR dataStream, VOID (*putChProc)(), APTR putChData );
ULONG    __stdargs GetCC( VOID );
ULONG    __stdargs TypeOfMem( CONST_APTR address );
ULONG    __stdargs Procure( struct SignalSemaphore *sigSem, struct SemaphoreMessage *bidMsg );
VOID    __stdargs Vacate( struct SignalSemaphore *sigSem, struct SemaphoreMessage *bidMsg );
struct Library *   __stdargs OpenLibrary( CONST_STRPTR libName, ULONG version );
/*--- functions in V33 or higher (Release 1.2) ---*/
/*------ signal semaphores (note funny registers)----------------------*/
VOID    __stdargs InitSemaphore( struct SignalSemaphore *sigSem );
VOID    __stdargs ObtainSemaphore( struct SignalSemaphore *sigSem );
VOID    __stdargs ReleaseSemaphore( struct SignalSemaphore *sigSem );
ULONG    __stdargs AttemptSemaphore( struct SignalSemaphore *sigSem );
VOID    __stdargs ObtainSemaphoreList( struct List *sigSem );
VOID    __stdargs ReleaseSemaphoreList( struct List *sigSem );
struct SignalSemaphore *   __stdargs FindSemaphore( CONST_STRPTR name );
VOID    __stdargs AddSemaphore( struct SignalSemaphore *sigSem );
VOID    __stdargs RemSemaphore( struct SignalSemaphore *sigSem );
/*------ kickmem support ----------------------------------------------*/
ULONG    __stdargs SumKickData( VOID );
/*------ more memory support ------------------------------------------*/
VOID    __stdargs AddMemList( ULONG size, ULONG attributes, LONG pri, APTR base, STRPTR name );
VOID    __stdargs CopyMem( CONST_APTR source, APTR dest, ULONG size );
VOID    __stdargs CopyMemQuick( CONST_APTR source, APTR dest, ULONG size );
/*------ cache --------------------------------------------------------*/
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
