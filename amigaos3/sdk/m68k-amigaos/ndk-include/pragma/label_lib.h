#ifndef PRAGMA_LABEL_LIB_H
#define PRAGMA_LABEL_LIB_H

/*
**	$VER: label_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_LABEL_PROTOS_H
#include <clib/label_protos.h>
#endif /* CLIB_LABEL_PROTOS_H */

/* "label.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(LabelBase, 0x1e, LABEL_GetClass())

#endif /* PRAGMA_LABEL_LIB_H */
