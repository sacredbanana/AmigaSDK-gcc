/*
 * $Id: wchar.h,v 1.8 2008-04-30 14:34:03 obarthel Exp $
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

#ifndef _WCHAR_H
#define _WCHAR_H

#if __STDC_VERSION__ >= 199901L
#define __restrict restrict
#elif !defined(__GNUC__)
#define __restrict
#endif

/****************************************************************************/

#ifndef _SYS_CLIB2_STDC_H
#include <sys/clib2_stdc.h>
#endif /* _SYS_CLIB2_STDC_H */

#ifndef _STDDEF_H
#include <stddef.h>
#endif /* _STDDEF_H */

#ifndef _STDIO_H
#include <stdio.h>
#endif /* _STDIO_H */

#ifndef _STDARG_H
#include <stdarg.h>
#endif /* _STDARG_H */

#ifndef _TIME_H
#include <time.h>
#endif /* _TIME_H */

#ifndef _LOCALE_H
#include <locale.h>
#endif /* _LOCALE_H */

#ifndef _STDINT_H
#include <stdint.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

#define WEOF (-1)

/****************************************************************************/

typedef long int wint_t;
typedef long mbstate_t;

/****************************************************************************/

extern wint_t btowc(int c);
extern int wctob(wint_t c);
extern int mbsinit(const mbstate_t *ps);
extern size_t wcrtomb(char *s, wchar_t wc, mbstate_t *ps);
extern size_t mbsrtowcs(wchar_t * __restrict pwcs,
    const char ** __restrict src, size_t n, mbstate_t * __restrict ps);
extern size_t wcsrtombs(char * __restrict s, const wchar_t ** __restrict src,
    size_t n, mbstate_t * __restrict ps);

/****************************************************************************/

extern wchar_t *wcscat(wchar_t * __restrict p, const wchar_t * __restrict q);
extern wchar_t *wcsncat(wchar_t * __restrict p, const wchar_t * __restrict q,
    size_t n);
extern int wcscmp(const wchar_t *p, const wchar_t *q);
extern int wcsncmp(const wchar_t *p, const wchar_t *q, size_t n);
extern wchar_t * wcscpy(wchar_t * __restrict p, const wchar_t * __restrict q);
extern wchar_t * wcsncpy(wchar_t * __restrict p, const wchar_t * __restrict q,
    size_t n);
extern size_t wcslen(const wchar_t *s);
extern wchar_t * wcschr(const wchar_t *p, wchar_t c);
extern size_t wcsspn(const wchar_t *p, const wchar_t *q);
extern wchar_t *wcspbrk(const wchar_t *p, const wchar_t *q);
extern wchar_t *wcstok(wchar_t * __restrict s, const wchar_t * __restrict q,
    wchar_t ** __restrict p);
extern wchar_t *wcsstr(const wchar_t *src, const wchar_t *sub);

/****************************************************************************/

extern float wcstof(const wchar_t * __restrict p, wchar_t ** __restrict q);
extern double wcstod(const wchar_t * __restrict p, wchar_t ** __restrict q);
extern long double wcstold(const wchar_t * __restrict p,
    wchar_t ** __restrict q);
extern long wcstol(const wchar_t * __restrict p, wchar_t ** __restrict q,
    int base);
extern long long wcstoll(const wchar_t * __restrict p, wchar_t ** __restrict q,
    int base);
extern unsigned long wcstoul(const wchar_t * __restrict p,
    wchar_t ** __restrict q, int base);
extern unsigned long long wcstoull(const wchar_t * __restrict p,
    wchar_t ** __restrict q, int base);

/****************************************************************************/

extern int wscoll(const wchar_t *p, const wchar_t *q);
extern size_t wcsxfrm(wchar_t * __restrict p,
    const wchar_t * __restrict q, size_t n);

/****************************************************************************/

extern wchar_t *wmemchr(const wchar_t *p, wchar_t c, size_t n);
extern int wmemcmp(const wchar_t *p, const wchar_t *q, size_t n);
extern wchar_t *wmemcpy(wchar_t * __restrict p,
    const wchar_t * __restrict q, size_t n);
