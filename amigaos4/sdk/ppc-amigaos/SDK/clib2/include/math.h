/*
 * $Id: math.h,v 1.22 2007-01-06 10:09:49 obarthel Exp $
 *
 * :ts=4
 *
 * Portable ISO 'C' (1994) runtime library for the Amiga computer
 * Copyright (c) 2002-2015 by Olaf Barthel <obarthel (at) gmx.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   - Neither the name of Olaf Barthel nor the names of contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************
 *
 * Documentation and source code for this library, and the most recent library
 * build are available from <http://sourceforge.net/projects/clib2>.
 *
 *****************************************************************************
 */

#ifndef _MATH_H
#define _MATH_H

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

#ifndef _STDLIB_H
#include <stdlib.h>
#endif /* _STDLIB_H */

/****************************************************************************/

extern double __huge_val;

/****************************************************************************/

#define	HUGE_VAL ((const double)__huge_val)

/****************************************************************************/

extern double acos(double x);
extern double asin(double x);
extern double atan(double x);
extern double atan2(double y,double x);
extern double ceil(double x);
extern double cos(double x);
extern double cosh(double x);
extern double exp(double x);
extern double fabs(double x);
extern double floor(double x);
extern double fmod(double x,double y);
extern double frexp(double x,int *nptr);
extern double ldexp(double x,int n);
extern double log(double x);
extern double log10(double x);
extern double modf(double x,double *nptr);
extern double pow(double x,double y);
extern double sin(double x);
extern double sinh(double x);
extern double sqrt(double x);
extern double tan(double x);
extern double tanh(double x);

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard. */

/****************************************************************************/

#define	M_E			2.7182818284590452354
#define	M_LOG2E		1.4426950408889634074
#define	M_LOG10E	0.43429448190325182765
#define	M_LN2		0.69314718055994530942
#define	M_LN10		2.30258509299404568402
#define	M_PI		3.14159265358979323846
#define	M_PI_2		1.57079632679489661923
#define	M_PI_4		0.78539816339744830962
#define	M_1_PI		0.31830988618379067154
#define	M_2_PI		0.63661977236758134308
#define	M_2_SQRTPI	1.12837916709551257390
#define	M_SQRT2		1.41421356237309504880
#define	M_SQRT1_2	0.70710678118654752440

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard, but it should
   be part of ISO/IEC 9899:1999, also known as "C99". */

/****************************************************************************/

/* Note that the comparison operations performed on the floating point
   data types ought to include float, double and long double. However,
   because the current (2005-06-12) compiler technology available on the
   Amiga does not support the long double type yet, this library is
   restricted to operations on float and double. */

/****************************************************************************/

extern float __huge_val_float;

/****************************************************************************/

#define	HUGE_VALF ((const float)__huge_val_float)

/****************************************************************************/

extern float __infinity;
extern float __nan;

/****************************************************************************/

#define INFINITY	((const float)__infinity)
#define NAN			((const float)__nan)

/****************************************************************************/

#define FP_INFINITE		0	/* -/+ infinity */
#define FP_NAN			1	/* not a number */
#define FP_NORMAL		2	/* normalized floating point number */
#define FP_SUBNORMAL	3	/* very small floating point number; special
							   case of IEEE 754 */
#define FP_ZERO			4	/* exponent/fraction are zero */
#define FP_ILOGB0		0
#define FP_ILOGBNAN		NAN

/****************************************************************************/

