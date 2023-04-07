/*
 * $Id: getopt.h,v 1.5 2006-01-08 12:06:14 obarthel Exp $
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

#ifndef _GETOPT_H
#define _GETOPT_H

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard. */

/****************************************************************************/

#include <unistd.h>

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

#define no_argument 		0
#define required_argument	1
#define optional_argument	2

struct option 
{
	const char *	name;
	int 			has_arg;
	int *			flag;
	int 			val;
};

/****************************************************************************/

extern __stdargs int getopt_long(int argc, const char **argv, const char *optstring,
		const struct option *longopts, int *longindex);

/*extern __stdargs int getopt_long_only(int argc, const char **argv, const char *optstring,
		const struct option *longopts, int *longindex);
*/
extern int optreset;

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _GETOPT_H */
