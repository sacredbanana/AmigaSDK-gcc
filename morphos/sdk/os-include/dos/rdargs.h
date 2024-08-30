#ifndef DOS_RDARGS_H
#define DOS_RDARGS_H

/*
	dos ReadArgs definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct CSource
{
	UBYTE *CS_Buffer;
	LONG   CS_Length;
	LONG   CS_CurChr;
};

struct RDArgs
{
	struct CSource  RDA_Source;
	LONG            RDA_DAList;
	UBYTE          *RDA_Buffer;
	LONG            RDA_BufSiz;
	UBYTE          *RDA_ExtHelp;
	LONG            RDA_Flags;
};


#define RDAB_STDIN     0
#define RDAF_STDIN     (1<<RDAB_STDIN)

#define RDAB_NOALLOC   1
#define RDAF_NOALLOC   (1<<RDAB_NOALLOC)

#define RDAB_NOPROMPT  2
#define RDAF_NOPROMPT  (1<<RDAB_NOPROMPT)


#define MAX_TEMPLATE_ITEMS  100
#define MAX_MULTIARGS       128


#pragma pack()

#endif /* DOS_RDARGS_H */
