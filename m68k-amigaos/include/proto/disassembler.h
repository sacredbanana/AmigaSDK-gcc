/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_DISASSEMBLER_H
#define PROTO_DISASSEMBLER_H

#include <clib/disassembler_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/disassembler.h>
#  else
#   include <inline/disassembler.h>
#  endif
# else
#  include <pragmas/disassembler_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/disassembler.h>
# ifndef __NOGLOBALIFACE__
   extern struct DisassemblerIFace *IDisassembler;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  DisassemblerBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_DISASSEMBLER_H */
