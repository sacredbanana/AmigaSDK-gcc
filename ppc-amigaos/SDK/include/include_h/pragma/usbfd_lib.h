#ifndef _INCLUDE_PRAGMA_USBFD_LIB_H
#define _INCLUDE_PRAGMA_USBFD_LIB_H

/*
**    $VER: usbfd_lib.h 54.16 (22.08.2022)
**
**    Aztec `C' style pragma header file wrapper
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef CLIB_USBFD_PROTOS_H
#include <clib/usbfd_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(USBFDBase,0x01E,USBFDGetAttrsA(a0))
#pragma amicall(USBFDBase,0x024,USBFDRunFunction(a0))
#pragma amicall(USBFDBase,0x02A,USBFDRunInterface(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall USBFDBase USBFDGetAttrsA       01E 801
#pragma  libcall USBFDBase USBFDRunFunction     024 801
#pragma  libcall USBFDBase USBFDRunInterface    02A 801
#endif
#ifdef __STORM__
#pragma tagcall(USBFDBase,0x01E,USBFDGetAttrs(a0))
#endif
#ifdef __SASC_60
#pragma  tagcall USBFDBase USBFDGetAttrs        01E 801
#endif

#endif	/*  _INCLUDE_PRAGMA_USBFD_LIB_H  */
