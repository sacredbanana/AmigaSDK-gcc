#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_SKETCHBOARD_H
#define _INLINE_SKETCHBOARD_H

#ifndef CLIB_SKETCHBOARD_PROTOS_H
#define CLIB_SKETCHBOARD_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef SKETCHBOARD_BASE_NAME
#define SKETCHBOARD_BASE_NAME SketchBoardBase
#endif

#define SKETCHBOARD_GetClass() ({ \
  Class * _SKETCHBOARD_GetClass__re = \
  ({ \
  register struct Library * const __SKETCHBOARD_GetClass__bn __asm("a6") = (struct Library *) (SKETCHBOARD_BASE_NAME);\
  register Class * __SKETCHBOARD_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SKETCHBOARD_GetClass__re) \
  : "r"(__SKETCHBOARD_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SKETCHBOARD_GetClass__re; \
  }); \
  _SKETCHBOARD_GetClass__re; \
})

#endif /*  _INLINE_SKETCHBOARD_H  */
