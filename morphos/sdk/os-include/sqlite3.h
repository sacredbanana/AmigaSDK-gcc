/*
 * libsqlite3.a wrapper
 *
 * Basically includes the MorphOS-style library headers here, so that
 * code doesn't need to be changed to be portable.
 *
 * Copyright © 2014 The MorphOS Development Team, All Rights Reserved.
*/

#if !defined(__MORPHOS_SHAREDLIBS) || defined(__ixemul__)

#include_next <sqlite3.h>

#else

#ifndef SQLITE3_H
#define SQLITE3_H

#include <libraries/sqlite3.h>
#include <proto/sqlite.h>

#endif /* SQLITE3_H */

#endif /* __MORPHOS_SHAREDLIBS */
