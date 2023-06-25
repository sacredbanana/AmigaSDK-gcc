#ifndef PROTO_BULLET_H
#define PROTO_BULLET_H

/*
**	$VER: bullet.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef DISKFONT_GLYPH_H
#include <diskfont/glyph.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * BulletBase;
 #else
  extern struct Library * BulletBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/bullet.h>
 #ifdef __USE_INLINE__
  /*
   * No inlines which would require the same struct BulletIFace *
   * for multiple fonts/GlyphEngines.
   * Use the new diskfont functions instead.
   */
  /* #include <inline4/bullet.h> */
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_BULLET_PROTOS_H
  #define CLIB_BULLET_PROTOS_H 1
 #endif /* CLIB_BULLET_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  /*
   * No global struct BulletIFace *
   * for multiple fonts/GlyphEngines.
   * Use the new diskfont functions instead.
   */
  /* #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::BulletIFace * IBullet;
  #else
   extern struct BulletIFace * IBullet;
  #endif */
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_BULLET_PROTOS_H
  #include <clib/bullet_protos.h>
 #endif /* CLIB_BULLET_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/bullet.h>
  #else /* __PPC__ */
   #include <ppcinline/bullet.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/bullet_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/bullet_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_BULLET_H */
