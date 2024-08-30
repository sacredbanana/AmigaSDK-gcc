/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_COMMODITIES_H
#define _INLINE_COMMODITIES_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

CxObj * __CreateCxObj(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") LONG arg1 , __reg("a1") LONG arg2 ) = "\tjsr\t-30(a6)";
#define CreateCxObj(type, arg1, arg2) __CreateCxObj(CxBase, (type), (arg1), (arg2))

CxObj * __CxBroker(__reg("a6") struct Library * , __reg("a0") CONST struct NewBroker * nb , __reg("d0") LONG * error ) = "\tjsr\t-36(a6)";
#define CxBroker(nb, error) __CxBroker(CxBase, (nb), (error))

LONG __ActivateCxObj(__reg("a6") struct Library * , __reg("a0") CxObj * co , __reg("d0") LONG flag ) = "\tjsr\t-42(a6)";
#define ActivateCxObj(co, flag) __ActivateCxObj(CxBase, (co), (flag))

VOID __DeleteCxObj(__reg("a6") struct Library * , __reg("a0") CxObj * co ) = "\tjsr\t-48(a6)";
#define DeleteCxObj(co) __DeleteCxObj(CxBase, (co))

VOID __DeleteCxObjAll(__reg("a6") struct Library * , __reg("a0") CxObj * co ) = "\tjsr\t-54(a6)";
#define DeleteCxObjAll(co) __DeleteCxObjAll(CxBase, (co))

ULONG __CxObjType(__reg("a6") struct Library * , __reg("a0") CONST CxObj * co ) = "\tjsr\t-60(a6)";
#define CxObjType(co) __CxObjType(CxBase, (co))

LONG __CxObjError(__reg("a6") struct Library * , __reg("a0") CONST CxObj * co ) = "\tjsr\t-66(a6)";
#define CxObjError(co) __CxObjError(CxBase, (co))

VOID __ClearCxObjError(__reg("a6") struct Library * , __reg("a0") CxObj * co ) = "\tjsr\t-72(a6)";
#define ClearCxObjError(co) __ClearCxObjError(CxBase, (co))

LONG __SetCxObjPri(__reg("a6") struct Library * , __reg("a0") CxObj * co , __reg("d0") LONG pri ) = "\tjsr\t-78(a6)";
#define SetCxObjPri(co, pri) __SetCxObjPri(CxBase, (co), (pri))

VOID __AttachCxObj(__reg("a6") struct Library * , __reg("a0") CxObj * headObj , __reg("a1") CxObj * co ) = "\tjsr\t-84(a6)";
#define AttachCxObj(headObj, co) __AttachCxObj(CxBase, (headObj), (co))

VOID __EnqueueCxObj(__reg("a6") struct Library * , __reg("a0") CxObj * headObj , __reg("a1") CxObj * co ) = "\tjsr\t-90(a6)";
#define EnqueueCxObj(headObj, co) __EnqueueCxObj(CxBase, (headObj), (co))

VOID __InsertCxObj(__reg("a6") struct Library * , __reg("a0") CxObj * headObj , __reg("a1") CxObj * co , __reg("a2") CxObj * pred ) = "\tjsr\t-96(a6)";
#define InsertCxObj(headObj, co, pred) __InsertCxObj(CxBase, (headObj), (co), (pred))

VOID __RemoveCxObj(__reg("a6") struct Library * , __reg("a0") CxObj * co ) = "\tjsr\t-102(a6)";
#define RemoveCxObj(co) __RemoveCxObj(CxBase, (co))

VOID __SetTranslate(__reg("a6") struct Library * , __reg("a0") CxObj * translator , __reg("a1") struct InputEvent * events ) = "\tjsr\t-114(a6)";
#define SetTranslate(translator, events) __SetTranslate(CxBase, (translator), (events))

VOID __SetFilter(__reg("a6") struct Library * , __reg("a0") CxObj * filter , __reg("a1") CONST_STRPTR text ) = "\tjsr\t-120(a6)";
#define SetFilter(filter, text) __SetFilter(CxBase, (filter), (text))

VOID __SetFilterIX(__reg("a6") struct Library * , __reg("a0") CxObj * filter , __reg("a1") CONST IX * ix ) = "\tjsr\t-126(a6)";
#define SetFilterIX(filter, ix) __SetFilterIX(CxBase, (filter), (ix))

LONG __ParseIX(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR description , __reg("a1") IX * ix ) = "\tjsr\t-132(a6)";
#define ParseIX(description, ix) __ParseIX(CxBase, (description), (ix))

ULONG __CxMsgType(__reg("a6") struct Library * , __reg("a0") CONST CxMsg * cxm ) = "\tjsr\t-138(a6)";
#define CxMsgType(cxm) __CxMsgType(CxBase, (cxm))

APTR __CxMsgData(__reg("a6") struct Library * , __reg("a0") CONST CxMsg * cxm ) = "\tjsr\t-144(a6)";
#define CxMsgData(cxm) __CxMsgData(CxBase, (cxm))

LONG __CxMsgID(__reg("a6") struct Library * , __reg("a0") CONST CxMsg * cxm ) = "\tjsr\t-150(a6)";
#define CxMsgID(cxm) __CxMsgID(CxBase, (cxm))

VOID __DivertCxMsg(__reg("a6") struct Library * , __reg("a0") CxMsg * cxm , __reg("a1") CxObj * headObj , __reg("a2") CxObj * returnObj ) = "\tjsr\t-156(a6)";
#define DivertCxMsg(cxm, headObj, returnObj) __DivertCxMsg(CxBase, (cxm), (headObj), (returnObj))

VOID __RouteCxMsg(__reg("a6") struct Library * , __reg("a0") CxMsg * cxm , __reg("a1") CxObj * co ) = "\tjsr\t-162(a6)";
#define RouteCxMsg(cxm, co) __RouteCxMsg(CxBase, (cxm), (co))

VOID __DisposeCxMsg(__reg("a6") struct Library * , __reg("a0") CxMsg * cxm ) = "\tjsr\t-168(a6)";
#define DisposeCxMsg(cxm) __DisposeCxMsg(CxBase, (cxm))

BOOL __InvertKeyMap(__reg("a6") struct Library * , __reg("d0") ULONG ansiCode , __reg("a0") struct InputEvent * event , __reg("a1") CONST struct KeyMap * km ) = "\tjsr\t-174(a6)";
#define InvertKeyMap(ansiCode, event, km) __InvertKeyMap(CxBase, (ansiCode), (event), (km))

VOID __AddIEvents(__reg("a6") struct Library * , __reg("a0") struct InputEvent * events ) = "\tjsr\t-180(a6)";
#define AddIEvents(events) __AddIEvents(CxBase, (events))

BOOL __MatchIX(__reg("a6") struct Library * , __reg("a0") CONST struct InputEvent * event , __reg("a1") CONST IX * ix ) = "\tjsr\t-204(a6)";
#define MatchIX(event, ix) __MatchIX(CxBase, (event), (ix))

#endif /* !_INLINE_COMMODITIES_H */
