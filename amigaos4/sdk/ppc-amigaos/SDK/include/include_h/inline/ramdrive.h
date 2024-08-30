#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_RAMDRIVE_H
#define _INLINE_RAMDRIVE_H

#ifndef CLIB_RAMDRIVE_PROTOS_H
#define CLIB_RAMDRIVE_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef RAMDRIVE_BASE_NAME
#define RAMDRIVE_BASE_NAME RamdriveDevice
#endif

#define KillRAD0() ({ \
  STRPTR _KillRAD0__re = \
  ({ \
  register struct Device * const __KillRAD0__bn __asm("a6") = (struct Device *) (RAMDRIVE_BASE_NAME);\
  register STRPTR __KillRAD0__re __asm("d0"); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__KillRAD0__re) \
  : "r"(__KillRAD0__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __KillRAD0__re; \
  }); \
  _KillRAD0__re; \
})

#define KillRAD(unit) ({ \
  ULONG _KillRAD_unit = (unit); \
  STRPTR _KillRAD__re = \
  ({ \
  register struct Device * const __KillRAD__bn __asm("a6") = (struct Device *) (RAMDRIVE_BASE_NAME);\
  register STRPTR __KillRAD__re __asm("d0"); \
  register ULONG __KillRAD_unit __asm("d0") = (_KillRAD_unit); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__KillRAD__re) \
  : "r"(__KillRAD__bn), "r"(__KillRAD_unit) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __KillRAD__re; \
  }); \
  _KillRAD__re; \
})

#endif /*  _INLINE_RAMDRIVE_H  */
