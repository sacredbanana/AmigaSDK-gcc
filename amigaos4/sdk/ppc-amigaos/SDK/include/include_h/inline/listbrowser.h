#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LISTBROWSER_H
#define _INLINE_LISTBROWSER_H

#ifndef CLIB_LISTBROWSER_PROTOS_H
#define CLIB_LISTBROWSER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  GADGETS_LISTBROWSER_H
#include <gadgets/listbrowser.h>
#endif

#ifndef LISTBROWSER_BASE_NAME
#define LISTBROWSER_BASE_NAME ListBrowserBase
#endif

#define LISTBROWSER_GetClass() ({ \
  struct IClass * _LISTBROWSER_GetClass__re = \
  ({ \
  register struct Library * const __LISTBROWSER_GetClass__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct IClass * __LISTBROWSER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__LISTBROWSER_GetClass__re) \
  : "r"(__LISTBROWSER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LISTBROWSER_GetClass__re; \
  }); \
  _LISTBROWSER_GetClass__re; \
})

#define AllocListBrowserNodeA(columns, tags) ({ \
  ULONG _AllocListBrowserNodeA_columns = (columns); \
  struct TagItem * _AllocListBrowserNodeA_tags = (tags); \
  struct Node * _AllocListBrowserNodeA__re = \
  ({ \
  register struct Library * const __AllocListBrowserNodeA__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct Node * __AllocListBrowserNodeA__re __asm("d0"); \
  register ULONG __AllocListBrowserNodeA_columns __asm("d0") = (_AllocListBrowserNodeA_columns); \
  register struct TagItem * __AllocListBrowserNodeA_tags __asm("a0") = (_AllocListBrowserNodeA_tags); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AllocListBrowserNodeA__re) \
  : "r"(__AllocListBrowserNodeA__bn), "r"(__AllocListBrowserNodeA_columns), "r"(__AllocListBrowserNodeA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocListBrowserNodeA__re; \
  }); \
  _AllocListBrowserNodeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Node * ___AllocListBrowserNode(struct Library * ListBrowserBase, ULONG columns, ...)
{
  return AllocListBrowserNodeA(columns, (struct TagItem *) ((ULONG) &columns + sizeof(ULONG)));
}

#define AllocListBrowserNode(columns...) ___AllocListBrowserNode(LISTBROWSER_BASE_NAME, columns)
#endif