#if defined __has_builtin
#if __has_builtin (__builtin_isunordered)
#define isunordered(x,y) __builtin_isunordered(x,y)
#endif /* __builtin_isunordered */
#if __has_builtin (__builtin_isgreater)
#define isgreater(x,y) __builtin_isgreater(x,y)
#endif /* __builtin_isgreater */
#if __has_builtin (__builtin_isgreaterqeual)
#define isgreaterqeual(x,y) __builtin_isgreaterqeual(x,y)
#endif /* __builtin_isgreaterqeual */
#if __has_builtin (__builtin_isless)
#define isless(x,y) __builtin_isless(x,y)
#endif /* __builtin_isless */
#if __has_builtin (__builtin_islessequal)
#define islessequal(x,y) __builtin_islessequal(x,y)
#endif /* __builtin_islessequal */
#if __has_builtin (__builtin_islessgreater)
#define islessgreater(x,y) __builtin_islessgreater(x,y)
#endif /* __builtin_islessgreater */
#if __has_builtin (__builtin_isinf)
#define isinf(x) __builtin_isinf(x)
#endif /* __builtin_isinf */
#if __has_builtin (__builtin_isnan)
#define isnan(x) __builtin_isnan(x)
#endif /* __builtin_isnan */
#if __has_builtin (__builtin_isnormal)
#define isnormal(x) __builtin_isnormal(x)
#endif /* __builtin_isnormal */
#if __has_builtin (__builtin_fpclassify)
#define fpclassify(x) (__builtin_fpclassify(FP_NAN, FP_INFINITE, \
FP_NORMAL, FP_SUBNORMAL, FP_ZERO, x))
#endif /* __builtin_fpclassify */
#if __has_builtin (__builtin_isfinite)
#define isfinite(x) __builtin_isfinite(x)
#endif /* __builtin_isinfinite */
#if __has_builtin (__builtin_signbit)
#define signbit(x) __builtin_signbit(x)
#endif /* __builtin_signbit */
#if __has_builtin (__builtin_isinf)
#define isinf(x) __builtin_isinf(x)
#endif /* __builtin_isinf */
#if __has_builtin (__builtin_isnan)
#define isnan(x) __builtin_isnan(x)
#endif /* __builtin_isnan */
#if __has_builtin (__builtin_isnormal)
#define isnormal(x) __builtin_isnormal(x)
#endif /* __builtin_isnormal */
#endif /* __has_builtin */

/****************************************************************************/

#ifndef fpclassify
extern int __fpclassify_float(float x);
extern int __fpclassify_double(double x);
extern int __fpclassify_long_double(long double x);
#define fpclassify(x) _Generic(x, float : __fpclassify_float, \
double : __fpclassify_double, long double : __fpclassify_long_double)(x)
#endif /* fpclassify */
#ifndef isfinite
extern int __isfinite_float(float x);
extern int __isfinite_double(double x);
extern int __isfinite_long_double(long double x);
#define isfinite(x) _Generic(x, float : __isfinite_float, \
double : __isfinite_double, long double : __isfinite_long_double)(x)
#endif /* isfinite */
#ifndef signbit
extern int __signbit_float(float x);
extern int __signbit_double(double x);
extern int __signbit_long_double(long double x);
#define signbit(x) _Generic(x, float : __signbit_float, \
double : __signbit_double, long double : __signbit_long_double)(x)
#endif /* signbit */
#ifndef isinf
#define isinf(x) (fpclassify(x) == FP_INFINITE)
#endif /* isinf */
#ifndef isnan
#define isnan(x) (fpclassify(x) == FP_NAN)
#endif /* isnan */
#ifndef isnormal
#define isnormal(x) (fpclassify(x) == FP_NORMAL)
#endif /* isnormal */
#ifndef isunordered
#define isunordered(x,y) (isnan((x)) ? ((void)(y),1) : isnan((y)))
#endif /* isunordered */
#ifndef isgreater
#define isgreater(x,y) (isunordered(x,y) ? 0 : (x) > (y))
#endif /* isgreater */
#ifndef isgreaterequal
#define isgreaterequal(x,y) (isunordered(x,y) ? 0 : (x) >= (y))
#endif /* isgreaterequal */
#ifndef isless
#define isless(x,y) (isunordered(x,y) ? 0 : (x) < (y))
#endif /* isless */
#ifndef islessequal
#define islessequal(x,y) (isunordered(x,y) ? 0 : (x) <= (y))
#endif /* islessequal */
#ifndef islessgreater
/* ZZZ don't evaluate twice! */
#define islessgreater(x,y) (isunordered(x,y) ? 0 : (x) < (y) || (x) > (y))
#endif /* islessgreater */

/****************************************************************************/

extern float acosf(float x);
extern float asinf(float x);
extern float atanf(float x);
extern float atan2f(float y, float x);
extern float ceilf(float x);
extern float cosf(float x);
extern float coshf(float x);
extern float expf(float x);
extern float fabsf(float x);
extern float floorf(float x);
extern float fmodf(float x, float y);
extern float frexpf(float x, int *eptr);
extern float ldexpf(float x,int exp);
extern float logf(float x);
extern float log10f(float x);
extern float modff(float x, float *iptr);
extern float powf(float x, float y);
extern float sinf(float x);
extern float sinhf(float x);
extern float sqrtf(float x);
extern float tanf(float x);
extern float tanhf(float x);

/****************************************************************************/

