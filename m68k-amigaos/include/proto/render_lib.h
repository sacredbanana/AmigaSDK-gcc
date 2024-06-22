/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_RENDER_H
#define PROTO_RENDER_H

#include <clib/render_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/render.h>
#  else
#   include <inline/render.h>
#  endif
# else
#  include <pragmas/render_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/render.h>
# ifndef __NOGLOBALIFACE__
   extern struct RenderIFace *IRender;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  RenderBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_RENDER_H */
