/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_RADIOBUTTON_H
#define _INLINE_RADIOBUTTON_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __RADIOBUTTON_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define RADIOBUTTON_GetClass() __RADIOBUTTON_GetClass(RadioButtonBase)

struct Node * __AllocRadioButtonNodeA(__reg("a6") struct Library * , __reg("d0") ULONG columns , __reg("a0") struct TagItem * tags ) = "\tjsr\t-36(a6)";
#define AllocRadioButtonNodeA(columns, tags) __AllocRadioButtonNodeA(RadioButtonBase, (columns), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct Node * __AllocRadioButtonNode(__reg("a6") struct Library * , __reg("d0") ULONG columns , Tag _tag1 , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-36(a6)\n\tmovea.l\t(a7)+,a0";
#define AllocRadioButtonNode(columns, ...) __AllocRadioButtonNode(RadioButtonBase, (columns), __VA_ARGS__)
#endif

VOID __FreeRadioButtonNode(__reg("a6") struct Library * , __reg("a0") struct Node * node ) = "\tjsr\t-42(a6)";
#define FreeRadioButtonNode(node) __FreeRadioButtonNode(RadioButtonBase, (node))

VOID __SetRadioButtonNodeAttrsA(__reg("a6") struct Library * , __reg("a0") struct Node * node , __reg("a1") struct TagItem * tags ) = "\tjsr\t-48(a6)";
#define SetRadioButtonNodeAttrsA(node, tags) __SetRadioButtonNodeAttrsA(RadioButtonBase, (node), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __SetRadioButtonNodeAttrs(__reg("a6") struct Library * , __reg("a0") struct Node * node , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a1";
#define SetRadioButtonNodeAttrs(node, ...) __SetRadioButtonNodeAttrs(RadioButtonBase, (node), __VA_ARGS__)
#endif

VOID __GetRadioButtonNodeAttrsA(__reg("a6") struct Library * , __reg("a0") struct Node * node , __reg("a1") struct TagItem * tags ) = "\tjsr\t-54(a6)";
#define GetRadioButtonNodeAttrsA(node, tags) __GetRadioButtonNodeAttrsA(RadioButtonBase, (node), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __GetRadioButtonNodeAttrs(__reg("a6") struct Library * , __reg("a0") struct Node * node , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-54(a6)\n\tmovea.l\t(a7)+,a1";
#define GetRadioButtonNodeAttrs(node, ...) __GetRadioButtonNodeAttrs(RadioButtonBase, (node), __VA_ARGS__)
#endif

#endif /* !_INLINE_RADIOBUTTON_H */
