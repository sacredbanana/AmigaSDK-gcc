/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_AMIGAGUIDE_H
#define _INLINE_AMIGAGUIDE_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

LONG __LockAmigaGuideBase(__reg("a6") struct Library * , __reg("a0") APTR handle ) = "\tjsr\t-36(a6)";
#define LockAmigaGuideBase(handle) __LockAmigaGuideBase(AmigaGuideBase, (handle))

VOID __UnlockAmigaGuideBase(__reg("a6") struct Library * , __reg("d0") LONG key ) = "\tjsr\t-42(a6)";
#define UnlockAmigaGuideBase(key) __UnlockAmigaGuideBase(AmigaGuideBase, (key))

APTR __OpenAmigaGuideA(__reg("a6") struct Library * , __reg("a0") struct NewAmigaGuide * nag , __reg("a1") CONST struct TagItem * attrs ) = "\tjsr\t-54(a6)";
#define OpenAmigaGuideA(nag, attrs) __OpenAmigaGuideA(AmigaGuideBase, (nag), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __OpenAmigaGuide(__reg("a6") struct Library * , __reg("a0") struct NewAmigaGuide * nag , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-54(a6)\n\tmovea.l\t(a7)+,a1";
#define OpenAmigaGuide(nag, ...) __OpenAmigaGuide(AmigaGuideBase, (nag), __VA_ARGS__)
#endif

APTR __OpenAmigaGuideAsyncA(__reg("a6") struct Library * , __reg("a0") struct NewAmigaGuide * nag , __reg("d0") CONST struct TagItem * attrs ) = "\tjsr\t-60(a6)";
#define OpenAmigaGuideAsyncA(nag, attrs) __OpenAmigaGuideAsyncA(AmigaGuideBase, (nag), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __OpenAmigaGuideAsync(__reg("a6") struct Library * , __reg("a0") struct NewAmigaGuide * nag , Tag _tag1 , ... ) = "\tmove.l\td0,-(a7)\n\tlea\t4(a7),d0\n\tjsr\t-60(a6)\n\tmovea.l\t(a7)+,d0";
#define OpenAmigaGuideAsync(nag, ...) __OpenAmigaGuideAsync(AmigaGuideBase, (nag), __VA_ARGS__)
#endif

VOID __CloseAmigaGuide(__reg("a6") struct Library * , __reg("a0") APTR cl ) = "\tjsr\t-66(a6)";
#define CloseAmigaGuide(cl) __CloseAmigaGuide(AmigaGuideBase, (cl))

ULONG __AmigaGuideSignal(__reg("a6") struct Library * , __reg("a0") APTR cl ) = "\tjsr\t-72(a6)";
#define AmigaGuideSignal(cl) __AmigaGuideSignal(AmigaGuideBase, (cl))

struct AmigaGuideMsg * __GetAmigaGuideMsg(__reg("a6") struct Library * , __reg("a0") APTR cl ) = "\tjsr\t-78(a6)";
#define GetAmigaGuideMsg(cl) __GetAmigaGuideMsg(AmigaGuideBase, (cl))

VOID __ReplyAmigaGuideMsg(__reg("a6") struct Library * , __reg("a0") struct AmigaGuideMsg * amsg ) = "\tjsr\t-84(a6)";
#define ReplyAmigaGuideMsg(amsg) __ReplyAmigaGuideMsg(AmigaGuideBase, (amsg))

LONG __SetAmigaGuideContextA(__reg("a6") struct Library * , __reg("a0") APTR cl , __reg("d0") ULONG id , __reg("d1") CONST struct TagItem * attrs ) = "\tjsr\t-90(a6)";
#define SetAmigaGuideContextA(cl, id, attrs) __SetAmigaGuideContextA(AmigaGuideBase, (cl), (id), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __SetAmigaGuideContext(__reg("a6") struct Library * , __reg("a0") APTR cl , __reg("d0") ULONG id , Tag _tag1 , ... ) = "\tmove.l\td1,-(a7)\n\tlea\t4(a7),d1\n\tjsr\t-90(a6)\n\tmovea.l\t(a7)+,d1";
#define SetAmigaGuideContext(cl, id, ...) __SetAmigaGuideContext(AmigaGuideBase, (cl), (id), __VA_ARGS__)
#endif

LONG __SendAmigaGuideContextA(__reg("a6") struct Library * , __reg("a0") APTR cl , __reg("d0") CONST struct TagItem * attrs ) = "\tjsr\t-96(a6)";
#define SendAmigaGuideContextA(cl, attrs) __SendAmigaGuideContextA(AmigaGuideBase, (cl), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __SendAmigaGuideContext(__reg("a6") struct Library * , __reg("a0") APTR cl , Tag _tag1 , ... ) = "\tmove.l\td0,-(a7)\n\tlea\t4(a7),d0\n\tjsr\t-96(a6)\n\tmovea.l\t(a7)+,d0";
#define SendAmigaGuideContext(cl, ...) __SendAmigaGuideContext(AmigaGuideBase, (cl), __VA_ARGS__)
#endif

