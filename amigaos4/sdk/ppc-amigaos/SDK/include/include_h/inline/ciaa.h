#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CIAA_H
#define _INLINE_CIAA_H

#ifndef CLIB_CIAA_PROTOS_H
#define CLIB_CIAA_PROTOS_H
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

#ifndef CIAA_BASE_NAME
#define CIAA_BASE_NAME CIAABase
#endif

#define AddICRAVector(iCRBit, interrupt) ({ \
  LONG _AddICRAVector_iCRBit = (iCRBit); \
  struct Interrupt * _AddICRAVector_interrupt = (interrupt); \
  struct Interrupt * _AddICRAVector__re = \
  ({ \
  register struct Library * const __AddICRAVector__bn __asm("a6") = (struct Library *) (CIAA_BASE_NAME);\
  register struct Interrupt * __AddICRAVector__re __asm("d0"); \
  register LONG __AddICRAVector_iCRBit __asm("d0") = (_AddICRAVector_iCRBit); \
  register struct Interrupt * __AddICRAVector_interrupt __asm("a1") = (_AddICRAVector_interrupt); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__AddICRAVector__re) \
  : "r"(__AddICRAVector__bn), "r"(__AddICRAVector_iCRBit), "r"(__AddICRAVector_interrupt) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddICRAVector__re; \
  }); \
  _AddICRAVector__re; \
})

#define RemICRAVector(iCRBit, interrupt) ({ \
  LONG _RemICRAVector_iCRBit = (iCRBit); \
  struct Interrupt * _RemICRAVector_interrupt = (interrupt); \
  { \
  register struct Library * const __RemICRAVector__bn __asm("a6") = (struct Library *) (CIAA_BASE_NAME);\
  register LONG __RemICRAVector_iCRBit __asm("d0") = (_RemICRAVector_iCRBit); \
  register struct Interrupt * __RemICRAVector_interrupt __asm("a1") = (_RemICRAVector_interrupt); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__RemICRAVector__bn), "r"(__RemICRAVector_iCRBit), "r"(__RemICRAVector_interrupt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AbleICRA(mask) ({ \
  LONG _AbleICRA_mask = (mask); \
  WORD _AbleICRA__re = \
  ({ \
  register struct Library * const __AbleICRA__bn __asm("a6") = (struct Library *) (CIAA_BASE_NAME);\
  register WORD __AbleICRA__re __asm("d0"); \
  register LONG __AbleICRA_mask __asm("d0") = (_AbleICRA_mask); \
  __asm volatile ("jsr a6@(-18:W)" \
  : "=r"(__AbleICRA__re) \
  : "r"(__AbleICRA__bn), "r"(__AbleICRA_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AbleICRA__re; \
  }); \
  _AbleICRA__re; \
})

#define SetICRA(mask) ({ \
  LONG _SetICRA_mask = (mask); \
  WORD _SetICRA__re = \
  ({ \
  register struct Library * const __SetICRA__bn __asm("a6") = (struct Library *) (CIAA_BASE_NAME);\
  register WORD __SetICRA__re __asm("d0"); \
  register LONG __SetICRA_mask __asm("d0") = (_SetICRA_mask); \
  __asm volatile ("jsr a6@(-24:W)" \
  : "=r"(__SetICRA__re) \
  : "r"(__SetICRA__bn), "r"(__SetICRA_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetICRA__re; \
  }); \
  _SetICRA__re; \
})

#endif /*  _INLINE_CIAA_H  */
