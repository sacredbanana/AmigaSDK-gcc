#ifndef PROTO_PALETTE_H
#define PROTO_PALETTE_H

/*
**	$VER: palette.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * PaletteBase;
 #else
  extern struct Library * PaletteBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/palette.h>
 #ifdef __USE_INLINE__
  #include <inline4/palette.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PALETTE_PROTOS_H
  #define CLIB_PALETTE_PROTOS_H 1
 #endif /* CLIB_PALETTE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PaletteIFace * IPalette;
  #else
   extern struct PaletteIFace * IPalette;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PALETTE_PROTOS_H
  #include <clib/palette_protos.h>
 #endif /* CLIB_PALETTE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/palette.h>
  #else /* __PPC__ */
   #include <ppcinline/palette.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/palette_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/palette_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PALETTE_H */
