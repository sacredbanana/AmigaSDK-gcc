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

#ifndef _UCHAR_H
#define _UCHAR_H

#if __STDC_VERSION__ >= 199901L
#define __restrict restrict
#elif !defined(__GNUC__)
#define __restrict
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _WCHAR_H
#include <wchar.h>
#endif /* _WCHAR_H */

#if !defined(__cplusplus) || __cplusplus < 201103L
typedef uint16_t char16_t;
typedef uint32_t char32_t;
#endif /* __cplusplus */

size_t c16rtomb(char * __restrict s, char16_t c16, mbstate_t * __restrict ps);
size_t mbrtoc16(char16_t * __restrict pc16, const char * __restrict s,
    size_t n, mbstate_t * __restrict ps);
size_t c32rtomb(char * __restrict s, char32_t c32, mbstate_t * __restrict ps);
size_t mbrtoc32(char32_t * __restrict pc32, const char * __restrict s, size_t n,
    mbstate_t * __restrict ps);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _UCHAR_H */
