/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_USBCLASS_H
#define PROTO_USBCLASS_H

#include L<clib/usbclass_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include L<defines/usbclass.h>
#  else
#   include L<inline/usbclass.h>
#  endif
# else
#  include L<pragmas/usbclass_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/usbclass.h>
# ifndef __NOGLOBALIFACE__
   extern struct UsbClsIFace *IUsbCls;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  UsbClsBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_USBCLASS_H */
