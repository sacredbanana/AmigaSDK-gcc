#ifndef _PROTO_XPKSUB_H
#define _PROTO_XPKSUB_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef CLIB_XPKSUB_PROTOS_H
#include <clib/xpksub_protos.h>
#endif

#ifdef __GNUC__
#include <ppcinline/xpksub.h>
#else
#include <pragma/xpksub_lib.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *
#ifdef __CONSTLIBBASEDECL__
__CONSTLIBBASEDECL__
#endif /* __CONSTLIBBASEDECL__ */
XpkSubBase;
#endif

#endif	/*  _PROTO_XPKSUB_H  */
