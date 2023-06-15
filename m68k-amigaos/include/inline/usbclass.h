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

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef USBCLASS_BASE_NAME
#define USBCLASS_BASE_NAME UsbClsBase
#endif /* !USBCLASS_BASE_NAME */

#define usbAttemptInterfaceBinding(___pif) \
      LP1(0x1e, APTR, usbAttemptInterfaceBinding , APTR, ___pif, a0,\
      , USBCLASS_BASE_NAME)

#define usbReleaseInterfaceBinding(___uifb) \
      LP1NR(0x24, usbReleaseInterfaceBinding , APTR, ___uifb, a0,\
      , USBCLASS_BASE_NAME)

#define usbAttemptDeviceBinding(___pd) \
      LP1(0x2a, APTR, usbAttemptDeviceBinding , APTR, ___pd, a0,\
      , USBCLASS_BASE_NAME)

#define usbReleaseDeviceBinding(___udb) \
      LP1NR(0x30, usbReleaseDeviceBinding , APTR, ___udb, a0,\
      , USBCLASS_BASE_NAME)

#define usbForceInterfaceBinding(___pif) \
      LP1(0x36, APTR, usbForceInterfaceBinding , APTR, ___pif, a0,\
      , USBCLASS_BASE_NAME)

#define usbForceDeviceBinding(___pd) \
      LP1(0x3c, APTR, usbForceDeviceBinding , APTR, ___pd, a0,\
      , USBCLASS_BASE_NAME)

#define usbGetAttrsA(___type, ___usbstruct, ___taglist) \
      LP3(0x42, LONG, usbGetAttrsA , ULONG, ___type, d0, APTR, ___usbstruct, a0, struct TagItem *, ___taglist, a1,\
      , USBCLASS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define usbGetAttrs(___type, ___usbstruct, ___tag1, ...) \
    ({_sfdc_vararg _tags[] = { ___tag1, __VA_ARGS__ }; usbGetAttrsA((___type), (___usbstruct), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define usbSetAttrsA(___type, ___usbstruct, ___taglist) \
      LP3(0x48, LONG, usbSetAttrsA , ULONG, ___type, d0, APTR, ___usbstruct, a0, struct TagItem *, ___taglist, a1,\
      , USBCLASS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define usbSetAttrs(___type, ___usbstruct, ___tag1, ...) \
    ({_sfdc_vararg _tags[] = { ___tag1, __VA_ARGS__ }; usbSetAttrsA((___type), (___usbstruct), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define usbDoMethodA(___methodid, ___methoddata) \
      LP2(0x4e, LONG, usbDoMethodA , ULONG, ___methodid, d0, APTR, ___methoddata, a1,\
      , USBCLASS_BASE_NAME)

#ifndef NO_INLINE_VARARGS
#define usbDoMethod(___methodid, ...) \
     ({_sfdc_vararg _args[] = { __VA_ARGS__ }; usbDoMethodA((___methodid), (APTR) _args); })
#endif /* !NO_INLINE_VARARGS */

#endif /* !_INLINE_USBCLASS_H */
