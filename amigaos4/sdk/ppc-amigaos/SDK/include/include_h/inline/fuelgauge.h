#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_FUELGAUGE_H
#define _INLINE_FUELGAUGE_H

#ifndef CLIB_FUELGAUGE_PROTOS_H
#define CLIB_FUELGAUGE_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef FUELGAUGE_BASE_NAME
#define FUELGAUGE_BASE_NAME FuelGaugeBase
#endif

#define FUELGAUGE_GetClass() ({ \
  Class * _FUELGAUGE_GetClass__re = \
  ({ \
  register struct Library * const __FUELGAUGE_GetClass__bn __asm("a6") = (struct Library *) (FUELGAUGE_BASE_NAME);\
  register Class * __FUELGAUGE_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__FUELGAUGE_GetClass__re) \
  : "r"(__FUELGAUGE_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FUELGAUGE_GetClass__re; \
  }); \
  _FUELGAUGE_GetClass__re; \
})

#endif /*  _INLINE_FUELGAUGE_H  */
