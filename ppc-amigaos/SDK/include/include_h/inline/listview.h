#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LISTVIEW_H
#define _INLINE_LISTVIEW_H

#ifndef CLIB_LISTVIEW_PROTOS_H
#define CLIB_LISTVIEW_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef LISTVIEW_BASE_NAME
#define LISTVIEW_BASE_NAME ListViewBase
#endif

#define LISTVIEW_GetClass() ({ \
  Class * _LISTVIEW_GetClass__re = \
  ({ \
  register struct Library * const __LISTVIEW_GetClass__bn __asm("a6") = (struct Library *) (LISTVIEW_BASE_NAME);\
  register Class * __LISTVIEW_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__LISTVIEW_GetClass__re) \
  : "r"(__LISTVIEW_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LISTVIEW_GetClass__re; \
  }); \
  _LISTVIEW_GetClass__re; \
})

#endif /*  _INLINE_LISTVIEW_H  */
