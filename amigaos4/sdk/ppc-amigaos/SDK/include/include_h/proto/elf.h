#ifndef PROTO_ELF_H
#define PROTO_ELF_H

/*
**	$VER: elf.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_ELF_H
#include <libraries/elf.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ElfBase;
 #else
  extern struct Library * ElfBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/elf.h>
 #ifdef __USE_INLINE__
  #include <inline4/elf.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_ELF_PROTOS_H
  #define CLIB_ELF_PROTOS_H 1
 #endif /* CLIB_ELF_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ElfIFace * IElf;
  #else
   extern struct ElfIFace * IElf;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_ELF_PROTOS_H
  #include <clib/elf_protos.h>
 #endif /* CLIB_ELF_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/elf.h>
  #else /* __PPC__ */
   #include <ppcinline/elf.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/elf_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/elf_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_ELF_H */
