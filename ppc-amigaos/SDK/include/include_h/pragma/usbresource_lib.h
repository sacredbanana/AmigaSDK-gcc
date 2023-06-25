#ifndef _INCLUDE_PRAGMA_USBRESOURCE_LIB_H
#define _INCLUDE_PRAGMA_USBRESOURCE_LIB_H

/*
**    $VER: usbresource_lib.h 54.16 (22.08.2022)
**
**    Aztec `C' style pragma header file wrapper
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef CLIB_USBRESOURCE_PROTOS_H
#include <clib/usbresource_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(USBResourceBase,0x01e,USBResRegisterFDA(a0))
#pragma amicall(USBResourceBase,0x024,USBResUnregisterFD(a0))
#pragma amicall(USBResourceBase,0x02a,USBResRegisterHCDA(a0))
#pragma amicall(USBResourceBase,0x030,USBResUnregisterHCD(a0))
#pragma amicall(USBResourceBase,0x05a,USBResAddNotify(d0,a0))
#pragma amicall(USBResourceBase,0x060,USBResRemNotify(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall USBResourceBase USBResRegisterFDA      01e 801
#pragma  libcall USBResourceBase USBResUnregisterFD     024 801
#pragma  libcall USBResourceBase USBResRegisterHCDA     02a 801
#pragma  libcall USBResourceBase USBResUnregisterHCD    030 801
#pragma  libcall USBResourceBase USBResAddNotify        05a 8002
#pragma  libcall USBResourceBase USBResRemNotify        060 801
#endif
#ifdef __STORM__
#pragma tagcall(USBResourceBase,0x01e,USBResRegisterFD(a0))
#pragma tagcall(USBResourceBase,0x02a,USBResRegisterHCD(a0))
#endif
#ifdef __SASC_60
#pragma  tagcall USBResourceBase USBResRegisterFD       01e 801
#pragma  tagcall USBResourceBase USBResRegisterHCD      02a 801
#endif

#endif	/*  _INCLUDE_PRAGMA_USBRESOURCE_LIB_H  */
