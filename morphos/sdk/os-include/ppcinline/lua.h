/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LUA_H
#define _PPCINLINE_LUA_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LUA_BASE_NAME
#define LUA_BASE_NAME LuaBase
#endif /* !LUA_BASE_NAME */

#define LuaNewUserData(__p0, __p1) \
	(((APTR (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 304))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaIsString(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 106))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaToInteger(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 160))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaPushString(__p0, __p1) \
	(((void (*)(void *, LuaState *, const char *))*(void**)((long)(LUA_BASE_NAME) - 232))((void*)(LUA_BASE_NAME), __p0, __p1))

#if !defined(__STRICT_ANSI__)
#define LuaPushFString(__p0, ...) \
	(((const char *(*)(void *, LuaState *, const char *, ...))*(void**)((long)(LUA_BASE_NAME) - 244))((void*)(LUA_BASE_NAME), __p0, __VA_ARGS__))
#endif

#define LuaArgError(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , const char *))*(void**)((long)(LUA_BASE_NAME) - 568))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetField(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , const char *))*(void**)((long)(LUA_BASE_NAME) - 280))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetInfo(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, const char *, struct LuaDebug *))*(void**)((long)(LUA_BASE_NAME) - 448))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaSetUpValue(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 472))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaTypeName(__p0, __p1) \
	(((const char *(*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 130))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaStatus(__p0) \
	(((LONG (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 400))((void*)(LUA_BASE_NAME), __p0))

#define LuaCPCall(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LuaCFunction , APTR ))*(void**)((long)(LUA_BASE_NAME) - 370))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaCall(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 358))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaCheckStack(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 88))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaCallMeta(__p0, __p1, __p2) \
	(((BOOL (*)(void *, LuaState *, LONG , const char *))*(void**)((long)(LUA_BASE_NAME) - 544))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaRemove(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 70))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaCheckNumber(__p0, __p1) \
	(((double (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 508))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaPushBoolean(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 256))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaToBoolean(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 166))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaResume(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 394))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaSetLocal(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, const struct LuaDebug *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 460))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaPushThread(__p0) \
	(((LONG (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 268))((void*)(LUA_BASE_NAME), __p0))

#define LuaSetTable(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 322))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaEqual(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 136))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaPushNil(__p0) \
	(((void (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 208))((void*)(LUA_BASE_NAME), __p0))

#define LuaGetMetaField(__p0, __p1, __p2) \
	(((BOOL (*)(void *, LuaState *, LONG , const char *))*(void**)((long)(LUA_BASE_NAME) - 574))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaSetField(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , const char *))*(void**)((long)(LUA_BASE_NAME) - 328))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetHookCount(__p0) \
	(((LONG (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 496))((void*)(LUA_BASE_NAME), __p0))

#define LuaGetUpValue(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 466))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaRegisterModule(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, const char *, const LuaLibReg *))*(void**)((long)(LUA_BASE_NAME) - 502))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaPushValue(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 64))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaCheckInteger(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 520))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaInsert(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 76))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaAtPanic(__p0, __p1) \
	(((LuaCFunction (*)(void *, LuaState *, LuaCFunction ))*(void**)((long)(LUA_BASE_NAME) - 46))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaRawGetI(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 292))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaCheckLString(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, LONG , LONG *))*(void**)((long)(LUA_BASE_NAME) - 514))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaToPointer(__p0, __p1) \
	(((CONST_APTR (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 202))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaRawSetI(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 340))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaLessThan(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 148))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetTable(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 274))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaGetLocal(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, const struct LuaDebug *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 454))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaNext(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 418))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaReplace(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 82))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaCheckUData(__p0, __p1, __p2) \
	(((APTR (*)(void *, LuaState *, LONG , const char *))*(void**)((long)(LUA_BASE_NAME) - 586))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetFEnv(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 316))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaPushVFString(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, const char *, va_list ))*(void**)((long)(LUA_BASE_NAME) - 238))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetTop(__p0) \
	(((LONG (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 52))((void*)(LUA_BASE_NAME), __p0))

#define LuaDump(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LuaWriter , APTR ))*(void**)((long)(LUA_BASE_NAME) - 382))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaType(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 124))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaSetMetaTable(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 346))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaClose(__p0) \
	(((void (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 34))((void*)(LUA_BASE_NAME), __p0))

#define LuaGetAllocF(__p0, __p1) \
	(((LuaAlloc (*)(void *, LuaState *, APTR *))*(void**)((long)(LUA_BASE_NAME) - 430))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaToNumber(__p0, __p1) \
	(((double (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 154))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaIsCFunction(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 112))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaNewThread(__p0) \
	(((LuaState *(*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 40))((void*)(LUA_BASE_NAME), __p0))

#define LuaCheckAny(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 538))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaToUserData(__p0, __p1) \
	(((APTR (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 190))((void*)(LUA_BASE_NAME), __p0, __p1))

#if !defined(__STRICT_ANSI__)
#define LuaErrorF(__p0, ...) \
	(((void (*)(void *, LuaState *, const char *, ...))*(void**)((long)(LUA_BASE_NAME) - 532))((void*)(LUA_BASE_NAME), __p0, __VA_ARGS__))
#endif

#define LuaToLString(__p0, __p1, __p2) \
	(((const char *(*)(void *, LuaState *, LONG , LONG *))*(void**)((long)(LUA_BASE_NAME) - 172))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaOpenLibs(__p0) \
	(((void (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 604))((void*)(LUA_BASE_NAME), __p0))

#define LuaSetLevel(__p0, __p1) \
	(((void (*)(void *, LuaState *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 598))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaCheckOption(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, LuaState *, LONG , const char *, const char **))*(void**)((long)(LUA_BASE_NAME) - 580))((void*)(LUA_BASE_NAME), __p0, __p1, __p2, __p3))

#define LuaPushNumber(__p0, __p1) \
	(((void (*)(void *, LuaState *, double ))*(void**)((long)(LUA_BASE_NAME) - 214))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaPushInteger(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 220))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaPushLString(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, const char *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 226))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaCreateTable(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 298))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetHook(__p0) \
	(((LuaHook (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 484))((void*)(LUA_BASE_NAME), __p0))

#define LuaCheckType(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 556))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaPCall(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, LuaState *, LONG , LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 364))((void*)(LUA_BASE_NAME), __p0, __p1, __p2, __p3))

#define LuaToCFunction(__p0, __p1) \
	(((LuaCFunction (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 184))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaConcat(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 424))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaRawGet(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 286))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaLoad(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, LuaState *, LuaReader , APTR , const char *))*(void**)((long)(LUA_BASE_NAME) - 376))((void*)(LUA_BASE_NAME), __p0, __p1, __p2, __p3))

#define LuaNewState(__p0, __p1) \
	(((LuaState *(*)(void *, LuaAlloc , APTR ))*(void**)((long)(LUA_BASE_NAME) - 28))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaIsNumber(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 100))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaSetFEnv(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 352))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaSetAllocF(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LuaAlloc , APTR ))*(void**)((long)(LUA_BASE_NAME) - 436))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaGetMetaTable(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 310))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaWhere(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 550))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaSetTop(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 58))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaXMove(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 94))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaPushCClosure(__p0, __p1, __p2) \
	(((void (*)(void *, LuaState *, LuaCFunction , LONG ))*(void**)((long)(LUA_BASE_NAME) - 250))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaRawSet(__p0, __p1) \
	(((void (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 334))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaOptLString(__p0, __p1, __p2, __p3) \
	(((const char *(*)(void *, LuaState *, LONG , const char *, LONG *))*(void**)((long)(LUA_BASE_NAME) - 562))((void*)(LUA_BASE_NAME), __p0, __p1, __p2, __p3))

#define LuaGetHookMask(__p0) \
	(((LONG (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 490))((void*)(LUA_BASE_NAME), __p0))

#define LuaYield(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 388))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaNewMetaTable(__p0, __p1) \
	(((BOOL (*)(void *, LuaState *, const char *))*(void**)((long)(LUA_BASE_NAME) - 592))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaPushLightUserData(__p0, __p1) \
	(((void (*)(void *, LuaState *, APTR ))*(void**)((long)(LUA_BASE_NAME) - 262))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaOptInteger(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 526))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaSetHook(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, LuaState *, LuaHook , LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 478))((void*)(LUA_BASE_NAME), __p0, __p1, __p2, __p3))

#define LuaGC(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 406))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaError(__p0) \
	(((LONG (*)(void *, LuaState *))*(void**)((long)(LUA_BASE_NAME) - 412))((void*)(LUA_BASE_NAME), __p0))

#define LuaIsUserData(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 118))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaObjLen(__p0, __p1) \
	(((LONG (*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 178))((void*)(LUA_BASE_NAME), __p0, __p1))

#define LuaGetStack(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , struct LuaDebug *))*(void**)((long)(LUA_BASE_NAME) - 442))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaRawEqual(__p0, __p1, __p2) \
	(((LONG (*)(void *, LuaState *, LONG , LONG ))*(void**)((long)(LUA_BASE_NAME) - 142))((void*)(LUA_BASE_NAME), __p0, __p1, __p2))

#define LuaToThread(__p0, __p1) \
	(((LuaState *(*)(void *, LuaState *, LONG ))*(void**)((long)(LUA_BASE_NAME) - 196))((void*)(LUA_BASE_NAME), __p0, __p1))

#endif /* !_PPCINLINE_LUA_H */
