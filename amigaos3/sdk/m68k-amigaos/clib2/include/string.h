/*
 * $Id: string.h,v 1.12 2006-09-17 17:36:42 obarthel Exp $
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

#ifndef _STRING_H
#define _STRING_H

/****************************************************************************/

#ifndef _STDDEF_H
#include <stddef.h>
#endif /* _STDDEF_H */

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

extern __stdargs char *strerror(int error_number);
extern __stdargs char *strcat(char *dest, const char *src);
extern __stdargs char *strncat(char *dest, const char *src, size_t n);
extern __stdargs int strcmp(const char *s1, const char * s2);
extern __stdargs int strncmp(const char *s1, const char *s2, size_t n);
extern __stdargs char *strcpy(char *dest, const char *src);
extern __stdargs char *strncpy(char *dest, const char *src, size_t n);
extern __stdargs size_t strnlen(const char *s, size_t maxlen);
extern __stdargs size_t strlen(const char *s);
extern __stdargs char *strchr(const char *s, int c);
extern __stdargs char *strrchr(const char *s, int c);
extern __stdargs size_t strspn(const char *s, const char *set);
extern __stdargs size_t strcspn(const char *s, const char *set);
extern __stdargs char *strpbrk(const char *s, const char *set);
extern __stdargs char *strtok(char *str, const char *set);
extern __stdargs char *strstr(const char *src, const char *sub);

/****************************************************************************/

extern __stdargs int strcoll(const char *s1, const char *s2);
extern __stdargs size_t strxfrm(char *dest, const char *src, size_t len);

/****************************************************************************/

extern __stdargs void *memmove(void *dest, const void * src, size_t len);
extern __stdargs void *memchr(const void * ptr, int val, size_t len);

/* This is ugly: GCC 2.95.x assumes that 'unsigned long' is used in the built-in
   memcmp/memcpy/memset functions instead of 'size_t'. This can produce warnings
   where none are necessary. */
#if defined(__GNUC__) && (__GNUC__ < 3)
extern __stdargs int memcmp(const void *ptr1, const void *ptr2, unsigned long len);
extern __stdargs void *memcpy(void *dest, const void *src, unsigned long len);
extern __stdargs void *memset(void *ptr, int val, unsigned long len);
#else
extern __stdargs int memcmp(const void *ptr1, const void *ptr2, size_t len);
extern __stdargs void *memcpy(void *dest, const void *src, size_t len);
extern __stdargs void *memset(void *ptr, int val, size_t len);
#endif /* __GNUC__ && __GNUC__ < 3 */

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard. */

/****************************************************************************/

#ifndef _STRINGS_H
#include <strings.h>
#endif /* _STRINGS_H */

/****************************************************************************/

extern __stdargs int strerror_r(int error,char * buffer,size_t buffer_size);
extern __stdargs char * index(const char *s, int c);
extern __stdargs char * rindex(const char *s, int c);

/****************************************************************************/

extern __stdargs char * strdup(const char *s);

#ifdef __MEM_DEBUG
extern __stdargs char * __strdup(const char *s,const char *file,int line);

#define strdup(s) __strdup((s),__FILE__,__LINE__)
#endif /* __MEM_DEBUG */

/****************************************************************************/

extern __stdargs void bcopy(const void *from,void *to,size_t len);
extern __stdargs void bzero(void *m,size_t len);
extern __stdargs int bcmp(const void *a,const void *b,size_t len);

/****************************************************************************/

extern __stdargs size_t strlcpy(char *dst, const char *src, size_t siz);
extern __stdargs size_t strlcat(char *dst, const char *src, size_t siz);

/****************************************************************************/

extern __stdargs char * strtok_r(char *str, const char *separator_set,char ** state_ptr);

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _STRING_H */
