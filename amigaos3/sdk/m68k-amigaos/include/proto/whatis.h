/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_WHATIS_H
#define PROTO_WHATIS_H

#include <clib/whatis_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/whatis.h>
#  else
#   include <inline/whatis.h>
#  endif
# else
#  include <pragmas/whatis_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/whatis.h>
# ifndef __NOGLOBALIFACE__
   extern struct WhatIsIFace *IWhatIs;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  WhatIsBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_WHATIS_H */
