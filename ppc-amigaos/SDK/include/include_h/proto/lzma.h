#ifndef PROTO_LZMA_H
#define PROTO_LZMA_H

/*
**	$VER: lzma.h 53.34 (09.12.2021)
**	Includes Release 50.1
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * LZMABase;
 #else
  extern struct Library * LZMABase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/lzma.h>
 #ifdef __USE_INLINE__
  #include <inline4/lzma.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LZMA_PROTOS_H
  #define CLIB_LZMA_PROTOS_H 1
 #endif /* CLIB_LZMA_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct LZMAIFace *ILZMA;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LZMA_PROTOS_H
  #include <clib/lzma_protos.h>
 #endif /* CLIB_LZMA_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/lzma.h>
  #else
   #include <ppcinline/lzma.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/lzma_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/lzma_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LZMA_H */
