#ifndef PRAGMA_TRANSLATOR_LIB_H
#define PRAGMA_TRANSLATOR_LIB_H

/*
**	$VER: translator_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_TRANSLATOR_PROTOS_H
#include <clib/translator_protos.h>
#endif /* CLIB_TRANSLATOR_PROTOS_H */

/* "translator.library" */
#pragma amicall(TranslatorBase, 0x1e, Translate(a0,d0,a1,d1))

#endif /* PRAGMA_TRANSLATOR_LIB_H */
