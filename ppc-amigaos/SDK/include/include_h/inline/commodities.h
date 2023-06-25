#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_COMMODITIES_H
#define _INLINE_COMMODITIES_H

#ifndef CLIB_COMMODITIES_PROTOS_H
#define CLIB_COMMODITIES_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef  LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif
#ifndef  DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef  DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif

#ifndef COMMODITIES_BASE_NAME
#define COMMODITIES_BASE_NAME CxBase
#endif

#define CreateCxObj(type, arg1, arg2) ({ \
  ULONG _CreateCxObj_type = (type); \
  LONG _CreateCxObj_arg1 = (arg1); \
  LONG _CreateCxObj_arg2 = (arg2); \
  CxObj * _CreateCxObj__re = \
  ({ \
  register struct Library * const __CreateCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __CreateCxObj__re __asm("d0"); \
  register ULONG __CreateCxObj_type __asm("d0") = (_CreateCxObj_type); \
  register LONG __CreateCxObj_arg1 __asm("a0") = (_CreateCxObj_arg1); \
  register LONG __CreateCxObj_arg2 __asm("a1") = (_CreateCxObj_arg2); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__CreateCxObj__re) \
  : "r"(__CreateCxObj__bn), "r"(__CreateCxObj_type), "r"(__CreateCxObj_arg1), "r"(__CreateCxObj_arg2) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateCxObj__re; \
  }); \
  _CreateCxObj__re; \
})

#define CxBroker(nb, error) ({ \
  const struct NewBroker * _CxBroker_nb = (nb); \
  LONG * _CxBroker_error = (error); \
  CxObj * _CxBroker__re = \
  ({ \
  register struct Library * const __CxBroker__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __CxBroker__re __asm("d0"); \
  register const struct NewBroker * __CxBroker_nb __asm("a0") = (_CxBroker_nb); \
  register LONG * __CxBroker_error __asm("d0") = (_CxBroker_error); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__CxBroker__re) \
  : "r"(__CxBroker__bn), "r"(__CxBroker_nb), "r"(__CxBroker_error) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CxBroker__re; \
  }); \
  _CxBroker__re; \
})

#define ActivateCxObj(co, doIt) ({ \
  CxObj * _ActivateCxObj_co = (co); \
  LONG _ActivateCxObj_doIt = (doIt); \
  LONG _ActivateCxObj__re = \
  ({ \
  register struct Library * const __ActivateCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register LONG __ActivateCxObj__re __asm("d0"); \
  register CxObj * __ActivateCxObj_co __asm("a0") = (_ActivateCxObj_co); \
  register LONG __ActivateCxObj_doIt __asm("d0") = (_ActivateCxObj_doIt); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__ActivateCxObj__re) \
  : "r"(__ActivateCxObj__bn), "r"(__ActivateCxObj_co), "r"(__ActivateCxObj_doIt) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ActivateCxObj__re; \
  }); \
  _ActivateCxObj__re; \
})

#define DeleteCxObj(co) ({ \
  CxObj * _DeleteCxObj_co = (co); \
  { \
  register struct Library * const __DeleteCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __DeleteCxObj_co __asm("a0") = (_DeleteCxObj_co); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__DeleteCxObj__bn), "r"(__DeleteCxObj_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DeleteCxObjAll(co) ({ \
  CxObj * _DeleteCxObjAll_co = (co); \
  { \
  register struct Library * const __DeleteCxObjAll__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __DeleteCxObjAll_co __asm("a0") = (_DeleteCxObjAll_co); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__DeleteCxObjAll__bn), "r"(__DeleteCxObjAll_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CxObjType(co) ({ \
  const CxObj * _CxObjType_co = (co); \
  ULONG _CxObjType__re = \
  ({ \
  register struct Library * const __CxObjType__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register ULONG __CxObjType__re __asm("d0"); \
  register const CxObj * __CxObjType_co __asm("a0") = (_CxObjType_co); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__CxObjType__re) \
  : "r"(__CxObjType__bn), "r"(__CxObjType_co) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CxObjType__re; \
  }); \
  _CxObjType__re; \
})

#define CxObjError(co) ({ \
  const CxObj * _CxObjError_co = (co); \
  LONG _CxObjError__re = \
  ({ \
  register struct Library * const __CxObjError__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register LONG __CxObjError__re __asm("d0"); \
  register const CxObj * __CxObjError_co __asm("a0") = (_CxObjError_co); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__CxObjError__re) \
  : "r"(__CxObjError__bn), "r"(__CxObjError_co) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CxObjError__re; \
  }); \
  _CxObjError__re; \
})

