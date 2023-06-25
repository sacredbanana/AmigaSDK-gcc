#ifndef INLINE4_USBSYS_H
#define INLINE4_USBSYS_H

/*
** This file was auto generated by idltool 53.6.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef USB_SYSTEM_H
#include <usb/system.h>
#endif
#include <interfaces/usbsys.h>

/* Inline macros for Interface "main" */
#define USBAllocRequestA(openreq, taglist) IUSBSys->USBAllocRequestA((openreq), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBAllocRequest(...) IUSBSys->USBAllocRequest(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBAllocRequest(vargs...) IUSBSys->USBAllocRequest(## vargs) 
#endif
#define USBFreeRequest(req) IUSBSys->USBFreeRequest((req)) 
#define USBFindFunctionA(curfkt, taglist) IUSBSys->USBFindFunctionA((curfkt), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBFindFunction(...) IUSBSys->USBFindFunction(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBFindFunction(vargs...) IUSBSys->USBFindFunction(## vargs) 
#endif
#define USBLockFunction(rawfkt) IUSBSys->USBLockFunction((rawfkt)) 
#define USBUnlockFunction(rawfkt) IUSBSys->USBUnlockFunction((rawfkt)) 
#define USBClaimFunction(rawfkt, fdfkt, port) IUSBSys->USBClaimFunction((rawfkt), (fdfkt), (port)) 
#define USBDeclaimFunction(usfkt) IUSBSys->USBDeclaimFunction((usfkt)) 
#define USBAddFunctionA(ushubifc, taglist) IUSBSys->USBAddFunctionA((ushubifc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBAddFunction(...) IUSBSys->USBAddFunction(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBAddFunction(vargs...) IUSBSys->USBAddFunction(## vargs) 
#endif
#define USBRemFunction(rawfkt, ushubifc) IUSBSys->USBRemFunction((rawfkt), (ushubifc)) 
#define USBGetEndPoint(usfkt, usifc, epnum) IUSBSys->USBGetEndPoint((usfkt), (usifc), (epnum)) 
#define USBEPControlXferA(openreq, usep, rcmd, rtype, rval, ridx, buf, buflen, taglist) IUSBSys->USBEPControlXferA((openreq), (usep), (rcmd), (rtype), (rval), (ridx), (buf), (buflen), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBEPControlXfer(openreq, usep, rcmd, rtype, rval, ridx, buf, ...) IUSBSys->USBEPControlXfer((openreq), (usep), (rcmd), (rtype), (rval), (ridx), (buf), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBEPControlXfer(openreq, usep, rcmd, rtype, rval, ridx, buf, vargs...) IUSBSys->USBEPControlXfer(openreq, usep, rcmd, rtype, rval, ridx, buf, ## vargs) 
#endif
#define USBEPGetDescriptorA(openreq, usep, rtype, dtyp, didx, taglist) IUSBSys->USBEPGetDescriptorA((openreq), (usep), (rtype), (dtyp), (didx), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBEPGetDescriptor(openreq, usep, rtype, dtyp, ...) IUSBSys->USBEPGetDescriptor((openreq), (usep), (rtype), (dtyp), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBEPGetDescriptor(openreq, usep, rtype, dtyp, vargs...) IUSBSys->USBEPGetDescriptor(openreq, usep, rtype, dtyp, ## vargs) 
#endif
#define USBFktGetCfgDescriptorsA(openreq, usfkt, cfgid, taglist) IUSBSys->USBFktGetCfgDescriptorsA((openreq), (usfkt), (cfgid), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBFktGetCfgDescriptors(openreq, usfkt, ...) IUSBSys->USBFktGetCfgDescriptors((openreq), (usfkt), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBFktGetCfgDescriptors(openreq, usfkt, vargs...) IUSBSys->USBFktGetCfgDescriptors(openreq, usfkt, ## vargs) 
#endif
#define USBFktSetConfigurationA(openreq, fkt, cfgdsc, taglist) IUSBSys->USBFktSetConfigurationA((openreq), (fkt), (cfgdsc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBFktSetConfiguration(openreq, fkt, ...) IUSBSys->USBFktSetConfiguration((openreq), (fkt), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBFktSetConfiguration(openreq, fkt, vargs...) IUSBSys->USBFktSetConfiguration(openreq, fkt, ## vargs) 
#endif
#define USBParseDescriptors(buffer, buflen) IUSBSys->USBParseDescriptors((buffer), (buflen)) 
#define USBFreeDescriptors(dscr) IUSBSys->USBFreeDescriptors((dscr)) 
#define USBNextDescriptor(dscr) IUSBSys->USBNextDescriptor((dscr)) 
#define USBPrevDescriptor(dscr) IUSBSys->USBPrevDescriptor((dscr)) 
#define USBObtainResourceA(type, object, taglist) IUSBSys->USBObtainResourceA((type), (object), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBObtainResource(type, ...) IUSBSys->USBObtainResource((type), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBObtainResource(type, vargs...) IUSBSys->USBObtainResource(type, ## vargs) 
#endif
#define USBReleaseResource(type, object) IUSBSys->USBReleaseResource((type), (object)) 
#define USBFindInterfaceA(curifc, taglist) IUSBSys->USBFindInterfaceA((curifc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBFindInterface(...) IUSBSys->USBFindInterface(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBFindInterface(vargs...) IUSBSys->USBFindInterface(## vargs) 
#endif
#define USBLockInterface(rawifc) IUSBSys->USBLockInterface((rawifc)) 
#define USBUnlockInterface(rawifc) IUSBSys->USBUnlockInterface((rawifc)) 
#define USBClaimInterface(rawifc, fdifc, port) IUSBSys->USBClaimInterface((rawifc), (fdifc), (port)) 
#define USBDeclaimInterface(usifc) IUSBSys->USBDeclaimInterface((usifc)) 
#define USBGetInterface(usfkt, ifcnum) IUSBSys->USBGetInterface((usfkt), (ifcnum)) 
#define USBIntGetConfigurationA(openreq, usifc, taglist) IUSBSys->USBIntGetConfigurationA((openreq), (usifc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBIntGetConfiguration(openreq, ...) IUSBSys->USBIntGetConfiguration((openreq), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBIntGetConfiguration(openreq, vargs...) IUSBSys->USBIntGetConfiguration(openreq, ## vargs) 
#endif
#define USBIntGetAltSettingA(openreq, usifc, taglist) IUSBSys->USBIntGetAltSettingA((openreq), (usifc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBIntGetAltSetting(openreq, ...) IUSBSys->USBIntGetAltSetting((openreq), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBIntGetAltSetting(openreq, vargs...) IUSBSys->USBIntGetAltSetting(openreq, ## vargs) 
#endif
#define USBIntSetAltSettingA(openreq, usifc, altnum, taglist) IUSBSys->USBIntSetAltSettingA((openreq), (usifc), (altnum), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBIntSetAltSetting(openreq, usifc, ...) IUSBSys->USBIntSetAltSetting((openreq), (usifc), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBIntSetAltSetting(openreq, usifc, vargs...) IUSBSys->USBIntSetAltSetting(openreq, usifc, ## vargs) 
#endif
#define USBLogPuts(err, context, msg) IUSBSys->USBLogPuts((err), (context), (msg)) 
#define USBLogVPrintf(err, context, msg, fmtargs) IUSBSys->USBLogVPrintf((err), (context), (msg), (fmtargs)) 
#define USBSetFunctionAttrsA(clfkt, taglist) IUSBSys->USBSetFunctionAttrsA((clfkt), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBSetFunctionAttrs(...) IUSBSys->USBSetFunctionAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBSetFunctionAttrs(vargs...) IUSBSys->USBSetFunctionAttrs(## vargs) 
#endif
#define USBSetInterfaceAttrsA(clifc, taglist) IUSBSys->USBSetInterfaceAttrsA((clifc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBSetInterfaceAttrs(...) IUSBSys->USBSetInterfaceAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBSetInterfaceAttrs(vargs...) IUSBSys->USBSetInterfaceAttrs(## vargs) 
#endif
#define USBGetStackAttrsA(taglist) IUSBSys->USBGetStackAttrsA((taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBGetStackAttrs(...) IUSBSys->USBGetStackAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBGetStackAttrs(...) IUSBSys->USBGetStackAttrs(## vargs) 
#endif
#define USBGetRawFunctionAttrsA(rawfkt, taglist) IUSBSys->USBGetRawFunctionAttrsA((rawfkt), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBGetRawFunctionAttrs(...) IUSBSys->USBGetRawFunctionAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBGetRawFunctionAttrs(vargs...) IUSBSys->USBGetRawFunctionAttrs(## vargs) 
#endif
#define USBGetRawInterfaceAttrsA(rawifc, taglist) IUSBSys->USBGetRawInterfaceAttrsA((rawifc), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBGetRawInterfaceAttrs(...) IUSBSys->USBGetRawInterfaceAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBGetRawInterfaceAttrs(vargs...) IUSBSys->USBGetRawInterfaceAttrs(## vargs) 
#endif
#define USBFktDriverRunning(fkt) IUSBSys->USBFktDriverRunning((fkt)) 
#define USBIfcDriverRunning(ifc) IUSBSys->USBIfcDriverRunning((ifc)) 
#define USBEPDestall(openreq, usep) IUSBSys->USBEPDestall((openreq), (usep)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBAllocObjectTags(...) IUSBSys->USBAllocObjectTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBAllocObjectTags(vargs...) IUSBSys->USBAllocObjectTags(## vargs) 
#endif
#define USBAllocObject(type, taglist) IUSBSys->USBAllocObject((type), (taglist)) 
#define USBFreeObject(type, object) IUSBSys->USBFreeObject((type), (object)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBLogPrintf(err, context, ...) IUSBSys->USBLogPrintf((err), (context), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBLogPrintf(err, context, vargs...) IUSBSys->USBLogPrintf(err, context, ## vargs) 
#endif
#define USBScanA(type, hook, taglist) IUSBSys->USBScanA((type), (hook), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBScan(type, ...) IUSBSys->USBScan((type), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBScan(type, vargs...) IUSBSys->USBScan(type, ## vargs) 
#endif
#define USBGetEndPointAttrsA(ep, taglist) IUSBSys->USBGetEndPointAttrsA((ep), (taglist)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define USBGetEndPointAttrs(...) IUSBSys->USBGetEndPointAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define USBGetEndPointAttrs(vargs...) IUSBSys->USBGetEndPointAttrs(## vargs) 
#endif
#define USBGetFrameNumber(ep, timestamp) IUSBSys->USBGetFrameNumber((ep), (timestamp)) 
#define USBSetIsoTransferCount(ioReq, transferIndex) IUSBSys->USBSetIsoTransferCount((ioReq), (transferIndex)) 
#define USBSetIsoTransferSetup(ioReq, transferIndex, offset, length) IUSBSys->USBSetIsoTransferSetup((ioReq), (transferIndex), (offset), (length)) 
#define USBGetIsoTransferResult(ioReq, transferIndex, setupOut) IUSBSys->USBGetIsoTransferResult((ioReq), (transferIndex), (setupOut)) 
#define USBGetIsoTransferSetupHcd(ioReq, transferIndex) IUSBSys->USBGetIsoTransferSetupHcd((ioReq), (transferIndex)) 
#define USBSetIsoTransferResultHcd(ioReq, transferIndex, actual, result) IUSBSys->USBSetIsoTransferResultHcd((ioReq), (transferIndex), (actual), (result)) 

#endif /* INLINE4_USBSYS_H */
