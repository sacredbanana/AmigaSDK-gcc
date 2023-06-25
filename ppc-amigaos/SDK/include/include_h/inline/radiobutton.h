#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_RADIOBUTTON_H
#define _INLINE_RADIOBUTTON_H

#ifndef CLIB_RADIOBUTTON_PROTOS_H
#define CLIB_RADIOBUTTON_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef RADIOBUTTON_BASE_NAME
#define RADIOBUTTON_BASE_NAME RadioButtonBase
#endif

#define RADIOBUTTON_GetClass() ({ \
  Class * _RADIOBUTTON_GetClass__re = \
  ({ \
  register struct Library * const __RADIOBUTTON_GetClass__bn __asm("a6") = (struct Library *) (RADIOBUTTON_BASE_NAME);\
  register Class * __RADIOBUTTON_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__RADIOBUTTON_GetClass__re) \
  : "r"(__RADIOBUTTON_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RADIOBUTTON_GetClass__re; \
  }); \
  _RADIOBUTTON_GetClass__re; \
})

#define AllocRadioButtonNodeA(columns, tags) ({ \
  ULONG _AllocRadioButtonNodeA_columns = (columns); \
  struct TagItem * _AllocRadioButtonNodeA_tags = (tags); \
  struct Node * _AllocRadioButtonNodeA__re = \
  ({ \
  register struct Library * const __AllocRadioButtonNodeA__bn __asm("a6") = (struct Library *) (RADIOBUTTON_BASE_NAME);\
  register struct Node * __AllocRadioButtonNodeA__re __asm("d0"); \
  register ULONG __AllocRadioButtonNodeA_columns __asm("d0") = (_AllocRadioButtonNodeA_columns); \
  register struct TagItem * __AllocRadioButtonNodeA_tags __asm("a0") = (_AllocRadioButtonNodeA_tags); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AllocRadioButtonNodeA__re) \
  : "r"(__AllocRadioButtonNodeA__bn), "r"(__AllocRadioButtonNodeA_columns), "r"(__AllocRadioButtonNodeA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocRadioButtonNodeA__re; \
  }); \
  _AllocRadioButtonNodeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Node * ___AllocRadioButtonNode(struct Library * RadioButtonBase, ULONG columns, Tag tags, ...)
{
  return AllocRadioButtonNodeA(columns, (struct TagItem *) &tags);
}

#define AllocRadioButtonNode(columns...) ___AllocRadioButtonNode(RADIOBUTTON_BASE_NAME, columns)
#endif

#define FreeRadioButtonNode(node) ({ \
  struct Node * _FreeRadioButtonNode_node = (node); \
  { \
  register struct Library * const __FreeRadioButtonNode__bn __asm("a6") = (struct Library *) (RADIOBUTTON_BASE_NAME);\
  register struct Node * __FreeRadioButtonNode_node __asm("a0") = (_FreeRadioButtonNode_node); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FreeRadioButtonNode__bn), "r"(__FreeRadioButtonNode_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetRadioButtonNodeAttrsA(node, tags) ({ \
  struct Node * _SetRadioButtonNodeAttrsA_node = (node); \
  struct TagItem * _SetRadioButtonNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __SetRadioButtonNodeAttrsA__bn __asm("a6") = (struct Library *) (RADIOBUTTON_BASE_NAME);\
  register struct Node * __SetRadioButtonNodeAttrsA_node __asm("a0") = (_SetRadioButtonNodeAttrsA_node); \
  register struct TagItem * __SetRadioButtonNodeAttrsA_tags __asm("a1") = (_SetRadioButtonNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SetRadioButtonNodeAttrsA__bn), "r"(__SetRadioButtonNodeAttrsA_node), "r"(__SetRadioButtonNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetRadioButtonNodeAttrs(struct Library * RadioButtonBase, struct Node * node, ...)
{
  SetRadioButtonNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define SetRadioButtonNodeAttrs(node...) ___SetRadioButtonNodeAttrs(RADIOBUTTON_BASE_NAME, node)
#endif

#define GetRadioButtonNodeAttrsA(node, tags) ({ \
  struct Node * _GetRadioButtonNodeAttrsA_node = (node); \
  struct TagItem * _GetRadioButtonNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __GetRadioButtonNodeAttrsA__bn __asm("a6") = (struct Library *) (RADIOBUTTON_BASE_NAME);\
  register struct Node * __GetRadioButtonNodeAttrsA_node __asm("a0") = (_GetRadioButtonNodeAttrsA_node); \
  register struct TagItem * __GetRadioButtonNodeAttrsA_tags __asm("a1") = (_GetRadioButtonNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__GetRadioButtonNodeAttrsA__bn), "r"(__GetRadioButtonNodeAttrsA_node), "r"(__GetRadioButtonNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___GetRadioButtonNodeAttrs(struct Library * RadioButtonBase, struct Node * node, ...)
{
  GetRadioButtonNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define GetRadioButtonNodeAttrs(node...) ___GetRadioButtonNodeAttrs(RADIOBUTTON_BASE_NAME, node)
#endif

#endif /*  _INLINE_RADIOBUTTON_H  */
