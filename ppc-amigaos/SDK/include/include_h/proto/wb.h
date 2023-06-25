#ifndef PROTO_WB_H
#define PROTO_WB_H

/*
**	$VER: wb.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * WorkbenchBase;
 #else
  extern struct Library * WorkbenchBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/wb.h>
 #ifdef __USE_INLINE__
  #include <inline4/wb.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_WB_PROTOS_H
  #define CLIB_WB_PROTOS_H 1
 #endif /* CLIB_WB_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::WorkbenchIFace * IWorkbench;
  #else
   extern struct WorkbenchIFace * IWorkbench;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_WB_PROTOS_H
  #include <clib/wb_protos.h>
 #endif /* CLIB_WB_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/wb.h>
  #else /* __PPC__ */
   #include <ppcinline/wb.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/wb_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/wb_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_WB_H */
