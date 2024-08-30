/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_USBCLASS_H
#define _INLINE_USBCLASS_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __usbAttemptInterfaceBinding(__reg("a6") struct Library * , __reg("a0") APTR pif ) = "\tjsr\t-30(a6)";
#define usbAttemptInterfaceBinding(pif) __usbAttemptInterfaceBinding(UsbClsBase, (pif))

VOID __usbReleaseInterfaceBinding(__reg("a6") struct Library * , __reg("a0") APTR uifb ) = "\tjsr\t-36(a6)";
#define usbReleaseInterfaceBinding(uifb) __usbReleaseInterfaceBinding(UsbClsBase, (uifb))

APTR __usbAttemptDeviceBinding(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-42(a6)";
#define usbAttemptDeviceBinding(pd) __usbAttemptDeviceBinding(UsbClsBase, (pd))

VOID __usbReleaseDeviceBinding(__reg("a6") struct Library * , __reg("a0") APTR udb ) = "\tjsr\t-48(a6)";
#define usbReleaseDeviceBinding(udb) __usbReleaseDeviceBinding(UsbClsBase, (udb))

APTR __usbForceInterfaceBinding(__reg("a6") struct Library * , __reg("a0") APTR pif ) = "\tjsr\t-54(a6)";
#define usbForceInterfaceBinding(pif) __usbForceInterfaceBinding(UsbClsBase, (pif))

APTR __usbForceDeviceBinding(__reg("a6") struct Library * , __reg("a0") APTR pd ) = "\tjsr\t-60(a6)";
#define usbForceDeviceBinding(pd) __usbForceDeviceBinding(UsbClsBase, (pd))

LONG __usbGetAttrsA(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR usbstruct , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-66(a6)";
#define usbGetAttrsA(type, usbstruct, taglist) __usbGetAttrsA(UsbClsBase, (type), (usbstruct), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __usbGetAttrs(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR usbstruct , ULONG tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-66(a6)\n\tmovea.l\t(a7)+,a1";
#define usbGetAttrs(type, usbstruct, ...) __usbGetAttrs(UsbClsBase, (type), (usbstruct), __VA_ARGS__)
#endif

LONG __usbSetAttrsA(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR usbstruct , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-72(a6)";
#define usbSetAttrsA(type, usbstruct, taglist) __usbSetAttrsA(UsbClsBase, (type), (usbstruct), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __usbSetAttrs(__reg("a6") struct Library * , __reg("d0") ULONG type , __reg("a0") APTR usbstruct , ULONG tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-72(a6)\n\tmovea.l\t(a7)+,a1";
#define usbSetAttrs(type, usbstruct, ...) __usbSetAttrs(UsbClsBase, (type), (usbstruct), __VA_ARGS__)
#endif

LONG __usbDoMethodA(__reg("a6") struct Library * , __reg("d0") ULONG methodid , __reg("a1") APTR methoddata ) = "\tjsr\t-78(a6)";
#define usbDoMethodA(methodid, methoddata) __usbDoMethodA(UsbClsBase, (methodid), (methoddata))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __usbDoMethod(__reg("a6") struct Library * , ULONG methodid , ... ) = "\tmove.l\td0,-(a7)\n\tlea\t4(a7),d0\n\tjsr\t-78(a6)\n\tmovea.l\t(a7)+,d0";
#define usbDoMethod(...) __usbDoMethod(UsbClsBase, __VA_ARGS__)
#endif

#endif /* !_INLINE_USBCLASS_H */
