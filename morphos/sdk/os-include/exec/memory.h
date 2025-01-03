#ifndef EXEC_MEMORY_H
#define EXEC_MEMORY_H

/*
	exec memory definitions (V50)

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#pragma pack(2)


struct MemChunk
{
	struct MemChunk *mc_Next;
	ULONG            mc_Bytes;
};

struct MemHeader
{
	struct Node      mh_Node;
	UWORD            mh_Attributes;
	struct MemChunk *mh_First;
	APTR             mh_Lower;
	APTR             mh_Upper;
	ULONG            mh_Free;
};

struct MemEntry
{
	union
	{
		ULONG meu_Reqs;
		APTR  meu_Addr;
	}     me_Un;
	ULONG me_Length;
};

#define me_un    me_Un
#define me_Reqs  me_Un.meu_Reqs
#define me_Addr  me_Un.meu_Addr

struct MemList
{
	struct Node     ml_Node;
	UWORD           ml_NumEntries;
	struct MemEntry ml_ME[1];
};

#define ml_me  ml_ME

#define MEMF_ANY            (0)
#define MEMF_PUBLIC         (1<<0)
#define MEMF_CHIP           (1<<1)
#define MEMF_FAST           (1<<2)
#define MEMF_LOCAL          (1<<8)
#define MEMF_24BITDMA       (1<<9)
#define MEMF_KICK           (1<<10)
#define MEMF_SWAP           (1<<11)	/* Memory that can be swapped out to disk */
#define MEMF_31BIT          (1<<12)	/* Memory that is in <2GiB area (V51) */

#define MEMF_CLEAR          (1<<16)
#define MEMF_LARGEST        (1<<17)
#define MEMF_REVERSE        (1<<18)
#define MEMF_TOTAL          (1<<19)
#define MEMF_SEM_PROTECTED  (1<<20)	/* Pools: semaphore protection */
#define MEMF_NO_EXPUNGE     (1<<31)

#define MEM_BLOCKSIZE       (8UL)
#define MEM_BLOCKMASK       (MEM_BLOCKSIZE - 1)

struct MemHandlerData
{
	ULONG memh_RequestSize;
	ULONG memh_RequestFlags;
	ULONG memh_Flags;
};

#define MEMHF_RECYCLE   (1<<0)

#define MEM_DID_NOTHING (0)
#define MEM_ALL_DONE    (-1)
#define MEM_TRY_AGAIN   (1)

struct FreeBlocksData
{
	ULONG           fbd_NumBlocks;
	struct MemEntry fbd_Blocks[1];  /* fbd_NumBlocks entries */
};


#pragma pack()

#endif
