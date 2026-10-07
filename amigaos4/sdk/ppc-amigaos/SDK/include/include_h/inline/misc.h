#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MISC_H
#define _INLINE_MISC_H

#ifndef CLIB_MISC_PROTOS_H
#define CLIB_MISC_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MISC_BASE_NAME
#define MISC_BASE_NAME MiscBase
#endif

#define AllocMiscResource(unitNum, name) ({ \
  ULONG _AllocMiscResource_unitNum = (unitNum); \
  CONST_STRPTR _AllocMiscResource_name = (name); \
  CONST_STRPTR _AllocMiscResource__re = \
  ({ \
  register struct Library * const __AllocMiscResource__bn __asm("a6") = (struct Library *) (MISC_BASE_NAME);\
  register CONST_STRPTR __AllocMiscResource__re __asm("d0"); \
  register ULONG __AllocMiscResource_unitNum __asm("d0") = (_AllocMiscResource_unitNum); \
  register CONST_STRPTR __AllocMiscResource_name __asm("a1") = (_AllocMiscResource_name); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__AllocMiscResource__re) \
  : "r"(__AllocMiscResource__bn), "r"(__AllocMiscResource_unitNum), "r"(__AllocMiscResource_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocMiscResource__re; \
  }); \
  _AllocMiscResource__re; \
})

#define FreeMiscResource(unitNum) ({ \
  ULONG _FreeMiscResource_unitNum = (unitNum); \
  { \
  register struct Library * const __FreeMiscResource__bn __asm("a6") = (struct Library *) (MISC_BASE_NAME);\
  register ULONG __FreeMiscResource_unitNum __asm("d0") = (_FreeMiscResource_unitNum); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__FreeMiscResource__bn), "r"(__FreeMiscResource_unitNum) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_MISC_H  */
