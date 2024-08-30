/*
 * Copyright (c) 2021 Frust GmbH
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _TGMATH_H
#define _TGMATH_H

#include <complex.h>
#include <math.h>

#undef acos
#undef acosh
#undef asin
#undef asinh
#undef atan
#undef atan2
#undef atanh
#undef carg
#undef cbrt
#undef ceil
#undef cimag
#undef conj
#undef copysign
#undef cos
#undef cosh
#undef cproj
#undef creal
#undef erf
#undef erfc
#undef exp
#undef exp2
#undef expm1
#undef fabs
#undef fdim
#undef floor
#undef fma
#undef fmax
#undef fmin
#undef fmod
#undef frexp
#undef hypot
#undef ilogb
#undef ldexp
#undef lgamma
#undef llrint
#undef llround
#undef log
#undef log10
#undef log1p
#undef log2
#undef logb
#undef lrint
#undef lround
#undef nearbyint
#undef nextafter
#undef nexttoward
#undef pow
#undef remainder
#undef remquo
#undef rint
#undef round
#undef scalbln
#undef scalbn
#undef sin
#undef sinh
#undef sqrt
#undef tan
#undef tanh
#undef tgamma
#undef trunc

#define acos(x) __builtin_tgmath(acosf, acos, acosl, cacosf, cacos, cacosl, x)
#define acosh(x) __builtin_tgmath(acoshf, acosh, acoshl, cacoshf, cacosh, cacoshl, x)
#define asin(x) __builtin_tgmath(asinf, asin, asinl, casinf, casin, casinl, x)
#define asinh(x) __builtin_tgmath(asinhf, asinh, asinhl, casinhf, casinh, casinhl, x)
#define atan(x) __builtin_tgmath(atanf, atan, atanl, catanf, catan, catanl, x)
#define atan2(x,y) __builtin_tgmath(atan2f, atan2, atan2l, x, y)
#define atanh(x) __builtin_tgmath(atanhf, atanh, atanhl, catanhf, catanh, catanhl, x)
#define carg(x) __builtin_tgmath(cargf, carg, cargl, x)
#define cbrt(x) __builtin_tgmath(cbrtf, cbrt, cbrtl, x)
#define ceil(x) __builtin_tgmath(ceilf, ceil, ceill, x)
#define cimag(x) __builtin_tgmath(cimagf, cimag, cimagl, x)
#define conj(x) __builtin_tgmath(conjf, conj, conjl, x)
#define copysign(x,y) __builtin_tgmath(copysignf, copysign, copysignl, x, y)
#define cos(x) __builtin_tgmath(cosf, cos, cosl, ccosf, ccos, ccosl, x)
#define cosh(x) __builtin_tgmath(coshf, cosh, coshl, ccoshf, ccosh, ccoshl, x)
#define cproj(x) __builtin_tgmath(cprojf, cproj, cprojl, x)
#define creal(x) __builtin_tgmath(crealf, creal, creall, x)
#define erf(x) __builtin_tgmath(erff, erf, erfl, x)
#define erfc(x) __builtin_tgmath(erfcf, erfc, erfcl, x)
#define exp(x) __builtin_tgmath(expf, exp, expl, cexpf, cexp, cexpl, x)
#define exp2(x) __builtin_tgmath(exp2f, exp2, exp2l, x)
#define expm1(x) __builtin_tgmath(expm1f, expm1, expm1l, x)
#define fabs(x) __builtin_tgmath(fabsf, fabs, fabsl, x)
#define fdim(x,y) __builtin_tgmath(fdimf, fdim, fdiml, x, y)
#define floor(x) __builtin_tgmath(floorf, floor, floorl, x)
#define fma(x,y,z) __builtin_tgmath(fmaf, fma, fmal, x, y, z)
#define fmax(x,y) __builtin_tgmath(fmaxf, fmax, fmaxl, x, y)
#define fmin(x,y) __builtin_tgmath(fminf, fmin, fminl, x, y)
#define fmod(x,y) __builtin_tgmath(fmodf, fmod, fmodl, x, y)
#define frexp(x,y) __builtin_tgmath(frexpf, frexp, frexpl, x, y)
#define hypot(x,y) __builtin_tgmath(hypotf, hypot, hypotl, x, y)
#define ilogb(x) __builtin_tgmath(ilogbf, ilogb, ilogbl, x)
#define ldexp(x,y) __builtin_tgmath(ldexpf, ldexp, ldexpl, x, y)
#define lgamma(x) __builtin_tgmath(lgammaf, lgamma, lgammal, x)
#define llrint(x) __builtin_tgmath(llrintf, llrint, llrintl, x)
#define llround(x) __builtin_tgmath(llroundf, llround, llroundl, x)
#define log(x) __builtin_tgmath(logf, log, logl, clogf, clog, clogl, x)
#define log10(x) __builtin_tgmath(log10f, log10, log10l, x)
#define log1p(x) __builtin_tgmath(log1pf, log1p, log1pl, x)
#define log2(x) __builtin_tgmath(log2f, log2, log2l, x)
#define logb(x) __builtin_tgmath(logbf, logb, logbl, x)
#define lrint(x) __builtin_tgmath(lrintf, lrint, lrintl, x)
#define lround(x) __builtin_tgmath(lroundf, lround, lroundl, x)
#define nearbyint(x) __builtin_tgmath(nearbyintf, nearbyint, nearbyintl, x)
#define nextafter(x,y) __builtin_tgmath(nextafterf, nextafter, nextafterl, x, y)
#define nexttoward(x,y) __builtin_tgmath(nexttowardf, nexttoward, nexttowardl, x, y)
#define pow(a, b) __builtin_tgmath(powf, pow, powl, cpowf, cpow, cpowl, a, b)
#define remainder(x,y) __builtin_tgmath(remainderf, remainder, remainderl, x, y)
#define remquo(x,y,z) __builtin_tgmath(remquof, remquo, remquol, x, y, z)
#define rint(x) __builtin_tgmath(rintf, rint, rintl, x)
#define round(x) __builtin_tgmath(roundf, round, roundl, x)
#define scalbln(x,y) __builtin_tgmath(scalblnf, scalbln, scalblnl, x, y)
#define scalbn(x,y) __builtin_tgmath(scalbnf, scalbn, scalbnl, x, y)
#define sin(x) __builtin_tgmath(sinf, sin, sinl, csinf, csin, csinl, x)
#define sinh(x) __builtin_tgmath(sinhf, sinh, sinhl, csinhf, csinh, csinhl, x)
#define sqrt(x) __builtin_tgmath(sqrtf, sqrt, sqrtl, csqrtf, csqrt, csqrtl, x)
#define tan(x) __builtin_tgmath(tanf, tan, tanl, ctanf, ctan, ctanl, x)
#define tanh(x) __builtin_tgmath(tanhf, tanh, tanhl, ctanhf, ctanh, ctanhl, x)
#define tgamma(x) __builtin_tgmath(tgammaf, tgamma, tgammal, x)
#define trunc(x) __builtin_tgmath(truncf, trunc, truncl, x)

#endif /* _TGMATH_H */
