#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_DATATYPES_H
#define _INLINE_DATATYPES_H

#ifndef CLIB_DATATYPES_PROTOS_H
#define CLIB_DATATYPES_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
#endif
#ifndef  DATATYPES_DATATYPES_H
#include <datatypes/datatypes.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif

#ifndef DATATYPES_BASE_NAME
#define DATATYPES_BASE_NAME DataTypesBase
#endif

#define ObtainDataTypeA(type, handle, attrs) ({ \
  ULONG _ObtainDataTypeA_type = (type); \
  APTR _ObtainDataTypeA_handle = (handle); \
  CONST struct TagItem * _ObtainDataTypeA_attrs = (attrs); \
  struct DataType * _ObtainDataTypeA__re = \
  ({ \
  register struct Library * const __ObtainDataTypeA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register struct DataType * __ObtainDataTypeA__re __asm("d0"); \
  register ULONG __ObtainDataTypeA_type __asm("d0") = (_ObtainDataTypeA_type); \
  register APTR __ObtainDataTypeA_handle __asm("a0") = (_ObtainDataTypeA_handle); \
  register CONST struct TagItem * __ObtainDataTypeA_attrs __asm("a1") = (_ObtainDataTypeA_attrs); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__ObtainDataTypeA__re) \
  : "r"(__ObtainDataTypeA__bn), "r"(__ObtainDataTypeA_type), "r"(__ObtainDataTypeA_handle), "r"(__ObtainDataTypeA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainDataTypeA__re; \
  }); \
  _ObtainDataTypeA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct DataType * ___ObtainDataType(struct Library * DataTypesBase, ULONG type, APTR handle, Tag attrs, ...)
{
  return ObtainDataTypeA(type, handle, (CONST struct TagItem *) &attrs);
}

#define ObtainDataType(type, handle...) ___ObtainDataType(DATATYPES_BASE_NAME, type, handle)
#endif

