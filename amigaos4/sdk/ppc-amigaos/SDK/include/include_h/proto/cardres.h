#ifndef PROTO_CARDRES_H
#define PROTO_CARDRES_H

/*
**	$VER: cardres.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_RESIDENT_H
#include <exec/resident.h>
#endif
#ifndef RESOURCES_CARD_H
#include <resources/card.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * CardResource;
 #else
  extern struct Library * CardResource;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/cardres.h>
 #ifdef __USE_INLINE__
  #include <inline4/cardres.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CARDRES_PROTOS_H
  #define CLIB_CARDRES_PROTOS_H 1
 #endif /* CLIB_CARDRES_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CardIFace * ICard;
  #else
   extern struct CardIFace * ICard;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CARDRES_PROTOS_H
  #include <clib/cardres_protos.h>
 #endif /* CLIB_CARDRES_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/cardres.h>
  #else /* __PPC__ */
   #include <ppcinline/cardres.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/cardres_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/cardres_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CARDRES_H */
