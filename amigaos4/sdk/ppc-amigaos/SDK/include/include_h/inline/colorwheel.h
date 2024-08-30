#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_COLORWHEEL_H
#define _INLINE_COLORWHEEL_H

#ifndef CLIB_COLORWHEEL_PROTOS_H
#define CLIB_COLORWHEEL_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  GADGETS_COLORWHEEL_H
#include <gadgets/colorwheel.h>
#endif

#ifndef COLORWHEEL_BASE_NAME
#define COLORWHEEL_BASE_NAME ColorWheelBase
#endif

#define ConvertHSBToRGB(hsb, rgb) ({ \
  struct ColorWheelHSB * _ConvertHSBToRGB_hsb = (hsb); \
  struct ColorWheelRGB * _ConvertHSBToRGB_rgb = (rgb); \
  { \
  register struct Library * const __ConvertHSBToRGB__bn __asm("a6") = (struct Library *) (COLORWHEEL_BASE_NAME);\
  register struct ColorWheelHSB * __ConvertHSBToRGB_hsb __asm("a0") = (_ConvertHSBToRGB_hsb); \
  register struct ColorWheelRGB * __ConvertHSBToRGB_rgb __asm("a1") = (_ConvertHSBToRGB_rgb); \
  __asm volatile ("jsr a6@(-30:W)" \
  : \
  : "r"(__ConvertHSBToRGB__bn), "r"(__ConvertHSBToRGB_hsb), "r"(__ConvertHSBToRGB_rgb) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ConvertRGBToHSB(rgb, hsb) ({ \
  struct ColorWheelRGB * _ConvertRGBToHSB_rgb = (rgb); \
  struct ColorWheelHSB * _ConvertRGBToHSB_hsb = (hsb); \
  { \
  register struct Library * const __ConvertRGBToHSB__bn __asm("a6") = (struct Library *) (COLORWHEEL_BASE_NAME);\
  register struct ColorWheelRGB * __ConvertRGBToHSB_rgb __asm("a0") = (_ConvertRGBToHSB_rgb); \
  register struct ColorWheelHSB * __ConvertRGBToHSB_hsb __asm("a1") = (_ConvertRGBToHSB_hsb); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__ConvertRGBToHSB__bn), "r"(__ConvertRGBToHSB_rgb), "r"(__ConvertRGBToHSB_hsb) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_COLORWHEEL_H  */
