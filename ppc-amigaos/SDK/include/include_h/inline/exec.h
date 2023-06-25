#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_EXEC_H
#define _INLINE_EXEC_H

#ifndef CLIB_EXEC_PROTOS_H
#define CLIB_EXEC_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
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
#ifndef  EXEC_AVL_H
#include <exec/avl.h>
#endif

#ifndef EXEC_BASE_NAME
#define EXEC_BASE_NAME SysBase
#endif

#define Supervisor(userFunction) ({ \
  ULONG (*_Supervisor_userFunction)() = (userFunction); \
  ULONG _Supervisor__re = \
  ({ \
  register struct ExecBase * const __Supervisor__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __Supervisor__re __asm("d0"); \
  register ULONG (*__Supervisor_userFunction)() __asm("d2") = (_Supervisor_userFunction); \
  __asm volatile ("exg a5,d2\n\tjsr a6@(-30:W)\n\texg a5,d2" \
  : "=r"(__Supervisor__re) \
  : "r"(__Supervisor__bn), "r"(__Supervisor_userFunction) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Supervisor__re; \
  }); \
  _Supervisor__re; \
})

#define InitCode(startClass, version) ({ \
  ULONG _InitCode_startClass = (startClass); \
  ULONG _InitCode_version = (version); \
  { \
  register struct ExecBase * const __InitCode__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __InitCode_startClass __asm("d0") = (_InitCode_startClass); \
  register ULONG __InitCode_version __asm("d1") = (_InitCode_version); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__InitCode__bn), "r"(__InitCode_startClass), "r"(__InitCode_version) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InitStruct(initTable, memory, size) ({ \
  const APTR _InitStruct_initTable = (initTable); \
  APTR _InitStruct_memory = (memory); \
  ULONG _InitStruct_size = (size); \
  { \
  register struct ExecBase * const __InitStruct__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register const APTR __InitStruct_initTable __asm("a1") = (_InitStruct_initTable); \
  register APTR __InitStruct_memory __asm("a2") = (_InitStruct_memory); \
  register ULONG __InitStruct_size __asm("d0") = (_InitStruct_size); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__InitStruct__bn), "r"(__InitStruct_initTable), "r"(__InitStruct_memory), "r"(__InitStruct_size) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MakeLibrary(funcInit, structInit, libInit, dataSize, segList) ({ \
  const APTR _MakeLibrary_funcInit = (funcInit); \
  const APTR _MakeLibrary_structInit = (structInit); \
  ULONG (*_MakeLibrary_libInit)() = (libInit); \
  ULONG _MakeLibrary_dataSize = (dataSize); \
  ULONG _MakeLibrary_segList = (segList); \
  struct Library * _MakeLibrary__re = \
  ({ \
  register struct ExecBase * const __MakeLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __MakeLibrary__re __asm("d0"); \
  register const APTR __MakeLibrary_funcInit __asm("a0") = (_MakeLibrary_funcInit); \
  register const APTR __MakeLibrary_structInit __asm("a1") = (_MakeLibrary_structInit); \
  register ULONG (*__MakeLibrary_libInit)() __asm("a2") = (_MakeLibrary_libInit); \
  register ULONG __MakeLibrary_dataSize __asm("d0") = (_MakeLibrary_dataSize); \
  register ULONG __MakeLibrary_segList __asm("d1") = (_MakeLibrary_segList); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__MakeLibrary__re) \
  : "r"(__MakeLibrary__bn), "r"(__MakeLibrary_funcInit), "r"(__MakeLibrary_structInit), "r"(__MakeLibrary_libInit), "r"(__MakeLibrary_dataSize), "r"(__MakeLibrary_segList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MakeLibrary__re; \
  }); \
  _MakeLibrary__re; \
})

#define MakeFunctions(target, functionArray, funcDispBase) ({ \
  APTR _MakeFunctions_target = (target); \
  const APTR _MakeFunctions_functionArray = (functionArray); \
  const APTR _MakeFunctions_funcDispBase = (funcDispBase); \
  { \
  register struct ExecBase * const __MakeFunctions__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __MakeFunctions_target __asm("a0") = (_MakeFunctions_target); \
  register const APTR __MakeFunctions_functionArray __asm("a1") = (_MakeFunctions_functionArray); \
  register const APTR __MakeFunctions_funcDispBase __asm("a2") = (_MakeFunctions_funcDispBase); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__MakeFunctions__bn), "r"(__MakeFunctions_target), "r"(__MakeFunctions_functionArray), "r"(__MakeFunctions_funcDispBase) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindResident(name) ({ \
  CONST_STRPTR _FindResident_name = (name); \
  struct Resident * _FindResident__re = \
  ({ \
  register struct ExecBase * const __FindResident__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Resident * __FindResident__re __asm("d0"); \
  register CONST_STRPTR __FindResident_name __asm("a1") = (_FindResident_name); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__FindResident__re) \
  : "r"(__FindResident__bn), "r"(__FindResident_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindResident__re; \
  }); \
  _FindResident__re; \
})

#define InitResident(resident, segList) ({ \
  const struct Resident * _InitResident_resident = (resident); \
  ULONG _InitResident_segList = (segList); \
  APTR _InitResident__re = \
  ({ \
  register struct ExecBase * const __InitResident__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __InitResident__re __asm("d0"); \
  register const struct Resident * __InitResident_resident __asm("a1") = (_InitResident_resident); \
  register ULONG __InitResident_segList __asm("d1") = (_InitResident_segList); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__InitResident__re) \
  : "r"(__InitResident__bn), "r"(__InitResident_resident), "r"(__InitResident_segList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __InitResident__re; \
  }); \
  _InitResident__re; \
})

