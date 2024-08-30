#ifndef IFF_IFFPARSE_H
#define IFF_IFFPARSE_H

/*
	iffparse.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef DEVICES_CLIPBOARD_H
# include <devices/clipboard.h>
#endif

#pragma pack(2)


struct IFFHandle
{
	ULONG iff_Stream;
	ULONG iff_Flags;
	LONG  iff_Depth;
};

#define IFFF_READ      0
#define IFFF_WRITE     1
#define IFFF_RWBITS    (IFFF_READ | IFFF_WRITE)
#define IFFF_FSEEK     (1<<1)
#define IFFF_RSEEK     (1<<2)
#define IFFF_RESERVED  0xFFFF0000


struct IFFStreamCmd
{
	LONG sc_Command;
	APTR sc_Buf;
	LONG sc_NBytes;
};


struct ContextNode
{
	struct MinNode cn_Node;
	LONG           cn_ID;
	LONG           cn_Type;
	LONG           cn_Size;
	LONG           cn_Scan;
};


struct LocalContextItem
{
	struct MinNode lci_Node;
	ULONG          lci_ID;
	ULONG          lci_Type;
	ULONG          lci_Ident;
};


struct StoredProperty
{
	LONG sp_Size;
	APTR sp_Data;
};


struct CollectionItem
{
	struct CollectionItem *ci_Next;
	LONG                   ci_Size;
	APTR                   ci_Data;
};


struct ClipboardHandle
{
	struct IOClipReq cbh_Req;
	struct MsgPort   cbh_CBport;
	struct MsgPort   cbh_SatisfyPort;
};


#define IFFERR_EOF         -1
#define IFFERR_EOC         -2
#define IFFERR_NOSCOPE     -3
#define IFFERR_NOMEM       -4
#define IFFERR_READ        -5
#define IFFERR_WRITE       -6
#define IFFERR_SEEK        -7
#define IFFERR_MANGLED     -8
#define IFFERR_SYNTAX      -9
#define IFFERR_NOTIFF      -10
#define IFFERR_NOHOOK      -11
#define IFF_RETURN2CLIENT  -12


#define MAKE_ID(a,b,c,d)  ((ULONG) (a)<<24 | (ULONG) (b)<<16 | (ULONG) (c)<<8 | (ULONG) (d))

#define ID_FORM  MAKE_ID('F','O','R','M')
#define ID_LIST  MAKE_ID('L','I','S','T')
#define ID_CAT   MAKE_ID('C','A','T',' ')
#define ID_PROP  MAKE_ID('P','R','O','P')
#define ID_NULL  MAKE_ID(' ',' ',' ',' ')

#define IFFLCI_PROP          MAKE_ID('p','r','o','p')
#define IFFLCI_COLLECTION    MAKE_ID('c','o','l','l')
#define IFFLCI_ENTRYHANDLER  MAKE_ID('e','n','h','d')
#define IFFLCI_EXITHANDLER   MAKE_ID('e','x','h','d')


#define IFFPARSE_SCAN     0
#define IFFPARSE_STEP     1
#define IFFPARSE_RAWSTEP  2


#define IFFSLI_ROOT  1
#define IFFSLI_TOP   2
#define IFFSLI_PROP  3


#define IFFSIZE_UNKNOWN  -1


#define IFFCMD_INIT      0
#define IFFCMD_CLEANUP   1
#define IFFCMD_READ      2
#define IFFCMD_WRITE     3
#define IFFCMD_SEEK      4
#define IFFCMD_ENTRY     5
#define IFFCMD_EXIT      6
#define IFFCMD_PURGELCI  7

/* Seek modes for SeekChunkBytes() and SeekChunkRecords() */

#define IFFOFFSET_BEGINNING     0
#define IFFOFFSET_END           1
#define IFFOFFSET_CURRENT       2


/*** OBSOLETE ***/

#ifndef IFFPARSE_V37_NAMES_ONLY

#define IFFSCC_INIT     IFFCMD_INIT
#define IFFSCC_CLEANUP  IFFCMD_CLEANUP
#define IFFSCC_READ     IFFCMD_READ
#define IFFSCC_WRITE    IFFCMD_WRITE
#define IFFSCC_SEEK     IFFCMD_SEEK

#endif /* IFFPARSE_V37_NAMES_ONLY */


#pragma pack()

#endif /* IFFPARSE_H */
