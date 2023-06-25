#ifndef INLINE4_ASL_H
#define INLINE4_ASL_H

/*
** This file was auto generated by idltool 52.7.
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
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_ASL_H
#include <libraries/asl.h>
#endif
#include <interfaces/asl.h>

/* Inline macros for Interface "main" */
#define OBSOLETE_AllocFileRequest() IAsl->OBSOLETE_AllocFileRequest() 
#define OBSOLETE_FreeFileRequest(fileReq) IAsl->OBSOLETE_FreeFileRequest((fileReq)) 
#define OBSOLETE_RequestFile(fileReq) IAsl->OBSOLETE_RequestFile((fileReq)) 
#define AllocAslRequest(reqType, tagList) IAsl->AllocAslRequest((reqType), (tagList)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define AllocAslRequestTags(...) IAsl->AllocAslRequestTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define AllocAslRequestTags(vargs...) IAsl->AllocAslRequestTags(## vargs) 
#endif
#define FreeAslRequest(requester) IAsl->FreeAslRequest((requester)) 
#define AslRequest(requester, tagList) IAsl->AslRequest((requester), (tagList)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define AslRequestTags(...) IAsl->AslRequestTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define AslRequestTags(vargs...) IAsl->AslRequestTags(## vargs) 
#endif
#define AslFreeVec(memory) IAsl->AslFreeVec((memory)) 
#define AslAllocVec(byteSize, attributes) IAsl->AslAllocVec((byteSize), (attributes)) 
#define AbortAslRequest(requester) IAsl->AbortAslRequest((requester)) 
#define ActivateAslRequest(requester) IAsl->ActivateAslRequest((requester)) 
#define AslControl(tags) IAsl->AslControl((tags)) 
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (__GNUC__ >= 3)
#define AslControlTags(...) IAsl->AslControlTags(__VA_ARGS__) 
#elif (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define AslControlTags(...) IAsl->AslControlTags(## vargs) 
#endif

#endif /* INLINE4_ASL_H */
