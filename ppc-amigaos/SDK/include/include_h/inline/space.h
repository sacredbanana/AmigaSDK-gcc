#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_SPACE_H
#define _INLINE_SPACE_H

#ifndef CLIB_SPACE_PROTOS_H
#define CLIB_SPACE_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef SPACE_BASE_NAME
#define SPACE_BASE_NAME SpaceBase
#endif

#define SPACE_GetClass() ({ \
  Class * _SPACE_GetClass__re = \
  ({ \
  register struct Library * const __SPACE_GetClass__bn __asm("a6") = (struct Library *) (SPACE_BASE_NAME);\
  register Class * __SPACE_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SPACE_GetClass__re) \
  : "r"(__SPACE_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPACE_GetClass__re; \
  }); \
  _SPACE_GetClass__re; \
})

#endif /*  _INLINE_SPACE_H  */
