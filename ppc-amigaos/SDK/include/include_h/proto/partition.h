#ifndef PROTO_PARTITION_H
#define PROTO_PARTITION_H

/*
**	$VER: partition.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * PartitionBase;
 #else
  extern struct Library * PartitionBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/partition.h>
 #ifdef __USE_INLINE__
  #include <inline4/partition.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PARTITION_PROTOS_H
  #define CLIB_PARTITION_PROTOS_H 1
 #endif /* CLIB_PARTITION_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PartitionIFace * IPartition;
  #else
   extern struct PartitionIFace * IPartition;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PARTITION_PROTOS_H
  #include <clib/partition_protos.h>
 #endif /* CLIB_PARTITION_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/partition.h>
  #else /* __PPC__ */
   #include <ppcinline/partition.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/partition_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/partition_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PARTITION_H */
