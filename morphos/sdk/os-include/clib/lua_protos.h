#ifndef CLIB_LUA_PROTOS_H
#define CLIB_LUA_PROTOS_H

/*
	lua.library C prototypes

	Copyright © 2010-2011 Grzegorz Kraszewski
*/

#ifndef LIBRARIES_LUA_H
#include <libraries/lua.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

LuaState* LuaNewState(LuaAlloc, APTR);
void LuaClose(LuaState*);
LuaState* LuaNewThread(LuaState*);
LuaCFunction LuaAtPanic(LuaState*, LuaCFunction);
LONG LuaGetTop(LuaState*);
void LuaSetTop(LuaState*, LONG);
void LuaPushValue(LuaState*, LONG);
void LuaRemove(LuaState*, LONG);
void LuaInsert(LuaState*, LONG);
void LuaReplace(LuaState*, LONG);
LONG LuaCheckStack(LuaState*, LONG);
void LuaXMove(LuaState*, LuaState*, LONG);
LONG LuaIsNumber(LuaState*, LONG);
LONG LuaIsString(LuaState*, LONG);
LONG LuaIsCFunction(LuaState*, LONG);
LONG LuaIsUserData(LuaState*, LONG);
LONG LuaType(LuaState*, LONG);
const char* LuaTypeName(LuaState*, LONG);
LONG LuaEqual(LuaState*, LONG, LONG);
LONG LuaRawEqual(LuaState*, LONG, LONG);
LONG LuaLessThan(LuaState*, LONG, LONG);
double LuaToNumber(LuaState*, LONG);
LONG LuaToInteger(LuaState*, LONG);
LONG LuaToBoolean(LuaState*, LONG);
const char* LuaToLString(LuaState*, LONG, LONG*);
LONG LuaObjLen(LuaState*, LONG);
LuaCFunction LuaToCFunction(LuaState*, LONG);
APTR LuaToUserData(LuaState*, LONG);
LuaState* LuaToThread(LuaState*, LONG);
CONST_APTR LuaToPointer(LuaState*, LONG);
void LuaPushNil(LuaState*);
void LuaPushNumber(LuaState*, double);
void LuaPushInteger(LuaState*, LONG);
void LuaPushLString(LuaState*, const char*, LONG);
void LuaPushString(LuaState*, const char*);
const char* LuaPushFString(LuaState*, const char*, ...);
void LuaPushCClosure(LuaState*, LuaCFunction, LONG);
void LuaPushBoolean(LuaState*, LONG);
void LuaPushLightUserData(LuaState*, APTR);
LONG LuaPushThread(LuaState*);
void LuaGetTable(LuaState*, LONG);
void LuaGetField(LuaState*, LONG, const char*);
void LuaRawGet(LuaState*, LONG);
void LuaRawGetI(LuaState*, LONG, LONG);
void LuaCreateTable(LuaState*, LONG, LONG);
APTR LuaNewUserData(LuaState*, LONG);
LONG LuaGetMetaTable(LuaState*, LONG);
void LuaGetFEnv(LuaState*, LONG);
void LuaSetTable(LuaState*, LONG);
void LuaSetField(LuaState*, LONG, const char*);
void LuaRawSet(LuaState*, LONG);
void LuaRawSetI(LuaState*, LONG, LONG);
LONG LuaSetMetaTable(LuaState*, LONG);
LONG LuaSetFEnv(LuaState*, LONG);
void LuaCall(LuaState*, LONG, LONG);
LONG LuaPCall(LuaState*, LONG, LONG, LONG);
LONG LuaCPCall(LuaState*, LuaCFunction, APTR);
LONG LuaLoad(LuaState*, LuaReader, APTR, const char*);
LONG LuaDump(LuaState*, LuaWriter, APTR);
LONG LuaYield(LuaState*, LONG);
LONG LuaResume(LuaState*, LONG);
LONG LuaStatus(LuaState*);
LONG LuaGC(LuaState*, LONG, LONG);
LONG LuaError(LuaState*);
LONG LuaNext(LuaState*, LONG);
void LuaConcat(LuaState*, LONG);
LuaAlloc LuaGetAllocF(LuaState*, APTR*);
void LuaSetAllocF(LuaState*, LuaAlloc, APTR);
LONG LuaGetStack(LuaState*, LONG, struct LuaDebug*);
LONG LuaGetInfo(LuaState*, const char*, struct LuaDebug*);
const char* LuaGetLocal(LuaState*, const struct LuaDebug*, LONG);
const char* LuaSetLocal(LuaState*, const struct LuaDebug*, LONG);
const char* LuaGetUpValue(LuaState*, LONG, LONG);
const char* LuaSetUpValue(LuaState*, LONG, LONG);
LONG LuaSetHook(LuaState*, LuaHook, LONG, LONG);
LuaHook LuaGetHook(LuaState*);
LONG LuaGetHookMask(LuaState*);
LONG LuaGetHookCount(LuaState*);
void LuaRegisterModule(LuaState*, const char*, const LuaLibReg*);
double LuaCheckNumber(LuaState*, LONG);
const char* LuaCheckLString(LuaState*, LONG, LONG*);
LONG LuaCheckInteger(LuaState*, LONG);
LONG LuaOptInteger(LuaState*, LONG, LONG);
void LuaErrorF(LuaState*, const char*, ...);
void LuaCheckAny(LuaState*, LONG);
BOOL LuaCallMeta(LuaState*, LONG, const char*);
void LuaWhere(LuaState*, LONG);
void LuaCheckType(LuaState*, LONG, LONG);
const char* LuaOptLString(LuaState*, LONG, const char*, LONG*);
LONG LuaArgError(LuaState*, LONG, const char*);
BOOL LuaGetMetaField(LuaState*, LONG, const char*);
LONG LuaCheckOption(LuaState*, LONG, const char*, const char**);
APTR LuaCheckUData(LuaState*, LONG, const char*);
BOOL LuaNewMetaTable(LuaState*, const char*);
void LuaSetLevel(LuaState*, LuaState*);
void LuaOpenLibs(LuaState *state);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* No va_args stuff in C++. */

#ifndef __cplusplus
const char* LuaPushVFString(LuaState*, const char*, va_list);
#endif

#endif /* CLIB_LUA_PROTOS_H */
