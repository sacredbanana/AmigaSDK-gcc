#ifndef REXX_STORAGE_H
#define REXX_STORAGE_H

/*
	rexx storage defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#pragma pack(2)


struct NexxStr
{
	LONG  ns_Ivalue;
	UWORD ns_Length;
	UBYTE ns_Flags;
	UBYTE ns_Hash;
	BYTE  ns_Buff[8];
};


#define NXADDLEN  9
#define IVALUE(nsPtr)  (nsPtr->ns_Ivalue)


/* String attribute flag-bits */

#define NSB_KEEP    0
#define NSB_STRING  1
#define NSB_NOTNUM  2
#define NSB_NUMBER  3
#define NSB_BINARY  4
#define NSB_FLOAT   5
#define NSB_EXT     6
#define NSB_SOURCE  7

#define NSF_KEEP    (1 << NSB_KEEP)
#define NSF_STRING  (1 << NSB_STRING)
#define NSF_NOTNUM  (1 << NSB_NOTNUM)
#define NSF_NUMBER  (1 << NSB_NUMBER)
#define NSF_BINARY  (1 << NSB_BINARY)
#define NSF_FLOAT   (1 << NSB_FLOAT)
#define NSF_EXT     (1 << NSB_EXT)
#define NSF_SOURCE  (1 << NSB_SOURCE)


/* Combinations of flags */

#define NSF_INTNUM  (NSF_NUMBER | NSF_BINARY | NSF_STRING)
#define NSF_DPNUM   (NSF_NUMBER | NSF_FLOAT)
#define NSF_ALPHA   (NSF_NOTNUM | NSF_STRING)
#define NSF_OWNED   (NSF_SOURCE | NSF_EXT    | NSF_KEEP)
#define KEEPSTR     (NSF_STRING | NSF_SOURCE | NSF_NOTNUM)
#define KEEPNUM     (NSF_STRING | NSF_SOURCE | NSF_NUMBER | NSF_BINARY)


struct RexxArg
{
	LONG  ra_Size;
	UWORD ra_Length;
	UBYTE ra_Flags;
	UBYTE ra_Hash;
	BYTE  ra_Buff[8];
};


struct RexxMsg
{
	struct Message  rm_Node;
	APTR            rm_TaskBlock;
	APTR            rm_LibBase;
	LONG            rm_Action;
	LONG            rm_Result1;
	LONG            rm_Result2;
	STRPTR          rm_Args[16];

	struct MsgPort *rm_PassPort;
	STRPTR          rm_CommAddr;
	STRPTR          rm_FileExt;
	LONG            rm_Stdin;
	LONG            rm_Stdout;
	LONG            rm_avail;
};


/* Field definitions */

#define ARG0(rmp)  (rmp->rm_Args[0])
#define ARG1(rmp)  (rmp->rm_Args[1])
#define ARG2(rmp)  (rmp->rm_Args[2])

#define MAXRMARG  15


/* Message-packet commands */

#define RXCOMM    0x01000000
#define RXFUNC    0x02000000
#define RXCLOSE   0x03000000
#define RXQUERY   0x04000000
#define RXADDFH   0x07000000
#define RXADDLIB  0x08000000
#define RXREMLIB  0x09000000
#define RXADDCON  0x0A000000
#define RXREMCON  0x0B000000
#define RXTCOPN   0x0C000000
#define RXTCCLS   0x0D000000


/* Command modifier flag-bits */

#define RXFB_NOIO    16
#define RXFB_RESULT  17
#define RXFB_STRING  18
#define RXFB_TOKEN   19
#define RXFB_NONRET  20

#define RXFF_NOIO    (1 << RXFB_NOIO)
#define RXFF_RESULT  (1 << RXFB_RESULT)
#define RXFF_STRING  (1 << RXFB_STRING)
#define RXFF_TOKEN   (1 << RXFB_TOKEN)
#define RXFF_NONRET  (1 << RXFB_NONRET)

#define RXCODEMASK   0xFF000000
#define RXARGMASK    0x0000000F


struct RexxRsrc
{
	struct Node rr_Node;
	WORD        rr_Func;
	APTR        rr_Base;
	LONG        rr_Size;
	LONG        rr_Arg1;
	LONG        rr_Arg2;
};


/* Resource node-types */

#define RRT_ANY   0
#define RRT_LIB   1
#define RRT_PORT  2
#define RRT_FILE  3
#define RRT_HOST  4
#define RRT_CLIP  5


#define GLOBALSZ  200


struct RexxTask
{
	BYTE           rt_Global[GLOBALSZ];
	struct MsgPort rt_MsgPort;
	UBYTE          rt_Flags;
	BYTE           rt_SigBit;

	APTR           rt_ClientID;
	APTR           rt_MsgPkt;
	APTR           rt_TaskID;
	APTR           rt_RexxPort;

	APTR           rt_ErrTrap;
	APTR           rt_StackPtr;

	struct List    rt_Header1;
	struct List    rt_Header2;
	struct List    rt_Header3;
	struct List    rt_Header4;
	struct List    rt_Header5;
};


/* RexxTask flag-bits */

#define RTFB_TRACE  0
#define RTFB_HALT   1
#define RTFB_SUSP   2
#define RTFB_TCUSE  3
#define RTFB_WAIT   6
#define RTFB_CLOSE  7


/* Memory allocation constants */

#define MEMQUANT  16L
#define MEMMASK   0xFFFFFFF0

#define MEMQUICK  (1 << 0)
#define MEMCLEAR  (1 << 16)


struct SrcNode
{
	struct SrcNode *sn_Succ;
	struct SrcNode *sn_Pred;
	APTR            sn_Ptr;
	LONG            sn_Size;
};


#pragma pack()

#endif
