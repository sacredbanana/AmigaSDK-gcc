#ifndef LIBRARIES_LUA_H
#define LIBRARIES_LUA_H

/*
  lua.library include
  For MorphOS adaptation copyright © 2010-2015 Grzegorz Kraszewski.
  For Lua programming language itself see below.
*/

/******************************************************************************
* Copyright (C) 1994-2008 Lua.org, PUC-Rio.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#define LUA_VERSION       "Lua 5.1"
#define LUA_RELEASE       "Lua 5.1.4"
#define LUA_VERSION_NUM   501
#define LUA_COPYRIGHT     "Copyright © 1994-2008 Lua.org, PUC-Rio"
#define LUA_AUTHORS       "R. Ierusalimschy, L. H. de Figueiredo & W. Celes"
#define LUA_SIGNATURE     "\033Lua"

/*
** pseudo-indices
*/

#define LUA_REGISTRYINDEX   (-10000)
#define LUA_ENVIRONINDEX    (-10001)
#define LUA_GLOBALSINDEX    (-10002)
#define LUA_UPVALUEINDEX(i) (LUA_GLOBALSINDEX-(i))
#define LUA_MULTRET         (-1)

/*
** thread status; 0 is OK
*/

#define LUA_YIELD      1
#define LUA_ERRRUN     2
#define LUA_ERRSYNTAX  3
#define LUA_ERRMEM     4
#define LUA_ERRERR     5

/*
** some types used in API
*/

typedef struct lua_State LuaState;
typedef LONG (*LuaCFunction)(LuaState*);
typedef const char* (*LuaReader)(LuaState*, APTR, LONG*);
typedef int (*LuaWriter)(LuaState*, const APTR, LONG, APTR);
typedef APTR (*LuaAlloc)(APTR, APTR, LONG, LONG);

#define LUA_READER_MEMORY   (LuaReader)(-1)
#define LUA_READER_FILE     (LuaReader)(-2)
#define LUA_WRITER_MEMORY   (LuaWriter)(-1)
#define LUA_WRITER_FILE     (LuaWriter)(-2)

/* Used when loading and saving Lua code to memory. */

struct LuaMemoryData
{
	const char  *Buffer;
	LONG         Length;
};


/*
** basic Lua types
*/

#define LUA_TNONE           (-1)

#define LUA_TNIL              0
#define LUA_TBOOLEAN          1
#define LUA_TLIGHTUSERDATA    2
#define LUA_TNUMBER           3
#define LUA_TSTRING           4
#define LUA_TTABLE            5
#define LUA_TFUNCTION         6
#define LUA_TUSERDATA         7
#define LUA_TTHREAD           8

/*
** minimum Lua stack available to a C function
*/

#define LUA_MINSTACK 20

/*
** macros
*/

#define LuaPop(L, n) LuaSetTop(L, -(n)-1)
#define LuaNewTable(L) LuaCreateTable(L, 0, 0)
#define LuaRegister(L, n, f) (LuaPushCFunction(L, (f)), LuaSetGlobal(L, (n)))
#define LuaPushCFunction(L, f) LuaPushCClosure(L, (f), 0)
#define LuaStrLen(L, i) LuaObjLen(L, (i))
#define LuaIsFunction(L, n) (LuaType(L, (n)) == LUA_TFUNCTION)
#define LuaIsTable(L, n) (LuaType(L, (n)) == LUA_TTABLE)
#define LuaIsLightUserData(L, n) (LuaType(L, (n)) == LUA_TLIGHTUSERDATA)
#define LuaIsNil(L, n) (LuaType(L, (n)) == LUA_TNIL)
#define LuaIsBoolean(L, n) (LuaType(L, (n)) == LUA_TBOOLEAN)
#define LuaIsThread(L, n) (LuaType(L, (n)) == LUA_TTHREAD)
#define LuaIsNone(L, n) (LuaType(L, (n)) == LUA_TNONE)
#define LuaIsNoneOrNil(L, n) (LuaType(L, (n)) <= 0)
#define LuaPushLiteral(L, s) (LuaPushLString(L, "" s, (sizeof(s) / sizeof(char)) - 1))
#define LuaSetGlobal(L, s) (LuaSetField(L, LUA_GLOBALSINDEX, (s)))
#define LuaGetGlobal(L, s) (LuaGetField(L, LUA_GLOBALSINDEX, (s)))
#define LuaToString(L, i) (LuaToLString(L, (i), NULL))
#define LuaCheckString(L, n) (LuaCheckLString(L, (n), NULL))
#define LuaOptString(L, n, d) (LuaOptLString(L, (n), (d), NULL))
#define LuaOpt(L, f, n, d) (LuaIsNoneOrNil(L, (n)) ? (d) : f(L, (n)))

#define LuaArgCheck(L, cond, numarg, extramsg) ((void)((cond) || LuaArgError(L, (numarg), (extramsg))))

#define LUA_IDSIZE 80

struct LuaDebug {
  LONG event;
  const char *name;      /* (n) */
  const char *namewhat;  /* (n) `global', `local', `field', `method' */
  const char *what;      /* (S) `Lua', `C', `main', `tail' */
  const char *source;    /* (S) */
  LONG currentline;      /* (l) */
  LONG nups;             /* (u) number of upvalues */
  LONG linedefined;      /* (S) */
  LONG lastlinedefined;  /* (S) */
  char short_src[LUA_IDSIZE]; /* (S) */
  /* private part */
  LONG i_ci;  /* active function */
};

typedef void (*LuaHook)(LuaState*, struct LuaDebug*);

/* Debug hook event mask constants. */

#define LUA_HOOKCALL    0
#define LUA_HOOKRET     1
#define LUA_HOOKLINE    2
#define LUA_HOOKCOUNT   3
#define LUA_HOOKTAILRET 4

#define LUA_MASKCALL    (1 << LUA_HOOKCALL)
#define LUA_MASKRET     (1 << LUA_HOOKRET)
#define LUA_MASKLINE    (1 << LUA_HOOKLINE)
#define LUA_MASKCOUNT   (1 << LUA_HOOKCOUNT)


/* definitions for creating compiled modules (shared libs). */

typedef struct LuaLibReg
{
	const char   *name;
	LuaCFunction  func;
} LuaLibReg;


/* macros used in error reporting, define way of quoting */
/* names of variables.                                   */

#define LUA_QL(x)         "'" x "'"
#define LUA_QS            LUA_QL("%s")


/* garbage collector operations */

#define LUA_GCSTOP          0
#define LUA_GCRESTART       1
#define LUA_GCCOLLECT       2
#define LUA_GCCOUNT         3
#define LUA_GCCOUNTB        4
#define LUA_GCSTEP          5
#define LUA_GCSETPAUSE      6
#define LUA_GCSETSTEPMUL    7


#endif /* LIBRARIES_LUA_H */