#define ReleaseDataType(dt) ({ \
  struct DataType * _ReleaseDataType_dt = (dt); \
  { \
  register struct Library * const __ReleaseDataType__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register struct DataType * __ReleaseDataType_dt __asm("a0") = (_ReleaseDataType_dt); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__ReleaseDataType__bn), "r"(__ReleaseDataType_dt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define NewDTObjectA(name, attrs) ({ \
  CONST_STRPTR _NewDTObjectA_name = (name); \
  CONST struct TagItem * _NewDTObjectA_attrs = (attrs); \
  Object * _NewDTObjectA__re = \
  ({ \
  register struct Library * const __NewDTObjectA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register Object * __NewDTObjectA__re __asm("d0"); \
  register CONST_STRPTR __NewDTObjectA_name __asm("d0") = (_NewDTObjectA_name); \
  register CONST struct TagItem * __NewDTObjectA_attrs __asm("a0") = (_NewDTObjectA_attrs); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__NewDTObjectA__re) \
  : "r"(__NewDTObjectA__bn), "r"(__NewDTObjectA_name), "r"(__NewDTObjectA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NewDTObjectA__re; \
  }); \
  _NewDTObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ Object * ___NewDTObject(struct Library * DataTypesBase, CONST_STRPTR name, Tag attrs, ...)
{
  return NewDTObjectA(name, (CONST struct TagItem *) &attrs);
}

#define NewDTObject(name...) ___NewDTObject(DATATYPES_BASE_NAME, name)
#endif

#define DisposeDTObject(o) ({ \
  Object * _DisposeDTObject_o = (o); \
  { \
  register struct Library * const __DisposeDTObject__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register Object * __DisposeDTObject_o __asm("a0") = (_DisposeDTObject_o); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__DisposeDTObject__bn), "r"(__DisposeDTObject_o) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetDTAttrsA(o, win, req, attrs) ({ \
  Object * _SetDTAttrsA_o = (o); \
  struct Window * _SetDTAttrsA_win = (win); \
  struct Requester * _SetDTAttrsA_req = (req); \
  CONST struct TagItem * _SetDTAttrsA_attrs = (attrs); \
  ULONG _SetDTAttrsA__re = \
  ({ \
  register struct Library * const __SetDTAttrsA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __SetDTAttrsA__re __asm("d0"); \
  register Object * __SetDTAttrsA_o __asm("a0") = (_SetDTAttrsA_o); \
  register struct Window * __SetDTAttrsA_win __asm("a1") = (_SetDTAttrsA_win); \
  register struct Requester * __SetDTAttrsA_req __asm("a2") = (_SetDTAttrsA_req); \
  register CONST struct TagItem * __SetDTAttrsA_attrs __asm("a3") = (_SetDTAttrsA_attrs); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__SetDTAttrsA__re) \
  : "r"(__SetDTAttrsA__bn), "r"(__SetDTAttrsA_o), "r"(__SetDTAttrsA_win), "r"(__SetDTAttrsA_req), "r"(__SetDTAttrsA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetDTAttrsA__re; \
  }); \
  _SetDTAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetDTAttrs(struct Library * DataTypesBase, Object * o, struct Window * win, struct Requester * req, Tag attrs, ...)
{
  return SetDTAttrsA(o, win, req, (CONST struct TagItem *) &attrs);
}

#define SetDTAttrs(o, win, req...) ___SetDTAttrs(DATATYPES_BASE_NAME, o, win, req)
#endif

#define GetDTAttrsA(o, attrs) ({ \
  Object * _GetDTAttrsA_o = (o); \
  CONST struct TagItem * _GetDTAttrsA_attrs = (attrs); \
  ULONG _GetDTAttrsA__re = \
  ({ \
  register struct Library * const __GetDTAttrsA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __GetDTAttrsA__re __asm("d0"); \
  register Object * __GetDTAttrsA_o __asm("a0") = (_GetDTAttrsA_o); \
  register CONST struct TagItem * __GetDTAttrsA_attrs __asm("a2") = (_GetDTAttrsA_attrs); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__GetDTAttrsA__re) \
  : "r"(__GetDTAttrsA__bn), "r"(__GetDTAttrsA_o), "r"(__GetDTAttrsA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDTAttrsA__re; \
  }); \
  _GetDTAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___GetDTAttrs(struct Library * DataTypesBase, Object * o, Tag attrs, ...)
{
  return GetDTAttrsA(o, (CONST struct TagItem *) &attrs);
}

#define GetDTAttrs(o...) ___GetDTAttrs(DATATYPES_BASE_NAME, o)
#endif

#define AddDTObject(win, req, o, pos) ({ \
  struct Window * _AddDTObject_win = (win); \
  struct Requester * _AddDTObject_req = (req); \
  Object * _AddDTObject_o = (o); \
  LONG _AddDTObject_pos = (pos); \
  LONG _AddDTObject__re = \
  ({ \
  register struct Library * const __AddDTObject__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register LONG __AddDTObject__re __asm("d0"); \
  register struct Window * __AddDTObject_win __asm("a0") = (_AddDTObject_win); \
  register struct Requester * __AddDTObject_req __asm("a1") = (_AddDTObject_req); \
  register Object * __AddDTObject_o __asm("a2") = (_AddDTObject_o); \
  register LONG __AddDTObject_pos __asm("d0") = (_AddDTObject_pos); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__AddDTObject__re) \
  : "r"(__AddDTObject__bn), "r"(__AddDTObject_win), "r"(__AddDTObject_req), "r"(__AddDTObject_o), "r"(__AddDTObject_pos) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddDTObject__re; \
  }); \
  _AddDTObject__re; \
})

#define RefreshDTObjectA(o, win, req, attrs) ({ \
  Object * _RefreshDTObjectA_o = (o); \
  struct Window * _RefreshDTObjectA_win = (win); \
  struct Requester * _RefreshDTObjectA_req = (req); \
  CONST struct TagItem * _RefreshDTObjectA_attrs = (attrs); \
  { \
  register struct Library * const __RefreshDTObjectA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register Object * __RefreshDTObjectA_o __asm("a0") = (_RefreshDTObjectA_o); \
  register struct Window * __RefreshDTObjectA_win __asm("a1") = (_RefreshDTObjectA_win); \
  register struct Requester * __RefreshDTObjectA_req __asm("a2") = (_RefreshDTObjectA_req); \
  register CONST struct TagItem * __RefreshDTObjectA_attrs __asm("a3") = (_RefreshDTObjectA_attrs); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__RefreshDTObjectA__bn), "r"(__RefreshDTObjectA_o), "r"(__RefreshDTObjectA_win), "r"(__RefreshDTObjectA_req), "r"(__RefreshDTObjectA_attrs) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___RefreshDTObjects(struct Library * DataTypesBase, Object * o, struct Window * win, struct Requester * req, Tag attrs, ...)
{
  RefreshDTObjectA(o, win, req, (CONST struct TagItem *) &attrs);
}

#define RefreshDTObjects(o, win, req...) ___RefreshDTObjects(DATATYPES_BASE_NAME, o, win, req)
#endif

#ifndef NO_INLINE_STDARG
#define RefreshDTObject RefreshDTObjects
#endif

#define DoAsyncLayout(o, gpl) ({ \
  Object * _DoAsyncLayout_o = (o); \
  struct gpLayout * _DoAsyncLayout_gpl = (gpl); \
  ULONG _DoAsyncLayout__re = \
  ({ \
  register struct Library * const __DoAsyncLayout__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __DoAsyncLayout__re __asm("d0"); \
  register Object * __DoAsyncLayout_o __asm("a0") = (_DoAsyncLayout_o); \
  register struct gpLayout * __DoAsyncLayout_gpl __asm("a1") = (_DoAsyncLayout_gpl); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__DoAsyncLayout__re) \
  : "r"(__DoAsyncLayout__bn), "r"(__DoAsyncLayout_o), "r"(__DoAsyncLayout_gpl) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoAsyncLayout__re; \
  }); \
  _DoAsyncLayout__re; \
})

