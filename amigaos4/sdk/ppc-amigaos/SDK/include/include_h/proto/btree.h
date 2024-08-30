#ifndef PROTO_BTREE_H
#define PROTO_BTREE_H

/*
**	$VER: btree.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef LIBRARIES_BTREE_H
#include <libraries/btree.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * BTreeBase;
  #else
   extern struct Library * BTreeBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * BTreeBase;
  #else
   extern struct Library * BTreeBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/btree.h>
 #ifdef __USE_INLINE__
  #include <inline4/btree.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_BTREE_PROTOS_H
  #define CLIB_BTREE_PROTOS_H 1
 #endif /* CLIB_BTREE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::BTreeIFace * IBTree;
  #else
   extern struct BTreeIFace * IBTree;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_BTREE_PROTOS_H
  #include <clib/btree_protos.h>
 #endif /* CLIB_BTREE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/btree.h>
  #else /* __PPC__ */
   #include <ppcinline/btree.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/btree_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/btree_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_BTREE_H */
