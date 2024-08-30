#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CHOOSER_H
#define _INLINE_CHOOSER_H

#ifndef CLIB_CHOOSER_PROTOS_H
#define CLIB_CHOOSER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef CHOOSER_BASE_NAME
#define CHOOSER_BASE_NAME ChooserBase
#endif

#define CHOOSER_GetClass() ({ \
  Class * _CHOOSER_GetClass__re = \
  ({ \
  register struct Library * const __CHOOSER_GetClass__bn __asm("a6") = (struct Library *) (CHOOSER_BASE_NAME);\
  register Class * __CHOOSER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__CHOOSER_GetClass__re) \
  : "r"(__CHOOSER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CHOOSER_GetClass__re; \
  }); \
  _CHOOSER_GetClass__re; \
})

#define AllocChooserNodeA(tags) ({ \
  struct TagItem * _AllocChooserNodeA_tags = (tags); \
  struct Node * _AllocChooserNodeA__re = \
  ({ \
  register struct Library * const __AllocChooserNodeA__bn __asm("a6") = (struct Library *) (CHOOSER_BASE_NAME);\
  register struct Node * __AllocChooserNodeA__re __asm("d0"); \
  register struct TagItem * __AllocChooserNodeA_tags __asm("a0") = (_AllocChooserNodeA_tags); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AllocChooserNodeA__re) \
  : "r"(__AllocChooserNodeA__bn), "r"(__AllocChooserNodeA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocChooserNodeA__re; \
  }); \
  _AllocChooserNodeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Node * ___AllocChooserNode(struct Library * ChooserBase, Tag tags, ...)
{
  return AllocChooserNodeA((struct TagItem *) &tags);
}

#define AllocChooserNode(tags...) ___AllocChooserNode(CHOOSER_BASE_NAME, tags)
#endif

#define FreeChooserNode(node) ({ \
  struct Node * _FreeChooserNode_node = (node); \
  { \
  register struct Library * const __FreeChooserNode__bn __asm("a6") = (struct Library *) (CHOOSER_BASE_NAME);\
  register struct Node * __FreeChooserNode_node __asm("a0") = (_FreeChooserNode_node); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FreeChooserNode__bn), "r"(__FreeChooserNode_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetChooserNodeAttrsA(node, tags) ({ \
  struct Node * _SetChooserNodeAttrsA_node = (node); \
  struct TagItem * _SetChooserNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __SetChooserNodeAttrsA__bn __asm("a6") = (struct Library *) (CHOOSER_BASE_NAME);\
  register struct Node * __SetChooserNodeAttrsA_node __asm("a0") = (_SetChooserNodeAttrsA_node); \
  register struct TagItem * __SetChooserNodeAttrsA_tags __asm("a1") = (_SetChooserNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SetChooserNodeAttrsA__bn), "r"(__SetChooserNodeAttrsA_node), "r"(__SetChooserNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetChooserNodeAttrs(struct Library * ChooserBase, struct Node * node, ...)
{
  SetChooserNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define SetChooserNodeAttrs(node...) ___SetChooserNodeAttrs(CHOOSER_BASE_NAME, node)
#endif

#define GetChooserNodeAttrsA(node, tags) ({ \
  struct Node * _GetChooserNodeAttrsA_node = (node); \
  struct TagItem * _GetChooserNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __GetChooserNodeAttrsA__bn __asm("a6") = (struct Library *) (CHOOSER_BASE_NAME);\
  register struct Node * __GetChooserNodeAttrsA_node __asm("a0") = (_GetChooserNodeAttrsA_node); \
  register struct TagItem * __GetChooserNodeAttrsA_tags __asm("a1") = (_GetChooserNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__GetChooserNodeAttrsA__bn), "r"(__GetChooserNodeAttrsA_node), "r"(__GetChooserNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___GetChooserNodeAttrs(struct Library * ChooserBase, struct Node * node, ...)
{
  GetChooserNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define GetChooserNodeAttrs(node...) ___GetChooserNodeAttrs(CHOOSER_BASE_NAME, node)
#endif

#endif /*  _INLINE_CHOOSER_H  */