#define DoDTMethodA(o, win, req, msg) ({ \
  Object * _DoDTMethodA_o = (o); \
  struct Window * _DoDTMethodA_win = (win); \
  struct Requester * _DoDTMethodA_req = (req); \
  Msg _DoDTMethodA_msg = (msg); \
  ULONG _DoDTMethodA__re = \
  ({ \
  register struct Library * const __DoDTMethodA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __DoDTMethodA__re __asm("d0"); \
  register Object * __DoDTMethodA_o __asm("a0") = (_DoDTMethodA_o); \
  register struct Window * __DoDTMethodA_win __asm("a1") = (_DoDTMethodA_win); \
  register struct Requester * __DoDTMethodA_req __asm("a2") = (_DoDTMethodA_req); \
  register Msg __DoDTMethodA_msg __asm("a3") = (_DoDTMethodA_msg); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__DoDTMethodA__re) \
  : "r"(__DoDTMethodA__bn), "r"(__DoDTMethodA_o), "r"(__DoDTMethodA_win), "r"(__DoDTMethodA_req), "r"(__DoDTMethodA_msg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoDTMethodA__re; \
  }); \
  _DoDTMethodA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___DoDTMethod(struct Library * DataTypesBase, Object * o, struct Window * win, struct Requester * req, ULONG msg, ...)
{
  return DoDTMethodA(o, win, req, (Msg) &msg);
}

#define DoDTMethod(o, win, req...) ___DoDTMethod(DATATYPES_BASE_NAME, o, win, req)
#endif

#define RemoveDTObject(win, o) ({ \
  struct Window * _RemoveDTObject_win = (win); \
  Object * _RemoveDTObject_o = (o); \
  LONG _RemoveDTObject__re = \
  ({ \
  register struct Library * const __RemoveDTObject__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register LONG __RemoveDTObject__re __asm("d0"); \
  register struct Window * __RemoveDTObject_win __asm("a0") = (_RemoveDTObject_win); \
  register Object * __RemoveDTObject_o __asm("a1") = (_RemoveDTObject_o); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__RemoveDTObject__re) \
  : "r"(__RemoveDTObject__bn), "r"(__RemoveDTObject_win), "r"(__RemoveDTObject_o) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveDTObject__re; \
  }); \
  _RemoveDTObject__re; \
})

