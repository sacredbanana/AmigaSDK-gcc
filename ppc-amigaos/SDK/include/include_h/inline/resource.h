#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_RESOURCE_H
#define _INLINE_RESOURCE_H

#ifndef CLIB_RESOURCE_PROTOS_H
#define CLIB_RESOURCE_PROTOS_H
#endif

#ifndef  LIBRARIES_RESOURCE_H
#include <libraries/resource.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef RESOURCE_BASE_NAME
#define RESOURCE_BASE_NAME ResourceBase
#endif

#define RL_OpenResource(resource, screen, catalog) ({ \
  APTR _RL_OpenResource_resource = (resource); \
  struct Screen * _RL_OpenResource_screen = (screen); \
  struct Catalog * _RL_OpenResource_catalog = (catalog); \
  RESOURCEFILE _RL_OpenResource__re = \
  ({ \
  register struct Library * const __RL_OpenResource__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register RESOURCEFILE __RL_OpenResource__re __asm("d0"); \
  register APTR __RL_OpenResource_resource __asm("a0") = (_RL_OpenResource_resource); \
  register struct Screen * __RL_OpenResource_screen __asm("a1") = (_RL_OpenResource_screen); \
  register struct Catalog * __RL_OpenResource_catalog __asm("a2") = (_RL_OpenResource_catalog); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__RL_OpenResource__re) \
  : "r"(__RL_OpenResource__bn), "r"(__RL_OpenResource_resource), "r"(__RL_OpenResource_screen), "r"(__RL_OpenResource_catalog) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RL_OpenResource__re; \
  }); \
  _RL_OpenResource__re; \
})

