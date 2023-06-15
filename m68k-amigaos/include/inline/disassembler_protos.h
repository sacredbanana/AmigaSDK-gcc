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

APTR __Disassemble(__reg("a6") struct Library * , __reg("a0") struct DisData * data ) = "\tjsr\t-66(a6)";
#define Disassemble(data) __Disassemble(DisassemblerBase, (data))

APTR __FindStartPosition(__reg("a6") struct Library * , __reg("a0") APTR startpc , __reg("d0") UWORD min , __reg("d1") UWORD max ) = "\tjsr\t-72(a6)";
#define FindStartPosition(startpc, min, max) __FindStartPosition(DisassemblerBase, (startpc), (min), (max))

#endif /* !_INLINE_DISASSEMBLER_H */
