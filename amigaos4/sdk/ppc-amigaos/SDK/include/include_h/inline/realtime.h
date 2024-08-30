#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_REALTIME_H
#define _INLINE_REALTIME_H

#ifndef CLIB_REALTIME_PROTOS_H
#define CLIB_REALTIME_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  LIBRARIES_REALTIME_H
#include <libraries/realtime.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef REALTIME_BASE_NAME
#define REALTIME_BASE_NAME RealTimeBase
#endif

#define LockRealTime(lockType) ({ \
  ULONG _LockRealTime_lockType = (lockType); \
  APTR _LockRealTime__re = \
  ({ \
  register struct RealTimeBase * const __LockRealTime__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register APTR __LockRealTime__re __asm("d0"); \
  register ULONG __LockRealTime_lockType __asm("d0") = (_LockRealTime_lockType); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__LockRealTime__re) \
  : "r"(__LockRealTime__bn), "r"(__LockRealTime_lockType) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockRealTime__re; \
  }); \
  _LockRealTime__re; \
})

#define UnlockRealTime(lock) ({ \
  APTR _UnlockRealTime_lock = (lock); \
  { \
  register struct RealTimeBase * const __UnlockRealTime__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register APTR __UnlockRealTime_lock __asm("a0") = (_UnlockRealTime_lock); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__UnlockRealTime__bn), "r"(__UnlockRealTime_lock) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CreatePlayerA(tagList) ({ \
  const struct TagItem * _CreatePlayerA_tagList = (tagList); \
  struct Player * _CreatePlayerA__re = \
  ({ \
  register struct RealTimeBase * const __CreatePlayerA__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register struct Player * __CreatePlayerA__re __asm("d0"); \
  register const struct TagItem * __CreatePlayerA_tagList __asm("a0") = (_CreatePlayerA_tagList); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__CreatePlayerA__re) \
  : "r"(__CreatePlayerA__bn), "r"(__CreatePlayerA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreatePlayerA__re; \
  }); \
  _CreatePlayerA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Player * ___CreatePlayer(struct RealTimeBase * RealTimeBase, Tag tagList, ...)
{
  return CreatePlayerA((const struct TagItem *) &tagList);
}

#define CreatePlayer(tags...) ___CreatePlayer(REALTIME_BASE_NAME, tags)
#endif

#define DeletePlayer(player) ({ \
  struct Player * _DeletePlayer_player = (player); \
  { \
  register struct RealTimeBase * const __DeletePlayer__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register struct Player * __DeletePlayer_player __asm("a0") = (_DeletePlayer_player); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__DeletePlayer__bn), "r"(__DeletePlayer_player) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetPlayerAttrsA(player, tagList) ({ \
  struct Player * _SetPlayerAttrsA_player = (player); \
  const struct TagItem * _SetPlayerAttrsA_tagList = (tagList); \
  BOOL _SetPlayerAttrsA__re = \
  ({ \
  register struct RealTimeBase * const __SetPlayerAttrsA__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register BOOL __SetPlayerAttrsA__re __asm("d0"); \
  register struct Player * __SetPlayerAttrsA_player __asm("a0") = (_SetPlayerAttrsA_player); \
  register const struct TagItem * __SetPlayerAttrsA_tagList __asm("a1") = (_SetPlayerAttrsA_tagList); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__SetPlayerAttrsA__re) \
  : "r"(__SetPlayerAttrsA__bn), "r"(__SetPlayerAttrsA_player), "r"(__SetPlayerAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetPlayerAttrsA__re; \
  }); \
  _SetPlayerAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___SetPlayerAttrs(struct RealTimeBase * RealTimeBase, struct Player * player, Tag tagList, ...)
{
  return SetPlayerAttrsA(player, (const struct TagItem *) &tagList);
}

#define SetPlayerAttrs(player...) ___SetPlayerAttrs(REALTIME_BASE_NAME, player)
#endif

#define SetConductorState(player, state, time) ({ \
  struct Player * _SetConductorState_player = (player); \
  ULONG _SetConductorState_state = (state); \
  LONG _SetConductorState_time = (time); \
  LONG _SetConductorState__re = \
  ({ \
  register struct RealTimeBase * const __SetConductorState__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register LONG __SetConductorState__re __asm("d0"); \
  register struct Player * __SetConductorState_player __asm("a0") = (_SetConductorState_player); \
  register ULONG __SetConductorState_state __asm("d0") = (_SetConductorState_state); \
  register LONG __SetConductorState_time __asm("d1") = (_SetConductorState_time); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__SetConductorState__re) \
  : "r"(__SetConductorState__bn), "r"(__SetConductorState_player), "r"(__SetConductorState_state), "r"(__SetConductorState_time) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetConductorState__re; \
  }); \
  _SetConductorState__re; \
})

#define ExternalSync(player, minTime, maxTime) ({ \
  struct Player * _ExternalSync_player = (player); \
  LONG _ExternalSync_minTime = (minTime); \
  LONG _ExternalSync_maxTime = (maxTime); \
  BOOL _ExternalSync__re = \
  ({ \
  register struct RealTimeBase * const __ExternalSync__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register BOOL __ExternalSync__re __asm("d0"); \
  register struct Player * __ExternalSync_player __asm("a0") = (_ExternalSync_player); \
  register LONG __ExternalSync_minTime __asm("d0") = (_ExternalSync_minTime); \
  register LONG __ExternalSync_maxTime __asm("d1") = (_ExternalSync_maxTime); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__ExternalSync__re) \
  : "r"(__ExternalSync__bn), "r"(__ExternalSync_player), "r"(__ExternalSync_minTime), "r"(__ExternalSync_maxTime) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ExternalSync__re; \
  }); \
  _ExternalSync__re; \
})

