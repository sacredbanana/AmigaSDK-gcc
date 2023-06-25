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

#ifndef _STDALIGN_H
#define _STDALIGN_H

#ifndef __cplusplus

#if __STDC_VERSION__ < 201112L

#if defined __has_attribute
#if __has_attribute(__aligned__)
#define _Alignas(t) __attribute__((__aligned__(t)))
#endif /* __has_attribute(__aligned__) */
#if __has_attribute(__alignof__)
#define _Alignof(t) __alignof__(t)
#endif /* __has_attribute(__alignof__) */
#endif /* __has_attribute */

#endif /* __STDC_VERSION__ < 201112L */

#define alignas _Alignas
#define alignof _Alignof

#endif /* __cplusplus */

#define __alignas_is_defined 1
#define __alignof_is_defined 1

#endif /* _STDALIGN_H */
