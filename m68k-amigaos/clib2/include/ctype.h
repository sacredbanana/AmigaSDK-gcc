/*
 * $Id: ctype.h,v 1.10 2006-01-08 12:06:14 obarthel Exp $
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

#ifndef _CTYPE_H
#define _CTYPE_H

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

extern __stdargs int isalnum(int c);
extern __stdargs int isalpha(int c);
extern __stdargs int iscntrl(int c);

extern __stdargs int isdigit(int c);
extern __stdargs int isxdigit(int c);

extern __stdargs int isgraph(int c);
extern __stdargs int ispunct(int c);
extern __stdargs int isprint(int c);

extern __stdargs int islower(int c);
extern __stdargs int isupper(int c);

extern __stdargs int isspace(int c);
extern __stdargs int isblank(int c);

extern __stdargs int tolower(int c);
extern __stdargs int toupper(int c);

/****************************************************************************/

/*
 * If requested, reimplement the character classification functions as macros;
 * note that the macro variants ignore the current locale and default to the
 * 'C' locale rules.
 */

#define __CTYPE_CONTROL		0x01	/* This is a control character */
#define __CTYPE_DIGIT		0x02	/* This is a 'decimal' digit */
#define __CTYPE_HEX_DIGIT	0x04	/* This is a hexadecimal digit */
#define __CTYPE_PUNCTUATION	0x08	/* This is a punctuation character */
#define __CTYPE_PRINTABLE	0x10	/* This is a printable character */
#define __CTYPE_WHITE_SPACE	0x20	/* This is a blank space character */
#define __CTYPE_LOWER_CASE	0x40	/* This is a lower case letter */
#define __CTYPE_UPPER_CASE	0x80	/* This is an upper case letter */

#if 0
// or this one?
#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200 

#else

#define	_U	__CTYPE_UPPER_CASE
#define	_L	__CTYPE_LOWER_CASE
#define	_N	__CTYPE_DIGIT
#define	_S	__CTYPE_WHITE_SPACE
#define _P	__CTYPE_PUNCTUATION
#define _C	__CTYPE_CONTROL
#define _X	__CTYPE_HEX_DIGIT
#define _B	__CTYPE_PRINTABLE
#endif


#ifdef __C_MACROS__

/****************************************************************************/

extern const unsigned char __ctype_table[];

/****************************************************************************/

/****************************************************************************/

#define isalnum(c)	((__ctype_table[(c) & 255] & (__CTYPE_DIGIT|__CTYPE_LOWER_CASE|__CTYPE_UPPER_CASE)) != 0)
#define isalpha(c)	((__ctype_table[(c) & 255] & (__CTYPE_LOWER_CASE|__CTYPE_UPPER_CASE)) != 0)
#define iscntrl(c)	((__ctype_table[(c) & 255] & __CTYPE_CONTROL) != 0)
#define isdigit(c)	((__ctype_table[(c) & 255] & __CTYPE_DIGIT) != 0)
#define isxdigit(c)	((__ctype_table[(c) & 255] & __CTYPE_HEX_DIGIT) != 0)
#define isgraph(c)	((__ctype_table[(c) & 255] & (__CTYPE_DIGIT|__CTYPE_PUNCTUATION|__CTYPE_LOWER_CASE|__CTYPE_UPPER_CASE)) != 0)
#define ispunct(c)	((__ctype_table[(c) & 255] & __CTYPE_PUNCTUATION) != 0)
#define isprint(c)	((__ctype_table[(c) & 255] & __CTYPE_PRINTABLE) != 0)
#define islower(c)	((__ctype_table[(c) & 255] & __CTYPE_LOWER_CASE) != 0)
#define isupper(c)	((__ctype_table[(c) & 255] & __CTYPE_UPPER_CASE) != 0)
#define isspace(c)	((__ctype_table[(c) & 255] & __CTYPE_WHITE_SPACE) != 0)
#define isblank(c)	((c) == ' ' || (c) == '\t')

/****************************************************************************/

#endif /* __C_MACROS__ */

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard. */

#define isascii(c) ((unsigned)(c) <= 127)

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _CTYPE_H */
