/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_ASL_H
#define _INLINE_ASL_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

struct FileRequester * __AllocFileRequest(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define AllocFileRequest() __AllocFileRequest(AslBase)

VOID __FreeFileRequest(__reg("a6") struct Library * , __reg("a0") struct FileRequester * fileReq ) = "\tjsr\t-36(a6)";
#define FreeFileRequest(fileReq) __FreeFileRequest(AslBase, (fileReq))

BOOL __RequestFile(__reg("a6") struct Library * , __reg("a0") struct FileRequester * fileReq ) = "\tjsr\t-42(a6)";
#define RequestFile(fileReq) __RequestFile(AslBase, (fileReq))

APTR __AllocAslRequest(__reg("a6") struct Library * , __reg("d0") ULONG reqType , __reg("a0") CONST struct TagItem * tagList ) = "\tjsr\t-48(a6)";
#define AllocAslRequest(reqType, tagList) __AllocAslRequest(AslBase, (reqType), (tagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __AllocAslRequestTags(__reg("a6") struct Library * , __reg("d0") ULONG reqType , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a0";
#define AllocAslRequestTags(reqType, ...) __AllocAslRequestTags(AslBase, (reqType), __VA_ARGS__)
#endif

VOID __FreeAslRequest(__reg("a6") struct Library * , __reg("a0") APTR requester ) = "\tjsr\t-54(a6)";
#define FreeAslRequest(requester) __FreeAslRequest(AslBase, (requester))

BOOL __AslRequest(__reg("a6") struct Library * , __reg("a0") APTR requester , __reg("a1") CONST struct TagItem * tagList ) = "\tjsr\t-60(a6)";
#define AslRequest(requester, tagList) __AslRequest(AslBase, (requester), (tagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __AslRequestTags(__reg("a6") struct Library * , __reg("a0") APTR requester , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-60(a6)\n\tmovea.l\t(a7)+,a1";
#define AslRequestTags(requester, ...) __AslRequestTags(AslBase, (requester), __VA_ARGS__)
#endif

VOID __AbortAslRequest(__reg("a6") struct Library * , __reg("a0") APTR requester ) = "\tjsr\t-78(a6)";
#define AbortAslRequest(requester) __AbortAslRequest(AslBase, (requester))

VOID __ActivateAslRequest(__reg("a6") struct Library * , __reg("a0") APTR requester ) = "\tjsr\t-84(a6)";
#define ActivateAslRequest(requester) __ActivateAslRequest(AslBase, (requester))

#endif /* !_INLINE_ASL_H */
