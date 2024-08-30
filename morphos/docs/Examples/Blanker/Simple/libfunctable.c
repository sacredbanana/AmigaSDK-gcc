#include "libdata.h"

void	LIB_Open(void);
void	LIB_Close(void);
void	LIB_Expunge(void);
void	LIB_Query(void);
void	LIB_QueryBlanker(void);
void	LIB_InitBlanker(void);
void	LIB_EndBlanker(void);
void	LIB_AnimBlanker(void);

ULONG	LibFuncTable[]=
{
FUNCARRAY_BEGIN,
FUNCARRAY_32BIT_NATIVE,
(ULONG) &LIB_Open,		/* Old ABOX Library ABI Function Block */
(ULONG) &LIB_Close,
(ULONG) &LIB_Expunge,
(ULONG) &LIB_Query,
(ULONG) &LIB_QueryBlanker,
(ULONG) &LIB_InitBlanker,
(ULONG) &LIB_EndBlanker,
(ULONG) &LIB_AnimBlanker,
0xffffffff,
FUNCARRAY_END
};

