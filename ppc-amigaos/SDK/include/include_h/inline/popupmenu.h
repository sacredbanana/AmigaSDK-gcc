#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_POPUPMENU_H
#define _INLINE_POPUPMENU_H

#ifndef CLIB_POPUPMENU_PROTOS_H
#define CLIB_POPUPMENU_PROTOS_H
#endif

#ifndef  CLASSES_POPUPMENU_H
#include <classes/popupmenu.h>
#endif

#ifndef POPUPMENU_BASE_NAME
#define POPUPMENU_BASE_NAME PopupMenuBase
#endif

#define POPUPMENU_GetClass() ({ \
  Class * _POPUPMENU_GetClass__re = \
  ({ \
  register struct PopupMenuBase * const __POPUPMENU_GetClass__bn __asm("a6") = (struct PopupMenuBase *) (POPUPMENU_BASE_NAME);\
  register Class * __POPUPMENU_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__POPUPMENU_GetClass__re) \
  : "r"(__POPUPMENU_GetClass__bn)  \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __POPUPMENU_GetClass__re; \
  }); \
  _POPUPMENU_GetClass__re; \
})

#define POPUPMENU_GetItemClass() ({ \
  Class * _POPUPMENU_GetItemClass__re = \
  ({ \
  register struct PopupMenuBase * const __POPUPMENU_GetItemClass__bn __asm("a6") = (struct PopupMenuBase *) (POPUPMENU_BASE_NAME);\
  register Class * __POPUPMENU_GetItemClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__POPUPMENU_GetItemClass__re) \
  : "r"(__POPUPMENU_GetItemClass__bn)  \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __POPUPMENU_GetItemClass__re; \
  }); \
  _POPUPMENU_GetItemClass__re; \
})

#define POPUPMENU_MakeMXListA(ids) ({ \
  ULONG * _POPUPMENU_MakeMXListA_ids = (ids); \
  APTR _POPUPMENU_MakeMXListA__re = \
  ({ \
  register struct PopupMenuBase * const __POPUPMENU_MakeMXListA__bn __asm("a6") = (struct PopupMenuBase *) (POPUPMENU_BASE_NAME);\
  register APTR __POPUPMENU_MakeMXListA__re __asm("d0"); \
  register ULONG * __POPUPMENU_MakeMXListA_ids __asm("a0") = (_POPUPMENU_MakeMXListA_ids); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__POPUPMENU_MakeMXListA__re) \
  : "r"(__POPUPMENU_MakeMXListA__bn), "r"(__POPUPMENU_MakeMXListA_ids)  \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __POPUPMENU_MakeMXListA__re; \
  }); \
  _POPUPMENU_MakeMXListA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___POPUPMENU_MakeMXList(struct PopupMenuBase * PopupMenuBase, ULONG ids, ...)
{
  return POPUPMENU_MakeMXListA((ULONG *) &ids);
}

#define POPUPMENU_MakeMXList(tags...) ___POPUPMENU_MakeMXList(POPUPMENU_BASE_NAME, tags)
#endif

#define POPUPMENU_FreeIDList(idlist) ({ \
  APTR _POPUPMENU_FreeIDList_idlist = (idlist); \
  { \
  register struct PopupMenuBase * const __POPUPMENU_FreeIDList__bn __asm("a6") = (struct PopupMenuBase *) (POPUPMENU_BASE_NAME);\
  register APTR __POPUPMENU_FreeIDList_idlist __asm("a0") = (_POPUPMENU_FreeIDList_idlist); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__POPUPMENU_FreeIDList__bn), "r"(__POPUPMENU_FreeIDList_idlist)  \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define POPUPMENU_MakeIDListA(tags) ({ \
  struct TagItem * _POPUPMENU_MakeIDListA_tags = (tags); \
  APTR _POPUPMENU_MakeIDListA__re = \
  ({ \
  register struct PopupMenuBase * const __POPUPMENU_MakeIDListA__bn __asm("a6") = (struct PopupMenuBase *) (POPUPMENU_BASE_NAME);\
  register APTR __POPUPMENU_MakeIDListA__re __asm("d0"); \
  register struct TagItem * __POPUPMENU_MakeIDListA_tags __asm("a0") = (_POPUPMENU_MakeIDListA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__POPUPMENU_MakeIDListA__re) \
  : "r"(__POPUPMENU_MakeIDListA__bn), "r"(__POPUPMENU_MakeIDListA_tags)  \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __POPUPMENU_MakeIDListA__re; \
  }); \
  _POPUPMENU_MakeIDListA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___POPUPMENU_MakeIDList(struct PopupMenuBase * PopupMenuBase, Tag tags, ...)
{
  return POPUPMENU_MakeIDListA((struct TagItem *) &tags);
}

#define POPUPMENU_MakeIDList(tags...) ___POPUPMENU_MakeIDList(POPUPMENU_BASE_NAME, tags)
#endif

#endif /*  _INLINE_PM_H  */
