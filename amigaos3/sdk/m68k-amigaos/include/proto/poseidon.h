/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_POSEIDON_H
#define PROTO_POSEIDON_H

#include <clib/poseidon_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/poseidon.h>
#  else
#   include <inline/poseidon.h>
#  endif
# else
#  include <pragmas/poseidon_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/poseidon.h>
# ifndef __NOGLOBALIFACE__
   extern struct PsdIFace *IPsd;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  PsdBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_POSEIDON_H */
