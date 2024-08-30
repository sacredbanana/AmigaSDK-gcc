#ifndef PROTO_OPENURL_H
#define PROTO_OPENURL_H

/*
**  $VER: openurl.h 6.3 (17.4.2005)
**  Includes Release 6.3
**
**  SAS `C' style prototype/pragma header file combo
**
**  openurl.library - universal URL display and browser
**  launcher library
**
**  Written by Troels Walsted Hansen <troels@thule.no>
**  Placed in the public domain.
**
**  Developed by:
**  - Alfonso Ranieri <alforan@tin.it>
**  - Stefan Kost <ensonic@sonicpulse.de>
**
*/

#ifndef __NOLIBBASE__
extern struct Library *
#ifdef __CONSTLIBBASEDECL__
__CONSTLIBBASEDECL__
#endif /* __CONSTLIBBASEDECL__ */
OpenURLBase;
#endif /* !__NOLIBBASE__ */

#include <clib/openurl_protos.h>

#ifdef __GNUC__
#ifdef __PPC__
#ifndef _NO_PPCINLINE
#include <ppcinline/openurl.h>
#endif /* _NO_PPCINLINE */
#else
#ifndef _NO_INLINE
#include <inline/openurl.h>
#endif /* _NO_INLINE */
#endif /* __PPC__ */
#else
#include <pragmas/openurl_pragmas.h>
#endif /* __GNUC__ */

#endif /* !PROTO_OPENURL_H */
