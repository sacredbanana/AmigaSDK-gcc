/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CHOOSER_H
#define _INLINE_CHOOSER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __CHOOSER_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define CHOOSER_GetClass() __CHOOSER_GetClass(ChooserBase)

struct Node * __AllocChooserNodeA(__reg("a6") struct Library * , __reg("a0") struct TagItem * tags ) = "\tjsr\t-36(a6)";
#define AllocChooserNodeA(tags) __AllocChooserNodeA(ChooserBase, (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct Node * __AllocChooserNode(__reg("a6") struct Library * , Tag firstTag , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-36(a6)\n\tmovea.l\t(a7)+,a0";
#define AllocChooserNode(...) __AllocChooserNode(ChooserBase, __VA_ARGS__)
#endif

VOID __FreeChooserNode(__reg("a6") struct Library * , __reg("a0") struct Node * node ) = "\tjsr\t-42(a6)";
#define FreeChooserNode(node) __FreeChooserNode(ChooserBase, (node))

VOID __SetChooserNodeAttrsA(__reg("a6") struct Library * , __reg("a0") struct Node * node , __reg("a1") struct TagItem * tags ) = "\tjsr\t-48(a6)";
#define SetChooserNodeAttrsA(node, tags) __SetChooserNodeAttrsA(ChooserBase, (node), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __SetChooserNodeAttrs(__reg("a6") struct Library * , __reg("a0") struct Node * node , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a1";
#define SetChooserNodeAttrs(node, ...) __SetChooserNodeAttrs(ChooserBase, (node), __VA_ARGS__)
#endif

VOID __GetChooserNodeAttrsA(__reg("a6") struct Library * , __reg("a0") struct Node * node , __reg("a1") struct TagItem * tags ) = "\tjsr\t-54(a6)";
#define GetChooserNodeAttrsA(node, tags) __GetChooserNodeAttrsA(ChooserBase, (node), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
VOID __GetChooserNodeAttrs(__reg("a6") struct Library * , __reg("a0") struct Node * node , Tag _tag1 , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-54(a6)\n\tmovea.l\t(a7)+,a1";
#define GetChooserNodeAttrs(node, ...) __GetChooserNodeAttrs(ChooserBase, (node), __VA_ARGS__)
#endif

ULONG __ShowChooser(__reg("a6") struct Library * , __reg("a0") Object * o , __reg("a1") struct Window * w , __reg("d0") ULONG xpos , __reg("d1") ULONG ypos ) = "\tjsr\t-60(a6)";
#define ShowChooser(o, w, xpos, ypos) __ShowChooser(ChooserBase, (o), (w), (xpos), (ypos))

VOID __HideChooser(__reg("a6") struct Library * , __reg("a0") Object * o , __reg("a1") struct Window * w ) = "\tjsr\t-66(a6)";
#define HideChooser(o, w) __HideChooser(ChooserBase, (o), (w))

#endif /* !_INLINE_CHOOSER_H */
