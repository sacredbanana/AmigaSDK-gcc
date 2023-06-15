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

void * __AllocAligned(__reg("a6") struct Library * , __reg("d0") ULONG bytesize , __reg("d1") ULONG reqments , __reg("a0") ULONG alignment ) = "\tjsr\t-30(a6)";
#define AllocAligned(bytesize, reqments, alignment) __AllocAligned(MMUBase, (bytesize), (reqments), (alignment))

struct MinList * __GetMapping(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-36(a6)";
#define GetMapping(ctx) __GetMapping(MMUBase, (ctx))

void __ReleaseMapping(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct MinList * list ) = "\tjsr\t-42(a6)";
#define ReleaseMapping(ctx, list) __ReleaseMapping(MMUBase, (ctx), (list))

ULONG __GetPageSize(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-48(a6)";
#define GetPageSize(ctx) __GetPageSize(MMUBase, (ctx))

char __GetMMUType(__reg("a6") struct Library * ) = "\tjsr\t-54(a6)";
#define GetMMUType() __GetMMUType(MMUBase)

void __LockMMUContext(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-72(a6)";
#define LockMMUContext(ctx) __LockMMUContext(MMUBase, (ctx))

void __UnlockMMUContext(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-78(a6)";
#define UnlockMMUContext(ctx) __UnlockMMUContext(MMUBase, (ctx))

BOOL __SetPropertiesA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("d1") ULONG flags , __reg("d2") ULONG mask , __reg("a1") ULONG lower , __reg("d0") ULONG size , __reg("a2") struct TagItem * tags ) = "\tjsr\t-84(a6)";
#define SetPropertiesA(ctx, flags, mask, lower, size, tags) __SetPropertiesA(MMUBase, (ctx), (flags), (mask), (lower), (size), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __SetProperties(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("d1") ULONG flags , __reg("d2") ULONG mask , __reg("a1") ULONG lower , __reg("d0") ULONG size , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-84(a6)\n\tmovea.l\t(a7)+,a2";
#define SetProperties(ctx, flags, mask, lower, size, ...) __SetProperties(MMUBase, (ctx), (flags), (mask), (lower), (size), __VA_ARGS__)
#endif

ULONG __GetPropertiesA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") ULONG lower , __reg("a2") struct TagItem * tags ) = "\tjsr\t-90(a6)";
#define GetPropertiesA(ctx, lower, tags) __GetPropertiesA(MMUBase, (ctx), (lower), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __GetProperties(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") ULONG lower , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-90(a6)\n\tmovea.l\t(a7)+,a2";
#define GetProperties(ctx, lower, ...) __GetProperties(MMUBase, (ctx), (lower), __VA_ARGS__)
#endif

BOOL __RebuildTree(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-96(a6)";
#define RebuildTree(ctx) __RebuildTree(MMUBase, (ctx))

BOOL __SetPagePropertiesA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("d1") ULONG flags , __reg("d2") ULONG mask , __reg("a1") ULONG lower , __reg("a2") struct TagItem * tags ) = "\tjsr\t-102(a6)";
#define SetPagePropertiesA(ctx, flags, mask, lower, tags) __SetPagePropertiesA(MMUBase, (ctx), (flags), (mask), (lower), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __SetPageProperties(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("d1") ULONG flags , __reg("d2") ULONG mask , __reg("a1") ULONG lower , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-102(a6)\n\tmovea.l\t(a7)+,a2";
#define SetPageProperties(ctx, flags, mask, lower, ...) __SetPageProperties(MMUBase, (ctx), (flags), (mask), (lower), __VA_ARGS__)
#endif

ULONG __GetPagePropertiesA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") ULONG lower , __reg("a2") struct TagItem * tags ) = "\tjsr\t-108(a6)";
#define GetPagePropertiesA(ctx, lower, tags) __GetPagePropertiesA(MMUBase, (ctx), (lower), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __GetPageProperties(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") ULONG lower , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-108(a6)\n\tmovea.l\t(a7)+,a2";
#define GetPageProperties(ctx, lower, ...) __GetPageProperties(MMUBase, (ctx), (lower), __VA_ARGS__)
#endif

struct MMUContext * __CreateMMUContextA(__reg("a6") struct Library * , __reg("a0") struct TagItem * tags ) = "\tjsr\t-114(a6)";
#define CreateMMUContextA(tags) __CreateMMUContextA(MMUBase, (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct MMUContext * __CreateMMUContext(__reg("a6") struct Library * , Tag tags , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-114(a6)\n\tmovea.l\t(a7)+,a0";
#define CreateMMUContext(...) __CreateMMUContext(MMUBase, __VA_ARGS__)
#endif

BOOL __DeleteMMUContext(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-120(a6)";
#define DeleteMMUContext(ctx) __DeleteMMUContext(MMUBase, (ctx))

void * __AllocLineVec(__reg("a6") struct Library * , __reg("d0") ULONG bytesize , __reg("d1") ULONG reqments ) = "\tjsr\t-132(a6)";
#define AllocLineVec(bytesize, reqments) __AllocLineVec(MMUBase, (bytesize), (reqments))

ULONG __PhysicalPageLocation(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") ULONG addr ) = "\tjsr\t-138(a6)";
#define PhysicalPageLocation(ctx, addr) __PhysicalPageLocation(MMUBase, (ctx), (addr))

struct MMUContext * __SuperContext(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-144(a6)";
#define SuperContext(ctx) __SuperContext(MMUBase, (ctx))

struct MMUContext * __DefaultContext(__reg("a6") struct Library * ) = "\tjsr\t-150(a6)";
#define DefaultContext() __DefaultContext(MMUBase)

struct MMUContext * __EnterMMUContext(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct Task * task ) = "\tjsr\t-156(a6)";
#define EnterMMUContext(ctx, task) __EnterMMUContext(MMUBase, (ctx), (task))

struct MMUContext * __LeaveMMUContext(__reg("a6") struct Library * , __reg("a1") struct Task * task ) = "\tjsr\t-162(a6)";
#define LeaveMMUContext(task) __LeaveMMUContext(MMUBase, (task))

struct ExceptionHook * __AddContextHookA(__reg("a6") struct Library * , __reg("a0") struct TagItem * tags ) = "\tjsr\t-168(a6)";
#define AddContextHookA(tags) __AddContextHookA(MMUBase, (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct ExceptionHook * __AddContextHook(__reg("a6") struct Library * , Tag tags , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-168(a6)\n\tmovea.l\t(a7)+,a0";
#define AddContextHook(...) __AddContextHook(MMUBase, __VA_ARGS__)
#endif

void __RemContextHook(__reg("a6") struct Library * , __reg("a1") struct ExceptionHook * hook ) = "\tjsr\t-174(a6)";
#define RemContextHook(hook) __RemContextHook(MMUBase, (hook))

struct ExceptionHook * __AddMessageHookA(__reg("a6") struct Library * , __reg("a0") struct TagItem * tags ) = "\tjsr\t-180(a6)";
#define AddMessageHookA(tags) __AddMessageHookA(MMUBase, (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct ExceptionHook * __AddMessageHook(__reg("a6") struct Library * , Tag tags , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-180(a6)\n\tmovea.l\t(a7)+,a0";
#define AddMessageHook(...) __AddMessageHook(MMUBase, __VA_ARGS__)
#endif

void __RemMessageHook(__reg("a6") struct Library * , __reg("a1") struct ExceptionHook * hook ) = "\tjsr\t-186(a6)";
#define RemMessageHook(hook) __RemMessageHook(MMUBase, (hook))

void __ActivateException(__reg("a6") struct Library * , __reg("a1") struct ExceptionHook * hook ) = "\tjsr\t-192(a6)";
#define ActivateException(hook) __ActivateException(MMUBase, (hook))

void __DeactivateException(__reg("a6") struct Library * , __reg("a1") struct ExceptionHook * hook ) = "\tjsr\t-198(a6)";
#define DeactivateException(hook) __DeactivateException(MMUBase, (hook))

LONG __AttemptLockMMUContext(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-204(a6)";
#define AttemptLockMMUContext(ctx) __AttemptLockMMUContext(MMUBase, (ctx))

void __LockContextList(__reg("a6") struct Library * ) = "\tjsr\t-210(a6)";
#define LockContextList() __LockContextList(MMUBase)

void __UnlockContextList(__reg("a6") struct Library * ) = "\tjsr\t-216(a6)";
#define UnlockContextList() __UnlockContextList(MMUBase)

LONG __AttemptLockContextList(__reg("a6") struct Library * ) = "\tjsr\t-222(a6)";
#define AttemptLockContextList() __AttemptLockContextList(MMUBase)

void __SetPropertyList(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct MinList * list ) = "\tjsr\t-228(a6)";
#define SetPropertyList(ctx, list) __SetPropertyList(MMUBase, (ctx), (list))

void __TouchPropertyList(__reg("a6") struct Library * , __reg("a1") struct MinList * list ) = "\tjsr\t-234(a6)";
#define TouchPropertyList(list) __TouchPropertyList(MMUBase, (list))

struct MMUContext * __CurrentContext(__reg("a6") struct Library * , __reg("a1") struct Task * task ) = "\tjsr\t-240(a6)";
#define CurrentContext(task) __CurrentContext(MMUBase, (task))

void __DMAInitiate(__reg("a6") struct Library * , __reg("d1") struct MMUContext * ctx , __reg("a0") void * * addrptrptr , __reg("a1") ULONG * lengthptr , __reg("d0") BOOL write ) = "\tjsr\t-246(a6)";
#define DMAInitiate(ctx, addrptrptr, lengthptr, write) __DMAInitiate(MMUBase, (ctx), (addrptrptr), (lengthptr), (write))

void __DMATerminate(__reg("a6") struct Library * , __reg("d1") struct MMUContext * ctx ) = "\tjsr\t-252(a6)";
#define DMATerminate(ctx) __DMATerminate(MMUBase, (ctx))

ULONG __PhysicalLocation(__reg("a6") struct Library * , __reg("d1") struct MMUContext * ctx , __reg("a0") void * * addrptrptr , __reg("a1") ULONG * lengthptr ) = "\tjsr\t-258(a6)";
#define PhysicalLocation(ctx, addrptrptr, lengthptr) __PhysicalLocation(MMUBase, (ctx), (addrptrptr), (lengthptr))

ULONG __RemapSize(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx ) = "\tjsr\t-264(a6)";
#define RemapSize(ctx) __RemapSize(MMUBase, (ctx))

ULONG __WithoutMMU(__reg("a6") struct Library * , __reg("a5") unsigned long (* func)() ) = "\tjsr\t-270(a6)";
#define WithoutMMU(func) __WithoutMMU(MMUBase, (func))

void __SetBusError(__reg("a6") struct Library * , __reg("a0") void (* func)() , __reg("a1") void (* oldfuncptr)() ) = "\tjsr\t-276(a6)";
#define SetBusError(func, oldfuncptr) __SetBusError(MMUBase, (func), (oldfuncptr))

ULONG __GetMMUContextData(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("d0") ULONG tagid ) = "\tjsr\t-282(a6)";
#define GetMMUContextData(ctx, tagid) __GetMMUContextData(MMUBase, (ctx), (tagid))

void __SetMMUContextDataA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct TagItem * tags ) = "\tjsr\t-288(a6)";
#define SetMMUContextDataA(ctx, tags) __SetMMUContextDataA(MMUBase, (ctx), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __SetMMUContextData(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-288(a6)\n\tmovea.l\t(a7)+,a1";
#define SetMMUContextData(ctx, ...) __SetMMUContextData(MMUBase, (ctx), __VA_ARGS__)
#endif

struct MinList * __NewMapping(__reg("a6") struct Library * ) = "\tjsr\t-294(a6)";
#define NewMapping() __NewMapping(MMUBase)

BOOL __CopyMapping(__reg("a6") struct Library * , __reg("a0") struct MinList * from , __reg("a1") struct MinList * to , __reg("d0") ULONG base , __reg("d1") ULONG length , __reg("d2") ULONG mask ) = "\tjsr\t-300(a6)";
#define CopyMapping(from, to, base, length, mask) __CopyMapping(MMUBase, (from), (to), (base), (length), (mask))

struct MinList * __DupMapping(__reg("a6") struct Library * , __reg("a0") struct MinList * list ) = "\tjsr\t-306(a6)";
#define DupMapping(list) __DupMapping(MMUBase, (list))

BOOL __CopyContextRegion(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct MinList * list , __reg("d0") ULONG base , __reg("d1") ULONG length , __reg("d2") ULONG mask ) = "\tjsr\t-312(a6)";
#define CopyContextRegion(ctx, list, base, length, mask) __CopyContextRegion(MMUBase, (ctx), (list), (base), (length), (mask))

BOOL __SetPropertiesMapping(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct MinList * list , __reg("d0") ULONG base , __reg("d1") ULONG length , __reg("d2") ULONG mask ) = "\tjsr\t-318(a6)";
#define SetPropertiesMapping(ctx, list, base, length, mask) __SetPropertiesMapping(MMUBase, (ctx), (list), (base), (length), (mask))

int __SetMappingPropertiesA(__reg("a6") struct Library * , __reg("a0") struct MinList * list , __reg("d1") ULONG flags , __reg("d2") ULONG mask , __reg("a1") ULONG lower , __reg("d0") ULONG size , __reg("a2") struct TagItem * tags ) = "\tjsr\t-324(a6)";
#define SetMappingPropertiesA(list, flags, mask, lower, size, tags) __SetMappingPropertiesA(MMUBase, (list), (flags), (mask), (lower), (size), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
int __SetMappingProperties(__reg("a6") struct Library * , __reg("a0") struct MinList * list , __reg("d1") ULONG flags , __reg("d2") ULONG mask , __reg("a1") ULONG lower , __reg("d0") ULONG size , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-324(a6)\n\tmovea.l\t(a7)+,a2";
#define SetMappingProperties(list, flags, mask, lower, size, ...) __SetMappingProperties(MMUBase, (list), (flags), (mask), (lower), (size), __VA_ARGS__)
#endif

ULONG __GetMappingPropertiesA(__reg("a6") struct Library * , __reg("a0") struct MinList * list , __reg("a1") ULONG lower , __reg("a2") struct TagItem * tags ) = "\tjsr\t-330(a6)";
#define GetMappingPropertiesA(list, lower, tags) __GetMappingPropertiesA(MMUBase, (list), (lower), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __GetMappingProperties(__reg("a6") struct Library * , __reg("a0") struct MinList * list , __reg("a1") ULONG lower , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-330(a6)\n\tmovea.l\t(a7)+,a2";
#define GetMappingProperties(list, lower, ...) __GetMappingProperties(MMUBase, (list), (lower), __VA_ARGS__)
#endif

ULONG __BuildIndirect(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("d0") ULONG address , __reg("d1") ULONG props ) = "\tjsr\t-336(a6)";
#define BuildIndirect(ctx, address, props) __BuildIndirect(MMUBase, (ctx), (address), (props))

void __SetIndirect(__reg("a6") struct Library * , __reg("a0") ULONG * destination , __reg("a1") ULONG logical , __reg("d0") ULONG descriptor ) = "\tjsr\t-342(a6)";
#define SetIndirect(destination, logical, descriptor) __SetIndirect(MMUBase, (destination), (logical), (descriptor))

void __GetIndirect(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") struct AbstractDescriptor * adt , __reg("d0") ULONG * address ) = "\tjsr\t-348(a6)";
#define GetIndirect(ctx, adt, address) __GetIndirect(MMUBase, (ctx), (adt), (address))

BOOL __RebuildTreesA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * * ctxptr ) = "\tjsr\t-360(a6)";
#define RebuildTreesA(ctxptr) __RebuildTreesA(MMUBase, (ctxptr))

ULONG __RunOldConfig(__reg("a6") struct Library * , __reg("a5") unsigned long (* func)() ) = "\tjsr\t-366(a6)";
#define RunOldConfig(func) __RunOldConfig(MMUBase, (func))

void __SetIndirectArray(__reg("a6") struct Library * , __reg("a0") ULONG * destination , __reg("a1") ULONG * descriptor , __reg("d0") ULONG number ) = "\tjsr\t-372(a6)";
#define SetIndirectArray(destination, descriptor, number) __SetIndirectArray(MMUBase, (destination), (descriptor), (number))

ULONG __GetPageUsedModified(__reg("a6") struct Library * , __reg("a0") struct MMUContext * ctx , __reg("a1") ULONG address ) = "\tjsr\t-378(a6)";
#define GetPageUsedModified(ctx, address) __GetPageUsedModified(MMUBase, (ctx), (address))

BOOL __MapWindow(__reg("a6") struct Library * , __reg("a0") struct MMUContext * targetctx , __reg("a1") struct MMUContext * srcctx , __reg("d1") struct ContextWindow * window ) = "\tjsr\t-420(a6)";
#define MapWindow(targetctx, srcctx, window) __MapWindow(MMUBase, (targetctx), (srcctx), (window))

struct ContextWindow * __CreateContextWindowA(__reg("a6") struct Library * , __reg("a0") struct MMUContext * targetctx , __reg("a1") struct MMUContext * * srcctxptrptr ) = "\tjsr\t-426(a6)";
#define CreateContextWindowA(targetctx, srcctxptrptr) __CreateContextWindowA(MMUBase, (targetctx), (srcctxptrptr))

void __ReleaseContextWindow(__reg("a6") struct Library * , __reg("a1") struct ContextWindow * window ) = "\tjsr\t-432(a6)";
#define ReleaseContextWindow(window) __ReleaseContextWindow(MMUBase, (window))

BOOL __RefreshContextWindow(__reg("a6") struct Library * , __reg("a0") struct ContextWindow * window ) = "\tjsr\t-438(a6)";
#define RefreshContextWindow(window) __RefreshContextWindow(MMUBase, (window))

BOOL __MapWindowCached(__reg("a6") struct Library * , __reg("a0") struct MMUContext * targetctx , __reg("a1") struct MMUContext * srcctx , __reg("d1") struct ContextWindow * window ) = "\tjsr\t-444(a6)";
#define MapWindowCached(targetctx, srcctx, window) __MapWindowCached(MMUBase, (targetctx), (srcctx), (window))

BOOL __LayoutContextWindow(__reg("a6") struct Library * , __reg("a0") struct ContextWindow * window ) = "\tjsr\t-450(a6)";
#define LayoutContextWindow(window) __LayoutContextWindow(MMUBase, (window))

ULONG __LogicalLocation(__reg("a6") struct Library * , __reg("d1") struct MMUContext * ctx , __reg("a0") void * * adrptrptr , __reg("a1") ULONG * lengthptr ) = "\tjsr\t-462(a6)";
#define LogicalLocation(ctx, adrptrptr, lengthptr) __LogicalLocation(MMUBase, (ctx), (adrptrptr), (lengthptr))

#endif /* !_INLINE_MMU_H */