#define Alert(alertNum) ({ \
  ULONG _Alert_alertNum = (alertNum); \
  { \
  register struct ExecBase * const __Alert__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __Alert_alertNum __asm("d7") = (_Alert_alertNum); \
  __asm volatile ("jsr a6@(-108:W)" \
  : \
  : "r"(__Alert__bn), "r"(__Alert_alertNum) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Debug(flags) ({ \
  ULONG _Debug_flags = (flags); \
  { \
  register struct ExecBase * const __Debug__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __Debug_flags __asm("d0") = (_Debug_flags); \
  __asm volatile ("jsr a6@(-114:W)" \
  : \
  : "r"(__Debug__bn), "r"(__Debug_flags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Disable() ({ \
  register struct ExecBase * const __Disable__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__Disable__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define Enable() ({ \
  register struct ExecBase * const __Enable__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  __asm volatile ("jsr a6@(-126:W)" \
  : \
  : "r"(__Enable__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define Forbid() ({ \
  register struct ExecBase * const __Forbid__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__Forbid__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define Permit() ({ \
  register struct ExecBase * const __Permit__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  __asm volatile ("jsr a6@(-138:W)" \
  : \
  : "r"(__Permit__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define SetSR(newSR, mask) ({ \
  ULONG _SetSR_newSR = (newSR); \
  ULONG _SetSR_mask = (mask); \
  ULONG _SetSR__re = \
  ({ \
  register struct ExecBase * const __SetSR__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __SetSR__re __asm("d0"); \
  register ULONG __SetSR_newSR __asm("d0") = (_SetSR_newSR); \
  register ULONG __SetSR_mask __asm("d1") = (_SetSR_mask); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__SetSR__re) \
  : "r"(__SetSR__bn), "r"(__SetSR_newSR), "r"(__SetSR_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetSR__re; \
  }); \
  _SetSR__re; \
})

#define SuperState() ({ \
  APTR _SuperState__re = \
  ({ \
  register struct ExecBase * const __SuperState__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __SuperState__re __asm("d0"); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__SuperState__re) \
  : "r"(__SuperState__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SuperState__re; \
  }); \
  _SuperState__re; \
})

#define UserState(sysStack) ({ \
  APTR _UserState_sysStack = (sysStack); \
  { \
  register struct ExecBase * const __UserState__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __UserState_sysStack __asm("d0") = (_UserState_sysStack); \
  __asm volatile ("jsr a6@(-156:W)" \
  : \
  : "r"(__UserState__bn), "r"(__UserState_sysStack) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetIntVector(intNumber, interrupt) ({ \
  LONG _SetIntVector_intNumber = (intNumber); \
  const struct Interrupt * _SetIntVector_interrupt = (interrupt); \
  struct Interrupt * _SetIntVector__re = \
  ({ \
  register struct ExecBase * const __SetIntVector__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Interrupt * __SetIntVector__re __asm("d0"); \
  register LONG __SetIntVector_intNumber __asm("d0") = (_SetIntVector_intNumber); \
  register const struct Interrupt * __SetIntVector_interrupt __asm("a1") = (_SetIntVector_interrupt); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__SetIntVector__re) \
  : "r"(__SetIntVector__bn), "r"(__SetIntVector_intNumber), "r"(__SetIntVector_interrupt) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetIntVector__re; \
  }); \
  _SetIntVector__re; \
})

#define AddIntServer(intNumber, interrupt) ({ \
  LONG _AddIntServer_intNumber = (intNumber); \
  struct Interrupt * _AddIntServer_interrupt = (interrupt); \
  { \
  register struct ExecBase * const __AddIntServer__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register LONG __AddIntServer_intNumber __asm("d0") = (_AddIntServer_intNumber); \
  register struct Interrupt * __AddIntServer_interrupt __asm("a1") = (_AddIntServer_interrupt); \
  __asm volatile ("jsr a6@(-168:W)" \
  : \
  : "r"(__AddIntServer__bn), "r"(__AddIntServer_intNumber), "r"(__AddIntServer_interrupt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemIntServer(intNumber, interrupt) ({ \
  LONG _RemIntServer_intNumber = (intNumber); \
  struct Interrupt * _RemIntServer_interrupt = (interrupt); \
  { \
  register struct ExecBase * const __RemIntServer__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register LONG __RemIntServer_intNumber __asm("d0") = (_RemIntServer_intNumber); \
  register struct Interrupt * __RemIntServer_interrupt __asm("a1") = (_RemIntServer_interrupt); \
  __asm volatile ("jsr a6@(-174:W)" \
  : \
  : "r"(__RemIntServer__bn), "r"(__RemIntServer_intNumber), "r"(__RemIntServer_interrupt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Cause(interrupt) ({ \
  struct Interrupt * _Cause_interrupt = (interrupt); \
  { \
  register struct ExecBase * const __Cause__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Interrupt * __Cause_interrupt __asm("a1") = (_Cause_interrupt); \
  __asm volatile ("jsr a6@(-180:W)" \
  : \
  : "r"(__Cause__bn), "r"(__Cause_interrupt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Allocate(freeList, byteSize) ({ \
  struct MemHeader * _Allocate_freeList = (freeList); \
  ULONG _Allocate_byteSize = (byteSize); \
  APTR _Allocate__re = \
  ({ \
  register struct ExecBase * const __Allocate__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __Allocate__re __asm("d0"); \
  register struct MemHeader * __Allocate_freeList __asm("a0") = (_Allocate_freeList); \
  register ULONG __Allocate_byteSize __asm("d0") = (_Allocate_byteSize); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__Allocate__re) \
  : "r"(__Allocate__bn), "r"(__Allocate_freeList), "r"(__Allocate_byteSize) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Allocate__re; \
  }); \
  _Allocate__re; \
})

#define Deallocate(freeList, memoryBlock, byteSize) ({ \
  struct MemHeader * _Deallocate_freeList = (freeList); \
  APTR _Deallocate_memoryBlock = (memoryBlock); \
  ULONG _Deallocate_byteSize = (byteSize); \
  { \
  register struct ExecBase * const __Deallocate__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MemHeader * __Deallocate_freeList __asm("a0") = (_Deallocate_freeList); \
  register APTR __Deallocate_memoryBlock __asm("a1") = (_Deallocate_memoryBlock); \
  register ULONG __Deallocate_byteSize __asm("d0") = (_Deallocate_byteSize); \
  __asm volatile ("jsr a6@(-192:W)" \
  : \
  : "r"(__Deallocate__bn), "r"(__Deallocate_freeList), "r"(__Deallocate_memoryBlock), "r"(__Deallocate_byteSize) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocMem(byteSize, requirements) ({ \
  ULONG _AllocMem_byteSize = (byteSize); \
  ULONG _AllocMem_requirements = (requirements); \
  APTR _AllocMem__re = \
  ({ \
  register struct ExecBase * const __AllocMem__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __AllocMem__re __asm("d0"); \
  register ULONG __AllocMem_byteSize __asm("d0") = (_AllocMem_byteSize); \
  register ULONG __AllocMem_requirements __asm("d1") = (_AllocMem_requirements); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__AllocMem__re) \
  : "r"(__AllocMem__bn), "r"(__AllocMem_byteSize), "r"(__AllocMem_requirements) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocMem__re; \
  }); \
  _AllocMem__re; \
})

#define AllocAbs(byteSize, location) ({ \
  ULONG _AllocAbs_byteSize = (byteSize); \
  APTR _AllocAbs_location = (location); \
  APTR _AllocAbs__re = \
  ({ \
  register struct ExecBase * const __AllocAbs__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __AllocAbs__re __asm("d0"); \
  register ULONG __AllocAbs_byteSize __asm("d0") = (_AllocAbs_byteSize); \
  register APTR __AllocAbs_location __asm("a1") = (_AllocAbs_location); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__AllocAbs__re) \
  : "r"(__AllocAbs__bn), "r"(__AllocAbs_byteSize), "r"(__AllocAbs_location) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocAbs__re; \
  }); \
  _AllocAbs__re; \
})

#define FreeMem(memoryBlock, byteSize) ({ \
  APTR _FreeMem_memoryBlock = (memoryBlock); \
  ULONG _FreeMem_byteSize = (byteSize); \
  { \
  register struct ExecBase * const __FreeMem__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __FreeMem_memoryBlock __asm("a1") = (_FreeMem_memoryBlock); \
  register ULONG __FreeMem_byteSize __asm("d0") = (_FreeMem_byteSize); \
  __asm volatile ("jsr a6@(-210:W)" \
  : \
  : "r"(__FreeMem__bn), "r"(__FreeMem_memoryBlock), "r"(__FreeMem_byteSize) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AvailMem(requirements) ({ \
  ULONG _AvailMem_requirements = (requirements); \
  ULONG _AvailMem__re = \
  ({ \
  register struct ExecBase * const __AvailMem__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __AvailMem__re __asm("d0"); \
  register ULONG __AvailMem_requirements __asm("d1") = (_AvailMem_requirements); \
  __asm volatile ("jsr a6@(-216:W)" \
  : "=r"(__AvailMem__re) \
  : "r"(__AvailMem__bn), "r"(__AvailMem_requirements) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AvailMem__re; \
  }); \
  _AvailMem__re; \
})

#define AllocEntry(entry) ({ \
  struct MemList * _AllocEntry_entry = (entry); \
  struct MemList * _AllocEntry__re = \
  ({ \
  register struct ExecBase * const __AllocEntry__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MemList * __AllocEntry__re __asm("d0"); \
  register struct MemList * __AllocEntry_entry __asm("a0") = (_AllocEntry_entry); \
  __asm volatile ("jsr a6@(-222:W)" \
  : "=r"(__AllocEntry__re) \
  : "r"(__AllocEntry__bn), "r"(__AllocEntry_entry) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocEntry__re; \
  }); \
  _AllocEntry__re; \
})

#define FreeEntry(entry) ({ \
  struct MemList * _FreeEntry_entry = (entry); \
  { \
  register struct ExecBase * const __FreeEntry__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MemList * __FreeEntry_entry __asm("a0") = (_FreeEntry_entry); \
  __asm volatile ("jsr a6@(-228:W)" \
  : \
  : "r"(__FreeEntry__bn), "r"(__FreeEntry_entry) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Insert(list, node, pred) ({ \
  struct List * _Insert_list = (list); \
  struct Node * _Insert_node = (node); \
  struct Node * _Insert_pred = (pred); \
  { \
  register struct ExecBase * const __Insert__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct List * __Insert_list __asm("a0") = (_Insert_list); \
  register struct Node * __Insert_node __asm("a1") = (_Insert_node); \
  register struct Node * __Insert_pred __asm("a2") = (_Insert_pred); \
  __asm volatile ("jsr a6@(-234:W)" \
  : \
  : "r"(__Insert__bn), "r"(__Insert_list), "r"(__Insert_node), "r"(__Insert_pred) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddHead(list, node) ({ \
  struct List * _AddHead_list = (list); \
  struct Node * _AddHead_node = (node); \
  { \
  register struct ExecBase * const __AddHead__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct List * __AddHead_list __asm("a0") = (_AddHead_list); \
  register struct Node * __AddHead_node __asm("a1") = (_AddHead_node); \
  __asm volatile ("jsr a6@(-240:W)" \
  : \
  : "r"(__AddHead__bn), "r"(__AddHead_list), "r"(__AddHead_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddTail(list, node) ({ \
  struct List * _AddTail_list = (list); \
  struct Node * _AddTail_node = (node); \
  { \
  register struct ExecBase * const __AddTail__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct List * __AddTail_list __asm("a0") = (_AddTail_list); \
  register struct Node * __AddTail_node __asm("a1") = (_AddTail_node); \
  __asm volatile ("jsr a6@(-246:W)" \
  : \
  : "r"(__AddTail__bn), "r"(__AddTail_list), "r"(__AddTail_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Remove(node) ({ \
  struct Node * _Remove_node = (node); \
  { \
  register struct ExecBase * const __Remove__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Node * __Remove_node __asm("a1") = (_Remove_node); \
  __asm volatile ("jsr a6@(-252:W)" \
  : \
  : "r"(__Remove__bn), "r"(__Remove_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemHead(list) ({ \
  struct List * _RemHead_list = (list); \
  struct Node * _RemHead__re = \
  ({ \
  register struct ExecBase * const __RemHead__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Node * __RemHead__re __asm("d0"); \
  register struct List * __RemHead_list __asm("a0") = (_RemHead_list); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r"(__RemHead__re) \
  : "r"(__RemHead__bn), "r"(__RemHead_list) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemHead__re; \
  }); \
  _RemHead__re; \
})

#define RemTail(list) ({ \
  struct List * _RemTail_list = (list); \
  struct Node * _RemTail__re = \
  ({ \
  register struct ExecBase * const __RemTail__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Node * __RemTail__re __asm("d0"); \
  register struct List * __RemTail_list __asm("a0") = (_RemTail_list); \
  __asm volatile ("jsr a6@(-264:W)" \
  : "=r"(__RemTail__re) \
  : "r"(__RemTail__bn), "r"(__RemTail_list) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemTail__re; \
  }); \
  _RemTail__re; \
})

#define Enqueue(list, node) ({ \
  struct List * _Enqueue_list = (list); \
  struct Node * _Enqueue_node = (node); \
  { \
  register struct ExecBase * const __Enqueue__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct List * __Enqueue_list __asm("a0") = (_Enqueue_list); \
  register struct Node * __Enqueue_node __asm("a1") = (_Enqueue_node); \
  __asm volatile ("jsr a6@(-270:W)" \
  : \
  : "r"(__Enqueue__bn), "r"(__Enqueue_list), "r"(__Enqueue_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindName(list, name) ({ \
  struct List * _FindName_list = (list); \
  CONST_STRPTR _FindName_name = (name); \
  struct Node * _FindName__re = \
  ({ \
  register struct ExecBase * const __FindName__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Node * __FindName__re __asm("d0"); \
  register struct List * __FindName_list __asm("a0") = (_FindName_list); \
  register CONST_STRPTR __FindName_name __asm("a1") = (_FindName_name); \
  __asm volatile ("jsr a6@(-276:W)" \
  : "=r"(__FindName__re) \
  : "r"(__FindName__bn), "r"(__FindName_list), "r"(__FindName_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindName__re; \
  }); \
  _FindName__re; \
})

#define AddTask(task, initPC, finalPC) ({ \
  struct Task * _AddTask_task = (task); \
  const APTR _AddTask_initPC = (initPC); \
  const APTR _AddTask_finalPC = (finalPC); \
  APTR _AddTask__re = \
  ({ \
  register struct ExecBase * const __AddTask__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __AddTask__re __asm("d0"); \
  register struct Task * __AddTask_task __asm("a1") = (_AddTask_task); \
  register const APTR __AddTask_initPC __asm("a2") = (_AddTask_initPC); \
  register const APTR __AddTask_finalPC __asm("a3") = (_AddTask_finalPC); \
  __asm volatile ("jsr a6@(-282:W)" \
  : "=r"(__AddTask__re) \
  : "r"(__AddTask__bn), "r"(__AddTask_task), "r"(__AddTask_initPC), "r"(__AddTask_finalPC) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddTask__re; \
  }); \
  _AddTask__re; \
})

#define RemTask(task) ({ \
  struct Task * _RemTask_task = (task); \
  { \
  register struct ExecBase * const __RemTask__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Task * __RemTask_task __asm("a1") = (_RemTask_task); \
  __asm volatile ("jsr a6@(-288:W)" \
  : \
  : "r"(__RemTask__bn), "r"(__RemTask_task) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindTask(name) ({ \
  CONST_STRPTR _FindTask_name = (name); \
  struct Task * _FindTask__re = \
  ({ \
  register struct ExecBase * const __FindTask__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Task * __FindTask__re __asm("d0"); \
  register CONST_STRPTR __FindTask_name __asm("a1") = (_FindTask_name); \
  __asm volatile ("jsr a6@(-294:W)" \
  : "=r"(__FindTask__re) \
  : "r"(__FindTask__bn), "r"(__FindTask_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindTask__re; \
  }); \
  _FindTask__re; \
})

#define SetTaskPri(task, priority) ({ \
  struct Task * _SetTaskPri_task = (task); \
  BYTE _SetTaskPri_priority = (priority); \
  BYTE _SetTaskPri__re = \
  ({ \
  register struct ExecBase * const __SetTaskPri__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register BYTE __SetTaskPri__re __asm("d0"); \
  register struct Task * __SetTaskPri_task __asm("a1") = (_SetTaskPri_task); \
  register BYTE __SetTaskPri_priority __asm("d0") = (_SetTaskPri_priority); \
  __asm volatile ("jsr a6@(-300:W)" \
  : "=r"(__SetTaskPri__re) \
  : "r"(__SetTaskPri__bn), "r"(__SetTaskPri_task), "r"(__SetTaskPri_priority) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetTaskPri__re; \
  }); \
  _SetTaskPri__re; \
})

#define SetSignal(newSignals, signalSet) ({ \
  ULONG _SetSignal_newSignals = (newSignals); \
  ULONG _SetSignal_signalSet = (signalSet); \
  ULONG _SetSignal__re = \
  ({ \
  register struct ExecBase * const __SetSignal__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __SetSignal__re __asm("d0"); \
  register ULONG __SetSignal_newSignals __asm("d0") = (_SetSignal_newSignals); \
  register ULONG __SetSignal_signalSet __asm("d1") = (_SetSignal_signalSet); \
  __asm volatile ("jsr a6@(-306:W)" \
  : "=r"(__SetSignal__re) \
  : "r"(__SetSignal__bn), "r"(__SetSignal_newSignals), "r"(__SetSignal_signalSet) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetSignal__re; \
  }); \
  _SetSignal__re; \
})

#define SetExcept(newSignals, signalSet) ({ \
  ULONG _SetExcept_newSignals = (newSignals); \
  ULONG _SetExcept_signalSet = (signalSet); \
  ULONG _SetExcept__re = \
  ({ \
  register struct ExecBase * const __SetExcept__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __SetExcept__re __asm("d0"); \
  register ULONG __SetExcept_newSignals __asm("d0") = (_SetExcept_newSignals); \
  register ULONG __SetExcept_signalSet __asm("d1") = (_SetExcept_signalSet); \
  __asm volatile ("jsr a6@(-312:W)" \
  : "=r"(__SetExcept__re) \
  : "r"(__SetExcept__bn), "r"(__SetExcept_newSignals), "r"(__SetExcept_signalSet) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetExcept__re; \
  }); \
  _SetExcept__re; \
})

#define Wait(signalSet) ({ \
  ULONG _Wait_signalSet = (signalSet); \
  ULONG _Wait__re = \
  ({ \
  register struct ExecBase * const __Wait__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __Wait__re __asm("d0"); \
  register ULONG __Wait_signalSet __asm("d0") = (_Wait_signalSet); \
  __asm volatile ("jsr a6@(-318:W)" \
  : "=r"(__Wait__re) \
  : "r"(__Wait__bn), "r"(__Wait_signalSet) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Wait__re; \
  }); \
  _Wait__re; \
})

#define Signal(task, signalSet) ({ \
  struct Task * _Signal_task = (task); \
  ULONG _Signal_signalSet = (signalSet); \
  { \
  register struct ExecBase * const __Signal__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Task * __Signal_task __asm("a1") = (_Signal_task); \
  register ULONG __Signal_signalSet __asm("d0") = (_Signal_signalSet); \
  __asm volatile ("jsr a6@(-324:W)" \
  : \
  : "r"(__Signal__bn), "r"(__Signal_task), "r"(__Signal_signalSet) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocSignal(signalNum) ({ \
  LONG _AllocSignal_signalNum = (signalNum); \
  BYTE _AllocSignal__re = \
  ({ \
  register struct ExecBase * const __AllocSignal__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register BYTE __AllocSignal__re __asm("d0"); \
  register LONG __AllocSignal_signalNum __asm("d0") = (_AllocSignal_signalNum); \
  __asm volatile ("jsr a6@(-330:W)" \
  : "=r"(__AllocSignal__re) \
  : "r"(__AllocSignal__bn), "r"(__AllocSignal_signalNum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocSignal__re; \
  }); \
  _AllocSignal__re; \
})

#define FreeSignal(signalNum) ({ \
  LONG _FreeSignal_signalNum = (signalNum); \
  { \
  register struct ExecBase * const __FreeSignal__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register LONG __FreeSignal_signalNum __asm("d0") = (_FreeSignal_signalNum); \
  __asm volatile ("jsr a6@(-336:W)" \
  : \
  : "r"(__FreeSignal__bn), "r"(__FreeSignal_signalNum) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocTrap(trapNum) ({ \
  LONG _AllocTrap_trapNum = (trapNum); \
  LONG _AllocTrap__re = \
  ({ \
  register struct ExecBase * const __AllocTrap__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register LONG __AllocTrap__re __asm("d0"); \
  register LONG __AllocTrap_trapNum __asm("d0") = (_AllocTrap_trapNum); \
  __asm volatile ("jsr a6@(-342:W)" \
  : "=r"(__AllocTrap__re) \
  : "r"(__AllocTrap__bn), "r"(__AllocTrap_trapNum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocTrap__re; \
  }); \
  _AllocTrap__re; \
})

#define FreeTrap(trapNum) ({ \
  LONG _FreeTrap_trapNum = (trapNum); \
  { \
  register struct ExecBase * const __FreeTrap__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register LONG __FreeTrap_trapNum __asm("d0") = (_FreeTrap_trapNum); \
  __asm volatile ("jsr a6@(-348:W)" \
  : \
  : "r"(__FreeTrap__bn), "r"(__FreeTrap_trapNum) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddPort(port) ({ \
  struct MsgPort * _AddPort_port = (port); \
  { \
  register struct ExecBase * const __AddPort__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MsgPort * __AddPort_port __asm("a1") = (_AddPort_port); \
  __asm volatile ("jsr a6@(-354:W)" \
  : \
  : "r"(__AddPort__bn), "r"(__AddPort_port) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemPort(port) ({ \
  struct MsgPort * _RemPort_port = (port); \
  { \
  register struct ExecBase * const __RemPort__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MsgPort * __RemPort_port __asm("a1") = (_RemPort_port); \
  __asm volatile ("jsr a6@(-360:W)" \
  : \
  : "r"(__RemPort__bn), "r"(__RemPort_port) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define PutMsg(port, message) ({ \
  struct MsgPort * _PutMsg_port = (port); \
  struct Message * _PutMsg_message = (message); \
  { \
  register struct ExecBase * const __PutMsg__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MsgPort * __PutMsg_port __asm("a0") = (_PutMsg_port); \
  register struct Message * __PutMsg_message __asm("a1") = (_PutMsg_message); \
  __asm volatile ("jsr a6@(-366:W)" \
  : \
  : "r"(__PutMsg__bn), "r"(__PutMsg_port), "r"(__PutMsg_message) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetMsg(port) ({ \
  struct MsgPort * _GetMsg_port = (port); \
  struct Message * _GetMsg__re = \
  ({ \
  register struct ExecBase * const __GetMsg__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Message * __GetMsg__re __asm("d0"); \
  register struct MsgPort * __GetMsg_port __asm("a0") = (_GetMsg_port); \
  __asm volatile ("jsr a6@(-372:W)" \
  : "=r"(__GetMsg__re) \
  : "r"(__GetMsg__bn), "r"(__GetMsg_port) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetMsg__re; \
  }); \
  _GetMsg__re; \
})

#define ReplyMsg(message) ({ \
  struct Message * _ReplyMsg_message = (message); \
  { \
  register struct ExecBase * const __ReplyMsg__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Message * __ReplyMsg_message __asm("a1") = (_ReplyMsg_message); \
  __asm volatile ("jsr a6@(-378:W)" \
  : \
  : "r"(__ReplyMsg__bn), "r"(__ReplyMsg_message) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WaitPort(port) ({ \
  struct MsgPort * _WaitPort_port = (port); \
  struct Message * _WaitPort__re = \
  ({ \
  register struct ExecBase * const __WaitPort__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Message * __WaitPort__re __asm("d0"); \
  register struct MsgPort * __WaitPort_port __asm("a0") = (_WaitPort_port); \
  __asm volatile ("jsr a6@(-384:W)" \
  : "=r"(__WaitPort__re) \
  : "r"(__WaitPort__bn), "r"(__WaitPort_port) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WaitPort__re; \
  }); \
  _WaitPort__re; \
})

#define FindPort(name) ({ \
  CONST_STRPTR _FindPort_name = (name); \
  struct MsgPort * _FindPort__re = \
  ({ \
  register struct ExecBase * const __FindPort__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MsgPort * __FindPort__re __asm("d0"); \
  register CONST_STRPTR __FindPort_name __asm("a1") = (_FindPort_name); \
  __asm volatile ("jsr a6@(-390:W)" \
  : "=r"(__FindPort__re) \
  : "r"(__FindPort__bn), "r"(__FindPort_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindPort__re; \
  }); \
  _FindPort__re; \
})

#define AddLibrary(library) ({ \
  struct Library * _AddLibrary_library = (library); \
  { \
  register struct ExecBase * const __AddLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __AddLibrary_library __asm("a1") = (_AddLibrary_library); \
  __asm volatile ("jsr a6@(-396:W)" \
  : \
  : "r"(__AddLibrary__bn), "r"(__AddLibrary_library) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemLibrary(library) ({ \
  struct Library * _RemLibrary_library = (library); \
  { \
  register struct ExecBase * const __RemLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __RemLibrary_library __asm("a1") = (_RemLibrary_library); \
  __asm volatile ("jsr a6@(-402:W)" \
  : \
  : "r"(__RemLibrary__bn), "r"(__RemLibrary_library) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OldOpenLibrary(libName) ({ \
  CONST_STRPTR _OldOpenLibrary_libName = (libName); \
  struct Library * _OldOpenLibrary__re = \
  ({ \
  register struct ExecBase * const __OldOpenLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __OldOpenLibrary__re __asm("d0"); \
  register CONST_STRPTR __OldOpenLibrary_libName __asm("a1") = (_OldOpenLibrary_libName); \
  __asm volatile ("jsr a6@(-408:W)" \
  : "=r"(__OldOpenLibrary__re) \
  : "r"(__OldOpenLibrary__bn), "r"(__OldOpenLibrary_libName) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OldOpenLibrary__re; \
  }); \
  _OldOpenLibrary__re; \
})

#define CloseLibrary(library) ({ \
  struct Library * _CloseLibrary_library = (library); \
  { \
  register struct ExecBase * const __CloseLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __CloseLibrary_library __asm("a1") = (_CloseLibrary_library); \
  __asm volatile ("jsr a6@(-414:W)" \
  : \
  : "r"(__CloseLibrary__bn), "r"(__CloseLibrary_library) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetFunction(library, funcOffset, newFunction) ({ \
  struct Library * _SetFunction_library = (library); \
  LONG _SetFunction_funcOffset = (funcOffset); \
  ULONG (*_SetFunction_newFunction)() = (newFunction); \
  APTR _SetFunction__re = \
  ({ \
  register struct ExecBase * const __SetFunction__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __SetFunction__re __asm("d0"); \
  register struct Library * __SetFunction_library __asm("a1") = (_SetFunction_library); \
  register LONG __SetFunction_funcOffset __asm("a0") = (_SetFunction_funcOffset); \
  register ULONG (*__SetFunction_newFunction)() __asm("d0") = (_SetFunction_newFunction); \
  __asm volatile ("jsr a6@(-420:W)" \
  : "=r"(__SetFunction__re) \
  : "r"(__SetFunction__bn), "r"(__SetFunction_library), "r"(__SetFunction_funcOffset), "r"(__SetFunction_newFunction) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetFunction__re; \
  }); \
  _SetFunction__re; \
})

#define SumLibrary(library) ({ \
  struct Library * _SumLibrary_library = (library); \
  { \
  register struct ExecBase * const __SumLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __SumLibrary_library __asm("a1") = (_SumLibrary_library); \
  __asm volatile ("jsr a6@(-426:W)" \
  : \
  : "r"(__SumLibrary__bn), "r"(__SumLibrary_library) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddDevice(device) ({ \
  struct Device * _AddDevice_device = (device); \
  { \
  register struct ExecBase * const __AddDevice__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Device * __AddDevice_device __asm("a1") = (_AddDevice_device); \
  __asm volatile ("jsr a6@(-432:W)" \
  : \
  : "r"(__AddDevice__bn), "r"(__AddDevice_device) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemDevice(device) ({ \
  struct Device * _RemDevice_device = (device); \
  { \
  register struct ExecBase * const __RemDevice__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Device * __RemDevice_device __asm("a1") = (_RemDevice_device); \
  __asm volatile ("jsr a6@(-438:W)" \
  : \
  : "r"(__RemDevice__bn), "r"(__RemDevice_device) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenDevice(devName, unit, ioRequest, flags) ({ \
  CONST_STRPTR _OpenDevice_devName = (devName); \
  ULONG _OpenDevice_unit = (unit); \
  struct IORequest * _OpenDevice_ioRequest = (ioRequest); \
  ULONG _OpenDevice_flags = (flags); \
  BYTE _OpenDevice__re = \
  ({ \
  register struct ExecBase * const __OpenDevice__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register BYTE __OpenDevice__re __asm("d0"); \
  register CONST_STRPTR __OpenDevice_devName __asm("a0") = (_OpenDevice_devName); \
  register ULONG __OpenDevice_unit __asm("d0") = (_OpenDevice_unit); \
  register struct IORequest * __OpenDevice_ioRequest __asm("a1") = (_OpenDevice_ioRequest); \
  register ULONG __OpenDevice_flags __asm("d1") = (_OpenDevice_flags); \
  __asm volatile ("jsr a6@(-444:W)" \
  : "=r"(__OpenDevice__re) \
  : "r"(__OpenDevice__bn), "r"(__OpenDevice_devName), "r"(__OpenDevice_unit), "r"(__OpenDevice_ioRequest), "r"(__OpenDevice_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenDevice__re; \
  }); \
  _OpenDevice__re; \
})

#define CloseDevice(ioRequest) ({ \
  struct IORequest * _CloseDevice_ioRequest = (ioRequest); \
  { \
  register struct ExecBase * const __CloseDevice__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct IORequest * __CloseDevice_ioRequest __asm("a1") = (_CloseDevice_ioRequest); \
  __asm volatile ("jsr a6@(-450:W)" \
  : \
  : "r"(__CloseDevice__bn), "r"(__CloseDevice_ioRequest) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DoIO(ioRequest) ({ \
  struct IORequest * _DoIO_ioRequest = (ioRequest); \
  BYTE _DoIO__re = \
  ({ \
  register struct ExecBase * const __DoIO__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register BYTE __DoIO__re __asm("d0"); \
  register struct IORequest * __DoIO_ioRequest __asm("a1") = (_DoIO_ioRequest); \
  __asm volatile ("jsr a6@(-456:W)" \
  : "=r"(__DoIO__re) \
  : "r"(__DoIO__bn), "r"(__DoIO_ioRequest) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoIO__re; \
  }); \
  _DoIO__re; \
})

#define SendIO(ioRequest) ({ \
  struct IORequest * _SendIO_ioRequest = (ioRequest); \
  { \
  register struct ExecBase * const __SendIO__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct IORequest * __SendIO_ioRequest __asm("a1") = (_SendIO_ioRequest); \
  __asm volatile ("jsr a6@(-462:W)" \
  : \
  : "r"(__SendIO__bn), "r"(__SendIO_ioRequest) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CheckIO(ioRequest) ({ \
  struct IORequest * _CheckIO_ioRequest = (ioRequest); \
  struct IORequest * _CheckIO__re = \
  ({ \
  register struct ExecBase * const __CheckIO__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct IORequest * __CheckIO__re __asm("d0"); \
  register struct IORequest * __CheckIO_ioRequest __asm("a1") = (_CheckIO_ioRequest); \
  __asm volatile ("jsr a6@(-468:W)" \
  : "=r"(__CheckIO__re) \
  : "r"(__CheckIO__bn), "r"(__CheckIO_ioRequest) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CheckIO__re; \
  }); \
  _CheckIO__re; \
})

#define WaitIO(ioRequest) ({ \
  struct IORequest * _WaitIO_ioRequest = (ioRequest); \
  BYTE _WaitIO__re = \
  ({ \
  register struct ExecBase * const __WaitIO__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register BYTE __WaitIO__re __asm("d0"); \
  register struct IORequest * __WaitIO_ioRequest __asm("a1") = (_WaitIO_ioRequest); \
  __asm volatile ("jsr a6@(-474:W)" \
  : "=r"(__WaitIO__re) \
  : "r"(__WaitIO__bn), "r"(__WaitIO_ioRequest) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WaitIO__re; \
  }); \
  _WaitIO__re; \
})

#define AbortIO(ioRequest) ({ \
  struct IORequest * _AbortIO_ioRequest = (ioRequest); \
  { \
  register struct ExecBase * const __AbortIO__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct IORequest * __AbortIO_ioRequest __asm("a1") = (_AbortIO_ioRequest); \
  __asm volatile ("jsr a6@(-480:W)" \
  : \
  : "r"(__AbortIO__bn), "r"(__AbortIO_ioRequest) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddResource(resource) ({ \
  APTR _AddResource_resource = (resource); \
  { \
  register struct ExecBase * const __AddResource__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __AddResource_resource __asm("a1") = (_AddResource_resource); \
  __asm volatile ("jsr a6@(-486:W)" \
  : \
  : "r"(__AddResource__bn), "r"(__AddResource_resource) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemResource(resource) ({ \
  APTR _RemResource_resource = (resource); \
  { \
  register struct ExecBase * const __RemResource__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __RemResource_resource __asm("a1") = (_RemResource_resource); \
  __asm volatile ("jsr a6@(-492:W)" \
  : \
  : "r"(__RemResource__bn), "r"(__RemResource_resource) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenResource(resName) ({ \
  CONST_STRPTR _OpenResource_resName = (resName); \
  APTR _OpenResource__re = \
  ({ \
  register struct ExecBase * const __OpenResource__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __OpenResource__re __asm("d0"); \
  register CONST_STRPTR __OpenResource_resName __asm("a1") = (_OpenResource_resName); \
  __asm volatile ("jsr a6@(-498:W)" \
  : "=r"(__OpenResource__re) \
  : "r"(__OpenResource__bn), "r"(__OpenResource_resName) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenResource__re; \
  }); \
  _OpenResource__re; \
})

#define RawDoFmt(formatString, dataStream, putChProc, putChData) ({ \
  CONST_STRPTR _RawDoFmt_formatString = (formatString); \
  const APTR _RawDoFmt_dataStream = (dataStream); \
  VOID (*_RawDoFmt_putChProc)() = (putChProc); \
  APTR _RawDoFmt_putChData = (putChData); \
  APTR _RawDoFmt__re = \
  ({ \
  register struct ExecBase * const __RawDoFmt__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __RawDoFmt__re __asm("d0"); \
  register CONST_STRPTR __RawDoFmt_formatString __asm("a0") = (_RawDoFmt_formatString); \
  register const APTR __RawDoFmt_dataStream __asm("a1") = (_RawDoFmt_dataStream); \
  register VOID (*__RawDoFmt_putChProc)() __asm("a2") = (_RawDoFmt_putChProc); \
  register APTR __RawDoFmt_putChData __asm("a3") = (_RawDoFmt_putChData); \
  __asm volatile ("jsr a6@(-522:W)" \
  : "=r"(__RawDoFmt__re) \
  : "r"(__RawDoFmt__bn), "r"(__RawDoFmt_formatString), "r"(__RawDoFmt_dataStream), "r"(__RawDoFmt_putChProc), "r"(__RawDoFmt_putChData) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RawDoFmt__re; \
  }); \
  _RawDoFmt__re; \
})

#define GetCC() ({ \
  ULONG _GetCC__re = \
  ({ \
  register struct ExecBase * const __GetCC__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __GetCC__re __asm("d0"); \
  __asm volatile ("jsr a6@(-528:W)" \
  : "=r"(__GetCC__re) \
  : "r"(__GetCC__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCC__re; \
  }); \
  _GetCC__re; \
})

#define TypeOfMem(address) ({ \
  const APTR _TypeOfMem_address = (address); \
  ULONG _TypeOfMem__re = \
  ({ \
  register struct ExecBase * const __TypeOfMem__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __TypeOfMem__re __asm("d0"); \
  register const APTR __TypeOfMem_address __asm("a1") = (_TypeOfMem_address); \
  __asm volatile ("jsr a6@(-534:W)" \
  : "=r"(__TypeOfMem__re) \
  : "r"(__TypeOfMem__bn), "r"(__TypeOfMem_address) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __TypeOfMem__re; \
  }); \
  _TypeOfMem__re; \
})

#define Procure(sigSem, bidMsg) ({ \
  struct SignalSemaphore * _Procure_sigSem = (sigSem); \
  struct SemaphoreMessage * _Procure_bidMsg = (bidMsg); \
  ULONG _Procure__re = \
  ({ \
  register struct ExecBase * const __Procure__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __Procure__re __asm("d0"); \
  register struct SignalSemaphore * __Procure_sigSem __asm("a0") = (_Procure_sigSem); \
  register struct SemaphoreMessage * __Procure_bidMsg __asm("a1") = (_Procure_bidMsg); \
  __asm volatile ("jsr a6@(-540:W)" \
  : "=r"(__Procure__re) \
  : "r"(__Procure__bn), "r"(__Procure_sigSem), "r"(__Procure_bidMsg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Procure__re; \
  }); \
  _Procure__re; \
})

#define Vacate(sigSem, bidMsg) ({ \
  struct SignalSemaphore * _Vacate_sigSem = (sigSem); \
  struct SemaphoreMessage * _Vacate_bidMsg = (bidMsg); \
  { \
  register struct ExecBase * const __Vacate__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __Vacate_sigSem __asm("a0") = (_Vacate_sigSem); \
  register struct SemaphoreMessage * __Vacate_bidMsg __asm("a1") = (_Vacate_bidMsg); \
  __asm volatile ("jsr a6@(-546:W)" \
  : \
  : "r"(__Vacate__bn), "r"(__Vacate_sigSem), "r"(__Vacate_bidMsg) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenLibrary(libName, version) ({ \
  CONST_STRPTR _OpenLibrary_libName = (libName); \
  ULONG _OpenLibrary_version = (version); \
  struct Library * _OpenLibrary__re = \
  ({ \
  register struct ExecBase * const __OpenLibrary__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Library * __OpenLibrary__re __asm("d0"); \
  register CONST_STRPTR __OpenLibrary_libName __asm("a1") = (_OpenLibrary_libName); \
  register ULONG __OpenLibrary_version __asm("d0") = (_OpenLibrary_version); \
  __asm volatile ("jsr a6@(-552:W)" \
  : "=r"(__OpenLibrary__re) \
  : "r"(__OpenLibrary__bn), "r"(__OpenLibrary_libName), "r"(__OpenLibrary_version) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenLibrary__re; \
  }); \
  _OpenLibrary__re; \
})

#define InitSemaphore(sigSem) ({ \
  struct SignalSemaphore * _InitSemaphore_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __InitSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __InitSemaphore_sigSem __asm("a0") = (_InitSemaphore_sigSem); \
  __asm volatile ("jsr a6@(-558:W)" \
  : \
  : "r"(__InitSemaphore__bn), "r"(__InitSemaphore_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainSemaphore(sigSem) ({ \
  struct SignalSemaphore * _ObtainSemaphore_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __ObtainSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __ObtainSemaphore_sigSem __asm("a0") = (_ObtainSemaphore_sigSem); \
  __asm volatile ("jsr a6@(-564:W)" \
  : \
  : "r"(__ObtainSemaphore__bn), "r"(__ObtainSemaphore_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ReleaseSemaphore(sigSem) ({ \
  struct SignalSemaphore * _ReleaseSemaphore_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __ReleaseSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __ReleaseSemaphore_sigSem __asm("a0") = (_ReleaseSemaphore_sigSem); \
  __asm volatile ("jsr a6@(-570:W)" \
  : \
  : "r"(__ReleaseSemaphore__bn), "r"(__ReleaseSemaphore_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AttemptSemaphore(sigSem) ({ \
  struct SignalSemaphore * _AttemptSemaphore_sigSem = (sigSem); \
  ULONG _AttemptSemaphore__re = \
  ({ \
  register struct ExecBase * const __AttemptSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __AttemptSemaphore__re __asm("d0"); \
  register struct SignalSemaphore * __AttemptSemaphore_sigSem __asm("a0") = (_AttemptSemaphore_sigSem); \
  __asm volatile ("jsr a6@(-576:W)" \
  : "=r"(__AttemptSemaphore__re) \
  : "r"(__AttemptSemaphore__bn), "r"(__AttemptSemaphore_sigSem) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AttemptSemaphore__re; \
  }); \
  _AttemptSemaphore__re; \
})

#define ObtainSemaphoreList(sigSem) ({ \
  struct List * _ObtainSemaphoreList_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __ObtainSemaphoreList__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct List * __ObtainSemaphoreList_sigSem __asm("a0") = (_ObtainSemaphoreList_sigSem); \
  __asm volatile ("jsr a6@(-582:W)" \
  : \
  : "r"(__ObtainSemaphoreList__bn), "r"(__ObtainSemaphoreList_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ReleaseSemaphoreList(sigSem) ({ \
  struct List * _ReleaseSemaphoreList_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __ReleaseSemaphoreList__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct List * __ReleaseSemaphoreList_sigSem __asm("a0") = (_ReleaseSemaphoreList_sigSem); \
  __asm volatile ("jsr a6@(-588:W)" \
  : \
  : "r"(__ReleaseSemaphoreList__bn), "r"(__ReleaseSemaphoreList_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindSemaphore(name) ({ \
  STRPTR _FindSemaphore_name = (name); \
  struct SignalSemaphore * _FindSemaphore__re = \
  ({ \
  register struct ExecBase * const __FindSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __FindSemaphore__re __asm("d0"); \
  register STRPTR __FindSemaphore_name __asm("a1") = (_FindSemaphore_name); \
  __asm volatile ("jsr a6@(-594:W)" \
  : "=r"(__FindSemaphore__re) \
  : "r"(__FindSemaphore__bn), "r"(__FindSemaphore_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindSemaphore__re; \
  }); \
  _FindSemaphore__re; \
})

#define AddSemaphore(sigSem) ({ \
  struct SignalSemaphore * _AddSemaphore_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __AddSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __AddSemaphore_sigSem __asm("a1") = (_AddSemaphore_sigSem); \
  __asm volatile ("jsr a6@(-600:W)" \
  : \
  : "r"(__AddSemaphore__bn), "r"(__AddSemaphore_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemSemaphore(sigSem) ({ \
  struct SignalSemaphore * _RemSemaphore_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __RemSemaphore__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __RemSemaphore_sigSem __asm("a1") = (_RemSemaphore_sigSem); \
  __asm volatile ("jsr a6@(-606:W)" \
  : \
  : "r"(__RemSemaphore__bn), "r"(__RemSemaphore_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SumKickData() ({ \
  ULONG _SumKickData__re = \
  ({ \
  register struct ExecBase * const __SumKickData__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __SumKickData__re __asm("d0"); \
  __asm volatile ("jsr a6@(-612:W)" \
  : "=r"(__SumKickData__re) \
  : "r"(__SumKickData__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SumKickData__re; \
  }); \
  _SumKickData__re; \
})

#define AddMemList(size, attributes, pri, base, name) ({ \
  ULONG _AddMemList_size = (size); \
  ULONG _AddMemList_attributes = (attributes); \
  LONG _AddMemList_pri = (pri); \
  APTR _AddMemList_base = (base); \
  CONST_STRPTR _AddMemList_name = (name); \
  { \
  register struct ExecBase * const __AddMemList__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __AddMemList_size __asm("d0") = (_AddMemList_size); \
  register ULONG __AddMemList_attributes __asm("d1") = (_AddMemList_attributes); \
  register LONG __AddMemList_pri __asm("d2") = (_AddMemList_pri); \
  register APTR __AddMemList_base __asm("a0") = (_AddMemList_base); \
  register CONST_STRPTR __AddMemList_name __asm("a1") = (_AddMemList_name); \
  __asm volatile ("jsr a6@(-618:W)" \
  : \
  : "r"(__AddMemList__bn), "r"(__AddMemList_size), "r"(__AddMemList_attributes), "r"(__AddMemList_pri), "r"(__AddMemList_base), "r"(__AddMemList_name) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CopyMem(source, dest, size) ({ \
  const APTR _CopyMem_source = (source); \
  APTR _CopyMem_dest = (dest); \
  ULONG _CopyMem_size = (size); \
  { \
  register struct ExecBase * const __CopyMem__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register const APTR __CopyMem_source __asm("a0") = (_CopyMem_source); \
  register APTR __CopyMem_dest __asm("a1") = (_CopyMem_dest); \
  register ULONG __CopyMem_size __asm("d0") = (_CopyMem_size); \
  __asm volatile ("jsr a6@(-624:W)" \
  : \
  : "r"(__CopyMem__bn), "r"(__CopyMem_source), "r"(__CopyMem_dest), "r"(__CopyMem_size) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CopyMemQuick(source, dest, size) ({ \
  const APTR _CopyMemQuick_source = (source); \
  APTR _CopyMemQuick_dest = (dest); \
  ULONG _CopyMemQuick_size = (size); \
  { \
  register struct ExecBase * const __CopyMemQuick__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register const APTR __CopyMemQuick_source __asm("a0") = (_CopyMemQuick_source); \
  register APTR __CopyMemQuick_dest __asm("a1") = (_CopyMemQuick_dest); \
  register ULONG __CopyMemQuick_size __asm("d0") = (_CopyMemQuick_size); \
  __asm volatile ("jsr a6@(-630:W)" \
  : \
  : "r"(__CopyMemQuick__bn), "r"(__CopyMemQuick_source), "r"(__CopyMemQuick_dest), "r"(__CopyMemQuick_size) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CacheClearU() ({ \
  register struct ExecBase * const __CacheClearU__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  __asm volatile ("jsr a6@(-636:W)" \
  : \
  : "r"(__CacheClearU__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define CacheClearE(address, length, caches) ({ \
  APTR _CacheClearE_address = (address); \
  ULONG _CacheClearE_length = (length); \
  ULONG _CacheClearE_caches = (caches); \
  { \
  register struct ExecBase * const __CacheClearE__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __CacheClearE_address __asm("a0") = (_CacheClearE_address); \
  register ULONG __CacheClearE_length __asm("d0") = (_CacheClearE_length); \
  register ULONG __CacheClearE_caches __asm("d1") = (_CacheClearE_caches); \
  __asm volatile ("jsr a6@(-642:W)" \
  : \
  : "r"(__CacheClearE__bn), "r"(__CacheClearE_address), "r"(__CacheClearE_length), "r"(__CacheClearE_caches) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CacheControl(cacheBits, cacheMask) ({ \
  ULONG _CacheControl_cacheBits = (cacheBits); \
  ULONG _CacheControl_cacheMask = (cacheMask); \
  ULONG _CacheControl__re = \
  ({ \
  register struct ExecBase * const __CacheControl__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __CacheControl__re __asm("d0"); \
  register ULONG __CacheControl_cacheBits __asm("d0") = (_CacheControl_cacheBits); \
  register ULONG __CacheControl_cacheMask __asm("d1") = (_CacheControl_cacheMask); \
  __asm volatile ("jsr a6@(-648:W)" \
  : "=r"(__CacheControl__re) \
  : "r"(__CacheControl__bn), "r"(__CacheControl_cacheBits), "r"(__CacheControl_cacheMask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CacheControl__re; \
  }); \
  _CacheControl__re; \
})

#define CreateIORequest(port, size) ({ \
  const struct MsgPort * _CreateIORequest_port = (port); \
  ULONG _CreateIORequest_size = (size); \
  APTR _CreateIORequest__re = \
  ({ \
  register struct ExecBase * const __CreateIORequest__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __CreateIORequest__re __asm("d0"); \
  register const struct MsgPort * __CreateIORequest_port __asm("a0") = (_CreateIORequest_port); \
  register ULONG __CreateIORequest_size __asm("d0") = (_CreateIORequest_size); \
  __asm volatile ("jsr a6@(-654:W)" \
  : "=r"(__CreateIORequest__re) \
  : "r"(__CreateIORequest__bn), "r"(__CreateIORequest_port), "r"(__CreateIORequest_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateIORequest__re; \
  }); \
  _CreateIORequest__re; \
})

#define DeleteIORequest(iorequest) ({ \
  APTR _DeleteIORequest_iorequest = (iorequest); \
  { \
  register struct ExecBase * const __DeleteIORequest__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __DeleteIORequest_iorequest __asm("a0") = (_DeleteIORequest_iorequest); \
  __asm volatile ("jsr a6@(-660:W)" \
  : \
  : "r"(__DeleteIORequest__bn), "r"(__DeleteIORequest_iorequest) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CreateMsgPort() ({ \
  struct MsgPort * _CreateMsgPort__re = \
  ({ \
  register struct ExecBase * const __CreateMsgPort__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MsgPort * __CreateMsgPort__re __asm("d0"); \
  __asm volatile ("jsr a6@(-666:W)" \
  : "=r"(__CreateMsgPort__re) \
  : "r"(__CreateMsgPort__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateMsgPort__re; \
  }); \
  _CreateMsgPort__re; \
})

#define DeleteMsgPort(port) ({ \
  struct MsgPort * _DeleteMsgPort_port = (port); \
  { \
  register struct ExecBase * const __DeleteMsgPort__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MsgPort * __DeleteMsgPort_port __asm("a0") = (_DeleteMsgPort_port); \
  __asm volatile ("jsr a6@(-672:W)" \
  : \
  : "r"(__DeleteMsgPort__bn), "r"(__DeleteMsgPort_port) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainSemaphoreShared(sigSem) ({ \
  struct SignalSemaphore * _ObtainSemaphoreShared_sigSem = (sigSem); \
  { \
  register struct ExecBase * const __ObtainSemaphoreShared__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct SignalSemaphore * __ObtainSemaphoreShared_sigSem __asm("a0") = (_ObtainSemaphoreShared_sigSem); \
  __asm volatile ("jsr a6@(-678:W)" \
  : \
  : "r"(__ObtainSemaphoreShared__bn), "r"(__ObtainSemaphoreShared_sigSem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocVec(byteSize, requirements) ({ \
  ULONG _AllocVec_byteSize = (byteSize); \
  ULONG _AllocVec_requirements = (requirements); \
  APTR _AllocVec__re = \
  ({ \
  register struct ExecBase * const __AllocVec__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __AllocVec__re __asm("d0"); \
  register ULONG __AllocVec_byteSize __asm("d0") = (_AllocVec_byteSize); \
  register ULONG __AllocVec_requirements __asm("d1") = (_AllocVec_requirements); \
  __asm volatile ("jsr a6@(-684:W)" \
  : "=r"(__AllocVec__re) \
  : "r"(__AllocVec__bn), "r"(__AllocVec_byteSize), "r"(__AllocVec_requirements) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocVec__re; \
  }); \
  _AllocVec__re; \
})

#define FreeVec(memoryBlock) ({ \
  APTR _FreeVec_memoryBlock = (memoryBlock); \
  { \
  register struct ExecBase * const __FreeVec__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __FreeVec_memoryBlock __asm("a1") = (_FreeVec_memoryBlock); \
  __asm volatile ("jsr a6@(-690:W)" \
  : \
  : "r"(__FreeVec__bn), "r"(__FreeVec_memoryBlock) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CreatePool(requirements, puddleSize, threshSize) ({ \
  ULONG _CreatePool_requirements = (requirements); \
  ULONG _CreatePool_puddleSize = (puddleSize); \
  ULONG _CreatePool_threshSize = (threshSize); \
  APTR _CreatePool__re = \
  ({ \
  register struct ExecBase * const __CreatePool__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __CreatePool__re __asm("d0"); \
  register ULONG __CreatePool_requirements __asm("d0") = (_CreatePool_requirements); \
  register ULONG __CreatePool_puddleSize __asm("d1") = (_CreatePool_puddleSize); \
  register ULONG __CreatePool_threshSize __asm("d2") = (_CreatePool_threshSize); \
  __asm volatile ("jsr a6@(-696:W)" \
  : "=r"(__CreatePool__re) \
  : "r"(__CreatePool__bn), "r"(__CreatePool_requirements), "r"(__CreatePool_puddleSize), "r"(__CreatePool_threshSize) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreatePool__re; \
  }); \
  _CreatePool__re; \
})

#define DeletePool(poolHeader) ({ \
  APTR _DeletePool_poolHeader = (poolHeader); \
  { \
  register struct ExecBase * const __DeletePool__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __DeletePool_poolHeader __asm("a0") = (_DeletePool_poolHeader); \
  __asm volatile ("jsr a6@(-702:W)" \
  : \
  : "r"(__DeletePool__bn), "r"(__DeletePool_poolHeader) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocPooled(poolHeader, memSize) ({ \
  APTR _AllocPooled_poolHeader = (poolHeader); \
  ULONG _AllocPooled_memSize = (memSize); \
  APTR _AllocPooled__re = \
  ({ \
  register struct ExecBase * const __AllocPooled__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __AllocPooled__re __asm("d0"); \
  register APTR __AllocPooled_poolHeader __asm("a0") = (_AllocPooled_poolHeader); \
  register ULONG __AllocPooled_memSize __asm("d0") = (_AllocPooled_memSize); \
  __asm volatile ("jsr a6@(-708:W)" \
  : "=r"(__AllocPooled__re) \
  : "r"(__AllocPooled__bn), "r"(__AllocPooled_poolHeader), "r"(__AllocPooled_memSize) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocPooled__re; \
  }); \
  _AllocPooled__re; \
})

#define FreePooled(poolHeader, memory, memSize) ({ \
  APTR _FreePooled_poolHeader = (poolHeader); \
  APTR _FreePooled_memory = (memory); \
  ULONG _FreePooled_memSize = (memSize); \
  { \
  register struct ExecBase * const __FreePooled__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __FreePooled_poolHeader __asm("a0") = (_FreePooled_poolHeader); \
  register APTR __FreePooled_memory __asm("a1") = (_FreePooled_memory); \
  register ULONG __FreePooled_memSize __asm("d0") = (_FreePooled_memSize); \
  __asm volatile ("jsr a6@(-714:W)" \
  : \
  : "r"(__FreePooled__bn), "r"(__FreePooled_poolHeader), "r"(__FreePooled_memory), "r"(__FreePooled_memSize) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AttemptSemaphoreShared(sigSem) ({ \
  struct SignalSemaphore * _AttemptSemaphoreShared_sigSem = (sigSem); \
  ULONG _AttemptSemaphoreShared__re = \
  ({ \
  register struct ExecBase * const __AttemptSemaphoreShared__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __AttemptSemaphoreShared__re __asm("d0"); \
  register struct SignalSemaphore * __AttemptSemaphoreShared_sigSem __asm("a0") = (_AttemptSemaphoreShared_sigSem); \
  __asm volatile ("jsr a6@(-720:W)" \
  : "=r"(__AttemptSemaphoreShared__re) \
  : "r"(__AttemptSemaphoreShared__bn), "r"(__AttemptSemaphoreShared_sigSem) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AttemptSemaphoreShared__re; \
  }); \
  _AttemptSemaphoreShared__re; \
})

#define ColdReboot() ({ \
  register struct ExecBase * const __ColdReboot__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  __asm volatile ("jsr a6@(-726:W)" \
  : \
  : "r"(__ColdReboot__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define StackSwap(newStack) ({ \
  struct StackSwapStruct * _StackSwap_newStack = (newStack); \
  { \
  register struct ExecBase * const __StackSwap__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct StackSwapStruct * __StackSwap_newStack __asm("a0") = (_StackSwap_newStack); \
  __asm volatile ("jsr a6@(-732:W)" \
  : \
  : "r"(__StackSwap__bn), "r"(__StackSwap_newStack) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CachePreDMA(address, length, flags) ({ \
  const APTR _CachePreDMA_address = (address); \
  ULONG * _CachePreDMA_length = (length); \
  ULONG _CachePreDMA_flags = (flags); \
  APTR _CachePreDMA__re = \
  ({ \
  register struct ExecBase * const __CachePreDMA__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register APTR __CachePreDMA__re __asm("d0"); \
  register const APTR __CachePreDMA_address __asm("a0") = (_CachePreDMA_address); \
  register ULONG * __CachePreDMA_length __asm("a1") = (_CachePreDMA_length); \
  register ULONG __CachePreDMA_flags __asm("d0") = (_CachePreDMA_flags); \
  __asm volatile ("jsr a6@(-762:W)" \
  : "=r"(__CachePreDMA__re) \
  : "r"(__CachePreDMA__bn), "r"(__CachePreDMA_address), "r"(__CachePreDMA_length), "r"(__CachePreDMA_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CachePreDMA__re; \
  }); \
  _CachePreDMA__re; \
})

#define CachePostDMA(address, length, flags) ({ \
  const APTR _CachePostDMA_address = (address); \
  ULONG * _CachePostDMA_length = (length); \
  ULONG _CachePostDMA_flags = (flags); \
  { \
  register struct ExecBase * const __CachePostDMA__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register const APTR __CachePostDMA_address __asm("a0") = (_CachePostDMA_address); \
  register ULONG * __CachePostDMA_length __asm("a1") = (_CachePostDMA_length); \
  register ULONG __CachePostDMA_flags __asm("d0") = (_CachePostDMA_flags); \
  __asm volatile ("jsr a6@(-768:W)" \
  : \
  : "r"(__CachePostDMA__bn), "r"(__CachePostDMA_address), "r"(__CachePostDMA_length), "r"(__CachePostDMA_flags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddMemHandler(memhand) ({ \
  struct Interrupt * _AddMemHandler_memhand = (memhand); \
  { \
  register struct ExecBase * const __AddMemHandler__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Interrupt * __AddMemHandler_memhand __asm("a1") = (_AddMemHandler_memhand); \
  __asm volatile ("jsr a6@(-774:W)" \
  : \
  : "r"(__AddMemHandler__bn), "r"(__AddMemHandler_memhand) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemMemHandler(memhand) ({ \
  struct Interrupt * _RemMemHandler_memhand = (memhand); \
  { \
  register struct ExecBase * const __RemMemHandler__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct Interrupt * __RemMemHandler_memhand __asm("a1") = (_RemMemHandler_memhand); \
  __asm volatile ("jsr a6@(-780:W)" \
  : \
  : "r"(__RemMemHandler__bn), "r"(__RemMemHandler_memhand) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainQuickVector(interruptCode) ({ \
  APTR _ObtainQuickVector_interruptCode = (interruptCode); \
  ULONG _ObtainQuickVector__re = \
  ({ \
  register struct ExecBase * const __ObtainQuickVector__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register ULONG __ObtainQuickVector__re __asm("d0"); \
  register APTR __ObtainQuickVector_interruptCode __asm("a0") = (_ObtainQuickVector_interruptCode); \
  __asm volatile ("jsr a6@(-786:W)" \
  : "=r"(__ObtainQuickVector__re) \
  : "r"(__ObtainQuickVector__bn), "r"(__ObtainQuickVector_interruptCode) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainQuickVector__re; \
  }); \
  _ObtainQuickVector__re; \
})

#define NewMinList(minlist) ({ \
  struct MinList * _NewMinList_minlist = (minlist); \
  { \
  register struct ExecBase * const __NewMinList__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct MinList * __NewMinList_minlist __asm("a0") = (_NewMinList_minlist); \
  __asm volatile ("jsr a6@(-828:W)" \
  : \
  : "r"(__NewMinList__bn), "r"(__NewMinList_minlist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AVL_AddNode(root, node, func) ({ \
  struct AVLNode ** _AVL_AddNode_root = (root); \
  struct AVLNode * _AVL_AddNode_node = (node); \
  APTR _AVL_AddNode_func = (func); \
  struct AVLNode * _AVL_AddNode__re = \
  ({ \
  register struct ExecBase * const __AVL_AddNode__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_AddNode__re __asm("d0"); \
  register struct AVLNode ** __AVL_AddNode_root __asm("a0") = (_AVL_AddNode_root); \
  register struct AVLNode * __AVL_AddNode_node __asm("a1") = (_AVL_AddNode_node); \
  register APTR __AVL_AddNode_func __asm("a2") = (_AVL_AddNode_func); \
  __asm volatile ("jsr a6@(-852:W)" \
  : "=r"(__AVL_AddNode__re) \
  : "r"(__AVL_AddNode__bn), "r"(__AVL_AddNode_root), "r"(__AVL_AddNode_node), "r"(__AVL_AddNode_func) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_AddNode__re; \
  }); \
  _AVL_AddNode__re; \
})

#define AVL_RemNodeByAddress(root, node) ({ \
  struct AVLNode ** _AVL_RemNodeByAddress_root = (root); \
  struct AVLNode * _AVL_RemNodeByAddress_node = (node); \
  struct AVLNode * _AVL_RemNodeByAddress__re = \
  ({ \
  register struct ExecBase * const __AVL_RemNodeByAddress__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_RemNodeByAddress__re __asm("d0"); \
  register struct AVLNode ** __AVL_RemNodeByAddress_root __asm("a0") = (_AVL_RemNodeByAddress_root); \
  register struct AVLNode * __AVL_RemNodeByAddress_node __asm("a1") = (_AVL_RemNodeByAddress_node); \
  __asm volatile ("jsr a6@(-858:W)" \
  : "=r"(__AVL_RemNodeByAddress__re) \
  : "r"(__AVL_RemNodeByAddress__bn), "r"(__AVL_RemNodeByAddress_root), "r"(__AVL_RemNodeByAddress_node) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_RemNodeByAddress__re; \
  }); \
  _AVL_RemNodeByAddress__re; \
})

#define AVL_RemNodeByKey(root, key, func) ({ \
  struct AVLNode ** _AVL_RemNodeByKey_root = (root); \
  APTR _AVL_RemNodeByKey_key = (key); \
  APTR _AVL_RemNodeByKey_func = (func); \
  struct AVLNode * _AVL_RemNodeByKey__re = \
  ({ \
  register struct ExecBase * const __AVL_RemNodeByKey__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_RemNodeByKey__re __asm("d0"); \
  register struct AVLNode ** __AVL_RemNodeByKey_root __asm("a0") = (_AVL_RemNodeByKey_root); \
  register APTR __AVL_RemNodeByKey_key __asm("a1") = (_AVL_RemNodeByKey_key); \
  register APTR __AVL_RemNodeByKey_func __asm("a2") = (_AVL_RemNodeByKey_func); \
  __asm volatile ("jsr a6@(-864:W)" \
  : "=r"(__AVL_RemNodeByKey__re) \
  : "r"(__AVL_RemNodeByKey__bn), "r"(__AVL_RemNodeByKey_root), "r"(__AVL_RemNodeByKey_key), "r"(__AVL_RemNodeByKey_func) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_RemNodeByKey__re; \
  }); \
  _AVL_RemNodeByKey__re; \
})

#define AVL_FindNode(root, key, func) ({ \
  CONST struct AVLNode * _AVL_FindNode_root = (root); \
  APTR _AVL_FindNode_key = (key); \
  APTR _AVL_FindNode_func = (func); \
  struct AVLNode * _AVL_FindNode__re = \
  ({ \
  register struct ExecBase * const __AVL_FindNode__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindNode__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindNode_root __asm("a0") = (_AVL_FindNode_root); \
  register APTR __AVL_FindNode_key __asm("a1") = (_AVL_FindNode_key); \
  register APTR __AVL_FindNode_func __asm("a2") = (_AVL_FindNode_func); \
  __asm volatile ("jsr a6@(-870:W)" \
  : "=r"(__AVL_FindNode__re) \
  : "r"(__AVL_FindNode__bn), "r"(__AVL_FindNode_root), "r"(__AVL_FindNode_key), "r"(__AVL_FindNode_func) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindNode__re; \
  }); \
  _AVL_FindNode__re; \
})

#define AVL_FindPrevNodeByAddress(node) ({ \
  CONST struct AVLNode * _AVL_FindPrevNodeByAddress_node = (node); \
  struct AVLNode * _AVL_FindPrevNodeByAddress__re = \
  ({ \
  register struct ExecBase * const __AVL_FindPrevNodeByAddress__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindPrevNodeByAddress__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindPrevNodeByAddress_node __asm("a0") = (_AVL_FindPrevNodeByAddress_node); \
  __asm volatile ("jsr a6@(-876:W)" \
  : "=r"(__AVL_FindPrevNodeByAddress__re) \
  : "r"(__AVL_FindPrevNodeByAddress__bn), "r"(__AVL_FindPrevNodeByAddress_node) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindPrevNodeByAddress__re; \
  }); \
  _AVL_FindPrevNodeByAddress__re; \
})

#define AVL_FindPrevNodeByKey(root, key, func) ({ \
  CONST struct AVLNode * _AVL_FindPrevNodeByKey_root = (root); \
  APTR _AVL_FindPrevNodeByKey_key = (key); \
  APTR _AVL_FindPrevNodeByKey_func = (func); \
  struct AVLNode * _AVL_FindPrevNodeByKey__re = \
  ({ \
  register struct ExecBase * const __AVL_FindPrevNodeByKey__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindPrevNodeByKey__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindPrevNodeByKey_root __asm("a0") = (_AVL_FindPrevNodeByKey_root); \
  register APTR __AVL_FindPrevNodeByKey_key __asm("a1") = (_AVL_FindPrevNodeByKey_key); \
  register APTR __AVL_FindPrevNodeByKey_func __asm("a2") = (_AVL_FindPrevNodeByKey_func); \
  __asm volatile ("jsr a6@(-882:W)" \
  : "=r"(__AVL_FindPrevNodeByKey__re) \
  : "r"(__AVL_FindPrevNodeByKey__bn), "r"(__AVL_FindPrevNodeByKey_root), "r"(__AVL_FindPrevNodeByKey_key), "r"(__AVL_FindPrevNodeByKey_func) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindPrevNodeByKey__re; \
  }); \
  _AVL_FindPrevNodeByKey__re; \
})

#define AVL_FindNextNodeByAddress(node) ({ \
  CONST struct AVLNode * _AVL_FindNextNodeByAddress_node = (node); \
  struct AVLNode * _AVL_FindNextNodeByAddress__re = \
  ({ \
  register struct ExecBase * const __AVL_FindNextNodeByAddress__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindNextNodeByAddress__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindNextNodeByAddress_node __asm("a0") = (_AVL_FindNextNodeByAddress_node); \
  __asm volatile ("jsr a6@(-888:W)" \
  : "=r"(__AVL_FindNextNodeByAddress__re) \
  : "r"(__AVL_FindNextNodeByAddress__bn), "r"(__AVL_FindNextNodeByAddress_node) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindNextNodeByAddress__re; \
  }); \
  _AVL_FindNextNodeByAddress__re; \
})

#define AVL_FindNextNodeByKey(root, key, func) ({ \
  CONST struct AVLNode * _AVL_FindNextNodeByKey_root = (root); \
  APTR _AVL_FindNextNodeByKey_key = (key); \
  APTR _AVL_FindNextNodeByKey_func = (func); \
  struct AVLNode * _AVL_FindNextNodeByKey__re = \
  ({ \
  register struct ExecBase * const __AVL_FindNextNodeByKey__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindNextNodeByKey__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindNextNodeByKey_root __asm("a0") = (_AVL_FindNextNodeByKey_root); \
  register APTR __AVL_FindNextNodeByKey_key __asm("a1") = (_AVL_FindNextNodeByKey_key); \
  register APTR __AVL_FindNextNodeByKey_func __asm("a2") = (_AVL_FindNextNodeByKey_func); \
  __asm volatile ("jsr a6@(-894:W)" \
  : "=r"(__AVL_FindNextNodeByKey__re) \
  : "r"(__AVL_FindNextNodeByKey__bn), "r"(__AVL_FindNextNodeByKey_root), "r"(__AVL_FindNextNodeByKey_key), "r"(__AVL_FindNextNodeByKey_func) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindNextNodeByKey__re; \
  }); \
  _AVL_FindNextNodeByKey__re; \
})

#define AVL_FindFirstNode(root) ({ \
  CONST struct AVLNode * _AVL_FindFirstNode_root = (root); \
  struct AVLNode * _AVL_FindFirstNode__re = \
  ({ \
  register struct ExecBase * const __AVL_FindFirstNode__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindFirstNode__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindFirstNode_root __asm("a0") = (_AVL_FindFirstNode_root); \
  __asm volatile ("jsr a6@(-900:W)" \
  : "=r"(__AVL_FindFirstNode__re) \
  : "r"(__AVL_FindFirstNode__bn), "r"(__AVL_FindFirstNode_root) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindFirstNode__re; \
  }); \
  _AVL_FindFirstNode__re; \
})

#define AVL_FindLastNode(root) ({ \
  CONST struct AVLNode * _AVL_FindLastNode_root = (root); \
  struct AVLNode * _AVL_FindLastNode__re = \
  ({ \
  register struct ExecBase * const __AVL_FindLastNode__bn __asm("a6") = (struct ExecBase *) (EXEC_BASE_NAME);\
  register struct AVLNode * __AVL_FindLastNode__re __asm("d0"); \
  register CONST struct AVLNode * __AVL_FindLastNode_root __asm("a0") = (_AVL_FindLastNode_root); \
  __asm volatile ("jsr a6@(-906:W)" \
  : "=r"(__AVL_FindLastNode__re) \
  : "r"(__AVL_FindLastNode__bn), "r"(__AVL_FindLastNode_root) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AVL_FindLastNode__re; \
  }); \
  _AVL_FindLastNode__re; \
})

#endif /*  _INLINE_EXEC_H  */
