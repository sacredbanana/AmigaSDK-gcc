/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_REALTIME_H
#define _INLINE_REALTIME_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __LockRealTime(__reg("a6") struct Library * , __reg("d0") ULONG lockType ) = "\tjsr\t-30(a6)";
#define LockRealTime(lockType) __LockRealTime(RealTimeBase, (lockType))

VOID __UnlockRealTime(__reg("a6") struct Library * , __reg("a0") APTR lock ) = "\tjsr\t-36(a6)";
#define UnlockRealTime(lock) __UnlockRealTime(RealTimeBase, (lock))

struct Player * __CreatePlayerA(__reg("a6") struct Library * , __reg("a0") CONST struct TagItem * tagList ) = "\tjsr\t-42(a6)";
#define CreatePlayerA(tagList) __CreatePlayerA(RealTimeBase, (tagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct Player * __CreatePlayer(__reg("a6") struct Library * , Tag tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-42(a6)\n\tmovea.l\t(a7)+,a0";
#define CreatePlayer(...) __CreatePlayer(RealTimeBase, __VA_ARGS__)
#endif

VOID __DeletePlayer(__reg("a6") struct Library * , __reg("a0") struct Player * player ) = "\tjsr\t-48(a6)";
#define DeletePlayer(player) __DeletePlayer(RealTimeBase, (player))

BOOL __SetPlayerAttrsA(__reg("a6") struct Library * , __reg("a0") struct Player * player , __reg("a1") CONST struct TagItem * tagList ) = "\tjsr\t-54(a6)";
#define SetPlayerAttrsA(player, tagList) __SetPlayerAttrsA(RealTimeBase, (player), (tagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __SetPlayerAttrs(__reg("a6") struct Library * , __reg("a0") struct Player * player , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-54(a6)\n\tmovea.l\t(a7)+,a1";
#define SetPlayerAttrs(player, ...) __SetPlayerAttrs(RealTimeBase, (player), __VA_ARGS__)
#endif

LONG __SetConductorState(__reg("a6") struct Library * , __reg("a0") struct Player * player , __reg("d0") ULONG state , __reg("d1") LONG time ) = "\tjsr\t-60(a6)";
#define SetConductorState(player, state, time) __SetConductorState(RealTimeBase, (player), (state), (time))

BOOL __ExternalSync(__reg("a6") struct Library * , __reg("a0") struct Player * player , __reg("d0") LONG minTime , __reg("d1") LONG maxTime ) = "\tjsr\t-66(a6)";
#define ExternalSync(player, minTime, maxTime) __ExternalSync(RealTimeBase, (player), (minTime), (maxTime))

struct Conductor * __NextConductor(__reg("a6") struct Library * , __reg("a0") CONST struct Conductor * previousConductor ) = "\tjsr\t-72(a6)";
#define NextConductor(previousConductor) __NextConductor(RealTimeBase, (previousConductor))

struct Conductor * __FindConductor(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR name ) = "\tjsr\t-78(a6)";
#define FindConductor(name) __FindConductor(RealTimeBase, (name))

ULONG __GetPlayerAttrsA(__reg("a6") struct Library * , __reg("a0") struct Player * player , __reg("a1") CONST struct TagItem * tagList ) = "\tjsr\t-84(a6)";
#define GetPlayerAttrsA(player, tagList) __GetPlayerAttrsA(RealTimeBase, (player), (tagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __GetPlayerAttrs(__reg("a6") struct Library * , __reg("a0") struct Player * player , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-84(a6)\n\tmovea.l\t(a7)+,a1";
#define GetPlayerAttrs(player, ...) __GetPlayerAttrs(RealTimeBase, (player), __VA_ARGS__)
#endif

#endif /* !_INLINE_REALTIME_H */