extern float acoshf(float x);
extern float asinhf(float x);
extern float atanhf(float x);
extern float cbrtf(float x);
extern float copysignf(float x, float y);
extern float erfcf(float x);
extern float erff(float x);
extern float expm1f(float x);
extern float fdimf(float x,float y);
extern float fmaf(float x,float y,float z);
extern float fmaxf(float x,float y);
extern float fminf(float x,float y);
extern float hypotf(float x, float y);
extern float lgammaf(float x);
extern float log1pf(float x);
extern float logbf(float x);
extern long long int llrintf(float x);
extern long int lrintf(float x);
extern long long int llroundf(float x);
extern long int lroundf(float x);
extern float nanf(const char *tagp);
extern float nearbyintf(float x);
extern float nextafterf(float x,float y);
extern float nexttowardf(float x, long double y);
extern float remainderf(float x, float p);
extern float remquof(float x,float y,int * quo);
extern float rintf(float x);
extern float roundf(float x);
extern float scalblnf(float x, long n);
extern float scalbnf(float x, int n);
extern float tgammaf(float x);
extern float truncf(float x);
extern int ilogbf(float x);

/****************************************************************************/

extern double acosh(double x);
extern double asinh(double x);
extern double atanh(double x);
extern double cbrt(double x);
extern double copysign(double x, double y);
extern double erf(double x);
extern double erfc(double x);
extern double expm1(double x);
extern double fdim(double x,double y);
extern double fma(double x,double y,double z);
extern double fmax(double x,double y);
extern double fmin(double x,double y);
extern double hypot(double x,double y);
extern double lgamma(double x);
extern double log1p(double x);
extern double logb(double x);
extern long long int llrint(double x);
extern long int lrint(double x);
extern long long int llround(double x);
extern long int lround(double x);
extern double nan(const char *tagp);
extern double nearbyint(double x);
extern double nextafter(double x,double y);
extern double nexttoward(double x, long double y);
extern double remainder(double x, double p);
extern double remquo(double x,double y,int * quo);
extern double rint(double x);
extern double round(double x);
extern double scalbln(double x, long n);
extern double scalbn (double x, int n);
extern double tgamma(double x);
extern double trunc(double x);
extern int ilogb(double x);

/****************************************************************************/

extern float exp2f(float x);
extern double exp2(double x);
extern long double exp2l(long double x);

extern double log2(double x);
extern float log2f(float x);
extern long double log2l(long double x);

/****************************************************************************/

extern long double acosl(long double x);
extern long double asinl(long double x);
extern long double atanl(long double x);
extern long double atan2l(long double y, long double x);
extern long double ceill(long double x);
extern long double cosl(long double x);
extern long double coshl(long double x);
extern long double expl(long double x);
extern long double fabsl(long double x);
extern long double floorl(long double x);
extern long double fmodl(long double x, long double y);
extern long double frexpl(long double x, int *nptr);
extern long double ldexpl(long double x, int n);
extern long double logl(long double x);
extern long double log10l(long double x);
extern long double modfl(long double x, long double *iptr);
extern long double powl(long double x, long double y);
extern long double sinl(long double x);
extern long double sinhl(long double x);
extern long double sqrtl(long double x);
extern long double tanl(long double x);
extern long double tanhl(long double x);

/****************************************************************************/

extern long double acoshl(long double x);
extern long double asinhl(long double x);
extern long double atanhl(long double x);
extern long double cbrtl(long double x);
extern long double copysignl(long double x, long double y);
extern long double erfcl(long double x);
extern long double erfl(long double x);
extern long double expm1l(long double x);
extern long double fdiml(long double x, long double y);
extern long double fmal(long double x, long double y, long double z);
extern long double fmaxl(long double x, long double y);
extern long double fminl(long double x, long double y);
extern long double hypotl(long double x, long double y);
extern long double lgammal(long double x);
extern long double log1pl(long double x);
extern long double logbl(long double x);
extern long long int llrintl(long double x);
extern long int lrintl(long double x);
extern long long int llroundl(long double x);
extern long int lroundl(long double x);
extern long double nanl(const char *tagp);
extern long double nearbyintl(long double x);
extern long double nextafterl(long double x, long double y);
extern long double nexttowardl(long double x, long double y);
extern long double remainderl(long double x, long double p);
extern long double remquol(long double x, long double y, int *quo);
extern long double rintl(long double x);
extern long double roundl(long double x);
extern long double scalblnl(long double x, long int n);
extern long double scalbnl(long double x, int n);
extern long double tgammal(long double x);
extern long double truncl(long double x);
extern int ilogbl(long double x);

/****************************************************************************/

#define FLT_EVAL_METHOD 0

/****************************************************************************/

typedef float	float_t;
typedef double	double_t;

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _MATH_H */
