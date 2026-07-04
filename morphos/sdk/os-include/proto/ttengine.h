#ifndef _PROTO_TTENGINE_H
#define _PROTO_TTENGINE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef CLIB_TTENGINE_PROTOS_H
#include <clib/ttengine_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *TTEngineBase;
#endif

#ifdef __GNUC__
#ifndef __PPC__
#include <inline/ttengine.h>
#else
#include <ppcinline/ttengine.h>
#endif
#elif defined(__VBCC__)
#ifndef __PPC__
#include <inline/ttengine_protos.h>
#endif
#else
#include <pragma/ttengine_lib.h>
#endif

#endif  /*  _PROTO_TTENGINE_H  */
