#ifndef PRAGMAS_EXEC_PRAGMAS_H
#define PRAGMAS_EXEC_PRAGMAS_H

/*
**	$VER: exec_pragmas.h 47.5 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_EXEC_PROTOS_H
#include <clib/exec_protos.h>
#endif /* CLIB_EXEC_PROTOS_H */

/* "exec.library" */
/*------ misc ---------------------------------------------------------*/
#pragma syscall Supervisor 1e D01
/*------ special patchable hooks to internal exec activity ------------*/
/*------ module creation ----------------------------------------------*/
#pragma syscall InitCode 48 1002
#pragma syscall InitStruct 4e 0A903
#pragma syscall MakeLibrary 54 10A9805
#pragma syscall MakeFunctions 5a A9803
#pragma syscall FindResident 60 901
#pragma syscall InitResident 66 1902
/*------ diagnostics --------------------------------------------------*/
#pragma syscall Alert 6c 701
#pragma syscall Debug 72 001
/*------ interrupts ---------------------------------------------------*/
#pragma syscall Disable 78 00
#pragma syscall Enable 7e 00
#pragma syscall Forbid 84 00
#pragma syscall Permit 8a 00
#pragma syscall SetSR 90 1002
#pragma syscall SuperState 96 00
#pragma syscall UserState 9c 001
#pragma syscall SetIntVector a2 9002
#pragma syscall AddIntServer a8 9002
#pragma syscall RemIntServer ae 9002
#pragma syscall Cause b4 901
/*------ memory allocation --------------------------------------------*/
#pragma syscall Allocate ba 0802
#pragma syscall Deallocate c0 09803
#pragma syscall AllocMem c6 1002
#pragma syscall AllocAbs cc 9002
#pragma syscall FreeMem d2 0902
#pragma syscall AvailMem d8 101
#pragma syscall AllocEntry de 801
#pragma syscall FreeEntry e4 801
/*------ lists --------------------------------------------------------*/
#pragma syscall Insert ea A9803
#pragma syscall InsertMinNode ea A9803
#pragma syscall AddHead f0 9802
#pragma syscall AddHeadMinList f0 9802
#pragma syscall AddTail f6 9802
#pragma syscall AddTailMinList f6 9802
#pragma syscall Remove fc 901
#pragma syscall RemoveMinNode fc 901
#pragma syscall RemHead 102 801
#pragma syscall RemHeadMinList 102 801
#pragma syscall RemTail 108 801
#pragma syscall RemTailMinList 108 801
#pragma syscall Enqueue 10e 9802
#pragma syscall FindName 114 9802
/*------ tasks --------------------------------------------------------*/
#pragma syscall AddTask 11a BA903
#pragma syscall RemTask 120 901
#pragma syscall FindTask 126 901
#pragma syscall SetTaskPri 12c 0902
#pragma syscall SetSignal 132 1002
#pragma syscall SetExcept 138 1002
#pragma syscall Wait 13e 001
#pragma syscall Signal 144 0902
#pragma syscall AllocSignal 14a 001
#pragma syscall FreeSignal 150 001
#pragma syscall AllocTrap 156 001
#pragma syscall FreeTrap 15c 001
/*------ messages -----------------------------------------------------*/
#pragma syscall AddPort 162 901
#pragma syscall RemPort 168 901
#pragma syscall PutMsg 16e 9802
#pragma syscall GetMsg 174 801
#pragma syscall ReplyMsg 17a 901
#pragma syscall WaitPort 180 801
#pragma syscall FindPort 186 901
/*------ libraries ----------------------------------------------------*/
#pragma syscall AddLibrary 18c 901
#pragma syscall RemLibrary 192 901
#pragma syscall OldOpenLibrary 198 901
#pragma syscall CloseLibrary 19e 901
#pragma syscall SetFunction 1a4 08903
#pragma syscall SumLibrary 1aa 901
/*------ devices ------------------------------------------------------*/
#pragma syscall AddDevice 1b0 901
#pragma syscall RemDevice 1b6 901
#pragma syscall OpenDevice 1bc 190804
#pragma syscall CloseDevice 1c2 901
#pragma syscall DoIO 1c8 901
#pragma syscall SendIO 1ce 901
#pragma syscall CheckIO 1d4 901
#pragma syscall WaitIO 1da 901
#pragma syscall AbortIO 1e0 901
/*------ resources ----------------------------------------------------*/
#pragma syscall AddResource 1e6 901
#pragma syscall RemResource 1ec 901
#pragma syscall OpenResource 1f2 901
/*------ private diagnostic support -----------------------------------*/
/*------ misc ---------------------------------------------------------*/
#pragma syscall RawDoFmt 20a BA9804
#pragma syscall GetCC 210 00
#pragma syscall TypeOfMem 216 901
#pragma syscall Procure 21c 9802
#pragma syscall Vacate 222 9802
#pragma syscall OpenLibrary 228 0902
/*--- functions in V33 or higher (Release 1.2) ---*/
/*------ signal semaphores (note funny registers)----------------------*/
#pragma syscall InitSemaphore 22e 801
#pragma syscall ObtainSemaphore 234 801
#pragma syscall ReleaseSemaphore 23a 801
#pragma syscall AttemptSemaphore 240 801
#pragma syscall ObtainSemaphoreList 246 801
#pragma syscall ReleaseSemaphoreList 24c 801
#pragma syscall FindSemaphore 252 901
#pragma syscall AddSemaphore 258 901
#pragma syscall RemSemaphore 25e 901
/*------ kickmem support ----------------------------------------------*/
#pragma syscall SumKickData 264 00
/*------ more memory support ------------------------------------------*/
#pragma syscall AddMemList 26a 9821005
#pragma syscall CopyMem 270 09803
#pragma syscall CopyMemQuick 276 09803
/*------ cache --------------------------------------------------------*/
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma syscall CacheClearU 27c 00
#pragma syscall CacheClearE 282 10803
#pragma syscall CacheControl 288 1002
/*------ misc ---------------------------------------------------------*/
#pragma syscall CreateIORequest 28e 0802
#pragma syscall DeleteIORequest 294 801
#pragma syscall CreateMsgPort 29a 00
#pragma syscall DeleteMsgPort 2a0 801
#pragma syscall ObtainSemaphoreShared 2a6 801
/*------ even more memory support -------------------------------------*/
#pragma syscall AllocVec 2ac 1002
#pragma syscall FreeVec 2b2 901
/*------ V39 Pool LVOs...*/
#pragma syscall CreatePool 2b8 21003
#pragma syscall DeletePool 2be 801
#pragma syscall AllocPooled 2c4 0802
#pragma syscall FreePooled 2ca 09803
/*------ misc ---------------------------------------------------------*/
#pragma syscall AttemptSemaphoreShared 2d0 801
#pragma syscall ColdReboot 2d6 00
#pragma syscall StackSwap 2dc 801
/*------ task trees ---------------------------------------------------*/
/*------ future expansion ---------------------------------------------*/
#pragma syscall CachePreDMA 2fa 09803
#pragma syscall CachePostDMA 300 09803
/*------ New, for V39*/
/*--- functions in V39 or higher (Release 3.0) ---*/
/*------ Low memory handler functions*/
#pragma syscall AddMemHandler 306 901
#pragma syscall RemMemHandler 30c 901
/*------ Function to attempt to obtain a Quick Interrupt Vector...*/
#pragma syscall ObtainQuickVector 312 801
/* For ROM Space, a tagged OpenLibrary */
/* More reserved LVOs */
/*--- functions in V45 or higher (Release 3.9) ---*/
/*------ Finally the list functions are complete*/
#pragma syscall NewMinList 33c 801
/*------ AVL tree support was introduced in V45 and was removed again in V46*/
/*--- (10 function slots reserved here) ---*/

#endif /* PRAGMAS_EXEC_PRAGMAS_H */
