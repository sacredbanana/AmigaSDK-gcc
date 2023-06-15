/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_TEXTEDITOR_H
#define _INLINE_TEXTEDITOR_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __TEXTEDITOR_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define TEXTEDITOR_GetClass() __TEXTEDITOR_GetClass(TextFieldBase)

VOID __HighlightSetFormat(__reg("a6") struct Library * , __reg("a0") APTR object , __reg("d0") ULONG pos , __reg("d1") ULONG end , __reg("d2") UWORD style ) = "\tjsr\t-36(a6)";
#define HighlightSetFormat(object, pos, end, style) __HighlightSetFormat(TextFieldBase, (object), (pos), (end), (style))

#endif /* !_INLINE_TEXTEDITOR_H */
