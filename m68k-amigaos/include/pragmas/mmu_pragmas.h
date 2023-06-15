#ifndef _INCLUDE_PRAGMA_MMU_LIB_H
#define _INCLUDE_PRAGMA_MMU_LIB_H

#ifndef CLIB_MMU_PROTOS_H
#include <clib/mmu_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(MMUBase,0x01e,AllocAligned(d0,d1,a0))
#pragma amicall(MMUBase,0x024,GetMapping(a0))
#pragma amicall(MMUBase,0x02a,ReleaseMapping(a0,a1))
#pragma amicall(MMUBase,0x030,GetPageSize(a0))
#pragma amicall(MMUBase,0x036,GetMMUType())
#pragma amicall(MMUBase,0x048,LockMMUContext(a0))
#pragma amicall(MMUBase,0x04e,UnlockMMUContext(a0))
#pragma amicall(MMUBase,0x054,SetPropertiesA(a0,d1,d2,a1,d0,a2))
#pragma amicall(MMUBase,0x05a,GetPropertiesA(a0,a1,a2))
#pragma amicall(MMUBase,0x060,RebuildTree(a0))
#pragma amicall(MMUBase,0x066,SetPagePropertiesA(a0,d1,d2,a1,a2))
#pragma amicall(MMUBase,0x06c,GetPagePropertiesA(a0,a1,a2))
#pragma amicall(MMUBase,0x072,CreateMMUContextA(a0))
#pragma amicall(MMUBase,0x078,DeleteMMUContext(a0))
#pragma amicall(MMUBase,0x084,AllocLineVec(d0,d1))
#pragma amicall(MMUBase,0x08a,PhysicalPageLocation(a0,a1))
#pragma amicall(MMUBase,0x090,SuperContext(a0))
#pragma amicall(MMUBase,0x096,DefaultContext())
#pragma amicall(MMUBase,0x09c,EnterMMUContext(a0,a1))
#pragma amicall(MMUBase,0x0a2,LeaveMMUContext(a1))
#pragma amicall(MMUBase,0x0a8,AddContextHookA(a0))
#pragma amicall(MMUBase,0x0ae,RemContextHook(a1))
#pragma amicall(MMUBase,0x0b4,AddMessageHookA(a0))
#pragma amicall(MMUBase,0x0ba,RemMessageHook(a1))
#pragma amicall(MMUBase,0x0c0,ActivateException(a1))
#pragma amicall(MMUBase,0x0c6,DeactivateException(a1))
#pragma amicall(MMUBase,0x0cc,AttemptLockMMUContext(a0))
#pragma amicall(MMUBase,0x0d2,LockContextList())
#pragma amicall(MMUBase,0x0d8,UnlockContextList())
#pragma amicall(MMUBase,0x0de,AttemptLockContextList())
#pragma amicall(MMUBase,0x0e4,SetPropertyList(a0,a1))
#pragma amicall(MMUBase,0x0ea,TouchPropertyList(a1))
#pragma amicall(MMUBase,0x0f0,CurrentContext(a1))
#pragma amicall(MMUBase,0x0f6,DMAInitiate(d1,a0,a1,d0))
#pragma amicall(MMUBase,0x0fc,DMATerminate(d1))
#pragma amicall(MMUBase,0x102,PhysicalLocation(d1,a0,a1))
#pragma amicall(MMUBase,0x108,RemapSize(a0))
#pragma amicall(MMUBase,0x10e,WithoutMMU(a5))
#pragma amicall(MMUBase,0x114,SetBusError(a0,a1))
#pragma amicall(MMUBase,0x11a,GetMMUContextData(a0,d0))
#pragma amicall(MMUBase,0x120,SetMMUContextDataA(a0,a1))
#pragma amicall(MMUBase,0x126,NewMapping())
#pragma amicall(MMUBase,0x12c,CopyMapping(a0,a1,d0,d1,d2))
#pragma amicall(MMUBase,0x132,DupMapping(a0))
#pragma amicall(MMUBase,0x138,CopyContextRegion(a0,a1,d0,d1,d2))
#pragma amicall(MMUBase,0x13e,SetPropertiesMapping(a0,a1,d0,d1,d2))
#pragma amicall(MMUBase,0x144,SetMappingPropertiesA(a0,d1,d2,a1,d0,a2))
#pragma amicall(MMUBase,0x14a,GetMappingPropertiesA(a0,a1,a2))
#pragma amicall(MMUBase,0x150,BuildIndirect(a0,d0,d1))
#pragma amicall(MMUBase,0x156,SetIndirect(a0,a1,d0))
#pragma amicall(MMUBase,0x15c,GetIndirect(a0,a1,d0))
#pragma amicall(MMUBase,0x168,RebuildTreesA(a0))
#pragma amicall(MMUBase,0x16e,RunOldConfig(a5))
#pragma amicall(MMUBase,0x174,SetIndirectArray(a0,a1,d0))
#pragma amicall(MMUBase,0x17a,GetPageUsedModified(a0,a1))
#pragma amicall(MMUBase,0x1a4,MapWindow(a0,a1,d1))
#pragma amicall(MMUBase,0x1aa,CreateContextWindowA(a0,a1))
#pragma amicall(MMUBase,0x1b0,ReleaseContextWindow(a1))
#pragma amicall(MMUBase,0x1b6,RefreshContextWindow(a0))
#pragma amicall(MMUBase,0x1bc,MapWindowCached(a0,a1,d1))
#pragma amicall(MMUBase,0x1c2,LayoutContextWindow(a0))
#pragma amicall(MMUBase,0x1ce,LogicalLocation(d1,a0,a1))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall MMUBase AllocAligned           01e 81003
#pragma  libcall MMUBase GetMapping             024 801
#pragma  libcall MMUBase ReleaseMapping         02a 9802
#pragma  libcall MMUBase GetPageSize            030 801
#pragma  libcall MMUBase GetMMUType             036 00
#pragma  libcall MMUBase LockMMUContext         048 801
#pragma  libcall MMUBase UnlockMMUContext       04e 801
#pragma  libcall MMUBase SetPropertiesA         054 a0921806
#pragma  libcall MMUBase GetPropertiesA         05a a9803
#pragma  libcall MMUBase RebuildTree            060 801
#pragma  libcall MMUBase SetPagePropertiesA     066 a921805
#pragma  libcall MMUBase GetPagePropertiesA     06c a9803
#pragma  libcall MMUBase CreateMMUContextA      072 801
#pragma  libcall MMUBase DeleteMMUContext       078 801
#pragma  libcall MMUBase AllocLineVec           084 1002
#pragma  libcall MMUBase PhysicalPageLocation   08a 9802
#pragma  libcall MMUBase SuperContext           090 801
#pragma  libcall MMUBase DefaultContext         096 00
#pragma  libcall MMUBase EnterMMUContext        09c 9802
#pragma  libcall MMUBase LeaveMMUContext        0a2 901
#pragma  libcall MMUBase AddContextHookA        0a8 801
#pragma  libcall MMUBase RemContextHook         0ae 901
#pragma  libcall MMUBase AddMessageHookA        0b4 801
#pragma  libcall MMUBase RemMessageHook         0ba 901
#pragma  libcall MMUBase ActivateException      0c0 901
#pragma  libcall MMUBase DeactivateException    0c6 901
#pragma  libcall MMUBase AttemptLockMMUContext  0cc 801
#pragma  libcall MMUBase LockContextList        0d2 00
#pragma  libcall MMUBase UnlockContextList      0d8 00
#pragma  libcall MMUBase AttemptLockContextList 0de 00
#pragma  libcall MMUBase SetPropertyList        0e4 9802
#pragma  libcall MMUBase TouchPropertyList      0ea 901
#pragma  libcall MMUBase CurrentContext         0f0 901
#pragma  libcall MMUBase DMAInitiate            0f6 098104
#pragma  libcall MMUBase DMATerminate           0fc 101
#pragma  libcall MMUBase PhysicalLocation       102 98103
#pragma  libcall MMUBase RemapSize              108 801
#pragma  libcall MMUBase WithoutMMU             10e d01
#pragma  libcall MMUBase SetBusError            114 9802
#pragma  libcall MMUBase GetMMUContextData      11a 0802
#pragma  libcall MMUBase SetMMUContextDataA     120 9802
#pragma  libcall MMUBase NewMapping             126 00
#pragma  libcall MMUBase CopyMapping            12c 2109805
#pragma  libcall MMUBase DupMapping             132 801
#pragma  libcall MMUBase CopyContextRegion      138 2109805
#pragma  libcall MMUBase SetPropertiesMapping   13e 2109805
#pragma  libcall MMUBase SetMappingPropertiesA  144 a0921806
#pragma  libcall MMUBase GetMappingPropertiesA  14a a9803
#pragma  libcall MMUBase BuildIndirect          150 10803
#pragma  libcall MMUBase SetIndirect            156 09803
#pragma  libcall MMUBase GetIndirect            15c 09803
#pragma  libcall MMUBase RebuildTreesA          168 801
#pragma  libcall MMUBase RunOldConfig           16e d01
#pragma  libcall MMUBase SetIndirectArray       174 09803
#pragma  libcall MMUBase GetPageUsedModified    17a 9802
#pragma  libcall MMUBase MapWindow              1a4 19803
#pragma  libcall MMUBase CreateContextWindowA   1aa 9802
#pragma  libcall MMUBase ReleaseContextWindow   1b0 901
#pragma  libcall MMUBase RefreshContextWindow   1b6 801
#pragma  libcall MMUBase MapWindowCached        1bc 19803
#pragma  libcall MMUBase LayoutContextWindow    1c2 801
#pragma  libcall MMUBase LogicalLocation        1ce 98103
#endif
#ifdef __STORM__
#pragma tagcall(MMUBase,0x054,SetProperties(a0,d1,d2,a1,d0,a2))
#pragma tagcall(MMUBase,0x05a,GetProperties(a0,a1,a2))
#pragma tagcall(MMUBase,0x066,SetPageProperties(a0,d1,d2,a1,a2))
#pragma tagcall(MMUBase,0x06c,GetPageProperties(a0,a1,a2))
#pragma tagcall(MMUBase,0x072,CreateMMUContext(a0))
#pragma tagcall(MMUBase,0x0a8,AddContextHook(a0))
#pragma tagcall(MMUBase,0x0b4,AddMessageHook(a0))
#pragma tagcall(MMUBase,0x120,SetMMUContextData(a0,a1))
#pragma tagcall(MMUBase,0x144,SetMappingProperties(a0,d1,d2,a1,d0,a2))
#pragma tagcall(MMUBase,0x14a,GetMappingProperties(a0,a1,a2))
#pragma tagcall(MMUBase,0x168,RebuildTrees(a0))
#pragma tagcall(MMUBase,0x1aa,CreateContextWindow(a0,a1))
#endif
#ifdef __SASC_60
#pragma  tagcall MMUBase SetProperties          054 a0921806
#pragma  tagcall MMUBase GetProperties          05a a9803
#pragma  tagcall MMUBase SetPageProperties      066 a921805
#pragma  tagcall MMUBase GetPageProperties      06c a9803
#pragma  tagcall MMUBase CreateMMUContext       072 801
#pragma  tagcall MMUBase AddContextHook         0a8 801
#pragma  tagcall MMUBase AddMessageHook         0b4 801
#pragma  tagcall MMUBase SetMMUContextData      120 9802
#pragma  tagcall MMUBase SetMappingProperties   144 a0921806
#pragma  tagcall MMUBase GetMappingProperties   14a a9803
#pragma  tagcall MMUBase RebuildTrees           168 801
#pragma  tagcall MMUBase CreateContextWindow    1aa 9802
#endif

#endif	/*  _INCLUDE_PRAGMA_MMU_LIB_H  */