#define RL_CloseResource(resfile) ({ \
  RESOURCEFILE _RL_CloseResource_resfile = (resfile); \
  { \
  register struct Library * const __RL_CloseResource__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register RESOURCEFILE __RL_CloseResource_resfile __asm("a0") = (_RL_CloseResource_resfile); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__RL_CloseResource__bn), "r"(__RL_CloseResource_resfile) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RL_NewObjectA(resfile, resid, tags) ({ \
  RESOURCEFILE _RL_NewObjectA_resfile = (resfile); \
  RESOURCEID _RL_NewObjectA_resid = (resid); \
  struct TagItem * _RL_NewObjectA_tags = (tags); \
  Object * _RL_NewObjectA__re = \
  ({ \
  register struct Library * const __RL_NewObjectA__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register Object * __RL_NewObjectA__re __asm("d0"); \
  register RESOURCEFILE __RL_NewObjectA_resfile __asm("a0") = (_RL_NewObjectA_resfile); \
  register RESOURCEID __RL_NewObjectA_resid __asm("d0") = (_RL_NewObjectA_resid); \
  register struct TagItem * __RL_NewObjectA_tags __asm("a1") = (_RL_NewObjectA_tags); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__RL_NewObjectA__re) \
  : "r"(__RL_NewObjectA__bn), "r"(__RL_NewObjectA_resfile), "r"(__RL_NewObjectA_resid), "r"(__RL_NewObjectA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RL_NewObjectA__re; \
  }); \
  _RL_NewObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ Object * ___RL_NewObject(struct Library * ResourceBase, RESOURCEFILE resfile, RESOURCEID resid, ...)
{
  return RL_NewObjectA(resfile, resid, (struct TagItem *) ((ULONG) &resid + sizeof(RESOURCEID)));
}

#define RL_NewObject(resfile, resid...) ___RL_NewObject(RESOURCE_BASE_NAME, resfile, resid)
#endif

#define RL_DisposeObject(resfile, obj) ({ \
  RESOURCEFILE _RL_DisposeObject_resfile = (resfile); \
  Object * _RL_DisposeObject_obj = (obj); \
  { \
  register struct Library * const __RL_DisposeObject__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register RESOURCEFILE __RL_DisposeObject_resfile __asm("a0") = (_RL_DisposeObject_resfile); \
  register Object * __RL_DisposeObject_obj __asm("a1") = (_RL_DisposeObject_obj); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__RL_DisposeObject__bn), "r"(__RL_DisposeObject_resfile), "r"(__RL_DisposeObject_obj) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RL_NewGroupA(resfile, id, taglist) ({ \
  RESOURCEFILE _RL_NewGroupA_resfile = (resfile); \
  RESOURCEID _RL_NewGroupA_id = (id); \
  struct TagItem * _RL_NewGroupA_taglist = (taglist); \
  Object ** _RL_NewGroupA__re = \
  ({ \
  register struct Library * const __RL_NewGroupA__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register Object ** __RL_NewGroupA__re __asm("d0"); \
  register RESOURCEFILE __RL_NewGroupA_resfile __asm("a0") = (_RL_NewGroupA_resfile); \
  register RESOURCEID __RL_NewGroupA_id __asm("d0") = (_RL_NewGroupA_id); \
  register struct TagItem * __RL_NewGroupA_taglist __asm("a1") = (_RL_NewGroupA_taglist); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__RL_NewGroupA__re) \
  : "r"(__RL_NewGroupA__bn), "r"(__RL_NewGroupA_resfile), "r"(__RL_NewGroupA_id), "r"(__RL_NewGroupA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RL_NewGroupA__re; \
  }); \
  _RL_NewGroupA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ Object ** ___RL_NewGroup(struct Library * ResourceBase, RESOURCEFILE resfile, RESOURCEID id, ...)
{
  return RL_NewGroupA(resfile, id, (struct TagItem *) ((ULONG) &id + sizeof(RESOURCEID)));
}

#define RL_NewGroup(resfile, id...) ___RL_NewGroup(RESOURCE_BASE_NAME, resfile, id)
#endif

#define RL_DisposeGroup(resfile, obj) ({ \
  RESOURCEFILE _RL_DisposeGroup_resfile = (resfile); \
  Object ** _RL_DisposeGroup_obj = (obj); \
  { \
  register struct Library * const __RL_DisposeGroup__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register RESOURCEFILE __RL_DisposeGroup_resfile __asm("a0") = (_RL_DisposeGroup_resfile); \
  register Object ** __RL_DisposeGroup_obj __asm("a1") = (_RL_DisposeGroup_obj); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__RL_DisposeGroup__bn), "r"(__RL_DisposeGroup_resfile), "r"(__RL_DisposeGroup_obj) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RL_GetObjectArray(resfile, obj, id) ({ \
  RESOURCEFILE _RL_GetObjectArray_resfile = (resfile); \
  Object * _RL_GetObjectArray_obj = (obj); \
  RESOURCEID _RL_GetObjectArray_id = (id); \
  Object ** _RL_GetObjectArray__re = \
  ({ \
  register struct Library * const __RL_GetObjectArray__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register Object ** __RL_GetObjectArray__re __asm("d0"); \
  register RESOURCEFILE __RL_GetObjectArray_resfile __asm("a0") = (_RL_GetObjectArray_resfile); \
  register Object * __RL_GetObjectArray_obj __asm("a1") = (_RL_GetObjectArray_obj); \
  register RESOURCEID __RL_GetObjectArray_id __asm("d0") = (_RL_GetObjectArray_id); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__RL_GetObjectArray__re) \
  : "r"(__RL_GetObjectArray__bn), "r"(__RL_GetObjectArray_resfile), "r"(__RL_GetObjectArray_obj), "r"(__RL_GetObjectArray_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RL_GetObjectArray__re; \
  }); \
  _RL_GetObjectArray__re; \
})

#define RL_SetResourceScreen(resfile, screen) ({ \
  RESOURCEFILE _RL_SetResourceScreen_resfile = (resfile); \
  struct Screen * _RL_SetResourceScreen_screen = (screen); \
  BOOL _RL_SetResourceScreen__re = \
  ({ \
  register struct Library * const __RL_SetResourceScreen__bn __asm("a6") = (struct Library *) (RESOURCE_BASE_NAME);\
  register BOOL __RL_SetResourceScreen__re __asm("d0"); \
  register RESOURCEFILE __RL_SetResourceScreen_resfile __asm("a0") = (_RL_SetResourceScreen_resfile); \
  register struct Screen * __RL_SetResourceScreen_screen __asm("a1") = (_RL_SetResourceScreen_screen); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__RL_SetResourceScreen__re) \
  : "r"(__RL_SetResourceScreen__bn), "r"(__RL_SetResourceScreen_resfile), "r"(__RL_SetResourceScreen_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RL_SetResourceScreen__re; \
  }); \
  _RL_SetResourceScreen__re; \
})

#endif /*  _INLINE_RESOURCE_H  */
