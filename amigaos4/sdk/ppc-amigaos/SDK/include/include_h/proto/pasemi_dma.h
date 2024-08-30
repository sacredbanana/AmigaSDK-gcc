#ifndef PROTO_PASEMI_DMA_H
#define PROTO_PASEMI_DMA_H

/*
**	$VER: pasemi_dma.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef RESOURCES_PASEMI_DMA_H
#include <resources/pasemi_dma.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * PASemiDMABase;
 #else
  extern struct Library * PASemiDMABase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/pasemi_dma.h>
 #ifdef __USE_INLINE__
  #include <inline4/pasemi_dma.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PASEMI_DMA_PROTOS_H
  #define CLIB_PASEMI_DMA_PROTOS_H 1
 #endif /* CLIB_PASEMI_DMA_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PASDMAIFace * IPASDMA;
  #else
   extern struct PASDMAIFace * IPASDMA;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PASEMI_DMA_PROTOS_H
  #include <clib/pasemi_dma_protos.h>
 #endif /* CLIB_PASEMI_DMA_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/pasemi_dma.h>
  #else /* __PPC__ */
   #include <ppcinline/pasemi_dma.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/pasemi_dma_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/pasemi_dma_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PASEMI_DMA_H */
