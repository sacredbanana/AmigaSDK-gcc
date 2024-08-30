#ifndef PRAGMA_EXEC_LIB_H
#define PRAGMA_EXEC_LIB_H

/*
**	$VER: exec_lib.h 47.5 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_EXEC_PROTOS_H
#include <clib/exec_protos.h>
#endif /* CLIB_EXEC_PROTOS_H */

/* "exec.library" */
/*------ misc ---------------------------------------------------------*/
#pragma amicall(SysBase, 0x1e, Supervisor(a5))
/*------ special patchable hooks to internal exec activity ------------*/
/*------ module creation ----------------------------------------------*/
#pragma amicall(SysBase, 0x48, InitCode(d0,d1))
#pragma amicall(SysBase, 0x4e, InitStruct(a1,a2,d0))
#pragma amicall(SysBase, 0x54, MakeLibrary(a0,a1,a2,d0,d1))
#pragma amicall(SysBase, 0x5a, MakeFunctions(a0,a1,a2))
#pragma amicall(SysBase, 0x60, FindResident(a1))
#pragma amicall(SysBase, 0x66, InitResident(a1,d1))
/*------ diagnostics --------------------------------------------------*/
#pragma amicall(SysBase, 0x6c, Alert(d7))
#pragma amicall(SysBase, 0x72, Debug(d0))
/*------ interrupts ---------------------------------------------------*/
#pragma amicall(SysBase, 0x78, Disable())
#pragma amicall(SysBase, 0x7e, Enable())
#pragma amicall(SysBase, 0x84, Forbid())
#pragma amicall(SysBase, 0x8a, Permit())
#pragma amicall(SysBase, 0x90, SetSR(d0,d1))
#pragma amicall(SysBase, 0x96, SuperState())
#pragma amicall(SysBase, 0x9c, UserState(d0))
#pragma amicall(SysBase, 0xa2, SetIntVector(d0,a1))
#pragma amicall(SysBase, 0xa8, AddIntServer(d0,a1))
#pragma amicall(SysBase, 0xae, RemIntServer(d0,a1))
#pragma amicall(SysBase, 0xb4, Cause(a1))
/*------ memory allocation --------------------------------------------*/
#pragma amicall(SysBase, 0xba, Allocate(a0,d0))
#pragma amicall(SysBase, 0xc0, Deallocate(a0,a1,d0))
#pragma amicall(SysBase, 0xc6, AllocMem(d0,d1))
#pragma amicall(SysBase, 0xcc, AllocAbs(d0,a1))
#pragma amicall(SysBase, 0xd2, FreeMem(a1,d0))
#pragma amicall(SysBase, 0xd8, AvailMem(d1))
#pragma amicall(SysBase, 0xde, AllocEntry(a0))
#pragma amicall(SysBase, 0xe4, FreeEntry(a0))
/*------ lists --------------------------------------------------------*/
#pragma amicall(SysBase, 0xea, Insert(a0,a1,a2))
#pragma amicall(SysBase, 0xea, InsertMinNode(a0,a1,a2))
#pragma amicall(SysBase, 0xf0, AddHead(a0,a1))
#pragma amicall(SysBase, 0xf0, AddHeadMinList(a0,a1))
#pragma amicall(SysBase, 0xf6, AddTail(a0,a1))
#pragma amicall(SysBase, 0xf6, AddTailMinList(a0,a1))
#pragma amicall(SysBase, 0xfc, Remove(a1))
#pragma amicall(SysBase, 0xfc, RemoveMinNode(a1))
#pragma amicall(SysBase, 0x102, RemHead(a0))
#pragma amicall(SysBase, 0x102, RemHeadMinList(a0))
#pragma amicall(SysBase, 0x108, RemTail(a0))
#pragma amicall(SysBase, 0x108, RemTailMinList(a0))
#pragma amicall(SysBase, 0x10e, Enqueue(a0,a1))
#pragma amicall(SysBase, 0x114, FindName(a0,a1))
/*------ tasks --------------------------------------------------------*/
#pragma amicall(SysBase, 0x11a, AddTask(a1,a2,a3))
#pragma amicall(SysBase, 0x120, RemTask(a1))
#pragma amicall(SysBase, 0x126, FindTask(a1))
#pragma amicall(SysBase, 0x12c, SetTaskPri(a1,d0))
#pragma amicall(SysBase, 0x132, SetSignal(d0,d1))
#pragma amicall(SysBase, 0x138, SetExcept(d0,d1))
#pragma amicall(SysBase, 0x13e, Wait(d0))
#pragma amicall(SysBase, 0x144, Signal(a1,d0))
#pragma amicall(SysBase, 0x14a, AllocSignal(d0))
#pragma amicall(SysBase, 0x150, FreeSignal(d0))
#pragma amicall(SysBase, 0x156, AllocTrap(d0))
#pragma amicall(SysBase, 0x15c, FreeTrap(d0))
/*------ messages -----------------------------------------------------*/
#pragma amicall(SysBase, 0x162, AddPort(a1))
#pragma amicall(SysBase, 0x168, RemPort(a1))
#pragma amicall(SysBase, 0x16e, PutMsg(a0,a1))
#pragma amicall(SysBase, 0x174, GetMsg(a0))
#pragma amicall(SysBase, 0x17a, ReplyMsg(a1))
#pragma amicall(SysBase, 0x180, WaitPort(a0))
#pragma amicall(SysBase, 0x186, FindPort(a1))
/*------ libraries ----------------------------------------------------*/
#pragma amicall(SysBase, 0x18c, AddLibrary(a1))
#pragma amicall(SysBase, 0x192, RemLibrary(a1))
#pragma amicall(SysBase, 0x198, OldOpenLibrary(a1))
#pragma amicall(SysBase, 0x19e, CloseLibrary(a1))
#pragma amicall(SysBase, 0x1a4, SetFunction(a1,a0,d0))
#pragma amicall(SysBase, 0x1aa, SumLibrary(a1))
/*------ devices ------------------------------------------------------*/
#pragma amicall(SysBase, 0x1b0, AddDevice(a1))
#pragma amicall(SysBase, 0x1b6, RemDevice(a1))
#pragma amicall(SysBase, 0x1bc, OpenDevice(a0,d0,a1,d1))
#pragma amicall(SysBase, 0x1c2, CloseDevice(a1))
#pragma amicall(SysBase, 0x1c8, DoIO(a1))
#pragma amicall(SysBase, 0x1ce, SendIO(a1))
#pragma amicall(SysBase, 0x1d4, CheckIO(a1))
#pragma amicall(SysBase, 0x1da, WaitIO(a1))
#pragma amicall(SysBase, 0x1e0, AbortIO(a1))
/*------ resources ----------------------------------------------------*/
#pragma amicall(SysBase, 0x1e6, AddResource(a1))
#pragma amicall(SysBase, 0x1ec, RemResource(a1))
#pragma amicall(SysBase, 0x1f2, OpenResource(a1))
/*------ private diagnostic support -----------------------------------*/
/*------ misc ---------------------------------------------------------*/
#pragma amicall(SysBase, 0x20a, RawDoFmt(a0,a1,a2,a3))
#pragma amicall(SysBase, 0x210, GetCC())
#pragma amicall(SysBase, 0x216, TypeOfMem(a1))
#pragma amicall(SysBase, 0x21c, Procure(a0,a1))
#pragma amicall(SysBase, 0x222, Vacate(a0,a1))
#pragma amicall(SysBase, 0x228, OpenLibrary(a1,d0))
/*--- functions in V33 or higher (Release 1.2) ---*/
/*------ signal semaphores (note funny registers)----------------------*/
#pragma amicall(SysBase, 0x22e, InitSemaphore(a0))
#pragma amicall(SysBase, 0x234, ObtainSemaphore(a0))
#pragma amicall(SysBase, 0x23a, ReleaseSemaphore(a0))
#pragma amicall(SysBase, 0x240, AttemptSemaphore(a0))
#pragma amicall(SysBase, 0x246, ObtainSemaphoreList(a0))
#pragma amicall(SysBase, 0x24c, ReleaseSemaphoreList(a0))
#pragma amicall(SysBase, 0x252, FindSemaphore(a1))
#pragma amicall(SysBase, 0x258, AddSemaphore(a1))
#pragma amicall(SysBase, 0x25e, RemSemaphore(a1))
/*------ kickmem support ----------------------------------------------*/
#pragma amicall(SysBase, 0x264, SumKickData())
/*------ more memory support ------------------------------------------*/
#pragma amicall(SysBase, 0x26a, AddMemList(d0,d1,d2,a0,a1))
#pragma amicall(SysBase, 0x270, CopyMem(a0,a1,d0))
#pragma amicall(SysBase, 0x276, CopyMemQuick(a0,a1,d0))
/*------ cache --------------------------------------------------------*/
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(SysBase, 0x27c, CacheClearU())
#pragma amicall(SysBase, 0x282, CacheClearE(a0,d0,d1))
#pragma amicall(SysBase, 0x288, CacheControl(d0,d1))
/*------ misc ---------------------------------------------------------*/
#pragma amicall(SysBase, 0x28e, CreateIORequest(a0,d0))
#pragma amicall(SysBase, 0x294, DeleteIORequest(a0))
#pragma amicall(SysBase, 0x29a, CreateMsgPort())
#pragma amicall(SysBase, 0x2a0, DeleteMsgPort(a0))
#pragma amicall(SysBase, 0x2a6, ObtainSemaphoreShared(a0))
/*------ even more memory support -------------------------------------*/
#pragma amicall(SysBase, 0x2ac, AllocVec(d0,d1))
#pragma amicall(SysBase, 0x2b2, FreeVec(a1))
/*------ V39 Pool LVOs...*/
#pragma amicall(SysBase, 0x2b8, CreatePool(d0,d1,d2))
#pragma amicall(SysBase, 0x2be, DeletePool(a0))
#pragma amicall(SysBase, 0x2c4, AllocPooled(a0,d0))
#pragma amicall(SysBase, 0x2ca, FreePooled(a0,a1,d0))
/*------ misc ---------------------------------------------------------*/
#pragma amicall(SysBase, 0x2d0, AttemptSemaphoreShared(a0))
#pragma amicall(SysBase, 0x2d6, ColdReboot())
#pragma amicall(SysBase, 0x2dc, StackSwap(a0))
/*------ task trees ---------------------------------------------------*/
/*------ future expansion ---------------------------------------------*/
#pragma amicall(SysBase, 0x2fa, CachePreDMA(a0,a1,d0))
#pragma amicall(SysBase, 0x300, CachePostDMA(a0,a1,d0))
/*------ New, for V39*/
/*--- functions in V39 or higher (Release 3.0) ---*/
/*------ Low memory handler functions*/
#pragma amicall(SysBase, 0x306, AddMemHandler(a1))
#pragma amicall(SysBase, 0x30c, RemMemHandler(a1))
/*------ Function to attempt to obtain a Quick Interrupt Vector...*/
#pragma amicall(SysBase, 0x312, ObtainQuickVector(a0))
/* For ROM Space, a tagged OpenLibrary */
/* More reserved LVOs */
/*--- functions in V45 or higher (Release 3.9) ---*/
/*------ Finally the list functions are complete*/
#pragma amicall(SysBase, 0x33c, NewMinList(a0))
/*------ AVL tree support was introduced in V45 and was removed again in V46*/
/*--- (10 function slots reserved here) ---*/

#endif /* PRAGMA_EXEC_LIB_H */
