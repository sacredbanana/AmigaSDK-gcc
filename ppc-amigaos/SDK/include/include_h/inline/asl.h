#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_ASL_H
#define _INLINE_ASL_H

#ifndef CLIB_ASL_PROTOS_H
#define CLIB_ASL_PROTOS_H
#endif

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  LIBRARIES_ASL_H
#include <libraries/asl.h>
#endif

#ifndef ASL_BASE_NAME
#define ASL_BASE_NAME AslBase
#endif

#define AllocFileRequest() ({ \
  struct FileRequester * _AllocFileRequest__re = \
  ({ \
  register struct Library * const __AllocFileRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register struct FileRequester * __AllocFileRequest__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__AllocFileRequest__re) \
  : "r"(__AllocFileRequest__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocFileRequest__re; \
  }); \
  _AllocFileRequest__re; \
})

#define FreeFileRequest(fileReq) ({ \
  struct FileRequester * _FreeFileRequest_fileReq = (fileReq); \
  { \
  register struct Library * const __FreeFileRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register struct FileRequester * __FreeFileRequest_fileReq __asm("a0") = (_FreeFileRequest_fileReq); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__FreeFileRequest__bn), "r"(__FreeFileRequest_fileReq) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RequestFile(fileReq) ({ \
  struct FileRequester * _RequestFile_fileReq = (fileReq); \
  BOOL _RequestFile__re = \
  ({ \
  register struct Library * const __RequestFile__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register BOOL __RequestFile__re __asm("d0"); \
  register struct FileRequester * __RequestFile_fileReq __asm("a0") = (_RequestFile_fileReq); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__RequestFile__re) \
  : "r"(__RequestFile__bn), "r"(__RequestFile_fileReq) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RequestFile__re; \
  }); \
  _RequestFile__re; \
})

#define AllocAslRequest(reqType, tagList) ({ \
  ULONG _AllocAslRequest_reqType = (reqType); \
  struct TagItem * _AllocAslRequest_tagList = (tagList); \
  APTR _AllocAslRequest__re = \
  ({ \
  register struct Library * const __AllocAslRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register APTR __AllocAslRequest__re __asm("d0"); \
  register ULONG __AllocAslRequest_reqType __asm("d0") = (_AllocAslRequest_reqType); \
  register struct TagItem * __AllocAslRequest_tagList __asm("a0") = (_AllocAslRequest_tagList); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__AllocAslRequest__re) \
  : "r"(__AllocAslRequest__bn), "r"(__AllocAslRequest_reqType), "r"(__AllocAslRequest_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocAslRequest__re; \
  }); \
  _AllocAslRequest__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___AllocAslRequestTags(struct Library * AslBase, ULONG reqType, Tag tagList, ...)
{
  return AllocAslRequest(reqType, (struct TagItem *) &tagList);
}

#define AllocAslRequestTags(reqType...) ___AllocAslRequestTags(ASL_BASE_NAME, reqType)
#endif

#define FreeAslRequest(requester) ({ \
  APTR _FreeAslRequest_requester = (requester); \
  { \
  register struct Library * const __FreeAslRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register APTR __FreeAslRequest_requester __asm("a0") = (_FreeAslRequest_requester); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__FreeAslRequest__bn), "r"(__FreeAslRequest_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AslRequest(requester, tagList) ({ \
  APTR _AslRequest_requester = (requester); \
  struct TagItem * _AslRequest_tagList = (tagList); \
  BOOL _AslRequest__re = \
  ({ \
  register struct Library * const __AslRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register BOOL __AslRequest__re __asm("d0"); \
  register APTR __AslRequest_requester __asm("a0") = (_AslRequest_requester); \
  register struct TagItem * __AslRequest_tagList __asm("a1") = (_AslRequest_tagList); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__AslRequest__re) \
  : "r"(__AslRequest__bn), "r"(__AslRequest_requester), "r"(__AslRequest_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AslRequest__re; \
  }); \
  _AslRequest__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___AslRequestTags(struct Library * AslBase, APTR requester, Tag tagList, ...)
{
  return AslRequest(requester, (struct TagItem *) &tagList);
}

#define AslRequestTags(requester...) ___AslRequestTags(ASL_BASE_NAME, requester)
#endif

#define AbortAslRequest(requester) ({ \
  APTR _AbortAslRequest_requester = (requester); \
  { \
  register struct Library * const __AbortAslRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register APTR __AbortAslRequest_requester __asm("a0") = (_AbortAslRequest_requester); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__AbortAslRequest__bn), "r"(__AbortAslRequest_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ActivateAslRequest(requester) ({ \
  APTR _ActivateAslRequest_requester = (requester); \
  { \
  register struct Library * const __ActivateAslRequest__bn __asm("a6") = (struct Library *) (ASL_BASE_NAME);\
  register APTR __ActivateAslRequest_requester __asm("a0") = (_ActivateAslRequest_requester); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__ActivateAslRequest__bn), "r"(__ActivateAslRequest_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_ASL_H  */
