#ifndef INLINE4_AMIGAGUIDE_H
#define INLINE4_AMIGAGUIDE_H

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

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef LIBRARIES_AMIGAGUIDE_H
#include <libraries/amigaguide.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef REXX_STORAGE_H
#include <rexx/storage.h>
#endif

/* Inline macros for Interface "main" */
#define LockAmigaGuideBase(handle) IAmigaGuide->LockAmigaGuideBase(handle) 
#define UnlockAmigaGuideBase(key) IAmigaGuide->UnlockAmigaGuideBase(key) 
#define OpenAmigaGuideA(nag, tags) IAmigaGuide->OpenAmigaGuideA(nag, tags) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define OpenAmigaGuide(...) IAmigaGuide->OpenAmigaGuide(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define OpenAmigaGuide(vargs...) IAmigaGuide->OpenAmigaGuide(## vargs) 
#endif
#define OpenAmigaGuideAsyncA(nag, attrs) IAmigaGuide->OpenAmigaGuideAsyncA(nag, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define OpenAmigaGuideAsync(...) IAmigaGuide->OpenAmigaGuideAsync(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define OpenAmigaGuideAsync(vargs...) IAmigaGuide->OpenAmigaGuideAsync(## vargs) 
#endif
#define CloseAmigaGuide(cl) IAmigaGuide->CloseAmigaGuide(cl) 
#define AmigaGuideSignal(cl) IAmigaGuide->AmigaGuideSignal(cl) 
#define GetAmigaGuideMsg(cl) IAmigaGuide->GetAmigaGuideMsg(cl) 
#define ReplyAmigaGuideMsg(amsg) IAmigaGuide->ReplyAmigaGuideMsg(amsg) 
#define SetAmigaGuideContextA(cl, id, attrs) IAmigaGuide->SetAmigaGuideContextA(cl, id, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define SetAmigaGuideContext(cl, ...) IAmigaGuide->SetAmigaGuideContext(cl, __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define SetAmigaGuideContext(cl, vargs...) IAmigaGuide->SetAmigaGuideContext(cl, ## vargs) 
#endif
#define SendAmigaGuideContextA(cl, attrs) IAmigaGuide->SendAmigaGuideContextA(cl, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define SendAmigaGuideContext(...) IAmigaGuide->SendAmigaGuideContext(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define SendAmigaGuideContext(vargs...) IAmigaGuide->SendAmigaGuideContext(## vargs) 
#endif
#define SendAmigaGuideCmdA(cl, cmd, attrs) IAmigaGuide->SendAmigaGuideCmdA(cl, cmd, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define SendAmigaGuideCmd(cl, ...) IAmigaGuide->SendAmigaGuideCmd(cl, __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define SendAmigaGuideCmd(cl, vargs...) IAmigaGuide->SendAmigaGuideCmd(cl, ## vargs) 
#endif
#define SetAmigaGuideAttrsA(cl, attrs) IAmigaGuide->SetAmigaGuideAttrsA(cl, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define SetAmigaGuideAttrs(...) IAmigaGuide->SetAmigaGuideAttrs(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define SetAmigaGuideAttrs(vargs...) IAmigaGuide->SetAmigaGuideAttrs(## vargs) 
#endif
#define GetAmigaGuideAttr(tag, cl, storage) IAmigaGuide->GetAmigaGuideAttr(tag, cl, storage) 
#define LoadXRef(lock, name) IAmigaGuide->LoadXRef(lock, name) 
#define ExpungeXRef() IAmigaGuide->ExpungeXRef() 
#define AddAmigaGuideHostA(h, name, attrs) IAmigaGuide->AddAmigaGuideHostA(h, name, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define AddAmigaGuideHost(h, ...) IAmigaGuide->AddAmigaGuideHost(h, __VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define AddAmigaGuideHost(h, vargs...) IAmigaGuide->AddAmigaGuideHost(h, ## vargs) 
#endif
#define RemoveAmigaGuideHostA(hh, attrs) IAmigaGuide->RemoveAmigaGuideHostA(hh, attrs) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define RemoveAmigaGuideHost(...) IAmigaGuide->RemoveAmigaGuideHost(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define RemoveAmigaGuideHost(vargs...) IAmigaGuide->RemoveAmigaGuideHost(## vargs) 
#endif
#define GetAmigaGuideString(id) IAmigaGuide->GetAmigaGuideString(id) 

#endif /* INLINE4_AMIGAGUIDE_H */
