#ifndef _INCLUDE_PRAGMA_USBHCD_LIB_H
#define _INCLUDE_PRAGMA_USBHCD_LIB_H

/*
**    $VER: usbhcd_lib.h 54.16 (22.08.2022)
**
**    Aztec `C' style pragma header file wrapper
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef CLIB_USBHCD_PROTOS_H
#include <clib/usbhcd_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(USBHCDBase,0x02A,USBHCAddFunctionA(a0,a1,a2,a3))
#pragma amicall(USBHCDBase,0x030,USBHCRemFunction(a0,a1))
#pragma amicall(USBHCDBase,0x036,USBHCAddEndPointA(a0,a1,a2,d0,a3))
#pragma amicall(USBHCDBase,0x03C,USBHCRemEndPoint(a0,a1))
#pragma amicall(USBHCDBase,0x042,USBHCGetAttrsA(a0))
#pragma amicall(USBHCDBase,0x048,USBHCInitRootHubA(a0,a1,a2,a3))
#pragma amicall(USBHCDBase,0x04E,USBHCUninitRootHub(a0,a1))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall USBHCDBase USBHCAddFunctionA    02A BA9804
#pragma  libcall USBHCDBase USBHCRemFunction     030 9802
#pragma  libcall USBHCDBase USBHCAddEndPointA    036 B0A9805
#pragma  libcall USBHCDBase USBHCRemEndPoint     03C 9802
#pragma  libcall USBHCDBase USBHCGetAttrsA       042 801
#pragma  libcall USBHCDBase USBHCInitRootHubA    048 BA9804
#pragma  libcall USBHCDBase USBHCUninitRootHub   04E 9802
#endif
#ifdef __STORM__
#pragma tagcall(USBHCDBase,0x02A,USBHCAddFunction(a0,a1,a2,a3))
#pragma tagcall(USBHCDBase,0x036,USBHCAddEndPoint(a0,a1,a2,d0,a3))
#pragma tagcall(USBHCDBase,0x042,USBHCGetAttrs(a0))
#pragma tagcall(USBHCDBase,0x048,USBHCInitRootHub(a0,a1,a2,a3))
#endif
#ifdef __SASC_60
#pragma  tagcall USBHCDBase USBHCAddFunction     02A BA9804
#pragma  tagcall USBHCDBase USBHCAddEndPoint     036 B0A9805
#pragma  tagcall USBHCDBase USBHCGetAttrs        042 801
#pragma  tagcall USBHCDBase USBHCInitRootHub     048 BA9804
#endif

#endif	/*  _INCLUDE_PRAGMA_USBHCD_LIB_H  */
