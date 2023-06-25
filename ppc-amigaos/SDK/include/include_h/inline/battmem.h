#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_BATTMEM_H
#define _INLINE_BATTMEM_H

#ifndef CLIB_BATTMEM_PROTOS_H
#define CLIB_BATTMEM_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef BATTMEM_BASE_NAME
#define BATTMEM_BASE_NAME BattMemBase
#endif

#define ObtainBattSemaphore() ({ \
  register struct Library * const __ObtainBattSemaphore__bn __asm("a6") = (struct Library *) (BATTMEM_BASE_NAME);\
  __asm volatile ("jsr a6@(-6:W)" \
  : \
  : "r"(__ObtainBattSemaphore__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define ReleaseBattSemaphore() ({ \
  register struct Library * const __ReleaseBattSemaphore__bn __asm("a6") = (struct Library *) (BATTMEM_BASE_NAME);\
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__ReleaseBattSemaphore__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define ReadBattMem(buffer, offset, length) ({ \
  APTR _ReadBattMem_buffer = (buffer); \
  ULONG _ReadBattMem_offset = (offset); \
  ULONG _ReadBattMem_length = (length); \
  ULONG _ReadBattMem__re = \
  ({ \
  register struct Library * const __ReadBattMem__bn __asm("a6") = (struct Library *) (BATTMEM_BASE_NAME);\
  register ULONG __ReadBattMem__re __asm("d0"); \
  register APTR __ReadBattMem_buffer __asm("a0") = (_ReadBattMem_buffer); \
  register ULONG __ReadBattMem_offset __asm("d0") = (_ReadBattMem_offset); \
  register ULONG __ReadBattMem_length __asm("d1") = (_ReadBattMem_length); \
  __asm volatile ("jsr a6@(-18:W)" \
  : "=r"(__ReadBattMem__re) \
  : "r"(__ReadBattMem__bn), "r"(__ReadBattMem_buffer), "r"(__ReadBattMem_offset), "r"(__ReadBattMem_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadBattMem__re; \
  }); \
  _ReadBattMem__re; \
})

#define WriteBattMem(buffer, offset, length) ({ \
  const APTR _WriteBattMem_buffer = (buffer); \
  ULONG _WriteBattMem_offset = (offset); \
  ULONG _WriteBattMem_length = (length); \
  ULONG _WriteBattMem__re = \
  ({ \
  register struct Library * const __WriteBattMem__bn __asm("a6") = (struct Library *) (BATTMEM_BASE_NAME);\
  register ULONG __WriteBattMem__re __asm("d0"); \
  register const APTR __WriteBattMem_buffer __asm("a0") = (_WriteBattMem_buffer); \
  register ULONG __WriteBattMem_offset __asm("d0") = (_WriteBattMem_offset); \
  register ULONG __WriteBattMem_length __asm("d1") = (_WriteBattMem_length); \
  __asm volatile ("jsr a6@(-24:W)" \
  : "=r"(__WriteBattMem__re) \
  : "r"(__WriteBattMem__bn), "r"(__WriteBattMem_buffer), "r"(__WriteBattMem_offset), "r"(__WriteBattMem_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteBattMem__re; \
  }); \
  _WriteBattMem__re; \
})

#endif /*  _INLINE_BATTMEM_H  */
