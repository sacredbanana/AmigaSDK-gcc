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

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef POSEIDON_BASE_NAME
#define POSEIDON_BASE_NAME PsdBase
#endif /* !POSEIDON_BASE_NAME */

#define psdAllocVec(___size) \
      LP1(0x1e, APTR, psdAllocVec , ULONG, ___size, d0,\
      , POSEIDON_BASE_NAME)

#define psdFreeVec(___memptr) \
      LP1NR(0x24, psdFreeVec , APTR, ___memptr, a1,\
      , POSEIDON_BASE_NAME)

#define psdLockWritePBase() \
      LP0NR(0x2a, psdLockWritePBase ,\
      , POSEIDON_BASE_NAME)

#define psdLockReadPBase() \
      LP0NR(0x30, psdLockReadPBase ,\
      , POSEIDON_BASE_NAME)

#define psdUnlockPBase() \
      LP0NR(0x36, psdUnlockPBase ,\
      , POSEIDON_BASE_NAME)

#define psdCopyStr(___name) \
      LP1(0x3c, STRPTR, psdCopyStr , STRPTR, ___name, a0,\
      , POSEIDON_BASE_NAME)

#define psdDelayMS(___milli) \
      LP1NR(0x42, psdDelayMS , ULONG, ___milli, d0,\
      , POSEIDON_BASE_NAME)

#define psdAddHardware(___name, ___unit) \
      LP2(0x48, APTR, psdAddHardware , STRPTR, ___name, a0, ULONG, ___unit, d0,\
      , POSEIDON_BASE_NAME)

#define psdRemHardware(___phw) \
      LP1NR(0x4e, psdRemHardware , APTR, ___phw, a0,\
      , POSEIDON_BASE_NAME)

#define psdEnumerateHardware(___phw) \
      LP1(0x54, APTR, psdEnumerateHardware , APTR, ___phw, a0,\
      , POSEIDON_BASE_NAME)

#define psdAllocDevice(___phw) \
      LP1(0x5a, APTR, psdAllocDevice , APTR, ___phw, a0,\
      , POSEIDON_BASE_NAME)

#define psdFreeDevice(___pd) \
      LP1NR(0x60, psdFreeDevice , APTR, ___pd, a0,\
      , POSEIDON_BASE_NAME)

#define psdLockReadDevice(___pd) \
      LP1NR(0x66, psdLockReadDevice , APTR, ___pd, a0,\
      , POSEIDON_BASE_NAME)

#define psdLockWriteDevice(___pd) \
      LP1NR(0x6c, psdLockWriteDevice , APTR, ___pd, a0,\
      , POSEIDON_BASE_NAME)

#define psdUnlockDevice(___pd) \
      LP1NR(0x72, psdUnlockDevice , APTR, ___pd, a0,\
      , POSEIDON_BASE_NAME)

