/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_MUIMASTER_H
#define PROTO_MUIMASTER_H

#include <clib/muimaster_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/muimaster_lib.h>
#  else
#define NO_INLINE_STDARG
#define NO_INLINE_VARARGS
#   include <inline/muimaster_lib.h>
#undef NO_INLINE_STDARG
#undef NO_INLINE_VARARGS

#  endif
# else
#  include <pragmas/muimaster_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/muimaster_lib.h>
# ifndef __NOGLOBALIFACE__
   extern struct MUIMasterIFace *IMUIMaster;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  MUIMasterBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_MUIMASTER_H */
