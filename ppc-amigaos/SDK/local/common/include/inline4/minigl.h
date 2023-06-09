#ifndef INLINE4_MINIGL_H
#define INLINE4_MINIGL_H

/*
** This file was auto generated by idltool 51.6.
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

#ifndef GL_GLU_H
#include <GL/glu.h>
#endif

/* Inline macros for Interface "main" */
#define CreateContext(tagList) IMiniGL->CreateContext(tagList) 
#if !defined(__cplusplus) && (__GNUC__ >= 3    \
    || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95) \
    || (__STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#define CreateContextTags(...) IMiniGL->CreateContextTags(__VA_ARGS__) 
#endif
#define GetSupportedScreenModes(CallbackFn) IMiniGL->GetSupportedScreenModes(CallbackFn) 
#define ScreenModeIsSupported(width, height, depth) IMiniGL->ScreenModeIsSupported(width, height, depth) 

#endif /* INLINE4_MINIGL_H */
