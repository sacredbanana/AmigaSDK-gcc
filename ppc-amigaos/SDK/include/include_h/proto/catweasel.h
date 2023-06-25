#ifndef PROTO_CATWEASEL_H
#define PROTO_CATWEASEL_H

/*
**	$VER: catweasel.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef PROTO_EXPANSION_H
#include <proto/expansion.h>
#endif
#ifndef EXPANSION_PCI_H
#include <expansion/pci.h>
#endif
#ifndef RESOURCES_CATWEASEL_H
#include <resources/catweasel.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * CWBase;
  #else
   extern struct Library * CWBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CWBase * CWBase;
  #else
   extern struct CWBase * CWBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/catweasel.h>
 #ifdef __USE_INLINE__
  #include <inline4/catweasel.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CATWEASEL_PROTOS_H
  #define CLIB_CATWEASEL_PROTOS_H 1
 #endif /* CLIB_CATWEASEL_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CWIFace * ICW;
  #else
   extern struct CWIFace * ICW;
  #endif
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CW3GameportIFace * ICW3Gameport;
  #else
   extern struct CW3GameportIFace * ICW3Gameport;
  #endif
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CW3KeyboardIFace * ICW3Keyboard;
  #else
   extern struct CW3KeyboardIFace * ICW3Keyboard;
  #endif
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CW3SIDIFace * ICW3SID;
  #else
   extern struct CW3SIDIFace * ICW3SID;
  #endif
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CW3FloppyIFace * ICW3Floppy;
  #else
   extern struct CW3FloppyIFace * ICW3Floppy;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CATWEASEL_PROTOS_H
  #include <clib/catweasel_protos.h>
 #endif /* CLIB_CATWEASEL_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/catweasel.h>
  #else /* __PPC__ */
   #include <ppcinline/catweasel.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/catweasel_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/catweasel_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CATWEASEL_H */
