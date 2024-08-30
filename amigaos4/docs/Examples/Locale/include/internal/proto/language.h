#ifndef INTERNAL_PROTO_LANGUAGE_H
#define INTERNAL_PROTO_LANGUAGE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library * LanguageBase;
#endif /* __NOLIBBASE__ */

#ifdef __amigaos4__
#ifdef __USE_INLINE__
#include <internal/inline4/language.h>
#endif /* __USE_INLINE__ */
#include <internal/interfaces/language.h>

#ifndef __NOGLOBALIFACE__
extern struct LanguageIFace *ILanguage;
#endif /* __NOGLOBALIFACE__*/

#else /* __amigaos4__ */
#error 68k not supported
#endif /* __amigaos4__ */

#endif /* INTERNAL_PROTO_LANGUAGE_H  */
