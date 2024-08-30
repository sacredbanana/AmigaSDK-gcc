#ifndef INTERNAL_PROTO_CHARSET_H
#define INTERNAL_PROTO_CHARSET_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library * CharsetBase;
#endif /* __NOLIBBASE__ */

#ifdef __amigaos4__
#ifdef __USE_INLINE__
#include <internal/inline4/charset.h>
#endif /* __USE_INLINE__ */
#include <internal/interfaces/charset.h>

#ifndef __NOGLOBALIFACE__
extern struct CharsetIFace *ICharset;
#endif /* __NOGLOBALIFACE__*/

#else /* __amigaos4__ */
#error 68k not supported
#endif /* __amigaos4__ */

#endif /* INTERNAL_PROTO_CHARSET_H  */