LONG __SendAmigaGuideCmdA(__reg("a6") struct Library * , __reg("a0") APTR cl , __reg("d0") STRPTR cmd , __reg("d1") CONST struct TagItem * attrs ) = "\tjsr\t-102(a6)";
#define SendAmigaGuideCmdA(cl, cmd, attrs) __SendAmigaGuideCmdA(AmigaGuideBase, (cl), (cmd), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __SendAmigaGuideCmd(__reg("a6") struct Library * , __reg("a0") APTR cl , __reg("d0") CONST_STRPTR cmd , Tag _tag1 , ... ) = "\tmove.l\td1,-(a7)\n\tlea\t4(a7),d1\n\tjsr\t-102(a6)\n\tmovea.l\t(a7)+,d1";
#define SendAmigaGuideCmd(cl, cmd, ...) __SendAmigaGuideCmd(AmigaGuideBase, (cl), (cmd), __VA_ARGS__)
#endif

LONG __SetAmigaGuideAttrsA(__reg("a6") struct Library * , __reg("a0") APTR cl , __reg("a1") CONST struct TagItem * attrs ) = "\tjsr\t-108(a6)";
#define SetAmigaGuideAttrsA(cl, attrs) __SetAmigaGuideAttrsA(AmigaGuideBase, (cl), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __SetAmigaGuideAttrs(__reg("a6") struct Library * , __reg("a0") APTR cl , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-108(a6)\n\tmovea.l\t(a7)+,a1";
#define SetAmigaGuideAttrs(cl, ...) __SetAmigaGuideAttrs(AmigaGuideBase, (cl), __VA_ARGS__)
#endif

LONG __GetAmigaGuideAttr(__reg("a6") struct Library * , __reg("d0") Tag tag1 , __reg("a0") APTR cl , __reg("a1") ULONG * storage ) = "\tjsr\t-114(a6)";
#define GetAmigaGuideAttr(tag1, cl, storage) __GetAmigaGuideAttr(AmigaGuideBase, (tag1), (cl), (storage))

LONG __LoadXRef(__reg("a6") struct Library * , __reg("a0") BPTR lock , __reg("a1") STRPTR name ) = "\tjsr\t-126(a6)";
#define LoadXRef(lock, name) __LoadXRef(AmigaGuideBase, (lock), (name))

VOID __ExpungeXRef(__reg("a6") struct Library * ) = "\tjsr\t-132(a6)";
#define ExpungeXRef() __ExpungeXRef(AmigaGuideBase)

APTR __AddAmigaGuideHostA(__reg("a6") struct Library * , __reg("a0") struct Hook * h , __reg("d0") CONST_STRPTR name , __reg("a1") CONST struct TagItem * attrs ) = "\tjsr\t-138(a6)";
#define AddAmigaGuideHostA(h, name, attrs) __AddAmigaGuideHostA(AmigaGuideBase, (h), (name), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __AddAmigaGuideHost(__reg("a6") struct Library * , __reg("a0") struct Hook * h , __reg("d0") CONST_STRPTR name , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-138(a6)\n\tmovea.l\t(a7)+,a1";
#define AddAmigaGuideHost(h, name, ...) __AddAmigaGuideHost(AmigaGuideBase, (h), (name), __VA_ARGS__)
#endif

LONG __RemoveAmigaGuideHostA(__reg("a6") struct Library * , __reg("a0") APTR hh , __reg("a1") CONST struct TagItem * attrs ) = "\tjsr\t-144(a6)";
#define RemoveAmigaGuideHostA(hh, attrs) __RemoveAmigaGuideHostA(AmigaGuideBase, (hh), (attrs))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __RemoveAmigaGuideHost(__reg("a6") struct Library * , __reg("a0") APTR hh , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-144(a6)\n\tmovea.l\t(a7)+,a1";
#define RemoveAmigaGuideHost(hh, ...) __RemoveAmigaGuideHost(AmigaGuideBase, (hh), __VA_ARGS__)
#endif

STRPTR __GetAmigaGuideString(__reg("a6") struct Library * , __reg("d0") LONG id ) = "\tjsr\t-210(a6)";
#define GetAmigaGuideString(id) __GetAmigaGuideString(AmigaGuideBase, (id))

#endif /* !_INLINE_AMIGAGUIDE_H */
