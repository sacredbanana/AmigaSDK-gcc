/* What the math functions share to report errors.  Without an FPU, math.h says
   MATH_ERRNO, and the libraries can't be asked: the mathieee libraries take NaN
   and infinity for ordinary numbers, stop at DBL_MAX instead of overflowing, and
   return a number for what has no answer.  So the arguments are looked at first.

   The bits, never isnan() or x != x: libnix is built with -ffast-math.  With an
   FPU math.h says MATH_ERREXCEPT, and the FPU does this for the functions it
   calculates.  */

#ifndef _MATH_ERRNO_H
#define _MATH_ERRNO_H

#include <errno.h>

typedef unsigned short __attribute__((__may_alias__)) __math_word;
typedef unsigned long __attribute__((__may_alias__)) __math_long;

#define __math_high(x)    (((const __math_long *)&(x))[0])
#define __math_low(x)     (((const __math_long *)&(x))[1])
#define __math_exponent(x) (*(const __math_word *)&(x) & 0x7fff)

/* NaN or an infinity, and the unbiased exponent, which needs no library call.  */
#define __math_special_double(x)  ((__math_exponent(x) & 0x7ff0) == 0x7ff0)
#define __math_special_float(x)   ((__math_exponent(x) & 0x7f80) == 0x7f80)
#define __math_power_double(x)    ((int)(__math_exponent(x) >> 4) - 1023)
#define __math_power_float(x)     ((int)(__math_exponent(x) >> 7) - 127)

#define __math_abs_double(x)  (__math_high(x) & 0x7fffffffUL)
#define __math_abs_float(x)   (__math_high(x) & 0x7fffffffUL)

#define __math_zero_double(x)   ((__math_abs_double(x) | __math_low(x)) == 0)
#define __math_zero_float(x)    (__math_abs_float(x) == 0)
#define __math_nan_double(x) \
  (__math_abs_double(x) > 0x7ff00000UL || \
   (__math_abs_double(x) == 0x7ff00000UL && __math_low(x) != 0))
#define __math_nan_float(x)     (__math_abs_float(x) > 0x7f800000UL)
#define __math_inf_double(x) \
  (__math_abs_double(x) == 0x7ff00000UL && __math_low(x) == 0)
#define __math_inf_float(x)     (__math_abs_float(x) == 0x7f800000UL)
#define __math_negative(x)      ((__math_high(x) >> 31) != 0)

/* |x| > 1, and this takes NaN along.  */
#define __math_above_one_double(x) \
  (__math_abs_double(x) > 0x3ff00000UL || \
   (__math_abs_double(x) == 0x3ff00000UL && __math_low(x) != 0))
#define __math_above_one_float(x) (__math_abs_float(x) > 0x3f800000UL)
#define __math_one_double(x) \
  (__math_abs_double(x) == 0x3ff00000UL && __math_low(x) == 0)
#define __math_one_float(x)     (__math_abs_float(x) == 0x3f800000UL)

/* Negative, zero, or NaN or an infinity: what log() and sqrt() can't be given.  */
#define __math_not_positive_double(x) \
  (__math_high(x) >= 0x7ff00000UL || (__math_high(x) | __math_low(x)) == 0)
#define __math_not_positive_float(x) \
  (__math_high(x) >= 0x7f800000UL || __math_high(x) == 0)

/* mathieeedoubbas.library stops at DBL_MAX, and mathieeesingtrans.library has
   numbers above 2^127 which aren't right either.  */
#define __math_suspect_double(x)  (__math_power_double(x) >= 1023)
#define __math_suspect_float(x)   (__math_power_float(x) >= 127)

/* Each of these has a file of its own, so that a program only links the ones it
   calls.  */
static inline double __math_range(double result)
{
  errno = ERANGE;
  return result;
}

static inline float __math_rangef(float result)
{
  errno = ERANGE;
  return result;
}

extern double __math_domain(double x);
extern float __math_domainf(float x);
extern double __math_overflow(double sign);
extern float __math_overflowf(float sign);
extern double __math_underflow(double sign);
extern float __math_underflowf(float sign);
extern double __math_log_special(double x);
extern float __math_log_specialf(float x);
extern double __math_sqrt_special(double x);
extern float __math_sqrt_specialf(float x);
extern double __math_exp_special(double x);
extern float __math_exp_specialf(float x);
extern double __math_expm1_special(double x);
extern float __math_expm1_specialf(float x);
extern double __math_log1p_special(double x);
extern float __math_log1p_specialf(float x);
extern double __math_acosh_special(double x);
extern float __math_acosh_specialf(float x);
extern double __math_atanh_special(double x);
extern float __math_atanh_specialf(float x);
extern double __math_fmod_special(double x, double y);
extern float __math_fmod_specialf(float x, float y);
extern double __math_fma_special(double x, double y, double z);
extern double __math_hyperbolic(double x, double sign);
extern float __math_hyperbolicf(float x, float sign);
extern int __math_integer(double x);
extern int __math_integerf(float x);
extern int __math_fits(double rounded, int bits);
extern int __math_fitsf(float rounded, int bits);

#define __MATH_LONG_BITS 31
#define __MATH_LONG_LONG_BITS 63

/* C leaves it open whether a rounded number that doesn't fit is an error, and
   so glibc's EDOM it is.  One bit below the limit, it fits whatever the
   rounding does, so only numbers this size pay for rounding twice.  */
#define __MATH_ROUND_ERRNO(kind, suffix, x, round, bits) \
  do { \
    if (__math_power_##kind(x) >= (bits) - 1 && \
	!__math_fits##suffix(round(x), bits)) \
      errno = EDOM; \
  } while (0)

/* Only the software functions need what follows; with an FPU these are the
   functions they always were.  */
#ifdef __HAVE_68881__
#define __MATH_UNCHECKED(type, name) type name
#define __MATH_SOFT(fpu, soft) (fpu)
#else
#define __MATH_SETS_ERRNO
#define __MATH_UNCHECKED(type, name) static type __##name##_unchecked
#define __MATH_SOFT(fpu, soft) ((void)sizeof(fpu), (soft))
#endif

#endif /* _MATH_ERRNO_H */
