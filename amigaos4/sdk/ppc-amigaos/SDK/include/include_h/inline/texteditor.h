#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_TEXTEDITOR_H
#define _INLINE_TEXTEDITOR_H

#ifndef CLIB_TEXTEDITOR_PROTOS_H
#define CLIB_TEXTEDITOR_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef TEXTEDITOR_BASE_NAME
#define TEXTEDITOR_BASE_NAME TextEditorBase
#endif

#define TEXTEDITOR_GetClass() ({ \
  Class * _TEXTEDITOR_GetClass__re = \
  ({ \
  register struct Library * const __TEXTEDITOR_GetClass__bn __asm("a6") = (struct Library *) (TEXTEDITOR_BASE_NAME);\
  register Class * __TEXTEDITOR_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__TEXTEDITOR_GetClass__re) \
  : "r"(__TEXTEDITOR_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __TEXTEDITOR_GetClass__re; \
  }); \
  _TEXTEDITOR_GetClass__re; \
})

#endif /*  _INLINE_TEXTEDITOR_H  */
