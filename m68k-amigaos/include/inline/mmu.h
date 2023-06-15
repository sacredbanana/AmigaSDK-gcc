/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MMU_H
#define _INLINE_MMU_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef MMU_BASE_NAME
#define MMU_BASE_NAME MMUBase
#endif /* !MMU_BASE_NAME */

#define AllocAligned(___bytesize, ___reqments, ___alignment) \
      LP3(0x1e, void *, AllocAligned , ULONG, ___bytesize, d0, ULONG, ___reqments, d1, ULONG, ___alignment, a0,\
      , MMU_BASE_NAME)

#define GetMapping(___ctx) \
      LP1(0x24, struct MinList *, GetMapping , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define ReleaseMapping(___ctx, ___list) \
      LP2NR(0x2a, ReleaseMapping , struct MMUContext *, ___ctx, a0, struct MinList *, ___list, a1,\
      , MMU_BASE_NAME)

#define GetPageSize(___ctx) \
      LP1(0x30, ULONG, GetPageSize , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define GetMMUType() \
      LP0(0x36, char, GetMMUType ,\
      , MMU_BASE_NAME)

#define LockMMUContext(___ctx) \
      LP1NR(0x48, LockMMUContext , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define UnlockMMUContext(___ctx) \
      LP1NR(0x4e, UnlockMMUContext , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define SetPropertiesA(___ctx, ___flags, ___mask, ___lower, ___size, ___tags) \
      LP6(0x54, BOOL, SetPropertiesA , struct MMUContext *, ___ctx, a0, ULONG, ___flags, d1, ULONG, ___mask, d2, ULONG, ___lower, a1, ULONG, ___size, d0, struct TagItem *, ___tags, a2,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define SetProperties(___ctx, ___flags, ___mask, ___lower, ___size, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; SetPropertiesA((___ctx), (___flags), (___mask), (___lower), (___size), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define GetPropertiesA(___ctx, ___lower, ___tags) \
      LP3(0x5a, ULONG, GetPropertiesA , struct MMUContext *, ___ctx, a0, ULONG, ___lower, a1, struct TagItem *, ___tags, a2,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define GetProperties(___ctx, ___lower, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; GetPropertiesA((___ctx), (___lower), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define RebuildTree(___ctx) \
      LP1(0x60, BOOL, RebuildTree , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define SetPagePropertiesA(___ctx, ___flags, ___mask, ___lower, ___tags) \
      LP5(0x66, BOOL, SetPagePropertiesA , struct MMUContext *, ___ctx, a0, ULONG, ___flags, d1, ULONG, ___mask, d2, ULONG, ___lower, a1, struct TagItem *, ___tags, a2,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define SetPageProperties(___ctx, ___flags, ___mask, ___lower, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; SetPagePropertiesA((___ctx), (___flags), (___mask), (___lower), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define GetPagePropertiesA(___ctx, ___lower, ___tags) \
      LP3(0x6c, ULONG, GetPagePropertiesA , struct MMUContext *, ___ctx, a0, ULONG, ___lower, a1, struct TagItem *, ___tags, a2,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define GetPageProperties(___ctx, ___lower, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; GetPagePropertiesA((___ctx), (___lower), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreateMMUContextA(___tags) \
      LP1(0x72, struct MMUContext *, CreateMMUContextA , struct TagItem *, ___tags, a0,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateMMUContext(___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; CreateMMUContextA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeleteMMUContext(___ctx) \
      LP1(0x78, BOOL, DeleteMMUContext , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define AllocLineVec(___bytesize, ___reqments) \
      LP2(0x84, void *, AllocLineVec , ULONG, ___bytesize, d0, ULONG, ___reqments, d1,\
      , MMU_BASE_NAME)

#define PhysicalPageLocation(___ctx, ___addr) \
      LP2(0x8a, ULONG, PhysicalPageLocation , struct MMUContext *, ___ctx, a0, ULONG, ___addr, a1,\
      , MMU_BASE_NAME)

#define SuperContext(___ctx) \
      LP1(0x90, struct MMUContext *, SuperContext , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define DefaultContext() \
      LP0(0x96, struct MMUContext *, DefaultContext ,\
      , MMU_BASE_NAME)

#define EnterMMUContext(___ctx, ___task) \
      LP2(0x9c, struct MMUContext *, EnterMMUContext , struct MMUContext *, ___ctx, a0, struct Task *, ___task, a1,\
      , MMU_BASE_NAME)

#define LeaveMMUContext(___task) \
      LP1(0xa2, struct MMUContext *, LeaveMMUContext , struct Task *, ___task, a1,\
      , MMU_BASE_NAME)

#define AddContextHookA(___tags) \
      LP1(0xa8, struct ExceptionHook *, AddContextHookA , struct TagItem *, ___tags, a0,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddContextHook(___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; AddContextHookA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define RemContextHook(___hook) \
      LP1NR(0xae, RemContextHook , struct ExceptionHook *, ___hook, a1,\
      , MMU_BASE_NAME)

#define AddMessageHookA(___tags) \
      LP1(0xb4, struct ExceptionHook *, AddMessageHookA , struct TagItem *, ___tags, a0,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddMessageHook(___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; AddMessageHookA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define RemMessageHook(___hook) \
      LP1NR(0xba, RemMessageHook , struct ExceptionHook *, ___hook, a1,\
      , MMU_BASE_NAME)

#define ActivateException(___hook) \
      LP1NR(0xc0, ActivateException , struct ExceptionHook *, ___hook, a1,\
      , MMU_BASE_NAME)

#define DeactivateException(___hook) \
      LP1NR(0xc6, DeactivateException , struct ExceptionHook *, ___hook, a1,\
      , MMU_BASE_NAME)

#define AttemptLockMMUContext(___ctx) \
      LP1(0xcc, LONG, AttemptLockMMUContext , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define LockContextList() \
      LP0NR(0xd2, LockContextList ,\
      , MMU_BASE_NAME)

#define UnlockContextList() \
      LP0NR(0xd8, UnlockContextList ,\
      , MMU_BASE_NAME)

#define AttemptLockContextList() \
      LP0(0xde, LONG, AttemptLockContextList ,\
      , MMU_BASE_NAME)

#define SetPropertyList(___ctx, ___list) \
      LP2NR(0xe4, SetPropertyList , struct MMUContext *, ___ctx, a0, struct MinList *, ___list, a1,\
      , MMU_BASE_NAME)

#define TouchPropertyList(___list) \
      LP1NR(0xea, TouchPropertyList , struct MinList *, ___list, a1,\
      , MMU_BASE_NAME)

#define CurrentContext(___task) \
      LP1(0xf0, struct MMUContext *, CurrentContext , struct Task *, ___task, a1,\
      , MMU_BASE_NAME)

#define DMAInitiate(___ctx, ___addrptrptr, ___lengthptr, ___write) \
      LP4NR(0xf6, DMAInitiate , struct MMUContext *, ___ctx, d1, void * *, ___addrptrptr, a0, ULONG *, ___lengthptr, a1, BOOL, ___write, d0,\
      , MMU_BASE_NAME)

#define DMATerminate(___ctx) \
      LP1NR(0xfc, DMATerminate , struct MMUContext *, ___ctx, d1,\
      , MMU_BASE_NAME)

#define PhysicalLocation(___ctx, ___addrptrptr, ___lengthptr) \
      LP3(0x102, ULONG, PhysicalLocation , struct MMUContext *, ___ctx, d1, void * *, ___addrptrptr, a0, ULONG *, ___lengthptr, a1,\
      , MMU_BASE_NAME)

#define RemapSize(___ctx) \
      LP1(0x108, ULONG, RemapSize , struct MMUContext *, ___ctx, a0,\
      , MMU_BASE_NAME)

#define WithoutMMU(___func) \
      LP1A5FP(0x10e, ULONG, WithoutMMU , __fpt, ___func, d7,\
      , MMU_BASE_NAME, unsigned long (*__fpt)())

#define SetBusError(___func, ___oldfuncptr) \
      LP2NRFP2(0x114, SetBusError , __fpt1, ___func, a0, __fpt1, ___oldfuncptr, a1,\
      , MMU_BASE_NAME, void (*__fpt1)(), void (*__fpt2)())

#define GetMMUContextData(___ctx, ___tagid) \
      LP2(0x11a, ULONG, GetMMUContextData , struct MMUContext *, ___ctx, a0, ULONG, ___tagid, d0,\
      , MMU_BASE_NAME)

#define SetMMUContextDataA(___ctx, ___tags) \
      LP2NR(0x120, SetMMUContextDataA , struct MMUContext *, ___ctx, a0, struct TagItem *, ___tags, a1,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define SetMMUContextData(___ctx, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; SetMMUContextDataA((___ctx), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define NewMapping() \
      LP0(0x126, struct MinList *, NewMapping ,\
      , MMU_BASE_NAME)

#define CopyMapping(___from, ___to, ___base, ___length, ___mask) \
      LP5(0x12c, BOOL, CopyMapping , struct MinList *, ___from, a0, struct MinList *, ___to, a1, ULONG, ___base, d0, ULONG, ___length, d1, ULONG, ___mask, d2,\
      , MMU_BASE_NAME)

#define DupMapping(___list) \
      LP1(0x132, struct MinList *, DupMapping , struct MinList *, ___list, a0,\
      , MMU_BASE_NAME)

#define CopyContextRegion(___ctx, ___list, ___base, ___length, ___mask) \
      LP5(0x138, BOOL, CopyContextRegion , struct MMUContext *, ___ctx, a0, struct MinList *, ___list, a1, ULONG, ___base, d0, ULONG, ___length, d1, ULONG, ___mask, d2,\
      , MMU_BASE_NAME)

#define SetPropertiesMapping(___ctx, ___list, ___base, ___length, ___mask) \
      LP5(0x13e, BOOL, SetPropertiesMapping , struct MMUContext *, ___ctx, a0, struct MinList *, ___list, a1, ULONG, ___base, d0, ULONG, ___length, d1, ULONG, ___mask, d2,\
      , MMU_BASE_NAME)

#define SetMappingPropertiesA(___list, ___flags, ___mask, ___lower, ___size, ___tags) \
      LP6(0x144, int, SetMappingPropertiesA , struct MinList *, ___list, a0, ULONG, ___flags, d1, ULONG, ___mask, d2, ULONG, ___lower, a1, ULONG, ___size, d0, struct TagItem *, ___tags, a2,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define SetMappingProperties(___list, ___flags, ___mask, ___lower, ___size, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; SetMappingPropertiesA((___list), (___flags), (___mask), (___lower), (___size), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define GetMappingPropertiesA(___list, ___lower, ___tags) \
      LP3(0x14a, ULONG, GetMappingPropertiesA , struct MinList *, ___list, a0, ULONG, ___lower, a1, struct TagItem *, ___tags, a2,\
      , MMU_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define GetMappingProperties(___list, ___lower, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; GetMappingPropertiesA((___list), (___lower), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define BuildIndirect(___ctx, ___address, ___props) \
      LP3(0x150, ULONG, BuildIndirect , struct MMUContext *, ___ctx, a0, ULONG, ___address, d0, ULONG, ___props, d1,\
      , MMU_BASE_NAME)

#define SetIndirect(___destination, ___logical, ___descriptor) \
      LP3NR(0x156, SetIndirect , ULONG *, ___destination, a0, ULONG, ___logical, a1, ULONG, ___descriptor, d0,\
      , MMU_BASE_NAME)

#define GetIndirect(___ctx, ___adt, ___address) \
      LP3NR(0x15c, GetIndirect , struct MMUContext *, ___ctx, a0, struct AbstractDescriptor *, ___adt, a1, ULONG *, ___address, d0,\
      , MMU_BASE_NAME)

#define RebuildTreesA(___ctxptr) \
      LP1(0x168, BOOL, RebuildTreesA , struct MMUContext * *, ___ctxptr, a0,\
      , MMU_BASE_NAME)

#define RunOldConfig(___func) \
      LP1A5FP(0x16e, ULONG, RunOldConfig , __fpt, ___func, d7,\
      , MMU_BASE_NAME, unsigned long (*__fpt)())

#define SetIndirectArray(___destination, ___descriptor, ___number) \
      LP3NR(0x174, SetIndirectArray , ULONG *, ___destination, a0, ULONG *, ___descriptor, a1, ULONG, ___number, d0,\
      , MMU_BASE_NAME)

#define GetPageUsedModified(___ctx, ___address) \
      LP2(0x17a, ULONG, GetPageUsedModified , struct MMUContext *, ___ctx, a0, ULONG, ___address, a1,\
      , MMU_BASE_NAME)

#define MapWindow(___targetctx, ___srcctx, ___window) \
      LP3(0x1a4, BOOL, MapWindow , struct MMUContext *, ___targetctx, a0, struct MMUContext *, ___srcctx, a1, struct ContextWindow *, ___window, d1,\
      , MMU_BASE_NAME)

#define CreateContextWindowA(___targetctx, ___srcctxptrptr) \
      LP2(0x1aa, struct ContextWindow *, CreateContextWindowA , struct MMUContext *, ___targetctx, a0, struct MMUContext * *, ___srcctxptrptr, a1,\
      , MMU_BASE_NAME)

#define ReleaseContextWindow(___window) \
      LP1NR(0x1b0, ReleaseContextWindow , struct ContextWindow *, ___window, a1,\
      , MMU_BASE_NAME)

#define RefreshContextWindow(___window) \
      LP1(0x1b6, BOOL, RefreshContextWindow , struct ContextWindow *, ___window, a0,\
      , MMU_BASE_NAME)

#define MapWindowCached(___targetctx, ___srcctx, ___window) \
      LP3(0x1bc, BOOL, MapWindowCached , struct MMUContext *, ___targetctx, a0, struct MMUContext *, ___srcctx, a1, struct ContextWindow *, ___window, d1,\
      , MMU_BASE_NAME)

#define LayoutContextWindow(___window) \
      LP1(0x1c2, BOOL, LayoutContextWindow , struct ContextWindow *, ___window, a0,\
      , MMU_BASE_NAME)

#define LogicalLocation(___ctx, ___adrptrptr, ___lengthptr) \
      LP3(0x1ce, ULONG, LogicalLocation , struct MMUContext *, ___ctx, d1, void * *, ___adrptrptr, a0, ULONG *, ___lengthptr, a1,\
      , MMU_BASE_NAME)

#endif /* !_INLINE_MMU_H */
