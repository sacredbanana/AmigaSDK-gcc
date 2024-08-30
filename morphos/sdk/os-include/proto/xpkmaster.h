#ifndef _PROTO_XPKMASTER_H
#define _PROTO_XPKMASTER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef CLIB_XPKMASTER_PROTOS_H
#include <clib/xpkmaster_protos.h>
#endif

#ifdef __GNUC__
#include <ppcinline/xpkmaster.h>
#else
#include <pragma/xpkmaster_lib.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *
#ifdef __CONSTLIBBASEDECL__
__CONSTLIBBASEDECL__
#endif /* __CONSTLIBBASEDECL__ */
XpkBase;
#endif

#endif	/*  _PROTO_XPKMASTER_H  */