#define NextConductor(previousConductor) ({ \
  const struct Conductor * _NextConductor_previousConductor = (previousConductor); \
  struct Conductor * _NextConductor__re = \
  ({ \
  register struct RealTimeBase * const __NextConductor__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register struct Conductor * __NextConductor__re __asm("d0"); \
  register const struct Conductor * __NextConductor_previousConductor __asm("a0") = (_NextConductor_previousConductor); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__NextConductor__re) \
  : "r"(__NextConductor__bn), "r"(__NextConductor_previousConductor) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NextConductor__re; \
  }); \
  _NextConductor__re; \
})

#define FindConductor(name) ({ \
  CONST_STRPTR _FindConductor_name = (name); \
  struct Conductor * _FindConductor__re = \
  ({ \
  register struct RealTimeBase * const __FindConductor__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register struct Conductor * __FindConductor__re __asm("d0"); \
  register CONST_STRPTR __FindConductor_name __asm("a0") = (_FindConductor_name); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__FindConductor__re) \
  : "r"(__FindConductor__bn), "r"(__FindConductor_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindConductor__re; \
  }); \
  _FindConductor__re; \
})

#define GetPlayerAttrsA(player, tagList) ({ \
  const struct Player * _GetPlayerAttrsA_player = (player); \
  const struct TagItem * _GetPlayerAttrsA_tagList = (tagList); \
  ULONG _GetPlayerAttrsA__re = \
  ({ \
  register struct RealTimeBase * const __GetPlayerAttrsA__bn __asm("a6") = (struct RealTimeBase *) (REALTIME_BASE_NAME);\
  register ULONG __GetPlayerAttrsA__re __asm("d0"); \
  register const struct Player * __GetPlayerAttrsA_player __asm("a0") = (_GetPlayerAttrsA_player); \
  register const struct TagItem * __GetPlayerAttrsA_tagList __asm("a1") = (_GetPlayerAttrsA_tagList); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__GetPlayerAttrsA__re) \
  : "r"(__GetPlayerAttrsA__bn), "r"(__GetPlayerAttrsA_player), "r"(__GetPlayerAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetPlayerAttrsA__re; \
  }); \
  _GetPlayerAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___GetPlayerAttrs(struct RealTimeBase * RealTimeBase, const struct Player * player, Tag tagList, ...)
{
  return GetPlayerAttrsA(player, (const struct TagItem *) &tagList);
}

#define GetPlayerAttrs(player...) ___GetPlayerAttrs(REALTIME_BASE_NAME, player)
#endif

#endif /*  _INLINE_REALTIME_H  */
