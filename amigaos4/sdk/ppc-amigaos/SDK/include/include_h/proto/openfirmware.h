#ifndef PROTO_OPENFIRMWARE_H
#define PROTO_OPENFIRMWARE_H

/*
**	$VER: openfirmware.h 53.29 (10.8.2015)
**
**	Prototype/inline/pragma header file combo
**
**	(C) Copyright 2003-2005 Amiga, Inc.
**	    All Rights Reserved
**
** Copyright (c) 2010 Hyperion Entertainment CVBA.
**     All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef RESOURCES_OPENFIRMWARE_H
#include <resources/openfirmware.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * OpenFirmwareBase;
 #else
  extern struct Library * OpenFirmwareBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/openfirmware.h>
 #ifdef __USE_INLINE__
  #include <inline4/openfirmware.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_OPENFIRMWARE_PROTOS_H
  #define CLIB_OPENFIRMWARE_PROTOS_H 1
 #endif /* CLIB_OPENFIRMWARE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct OpenFirmwareIFace *IOpenFirmware;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_OPENFIRMWARE_PROTOS_H
  #include <clib/openfirmware_protos.h>
 #endif /* CLIB_OPENFIRMWARE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/openfirmware.h>
  #else
   #include <ppcinline/openfirmware.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/openfirmware_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/openfirmware_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_OPENFIRMWARE_H */
