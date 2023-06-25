#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_BEVEL_H
#define _INLINE_BEVEL_H

#ifndef CLIB_BEVEL_PROTOS_H
#define CLIB_BEVEL_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef BEVEL_BASE_NAME
#define BEVEL_BASE_NAME BevelBase
#endif

#define BEVEL_GetClass() ({ \
  Class * _BEVEL_GetClass__re = \
  ({ \
  register struct Library * const __BEVEL_GetClass__bn __asm("a6") = (struct Library *) (BEVEL_BASE_NAME);\
  register Class * __BEVEL_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__BEVEL_GetClass__re) \
  : "r"(__BEVEL_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BEVEL_GetClass__re; \
  }); \
  _BEVEL_GetClass__re; \
})

#endif /*  _INLINE_BEVEL_H  */
