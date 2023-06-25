#ifndef PROTO_TEXTCLIP_H
#define PROTO_TEXTCLIP_H

/*
**	$VER: textclip.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * TextClipBase;
 #else
  extern struct Library * TextClipBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/textclip.h>
 #ifdef __USE_INLINE__
  #include <inline4/textclip.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_TEXTCLIP_PROTOS_H
  #define CLIB_TEXTCLIP_PROTOS_H 1
 #endif /* CLIB_TEXTCLIP_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::TextClipIFace * ITextClip;
  #else
   extern struct TextClipIFace * ITextClip;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_TEXTCLIP_PROTOS_H
  #include <clib/textclip_protos.h>
 #endif /* CLIB_TEXTCLIP_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/textclip.h>
  #else /* __PPC__ */
   #include <ppcinline/textclip.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/textclip_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/textclip_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_TEXTCLIP_H */
