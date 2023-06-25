#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CHECKBOX_H
#define _INLINE_CHECKBOX_H

#ifndef CLIB_CHECKBOX_PROTOS_H
#define CLIB_CHECKBOX_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef CHECKBOX_BASE_NAME
#define CHECKBOX_BASE_NAME CheckBoxBase
#endif

#define CHECKBOX_GetClass() ({ \
  Class * _CHECKBOX_GetClass__re = \
  ({ \
  register struct Library * const __CHECKBOX_GetClass__bn __asm("a6") = (struct Library *) (CHECKBOX_BASE_NAME);\
  register Class * __CHECKBOX_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__CHECKBOX_GetClass__re) \
  : "r"(__CHECKBOX_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CHECKBOX_GetClass__re; \
  }); \
  _CHECKBOX_GetClass__re; \
})

#endif /*  _INLINE_CHECKBOX_H  */
