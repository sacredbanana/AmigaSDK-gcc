#ifndef PROTO_EXPANSION_H
#define PROTO_EXPANSION_H

/*
**	$VER: expansion.h 53.29 (10.8.2015)
**	Includes Release 50.1
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXPANSION_PCI_H
#include <expansion/pci.h>
#endif
#ifndef EXPANSION_EXPANSION_H
#include <expansion/expansion.h>
#endif
#ifndef EXPANSION_CONFIGVARS_H
#include <expansion/configvars.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * ExpansionBase;
 #else
  extern struct ExpansionBase * ExpansionBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/expansion.h>
 #ifdef __USE_INLINE__
  #include <inline4/expansion.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_EXPANSION_PROTOS_H
  #define CLIB_EXPANSION_PROTOS_H 1
 #endif /* CLIB_EXPANSION_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct ExpansionIFace *IExpansion;
  extern struct PCIIFace *IPCI;
  extern struct PCIDevice *IPCIDev;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_EXPANSION_PROTOS_H
  #include <clib/expansion_protos.h>
 #endif /* CLIB_EXPANSION_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/expansion.h>
  #else /* __PPC__ */
   #include <ppcinline/expansion.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/expansion_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/expansion_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_EXPANSION_H */
