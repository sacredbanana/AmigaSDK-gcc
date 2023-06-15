/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CIA_H
#define _INLINE_CIA_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

struct Interrupt * __AddICRVector(__reg("a6") struct Library * , __reg("a6") struct Library * resource , __reg("d0") WORD iCRBit , __reg("a1") struct Interrupt * interrupt ) = "\tjsr\t-6(a6)";
#define AddICRVector(resource, iCRBit, interrupt) __AddICRVector(Base, (resource), (iCRBit), (interrupt))

VOID __RemICRVector(__reg("a6") struct Library * , __reg("a6") struct Library * resource , __reg("d0") WORD iCRBit , __reg("a1") struct Interrupt * interrupt ) = "\tjsr\t-12(a6)";
#define RemICRVector(resource, iCRBit, interrupt) __RemICRVector(Base, (resource), (iCRBit), (interrupt))

WORD __AbleICR(__reg("a6") struct Library * , __reg("a6") struct Library * resource , __reg("d0") WORD mask ) = "\tjsr\t-18(a6)";
#define AbleICR(resource, mask) __AbleICR(Base, (resource), (mask))

WORD __SetICR(__reg("a6") struct Library * , __reg("a6") struct Library * resource , __reg("d0") WORD mask ) = "\tjsr\t-24(a6)";
#define SetICR(resource, mask) __SetICR(Base, (resource), (mask))

#endif /* !_INLINE_CIA_H */
