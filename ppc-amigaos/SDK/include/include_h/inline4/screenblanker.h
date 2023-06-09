#ifndef INLINE4_SCREENBLANKER_H
#define INLINE4_SCREENBLANKER_H

/*
** This file was auto generated by idltool 53.16.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef PROTO_BLANKERMODULE_H
#include <proto/blankermodule.h>
#endif
#include <interfaces/screenblanker.h>

/* Inline macros for Interface "main" */
#define OpenBlankerModuleA(name, tags) IScreenBlanker->OpenBlankerModuleA((name), (tags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define OpenBlankerModule(...) IScreenBlanker->OpenBlankerModule(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define OpenBlankerModule(vargs...) IScreenBlanker->OpenBlankerModule(## vargs) 
#endif
#define CloseBlankerModule() IScreenBlanker->CloseBlankerModule() 
#define SetBlankingMode(mode) IScreenBlanker->SetBlankingMode((mode)) 
#define SetScreenBlankerAttrsA(tags) IScreenBlanker->SetScreenBlankerAttrsA((tags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define SetScreenBlankerAttrs(...) IScreenBlanker->SetScreenBlankerAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define SetScreenBlankerAttrs(...) IScreenBlanker->SetScreenBlankerAttrs(## vargs) 
#endif
#define GetScreenBlankerAttrsA(tags) IScreenBlanker->GetScreenBlankerAttrsA((tags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define GetScreenBlankerAttrs(...) IScreenBlanker->GetScreenBlankerAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define GetScreenBlankerAttrs(...) IScreenBlanker->GetScreenBlankerAttrs(## vargs) 
#endif
#define LogPuts(err, context, msg) IScreenBlanker->LogPuts((err), (context), (msg)) 
#define LogFmtA(err, context, msg, args) IScreenBlanker->LogFmtA((err), (context), (msg), (args)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define LogFmt(err, context, ...) IScreenBlanker->LogFmt((err), (context), __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define LogFmt(err, context, vargs...) IScreenBlanker->LogFmt(err, context, ## vargs) 
#endif

#endif /* INLINE4_SCREENBLANKER_H */
