/*
 * $Id: wctype.h,v 1.8 2008-04-30 14:41:28 obarthel Exp $
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

#ifndef _WCYTPE_H
#define _WCYTPE_H

/****************************************************************************/

#ifndef _WCHAR_H
#include <wchar.h>
#endif /* _WCHAR_H */

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

typedef long wctype_t; /* ZZZ */
typedef long wctrans_t; /* ZZZ */

/****************************************************************************/

extern __stdargs int iswalnum(wint_t c);
extern __stdargs int iswalpha(wint_t c);
extern __stdargs int iswcntrl(wint_t c);

extern __stdargs int iswdigit(wint_t c);
extern __stdargs int iswxdigit(wint_t c);

extern __stdargs int iswgraph(wint_t c);
extern __stdargs int iswpunct(wint_t c);
extern __stdargs int iswprint(wint_t c);

extern __stdargs int iswlower(wint_t c);
extern __stdargs int iswupper(wint_t c);

extern __stdargs int iswspace(wint_t c);
extern __stdargs int iswblank(wint_t c);

extern __stdargs wint_t towlower(wint_t c);
extern __stdargs wint_t towupper(wint_t c);

/****************************************************************************/

extern __stdargs wctype_t wctype(const char *property);
extern __stdargs int iswctype(wint_t c, wctype_t desc);

/****************************************************************************/

extern __stdargs wctrans_t wctrans(const char *property);
extern __stdargs wint_t towctrans(wint_t c, wctrans_t desc);

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _WCYTPE_H */
