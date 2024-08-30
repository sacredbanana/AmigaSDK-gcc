#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_PARTITION_H
#define _INLINE_PARTITION_H

#ifndef CLIB_PARTITION_PROTOS_H
#define CLIB_PARTITION_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef PARTITION_BASE_NAME
#define PARTITION_BASE_NAME PartitionBase
#endif

#define PARTITION_GetClass() ({ \
  Class * _PARTITION_GetClass__re = \
  ({ \
  register struct Library * const __PARTITION_GetClass__bn __asm("a6") = (struct Library *) (PARTITION_BASE_NAME);\
  register Class * __PARTITION_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__PARTITION_GetClass__re) \
  : "r"(__PARTITION_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PARTITION_GetClass__re; \
  }); \
  _PARTITION_GetClass__re; \
})

#define AllocPartitionNodeA(last) ({ \
  struct TagItem * _AllocPartitionNodeA_last = (last); \
  struct Node * _AllocPartitionNodeA__re = \
  ({ \
  register struct Library * const __AllocPartitionNodeA__bn __asm("a6") = (struct Library *) (PARTITION_BASE_NAME);\
  register struct Node * __AllocPartitionNodeA__re __asm("d0"); \
  register struct TagItem * __AllocPartitionNodeA_last __asm("a0") = (_AllocPartitionNodeA_last); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AllocPartitionNodeA__re) \
  : "r"(__AllocPartitionNodeA__bn), "r"(__AllocPartitionNodeA_last) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocPartitionNodeA__re; \
  }); \
  _AllocPartitionNodeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Node * ___AllocPartitionNode(struct Library * PartitionBase, Tag last, ...)
{
  return AllocPartitionNodeA((struct TagItem *) &last);
}

#define AllocPartitionNode(tags...) ___AllocPartitionNode(PARTITION_BASE_NAME, tags)
#endif

#define FreePartitionNode(last) ({ \
  struct Node * _FreePartitionNode_last = (last); \
  { \
  register struct Library * const __FreePartitionNode__bn __asm("a6") = (struct Library *) (PARTITION_BASE_NAME);\
  register struct Node * __FreePartitionNode_last __asm("a0") = (_FreePartitionNode_last); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FreePartitionNode__bn), "r"(__FreePartitionNode_last) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetPartitionNodeAttrsA(par1, last) ({ \
  struct Node * _SetPartitionNodeAttrsA_par1 = (par1); \
  struct TagItem * _SetPartitionNodeAttrsA_last = (last); \
  { \
  register struct Library * const __SetPartitionNodeAttrsA__bn __asm("a6") = (struct Library *) (PARTITION_BASE_NAME);\
  register struct Node * __SetPartitionNodeAttrsA_par1 __asm("a0") = (_SetPartitionNodeAttrsA_par1); \
  register struct TagItem * __SetPartitionNodeAttrsA_last __asm("a1") = (_SetPartitionNodeAttrsA_last); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SetPartitionNodeAttrsA__bn), "r"(__SetPartitionNodeAttrsA_par1), "r"(__SetPartitionNodeAttrsA_last) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ void ___SetPartitionNodeAttrs(struct Library * PartitionBase, struct Node * par1, Tag last, ...)
{
  SetPartitionNodeAttrsA(par1, (struct TagItem *) &last);
}

#define SetPartitionNodeAttrs(par1...) ___SetPartitionNodeAttrs(PARTITION_BASE_NAME, par1)
#endif

#define GetPartitionNodeAttrsA(par1, last) ({ \
  struct Node * _GetPartitionNodeAttrsA_par1 = (par1); \
  struct TagItem * _GetPartitionNodeAttrsA_last = (last); \
  { \
  register struct Library * const __GetPartitionNodeAttrsA__bn __asm("a6") = (struct Library *) (PARTITION_BASE_NAME);\
  register struct Node * __GetPartitionNodeAttrsA_par1 __asm("a0") = (_GetPartitionNodeAttrsA_par1); \
  register struct TagItem * __GetPartitionNodeAttrsA_last __asm("a1") = (_GetPartitionNodeAttrsA_last); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__GetPartitionNodeAttrsA__bn), "r"(__GetPartitionNodeAttrsA_par1), "r"(__GetPartitionNodeAttrsA_last) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ void ___GetPartitionNodeAttrs(struct Library * PartitionBase, struct Node * par1, Tag last, ...)
{
  GetPartitionNodeAttrsA(par1, (struct TagItem *) &last);
}

#define GetPartitionNodeAttrs(par1...) ___GetPartitionNodeAttrs(PARTITION_BASE_NAME, par1)
#endif

#endif /*  _INLINE_PARTITION_H  */
