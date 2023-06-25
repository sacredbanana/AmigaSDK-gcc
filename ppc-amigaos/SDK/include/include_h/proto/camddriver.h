#ifndef PROTO_CAMDDRIVER_H
#define PROTO_CAMDDRIVER_H

/*
** $VER: camddriver.h 54.16 (22.08.2022)
**
** C. A. M. D. (Commodore Amiga MIDI Driver)
**
** Prototype/inline/pragma header file combo
**
** Copyright (c) 2015 Hyperion Entertainment CVBA.
** All Rights Reserved.
*/

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * CamdDriverBase;
 #else
  extern struct Library * CamdDriverBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/CamdDriver.h>
 #ifdef __USE_INLINE__
//  #include <inline4/CamdDriver.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CAMDDRIVER_PROTOS_H
  #define CLIB_CAMDDRIVER_PROTOS_H 1
 #endif /* CLIB_CAMDDRIVER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct CamdDriverIFace *ICamdDriver;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CAMDDRIVER_PROTOS_H
  #include <clib/CamdDriver_protos.h>
 #endif /* CLIB_CAMDDRIVER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/CamdDriver.h>
  #else
   #include <ppcinline/CamdDriver.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/CamdDriver_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/CamdDriver_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CAMDDRIVER_H */