#define GetDTMethods(object) ({ \
  Object * _GetDTMethods_object = (object); \
  ULONG * _GetDTMethods__re = \
  ({ \
  register struct Library * const __GetDTMethods__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG * __GetDTMethods__re __asm("d0"); \
  register Object * __GetDTMethods_object __asm("a0") = (_GetDTMethods_object); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__GetDTMethods__re) \
  : "r"(__GetDTMethods__bn), "r"(__GetDTMethods_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDTMethods__re; \
  }); \
  _GetDTMethods__re; \
})

#define GetDTTriggerMethods(object) ({ \
  Object * _GetDTTriggerMethods_object = (object); \
  struct DTMethods * _GetDTTriggerMethods__re = \
  ({ \
  register struct Library * const __GetDTTriggerMethods__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register struct DTMethods * __GetDTTriggerMethods__re __asm("d0"); \
  register Object * __GetDTTriggerMethods_object __asm("a0") = (_GetDTTriggerMethods_object); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__GetDTTriggerMethods__re) \
  : "r"(__GetDTTriggerMethods__bn), "r"(__GetDTTriggerMethods_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDTTriggerMethods__re; \
  }); \
  _GetDTTriggerMethods__re; \
})

#define PrintDTObjectA(o, w, r, msg) ({ \
  Object * _PrintDTObjectA_o = (o); \
  struct Window * _PrintDTObjectA_w = (w); \
  struct Requester * _PrintDTObjectA_r = (r); \
  struct dtPrint * _PrintDTObjectA_msg = (msg); \
  ULONG _PrintDTObjectA__re = \
  ({ \
  register struct Library * const __PrintDTObjectA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __PrintDTObjectA__re __asm("d0"); \
  register Object * __PrintDTObjectA_o __asm("a0") = (_PrintDTObjectA_o); \
  register struct Window * __PrintDTObjectA_w __asm("a1") = (_PrintDTObjectA_w); \
  register struct Requester * __PrintDTObjectA_r __asm("a2") = (_PrintDTObjectA_r); \
  register struct dtPrint * __PrintDTObjectA_msg __asm("a3") = (_PrintDTObjectA_msg); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__PrintDTObjectA__re) \
  : "r"(__PrintDTObjectA__bn), "r"(__PrintDTObjectA_o), "r"(__PrintDTObjectA_w), "r"(__PrintDTObjectA_r), "r"(__PrintDTObjectA_msg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PrintDTObjectA__re; \
  }); \
  _PrintDTObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___PrintDTObject(struct Library * DataTypesBase, Object * o, struct Window * w, struct Requester * r, ULONG msg, ...)
{
  return PrintDTObjectA(o, w, r, (struct dtPrint *) &msg);
}

#define PrintDTObject(o, w, r...) ___PrintDTObject(DATATYPES_BASE_NAME, o, w, r)
#endif

#define ObtainDTDrawInfoA(o, attrs) ({ \
  Object * _ObtainDTDrawInfoA_o = (o); \
  CONST struct TagItem * _ObtainDTDrawInfoA_attrs = (attrs); \
  APTR _ObtainDTDrawInfoA__re = \
  ({ \
  register struct Library * const __ObtainDTDrawInfoA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register APTR __ObtainDTDrawInfoA__re __asm("d0"); \
  register Object * __ObtainDTDrawInfoA_o __asm("a0") = (_ObtainDTDrawInfoA_o); \
  register CONST struct TagItem * __ObtainDTDrawInfoA_attrs __asm("a1") = (_ObtainDTDrawInfoA_attrs); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__ObtainDTDrawInfoA__re) \
  : "r"(__ObtainDTDrawInfoA__bn), "r"(__ObtainDTDrawInfoA_o), "r"(__ObtainDTDrawInfoA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainDTDrawInfoA__re; \
  }); \
  _ObtainDTDrawInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___ObtainDTDrawInfo(struct Library * DataTypesBase, Object * o, Tag attrs, ...)
{
  return ObtainDTDrawInfoA(o, (CONST struct TagItem *) &attrs);
}

