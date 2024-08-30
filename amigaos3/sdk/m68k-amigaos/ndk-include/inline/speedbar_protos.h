/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_SPEEDBAR_H
#define _INLINE_SPEEDBAR_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __SPEEDBAR_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define SPEEDBAR_GetClass() __SPEEDBAR_GetClass(SpeedBarBase)

struct Node * __AllocSpeedButtonNodeA(__reg("a6") struct Library * , __reg("d0") ULONG number , __reg("a0") struct TagItem * tags ) = "\tjsr\t-36(a6)";
#define AllocSpeedButtonNodeA(number, tags) __AllocSpeedButtonNodeA(SpeedBarBase, (number), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct Node * __AllocSpeedButtonNode(__reg("a6") struct Library * , __reg("d0") ULONG number , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-36(a6)\n\tmovea.l\t(a7)+,a0";
#define AllocSpeedButtonNode(number, ...) __AllocSpeedButtonNode(SpeedBarBase, (number), __VA_ARGS__)
#endif

VOID __FreeSpeedButtonNode(__reg("a6") struct Library * , __reg("a0") struct Node * node ) = "\tjsr\t-42(a6)";
#define FreeSpeedButtonNode(node) __FreeSpeedButtonNode(SpeedBarBase, (node))

VOID __SetSpeedButtonNodeAttrsA(__reg("a6") struct Library * , __reg("a0") struct Node * node , __reg("a1") struct TagItem * tags ) = "\tjsr\t-48(a6)";
#define SetSpeedButtonNodeAttrsA(node, tags) __SetSpeedButtonNodeAttrsA(SpeedBarBase, (node), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __SetSpeedButtonNodeAttrs(__reg("a6") struct Library * , __reg("a0") struct Node * node , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a1";
#define SetSpeedButtonNodeAttrs(node, ...) __SetSpeedButtonNodeAttrs(SpeedBarBase, (node), __VA_ARGS__)
#endif

VOID __GetSpeedButtonNodeAttrsA(__reg("a6") struct Library * , __reg("a0") struct Node * node , __reg("a1") struct TagItem * tags ) = "\tjsr\t-54(a6)";
#define GetSpeedButtonNodeAttrsA(node, tags) __GetSpeedButtonNodeAttrsA(SpeedBarBase, (node), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __GetSpeedButtonNodeAttrs(__reg("a6") struct Library * , __reg("a0") struct Node * node , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-54(a6)\n\tmovea.l\t(a7)+,a1";
#define GetSpeedButtonNodeAttrs(node, ...) __GetSpeedButtonNodeAttrs(SpeedBarBase, (node), __VA_ARGS__)
#endif

#endif /* !_INLINE_SPEEDBAR_H */
