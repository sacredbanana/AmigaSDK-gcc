/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_MMU_H
#define PROTO_MMU_H

#include <clib/mmu_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/mmu.h>
#  else
#   include <inline/mmu.h>
#  endif
# else
#  include <pragmas/mmu_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/mmu.h>
# ifndef __NOGLOBALIFACE__
   extern struct MMUIFace *IMMU;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  MMUBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_MMU_H */
