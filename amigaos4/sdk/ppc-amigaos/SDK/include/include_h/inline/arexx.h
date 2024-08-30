#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_AREXX_H
#define _INLINE_AREXX_H

#ifndef CLIB_AREXX_PROTOS_H
#define CLIB_AREXX_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef AREXX_BASE_NAME
#define AREXX_BASE_NAME ARexxBase
#endif

#define AREXX_GetClass() ({ \
  Class * _AREXX_GetClass__re = \
  ({ \
  register struct Library * const __AREXX_GetClass__bn __asm("a6") = (struct Library *) (AREXX_BASE_NAME);\
  register Class * __AREXX_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__AREXX_GetClass__re) \
  : "r"(__AREXX_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AREXX_GetClass__re; \
  }); \
  _AREXX_GetClass__re; \
})

#endif /*  _INLINE_AREXX_H  */
