#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_TIMER_H
#define _INLINE_TIMER_H

#ifndef CLIB_TIMER_PROTOS_H
#define CLIB_TIMER_PROTOS_H
#endif

#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif

#ifndef TIMER_BASE_NAME
#define TIMER_BASE_NAME TimerBase
#endif

#define AddTime(dest, src) ({ \
  struct TimeVal * _AddTime_dest = (dest); \
  struct TimeVal * _AddTime_src = (src); \
  { \
  register struct Device * const __AddTime__bn __asm("a6") = (struct Device *) (TIMER_BASE_NAME);\
  register struct TimeVal * __AddTime_dest __asm("a0") = (_AddTime_dest); \
  register struct TimeVal * __AddTime_src __asm("a1") = (_AddTime_src); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__AddTime__bn), "r"(__AddTime_dest), "r"(__AddTime_src) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SubTime(dest, src) ({ \
  struct TimeVal * _SubTime_dest = (dest); \
  struct TimeVal * _SubTime_src = (src); \
  { \
  register struct Device * const __SubTime__bn __asm("a6") = (struct Device *) (TIMER_BASE_NAME);\
  register struct TimeVal * __SubTime_dest __asm("a0") = (_SubTime_dest); \
  register struct TimeVal * __SubTime_src __asm("a1") = (_SubTime_src); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SubTime__bn), "r"(__SubTime_dest), "r"(__SubTime_src) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CmpTime(dest, src) ({ \
  struct TimeVal * _CmpTime_dest = (dest); \
  struct TimeVal * _CmpTime_src = (src); \
  LONG _CmpTime__re = \
  ({ \
  register struct Device * const __CmpTime__bn __asm("a6") = (struct Device *) (TIMER_BASE_NAME);\
  register LONG __CmpTime__re __asm("d0"); \
  register struct TimeVal * __CmpTime_dest __asm("a0") = (_CmpTime_dest); \
  register struct TimeVal * __CmpTime_src __asm("a1") = (_CmpTime_src); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__CmpTime__re) \
  : "r"(__CmpTime__bn), "r"(__CmpTime_dest), "r"(__CmpTime_src) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CmpTime__re; \
  }); \
  _CmpTime__re; \
})

#define ReadEClock(dest) ({ \
  struct EClockVal * _ReadEClock_dest = (dest); \
  ULONG _ReadEClock__re = \
  ({ \
  register struct Device * const __ReadEClock__bn __asm("a6") = (struct Device *) (TIMER_BASE_NAME);\
  register ULONG __ReadEClock__re __asm("d0"); \
  register struct EClockVal * __ReadEClock_dest __asm("a0") = (_ReadEClock_dest); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__ReadEClock__re) \
  : "r"(__ReadEClock__bn), "r"(__ReadEClock_dest) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadEClock__re; \
  }); \
  _ReadEClock__re; \
})

#define GetSysTime(dest) ({ \
  struct TimeVal * _GetSysTime_dest = (dest); \
  { \
  register struct Device * const __GetSysTime__bn __asm("a6") = (struct Device *) (TIMER_BASE_NAME);\
  register struct TimeVal * __GetSysTime_dest __asm("a0") = (_GetSysTime_dest); \
  __asm volatile ("jsr a6@(-66:W)" \
  : \
  : "r"(__GetSysTime__bn), "r"(__GetSysTime_dest) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetUpTime(dest) ({ \
  struct TimeVal * _GetUpTime_dest = (dest); \
  { \
  register struct Device * const __GetUpTime__bn __asm("a6") = (struct Device *) (TIMER_BASE_NAME);\
  register struct TimeVal * __GetUpTime_dest __asm("a0") = (_GetUpTime_dest); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__GetUpTime__bn), "r"(__GetUpTime_dest) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_TIMER_H  */
