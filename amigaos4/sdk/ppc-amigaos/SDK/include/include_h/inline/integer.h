#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_INTEGER_H
#define _INLINE_INTEGER_H

#ifndef CLIB_INTEGER_PROTOS_H
#define CLIB_INTEGER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef INTEGER_BASE_NAME
#define INTEGER_BASE_NAME IntegerBase
#endif

#define INTEGER_GetClass() ({ \
  Class * _INTEGER_GetClass__re = \
  ({ \
  register struct Library * const __INTEGER_GetClass__bn __asm("a6") = (struct Library *) (INTEGER_BASE_NAME);\
  register Class * __INTEGER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__INTEGER_GetClass__re) \
  : "r"(__INTEGER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __INTEGER_GetClass__re; \
  }); \
  _INTEGER_GetClass__re; \
})

#endif /*  _INLINE_INTEGER_H  */