#define psdEnumerateDevice(___pp) \
      LP1(0x78, APTR, psdEnumerateDevice , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetNextDevice(___pd) \
      LP1(0x7e, APTR, psdGetNextDevice , APTR, ___pd, a0,\
      , POSEIDON_BASE_NAME)

#define psdGetAttrsA(___type, ___psdstruct, ___taglist) \
      LP3(0x84, LONG, psdGetAttrsA , ULONG, ___type, d0, APTR, ___psdstruct, a0, struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdGetAttrs(___type, ___psdstruct, ___tag1, ...) \
    ({_sfdc_vararg _tags[] = { ___tag1, __VA_ARGS__ }; psdGetAttrsA((___type), (___psdstruct), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdSetAttrsA(___type, ___psdstruct, ___taglist) \
      LP3(0x8a, LONG, psdSetAttrsA , ULONG, ___type, d0, APTR, ___psdstruct, a0, struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdSetAttrs(___type, ___psdstruct, ___tag1, ...) \
    ({_sfdc_vararg _tags[] = { ___tag1, __VA_ARGS__ }; psdSetAttrsA((___type), (___psdstruct), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdAllocPipe(___pd, ___mp, ___ep) \
      LP3(0x90, APTR, psdAllocPipe , APTR, ___pd, a0, struct MsgPort *, ___mp, a1, APTR, ___ep, a2,\
      , POSEIDON_BASE_NAME)

#define psdFreePipe(___pp) \
      LP1(0x96, APTR, psdFreePipe , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdPipeSetup(___pp, ___rt, ___rq, ___val, ___idx) \
      LP5NR(0x9c, psdPipeSetup , APTR, ___pp, a1, UWORD, ___rt, d0, UWORD, ___rq, d1, UWORD, ___val, d2, UWORD, ___idx, d3,\
      , POSEIDON_BASE_NAME)

#define psdDoPipe(___pp, ___data, ___len) \
      LP3(0xa2, LONG, psdDoPipe , APTR, ___pp, a1, APTR, ___data, a0, ULONG, ___len, d0,\
      , POSEIDON_BASE_NAME)

#define psdSendPipe(___pp, ___data, ___len) \
      LP3NR(0xa8, psdSendPipe , APTR, ___pp, a1, APTR, ___data, a0, ULONG, ___len, d0,\
      , POSEIDON_BASE_NAME)

#define psdAbortPipe(___pp) \
      LP1NR(0xae, psdAbortPipe , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdWaitPipe(___pp) \
      LP1(0xb4, LONG, psdWaitPipe , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetPipeActual(___pp) \
      LP1(0xba, ULONG, psdGetPipeActual , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetPipeError(___pp) \
      LP1(0xc0, LONG, psdGetPipeError , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetStringDescriptor(___pp, ___idx) \
      LP2(0xc6, STRPTR, psdGetStringDescriptor , APTR, ___pp, a1, UWORD, ___idx, d0,\
      , POSEIDON_BASE_NAME)

#define psdSetDeviceConfig(___pp, ___cfgnum) \
      LP2(0xcc, BOOL, psdSetDeviceConfig , APTR, ___pp, a1, UWORD, ___cfgnum, d0,\
      , POSEIDON_BASE_NAME)

#define psdAddClass(___name, ___version) \
      LP2(0xd2, APTR, psdAddClass , STRPTR, ___name, a1, ULONG, ___version, d0,\
      , POSEIDON_BASE_NAME)

#define psdRemClass(___puc) \
      LP1NR(0xd8, psdRemClass , APTR, ___puc, a1,\
      , POSEIDON_BASE_NAME)

#define psdClassScan() \
      LP0NR(0xde, psdClassScan ,\
      , POSEIDON_BASE_NAME)

#define psdNumToStr(___type, ___idx, ___defstr) \
      LP3(0xe4, STRPTR, psdNumToStr , UWORD, ___type, d0, LONG, ___idx, d1, STRPTR, ___defstr, a0,\
      , POSEIDON_BASE_NAME)

#define psdSpawnSubTask(___name, ___initpc, ___userdata) \
      LP3(0xea, struct Task *, psdSpawnSubTask , STRPTR, ___name, a0, APTR, ___initpc, a1, APTR, ___userdata, a2,\
      , POSEIDON_BASE_NAME)

#define psdAddErrorMsgA(___level, ___origin, ___fmtstr, ___fmtdata) \
      LP4(0xf0, APTR, psdAddErrorMsgA , UWORD, ___level, d0, STRPTR, ___origin, a0, STRPTR, ___fmtstr, a1, APTR, ___fmtdata, a2,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_VARARGS
#define psdAddErrorMsg(___level, ___origin, ___fmtstr, ...) \
     ({_sfdc_vararg _args[] = { __VA_ARGS__ }; psdAddErrorMsgA((___level), (___origin), (___fmtstr), (APTR) _args); })
#endif /* !NO_INLINE_VARARGS */

#define psdRemErrorMsg(___pem) \
      LP1NR(0xf6, psdRemErrorMsg , APTR, ___pem, a0,\
      , POSEIDON_BASE_NAME)

#define psdSafeRawDoFmtA(___buf, ___len, ___fmtstr, ___fmtdata) \
      LP4NR(0xfc, psdSafeRawDoFmtA , STRPTR, ___buf, a0, ULONG, ___len, d0, STRPTR, ___fmtstr, a1, APTR, ___fmtdata, a2,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_VARARGS
#define psdSafeRawDoFmt(___buf, ___len, ___fmtstr, ...) \
     ({_sfdc_vararg _args[] = { __VA_ARGS__ }; psdSafeRawDoFmtA((___buf), (___len), (___fmtstr), (APTR) _args); })
#endif /* !NO_INLINE_VARARGS */

#define psdSetAltInterface(___pp, ___pif) \
      LP2(0x102, BOOL, psdSetAltInterface , APTR, ___pp, a1, APTR, ___pif, a0,\
      , POSEIDON_BASE_NAME)

#define psdFindDeviceA(___pd, ___taglist) \
      LP2(0x108, APTR, psdFindDeviceA , APTR, ___pd, a0, struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdFindDevice(___pd, ____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; psdFindDeviceA((___pd), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdClaimAppBindingA(___taglist) \
      LP1(0x10e, APTR, psdClaimAppBindingA , struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdClaimAppBinding(___tag1, ...) \
    ({_sfdc_vararg _tags[] = { ___tag1, __VA_ARGS__ }; psdClaimAppBindingA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdReleaseAppBinding(___pab) \
      LP1(0x114, APTR, psdReleaseAppBinding , APTR, ___pab, a0,\
      , POSEIDON_BASE_NAME)

#define psdAddEventHandler(___mp, ___msgmask) \
      LP2(0x11a, APTR, psdAddEventHandler , struct MsgPort *, ___mp, a1, ULONG, ___msgmask, d0,\
      , POSEIDON_BASE_NAME)

#define psdRemEventHandler(___peh) \
      LP1NR(0x120, psdRemEventHandler , APTR, ___peh, a0,\
      , POSEIDON_BASE_NAME)

#define psdSendEvent(___ehmt, ___param1, ___param2) \
      LP3NR(0x126, psdSendEvent , ULONG, ___ehmt, d0, APTR, ___param1, a0, APTR, ___param2, a1,\
      , POSEIDON_BASE_NAME)

#define psdReleaseDevBinding(___pd) \
      LP1NR(0x12c, psdReleaseDevBinding , APTR, ___pd, a0,\
      , POSEIDON_BASE_NAME)

#define psdReleaseIfBinding(___pif) \
      LP1NR(0x132, psdReleaseIfBinding , APTR, ___pif, a0,\
      , POSEIDON_BASE_NAME)

#define psdReadCfg(___pic, ___formdata) \
      LP2(0x138, BOOL, psdReadCfg , APTR, ___pic, a0, APTR, ___formdata, a1,\
      , POSEIDON_BASE_NAME)

#define psdWriteCfg(___pic) \
      LP1(0x13e, APTR, psdWriteCfg , APTR, ___pic, a0,\
      , POSEIDON_BASE_NAME)

#define psdFindCfgForm(___pic, ___formid) \
      LP2(0x144, APTR, psdFindCfgForm , APTR, ___pic, a0, ULONG, ___formid, d0,\
      , POSEIDON_BASE_NAME)

#define psdNextCfgForm(___pic) \
      LP1(0x14a, APTR, psdNextCfgForm , APTR, ___pic, a0,\
      , POSEIDON_BASE_NAME)

#define psdRemCfgForm(___pic) \
      LP1(0x150, BOOL, psdRemCfgForm , APTR, ___pic, a0,\
      , POSEIDON_BASE_NAME)

#define psdAddCfgEntry(___pic, ___formdata) \
      LP2(0x156, APTR, psdAddCfgEntry , APTR, ___pic, a0, APTR, ___formdata, a1,\
      , POSEIDON_BASE_NAME)

#define psdRemCfgChunk(___pic, ___chnkid) \
      LP2(0x15c, BOOL, psdRemCfgChunk , APTR, ___pic, a0, ULONG, ___chnkid, d0,\
      , POSEIDON_BASE_NAME)

#define psdGetCfgChunk(___pic, ___chnkid) \
      LP2(0x162, APTR, psdGetCfgChunk , APTR, ___pic, a0, ULONG, ___chnkid, d0,\
      , POSEIDON_BASE_NAME)

#define psdParseCfg() \
      LP0NR(0x168, psdParseCfg ,\
      , POSEIDON_BASE_NAME)

#define psdUnbindAll() \
      LP0NR(0x16e, psdUnbindAll ,\
      , POSEIDON_BASE_NAME)

#define psdSetClsCfg(___owner, ___form) \
      LP2(0x174, BOOL, psdSetClsCfg , STRPTR, ___owner, a0, APTR, ___form, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetClsCfg(___owner) \
      LP1(0x17a, APTR, psdGetClsCfg , STRPTR, ___owner, a0,\
      , POSEIDON_BASE_NAME)

#define psdSetUsbDevCfg(___owner, ___devid, ___ifid, ___form) \
      LP4(0x180, BOOL, psdSetUsbDevCfg , STRPTR, ___owner, a0, STRPTR, ___devid, a2, STRPTR, ___ifid, a3, APTR, ___form, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetUsbDevCfg(___owner, ___devid, ___ifid) \
      LP3(0x186, APTR, psdGetUsbDevCfg , STRPTR, ___owner, a0, STRPTR, ___devid, a2, STRPTR, ___ifid, a3,\
      , POSEIDON_BASE_NAME)

#define psdFindInterfaceA(___pd, ___pif, ___taglist) \
      LP3(0x18c, APTR, psdFindInterfaceA , APTR, ___pd, a0, APTR, ___pif, a2, struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdFindInterface(___pd, ___pif, ____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; psdFindInterfaceA((___pd), (___pif), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdFindEndpointA(___pif, ___pep, ___taglist) \
      LP3(0x192, APTR, psdFindEndpointA , APTR, ___pif, a0, APTR, ___pep, a2, struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdFindEndpoint(___pif, ___pep, ____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; psdFindEndpointA((___pif), (___pep), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdCopyStrFmtA(___fmtstr, ___fmtdata) \
      LP2(0x198, STRPTR, psdCopyStrFmtA , STRPTR, ___fmtstr, a0, APTR, ___fmtdata, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_VARARGS
#define psdCopyStrFmt(___fmtstr, ...) \
     ({_sfdc_vararg _args[] = { __VA_ARGS__ }; psdCopyStrFmtA((___fmtstr), (APTR) _args); })
#endif /* !NO_INLINE_VARARGS */

#define psdSetForcedBinding(___owner, ___devid, ___ifid) \
      LP3(0x19e, BOOL, psdSetForcedBinding , STRPTR, ___owner, a2, STRPTR, ___devid, a0, STRPTR, ___ifid, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetForcedBinding(___devid, ___ifid) \
      LP2(0x1a4, STRPTR, psdGetForcedBinding , STRPTR, ___devid, a0, STRPTR, ___ifid, a1,\
      , POSEIDON_BASE_NAME)

#define psdCheckPipe(___pp) \
      LP1(0x1aa, APTR, psdCheckPipe , APTR, ___pp, a1,\
      , POSEIDON_BASE_NAME)

#define psdOpenStreamA(___ep, ___taglist) \
      LP2(0x1b0, APTR, psdOpenStreamA , APTR, ___ep, a0, struct TagItem *, ___taglist, a1,\
      , POSEIDON_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define psdOpenStream(___ep, ____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; psdOpenStreamA((___ep), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define psdCloseStream(___pps) \
      LP1NR(0x1b6, psdCloseStream , APTR, ___pps, a1,\
      , POSEIDON_BASE_NAME)

#define psdStreamRead(___pps, ___buffer, ___length) \
      LP3(0x1bc, LONG, psdStreamRead , APTR, ___pps, a1, APTR, ___buffer, a0, LONG, ___length, d0,\
      , POSEIDON_BASE_NAME)

#define psdStreamWrite(___pps, ___buffer, ___length) \
      LP3(0x1c2, LONG, psdStreamWrite , APTR, ___pps, a1, APTR, ___buffer, a0, LONG, ___length, d0,\
      , POSEIDON_BASE_NAME)

#define psdStreamFlush(___pps) \
      LP1(0x1c8, LONG, psdStreamFlush , APTR, ___pps, a1,\
      , POSEIDON_BASE_NAME)

#define psdGetStreamError(___pps) \
      LP1(0x1ce, LONG, psdGetStreamError , APTR, ___pps, a1,\
      , POSEIDON_BASE_NAME)

#define psdCalculatePower(___phw) \
      LP1NR(0x1d4, psdCalculatePower , APTR, ___phw, a0,\
      , POSEIDON_BASE_NAME)

#define psdLoadCfgFromDisk(___filename) \
      LP1(0x1da, BOOL, psdLoadCfgFromDisk , STRPTR, ___filename, a1,\
      , POSEIDON_BASE_NAME)

#define psdSaveCfgToDisk(___filename, ___mode) \
      LP2(0x1e0, BOOL, psdSaveCfgToDisk , STRPTR, ___filename, a1, BOOL, ___mode, d0,\
      , POSEIDON_BASE_NAME)

#endif /* !_INLINE_POSEIDON_H */
