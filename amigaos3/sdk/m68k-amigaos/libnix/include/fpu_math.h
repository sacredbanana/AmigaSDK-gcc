/* With -m68881, the math functions use the FPU itself.  mathieeedoubtrans.library
   would only pass the result back, and it loses the exception flags and the
   rounding mode, which fenv.h is about.  */

#ifndef _FPU_MATH_H
#define _FPU_MATH_H

/* Stored in a volatile, the result is a double or a float with the flags of one,
   not the extended value left in fp0.  */
#define FPU_FUNCTION(type, name, insn)					\
  type name(type x)							\
  {									\
    volatile type result;						\
    __asm__ (insn "%.x %1,%0" : "=f" (result) : "f" (x));		\
    return result;							\
  }

/* The FPCR for a precision for the time of one instruction: fsqrt in the
   precision of its result rounds only once.  */
#define FPU_FUNCTION_FPCR(type, name, insn, clear, set)			\
  type name(type x)							\
  {									\
    unsigned long fpcr;							\
    volatile type result;						\
    __asm__ __volatile__ ("fmove%.l %/fpcr,%0" : "=dm" (fpcr));		\
    __asm__ __volatile__ ("fmove%.l %0,%/fpcr"				\
			  : : "dmi" ((fpcr & ~(unsigned long) (clear)) | (set)));	\
    __asm__ __volatile__ (insn "%.x %1,%0" : "=f" (result) : "f" (x));	\
    __asm__ __volatile__ ("fmove%.l %0,%/fpcr" : : "dmi" (fpcr));	\
    return result;							\
  }

#define FPCR_PRECISION 0xc0
#define FPCR_SINGLE    0x40
#define FPCR_DOUBLE    0x80

#define SIGN_BIT 0x80000000UL

/* ceil() and floor() work on the bits, and round away from zero when x has the
   sign in away: fint isn't in a 68040's hardware, and it raises INEXACT, which
   C23's Annex F says these functions don't.  */
extern double __fpu_round_to_integer(double x, unsigned long away);
extern float __fpu_round_to_integerf(float x, unsigned long away);

#endif /* _FPU_MATH_H */