#define ClearCxObjError(co) ({ \
  CxObj * _ClearCxObjError_co = (co); \
  { \
  register struct Library * const __ClearCxObjError__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __ClearCxObjError_co __asm("a0") = (_ClearCxObjError_co); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__ClearCxObjError__bn), "r"(__ClearCxObjError_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetCxObjPri(co, pri) ({ \
  CxObj * _SetCxObjPri_co = (co); \
  LONG _SetCxObjPri_pri = (pri); \
  LONG _SetCxObjPri__re = \
  ({ \
  register struct Library * const __SetCxObjPri__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register LONG __SetCxObjPri__re __asm("d0"); \
  register CxObj * __SetCxObjPri_co __asm("a0") = (_SetCxObjPri_co); \
  register LONG __SetCxObjPri_pri __asm("d0") = (_SetCxObjPri_pri); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__SetCxObjPri__re) \
  : "r"(__SetCxObjPri__bn), "r"(__SetCxObjPri_co), "r"(__SetCxObjPri_pri) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetCxObjPri__re; \
  }); \
  _SetCxObjPri__re; \
})

#define AttachCxObj(headObj, co) ({ \
  CxObj * _AttachCxObj_headObj = (headObj); \
  CxObj * _AttachCxObj_co = (co); \
  { \
  register struct Library * const __AttachCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __AttachCxObj_headObj __asm("a0") = (_AttachCxObj_headObj); \
  register CxObj * __AttachCxObj_co __asm("a1") = (_AttachCxObj_co); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__AttachCxObj__bn), "r"(__AttachCxObj_headObj), "r"(__AttachCxObj_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define EnqueueCxObj(headObj, co) ({ \
  CxObj * _EnqueueCxObj_headObj = (headObj); \
  CxObj * _EnqueueCxObj_co = (co); \
  { \
  register struct Library * const __EnqueueCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __EnqueueCxObj_headObj __asm("a0") = (_EnqueueCxObj_headObj); \
  register CxObj * __EnqueueCxObj_co __asm("a1") = (_EnqueueCxObj_co); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__EnqueueCxObj__bn), "r"(__EnqueueCxObj_headObj), "r"(__EnqueueCxObj_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InsertCxObj(headObj, co, pred) ({ \
  CxObj * _InsertCxObj_headObj = (headObj); \
  CxObj * _InsertCxObj_co = (co); \
  CxObj * _InsertCxObj_pred = (pred); \
  { \
  register struct Library * const __InsertCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __InsertCxObj_headObj __asm("a0") = (_InsertCxObj_headObj); \
  register CxObj * __InsertCxObj_co __asm("a1") = (_InsertCxObj_co); \
  register CxObj * __InsertCxObj_pred __asm("a2") = (_InsertCxObj_pred); \
  __asm volatile ("jsr a6@(-96:W)" \
  : \
  : "r"(__InsertCxObj__bn), "r"(__InsertCxObj_headObj), "r"(__InsertCxObj_co), "r"(__InsertCxObj_pred) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemoveCxObj(co) ({ \
  CxObj * _RemoveCxObj_co = (co); \
  { \
  register struct Library * const __RemoveCxObj__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __RemoveCxObj_co __asm("a0") = (_RemoveCxObj_co); \
  __asm volatile ("jsr a6@(-102:W)" \
  : \
  : "r"(__RemoveCxObj__bn), "r"(__RemoveCxObj_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetTranslate(translator, events) ({ \
  CxObj * _SetTranslate_translator = (translator); \
  struct InputEvent * _SetTranslate_events = (events); \
  { \
  register struct Library * const __SetTranslate__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __SetTranslate_translator __asm("a0") = (_SetTranslate_translator); \
  register struct InputEvent * __SetTranslate_events __asm("a1") = (_SetTranslate_events); \
  __asm volatile ("jsr a6@(-114:W)" \
  : \
  : "r"(__SetTranslate__bn), "r"(__SetTranslate_translator), "r"(__SetTranslate_events) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetFilter(filter, text) ({ \
  CxObj * _SetFilter_filter = (filter); \
  CONST_STRPTR _SetFilter_text = (text); \
  { \
  register struct Library * const __SetFilter__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __SetFilter_filter __asm("a0") = (_SetFilter_filter); \
  register CONST_STRPTR __SetFilter_text __asm("a1") = (_SetFilter_text); \
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__SetFilter__bn), "r"(__SetFilter_filter), "r"(__SetFilter_text) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetFilterIX(filter, ix) ({ \
  CxObj * _SetFilterIX_filter = (filter); \
  const IX * _SetFilterIX_ix = (ix); \
  { \
  register struct Library * const __SetFilterIX__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxObj * __SetFilterIX_filter __asm("a0") = (_SetFilterIX_filter); \
  register const IX * __SetFilterIX_ix __asm("a1") = (_SetFilterIX_ix); \
  __asm volatile ("jsr a6@(-126:W)" \
  : \
  : "r"(__SetFilterIX__bn), "r"(__SetFilterIX_filter), "r"(__SetFilterIX_ix) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ParseIX(description, ix) ({ \
  CONST_STRPTR _ParseIX_description = (description); \
  IX * _ParseIX_ix = (ix); \
  LONG _ParseIX__re = \
  ({ \
  register struct Library * const __ParseIX__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register LONG __ParseIX__re __asm("d0"); \
  register CONST_STRPTR __ParseIX_description __asm("a0") = (_ParseIX_description); \
  register IX * __ParseIX_ix __asm("a1") = (_ParseIX_ix); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__ParseIX__re) \
  : "r"(__ParseIX__bn), "r"(__ParseIX_description), "r"(__ParseIX_ix) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ParseIX__re; \
  }); \
  _ParseIX__re; \
})

#define CxMsgType(cxm) ({ \
  const CxMsg * _CxMsgType_cxm = (cxm); \
  ULONG _CxMsgType__re = \
  ({ \
  register struct Library * const __CxMsgType__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register ULONG __CxMsgType__re __asm("d0"); \
  register const CxMsg * __CxMsgType_cxm __asm("a0") = (_CxMsgType_cxm); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__CxMsgType__re) \
  : "r"(__CxMsgType__bn), "r"(__CxMsgType_cxm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CxMsgType__re; \
  }); \
  _CxMsgType__re; \
})

#define CxMsgData(cxm) ({ \
  const CxMsg * _CxMsgData_cxm = (cxm); \
  APTR _CxMsgData__re = \
  ({ \
  register struct Library * const __CxMsgData__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register APTR __CxMsgData__re __asm("d0"); \
  register const CxMsg * __CxMsgData_cxm __asm("a0") = (_CxMsgData_cxm); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__CxMsgData__re) \
  : "r"(__CxMsgData__bn), "r"(__CxMsgData_cxm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CxMsgData__re; \
  }); \
  _CxMsgData__re; \
})

#define CxMsgID(cxm) ({ \
  const CxMsg * _CxMsgID_cxm = (cxm); \
  LONG _CxMsgID__re = \
  ({ \
  register struct Library * const __CxMsgID__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register LONG __CxMsgID__re __asm("d0"); \
  register const CxMsg * __CxMsgID_cxm __asm("a0") = (_CxMsgID_cxm); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__CxMsgID__re) \
  : "r"(__CxMsgID__bn), "r"(__CxMsgID_cxm) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CxMsgID__re; \
  }); \
  _CxMsgID__re; \
})

#define DivertCxMsg(cxm, headObj, returnObj) ({ \
  CxMsg * _DivertCxMsg_cxm = (cxm); \
  CxObj * _DivertCxMsg_headObj = (headObj); \
  CxObj * _DivertCxMsg_returnObj = (returnObj); \
  { \
  register struct Library * const __DivertCxMsg__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxMsg * __DivertCxMsg_cxm __asm("a0") = (_DivertCxMsg_cxm); \
  register CxObj * __DivertCxMsg_headObj __asm("a1") = (_DivertCxMsg_headObj); \
  register CxObj * __DivertCxMsg_returnObj __asm("a2") = (_DivertCxMsg_returnObj); \
  __asm volatile ("jsr a6@(-156:W)" \
  : \
  : "r"(__DivertCxMsg__bn), "r"(__DivertCxMsg_cxm), "r"(__DivertCxMsg_headObj), "r"(__DivertCxMsg_returnObj) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RouteCxMsg(cxm, co) ({ \
  CxMsg * _RouteCxMsg_cxm = (cxm); \
  CxObj * _RouteCxMsg_co = (co); \
  { \
  register struct Library * const __RouteCxMsg__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxMsg * __RouteCxMsg_cxm __asm("a0") = (_RouteCxMsg_cxm); \
  register CxObj * __RouteCxMsg_co __asm("a1") = (_RouteCxMsg_co); \
  __asm volatile ("jsr a6@(-162:W)" \
  : \
  : "r"(__RouteCxMsg__bn), "r"(__RouteCxMsg_cxm), "r"(__RouteCxMsg_co) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DisposeCxMsg(cxm) ({ \
  CxMsg * _DisposeCxMsg_cxm = (cxm); \
  { \
  register struct Library * const __DisposeCxMsg__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register CxMsg * __DisposeCxMsg_cxm __asm("a0") = (_DisposeCxMsg_cxm); \
  __asm volatile ("jsr a6@(-168:W)" \
  : \
  : "r"(__DisposeCxMsg__bn), "r"(__DisposeCxMsg_cxm) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InvertKeyMap(ansiCode, event, km) ({ \
  ULONG _InvertKeyMap_ansiCode = (ansiCode); \
  struct InputEvent * _InvertKeyMap_event = (event); \
  const struct KeyMap * _InvertKeyMap_km = (km); \
  BOOL _InvertKeyMap__re = \
  ({ \
  register struct Library * const __InvertKeyMap__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register BOOL __InvertKeyMap__re __asm("d0"); \
  register ULONG __InvertKeyMap_ansiCode __asm("d0") = (_InvertKeyMap_ansiCode); \
  register struct InputEvent * __InvertKeyMap_event __asm("a0") = (_InvertKeyMap_event); \
  register const struct KeyMap * __InvertKeyMap_km __asm("a1") = (_InvertKeyMap_km); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__InvertKeyMap__re) \
  : "r"(__InvertKeyMap__bn), "r"(__InvertKeyMap_ansiCode), "r"(__InvertKeyMap_event), "r"(__InvertKeyMap_km) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __InvertKeyMap__re; \
  }); \
  _InvertKeyMap__re; \
})

#define AddIEvents(events) ({ \
  struct InputEvent * _AddIEvents_events = (events); \
  { \
  register struct Library * const __AddIEvents__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register struct InputEvent * __AddIEvents_events __asm("a0") = (_AddIEvents_events); \
  __asm volatile ("jsr a6@(-180:W)" \
  : \
  : "r"(__AddIEvents__bn), "r"(__AddIEvents_events) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MatchIX(event, ix) ({ \
  const struct InputEvent * _MatchIX_event = (event); \
  const IX * _MatchIX_ix = (ix); \
  BOOL _MatchIX__re = \
  ({ \
  register struct Library * const __MatchIX__bn __asm("a6") = (struct Library *) (COMMODITIES_BASE_NAME);\
  register BOOL __MatchIX__re __asm("d0"); \
  register const struct InputEvent * __MatchIX_event __asm("a0") = (_MatchIX_event); \
  register const IX * __MatchIX_ix __asm("a1") = (_MatchIX_ix); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__MatchIX__re) \
  : "r"(__MatchIX__bn), "r"(__MatchIX_event), "r"(__MatchIX_ix) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MatchIX__re; \
  }); \
  _MatchIX__re; \
})

#endif /*  _INLINE_COMMODITIES_H  */
