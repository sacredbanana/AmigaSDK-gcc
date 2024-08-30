#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CIAB_H
#define _INLINE_CIAB_H

#ifndef CLIB_CIAB_PROTOS_H
#define CLIB_CIAB_PROTOS_H
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

#ifndef CIAB_BASE_NAME
#define CIAB_BASE_NAME CIABBase
#endif

#define AddICRBVector(iCRBit, interrupt) ({ \
  LONG _AddICRBVector_iCRBit = (iCRBit); \
  struct Interrupt * _AddICRBVector_interrupt = (interrupt); \
  struct Interrupt * _AddICRBVector__re = \
  ({ \
  register struct Library * const __AddICRBVector__bn __asm("a6") = (struct Library *) (CIAB_BASE_NAME);\
  register struct Interrupt * __AddICRBVector__re __asm("d0"); \
  register LONG __AddICRBVector_iCRBit __asm("d0") = (_AddICRBVector_iCRBit); \
  register struct Interrupt * __AddICRBVector_interrupt __asm("a1") = (_AddICRBVector_interrupt); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__AddICRBVector__re) \
  : "r"(__AddICRBVector__bn), "r"(__AddICRBVector_iCRBit), "r"(__AddICRBVector_interrupt) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddICRBVector__re; \
  }); \
  _AddICRBVector__re; \
})

#define RemICRBVector(iCRBit, interrupt) ({ \
  LONG _RemICRBVector_iCRBit = (iCRBit); \
  struct Interrupt * _RemICRBVector_interrupt = (interrupt); \
  { \
  register struct Library * const __RemICRBVector__bn __asm("a6") = (struct Library *) (CIAB_BASE_NAME);\
  register LONG __RemICRBVector_iCRBit __asm("d0") = (_RemICRBVector_iCRBit); \
  register struct Interrupt * __RemICRBVector_interrupt __asm("a1") = (_RemICRBVector_interrupt); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__RemICRBVector__bn), "r"(__RemICRBVector_iCRBit), "r"(__RemICRBVector_interrupt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AbleICRB(mask) ({ \
  LONG _AbleICRB_mask = (mask); \
  WORD _AbleICRB__re = \
  ({ \
  register struct Library * const __AbleICRB__bn __asm("a6") = (struct Library *) (CIAB_BASE_NAME);\
  register WORD __AbleICRB__re __asm("d0"); \
  register LONG __AbleICRB_mask __asm("d0") = (_AbleICRB_mask); \
  __asm volatile ("jsr a6@(-18:W)" \
  : "=r"(__AbleICRB__re) \
  : "r"(__AbleICRB__bn), "r"(__AbleICRB_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AbleICRB__re; \
  }); \
  _AbleICRB__re; \
})

#define SetICRB(mask) ({ \
  LONG _SetICRB_mask = (mask); \
  WORD _SetICRB__re = \
  ({ \
  register struct Library * const __SetICRB__bn __asm("a6") = (struct Library *) (CIAB_BASE_NAME);\
  register WORD __SetICRB__re __asm("d0"); \
  register LONG __SetICRB_mask __asm("d0") = (_SetICRB_mask); \
  __asm volatile ("jsr a6@(-24:W)" \
  : "=r"(__SetICRB__re) \
  : "r"(__SetICRB__bn), "r"(__SetICRB_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetICRB__re; \
  }); \
  _SetICRB__re; \
})

#endif /*  _INLINE_CIAB_H  */
