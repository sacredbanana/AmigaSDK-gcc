/* Automatically generated header! Do not edit! */

#ifndef PROTO_DYNLOAD_H
#define PROTO_DYNLOAD_H

#ifndef __NOLIBBASE__
extern struct Library *
#ifdef __CONSTLIBBASEDECL__
__CONSTLIBBASEDECL__
#endif /* __CONSTLIBBASEDECL__ */
DynLoadBase;
#endif /* !__NOLIBBASE__ */

#include <clib/dynload_protos.h>

#ifdef __GNUC__
#ifdef __PPC__
#ifndef _NO_PPCINLINE
#include <ppcinline/dynload.h>
#endif /* _NO_PPCINLINE */
#else
#ifndef _NO_INLINE
#include <inline/dynload.h>
#endif /* _NO_INLINE */
#endif /* __PPC__ */
#elif defined(__VBCC__)
#include <inline/dynload_protos.h>
#else
#include <pragmas/dynload_pragmas.h>
#endif /* __GNUC__ */

#endif /* !PROTO_DYNLOAD_H */

