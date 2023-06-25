#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LABEL_H
#define _INLINE_LABEL_H

#ifndef CLIB_LABEL_PROTOS_H
#define CLIB_LABEL_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef LABEL_BASE_NAME
#define LABEL_BASE_NAME LabelBase
#endif

#define LABEL_GetClass() ({ \
  Class * _LABEL_GetClass__re = \
  ({ \
  register struct Library * const __LABEL_GetClass__bn __asm("a6") = (struct Library *) (LABEL_BASE_NAME);\
  register Class * __LABEL_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__LABEL_GetClass__re) \
  : "r"(__LABEL_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LABEL_GetClass__re; \
  }); \
  _LABEL_GetClass__re; \
})

#endif /*  _INLINE_LABEL_H  */
