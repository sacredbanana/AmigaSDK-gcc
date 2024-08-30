#ifndef PRAGMAS_EXEC_PRAGMAS_H
#define PRAGMAS_EXEC_PRAGMAS_H

/*
**	$VER: exec_sysbase_pragmas.h 47.5 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_EXEC_PROTOS_H
#include <clib/exec_protos.h>
#endif /* CLIB_EXEC_PROTOS_H */

/* "exec.library" */
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase Supervisor 1e D01
/*------ special patchable hooks to internal exec activity ------------*/
/*------ module creation ----------------------------------------------*/
#pragma libcall SysBase InitCode 48 1002
#pragma libcall SysBase InitStruct 4e 0A903
#pragma libcall SysBase MakeLibrary 54 10A9805
#pragma libcall SysBase MakeFunctions 5a A9803
#pragma libcall SysBase FindResident 60 901
#pragma libcall SysBase InitResident 66 1902
/*------ diagnostics --------------------------------------------------*/
#pragma libcall SysBase Alert 6c 701
#pragma libcall SysBase Debug 72 001
/*------ interrupts ---------------------------------------------------*/
#pragma libcall SysBase Disable 78 00
#pragma libcall SysBase Enable 7e 00
#pragma libcall SysBase Forbid 84 00
#pragma libcall SysBase Permit 8a 00
#pragma libcall SysBase SetSR 90 1002
#pragma libcall SysBase SuperState 96 00
#pragma libcall SysBase UserState 9c 001
#pragma libcall SysBase SetIntVector a2 9002
#pragma libcall SysBase AddIntServer a8 9002
#pragma libcall SysBase RemIntServer ae 9002
#pragma libcall SysBase Cause b4 901
/*------ memory allocation --------------------------------------------*/
#pragma libcall SysBase Allocate ba 0802
#pragma libcall SysBase Deallocate c0 09803
#pragma libcall SysBase AllocMem c6 1002
#pragma libcall SysBase AllocAbs cc 9002
#pragma libcall SysBase FreeMem d2 0902
#pragma libcall SysBase AvailMem d8 101
#pragma libcall SysBase AllocEntry de 801
#pragma libcall SysBase FreeEntry e4 801
/*------ lists --------------------------------------------------------*/
#pragma libcall SysBase Insert ea A9803
#pragma libcall SysBase InsertMinNode ea A9803
#pragma libcall SysBase AddHead f0 9802
#pragma libcall SysBase AddHeadMinList f0 9802
#pragma libcall SysBase AddTail f6 9802
#pragma libcall SysBase AddTailMinList f6 9802
#pragma libcall SysBase Remove fc 901
#pragma libcall SysBase RemoveMinNode fc 901
#pragma libcall SysBase RemHead 102 801
#pragma libcall SysBase RemHeadMinList 102 801
#pragma libcall SysBase RemTail 108 801
#pragma libcall SysBase RemTailMinList 108 801
#pragma libcall SysBase Enqueue 10e 9802
#pragma libcall SysBase FindName 114 9802
/*------ tasks --------------------------------------------------------*/
#pragma libcall SysBase AddTask 11a BA903
#pragma libcall SysBase RemTask 120 901
#pragma libcall SysBase FindTask 126 901
#pragma libcall SysBase SetTaskPri 12c 0902
#pragma libcall SysBase SetSignal 132 1002
#pragma libcall SysBase SetExcept 138 1002
#pragma libcall SysBase Wait 13e 001
#pragma libcall SysBase Signal 144 0902
#pragma libcall SysBase AllocSignal 14a 001
#pragma libcall SysBase FreeSignal 150 001
#pragma libcall SysBase AllocTrap 156 001
#pragma libcall SysBase FreeTrap 15c 001
/*------ messages -----------------------------------------------------*/
#pragma libcall SysBase AddPort 162 901
#pragma libcall SysBase RemPort 168 901
#pragma libcall SysBase PutMsg 16e 9802
#pragma libcall SysBase GetMsg 174 801
#pragma libcall SysBase ReplyMsg 17a 901
#pragma libcall SysBase WaitPort 180 801
#pragma libcall SysBase FindPort 186 901
/*------ libraries ----------------------------------------------------*/
#pragma libcall SysBase AddLibrary 18c 901
#pragma libcall SysBase RemLibrary 192 901
#pragma libcall SysBase OldOpenLibrary 198 901
#pragma libcall SysBase CloseLibrary 19e 901
#pragma libcall SysBase SetFunction 1a4 08903
#pragma libcall SysBase SumLibrary 1aa 901
/*------ devices ------------------------------------------------------*/
#pragma libcall SysBase AddDevice 1b0 901
#pragma libcall SysBase RemDevice 1b6 901
#pragma libcall SysBase OpenDevice 1bc 190804
#pragma libcall SysBase CloseDevice 1c2 901
#pragma libcall SysBase DoIO 1c8 901
#pragma libcall SysBase SendIO 1ce 901
#pragma libcall SysBase CheckIO 1d4 901
#pragma libcall SysBase WaitIO 1da 901
#pragma libcall SysBase AbortIO 1e0 901
/*------ resources ----------------------------------------------------*/
#pragma libcall SysBase AddResource 1e6 901
#pragma libcall SysBase RemResource 1ec 901
#pragma libcall SysBase OpenResource 1f2 901
/*------ private diagnostic support -----------------------------------*/
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase RawDoFmt 20a BA9804
#pragma libcall SysBase GetCC 210 00
#pragma libcall SysBase TypeOfMem 216 901
#pragma libcall SysBase Procure 21c 9802
#pragma libcall SysBase Vacate 222 9802
#pragma libcall SysBase OpenLibrary 228 0902
/*--- functions in V33 or higher (Release 1.2) ---*/
/*------ signal semaphores (note funny registers)----------------------*/
#pragma libcall SysBase InitSemaphore 22e 801
#pragma libcall SysBase ObtainSemaphore 234 801
#pragma libcall SysBase ReleaseSemaphore 23a 801
#pragma libcall SysBase AttemptSemaphore 240 801
#pragma libcall SysBase ObtainSemaphoreList 246 801
#pragma libcall SysBase ReleaseSemaphoreList 24c 801
#pragma libcall SysBase FindSemaphore 252 901
#pragma libcall SysBase AddSemaphore 258 901
#pragma libcall SysBase RemSemaphore 25e 901
/*------ kickmem support ----------------------------------------------*/
#pragma libcall SysBase SumKickData 264 00
/*------ more memory support ------------------------------------------*/
#pragma libcall SysBase AddMemList 26a 9821005
#pragma libcall SysBase CopyMem 270 09803
#pragma libcall SysBase CopyMemQuick 276 09803
/*------ cache --------------------------------------------------------*/
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall SysBase CacheClearU 27c 00
#pragma libcall SysBase CacheClearE 282 10803
#pragma libcall SysBase CacheControl 288 1002
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase CreateIORequest 28e 0802
#pragma libcall SysBase DeleteIORequest 294 801
#pragma libcall SysBase CreateMsgPort 29a 00
#pragma libcall SysBase DeleteMsgPort 2a0 801
#pragma libcall SysBase ObtainSemaphoreShared 2a6 801
/*------ even more memory support -------------------------------------*/
#pragma libcall SysBase AllocVec 2ac 1002
#pragma libcall SysBase FreeVec 2b2 901
/*------ V39 Pool LVOs...*/
#pragma libcall SysBase CreatePool 2b8 21003
#pragma libcall SysBase DeletePool 2be 801
#pragma libcall SysBase AllocPooled 2c4 0802
#pragma libcall SysBase FreePooled 2ca 09803
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase AttemptSemaphoreShared 2d0 801
#pragma libcall SysBase ColdReboot 2d6 00
#pragma libcall SysBase StackSwap 2dc 801
/*------ task trees ---------------------------------------------------*/
/*------ future expansion ---------------------------------------------*/
#pragma libcall SysBase CachePreDMA 2fa 09803
#pragma libcall SysBase CachePostDMA 300 09803
/*------ New, for V39*/
/*--- functions in V39 or higher (Release 3.0) ---*/
/*------ Low memory handler functions*/
#pragma libcall SysBase AddMemHandler 306 901
#pragma libcall SysBase RemMemHandler 30c 901
/*------ Function to attempt to obtain a Quick Interrupt Vector...*/
#pragma libcall SysBase ObtainQuickVector 312 801
/* For ROM Space, a tagged OpenLibrary */
/* More reserved LVOs */
/*--- functions in V45 or higher (Release 3.9) ---*/
/*------ Finally the list functions are complete*/
#pragma libcall SysBase NewMinList 33c 801
/*------ AVL tree support was introduced in V45 and was removed again in V46*/
/*--- (10 function slots reserved here) ---*/

#endif /* PRAGMAS_EXEC_PRAGMAS_H */
