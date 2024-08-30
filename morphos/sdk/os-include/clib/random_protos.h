#ifndef CLIB_RANDOM_PROTOS_H
#define CLIB_RANDOM_PROTOS_H

/*
   random C prototypes

   Copyright © 2003 The MorphOS Development Team, All Rights Reserved.

*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

ULONG Random(void);
UBYTE RandomByte(void);
void RandomStir(void);
void RandomBytes(APTR buf, LONG buflen);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_RANDOM_PROTOS_H */
