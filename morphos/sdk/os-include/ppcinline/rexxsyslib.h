/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_REXXSYSLIB_H
#define _PPCINLINE_REXXSYSLIB_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef REXXSYSLIB_BASE_NAME
#define REXXSYSLIB_BASE_NAME RexxSysBase
#endif /* !REXXSYSLIB_BASE_NAME */

#define LockRexxBase(__p0) \
	LP1NR(450, LockRexxBase, \
		ULONG , __p0, d0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockRexxBase(__p0) \
	LP1NR(456, UnlockRexxBase, \
		ULONG , __p0, d0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteRexxMsg(__p0) \
	LP1NR(150, DeleteRexxMsg, \
		struct RexxMsg *, __p0, a0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteArgstring(__p0) \
	LP1NR(132, DeleteArgstring, \
		STRPTR , __p0, a0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateRexxMsg(__p0, __p1, __p2) \
	LP3(144, struct RexxMsg *, CreateRexxMsg, \
		CONST struct MsgPort *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST_STRPTR , __p2, d0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsRexxMsg(__p0) \
	LP1(168, BOOL , IsRexxMsg, \
		CONST struct RexxMsg *, __p0, a0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LengthArgstring(__p0) \
	LP1(138, ULONG , LengthArgstring, \
		CONST_STRPTR , __p0, a0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearRexxMsg(__p0, __p1) \
	LP2NR(156, ClearRexxMsg, \
		struct RexxMsg *, __p0, a0, \
		ULONG , __p1, d0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateArgstring(__p0, __p1) \
	LP2(126, UBYTE *, CreateArgstring, \
		CONST_STRPTR , __p0, a0, \
		ULONG , __p1, d0, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FillRexxMsg(__p0, __p1, __p2) \
	LP3(162, BOOL , FillRexxMsg, \
		struct RexxMsg *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, REXXSYSLIB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_REXXSYSLIB_H */
