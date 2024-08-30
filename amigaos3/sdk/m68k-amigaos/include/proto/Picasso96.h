#ifndef PROTO_PICASSO96_H
#define PROTO_PICASSO96_H
#include <exec/types.h>
#include <clib/Picasso96_protos.h>

#ifndef __NOLIBBASE__
extern struct Library *
#ifdef __CONSTLIBBASEDECL__
__CONSTLIBBASEDECL__
#endif /* __CONSTLIBBASEDECL__ */
P96Base;
#endif /* !__NOLIBBASE__ */


#include <libraries/Picasso96.h>
#include <clib/Picasso96_protos.h>
#ifdef __GNUC__
#include <inline/Picasso96.h>
#else
#include <pragmas/Picasso96_pragmas.h>
#endif /* __GNUC__ */
#endif
