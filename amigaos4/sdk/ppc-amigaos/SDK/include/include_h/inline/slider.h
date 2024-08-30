#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_SLIDER_H
#define _INLINE_SLIDER_H

#ifndef CLIB_SLIDER_PROTOS_H
#define CLIB_SLIDER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef SLIDER_BASE_NAME
#define SLIDER_BASE_NAME SliderBase
#endif

#define SLIDER_GetClass() ({ \
  Class * _SLIDER_GetClass__re = \
  ({ \
  register struct Library * const __SLIDER_GetClass__bn __asm("a6") = (struct Library *) (SLIDER_BASE_NAME);\
  register Class * __SLIDER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SLIDER_GetClass__re) \
  : "r"(__SLIDER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SLIDER_GetClass__re; \
  }); \
  _SLIDER_GetClass__re; \
})

#endif /*  _INLINE_SLIDER_H  */
