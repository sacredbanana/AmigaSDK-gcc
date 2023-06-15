/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_POSEIDON_H
#define _INLINE_POSEIDON_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __psdAllocVec(__reg("a6") struct Library * , __reg("d0") ULONG size ) = "\tjsr\t-30(a6)";
#define psdAllocVec(size) __psdAllocVec(PsdBase, (size))

VOID __psdFreeVec(__reg("a6") struct Library * , __reg("a1") APTR memptr ) = "\tjsr\t-36(a6)";
#define psdFreeVec(memptr) __psdFreeVec(PsdBase, (memptr))

VOID __psdLockWritePBase(__reg("a6") struct Library * ) = "\tjsr\t-42(a6)";
#define psdLockWritePBase() __psdLockWritePBase(PsdBase)

VOID __psdLockReadPBase(__reg("a6") struct Library * ) = "\tjsr\t-48(a6)";
#define psdLockReadPBase() __psdLockReadPBase(PsdBase)

VOID __psdUnlockPBase(__reg("a6") struct Library * ) = "\tjsr\t-54(a6)";
#define psdUnlockPBase() __psdUnlockPBase(PsdBase)

STRPTR __psdCopyStr(__reg("a6") struct Library * , __reg("a0") STRPTR name ) = "\tjsr\t-60(a6)";
#define psdCopyStr(name) __psdCopyStr(PsdBase, (name))

VOID __psdDelayMS(__reg("a6") struct Library * , __reg("d0") ULONG milli ) = "\tjsr\t-66(a6)";
#define psdDelayMS(milli) __psdDelayMS(PsdBase, (milli))

APTR __psdAddHardware(__reg("a6") struct Library * , __reg("a0") STRPTR name , __reg("d0") ULONG unit ) = "\tjsr\t-72(a6)";
#define psdAddHardware(name, unit) __psdAddHardware(PsdBase, (name), (unit))

VOID __psdRemHardware(__reg("a6") struct Library * , __reg("a0") APTR phw ) = "\tjsr\t-78(a6)";
#define psdRemHardware(phw) __psdRemHardware(PsdBase, (phw))

APTR __psdEnumerateHardware(__reg("a6") struct Library * , __reg("a0") APTR phw ) = "\tjsr\t-84(a6)";
#define psdEnumerateHardware(phw) __psdEnumerateHardware(PsdBase, (phw))

APTR __psdAllocDevice(__reg("a6") struct Library * , __reg("a0") APTR phw ) = "\tjsr\t-90(a6)";
#define psdAllocDevice(phw) __psdAllocDevice(PsdBase, (phw))