#define ObtainDTDrawInfo(o...) ___ObtainDTDrawInfo(DATATYPES_BASE_NAME, o)
#endif

#define DrawDTObjectA(rp, o, x, y, w, h, th, tv, attrs) ({ \
  struct RastPort * _DrawDTObjectA_rp = (rp); \
  Object * _DrawDTObjectA_o = (o); \
  LONG _DrawDTObjectA_x = (x); \
  LONG _DrawDTObjectA_y = (y); \
  LONG _DrawDTObjectA_w = (w); \
  LONG _DrawDTObjectA_h = (h); \
  LONG _DrawDTObjectA_th = (th); \
  LONG _DrawDTObjectA_tv = (tv); \
  CONST struct TagItem * _DrawDTObjectA_attrs = (attrs); \
  LONG _DrawDTObjectA__re = \
  ({ \
  register struct Library * const __DrawDTObjectA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register LONG __DrawDTObjectA__re __asm("d0"); \
  register struct RastPort * __DrawDTObjectA_rp __asm("a0") = (_DrawDTObjectA_rp); \
  register Object * __DrawDTObjectA_o __asm("a1") = (_DrawDTObjectA_o); \
  register LONG __DrawDTObjectA_x __asm("d0") = (_DrawDTObjectA_x); \
  register LONG __DrawDTObjectA_y __asm("d1") = (_DrawDTObjectA_y); \
  register LONG __DrawDTObjectA_w __asm("d2") = (_DrawDTObjectA_w); \
  register LONG __DrawDTObjectA_h __asm("d3") = (_DrawDTObjectA_h); \
  register LONG __DrawDTObjectA_th __asm("d4") = (_DrawDTObjectA_th); \
  register LONG __DrawDTObjectA_tv __asm("d5") = (_DrawDTObjectA_tv); \
  register CONST struct TagItem * __DrawDTObjectA_attrs __asm("a2") = (_DrawDTObjectA_attrs); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__DrawDTObjectA__re) \
  : "r"(__DrawDTObjectA__bn), "r"(__DrawDTObjectA_rp), "r"(__DrawDTObjectA_o), "r"(__DrawDTObjectA_x), "r"(__DrawDTObjectA_y), "r"(__DrawDTObjectA_w), "r"(__DrawDTObjectA_h), "r"(__DrawDTObjectA_th), "r"(__DrawDTObjectA_tv), "r"(__DrawDTObjectA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DrawDTObjectA__re; \
  }); \
  _DrawDTObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___DrawDTObject(struct Library * DataTypesBase, struct RastPort * rp, Object * o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, Tag attrs, ...)
{
  return DrawDTObjectA(rp, o, x, y, w, h, th, tv, (CONST struct TagItem *) &attrs);
}

#define DrawDTObject(rp, o, x, y, w, h, th, tv...) ___DrawDTObject(DATATYPES_BASE_NAME, rp, o, x, y, w, h, th, tv)
#endif

