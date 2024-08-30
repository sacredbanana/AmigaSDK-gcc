#ifndef _INCLUDE_PRAGMA_USBSYS_LIB_H
#define _INCLUDE_PRAGMA_USBSYS_LIB_H

/*
**    $VER: usbsys_lib.h 54.16 (22.08.2022)
**
**    Aztec `C' style pragma header file wrapper
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef CLIB_USBSYS_PROTOS_H
#include <clib/usbsys_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(USBSysBase,0x02a,USBAllocRequestA(a0,a1))
#pragma amicall(USBSysBase,0x030,USBFreeRequest(a0))
#pragma amicall(USBSysBase,0x036,USBFindFunctionA(a0,a1))
#pragma amicall(USBSysBase,0x03c,USBLockFunction(a0))
#pragma amicall(USBSysBase,0x042,USBUnlockFunction(a0))
#pragma amicall(USBSysBase,0x048,USBClaimFunction(a0,a1,a2))
#pragma amicall(USBSysBase,0x04e,USBDeclaimFunction(a0))
#pragma amicall(USBSysBase,0x054,USBAddFunctionA(a0,a1))
#pragma amicall(USBSysBase,0x05a,USBRemFunction(a0,a1))
#pragma amicall(USBSysBase,0x060,USBGetEndPoint(a0,a1,d0))
#pragma amicall(USBSysBase,0x066,USBEPControlXferA(a0,a1,d0,d1,d2,d3,a2,d4,a3))
#pragma amicall(USBSysBase,0x06c,USBEPGetDescriptorA(a0,a1,d0,d1,d2,a2))
#pragma amicall(USBSysBase,0x072,USBFktGetCfgDescriptorsA(a0,a1,d0,a2))
#pragma amicall(USBSysBase,0x078,USBFktSetConfigurationA(a0,a1,a2,a3))
#pragma amicall(USBSysBase,0x07e,USBParseDescriptors(a0,d0))
#pragma amicall(USBSysBase,0x084,USBFreeDescriptors(a0))
#pragma amicall(USBSysBase,0x08a,USBNextDescriptor(a0))
#pragma amicall(USBSysBase,0x090,USBPrevDescriptor(a0))
#pragma amicall(USBSysBase,0x096,USBObtainResourceA(d0,a0,a1))
#pragma amicall(USBSysBase,0x09c,USBReleaseResource(d0,a0))
#pragma amicall(USBSysBase,0x0a2,USBFindInterfaceA(a0,a1))
#pragma amicall(USBSysBase,0x0a8,USBLockInterface(a0))
#pragma amicall(USBSysBase,0x0ae,USBUnlockInterface(a0))
#pragma amicall(USBSysBase,0x0b4,USBClaimInterface(a0,a1,a2))
#pragma amicall(USBSysBase,0x0ba,USBDeclaimInterface(a0))
#pragma amicall(USBSysBase,0x0c0,USBGetInterface(a0,d0))
#pragma amicall(USBSysBase,0x0c6,USBIntGetConfigurationA(a0,a1,a2))
#pragma amicall(USBSysBase,0x0cc,USBIntGetAltSettingA(a0,a1,a2))
#pragma amicall(USBSysBase,0x0d2,USBIntSetAltSettingA(a0,a1,d0,a2))
#pragma amicall(USBSysBase,0x0d8,USBLogPuts(d0,a0,a1))
#pragma amicall(USBSysBase,0x0de,USBLogVPrintf(d0,a0,a1,a2))
#pragma amicall(USBSysBase,0x0e4,USBSetFunctionAttrsA(a0,a1))
#pragma amicall(USBSysBase,0x0ea,USBSetInterfaceAttrsA(a0,a1))
#pragma amicall(USBSysBase,0x0f0,USBGetStackAttrsA(a0))
#pragma amicall(USBSysBase,0x0f6,USBGetRawFunctionAttrsA(a0,a1))
#pragma amicall(USBSysBase,0x0fc,USBGetRawInterfaceAttrsA(a0,a1))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall USBSysBase USBAllocRequestA       02a 9802
#pragma  libcall USBSysBase USBFreeRequest         030 801
#pragma  libcall USBSysBase USBFindFunctionA       036 9802
#pragma  libcall USBSysBase USBLockFunction        03c 801
#pragma  libcall USBSysBase USBUnlockFunction      042 801
#pragma  libcall USBSysBase USBClaimFunction       048 a9803
#pragma  libcall USBSysBase USBDeclaimFunction     04e 801
#pragma  libcall USBSysBase USBAddFunctionA        054 9802
#pragma  libcall USBSysBase USBRemFunction         05a 9802
#pragma  libcall USBSysBase USBGetEndPoint         060 09803
#pragma  libcall USBSysBase USBEPControlXferA      066 b4a32109809
#pragma  libcall USBSysBase USBEPGetDescriptorA    06c a2109806
#pragma  libcall USBSysBase USBFktGetCfgDescriptorsA 072 a09804
#pragma  libcall USBSysBase USBFktSetConfigurationA 078 ba9804
#pragma  libcall USBSysBase USBParseDescriptors    07e 0802
#pragma  libcall USBSysBase USBFreeDescriptors     084 801
#pragma  libcall USBSysBase USBNextDescriptor      08a 801
#pragma  libcall USBSysBase USBPrevDescriptor      090 801
#pragma  libcall USBSysBase USBObtainResourceA     096 98003
#pragma  libcall USBSysBase USBReleaseResource     09c 8002
#pragma  libcall USBSysBase USBFindInterfaceA      0a2 9802
#pragma  libcall USBSysBase USBLockInterface       0a8 801
#pragma  libcall USBSysBase USBUnlockInterface     0ae 801
#pragma  libcall USBSysBase USBClaimInterface      0b4 a9803
#pragma  libcall USBSysBase USBDeclaimInterface    0ba 801
#pragma  libcall USBSysBase USBGetInterface        0c0 0802
#pragma  libcall USBSysBase USBIntGetConfigurationA 0c6 a9803
#pragma  libcall USBSysBase USBIntGetAltSettingA   0cc a9803
#pragma  libcall USBSysBase USBIntSetAltSettingA   0d2 a09804
#pragma  libcall USBSysBase USBLogPuts             0d8 98003
#pragma  libcall USBSysBase USBLogVPrintf          0de a98004
#pragma  libcall USBSysBase USBSetFunctionAttrsA   0e4 9802
#pragma  libcall USBSysBase USBSetInterfaceAttrsA  0ea 9802
#pragma  libcall USBSysBase USBGetStackAttrsA      0f0 801
#pragma  libcall USBSysBase USBGetRawFunctionAttrsA 0f6 9802
#pragma  libcall USBSysBase USBGetRawInterfaceAttrsA 0fc 9802
#endif
#ifdef __STORM__
#pragma tagcall(USBSysBase,0x02a,USBAllocRequest(a0,a1))
#pragma tagcall(USBSysBase,0x036,USBFindFunction(a0,a1))
#pragma tagcall(USBSysBase,0x054,USBAddFunction(a0,a1))
#pragma tagcall(USBSysBase,0x066,USBEPControlXfer(a0,a1,d0,d1,d2,d3,a2,d4,a3))
#pragma tagcall(USBSysBase,0x06c,USBEPGetDescriptor(a0,a1,d0,d1,d2,a2))
#pragma tagcall(USBSysBase,0x072,USBFktGetCfgDescriptors(a0,a1,d0,a2))
#pragma tagcall(USBSysBase,0x078,USBFktSetConfiguration(a0,a1,a2,a3))
#pragma tagcall(USBSysBase,0x096,USBObtainResource(d0,a0,a1))
#pragma tagcall(USBSysBase,0x0a2,USBFindInterface(a0,a1))
#pragma tagcall(USBSysBase,0x0c6,USBIntGetConfiguration(a0,a1,a2))
#pragma tagcall(USBSysBase,0x0cc,USBIntGetAltSetting(a0,a1,a2))
#pragma tagcall(USBSysBase,0x0d2,USBIntSetAltSetting(a0,a1,d0,a2))
#pragma tagcall(USBSysBase,0x0e4,USBSetFunctionAttrs(a0,a1))
#pragma tagcall(USBSysBase,0x0ea,USBSetInterfaceAttrs(a0,a1))
#pragma tagcall(USBSysBase,0x0f0,USBGetStackAttrs(a0))
#pragma tagcall(USBSysBase,0x0f6,USBGetRawFunctionAttrs(a0,a1))
#pragma tagcall(USBSysBase,0x0fc,USBGetRawInterfaceAttrs(a0,a1))
#endif
#ifdef __SASC_60
#pragma  tagcall USBSysBase USBAllocRequest        02a 9802
#pragma  tagcall USBSysBase USBFindFunction        036 9802
#pragma  tagcall USBSysBase USBAddFunction         054 9802
#pragma  tagcall USBSysBase USBEPControlXfer       066 b4a32109809
#pragma  tagcall USBSysBase USBEPGetDescriptor     06c a2109806
#pragma  tagcall USBSysBase USBFktGetCfgDescriptors 072 a09804
#pragma  tagcall USBSysBase USBFktSetConfiguration 078 ba9804
#pragma  tagcall USBSysBase USBObtainResource      096 98003
#pragma  tagcall USBSysBase USBFindInterface       0a2 9802
#pragma  tagcall USBSysBase USBIntGetConfiguration 0c6 a9803
#pragma  tagcall USBSysBase USBIntGetAltSetting    0cc a9803
#pragma  tagcall USBSysBase USBIntSetAltSetting    0d2 a09804
#pragma  tagcall USBSysBase USBSetFunctionAttrs    0e4 9802
#pragma  tagcall USBSysBase USBSetInterfaceAttrs   0ea 9802
#pragma  tagcall USBSysBase USBGetStackAttrs       0f0 801
#pragma  tagcall USBSysBase USBGetRawFunctionAttrs 0f6 9802
#pragma  tagcall USBSysBase USBGetRawInterfaceAttrs 0fc 9802
#endif

#endif	/*  _INCLUDE_PRAGMA_USBSYS_LIB_H  */
