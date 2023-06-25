#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_DTCLASS_H
#define _INLINE_DTCLASS_H

#ifndef CLIB_DTCLASS_PROTOS_H
#define CLIB_DTCLASS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef DTCLASS_BASE_NAME
#define DTCLASS_BASE_NAME DTClassBase
#endif

#define ObtainEngine() ({ \
  Class * _ObtainEngine__re = \
  ({ \
  register struct Library * const __ObtainEngine__bn __asm("a6") = (struct Library *) (DTCLASS_BASE_NAME);\
  register Class * __ObtainEngine__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__ObtainEngine__re) \
  : "r"(__ObtainEngine__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainEngine__re; \
  }); \
  _ObtainEngine__re; \
})

#endif /*  _INLINE_DTCLASS_H  */