#define ReleaseDTDrawInfo(o, handle) ({ \
  Object * _ReleaseDTDrawInfo_o = (o); \
  APTR _ReleaseDTDrawInfo_handle = (handle); \
  { \
  register struct Library * const __ReleaseDTDrawInfo__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register Object * __ReleaseDTDrawInfo_o __asm("a0") = (_ReleaseDTDrawInfo_o); \
  register APTR __ReleaseDTDrawInfo_handle __asm("a1") = (_ReleaseDTDrawInfo_handle); \
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__ReleaseDTDrawInfo__bn), "r"(__ReleaseDTDrawInfo_o), "r"(__ReleaseDTDrawInfo_handle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetDTString(id) ({ \
  ULONG _GetDTString_id = (id); \
  CONST_STRPTR _GetDTString__re = \
  ({ \
  register struct Library * const __GetDTString__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register CONST_STRPTR __GetDTString__re __asm("d0"); \
  register ULONG __GetDTString_id __asm("d0") = (_GetDTString_id); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__GetDTString__re) \
  : "r"(__GetDTString__bn), "r"(__GetDTString_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDTString__re; \
  }); \
  _GetDTString__re; \
})

#define FindMethod(methods, id) ({ \
  ULONG * _FindMethod_methods = (methods); \
  ULONG _FindMethod_id = (id); \
  ULONG           * _FindMethod__re = \
  ({ \
  register struct Library * const __FindMethod__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG           * __FindMethod__re __asm("d0"); \
  register ULONG * __FindMethod_methods __asm("a0") = (_FindMethod_methods); \
  register ULONG __FindMethod_id __asm("a1") = (_FindMethod_id); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r"(__FindMethod__re) \
  : "r"(__FindMethod__bn), "r"(__FindMethod_methods), "r"(__FindMethod_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindMethod__re; \
  }); \
  _FindMethod__re; \
})

#define FindTriggerMethod(triggermethods, command, method) ({ \
  struct DTMethod * _FindTriggerMethod_triggermethods = (triggermethods); \
  CONST_STRPTR _FindTriggerMethod_command = (command); \
  ULONG _FindTriggerMethod_method = (method); \
  struct DTMethod * _FindTriggerMethod__re = \
  ({ \
  register struct Library * const __FindTriggerMethod__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register struct DTMethod * __FindTriggerMethod__re __asm("d0"); \
  register struct DTMethod * __FindTriggerMethod_triggermethods __asm("a0") = (_FindTriggerMethod_triggermethods); \
  register CONST_STRPTR __FindTriggerMethod_command __asm("a1") = (_FindTriggerMethod_command); \
  register ULONG __FindTriggerMethod_method __asm("d0") = (_FindTriggerMethod_method); \
  __asm volatile ("jsr a6@(-264:W)" \
  : "=r"(__FindTriggerMethod__re) \
  : "r"(__FindTriggerMethod__bn), "r"(__FindTriggerMethod_triggermethods), "r"(__FindTriggerMethod_command), "r"(__FindTriggerMethod_method) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindTriggerMethod__re; \
  }); \
  _FindTriggerMethod__re; \
})

#define CopyDTMethods(src, include, exclude) ({ \
  ULONG * _CopyDTMethods_src = (src); \
  ULONG * _CopyDTMethods_include = (include); \
  ULONG * _CopyDTMethods_exclude = (exclude); \
  ULONG           * _CopyDTMethods__re = \
  ({ \
  register struct Library * const __CopyDTMethods__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG           * __CopyDTMethods__re __asm("d0"); \
  register ULONG * __CopyDTMethods_src __asm("a0") = (_CopyDTMethods_src); \
  register ULONG * __CopyDTMethods_include __asm("a1") = (_CopyDTMethods_include); \
  register ULONG * __CopyDTMethods_exclude __asm("a2") = (_CopyDTMethods_exclude); \
  __asm volatile ("jsr a6@(-270:W)" \
  : "=r"(__CopyDTMethods__re) \
  : "r"(__CopyDTMethods__bn), "r"(__CopyDTMethods_src), "r"(__CopyDTMethods_include), "r"(__CopyDTMethods_exclude) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CopyDTMethods__re; \
  }); \
  _CopyDTMethods__re; \
})

#define CopyDTTriggerMethods(src, include, exclude) ({ \
  struct DTMethod * _CopyDTTriggerMethods_src = (src); \
  struct DTMethod * _CopyDTTriggerMethods_include = (include); \
  struct DTMethod * _CopyDTTriggerMethods_exclude = (exclude); \
  struct DTMethod * _CopyDTTriggerMethods__re = \
  ({ \
  register struct Library * const __CopyDTTriggerMethods__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register struct DTMethod * __CopyDTTriggerMethods__re __asm("d0"); \
  register struct DTMethod * __CopyDTTriggerMethods_src __asm("a0") = (_CopyDTTriggerMethods_src); \
  register struct DTMethod * __CopyDTTriggerMethods_include __asm("a1") = (_CopyDTTriggerMethods_include); \
  register struct DTMethod * __CopyDTTriggerMethods_exclude __asm("a2") = (_CopyDTTriggerMethods_exclude); \
  __asm volatile ("jsr a6@(-276:W)" \
  : "=r"(__CopyDTTriggerMethods__re) \
  : "r"(__CopyDTTriggerMethods__bn), "r"(__CopyDTTriggerMethods_src), "r"(__CopyDTTriggerMethods_include), "r"(__CopyDTTriggerMethods_exclude) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CopyDTTriggerMethods__re; \
  }); \
  _CopyDTTriggerMethods__re; \
})

