#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_SPEEDBAR_H
#define _INLINE_SPEEDBAR_H

#ifndef CLIB_SPEEDBAR_PROTOS_H
#define CLIB_SPEEDBAR_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef SPEEDBAR_BASE_NAME
#define SPEEDBAR_BASE_NAME SpeedBarBase
#endif

#define SPEEDBAR_GetClass() ({ \
  Class * _SPEEDBAR_GetClass__re = \
  ({ \
  register struct Library * const __SPEEDBAR_GetClass__bn __asm("a6") = (struct Library *) (SPEEDBAR_BASE_NAME);\
  register Class * __SPEEDBAR_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SPEEDBAR_GetClass__re) \
  : "r"(__SPEEDBAR_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SPEEDBAR_GetClass__re; \
  }); \
  _SPEEDBAR_GetClass__re; \
})

#define AllocSpeedButtonNodeA(number, tags) ({ \
  ULONG _AllocSpeedButtonNodeA_number = (number); \
  struct TagItem * _AllocSpeedButtonNodeA_tags = (tags); \
  struct Node * _AllocSpeedButtonNodeA__re = \
  ({ \
  register struct Library * const __AllocSpeedButtonNodeA__bn __asm("a6") = (struct Library *) (SPEEDBAR_BASE_NAME);\
  register struct Node * __AllocSpeedButtonNodeA__re __asm("d0"); \
  register ULONG __AllocSpeedButtonNodeA_number __asm("d0") = (_AllocSpeedButtonNodeA_number); \
  register struct TagItem * __AllocSpeedButtonNodeA_tags __asm("a0") = (_AllocSpeedButtonNodeA_tags); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AllocSpeedButtonNodeA__re) \
  : "r"(__AllocSpeedButtonNodeA__bn), "r"(__AllocSpeedButtonNodeA_number), "r"(__AllocSpeedButtonNodeA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocSpeedButtonNodeA__re; \
  }); \
  _AllocSpeedButtonNodeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Node * ___AllocSpeedButtonNode(struct Library * SpeedBarBase, ULONG number, Tag tags, ...)
{
  return AllocSpeedButtonNodeA(number, (struct TagItem *) &tags);
}

#define AllocSpeedButtonNode(number...) ___AllocSpeedButtonNode(SPEEDBAR_BASE_NAME, number)
#endif

#define FreeSpeedButtonNode(node) ({ \
  struct Node * _FreeSpeedButtonNode_node = (node); \
  { \
  register struct Library * const __FreeSpeedButtonNode__bn __asm("a6") = (struct Library *) (SPEEDBAR_BASE_NAME);\
  register struct Node * __FreeSpeedButtonNode_node __asm("a0") = (_FreeSpeedButtonNode_node); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FreeSpeedButtonNode__bn), "r"(__FreeSpeedButtonNode_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetSpeedButtonNodeAttrsA(node, tags) ({ \
  struct Node * _SetSpeedButtonNodeAttrsA_node = (node); \
  struct TagItem * _SetSpeedButtonNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __SetSpeedButtonNodeAttrsA__bn __asm("a6") = (struct Library *) (SPEEDBAR_BASE_NAME);\
  register struct Node * __SetSpeedButtonNodeAttrsA_node __asm("a0") = (_SetSpeedButtonNodeAttrsA_node); \
  register struct TagItem * __SetSpeedButtonNodeAttrsA_tags __asm("a1") = (_SetSpeedButtonNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SetSpeedButtonNodeAttrsA__bn), "r"(__SetSpeedButtonNodeAttrsA_node), "r"(__SetSpeedButtonNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetSpeedButtonNodeAttrs(struct Library * SpeedBarBase, struct Node * node, ...)
{
  SetSpeedButtonNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define SetSpeedButtonNodeAttrs(node...) ___SetSpeedButtonNodeAttrs(SPEEDBAR_BASE_NAME, node)
#endif

#define GetSpeedButtonNodeAttrsA(node, tags) ({ \
  struct Node * _GetSpeedButtonNodeAttrsA_node = (node); \
  struct TagItem * _GetSpeedButtonNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __GetSpeedButtonNodeAttrsA__bn __asm("a6") = (struct Library *) (SPEEDBAR_BASE_NAME);\
  register struct Node * __GetSpeedButtonNodeAttrsA_node __asm("a0") = (_GetSpeedButtonNodeAttrsA_node); \
  register struct TagItem * __GetSpeedButtonNodeAttrsA_tags __asm("a1") = (_GetSpeedButtonNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__GetSpeedButtonNodeAttrsA__bn), "r"(__GetSpeedButtonNodeAttrsA_node), "r"(__GetSpeedButtonNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___GetSpeedButtonNodeAttrs(struct Library * SpeedBarBase, struct Node * node, ...)
{
  GetSpeedButtonNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define GetSpeedButtonNodeAttrs(node...) ___GetSpeedButtonNodeAttrs(SPEEDBAR_BASE_NAME, node)
#endif

#endif /*  _INLINE_SPEEDBAR_H  */
