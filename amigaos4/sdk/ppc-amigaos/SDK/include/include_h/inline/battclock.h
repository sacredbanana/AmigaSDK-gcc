#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_BATTCLOCK_H
#define _INLINE_BATTCLOCK_H

#ifndef CLIB_BATTCLOCK_PROTOS_H
#define CLIB_BATTCLOCK_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef BATTCLOCK_BASE_NAME
#define BATTCLOCK_BASE_NAME BattClockBase
#endif

#define ResetBattClock() ({ \
  register struct Library * const __ResetBattClock__bn __asm("a6") = (struct Library *) (BATTCLOCK_BASE_NAME);\
  __asm volatile ("jsr a6@(-6:W)" \
  : \
  : "r"(__ResetBattClock__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define ReadBattClock() ({ \
  ULONG _ReadBattClock__re = \
  ({ \
  register struct Library * const __ReadBattClock__bn __asm("a6") = (struct Library *) (BATTCLOCK_BASE_NAME);\
  register ULONG __ReadBattClock__re __asm("d0"); \
  __asm volatile ("jsr a6@(-12:W)" \
  : "=r"(__ReadBattClock__re) \
  : "r"(__ReadBattClock__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadBattClock__re; \
  }); \
  _ReadBattClock__re; \
})

#define WriteBattClock(time) ({ \
  ULONG _WriteBattClock_time = (time); \
  { \
  register struct Library * const __WriteBattClock__bn __asm("a6") = (struct Library *) (BATTCLOCK_BASE_NAME);\
  register ULONG __WriteBattClock_time __asm("d0") = (_WriteBattClock_time); \
  __asm volatile ("jsr a6@(-18:W)" \
  : \
  : "r"(__WriteBattClock__bn), "r"(__WriteBattClock_time) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_BATTCLOCK_H  */