VOID __psdFreeDevice(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-96(a6)";
#define psdFreeDevice(pd) __psdFreeDevice(PsdBase, (pd))

VOID __psdLockReadDevice(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-102(a6)";
#define psdLockReadDevice(pd) __psdLockReadDevice(PsdBase, (pd))

VOID __psdLockWriteDevice(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-108(a6)";
#define psdLockWriteDevice(pd) __psdLockWriteDevice(PsdBase, (pd))

VOID __psdUnlockDevice(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-114(a6)";
#define psdUnlockDevice(pd) __psdUnlockDevice(PsdBase, (pd))

APTR __psdEnumerateDevice(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-120(a6)";
#define psdEnumerateDevice(pp) __psdEnumerateDevice(PsdBase, (pp))

APTR __psdGetNextDevice(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-126(a6)";
#define psdGetNextDevice(pd) __psdGetNextDevice(PsdBase, (pd))

LONG __psdGetAttrsA(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR psdstruct , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-132(a6)";
#define psdGetAttrsA(type, psdstruct, taglist) __psdGetAttrsA(PsdBase, (type), (psdstruct), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __psdGetAttrs(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR psdstruct , ULONG tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-132(a6)\n\tmovea.l\t(a7)+,a1";
#define psdGetAttrs(type, psdstruct, ...) __psdGetAttrs(PsdBase, (type), (psdstruct), __VA_ARGS__)
#endif

LONG __psdSetAttrsA(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR psdstruct , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-138(a6)";
#define psdSetAttrsA(type, psdstruct, taglist) __psdSetAttrsA(PsdBase, (type), (psdstruct), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __psdSetAttrs(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR psdstruct , ULONG tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-138(a6)\n\tmovea.l\t(a7)+,a1";
#define psdSetAttrs(type, psdstruct, ...) __psdSetAttrs(PsdBase, (type), (psdstruct), __VA_ARGS__)
#endif

APTR __psdAllocPipe(__reg("a6") struct Library * , __reg("a0") APTR pd , __reg("a1") struct MsgPort * mp , __reg("a2") APTR ep ) = "\tjsr\t-144(a6)";
#define psdAllocPipe(pd, mp, ep) __psdAllocPipe(PsdBase, (pd), (mp), (ep))

APTR __psdFreePipe(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-150(a6)";
#define psdFreePipe(pp) __psdFreePipe(PsdBase, (pp))

VOID __psdPipeSetup(__reg("a6") struct Library * , __reg("a1") APTR pp , __reg("d0") UWORD rt , __reg("d1") UWORD rq , __reg("d2") UWORD val , __reg("d3") UWORD idx ) = "\tjsr\t-156(a6)";
#define psdPipeSetup(pp, rt, rq, val, idx) __psdPipeSetup(PsdBase, (pp), (rt), (rq), (val), (idx))

LONG __psdDoPipe(__reg("a6") struct Library * , __reg("a1") APTR pp , __reg("a0") APTR data , __reg("d0") ULONG len ) = "\tjsr\t-162(a6)";
#define psdDoPipe(pp, data, len) __psdDoPipe(PsdBase, (pp), (data), (len))

VOID __psdSendPipe(__reg("a6") struct Library * , __reg("a1") APTR pp , __reg("a0") APTR data , __reg("d0") ULONG len ) = "\tjsr\t-168(a6)";
#define psdSendPipe(pp, data, len) __psdSendPipe(PsdBase, (pp), (data), (len))

VOID __psdAbortPipe(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-174(a6)";
#define psdAbortPipe(pp) __psdAbortPipe(PsdBase, (pp))

LONG __psdWaitPipe(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-180(a6)";
#define psdWaitPipe(pp) __psdWaitPipe(PsdBase, (pp))

ULONG __psdGetPipeActual(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-186(a6)";
#define psdGetPipeActual(pp) __psdGetPipeActual(PsdBase, (pp))

LONG __psdGetPipeError(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-192(a6)";
#define psdGetPipeError(pp) __psdGetPipeError(PsdBase, (pp))

STRPTR __psdGetStringDescriptor(__reg("a6") struct Library * , __reg("a1") APTR pp , __reg("d0") UWORD idx ) = "\tjsr\t-198(a6)";
#define psdGetStringDescriptor(pp, idx) __psdGetStringDescriptor(PsdBase, (pp), (idx))

BOOL __psdSetDeviceConfig(__reg("a6") struct Library * , __reg("a1") APTR pp , __reg("d0") UWORD cfgnum ) = "\tjsr\t-204(a6)";
#define psdSetDeviceConfig(pp, cfgnum) __psdSetDeviceConfig(PsdBase, (pp), (cfgnum))

APTR __psdAddClass(__reg("a6") struct Library * , __reg("a1") STRPTR name , __reg("d0") ULONG version ) = "\tjsr\t-210(a6)";
#define psdAddClass(name, version) __psdAddClass(PsdBase, (name), (version))

VOID __psdRemClass(__reg("a6") struct Library * , __reg("a1") APTR puc ) = "\tjsr\t-216(a6)";
#define psdRemClass(puc) __psdRemClass(PsdBase, (puc))

VOID __psdClassScan(__reg("a6") struct Library * ) = "\tjsr\t-222(a6)";
#define psdClassScan() __psdClassScan(PsdBase)

STRPTR __psdNumToStr(__reg("a6") struct Library * , __reg("d0") UWORD type , __reg("d1") LONG idx , __reg("a0") STRPTR defstr ) = "\tjsr\t-228(a6)";
#define psdNumToStr(type, idx, defstr) __psdNumToStr(PsdBase, (type), (idx), (defstr))

struct Task * __psdSpawnSubTask(__reg("a6") struct Library * , __reg("a0") STRPTR name , __reg("a1") APTR initpc , __reg("a2") APTR userdata ) = "\tjsr\t-234(a6)";
#define psdSpawnSubTask(name, initpc, userdata) __psdSpawnSubTask(PsdBase, (name), (initpc), (userdata))

APTR __psdAddErrorMsgA(__reg("a6") struct Library * , __reg("d0") UWORD level , __reg("a0") STRPTR origin , __reg("a1") STRPTR fmtstr , __reg("a2") APTR fmtdata ) = "\tjsr\t-240(a6)";
#define psdAddErrorMsgA(level, origin, fmtstr, fmtdata) __psdAddErrorMsgA(PsdBase, (level), (origin), (fmtstr), (fmtdata))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __psdAddErrorMsg(__reg("a6") struct Library * , __reg("d0") UWORD level , __reg("a0") STRPTR origin , STRPTR fmtstr , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-240(a6)\n\tmovea.l\t(a7)+,a1";
#define psdAddErrorMsg(level, origin, ...) __psdAddErrorMsg(PsdBase, (level), (origin), __VA_ARGS__)
#endif

VOID __psdRemErrorMsg(__reg("a6") struct Library * , __reg("a0") APTR pem ) = "\tjsr\t-246(a6)";
#define psdRemErrorMsg(pem) __psdRemErrorMsg(PsdBase, (pem))

VOID __psdSafeRawDoFmtA(__reg("a6") struct Library * , __reg("a0") STRPTR buf , __reg("d0") ULONG len , __reg("a1") STRPTR fmtstr , __reg("a2") APTR fmtdata ) = "\tjsr\t-252(a6)";
#define psdSafeRawDoFmtA(buf, len, fmtstr, fmtdata) __psdSafeRawDoFmtA(PsdBase, (buf), (len), (fmtstr), (fmtdata))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __psdSafeRawDoFmt(__reg("a6") struct Library * , __reg("a0") STRPTR buf , __reg("d0") ULONG len , STRPTR fmtstr , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-252(a6)\n\tmovea.l\t(a7)+,a1";
#define psdSafeRawDoFmt(buf, len, ...) __psdSafeRawDoFmt(PsdBase, (buf), (len), __VA_ARGS__)
#endif

BOOL __psdSetAltInterface(__reg("a6") struct Library * , __reg("a1") APTR pp , __reg("a0") APTR pif ) = "\tjsr\t-258(a6)";
#define psdSetAltInterface(pp, pif) __psdSetAltInterface(PsdBase, (pp), (pif))

APTR __psdFindDeviceA(__reg("a6") struct Library * , __reg("a0") APTR pd , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-264(a6)";
#define psdFindDeviceA(pd, taglist) __psdFindDeviceA(PsdBase, (pd), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __psdFindDevice(__reg("a6") struct Library * , __reg("a0") APTR pd , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-264(a6)\n\tmovea.l\t(a7)+,a1";
#define psdFindDevice(pd, ...) __psdFindDevice(PsdBase, (pd), __VA_ARGS__)
#endif

APTR __psdClaimAppBindingA(__reg("a6") struct Library * , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-270(a6)";
#define psdClaimAppBindingA(taglist) __psdClaimAppBindingA(PsdBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __psdClaimAppBinding(__reg("a6") struct Library * , ULONG tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-270(a6)\n\tmovea.l\t(a7)+,a1";
#define psdClaimAppBinding(...) __psdClaimAppBinding(PsdBase, __VA_ARGS__)
#endif

APTR __psdReleaseAppBinding(__reg("a6") struct Library * , __reg("a0") APTR pab ) = "\tjsr\t-276(a6)";
#define psdReleaseAppBinding(pab) __psdReleaseAppBinding(PsdBase, (pab))

APTR __psdAddEventHandler(__reg("a6") struct Library * , __reg("a1") struct MsgPort * mp , __reg("d0") ULONG msgmask ) = "\tjsr\t-282(a6)";
#define psdAddEventHandler(mp, msgmask) __psdAddEventHandler(PsdBase, (mp), (msgmask))

VOID __psdRemEventHandler(__reg("a6") struct Library * , __reg("a0") APTR peh ) = "\tjsr\t-288(a6)";
#define psdRemEventHandler(peh) __psdRemEventHandler(PsdBase, (peh))

VOID __psdSendEvent(__reg("a6") struct Library * , __reg("d0") ULONG ehmt , __reg("a0") APTR param1 , __reg("a1") APTR param2 ) = "\tjsr\t-294(a6)";
#define psdSendEvent(ehmt, param1, param2) __psdSendEvent(PsdBase, (ehmt), (param1), (param2))

VOID __psdReleaseDevBinding(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-300(a6)";
#define psdReleaseDevBinding(pd) __psdReleaseDevBinding(PsdBase, (pd))

VOID __psdReleaseIfBinding(__reg("a6") struct Library * , __reg("a0") APTR pif ) = "\tjsr\t-306(a6)";
#define psdReleaseIfBinding(pif) __psdReleaseIfBinding(PsdBase, (pif))

BOOL __psdReadCfg(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("a1") APTR formdata ) = "\tjsr\t-312(a6)";
#define psdReadCfg(pic, formdata) __psdReadCfg(PsdBase, (pic), (formdata))

APTR __psdWriteCfg(__reg("a6") struct Library * , __reg("a0") APTR pic ) = "\tjsr\t-318(a6)";
#define psdWriteCfg(pic) __psdWriteCfg(PsdBase, (pic))

APTR __psdFindCfgForm(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("d0") ULONG formid ) = "\tjsr\t-324(a6)";
#define psdFindCfgForm(pic, formid) __psdFindCfgForm(PsdBase, (pic), (formid))

APTR __psdNextCfgForm(__reg("a6") struct Library * , __reg("a0") APTR pic ) = "\tjsr\t-330(a6)";
#define psdNextCfgForm(pic) __psdNextCfgForm(PsdBase, (pic))

BOOL __psdRemCfgForm(__reg("a6") struct Library * , __reg("a0") APTR pic ) = "\tjsr\t-336(a6)";
#define psdRemCfgForm(pic) __psdRemCfgForm(PsdBase, (pic))

APTR __psdAddCfgEntry(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("a1") APTR formdata ) = "\tjsr\t-342(a6)";
#define psdAddCfgEntry(pic, formdata) __psdAddCfgEntry(PsdBase, (pic), (formdata))

BOOL __psdRemCfgChunk(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("d0") ULONG chnkid ) = "\tjsr\t-348(a6)";
#define psdRemCfgChunk(pic, chnkid) __psdRemCfgChunk(PsdBase, (pic), (chnkid))

APTR __psdGetCfgChunk(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("d0") ULONG chnkid ) = "\tjsr\t-354(a6)";
#define psdGetCfgChunk(pic, chnkid) __psdGetCfgChunk(PsdBase, (pic), (chnkid))

VOID __psdParseCfg(__reg("a6") struct Library * ) = "\tjsr\t-360(a6)";
#define psdParseCfg() __psdParseCfg(PsdBase)

VOID __psdUnbindAll(__reg("a6") struct Library * ) = "\tjsr\t-366(a6)";
#define psdUnbindAll() __psdUnbindAll(PsdBase)

BOOL __psdSetClsCfg(__reg("a6") struct Library * , __reg("a0") STRPTR owner , __reg("a1") APTR form ) = "\tjsr\t-372(a6)";
#define psdSetClsCfg(owner, form) __psdSetClsCfg(PsdBase, (owner), (form))

APTR __psdGetClsCfg(__reg("a6") struct Library * , __reg("a0") STRPTR owner ) = "\tjsr\t-378(a6)";
#define psdGetClsCfg(owner) __psdGetClsCfg(PsdBase, (owner))

BOOL __psdSetUsbDevCfg(__reg("a6") struct Library * , __reg("a0") STRPTR owner , __reg("a2") STRPTR devid , __reg("a3") STRPTR ifid , __reg("a1") APTR form ) = "\tjsr\t-384(a6)";
#define psdSetUsbDevCfg(owner, devid, ifid, form) __psdSetUsbDevCfg(PsdBase, (owner), (devid), (ifid), (form))

APTR __psdGetUsbDevCfg(__reg("a6") struct Library * , __reg("a0") STRPTR owner , __reg("a2") STRPTR devid , __reg("a3") STRPTR ifid ) = "\tjsr\t-390(a6)";
#define psdGetUsbDevCfg(owner, devid, ifid) __psdGetUsbDevCfg(PsdBase, (owner), (devid), (ifid))

APTR __psdFindInterfaceA(__reg("a6") struct Library * , __reg("a0") APTR pd , __reg("a2") APTR pif , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-396(a6)";
#define psdFindInterfaceA(pd, pif, taglist) __psdFindInterfaceA(PsdBase, (pd), (pif), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __psdFindInterface(__reg("a6") struct Library * , __reg("a0") APTR pd , __reg("a2") APTR pif , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-396(a6)\n\tmovea.l\t(a7)+,a1";
#define psdFindInterface(pd, pif, ...) __psdFindInterface(PsdBase, (pd), (pif), __VA_ARGS__)
#endif

APTR __psdFindEndpointA(__reg("a6") struct Library * , __reg("a0") APTR pif , __reg("a2") APTR pep , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-402(a6)";
#define psdFindEndpointA(pif, pep, taglist) __psdFindEndpointA(PsdBase, (pif), (pep), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __psdFindEndpoint(__reg("a6") struct Library * , __reg("a0") APTR pif , __reg("a2") APTR pep , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-402(a6)\n\tmovea.l\t(a7)+,a1";
#define psdFindEndpoint(pif, pep, ...) __psdFindEndpoint(PsdBase, (pif), (pep), __VA_ARGS__)
#endif

STRPTR __psdCopyStrFmtA(__reg("a6") struct Library * , __reg("a0") STRPTR fmtstr , __reg("a1") APTR fmtdata ) = "\tjsr\t-408(a6)";
#define psdCopyStrFmtA(fmtstr, fmtdata) __psdCopyStrFmtA(PsdBase, (fmtstr), (fmtdata))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
STRPTR __psdCopyStrFmt(__reg("a6") struct Library * , STRPTR fmtstr , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-408(a6)\n\tmovea.l\t(a7)+,a0";
#define psdCopyStrFmt(...) __psdCopyStrFmt(PsdBase, __VA_ARGS__)
#endif

BOOL __psdSetForcedBinding(__reg("a6") struct Library * , __reg("a2") STRPTR owner , __reg("a0") STRPTR devid , __reg("a1") STRPTR ifid ) = "\tjsr\t-414(a6)";
#define psdSetForcedBinding(owner, devid, ifid) __psdSetForcedBinding(PsdBase, (owner), (devid), (ifid))

STRPTR __psdGetForcedBinding(__reg("a6") struct Library * , __reg("a0") STRPTR devid , __reg("a1") STRPTR ifid ) = "\tjsr\t-420(a6)";
#define psdGetForcedBinding(devid, ifid) __psdGetForcedBinding(PsdBase, (devid), (ifid))

APTR __psdCheckPipe(__reg("a6") struct Library * , __reg("a1") APTR pp ) = "\tjsr\t-426(a6)";
#define psdCheckPipe(pp) __psdCheckPipe(PsdBase, (pp))

APTR __psdOpenStreamA(__reg("a6") struct Library * , __reg("a0") APTR ep , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-432(a6)";
#define psdOpenStreamA(ep, taglist) __psdOpenStreamA(PsdBase, (ep), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __psdOpenStream(__reg("a6") struct Library * , __reg("a0") APTR ep , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-432(a6)\n\tmovea.l\t(a7)+,a1";
#define psdOpenStream(ep, ...) __psdOpenStream(PsdBase, (ep), __VA_ARGS__)
#endif

VOID __psdCloseStream(__reg("a6") struct Library * , __reg("a1") APTR pps ) = "\tjsr\t-438(a6)";
#define psdCloseStream(pps) __psdCloseStream(PsdBase, (pps))

LONG __psdStreamRead(__reg("a6") struct Library * , __reg("a1") APTR pps , __reg("a0") APTR buffer , __reg("d0") LONG length ) = "\tjsr\t-444(a6)";
#define psdStreamRead(pps, buffer, length) __psdStreamRead(PsdBase, (pps), (buffer), (length))

LONG __psdStreamWrite(__reg("a6") struct Library * , __reg("a1") APTR pps , __reg("a0") APTR buffer , __reg("d0") LONG length ) = "\tjsr\t-450(a6)";
#define psdStreamWrite(pps, buffer, length) __psdStreamWrite(PsdBase, (pps), (buffer), (length))

LONG __psdStreamFlush(__reg("a6") struct Library * , __reg("a1") APTR pps ) = "\tjsr\t-456(a6)";
#define psdStreamFlush(pps) __psdStreamFlush(PsdBase, (pps))

LONG __psdGetStreamError(__reg("a6") struct Library * , __reg("a1") APTR pps ) = "\tjsr\t-462(a6)";
#define psdGetStreamError(pps) __psdGetStreamError(PsdBase, (pps))

VOID __psdCalculatePower(__reg("a6") struct Library * , __reg("a0") APTR phw ) = "\tjsr\t-468(a6)";
#define psdCalculatePower(phw) __psdCalculatePower(PsdBase, (phw))

BOOL __psdLoadCfgFromDisk(__reg("a6") struct Library * , __reg("a1") STRPTR filename ) = "\tjsr\t-474(a6)";
#define psdLoadCfgFromDisk(filename) __psdLoadCfgFromDisk(PsdBase, (filename))

BOOL __psdSaveCfgToDisk(__reg("a6") struct Library * , __reg("a1") STRPTR filename , __reg("d0") BOOL mode ) = "\tjsr\t-480(a6)";
#define psdSaveCfgToDisk(filename, mode) __psdSaveCfgToDisk(PsdBase, (filename), (mode))

#endif /* !_INLINE_POSEIDON_H */
