#ifndef INLINE4_RESOURCE_H
#define INLINE4_RESOURCE_H

/*
** This file was auto generated by idltool 51.8.
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

#ifndef LIBRARIES_RESOURCE_H
#include <libraries/resource.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* Inline macros for Interface "main" */
#define RL_OpenResource(resource, screen, catalog) IResource->RL_OpenResource(resource, screen, catalog) 
#define RL_CloseResource(resfile) IResource->RL_CloseResource(resfile) 
#define RL_NewObjectA(resfile, resid, tags) IResource->RL_NewObjectA(resfile, resid, tags) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define RL_NewObject(resfile, ...) IResource->RL_NewObject(resfile, __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define RL_NewObject(resfile, vargs...) IResource->RL_NewObject(resfile, ## vargs) 
#endif
#define RL_DisposeObject(resfile, obj) IResource->RL_DisposeObject(resfile, obj) 
#define RL_NewGroupA(resfile, id, taglist) IResource->RL_NewGroupA(resfile, id, taglist) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define RL_NewGroup(resfile, ...) IResource->RL_NewGroup(resfile, __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define RL_NewGroup(resfile, vargs...) IResource->RL_NewGroup(resfile, ## vargs) 
#endif
#define RL_DisposeGroup(resfile, obj) IResource->RL_DisposeGroup(resfile, obj) 
#define RL_GetObjectArray(resfile, obj, id) IResource->RL_GetObjectArray(resfile, obj, id) 
#define RL_SetResourceScreen(resfile, screen) IResource->RL_SetResourceScreen(resfile, screen) 

#endif /* INLINE4_RESOURCE_H */
