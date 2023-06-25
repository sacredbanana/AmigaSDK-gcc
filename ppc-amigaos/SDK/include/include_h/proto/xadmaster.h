#ifndef PROTO_XADMASTER_H
#define PROTO_XADMASTER_H

/* This file was created automatically by idltool v1.2.
 * Do NOT edit by hand!
 */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_XADMASTER_H
#include <libraries/xadmaster.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * XadMasterBase;
 #else
  extern struct XadMasterBase * XadMasterBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/xadmaster.h>
 #ifdef __USE_INLINE__
  #include <inline4/xadmaster.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_XADMASTER_PROTOS_H
  #define CLIB_XADMASTER_PROTOS_H 1
 #endif /* CLIB_XADMASTER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct XadMasterIFace *IXadMaster;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_XADMASTER_PROTOS_H
  #include <clib/xadmaster_protos.h>
 #endif /* CLIB_XADMASTER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/xadmaster.h>
  #else
   #include <ppcinline/xadmaster.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/xadmaster_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/xadmaster_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_XADMASTER_H */
