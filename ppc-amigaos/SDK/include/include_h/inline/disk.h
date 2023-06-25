#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_DISK_H
#define _INLINE_DISK_H

#ifndef CLIB_DISK_PROTOS_H
#define CLIB_DISK_PROTOS_H
#endif

#ifndef  RESOURCES_DISK_H
#include <resources/disk.h>
#endif

#ifndef DISK_BASE_NAME
#define DISK_BASE_NAME DiskBase
#endif

#define AllocUnit(unitNum) ({ \
  LONG _AllocUnit_unitNum = (unitNum); \
  BOOL _AllocUnit__re = \
  ({ \
  register struct DiskResource * const __AllocUnit__bn __asm("a6") = (struct DiskResource *) (DISK_BASE_NAME);\
  register BOOL __AllocUnit__re __asm("d0"); \
  register LONG __AllocUnit_unitNum __asm("d0") = (_AllocUnit_unitNum); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__AllocUnit__re) \
  : "r"(__AllocUnit__bn), "r"(__AllocUnit_unitNum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocUnit__re; \
  }); \
  _AllocUnit__re; \
})

#define FreeUnit(unitNum) ({ \
  LONG _FreeUnit_unitNum = (unitNum); \
  { \
  register struct DiskResource * const __FreeUnit__bn __asm("a6") = (struct DiskResource *) (DISK_BASE_NAME);\
  register LONG __FreeUnit_unitNum __asm("d0") = (_FreeUnit_unitNum); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__FreeUnit__bn), "r"(__FreeUnit_unitNum) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetUnit(unitPointer) ({ \
  struct DiscResourceUnit * _GetUnit_unitPointer = (unitPointer); \
  struct DiscResourceUnit * _GetUnit__re = \
  ({ \
  register struct DiskResource * const __GetUnit__bn __asm("a6") = (struct DiskResource *) (DISK_BASE_NAME);\
  register struct DiscResourceUnit * __GetUnit__re __asm("d0"); \
  register struct DiscResourceUnit * __GetUnit_unitPointer __asm("a1") = (_GetUnit_unitPointer); \
  __asm volatile ("jsr a6@(-18:W)" \
  : "=r"(__GetUnit__re) \
  : "r"(__GetUnit__bn), "r"(__GetUnit_unitPointer) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetUnit__re; \
  }); \
  _GetUnit__re; \
})

#define GiveUnit() ({ \
  register struct DiskResource * const __GiveUnit__bn __asm("a6") = (struct DiskResource *) (DISK_BASE_NAME);\
  __asm volatile ("jsr a6@(-24:W)" \
  : \
  : "r"(__GiveUnit__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define GetUnitID(unitNum) ({ \
  LONG _GetUnitID_unitNum = (unitNum); \
  LONG _GetUnitID__re = \
  ({ \
  register struct DiskResource * const __GetUnitID__bn __asm("a6") = (struct DiskResource *) (DISK_BASE_NAME);\
  register LONG __GetUnitID__re __asm("d0"); \
  register LONG __GetUnitID_unitNum __asm("d0") = (_GetUnitID_unitNum); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GetUnitID__re) \
  : "r"(__GetUnitID__bn), "r"(__GetUnitID_unitNum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetUnitID__re; \
  }); \
  _GetUnitID__re; \
})

#define ReadUnitID(unitNum) ({ \
  LONG _ReadUnitID_unitNum = (unitNum); \
  LONG _ReadUnitID__re = \
  ({ \
  register struct DiskResource * const __ReadUnitID__bn __asm("a6") = (struct DiskResource *) (DISK_BASE_NAME);\
  register LONG __ReadUnitID__re __asm("d0"); \
  register LONG __ReadUnitID_unitNum __asm("d0") = (_ReadUnitID_unitNum); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__ReadUnitID__re) \
  : "r"(__ReadUnitID__bn), "r"(__ReadUnitID_unitNum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadUnitID__re; \
  }); \
  _ReadUnitID__re; \
})

#endif /*  _INLINE_DISK_H  */
