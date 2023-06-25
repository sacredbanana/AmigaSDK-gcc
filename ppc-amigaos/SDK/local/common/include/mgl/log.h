/*
 * $Id: log.h 2 2000-04-07 19:44:48Z tfrieden $
 *
 * $Date: 2000-04-07 23:44:48 +0400 (Fri, 07 Apr 2000) $
 * $Revision: 2 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef __LOG_H
#define __LOG_H

/*
** Logging was removed in final version
*/

/*
** It is probably difficult to support logging of gl calls on other compilers,
** since the egcs/gcc preprocessor supports variable argument macros, and
** I am using it :)
*/
/*
#ifdef NLOGGING
#define LOG(level, func, format, args...)
#else
#ifdef __PPC__
extern int MGLDebugLevel;
#define LOG(level, func, format, args...) \
	if (MGLDebugLevel >= level)            \
	{                                       \
		kprintf("[MiniGL::%s] ", #func);     \
		kprintf(format , ## args );           \
		kprintf("\n");                         \
	}
#else
extern int MGLDebugLevel;
#define LOG(level, func, format, args...) \
	if (MGLDebugLevel >= level)            \
	{                                       \
		mykprintf("[MiniGL::%s] ", #func);   \
		mykprintf(format , ## args );         \
		mykprintf("\n");                       \
	}
#endif

#endif

*/
#endif
