/*
 * $Id: fs_plugin_cache.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 *
 * Amiga ROM file system reimplementation
 * Copyright © 2001-2005 by Olaf Barthel
 * All Rights Reserved
 */

#include <exec/memory.h>
#include <exec/interrupts.h>

#include <dos/dosextens.h>
#include <dos/rdargs.h>

#ifndef __amigaos4__
#include <clib/alib_protos.h>
#endif /* __amigaos4__ */

/****************************************************************************/

/* Kludge for new utility.library header files... */
#define UTILITY_DATA_STRUCTURES_H

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

/****************************************************************************/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/****************************************************************************/

#include "fs_plugin_cache_rev.h"
STRPTR version_tag = VERSTAG;

/****************************************************************************/

#include "compiler.h"
#include "plugin.h"

/****************************************************************************/

typedef LONG *	NUMBER;
typedef LONG	SWITCH;
typedef STRPTR	KEY;

/****************************************************************************/

/*#define DEBUG*/
#include "assert.h"

/****************************************************************************/

#define OK 0
#define NOT !
#define CANNOT !

/****************************************************************************/

#define D_S(type,name) \
	char a_##name[sizeof(type)+3]; \
	type *name = (type *)((LONG)(a_##name+3) & ~3)

/****************************************************************************/

/* A combination of a balanced binary tree with a doubly-linked list.
 * Typically used for caches with LRU purge scheme.
 */
struct SplayNode
{
	struct MinNode		sn_MinNode;		/* This goes into the list */
	struct SplayNode *	sn_Left;		/* Left child */
	struct SplayNode *	sn_Right;		/* Right child */
	ULONG				sn_Key;			/* Unique identifier */
};

/* The root of the splay tree. */
struct SplayTree
{
	struct SplayNode *	st_Root;
};

/****************************************************************************/

struct CacheNode
{
	struct SplayNode	cn_SplayNode;
	LONG				cn_Size;
	ULONG				cn_Checksum;
};

/****************************************************************************/

struct CacheContext
{
	struct FSPluginHook		cc_PluginHook;
	struct SignalSemaphore	cc_AccessSemaphore;
	struct Interrupt		cc_MemHandler;
	LONG					cc_BytesPerBlock;
	STRPTR					cc_DeviceName;
	LONG					cc_UnitNumber;
	PLUGIN_QUAD				cc_FirstSector;
	PLUGIN_QUAD				cc_LastSector;
	struct SplayTree		cc_ProtectedCacheTree;
	struct SplayTree		cc_ProbationCacheTree;
	struct MinList			cc_ProtectedCacheList;
	struct MinList			cc_ProbationCacheList;
	ULONG					cc_NumAccesses;
	ULONG					cc_NumHits;
	ULONG					cc_NumBytesAllocated;
	ULONG					cc_MaxBytesAllocated;
	ULONG					cc_NumCacheNodes;
	ULONG					cc_MaxCacheNodes;
	ULONG					cc_ProtectedCacheMax;
	ULONG					cc_ProtectedCacheSize;
	ULONG					cc_NumProtectedHits;
	ULONG					cc_NumProtectedMisses;
	ULONG					cc_ProbationCacheSize;
	ULONG					cc_NumProbationHits;
	ULONG					cc_NumProbationMisses;
	APTR					cc_Pool;
	struct Process *		cc_Parent;
	BOOL					cc_Corrupted;
	BOOL					cc_WriteAllocate;
	BOOL					cc_VerifyChecksums;
};

/****************************************************************************/

void tree_add(struct SplayTree *tree, struct SplayNode *new);
struct SplayNode *tree_remove(struct SplayTree *tree, ULONG key);
void tree_init(struct SplayTree *tree);
LONG cache_setup(struct CacheContext *cc, struct FSPluginSetupMsg *fspm);
LONG cache_purge(struct CacheContext *cc, struct FSPluginPurgeCacheMsg *unused_fspm);
LONG cache_retrieve(struct CacheContext *cc, struct FSPluginRetrieveMsg *fspm);
LONG cache_store(struct CacheContext *cc, struct FSPluginStoreMsg *fspm);
LONG cache_write(struct CacheContext *cc, struct FSPluginStoreMsg *fspm);
LONG cache_drop(struct CacheContext *cc, struct FSPluginDropMsg *fspm);

/****************************************************************************/

/* Simple top down splay, not requiring the key to be
 * in the tree.
 */
INLINE static struct SplayNode *
splay(struct SplayNode * t,ULONG key)
{
	struct SplayNode N,*l,*r,*y;

	memset(&N,0,sizeof(N));

	l = r = &N;

	while(key != t->sn_Key)
	{
		if(key < t->sn_Key)
		{
			if(t->sn_Left == NULL)
				break;

			if(key < t->sn_Left->sn_Key)
			{
				/* rotate right */
				y = t->sn_Left;
				t->sn_Left = y->sn_Right;
				y->sn_Right = t;
				t = y;

				if(t->sn_Left == NULL)
					break;
			}

			/* link right */
			r->sn_Left = t;
			r = t;
			t = t->sn_Left;
		}
		else
		{
			if(t->sn_Right == NULL)
				break;

			if(key > t->sn_Right->sn_Key)
			{
				/* rotate left */
				y = t->sn_Right;
				t->sn_Right = y->sn_Left;
				y->sn_Left = t;
				t = y;

				if(t->sn_Right == NULL)
					break;
			}

			/* link left */
			l->sn_Right = t;
			l = t;
			t = t->sn_Right;
		}
	}

	/* assemble */
	l->sn_Right	= t->sn_Left;
	r->sn_Left	= t->sn_Right;
	t->sn_Left	= N.sn_Right;
	t->sn_Right	= N.sn_Left;

	return(t);
}

/****************************************************************************/

/* Insert node into the splay tree. */
void
tree_add(struct SplayTree * tree,struct SplayNode * new)
{
	ASSERT(tree != NULL && new != NULL);

	if(tree->st_Root != NULL)
	{
		struct SplayNode * t;

		t = splay(tree->st_Root,new->sn_Key);

		if(new->sn_Key < t->sn_Key)
		{
			new->sn_Left	= t->sn_Left;
			new->sn_Right	= t;

			t->sn_Left = NULL;
		}
		else if (new->sn_Key > t->sn_Key)
		{
			new->sn_Right	= t->sn_Right;
			new->sn_Left	= t;

			t->sn_Right = NULL;
		}
		else
		{
			SHOWMSG("PANIC! duplicate block number in splay tree");
		}
	}
	else
	{
		new->sn_Left = new->sn_Right = NULL;
	}

	tree->st_Root = new;
}

/****************************************************************************/

/* Removes node from the tree if it's there. */
struct SplayNode *
tree_remove(struct SplayTree * tree,ULONG key)
{
	struct SplayNode * result = NULL;

	ASSERT(tree != NULL);

	if(tree->st_Root != NULL)
	{
		struct SplayNode * t;

		t = splay(tree->st_Root,key);

		if(t->sn_Key == key)
		{
			struct SplayNode * x;

			result = t;

			if(t->sn_Left == NULL)
			{
				x = t->sn_Right;
			}
			else
			{
				x = splay(t->sn_Left,key);

				x->sn_Right = t->sn_Right;
			}

			t = x;
		}

		tree->st_Root = t;
	}

	return(result);
}

/****************************************************************************/

/* Find a key in the tree; this is simply an exercise in following
 * the keys in a binary tree.
 */
INLINE static struct SplayNode *
tree_find(struct SplayTree * tree,ULONG key)
{
	struct SplayNode * found = NULL;
	struct SplayNode * t;

	ASSERT(tree != NULL);

	t = tree->st_Root;
	while(t != NULL)
	{
		if(key < t->sn_Key)
		{
			/* Key is smaller than the current node; move left
			 * to a smaller node value.
			 */
			t = t->sn_Left;
		}
		else if (key > t->sn_Key)
		{
			/* Key is greater than the current node; move right
			 * to a greater node value.
			 */
			t = t->sn_Right;
		}
		else
		{
			/* Found the key. */
			found = t;
			break;
		}
	}

	return(found);
}

/****************************************************************************/

/* Find a key in the tree, then splay the tree if a matching node is found. */
INLINE static struct SplayNode *
tree_find_and_splay(struct SplayTree * tree,ULONG key)
{
	struct SplayNode * found;

	ASSERT(tree != NULL);

	found = tree_find(tree,key);
	if(found != NULL && found != tree->st_Root)
		tree->st_Root = splay(tree->st_Root,key);

	return(found);
}

/****************************************************************************/

/* Initialize a splay tree to be empty. Very simple in operation. */
void
tree_init(struct SplayTree *tree)
{
	ASSERT( tree != NULL );

	tree->st_Root = NULL;
}

/****************************************************************************/

/* Move a node to the beginning of the list it is found
 * in (unless it's already there).
 */
INLINE static void
move_node_to_list_head(struct List * list,struct Node * node)
{
	if(node != list->lh_Head)
	{
		Remove(node);
		AddHead(list,node);
	}
}

/****************************************************************************/

INLINE static void
adjust_protected_cache_size(struct CacheContext * cc)
{
	struct CacheNode * cn;

	ENTER();

	while(cc->cc_ProtectedCacheSize >= cc->cc_ProtectedCacheMax)
	{
		cn = (struct CacheNode *)RemTail((struct List *)&cc->cc_ProtectedCacheList);
		if(cn != NULL)
		{
			tree_remove(&cc->cc_ProtectedCacheTree,cn->cn_SplayNode.sn_Key);
			cc->cc_ProtectedCacheSize--;

			AddHead((struct List *)&cc->cc_ProbationCacheList,(struct Node *)cn);
			tree_add(&cc->cc_ProbationCacheTree,(struct SplayNode *)cn);
			cc->cc_ProbationCacheSize++;
		}
		else
		{
			break;
		}
	}

	LEAVE();
}

/****************************************************************************/

INLINE static ULONG
calculate_checksum(ULONG * data,ULONG num_bytes)
{
	ULONG next_sum;
	ULONG sum;
	LONG num_longs;

	sum = 0;

	num_longs = num_bytes / sizeof(*data);

	while(num_longs-- > 0)
	{
		next_sum = sum + (*data++);
		if(next_sum < sum)
			next_sum++;

		sum = next_sum;
	}

	return(sum);
}

/****************************************************************************/

LONG
cache_setup(struct CacheContext * cc,struct FSPluginSetupMsg * fspm)
{
	LONG error = OK;

	ENTER();

	ObtainSemaphore(&cc->cc_AccessSemaphore);

	SHOWVALUE(fspm->fspm_BytesPerBlock);

	if(fspm->fspm_BytesPerBlock <= 0)
	{
		SHOWMSG("block size is too small");

		error = ERROR_INVALID_BLOCK_SIZE;
		goto out;
	}

	cc->cc_BytesPerBlock	= fspm->fspm_BytesPerBlock;
	cc->cc_DeviceName		= fspm->fspm_DeviceName;
	cc->cc_UnitNumber		= fspm->fspm_UnitNumber;
	cc->cc_FirstSector		= fspm->fspm_FirstSector;
	cc->cc_LastSector		= fspm->fspm_LastSector;

	cc->cc_MaxCacheNodes = cc->cc_MaxBytesAllocated / (sizeof(struct CacheNode) + cc->cc_BytesPerBlock);
	if(cc->cc_MaxCacheNodes == 0)
		cc->cc_MaxCacheNodes++;

	cc->cc_ProtectedCacheMax = cc->cc_MaxCacheNodes / 2;

 out:

	ReleaseSemaphore(&cc->cc_AccessSemaphore);

	RETURN(error);
	return(error);
}

LONG
cache_purge(struct CacheContext * cc,struct FSPluginPurgeCacheMsg * unused_fspm)
{
	struct CacheNode * cn;
	LONG error = OK;

	ENTER();

	ObtainSemaphore(&cc->cc_AccessSemaphore);

	/* First purge the probational segment. */
	while((cn = (struct CacheNode *)RemHead((struct List *)&cc->cc_ProbationCacheList)) != NULL)
		FreePooled(cc->cc_Pool,cn,cn->cn_Size);

	tree_init(&cc->cc_ProbationCacheTree);

	/* Then purge the protected segment. */
	while((cn = (struct CacheNode *)RemHead((struct List *)&cc->cc_ProtectedCacheList)) != NULL)
		FreePooled(cc->cc_Pool,cn,cn->cn_Size);

	tree_init(&cc->cc_ProtectedCacheTree);

	cc->cc_NumAccesses			= 0;
	cc->cc_NumHits				= 0;
	cc->cc_NumBytesAllocated	= 0;
	cc->cc_NumCacheNodes		= 0;
	cc->cc_ProtectedCacheSize	= 0;
	cc->cc_NumProtectedHits		= 0;
	cc->cc_NumProtectedMisses	= 0;
	cc->cc_ProbationCacheSize	= 0;
	cc->cc_NumProbationHits		= 0;
	cc->cc_NumProbationMisses	= 0;

	ReleaseSemaphore(&cc->cc_AccessSemaphore);

	RETURN(error);
	return(error);
}

LONG
cache_retrieve(struct CacheContext * cc,struct FSPluginRetrieveMsg * fspm)
{
	struct CacheNode * cn;
	LONG error;

	ENTER();

	ObtainSemaphoreShared(&cc->cc_AccessSemaphore);

	/* Bail out immediately if we are already in trouble. */
	if(cc->cc_Corrupted)
	{
		error = ERROR_BLOCK_NOT_FOUND;
		goto out;
	}

	cc->cc_NumAccesses++;

	/* First try to find the block in the probational segment of the cache. */
	cn = (struct CacheNode *)tree_remove(&cc->cc_ProbationCacheTree,fspm->fspm_Offset);
	if(cn != NULL)
	{
		cc->cc_NumProbationHits++;

		/* Remove the node from the probational segment and
		 * add it to the protected segment.
		 */
		Remove((struct Node *)cn);
		cc->cc_ProbationCacheSize--;

		AddHead((struct List *)&cc->cc_ProtectedCacheList,(struct Node *)cn);
		tree_add(&cc->cc_ProtectedCacheTree,&cn->cn_SplayNode);
		cc->cc_ProtectedCacheSize++;

		/* If there are more entries in the protected cache segment
		 * than there ought to be, move the least recently used
		 * entries into the probational segment.
		 */
		adjust_protected_cache_size(cc);
	}
	else
	{
		cc->cc_NumProbationMisses++;

		/* Second try: look for the block in the protected segment. */
		cn = (struct CacheNode *)tree_find_and_splay(&cc->cc_ProtectedCacheTree,fspm->fspm_Offset);
		if(cn != NULL)
		{
			/* Unless it's already there, put the cache node at
			 * the beginning of the list.
			 */
			move_node_to_list_head((struct List *)&cc->cc_ProtectedCacheList,(struct Node *)cn);

			cc->cc_NumProtectedHits++;
		}
		else
		{
			cc->cc_NumProtectedMisses++;

			D(("block %ld not in cache",fspm->fspm_Offset));

			error = ERROR_BLOCK_NOT_FOUND;
			goto out;
		}
	}

	cc->cc_NumHits++;

	/* Careful there: before we go any further, check if the cached data still
	 * looks good. It should not get corrupted.
	 */
	if(cc->cc_VerifyChecksums && calculate_checksum((ULONG *)(cn+1),(ULONG)cc->cc_BytesPerBlock) != cn->cn_Checksum)
	{
		D(("cached data for block %ld was corrupted!",fspm->fspm_Offset));

		/* Try to remove this entry. If this still works... */
		cn = (struct CacheNode *)tree_remove(&cc->cc_ProbationCacheTree,fspm->fspm_Offset);
		if(cn != NULL)
		{
			cc->cc_NumProbationHits++;

			cc->cc_ProbationCacheSize--;
		}
		else
		{
			cc->cc_NumProbationMisses++;

			cn = (struct CacheNode *)tree_remove(&cc->cc_ProtectedCacheTree,fspm->fspm_Offset);
			if(cn != NULL)
			{
				cc->cc_NumProtectedHits++;

				cc->cc_ProtectedCacheSize--;
			}
		}

		/* This ought to work. */
		if(cn != NULL)
		{
			LONG size;

			/* Remove the node from the associated list. */
			Remove((struct Node *)cn);

			size = cn->cn_Size;

			FreePooled(cc->cc_Pool,cn,size);

			cc->cc_NumBytesAllocated -= size;
			cc->cc_NumCacheNodes--;
		}

		/* Signal the parent process to exit. */
		cc->cc_Corrupted = TRUE;
		Signal((struct Task *)cc->cc_Parent,SIGBREAKF_CTRL_C);

		error = ERROR_BLOCK_NOT_FOUND;
		goto out;
	}

	/* NOTE: if the data pointer is NULL it means that the client
	 *       just wanted to know whether the data is in the cache
	 *       and is not interested in any data that might get
	 *       moved.
	 */
	if(fspm->fspm_Data != NULL)
		memcpy(fspm->fspm_Data,cn+1,(size_t)cc->cc_BytesPerBlock);

	error = OK;

 out:

	ReleaseSemaphore(&cc->cc_AccessSemaphore);

	RETURN(error);
	return(error);
}

LONG
cache_store(struct CacheContext * cc,struct FSPluginStoreMsg * fspm)
{
	struct CacheNode * cn;
	LONG error;

	ENTER();

	ObtainSemaphore(&cc->cc_AccessSemaphore);

	/* Bail out immediately if we are already in trouble. */
	if(cc->cc_Corrupted)
	{
		error = ERROR_BLOCK_NOT_FOUND;
		goto out;
	}

	cc->cc_NumAccesses++;

	/* We need to update the cache block or allocate another cache
	 * entry for it. First, try to find the block in the probational
	 * segment of the cache.
	 */
	cn = (struct CacheNode *)tree_remove(&cc->cc_ProbationCacheTree,fspm->fspm_Offset);
	if(cn != NULL)
	{
		cc->cc_NumProbationHits++;

		D(("updating cache block %ld",fspm->fspm_Offset));

		/* Remove the node from the probational segment and
		 * add it to the protected segment.
		 */
		Remove((struct Node *)cn);
		cc->cc_ProbationCacheSize--;

		AddHead((struct List *)&cc->cc_ProtectedCacheList,(struct Node *)cn);
		tree_add(&cc->cc_ProtectedCacheTree,&cn->cn_SplayNode);
		cc->cc_ProtectedCacheSize++;

		/* If there are more entries in the protected cache segment
		 * than there ought to be, move the least recently used
		 * entries into the probational segment.
		 */
		adjust_protected_cache_size(cc);

		cc->cc_NumHits++;
	}
	else
	{
		cc->cc_NumProbationMisses++;

		/* Try again; look into the protected segment of the cache tree. */
		cn = (struct CacheNode *)tree_find_and_splay(&cc->cc_ProtectedCacheTree,fspm->fspm_Offset);
		if(cn != NULL)
		{
			cc->cc_NumProtectedHits++;

			D(("updating cache block %ld",fspm->fspm_Offset));

			/* Unless it's already there, put the block at the
			 * beginning of the cache list.
			 */
			move_node_to_list_head((struct List *)&cc->cc_ProtectedCacheList,(struct Node *)cn);

			cc->cc_NumHits++;
		}
		else
		{
			BOOL recycle = TRUE;

			cc->cc_NumProtectedMisses++;

			/* Is there still room to add another entry to the
			 * local cache?
			 */
			if(cc->cc_NumCacheNodes < cc->cc_MaxCacheNodes)
			{
				LONG size;

				D(("adding new cache block %ld",fspm->fspm_Offset));

				size = sizeof(*cn) + cc->cc_BytesPerBlock;

				cn = AllocPooled(cc->cc_Pool,size);
				if(cn != NULL)
				{
					cn->cn_SplayNode.sn_Key	= fspm->fspm_Offset;
					cn->cn_Size				= size;

					/* Add the new entry to the probational segment of the cache. */
					AddHead((struct List *)&cc->cc_ProbationCacheList,(struct Node *)cn);
					tree_add(&cc->cc_ProbationCacheTree,(struct SplayNode *)cn);
					cc->cc_ProbationCacheSize++;

					cc->cc_NumBytesAllocated += size;
					cc->cc_NumCacheNodes++;

					recycle = FALSE;
				}
				else
				{
					SHOWMSG("not enough memory");
				}
			}
			else
			{
				SHOWMSG("not enough room for new cache block");
			}

			if(recycle)
			{
				struct SplayTree * tree;

				SHOWMSG("recycling least recently used cache block");

				/* Grab the least recently used entry from the cache.
				 * We first try the probational segment and then fall
				 * back to the protected segment (which then turns
				 * out not to be protected that well).
				 */
				cn = (struct CacheNode *)RemTail((struct List *)&cc->cc_ProbationCacheList);
				if(cn != NULL)
				{
					tree = &cc->cc_ProbationCacheTree;
					cc->cc_ProbationCacheSize--;
				}
				else
				{
					/* Try the protected cache segment. */
					cn = (struct CacheNode *)RemTail((struct List *)&cc->cc_ProtectedCacheList);
					if(cn == NULL)
					{
						SHOWMSG("no cache block to recycle");

						error = ERROR_NO_FREE_STORE;
						goto out;
					}

					tree = &cc->cc_ProtectedCacheTree;
					cc->cc_ProtectedCacheSize--;
				}

				/* Remove the splay node from the associated tree. */
				tree_remove(tree,cn->cn_SplayNode.sn_Key);

				D(("dropping cache block %ld",cn->cn_SplayNode.sn_Key));

				cn->cn_SplayNode.sn_Key = fspm->fspm_Offset;

				/* Put the entry into the probational cache. */
				AddHead((struct List *)&cc->cc_ProbationCacheList,(struct Node *)cn);
				tree_add(&cc->cc_ProbationCacheTree,(struct SplayNode *)cn);
				cc->cc_ProbationCacheSize++;
			}
		}
	}

	memcpy(cn+1,fspm->fspm_Data,(size_t)cc->cc_BytesPerBlock);

	if(cc->cc_VerifyChecksums)
		cn->cn_Checksum = calculate_checksum((ULONG *)(cn+1),(ULONG)cc->cc_BytesPerBlock);

	error = OK;

 out:

	ReleaseSemaphore(&cc->cc_AccessSemaphore);

	RETURN(error);
	return(error);
}

LONG
cache_update(struct CacheContext * cc,struct FSPluginStoreMsg * fspm)
{
	struct CacheNode * cn;
	LONG error;

	ENTER();

	cc->cc_NumAccesses++;

	/* We need to update the cache block. First, try to find the block
	 * in the probational segment of the cache.
	 */
	cn = (struct CacheNode *)tree_find(&cc->cc_ProbationCacheTree,fspm->fspm_Offset);
	if(cn != NULL)
	{
		cc->cc_NumProbationHits++;
	}
	else
	{
		cc->cc_NumProbationMisses++;

		/* Try again; look into the protected segment of the cache tree. */
		cn = (struct CacheNode *)tree_find(&cc->cc_ProtectedCacheTree,fspm->fspm_Offset);
		if(cn != NULL)
			cc->cc_NumProtectedHits++;
	}

	if(cn != NULL)
	{
		D(("updating cache block %ld",fspm->fspm_Offset));

		cc->cc_NumHits++;

		memcpy(cn+1,fspm->fspm_Data,(size_t)cc->cc_BytesPerBlock);

		if(cc->cc_VerifyChecksums)
			cn->cn_Checksum = calculate_checksum((ULONG *)(cn+1),(ULONG)cc->cc_BytesPerBlock);
	}

	error = OK;

 out:

	RETURN(error);
	return(error);
}

LONG
cache_write(struct CacheContext * cc,struct FSPluginStoreMsg * fspm)
{
	LONG error;

	ENTER();

	ObtainSemaphore(&cc->cc_AccessSemaphore);

	/* Bail out immediately if we are already in trouble. */
	if(cc->cc_Corrupted)
	{
		error = ERROR_BLOCK_NOT_FOUND;
		goto out;
	}

	/* Write allocation means that a block to be written will need to be
	 * stored in the cache, in case it might be needed later. While this
	 * strategy might work, it's possible that it is not appropriate for
	 * the kind of cache we are maintaining (write-through).
	 */
	if(cc->cc_WriteAllocate)
	{
		error = cache_store(cc,fspm);
	}
	else
	{
		/* OK, so we are in write-around mode. This means that unless a cache entry
		 * has already been allocated for the block to be stored, it will not end
		 * up changing anything in the cache.
		 */
		error = cache_update(cc,fspm);
	}

 out:

	ReleaseSemaphore(&cc->cc_AccessSemaphore);

	RETURN(error);
	return(error);
}

LONG
cache_drop(struct CacheContext * cc,struct FSPluginDropMsg * fspm)
{
	struct CacheNode * cn;
	LONG error;
	LONG size;

	ENTER();

	D(("dropping block %ld from cache",fspm->fspm_Offset));

	ObtainSemaphore(&cc->cc_AccessSemaphore);

	cc->cc_NumAccesses++;

	cn = (struct CacheNode *)tree_remove(&cc->cc_ProbationCacheTree,fspm->fspm_Offset);
	if(cn != NULL)
	{
		cc->cc_NumProbationHits++;

		cc->cc_ProbationCacheSize--;
	}
	else
	{
		cc->cc_NumProbationMisses++;

		cn = (struct CacheNode *)tree_remove(&cc->cc_ProtectedCacheTree,fspm->fspm_Offset);
		if(cn == NULL)
		{
			cc->cc_NumProtectedMisses++;

			error = ERROR_BLOCK_NOT_FOUND;
			goto out;
		}

		cc->cc_NumProtectedHits++;

		cc->cc_ProtectedCacheSize--;
	}

	cc->cc_NumHits++;

	/* Remove the node from the associated list. */
	Remove((struct Node *)cn);

	size = cn->cn_Size;

	FreePooled(cc->cc_Pool,cn,size);

	cc->cc_NumBytesAllocated -= size;
	cc->cc_NumCacheNodes--;

	error = OK;

 out:

	ReleaseSemaphore(&cc->cc_AccessSemaphore);

	RETURN(error);
	return(error);
}

/****************************************************************************/

STATIC LONG ASM
cache_hook_func(
	REG(a0,struct Hook *	hook),
    REG(a2,APTR				unused),
    REG(a1,LONG *			fspm))
{
	struct CacheContext * cc = hook->h_Data;
	LONG result;

	ENTER();

	switch(*fspm)
	{
		/* General initialization. */
		case fspm_setup:

			result = cache_setup(cc,(struct FSPluginSetupMsg *)fspm);
			break;

		/* Cleanup before shutdown. */
		case fspm_cleanup:

			result = OK;
			break;

		/* Release all the resources allocated for the cache. */
		case fspm_purge_cache:

			result = cache_purge(cc,(struct FSPluginPurgeCacheMsg *)fspm);
			break;

		/* Attempt to retrieve data from the cache. */
		case fspm_retrieve:

			result = cache_retrieve(cc,(struct FSPluginRetrieveMsg *)fspm);
			break;

		/* Store data in the cache which was read from disk. */
		case fspm_store:

			result = cache_store(cc,(struct FSPluginStoreMsg *)fspm);
			break;

		/* Store data in the cache which was just written to disk. */
		case fspm_write:

			result = cache_write(cc,(struct FSPluginStoreMsg *)fspm);
			break;

		/* Remove data from the cache. */
		case fspm_drop:

			result = cache_drop(cc,(struct FSPluginDropMsg *)fspm);
			break;

		default:

			D(("unknown plugin code %ld",*fspm));

			result = ERROR_ACTION_NOT_KNOWN;
			break;
	}

	RETURN(result);
	return(result);
}

/****************************************************************************/

STATIC LONG ASM
mem_handler(
	REG(a6,struct Library *			unused_sysbase),
	REG(a0,struct MemHandlerData *	memh),
	REG(a1,struct CacheContext *	cc))
{
	LONG result = MEM_DID_NOTHING;

	if(AttemptSemaphore(&cc->cc_AccessSemaphore))
	{
		if(memh->memh_RequestSize <= cc->cc_NumBytesAllocated)
		{
			struct CacheNode * cn;
			ULONG total_freed;
			LONG size;

			total_freed = 0;

			/* Drop entries from the probational segment first. If
			 * that is not enough, proceed to the protected
			 * segment.
			 */
			while(total_freed < memh->memh_RequestSize && (cn = (struct CacheNode *)RemTail((struct List *)&cc->cc_ProbationCacheList)) != NULL)
			{
				tree_remove(&cc->cc_ProbationCacheTree,cn->cn_SplayNode.sn_Key);
				cc->cc_ProbationCacheSize--;

				size = cn->cn_Size;

				FreePooled(cc->cc_Pool,cn,size);

				cc->cc_NumBytesAllocated -= size;
				cc->cc_NumCacheNodes--;

				total_freed += size;
			}

			while(total_freed < memh->memh_RequestSize && (cn = (struct CacheNode *)RemTail((struct List *)&cc->cc_ProtectedCacheList)) != NULL)
			{
				tree_remove(&cc->cc_ProtectedCacheTree,cn->cn_SplayNode.sn_Key);
				cc->cc_ProtectedCacheSize--;

				size = cn->cn_Size;

				FreePooled(cc->cc_Pool,cn,size);

				cc->cc_NumBytesAllocated -= size;
				cc->cc_NumCacheNodes--;

				total_freed += size;
			}

			D(("freed %lD bytes",total_freed));

			result = MEM_TRY_AGAIN;
		}
		else if (cc->cc_NumBytesAllocated > 0)
		{
			struct CacheNode * cn;

			SHOWMSG("freeing the entire cache");

			/* First free the probational segment. */
			while((cn = (struct CacheNode *)RemHead((struct List *)&cc->cc_ProbationCacheList)) != NULL)
				FreePooled(cc->cc_Pool,cn,cn->cn_Size);

			tree_init(&cc->cc_ProbationCacheTree);

			/* Then free the protected segment. */
			while((cn = (struct CacheNode *)RemHead((struct List *)&cc->cc_ProtectedCacheList)) != NULL)
				FreePooled(cc->cc_Pool,cn,cn->cn_Size);

			tree_init(&cc->cc_ProtectedCacheTree);

			cc->cc_NumBytesAllocated	= 0;
			cc->cc_NumCacheNodes		= 0;
			cc->cc_ProtectedCacheSize	= 0;
			cc->cc_ProbationCacheSize	= 0;
			cc->cc_NumHits				= 0;
			cc->cc_NumAccesses			= 0;
			cc->cc_NumProtectedHits		= 0;
			cc->cc_NumProtectedMisses	= 0;
			cc->cc_ProbationCacheSize	= 0;
			cc->cc_NumProbationHits		= 0;
			cc->cc_NumProbationMisses	= 0;

			result = MEM_ALL_DONE;
		}
		else
		{
			SHOWMSG("couldn't release any data...");
		}

		ReleaseSemaphore(&cc->cc_AccessSemaphore);
	}
	else
	{
		SHOWMSG("couldn't release any data...");
	}

	return(result);
}

/****************************************************************************/

int
main(int argc,char ** argv)
{
	struct
	{
		KEY		Device;
		NUMBER	CacheSize;
		NUMBER	ReadAhead;
		SWITCH	Quiet;
		SWITCH	WriteAround;
		SWITCH	NoChecksums;
	} args;

	const int puddle_size = 16384;
	struct TagItem tags[2];
	struct RDArgs * rda = NULL;
	struct CacheContext * cc = NULL;
	struct Interrupt * is = NULL;
	struct MsgPort * mp;
	BOOL debug_enabled = FALSE;
	ULONG signals;
	BOOL done;
	int result = RETURN_ERROR;

	SETPROGRAMNAME(argv[0]);
	SETDEBUGLEVEL(0);

	if(((struct Library *)SysBase)->lib_Version < 39)
	{
		STRPTR message = "This program requires Kickstart 3.0 or higher.\n";

		Write(Output(),message,strlen(message));
		goto out;
	}

	memset(&args,0,sizeof(args));

	rda = ReadArgs("DEVICE/A,S=CACHESIZE/K/N,R=READAHEAD/K/N,QUIET/S,WA=WRITEAROUND/S,NC=NOCHECKSUMS/S",(LONG *)&args,NULL);
	if(rda == NULL)
	{
		PrintFault(IoErr(),argv[0]);
		goto out;
	}

	mp = DeviceProc(args.Device);
	if(mp == NULL)
	{
		Printf("'%s' not found.\n",args.Device);
		goto out;
	}

	cc = AllocVec(sizeof(*cc),MEMF_ANY|MEMF_PUBLIC|MEMF_CLEAR);
	if(cc == NULL)
	{
		Printf("Not enough memory to set up cache for '%s'.\n",args.Device);
		goto out;
	}

	cc->cc_WriteAllocate = (args.WriteAround == FALSE);

	cc->cc_VerifyChecksums = (args.NoChecksums == FALSE);

	cc->cc_Parent = (struct Process *)FindTask(NULL);

	cc->cc_Pool = CreatePool(MEMF_ANY,puddle_size,puddle_size);
	if(cc->cc_Pool == NULL)
	{
		Printf("Not enough memory to create memory pool.\n");
		goto out;
	}

	cc->cc_PluginHook.fsp_VersionTag	= version_tag;
	cc->cc_PluginHook.fsp_Version		= PLUGIN_API_VERSION;
	cc->cc_PluginHook.fsp_Revision		= PLUGIN_API_REVISION;

	#if defined(__MORPHOS__)
	{
		cc->cc_PluginHook.fsp_Hook.h_Entry		= (HOOKFUNC)hookfuncentry;
		cc->cc_PluginHook.fsp_Hook.h_SubEntry	= (HOOKFUNC)cache_hook_func;
	}
	#else
	{
		cc->cc_PluginHook.fsp_Hook.h_Entry		= (HOOKFUNC)cache_hook_func;
		cc->cc_PluginHook.fsp_Hook.h_SubEntry	= (HOOKFUNC)NULL;
	}
	#endif /* __MORPHOS__ */

	cc->cc_PluginHook.fsp_Hook.h_Data	= cc;
	cc->cc_PluginHook.fsp_Type			= fspt_block_cache;

	if(args.ReadAhead != NULL && (*args.ReadAhead) > 0)
	{
		tags[0].ti_Tag	= FSPA_NumReadAheadBlocks;
		tags[0].ti_Data	= (*args.ReadAhead);
		tags[1].ti_Tag	= TAG_END;

		cc->cc_PluginHook.fsp_Options = tags;
	}

	InitSemaphore(&cc->cc_AccessSemaphore);

	NewList((struct List *)&cc->cc_ProtectedCacheList);
	tree_init(&cc->cc_ProtectedCacheTree);

	NewList((struct List *)&cc->cc_ProbationCacheList);
	tree_init(&cc->cc_ProbationCacheTree);

	if(args.CacheSize != NULL && (*args.CacheSize) > 0)
	{
		cc->cc_MaxBytesAllocated = (*args.CacheSize) * 1024;
	}
	else
	{
		D_S(struct InfoData,id);

		/* Find out how large the disk is, if that information
		 * is currently available.
		 */
		memset(id,0,sizeof(*id));
		DoPkt(mp,ACTION_DISK_INFO,MKBADDR(id),	0,0,0,0);

		/* About 1% of the disk size is allocated
		 * for the cache.
		 */
		cc->cc_MaxBytesAllocated = (id->id_NumBlocks / 100) * id->id_BytesPerBlock;
	}

	/* If the cache is too small, use a default value. */
	if(cc->cc_MaxBytesAllocated < 128 * 1024)
		cc->cc_MaxBytesAllocated = 128 * 1024;

	is = &cc->cc_MemHandler;

	#if defined(__amigaos4__)
	{
		is->is_Node.ln_Type	= NT_EXTINTERRUPT;
	}
	#else
	{
		is->is_Node.ln_Type	= NT_INTERRUPT;
	}
	#endif /* __amigaos4__ */
	
	is->is_Node.ln_Pri	= 50;
	is->is_Node.ln_Name	= args.Device;
	is->is_Code			= (VOID (*)())mem_handler;
	is->is_Data			= cc;

	AddMemHandler(is);

	SHOWMSG("adding the plugin");

	if(CANNOT DoPkt(mp,ACTION_ADD_PLUGIN,(LONG)&cc->cc_PluginHook,	0,0,0,0))
	{
		UBYTE error_message[80];

		Fault(IoErr(),NULL,error_message,sizeof(error_message));

		Printf("Could not install cache on '%s' (%s).\n",args.Device,error_message);
		goto out;
	}

	if(NOT args.Quiet)
	{
		Printf("Cache on '%s' installed (maximum size = %lD bytes); ^C to remove.\n",
			args.Device,cc->cc_MaxBytesAllocated);
	}

	do
	{
		done = FALSE;

		signals = Wait(SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_D | SIGBREAKF_CTRL_E | SIGBREAKF_CTRL_F);

		if(signals & SIGBREAKF_CTRL_C)
			done = TRUE;

		if(signals & SIGBREAKF_CTRL_D)
		{
			ULONG num_accesses;
			ULONG hit_ratio;
			LONG access_ratio;

			ObtainSemaphoreShared(&cc->cc_AccessSemaphore);

			if(cc->cc_NumAccesses > 0)
				access_ratio = (100 * cc->cc_NumHits) / cc->cc_NumAccesses;
			else
				access_ratio = 0;

			Printf("\nCache statistics for '%s':\n",args.Device);

			Printf("\t%lD bytes allocated, %lD bytes maximum (%ld%% used), %lD cache nodes in use\n",
				cc->cc_NumBytesAllocated,cc->cc_MaxBytesAllocated,
				(100 * cc->cc_NumBytesAllocated) / cc->cc_MaxBytesAllocated,cc->cc_NumCacheNodes);

			Printf("\t%lD accesses, %lD hits (%ld%% hit ratio)\n",
				cc->cc_NumAccesses,cc->cc_NumHits,access_ratio);

			num_accesses = cc->cc_NumProtectedHits + cc->cc_NumProtectedMisses;
			if(num_accesses > 0)
				hit_ratio = (100 * cc->cc_NumProtectedHits + (num_accesses-1)) / num_accesses;
			else
				hit_ratio = 0;

			Printf("\t%lD entries in protected segment (maximum = %lD, %ld%% used), %lD accesses / %lD misses (%ld%% hit ratio).\n",
				cc->cc_ProtectedCacheSize,
				cc->cc_ProtectedCacheMax,
				(100 * cc->cc_ProtectedCacheSize + cc->cc_ProtectedCacheMax-1) / cc->cc_ProtectedCacheMax,
				num_accesses,cc->cc_NumProtectedMisses,
				hit_ratio);

			num_accesses = cc->cc_NumProbationHits + cc->cc_NumProbationMisses;
			if(num_accesses > 0)
				hit_ratio = (100 * cc->cc_NumProbationHits + (num_accesses-1)) / num_accesses;
			else
				hit_ratio = 0;

			Printf("\t%lD entries in probational segment, %lD accesses / %lD misses (%ld%% hit ratio).\n",
				cc->cc_ProbationCacheSize,
				num_accesses,cc->cc_NumProbationMisses,
				hit_ratio);

			ReleaseSemaphore(&cc->cc_AccessSemaphore);
		}

		if(signals & SIGBREAKF_CTRL_E)
		{
			debug_enabled ^= TRUE;

			if(debug_enabled)
				SETDEBUGLEVEL(2);
			else
				SETDEBUGLEVEL(0);
		}

		if(signals & SIGBREAKF_CTRL_F)
		{
			ObtainSemaphore(&cc->cc_AccessSemaphore);

			cache_purge(cc,NULL);

			ReleaseSemaphore(&cc->cc_AccessSemaphore);

			Printf("Cache purged.\n");
		}
	}
	while(NOT done);

	SHOWMSG("removing the plugin");

	DoPkt(mp,ACTION_REMOVE_PLUGIN,(LONG)&cc->cc_PluginHook,	0,0,0,0);

	if(cc->cc_Corrupted)
	{
		Printf("\33[1mCAUTION!\33[0m Cache on '%s' removed due to memory corruption!\a\n",args.Device);

		result = RETURN_FAIL;
		goto out;
	}

	if(NOT args.Quiet)
		Printf("Cache on '%s' removed.\n",args.Device);

	result = RETURN_OK;

 out:

	if(is != NULL)
		RemMemHandler(is);

	if(cc != NULL)
	{
		if(cc->cc_Pool != NULL)
			DeletePool(cc->cc_Pool);

		FreeVec(cc);
	}

	FreeArgs(rda);

	return(result);
}