extern wchar_t *wmemmove(wchar_t *p, const wchar_t *q, size_t n);
extern wchar_t *wmemset(wchar_t *p, int c, size_t n);

/****************************************************************************/

extern int fwide(FILE *f, int mode);

/****************************************************************************/

extern wint_t fgetwc(FILE *f);
extern wint_t getwc(FILE *f);
extern wint_t getwchar(void);
extern wint_t ungetwc(wint_t c, FILE *f);

/****************************************************************************/

extern wchar_t *fgetws(wchar_t * __restrict p, int n, FILE * __restrict f);

/****************************************************************************/

extern int fwscanf(FILE * __restrict f, const wchar_t * __restrict format, ...);
extern int vfwscanf(FILE * __restrict f, const wchar_t * __restrict format,
    va_list arg);
extern int wscanf(const wchar_t * __restrict format, ...);
extern int vwscanf(const wchar_t * __restrict format, va_list arg);
extern int swscanf(wchar_t * __restrict s,
    const wchar_t * __restrict format, ...);
extern int vswscanf(wchar_t * __restrict s, const wchar_t * __restrict format,
    va_list arg);

/****************************************************************************/

extern wint_t fputwc(wchar_t c, FILE *f);
extern wint_t putwc(wchar_t c, FILE *f);
extern wint_t putwchar(wchar_t c);

/****************************************************************************/

extern wint_t fputws(const wchar_t * __restrict s, FILE * __restrict f);

/****************************************************************************/

extern int fwprintf(FILE * __restrict f,
    const wchar_t * __restrict format, ...);
extern int wprintf(const wchar_t * __restrict format, ...);
extern int swprintf(wchar_t * __restrict s,
    const wchar_t * __restrict format, ...);
/****************************************************************************/

extern int vfwprintf(FILE * __restrict f, const wchar_t * __restrict format,
    va_list arg);
extern int vwprintf(const wchar_t * __restrict format, va_list arg);
extern int vswprintf(wchar_t * __restrict s, size_t maxlen,
    const wchar_t * __restrict format, va_list arg);

/****************************************************************************/

extern size_t wcsftime(wchar_t * __restrict s, size_t n,
    const wchar_t * __restrict f, const struct tm * __restrict tm);

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard, but it should
   be part of ISO/IEC 9899:1999, also known as "C99". */

/****************************************************************************/

extern size_t mbrlen(const char *__restrict s, size_t n,
    mbstate_t *__restrict ps);
extern size_t mbrtowc(wchar_t * __restrict wcp, const char * __restrict sp,
    size_t n, mbstate_t * __restrict ps);
extern int mbsinit(const mbstate_t *ps);
extern size_t mbsnrtowcs(wchar_t *__restrict dst, const char **__restrict src,
    size_t nmc, size_t len, mbstate_t *__restrict ps);
extern size_t mbsrtowcs(wchar_t *__restrict dst, const char **__restrict src,
    size_t len, mbstate_t *__restrict ps);
extern size_t wcrtomb(char * __restrict p, wchar_t c,
    mbstate_t * __restrict ps);
extern int wcscoll(const wchar_t *ws1, const wchar_t *ws2);
extern int wcscoll_l(const wchar_t *ws1, const wchar_t *ws2, locale_t loc);
extern size_t wcscspn(const wchar_t *p, const wchar_t *q);
extern size_t wcsnrtombs(char *__restrict dst, const wchar_t **__restrict src,
    size_t nwc, size_t len, mbstate_t *__restrict ps);
extern wchar_t * wcsrchr(const wchar_t *ws, wchar_t wc);
extern size_t wcsrtombs(char *p, const wchar_t **sp, size_t n, mbstate_t *ps);
extern long long wcstoll(const wchar_t *p, wchar_t **q, int base);
extern unsigned long long wcstoull(const wchar_t *p, wchar_t **q, int base);

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _WCHAR_H */
