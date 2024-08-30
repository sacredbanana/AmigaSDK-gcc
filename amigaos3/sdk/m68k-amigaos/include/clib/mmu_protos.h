/*************************************************************************
 ** mmu.library                                                         **
 **                                                                     **
 ** a system library for arbitration and control of the MC68K MMUs      **
 **                                                                     **
 ** © 1998-2000 THOR-Software, Thomas Richter                           **
 ** No commercial use, reassembly, modification without prior, written  **
 ** permission of the authors.                                          **
 ** Including this library in any commercial software REQUIRES a        **
 ** written permission and the payment of a small fee.                  **
 **                                                                     **
 **---------------------------------------------------------------------**
 ** mmu.library prototypes                                              **
 ** Version 46.2                06.08.2016                              **
 *************************************************************************/

#ifndef CLIB_MMU_PROTOS_H
#define CLIB_MMU_PROTOS_H

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef MMU_CONTEXT_H
#include <mmu/context.h>
#endif

void *AllocAligned(ULONG bytesize,ULONG reqments,ULONG alignment);
struct MinList *GetMapping(struct MMUContext *);
void ReleaseMapping(struct MMUContext *,struct MinList *);
void SetPropertyList(struct MMUContext *,struct MinList *);
void TouchPropertyList(struct MinList *);
ULONG GetPageSize(struct MMUContext *);
ULONG RemapSize(struct MMUContext *);
char GetMMUType(void);
void LockMMUContext(struct MMUContext *);
void UnlockMMUContext(struct MMUContext *);
LONG AttemptLockMMUContext(struct MMUContext *);
void LockContextList(void);
void UnlockContextList(void);
LONG AttemptLockContextList(void);
BOOL SetPropertiesA(struct MMUContext *,ULONG flags,ULONG mask,ULONG lower,
        ULONG size,struct TagItem *tags);
BOOL SetProperties(struct MMUContext *,ULONG flags,ULONG mask,ULONG lower,
        ULONG size,unsigned long tag1type, ... );
ULONG GetPropertiesA(struct MMUContext *,ULONG lower,struct TagItem *tags);
ULONG GetProperties(struct MMUContext *,ULONG lower,
        unsigned long tag1type, ... );
BOOL RebuildTree(struct MMUContext *);
BOOL RebuildTreesA(struct MMUContext **);
BOOL RebuildTrees(struct MMUContext *, ... );
BOOL SetPagePropertiesA(struct MMUContext *,ULONG flags,ULONG mask,
        ULONG lower,struct TagItem *tags);
BOOL SetPageProperties(struct MMUContext *,ULONG flags,ULONG mask,
        ULONG lower,unsigned long tag1type, ... );
ULONG GetPagePropertiesA(struct MMUContext *,ULONG lower,
        struct TagItem *tags);
ULONG GetPageProperties(struct MMUContext *,ULONG lower,
        unsigned long tag1type, ... );
struct MMUContext *CreateMMUContextA(struct TagItem *tags);
struct MMUContext *CreateMMUContext(unsigned long tag1type, ... );
BOOL DeleteMMUContext(struct MMUContext *);
void *AllocLineVec(ULONG bytesize,ULONG reqments);
ULONG PhysicalPageLocation(struct MMUContext *,ULONG logical);
struct MMUContext *SuperContext(struct MMUContext *);
struct MMUContext *DefaultContext(void);
struct MMUContext *CurrentContext(struct Task *);
struct MMUContext *EnterMMUContext(struct MMUContext *,struct Task *);
struct MMUContext *LeaveMMUContext(struct Task *);
struct ExceptionHook *AddContextHookA(struct TagItem *tags);
struct ExceptionHook *AddContextHook(unsigned long tag1type, ... );
void RemContextHook(struct ExceptionHook *);
struct ExceptionHook *AddMessageHookA(struct TagItem *tags);
struct ExceptionHook *AddMessageHook(unsigned long tag1type, ... );
void RemMessageHook(struct ExceptionHook *);
void ActivateException(struct ExceptionHook *);
void DeactivateException(struct ExceptionHook *);
void DMAInitiate(struct MMUContext *,void **,ULONG *,BOOL);
void DMATerminate(struct MMUContext *);
ULONG PhysicalLocation(struct MMUContext *,void **,ULONG *);
ULONG WithoutMMU(unsigned long (*userFunction)() );
ULONG RunOldConfig(unsigned long (*userFunction)() );
void SetBusError(void (*handler)(), void (**oldhandler)() );
ULONG GetMMUContextData(struct MMUContext *,ULONG tag_id );
void SetMMUContextDataA(struct MMUContext *,struct TagItem * );
void SetMMUContextData(struct MMUContext *, unsigned long tag1type , ... );
struct MinList *NewMapping(void);
BOOL CopyMapping(struct MinList *, struct MinList *,ULONG base,ULONG len,ULONG mask);
struct MinList *DupMapping(struct MinList *);
BOOL CopyContextRegion(struct MMUContext *, struct MinList *,ULONG base,ULONG len,ULONG mask);
BOOL SetPropertiesMapping(struct MMUContext *, struct MinList *,ULONG base,ULONG len,ULONG mask);
int SetMappingPropertiesA(struct MinList *,ULONG flags,ULONG mask,ULONG lower,ULONG size,struct TagItem *);
int SetMappingProperties(struct MinList *,ULONG flags,ULONG mask,ULONG lower,ULONG size,unsigned long tag1type, ... );
ULONG GetMappingPropertiesA(struct MinList *,ULONG lower,struct TagItem *);
ULONG GetMappingProperties(struct MinList *,ULONG lower,unsigned long tag1type,...);
ULONG BuildIndirect(struct MMUContext *,ULONG adr,ULONG props);
void SetIndirect(ULONG *dest,ULONG logical, ULONG desc);
void SetIndirectArray(ULONG *dest,ULONG *descr,ULONG num);
void GetIndirect(struct MMUContext *,struct AbstractDescriptor *,ULONG *addr);
ULONG GetPageUsedModified(struct MMUContext *,ULONG lower);
BOOL MapWindow(struct MMUContext *targetctx,struct MMUContext *srcctx,struct ContextWindow *window);
struct ContextWindow *CreateContextWindow(struct MMUContext *target,struct MMUContext *src,...);
struct ContextWindow *CreateContextWindowA(struct MMUContext *target,struct MMUContext **psrc);
void ReleaseContextWindow(struct ContextWindow *);
BOOL RefreshContextWindow(struct ContextWindow *);
BOOL MapWindowCached(struct MMUContext *targetctx,struct MMUContext *srcctx,struct ContextWindow *window);
BOOL LayoutContextWindow(struct ContextWindow *);
ULONG LogicalLocation(struct MMUContext *,void **,ULONG *);
#endif
