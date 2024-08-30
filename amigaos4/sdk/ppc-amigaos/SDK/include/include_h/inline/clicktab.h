#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CLICKTAB_H
#define _INLINE_CLICKTAB_H

#ifndef CLIB_CLICKTAB_PROTOS_H
#define CLIB_CLICKTAB_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef CLICKTAB_BASE_NAME
#define CLICKTAB_BASE_NAME ClickTabBase
#endif

#define CLICKTAB_GetClass() ({ \
  Class * _CLICKTAB_GetClass__re = \
  ({ \
  register struct Library * const __CLICKTAB_GetClass__bn __asm("a6") = (struct Library *) (CLICKTAB_BASE_NAME);\
  register Class * __CLICKTAB_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__CLICKTAB_GetClass__re) \
  : "r"(__CLICKTAB_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CLICKTAB_GetClass__re; \
  }); \
  _CLICKTAB_GetClass__re; \
})

#define AllocClickTabNodeA(tags) ({ \
  struct TagItem * _AllocClickTabNodeA_tags = (tags); \
  struct Node * _AllocClickTabNodeA__re = \
  ({ \
  register struct Library * const __AllocClickTabNodeA__bn __asm("a6") = (struct Library *) (CLICKTAB_BASE_NAME);\
  register struct Node * __AllocClickTabNodeA__re __asm("d0"); \
  register struct TagItem * __AllocClickTabNodeA_tags __asm("a0") = (_AllocClickTabNodeA_tags); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AllocClickTabNodeA__re) \
  : "r"(__AllocClickTabNodeA__bn), "r"(__AllocClickTabNodeA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocClickTabNodeA__re; \
  }); \
  _AllocClickTabNodeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Node * ___AllocClickTabNode(struct Library * ClickTabBase, Tag tags, ...)
{
  return AllocClickTabNodeA((struct TagItem *) &tags);
}

#define AllocClickTabNode(tags...) ___AllocClickTabNode(CLICKTAB_BASE_NAME, tags)
#endif

#define FreeClickTabNode(node) ({ \
  struct Node * _FreeClickTabNode_node = (node); \
  { \
  register struct Library * const __FreeClickTabNode__bn __asm("a6") = (struct Library *) (CLICKTAB_BASE_NAME);\
  register struct Node * __FreeClickTabNode_node __asm("a0") = (_FreeClickTabNode_node); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FreeClickTabNode__bn), "r"(__FreeClickTabNode_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetClickTabNodeAttrsA(node, tags) ({ \
  struct Node * _SetClickTabNodeAttrsA_node = (node); \
  struct TagItem * _SetClickTabNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __SetClickTabNodeAttrsA__bn __asm("a6") = (struct Library *) (CLICKTAB_BASE_NAME);\
  register struct Node * __SetClickTabNodeAttrsA_node __asm("a0") = (_SetClickTabNodeAttrsA_node); \
  register struct TagItem * __SetClickTabNodeAttrsA_tags __asm("a1") = (_SetClickTabNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SetClickTabNodeAttrsA__bn), "r"(__SetClickTabNodeAttrsA_node), "r"(__SetClickTabNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetClickTabNodeAttrs(struct Library * ClickTabBase, struct Node * node, ...)
{
  SetClickTabNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define SetClickTabNodeAttrs(node...) ___SetClickTabNodeAttrs(CLICKTAB_BASE_NAME, node)
#endif

#define GetClickTabNodeAttrsA(node, tags) ({ \
  struct Node * _GetClickTabNodeAttrsA_node = (node); \
  struct TagItem * _GetClickTabNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __GetClickTabNodeAttrsA__bn __asm("a6") = (struct Library *) (CLICKTAB_BASE_NAME);\
  register struct Node * __GetClickTabNodeAttrsA_node __asm("a0") = (_GetClickTabNodeAttrsA_node); \
  register struct TagItem * __GetClickTabNodeAttrsA_tags __asm("a1") = (_GetClickTabNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__GetClickTabNodeAttrsA__bn), "r"(__GetClickTabNodeAttrsA_node), "r"(__GetClickTabNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___GetClickTabNodeAttrs(struct Library * ClickTabBase, struct Node * node, ...)
{
  GetClickTabNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define GetClickTabNodeAttrs(node...) ___GetClickTabNodeAttrs(CLICKTAB_BASE_NAME, node)
#endif

#endif /*  _INLINE_CLICKTAB_H  */
