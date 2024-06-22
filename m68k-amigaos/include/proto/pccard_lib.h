/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_PCCARD_H
#define PROTO_PCCARD_H

#include <clib/pccard_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/pccard.h>
#  else
#   include <inline/pccard.h>
#  endif
# else
#  include <pragmas/pccard_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/pccard.h>
# ifndef __NOGLOBALIFACE__
   extern struct PCCardIFace *IPCCard;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  PCCardBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_PCCARD_H */