#define FreeListBrowserNode(node) ({ \
  struct Node * _FreeListBrowserNode_node = (node); \
  { \
  register struct Library * const __FreeListBrowserNode__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct Node * __FreeListBrowserNode_node __asm("a0") = (_FreeListBrowserNode_node); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FreeListBrowserNode__bn), "r"(__FreeListBrowserNode_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetListBrowserNodeAttrsA(node, tags) ({ \
  struct Node * _SetListBrowserNodeAttrsA_node = (node); \
  struct TagItem * _SetListBrowserNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __SetListBrowserNodeAttrsA__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct Node * __SetListBrowserNodeAttrsA_node __asm("a0") = (_SetListBrowserNodeAttrsA_node); \
  register struct TagItem * __SetListBrowserNodeAttrsA_tags __asm("a1") = (_SetListBrowserNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__SetListBrowserNodeAttrsA__bn), "r"(__SetListBrowserNodeAttrsA_node), "r"(__SetListBrowserNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetListBrowserNodeAttrs(struct Library * ListBrowserBase, struct Node * node, ...)
{
  SetListBrowserNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define SetListBrowserNodeAttrs(node...) ___SetListBrowserNodeAttrs(LISTBROWSER_BASE_NAME, node)
#endif

#define GetListBrowserNodeAttrsA(node, tags) ({ \
  struct Node * _GetListBrowserNodeAttrsA_node = (node); \
  struct TagItem * _GetListBrowserNodeAttrsA_tags = (tags); \
  { \
  register struct Library * const __GetListBrowserNodeAttrsA__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct Node * __GetListBrowserNodeAttrsA_node __asm("a0") = (_GetListBrowserNodeAttrsA_node); \
  register struct TagItem * __GetListBrowserNodeAttrsA_tags __asm("a1") = (_GetListBrowserNodeAttrsA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__GetListBrowserNodeAttrsA__bn), "r"(__GetListBrowserNodeAttrsA_node), "r"(__GetListBrowserNodeAttrsA_tags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___GetListBrowserNodeAttrs(struct Library * ListBrowserBase, struct Node * node, ...)
{
  GetListBrowserNodeAttrsA(node, (struct TagItem *) ((ULONG) &node + sizeof(struct Node *)));
}

#define GetListBrowserNodeAttrs(node...) ___GetListBrowserNodeAttrs(LISTBROWSER_BASE_NAME, node)
#endif

#define ListBrowserSelectAll(list) ({ \
  struct List * _ListBrowserSelectAll_list = (list); \
  { \
  register struct Library * const __ListBrowserSelectAll__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct List * __ListBrowserSelectAll_list __asm("a0") = (_ListBrowserSelectAll_list); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__ListBrowserSelectAll__bn), "r"(__ListBrowserSelectAll_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ShowListBrowserNodeChildren(node, depth) ({ \
  struct Node * _ShowListBrowserNodeChildren_node = (node); \
  LONG _ShowListBrowserNodeChildren_depth = (depth); \
  { \
  register struct Library * const __ShowListBrowserNodeChildren__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct Node * __ShowListBrowserNodeChildren_node __asm("a0") = (_ShowListBrowserNodeChildren_node); \
  register LONG __ShowListBrowserNodeChildren_depth __asm("d0") = (_ShowListBrowserNodeChildren_depth); \
  __asm volatile ("jsr a6@(-66:W)" \
  : \
  : "r"(__ShowListBrowserNodeChildren__bn), "r"(__ShowListBrowserNodeChildren_node), "r"(__ShowListBrowserNodeChildren_depth) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define HideListBrowserNodeChildren(node) ({ \
  struct Node * _HideListBrowserNodeChildren_node = (node); \
  { \
  register struct Library * const __HideListBrowserNodeChildren__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct Node * __HideListBrowserNodeChildren_node __asm("a0") = (_HideListBrowserNodeChildren_node); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__HideListBrowserNodeChildren__bn), "r"(__HideListBrowserNodeChildren_node) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ShowAllListBrowserChildren(list) ({ \
  struct List * _ShowAllListBrowserChildren_list = (list); \
  { \
  register struct Library * const __ShowAllListBrowserChildren__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct List * __ShowAllListBrowserChildren_list __asm("a0") = (_ShowAllListBrowserChildren_list); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__ShowAllListBrowserChildren__bn), "r"(__ShowAllListBrowserChildren_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define HideAllListBrowserChildren(list) ({ \
  struct List * _HideAllListBrowserChildren_list = (list); \
  { \
  register struct Library * const __HideAllListBrowserChildren__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct List * __HideAllListBrowserChildren_list __asm("a0") = (_HideAllListBrowserChildren_list); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__HideAllListBrowserChildren__bn), "r"(__HideAllListBrowserChildren_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeListBrowserList(list) ({ \
  struct List * _FreeListBrowserList_list = (list); \
  { \
  register struct Library * const __FreeListBrowserList__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct List * __FreeListBrowserList_list __asm("a0") = (_FreeListBrowserList_list); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__FreeListBrowserList__bn), "r"(__FreeListBrowserList_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocLBColumnInfoA(columns, tags) ({ \
  ULONG _AllocLBColumnInfoA_columns = (columns); \
  struct TagItem * _AllocLBColumnInfoA_tags = (tags); \
  struct ColumnInfo * _AllocLBColumnInfoA__re = \
  ({ \
  register struct Library * const __AllocLBColumnInfoA__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct ColumnInfo * __AllocLBColumnInfoA__re __asm("d0"); \
  register ULONG __AllocLBColumnInfoA_columns __asm("d0") = (_AllocLBColumnInfoA_columns); \
  register struct TagItem * __AllocLBColumnInfoA_tags __asm("a0") = (_AllocLBColumnInfoA_tags); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__AllocLBColumnInfoA__re) \
  : "r"(__AllocLBColumnInfoA__bn), "r"(__AllocLBColumnInfoA_columns), "r"(__AllocLBColumnInfoA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocLBColumnInfoA__re; \
  }); \
  _AllocLBColumnInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct ColumnInfo * ___AllocLBColumnInfo(struct Library * ListBrowserBase, ULONG columns, ...)
{
  return AllocLBColumnInfoA(columns, (struct TagItem *) ((ULONG) &columns + sizeof(ULONG)));
}

#define AllocLBColumnInfo(columns...) ___AllocLBColumnInfo(LISTBROWSER_BASE_NAME, columns)
#endif

#define SetLBColumnInfoAttrsA(columninfo, tags) ({ \
  struct ColumnInfo * _SetLBColumnInfoAttrsA_columninfo = (columninfo); \
  struct TagItem * _SetLBColumnInfoAttrsA_tags = (tags); \
  LONG _SetLBColumnInfoAttrsA__re = \
  ({ \
  register struct Library * const __SetLBColumnInfoAttrsA__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register LONG __SetLBColumnInfoAttrsA__re __asm("d0"); \
  register struct ColumnInfo * __SetLBColumnInfoAttrsA_columninfo __asm("a1") = (_SetLBColumnInfoAttrsA_columninfo); \
  register struct TagItem * __SetLBColumnInfoAttrsA_tags __asm("a0") = (_SetLBColumnInfoAttrsA_tags); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__SetLBColumnInfoAttrsA__re) \
  : "r"(__SetLBColumnInfoAttrsA__bn), "r"(__SetLBColumnInfoAttrsA_columninfo), "r"(__SetLBColumnInfoAttrsA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetLBColumnInfoAttrsA__re; \
  }); \
  _SetLBColumnInfoAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetLBColumnInfoAttrs(struct Library * ListBrowserBase, struct ColumnInfo * columninfo, ...)
{
  return SetLBColumnInfoAttrsA(columninfo, (struct TagItem *) ((ULONG) &columninfo + sizeof(struct ColumnInfo *)));
}

#define SetLBColumnInfoAttrs(columninfo...) ___SetLBColumnInfoAttrs(LISTBROWSER_BASE_NAME, columninfo)
#endif

#define GetLBColumnInfoAttrsA(columninfo, tags) ({ \
  struct ColumnInfo * _GetLBColumnInfoAttrsA_columninfo = (columninfo); \
  struct TagItem * _GetLBColumnInfoAttrsA_tags = (tags); \
  LONG _GetLBColumnInfoAttrsA__re = \
  ({ \
  register struct Library * const __GetLBColumnInfoAttrsA__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register LONG __GetLBColumnInfoAttrsA__re __asm("d0"); \
  register struct ColumnInfo * __GetLBColumnInfoAttrsA_columninfo __asm("a1") = (_GetLBColumnInfoAttrsA_columninfo); \
  register struct TagItem * __GetLBColumnInfoAttrsA_tags __asm("a0") = (_GetLBColumnInfoAttrsA_tags); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__GetLBColumnInfoAttrsA__re) \
  : "r"(__GetLBColumnInfoAttrsA__bn), "r"(__GetLBColumnInfoAttrsA_columninfo), "r"(__GetLBColumnInfoAttrsA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetLBColumnInfoAttrsA__re; \
  }); \
  _GetLBColumnInfoAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GetLBColumnInfoAttrs(struct Library * ListBrowserBase, struct ColumnInfo * columninfo, ...)
{
  return GetLBColumnInfoAttrsA(columninfo, (struct TagItem *) ((ULONG) &columninfo + sizeof(struct ColumnInfo *)));
}

#define GetLBColumnInfoAttrs(columninfo...) ___GetLBColumnInfoAttrs(LISTBROWSER_BASE_NAME, columninfo)
#endif

#define FreeLBColumnInfo(columninfo) ({ \
  struct ColumnInfo * _FreeLBColumnInfo_columninfo = (columninfo); \
  { \
  register struct Library * const __FreeLBColumnInfo__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct ColumnInfo * __FreeLBColumnInfo_columninfo __asm("a0") = (_FreeLBColumnInfo_columninfo); \
  __asm volatile ("jsr a6@(-114:W)" \
  : \
  : "r"(__FreeLBColumnInfo__bn), "r"(__FreeLBColumnInfo_columninfo) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ListBrowserClearAll(list) ({ \
  struct List * _ListBrowserClearAll_list = (list); \
  { \
  register struct Library * const __ListBrowserClearAll__bn __asm("a6") = (struct Library *) (LISTBROWSER_BASE_NAME);\
  register struct List * __ListBrowserClearAll_list __asm("a0") = (_ListBrowserClearAll_list); \
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__ListBrowserClearAll__bn), "r"(__ListBrowserClearAll_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_LISTBROWSER_H  */
