#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_SPECIALFX_H
#define _INLINE_SPECIALFX_H

#ifndef CLIB_SPECIALFX_PROTOS_H
#define CLIB_SPECIALFX_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif

#ifndef SPECIALFX_BASE_NAME
#define SPECIALFX_BASE_NAME SpecialFXBase
#endif

#define AllocFX(vp, type, number, error) ({ \
  struct ViewPort * _AllocFX_vp = (vp); \
  ULONG _AllocFX_type = (type); \
  ULONG _AllocFX_number = (number); \
  ULONG * _AllocFX_error = (error); \
  APTR _AllocFX__re = \
  ({ \
  register struct Library * const __AllocFX__bn __asm("a6") = (struct Library *) (SPECIALFX_BASE_NAME);\
  register APTR __AllocFX__re __asm("d0"); \
  register struct ViewPort * __AllocFX_vp __asm("a0") = (_AllocFX_vp); \
  register ULONG __AllocFX_type __asm("d0") = (_AllocFX_type); \
  register ULONG __AllocFX_number __asm("d1") = (_AllocFX_number); \
  register ULONG * __AllocFX_error __asm("a1") = (_AllocFX_error); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__AllocFX__re) \
  : "r"(__AllocFX__bn), "r"(__AllocFX_vp), "r"(__AllocFX_type), "r"(__AllocFX_number), "r"(__AllocFX_error) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocFX__re; \
  }); \
  _AllocFX__re; \
})

#define FreeFX(handle) ({ \
  APTR _FreeFX_handle = (handle); \
  { \
  register struct Library * const __FreeFX__bn __asm("a6") = (struct Library *) (SPECIALFX_BASE_NAME);\
  register APTR __FreeFX_handle __asm("a0") = (_FreeFX_handle); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__FreeFX__bn), "r"(__FreeFX_handle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InstallFXA(view, vp, tags) ({ \
  struct View * _InstallFXA_view = (view); \
  struct ViewPort * _InstallFXA_vp = (vp); \
  struct TagItem * _InstallFXA_tags = (tags); \
  APTR _InstallFXA__re = \
  ({ \
  register struct Library * const __InstallFXA__bn __asm("a6") = (struct Library *) (SPECIALFX_BASE_NAME);\
  register APTR __InstallFXA__re __asm("d0"); \
  register struct View * __InstallFXA_view __asm("a0") = (_InstallFXA_view); \
  register struct ViewPort * __InstallFXA_vp __asm("a1") = (_InstallFXA_vp); \
  register struct TagItem * __InstallFXA_tags __asm("a2") = (_InstallFXA_tags); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__InstallFXA__re) \
  : "r"(__InstallFXA__bn), "r"(__InstallFXA_view), "r"(__InstallFXA_vp), "r"(__InstallFXA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __InstallFXA__re; \
  }); \
  _InstallFXA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___InstallFX(struct Library * SpecialFXBase, struct View * view, struct ViewPort * vp, ULONG tags, ...)
{
  return InstallFXA(view, vp, (struct TagItem *) &tags);
}

#define InstallFX(view, vp...) ___InstallFX(SPECIALFX_BASE_NAME, view, vp)
#endif

#define RemoveFX(handle) ({ \
  APTR _RemoveFX_handle = (handle); \
  { \
  register struct Library * const __RemoveFX__bn __asm("a6") = (struct Library *) (SPECIALFX_BASE_NAME);\
  register APTR __RemoveFX_handle __asm("a0") = (_RemoveFX_handle); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__RemoveFX__bn), "r"(__RemoveFX_handle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AnimateFX(handle) ({ \
  APTR _AnimateFX_handle = (handle); \
  { \
  register struct Library * const __AnimateFX__bn __asm("a6") = (struct Library *) (SPECIALFX_BASE_NAME);\
  register APTR __AnimateFX_handle __asm("a0") = (_AnimateFX_handle); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__AnimateFX__bn), "r"(__AnimateFX_handle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindVP(view, linenum) ({ \
  struct View * _FindVP_view = (view); \
  UWORD * _FindVP_linenum = (linenum); \
  struct ViewPort * _FindVP__re = \
  ({ \
  register struct Library * const __FindVP__bn __asm("a6") = (struct Library *) (SPECIALFX_BASE_NAME);\
  register struct ViewPort * __FindVP__re __asm("d0"); \
  register struct View * __FindVP_view __asm("a0") = (_FindVP_view); \
  register UWORD * __FindVP_linenum __asm("a1") = (_FindVP_linenum); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__FindVP__re) \
  : "r"(__FindVP__bn), "r"(__FindVP_view), "r"(__FindVP_linenum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindVP__re; \
  }); \
  _FindVP__re; \
})

#endif /*  _INLINE_SPECIALFX_H  */
