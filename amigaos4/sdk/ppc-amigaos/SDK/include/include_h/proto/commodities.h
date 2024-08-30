#ifndef PROTO_COMMODITIES_H
#define PROTO_COMMODITIES_H

/*
**	$VER: commodities.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif
#ifndef DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * CxBase;
 #else
  extern struct Library * CxBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/commodities.h>
 #ifdef __USE_INLINE__
  #include <inline4/commodities.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_COMMODITIES_PROTOS_H
  #define CLIB_COMMODITIES_PROTOS_H 1
 #endif /* CLIB_COMMODITIES_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CommoditiesIFace * ICommodities;
  #else
   extern struct CommoditiesIFace * ICommodities;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_COMMODITIES_PROTOS_H
  #include <clib/commodities_protos.h>
 #endif /* CLIB_COMMODITIES_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/commodities.h>
  #else /* __PPC__ */
   #include <ppcinline/commodities.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/commodities_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/commodities_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_COMMODITIES_H */
