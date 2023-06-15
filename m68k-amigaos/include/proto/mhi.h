/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_MHI_H
#define PROTO_MHI_H

#include L<clib/mhi_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include L<defines/mhi.h>
#  else
#   include L<inline/mhi.h>
#  endif
# else
#  include L<pragmas/mhi_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/mhi.h>
# ifndef __NOGLOBALIFACE__
   extern struct MHIIFace *IMHI;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  MHIBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_MHI_H */
