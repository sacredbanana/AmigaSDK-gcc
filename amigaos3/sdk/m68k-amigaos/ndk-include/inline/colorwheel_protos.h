/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_COLORWHEEL_H
#define _INLINE_COLORWHEEL_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __ConvertHSBToRGB(__reg("a6") struct Library * , __reg("a0") CONST struct ColorWheelHSB * hsb , __reg("a1") struct ColorWheelRGB * rgb ) = "\tjsr\t-30(a6)";
#define ConvertHSBToRGB(hsb, rgb) __ConvertHSBToRGB(ColorWheelBase, (hsb), (rgb))

VOID __ConvertRGBToHSB(__reg("a6") struct Library * , __reg("a0") CONST struct ColorWheelRGB * rgb , __reg("a1") struct ColorWheelHSB * hsb ) = "\tjsr\t-36(a6)";
#define ConvertRGBToHSB(rgb, hsb) __ConvertRGBToHSB(ColorWheelBase, (rgb), (hsb))

#endif /* !_INLINE_COLORWHEEL_H */
