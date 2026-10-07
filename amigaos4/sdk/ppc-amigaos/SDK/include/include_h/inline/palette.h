#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_PALETTE_H
#define _INLINE_PALETTE_H

#ifndef CLIB_PALETTE_PROTOS_H
#define CLIB_PALETTE_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef PALETTE_BASE_NAME
#define PALETTE_BASE_NAME PaletteBase
#endif

#define PALETTE_GetClass() ({ \
  Class * _PALETTE_GetClass__re = \
  ({ \
  register struct Library * const __PALETTE_GetClass__bn __asm("a6") = (struct Library *) (PALETTE_BASE_NAME);\
  register Class * __PALETTE_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__PALETTE_GetClass__re) \
  : "r"(__PALETTE_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PALETTE_GetClass__re; \
  }); \
  _PALETTE_GetClass__re; \
})

#endif /*  _INLINE_PALETTE_H  */
