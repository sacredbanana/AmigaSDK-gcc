#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CIA_H
#define _INLINE_CIA_H

#ifndef CLIB_CIA_PROTOS_H
#define CLIB_CIA_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#define AddICRVector(resource, iCRBit, interrupt) ({ \
  struct Library * _AddICRVector_resource = (resource); \
  LONG _AddICRVector_iCRBit = (iCRBit); \
  struct Interrupt * _AddICRVector_interrupt = (interrupt); \
  struct Interrupt * _AddICRVector__re = \
  ({ \
  register struct Interrupt * __AddICRVector__re __asm("d0"); \
  register struct Library * __AddICRVector_resource __asm("a6") = (_AddICRVector_resource); \
  register LONG __AddICRVector_iCRBit __asm("d0") = (_AddICRVector_iCRBit); \
  register struct Interrupt * __AddICRVector_interrupt __asm("a1") = (_AddICRVector_interrupt); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__AddICRVector__re) \
  : "r"(__AddICRVector_resource), "r"(__AddICRVector_iCRBit), "r"(__AddICRVector_interrupt) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddICRVector__re; \
  }); \
  _AddICRVector__re; \
})

#define RemICRVector(resource, iCRBit, interrupt) ({ \
  struct Library * _RemICRVector_resource = (resource); \
  LONG _RemICRVector_iCRBit = (iCRBit); \
  struct Interrupt * _RemICRVector_interrupt = (interrupt); \
  { \
  register struct Library * __RemICRVector_resource __asm("a6") = (_RemICRVector_resource); \
  register LONG __RemICRVector_iCRBit __asm("d0") = (_RemICRVector_iCRBit); \
  register struct Interrupt * __RemICRVector_interrupt __asm("a1") = (_RemICRVector_interrupt); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__RemICRVector_resource), "r"(__RemICRVector_iCRBit), "r"(__RemICRVector_interrupt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AbleICR(resource, mask) ({ \
  struct Library * _AbleICR_resource = (resource); \
  LONG _AbleICR_mask = (mask); \
  WORD _AbleICR__re = \
  ({ \
  register WORD __AbleICR__re __asm("d0"); \
  register struct Library * __AbleICR_resource __asm("a6") = (_AbleICR_resource); \
  register LONG __AbleICR_mask __asm("d0") = (_AbleICR_mask); \
  __asm volatile ("jsr a6@(-18:W)" \
  : "=r"(__AbleICR__re) \
  : "r"(__AbleICR_resource), "r"(__AbleICR_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AbleICR__re; \
  }); \
  _AbleICR__re; \
})

#define SetICR(resource, mask) ({ \
  struct Library * _SetICR_resource = (resource); \
  LONG _SetICR_mask = (mask); \
  WORD _SetICR__re = \
  ({ \
  register WORD __SetICR__re __asm("d0"); \
  register struct Library * __SetICR_resource __asm("a6") = (_SetICR_resource); \
  register LONG __SetICR_mask __asm("d0") = (_SetICR_mask); \
  __asm volatile ("jsr a6@(-24:W)" \
  : "=r"(__SetICR__re) \
  : "r"(__SetICR_resource), "r"(__SetICR_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetICR__re; \
  }); \
  _SetICR__re; \
})

#endif /*  _INLINE_CIA_H  */
