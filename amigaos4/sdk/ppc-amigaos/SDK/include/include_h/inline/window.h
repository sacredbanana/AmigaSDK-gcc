#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_WINDOW_H
#define _INLINE_WINDOW_H

#ifndef CLIB_WINDOW_PROTOS_H
#define CLIB_WINDOW_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef WINDOW_BASE_NAME
#define WINDOW_BASE_NAME WindowBase
#endif

#define WINDOW_GetClass() ({ \
  Class * _WINDOW_GetClass__re = \
  ({ \
  register struct Library * const __WINDOW_GetClass__bn __asm("a6") = (struct Library *) (WINDOW_BASE_NAME);\
  register Class * __WINDOW_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__WINDOW_GetClass__re) \
  : "r"(__WINDOW_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WINDOW_GetClass__re; \
  }); \
  _WINDOW_GetClass__re; \
})

#endif /*  _INLINE_WINDOW_H  */
