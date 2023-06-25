#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_GETFILE_H
#define _INLINE_GETFILE_H

#ifndef CLIB_GETFILE_PROTOS_H
#define CLIB_GETFILE_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef GETFILE_BASE_NAME
#define GETFILE_BASE_NAME GetFileBase
#endif

#define GETFILE_GetClass() ({ \
  Class * _GETFILE_GetClass__re = \
  ({ \
  register struct Library * const __GETFILE_GetClass__bn __asm("a6") = (struct Library *) (GETFILE_BASE_NAME);\
  register Class * __GETFILE_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GETFILE_GetClass__re) \
  : "r"(__GETFILE_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GETFILE_GetClass__re; \
  }); \
  _GETFILE_GetClass__re; \
})

#endif /*  _INLINE_GETFILE_H  */
