/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef PROTO_DOOMSOUND_H
#define PROTO_DOOMSOUND_H

#include <clib/doomsound_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include <defines/doomsound.h>
#  else
#   include <inline/doomsound.h>
#  endif
# else
#  include <pragmas/doomsound_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/doomsound.h>
# ifndef __NOGLOBALIFACE__
   extern struct DoomSndIFace *IDoomSnd;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  DoomSndBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_DOOMSOUND_H */
