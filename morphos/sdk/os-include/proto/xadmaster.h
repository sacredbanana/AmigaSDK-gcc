#ifndef _PROTO_XADMASTER_H
#define _PROTO_XADMASTER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef CLIB_XADMASTER_PROTOS_H
#include <clib/xadmaster_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct xadMasterBase *xadMasterBase;
#endif

#ifdef __GNUC__
#ifdef __PPC__
#include <ppcinline/xadmaster.h>
#else
#include <inline/xadmaster.h>
#endif
#elif defined(__VBCC__)
#if defined(__MORPHOS__) || !defined(__PPC__)
#include <inline/xadmaster_protos.h>
#endif
#else
#include <pragma/xadmaster_lib.h>
#endif

#endif	/*  _PROTO_XADMASTER_H  */
