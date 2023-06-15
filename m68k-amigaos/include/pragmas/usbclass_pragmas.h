#ifndef PRAGMAS_USBCLASS_PRAGMAS_H
#define PRAGMAS_USBCLASS_PRAGMAS_H

/*
**	$Id: usbclass_pragmas.h 1.1 2002/03/02 12:44:47 hodges Exp $
**
**	Direct ROM interface (pragma) definitions.
**
**	Copyright © 2002 Chris Hodges
**	    All Rights Reserved
*/

#if defined(LATTICE) || defined(__SASC) || defined(_DCC)
#ifndef __CLIB_PRAGMA_LIBCALL
#define __CLIB_PRAGMA_LIBCALL
#endif /* __CLIB_PRAGMA_LIBCALL */
#else /* __MAXON__, __STORM__ or AZTEC_C */
#ifndef __CLIB_PRAGMA_AMICALL
#define __CLIB_PRAGMA_AMICALL
#endif /* __CLIB_PRAGMA_AMICALL */
#endif /* */

#if defined(__SASC) || defined(__STORM__)
#ifndef __CLIB_PRAGMA_TAGCALL
#define __CLIB_PRAGMA_TAGCALL
#endif /* __CLIB_PRAGMA_TAGCALL */
#endif /* __MAXON__, __STORM__ or AZTEC_C */

#ifndef CLIB_USBCLASS_PROTOS_H
#include <clib/usbclass_protos.h>
#endif /* CLIB_USBCLASS_PROTOS_H */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbAttemptInterfaceBinding 1e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x1e, usbAttemptInterfaceBinding(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbReleaseInterfaceBinding 24 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x24, usbReleaseInterfaceBinding(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbAttemptDeviceBinding 2a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x2a, usbAttemptDeviceBinding(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbReleaseDeviceBinding 30 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x30, usbReleaseDeviceBinding(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbForceInterfaceBinding 36 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x36, usbForceInterfaceBinding(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbForceDeviceBinding 3c 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x3c, usbForceDeviceBinding(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbGetAttrsA 42 98003
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x42, usbGetAttrsA(d0,a0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall UsbClsBase usbGetAttrs 42 98003
 #endif /* __CLIB_PRAGMA_LIBCALL */
 #ifdef __CLIB_PRAGMA_AMICALL
  #pragma tagcall(UsbClsBase, 0x42, usbGetAttrs(d0,a0,a1))
 #endif /* __CLIB_PRAGMA_AMICALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbSetAttrsA 48 98003
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x48, usbSetAttrsA(d0,a0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall UsbClsBase usbSetAttrs 48 98003
 #endif /* __CLIB_PRAGMA_LIBCALL */
 #ifdef __CLIB_PRAGMA_AMICALL
  #pragma tagcall(UsbClsBase, 0x48, usbSetAttrs(d0,a0,a1))
 #endif /* __CLIB_PRAGMA_AMICALL */
#endif /* __CLIB_PRAGMA_TAGCALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall UsbClsBase usbDoMethodA 4e 9002
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(UsbClsBase, 0x4e, usbDoMethodA(d0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_TAGCALL
 #ifdef __CLIB_PRAGMA_LIBCALL
  #pragma tagcall UsbClsBase usbDoMethod 4e 9002
 #endif /* __CLIB_PRAGMA_LIBCALL */
 #ifdef __CLIB_PRAGMA_AMICALL
  #pragma tagcall(UsbClsBase, 0x4e, usbDoMethod(d0,a1))
 #endif /* __CLIB_PRAGMA_AMICALL */
#endif /* __CLIB_PRAGMA_TAGCALL */

#endif /* PRAGMAS_USBCLASS_PRAGMAS_H */
