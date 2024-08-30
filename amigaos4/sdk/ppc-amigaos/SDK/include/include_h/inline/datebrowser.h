#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_DATEBROWSER_H
#define _INLINE_DATEBROWSER_H

#ifndef CLIB_DATEBROWSER_PROTOS_H
#define CLIB_DATEBROWSER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef DATEBROWSER_BASE_NAME
#define DATEBROWSER_BASE_NAME DateBrowserBase
#endif

#define DATEBROWSER_GetClass() ({ \
  Class * _DATEBROWSER_GetClass__re = \
  ({ \
  register struct Library * const __DATEBROWSER_GetClass__bn __asm("a6") = (struct Library *) (DATEBROWSER_BASE_NAME);\
  register Class * __DATEBROWSER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__DATEBROWSER_GetClass__re) \
  : "r"(__DATEBROWSER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DATEBROWSER_GetClass__re; \
  }); \
  _DATEBROWSER_GetClass__re; \
})

#define JulianWeekDay(day, month, year) ({ \
  ULONG _JulianWeekDay_day = (day); \
  ULONG _JulianWeekDay_month = (month); \
  LONG _JulianWeekDay_year = (year); \
  UWORD _JulianWeekDay__re = \
  ({ \
  register struct Library * const __JulianWeekDay__bn __asm("a6") = (struct Library *) (DATEBROWSER_BASE_NAME);\
  register UWORD __JulianWeekDay__re __asm("d0"); \
  register ULONG __JulianWeekDay_day __asm("d0") = (_JulianWeekDay_day); \
  register ULONG __JulianWeekDay_month __asm("d1") = (_JulianWeekDay_month); \
  register LONG __JulianWeekDay_year __asm("d2") = (_JulianWeekDay_year); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__JulianWeekDay__re) \
  : "r"(__JulianWeekDay__bn), "r"(__JulianWeekDay_day), "r"(__JulianWeekDay_month), "r"(__JulianWeekDay_year) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __JulianWeekDay__re; \
  }); \
  _JulianWeekDay__re; \
})

#define JulianMonthDays(month, year) ({ \
  ULONG _JulianMonthDays_month = (month); \
  LONG _JulianMonthDays_year = (year); \
  UWORD _JulianMonthDays__re = \
  ({ \
  register struct Library * const __JulianMonthDays__bn __asm("a6") = (struct Library *) (DATEBROWSER_BASE_NAME);\
  register UWORD __JulianMonthDays__re __asm("d0"); \
  register ULONG __JulianMonthDays_month __asm("d0") = (_JulianMonthDays_month); \
  register LONG __JulianMonthDays_year __asm("d1") = (_JulianMonthDays_year); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__JulianMonthDays__re) \
  : "r"(__JulianMonthDays__bn), "r"(__JulianMonthDays_month), "r"(__JulianMonthDays_year) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __JulianMonthDays__re; \
  }); \
  _JulianMonthDays__re; \
})

#define JulianLeapYear(year) ({ \
  LONG _JulianLeapYear_year = (year); \
  BOOL _JulianLeapYear__re = \
  ({ \
  register struct Library * const __JulianLeapYear__bn __asm("a6") = (struct Library *) (DATEBROWSER_BASE_NAME);\
  register BOOL __JulianLeapYear__re __asm("d0"); \
  register LONG __JulianLeapYear_year __asm("d0") = (_JulianLeapYear_year); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__JulianLeapYear__re) \
  : "r"(__JulianLeapYear__bn), "r"(__JulianLeapYear_year) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __JulianLeapYear__re; \
  }); \
  _JulianLeapYear__re; \
})

#endif /*  _INLINE_DATEBROWSER_H  */
