#ifndef INLINE4_SPEEDBAR_H
#define INLINE4_SPEEDBAR_H

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

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

/* Inline macros for Interface "main" */
#define SPEEDBAR_GetClass() ISpeedBar->SPEEDBAR_GetClass() 
#define AllocSpeedButtonNodeA(number, tags) ISpeedBar->AllocSpeedButtonNodeA(number, tags) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define AllocSpeedButtonNode(...) ISpeedBar->AllocSpeedButtonNode(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define AllocSpeedButtonNode(vargs...) ISpeedBar->AllocSpeedButtonNode(## vargs) 
#endif
#define FreeSpeedButtonNode(node) ISpeedBar->FreeSpeedButtonNode(node) 
#define SetSpeedButtonNodeAttrsA(node, tags) ISpeedBar->SetSpeedButtonNodeAttrsA(node, tags) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define SetSpeedButtonNodeAttrs(...) ISpeedBar->SetSpeedButtonNodeAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define SetSpeedButtonNodeAttrs(vargs...) ISpeedBar->SetSpeedButtonNodeAttrs(## vargs) 
#endif
#define GetSpeedButtonNodeAttrsA(node, tags) ISpeedBar->GetSpeedButtonNodeAttrsA(node, tags) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define GetSpeedButtonNodeAttrs(...) ISpeedBar->GetSpeedButtonNodeAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define GetSpeedButtonNodeAttrs(vargs...) ISpeedBar->GetSpeedButtonNodeAttrs(## vargs) 
#endif

#endif /* INLINE4_SPEEDBAR_H */
