#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_POTGO_H
#define _INLINE_POTGO_H

#ifndef CLIB_POTGO_PROTOS_H
#define CLIB_POTGO_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef POTGO_BASE_NAME
#define POTGO_BASE_NAME PotgoBase
#endif

#define AllocPotBits(bits) ({ \
  ULONG _AllocPotBits_bits = (bits); \
  UWORD _AllocPotBits__re = \
  ({ \
  register struct Library * const __AllocPotBits__bn __asm("a6") = (struct Library *) (POTGO_BASE_NAME);\
  register UWORD __AllocPotBits__re __asm("d0"); \
  register ULONG __AllocPotBits_bits __asm("d0") = (_AllocPotBits_bits); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__AllocPotBits__re) \
  : "r"(__AllocPotBits__bn), "r"(__AllocPotBits_bits) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocPotBits__re; \
  }); \
  _AllocPotBits__re; \
})

#define FreePotBits(bits) ({ \
  ULONG _FreePotBits_bits = (bits); \
  { \
  register struct Library * const __FreePotBits__bn __asm("a6") = (struct Library *) (POTGO_BASE_NAME);\
  register ULONG __FreePotBits_bits __asm("d0") = (_FreePotBits_bits); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__FreePotBits__bn), "r"(__FreePotBits_bits) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WritePotgo(word, mask) ({ \
  ULONG _WritePotgo_word = (word); \
  ULONG _WritePotgo_mask = (mask); \
  { \
  register struct Library * const __WritePotgo__bn __asm("a6") = (struct Library *) (POTGO_BASE_NAME);\
  register ULONG __WritePotgo_word __asm("d0") = (_WritePotgo_word); \
  register ULONG __WritePotgo_mask __asm("d1") = (_WritePotgo_mask); \
  __asm volatile ("jsr a6@(-18:W)" \
  : \
  : "r"(__WritePotgo__bn), "r"(__WritePotgo_word), "r"(__WritePotgo_mask) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_POTGO_H  */