#define FreeDTMethods(m) ({ \
  APTR _FreeDTMethods_m = (m); \
  { \
  register struct Library * const __FreeDTMethods__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register APTR __FreeDTMethods_m __asm("a0") = (_FreeDTMethods_m); \
  __asm volatile ("jsr a6@(-282:W)" \
  : \
  : "r"(__FreeDTMethods__bn), "r"(__FreeDTMethods_m) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SaveDTObjectA(o, win, req, file, mode, saveicon, attrs) ({ \
  Object * _SaveDTObjectA_o = (o); \
  struct Window * _SaveDTObjectA_win = (win); \
  struct Requester * _SaveDTObjectA_req = (req); \
  CONST_STRPTR _SaveDTObjectA_file = (file); \
  ULONG _SaveDTObjectA_mode = (mode); \
  BOOL _SaveDTObjectA_saveicon = (saveicon); \
  CONST struct TagItem * _SaveDTObjectA_attrs = (attrs); \
  ULONG _SaveDTObjectA__re = \
  ({ \
  register struct Library * const __SaveDTObjectA__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __SaveDTObjectA__re __asm("d0"); \
  register Object * __SaveDTObjectA_o __asm("a0") = (_SaveDTObjectA_o); \
  register struct Window * __SaveDTObjectA_win __asm("a1") = (_SaveDTObjectA_win); \
  register struct Requester * __SaveDTObjectA_req __asm("a2") = (_SaveDTObjectA_req); \
  register CONST_STRPTR __SaveDTObjectA_file __asm("a3") = (_SaveDTObjectA_file); \
  register ULONG __SaveDTObjectA_mode __asm("d0") = (_SaveDTObjectA_mode); \
  register BOOL __SaveDTObjectA_saveicon __asm("d1") = (_SaveDTObjectA_saveicon); \
  register CONST struct TagItem * __SaveDTObjectA_attrs __asm("d2") = (_SaveDTObjectA_attrs); \
  __asm volatile ("exg a4,d2\n\tjsr a6@(-294:W)\n\texg a4,d2" \
  : "=r"(__SaveDTObjectA__re) \
  : "r"(__SaveDTObjectA__bn), "r"(__SaveDTObjectA_o), "r"(__SaveDTObjectA_win), "r"(__SaveDTObjectA_req), "r"(__SaveDTObjectA_file), "r"(__SaveDTObjectA_mode), "r"(__SaveDTObjectA_saveicon), "r"(__SaveDTObjectA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SaveDTObjectA__re; \
  }); \
  _SaveDTObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SaveDTObject(struct Library * DataTypesBase, Object * o, struct Window * win, struct Requester * req, CONST_STRPTR file, ULONG mode, BOOL saveicon, Tag attrs, ...)
{
  return SaveDTObjectA(o, win, req, file, mode, saveicon, (CONST struct TagItem *) &attrs);
}

#define SaveDTObject(o, win, req, file, mode, saveicon...) ___SaveDTObject(DATATYPES_BASE_NAME, o, win, req, file, mode, saveicon)
#endif

#define StartDragSelect(o) ({ \
  Object * _StartDragSelect_o = (o); \
  ULONG _StartDragSelect__re = \
  ({ \
  register struct Library * const __StartDragSelect__bn __asm("a6") = (struct Library *) (DATATYPES_BASE_NAME);\
  register ULONG __StartDragSelect__re __asm("d0"); \
  register Object * __StartDragSelect_o __asm("a0") = (_StartDragSelect_o); \
  __asm volatile ("jsr a6@(-300:W)" \
  : "=r"(__StartDragSelect__re) \
  : "r"(__StartDragSelect__bn), "r"(__StartDragSelect_o) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StartDragSelect__re; \
  }); \
  _StartDragSelect__re; \
})

#endif /*  _INLINE_DATATYPES_H  */
