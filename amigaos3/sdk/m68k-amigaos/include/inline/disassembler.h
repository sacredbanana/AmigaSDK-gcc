/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_DISASSEMBLER_H
#define _INLINE_DISASSEMBLER_H

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

#ifndef DISASSEMBLER_BASE_NAME
#define DISASSEMBLER_BASE_NAME DisassemblerBase
#endif /* !DISASSEMBLER_BASE_NAME */

#define Disassemble(___data) \
      LP1(0x42, APTR, Disassemble , struct DisData *, ___data, a0,\
      , DISASSEMBLER_BASE_NAME)

#define FindStartPosition(___startpc, ___min, ___max) \
      LP3(0x48, APTR, FindStartPosition , APTR, ___startpc, a0, UWORD, ___min, d0, UWORD, ___max, d1,\
      , DISASSEMBLER_BASE_NAME)

#endif /* !_INLINE_DISASSEMBLER_H */
