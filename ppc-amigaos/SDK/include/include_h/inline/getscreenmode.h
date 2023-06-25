#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_GETSCREENMODE_H
#define _INLINE_GETSCREENMODE_H

#ifndef CLIB_GETSCREENMODE_PROTOS_H
#define CLIB_GETSCREENMODE_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef GETSCREENMODE_BASE_NAME
#define GETSCREENMODE_BASE_NAME GetScreenModeBase
#endif

#define GETSCREENMODE_GetClass() ({ \
  Class * _GETSCREENMODE_GetClass__re = \
  ({ \
  register struct Library * const __GETSCREENMODE_GetClass__bn __asm("a6") = (struct Library *) (GETSCREENMODE_BASE_NAME);\
  register Class * __GETSCREENMODE_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GETSCREENMODE_GetClass__re) \
  : "r"(__GETSCREENMODE_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GETSCREENMODE_GetClass__re; \
  }); \
  _GETSCREENMODE_GetClass__re; \
})

#endif /*  _INLINE_GETSCREENMODE_H  */
