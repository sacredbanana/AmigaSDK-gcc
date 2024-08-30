#ifndef EXEC_MEMORY_H
#define EXEC_MEMORY_H
/*
**    $VER: memory.h 53.29 (10.8.2015)
**
**    Definitions and structures used by the memory allocation system
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#elif defined(__SASC)
   #pragma msg 79 ignore push
#endif

/****** MemChunk ****************************************************/

struct MemChunk
{
    struct MemChunk * mc_Next;  /* pointer to next chunk */
    uint32            mc_Bytes; /* chunk byte size      */
};

/****** MemHeader ***************************************************/

struct MemHeader
{
    struct Node       mh_Node;
    uint16            mh_Attributes; /* characteristics of this region */
    struct MemChunk * mh_First;      /* first free region */
    APTR              mh_Lower;      /* lower memory bound */
    APTR              mh_Upper;      /* upper memory bound+1 */
    uint32            mh_Free;       /* total number of free bytes */
};

/****** MemEntry ****************************************************/

struct  MemEntry
{
    union
    {
        uint32 meu_Reqs; /* the AllocMem requirements */
        APTR   meu_Addr; /* the address of this memory region */
    }     me_Un;

    uint32 me_Length;    /* the length of this memory region */
};

#define me_un    me_Un        /* compatibility - do not use*/
#define me_Reqs  me_Un.meu_Reqs
#define me_Addr  me_Un.meu_Addr

/****** MemList *****************************************************/

/* Note: sizeof(struct MemList) includes the size of the first MemEntry! */
struct MemList
{
    struct Node     ml_Node;
    uint16          ml_NumEntries; /* number of entries in this struct */
    struct MemEntry ml_ME[1];      /* the first entry      */
};

#define ml_me ml_ME /* compatibility - do not use */

/*----- Memory Requirement Types ---------------------------*/
/*----- See the AllocMem() documentation for details--------*/

/*
 * MEMF_SHARED has replaced MEMF_PUBLIC for almost all applications,
 * starting with AmigaOS release 4.0. In order to help you build
 * and test software, you can #define one of the two preprocessor
 * symbols below:
 *
 *     __DISABLE_MEMF_PUBLIC
 *         The MEMF_PUBLIC symbol will not be defined, causing your
 *         compiler to print an error message where it is still
 *         referenced in your code. This can help in tracking down
 *         all the references to MEMF_PUBLIC, so that you can replace
 *         them with MEMF_SHARED where appropriate; do not forget to
 *         rebuild your code with the __DISABLE_MEMF_PUBLIC symbol
 *         taken out after you have made all the necessary changes!
 *
 *     __REPLACE_MEMF_PUBLIC
 *         The MEMF_PUBLIC symbol will be replaced with the definition
 *         of MEMF_SHARED. This has the effect of switching over all
 *         MEMF_PUBLIC references to MEMF_SHARED, an effect you could
 *         also achieve by a global search & replace operation performed
 *         on your source code. However, by defining __REPLACE_MEMF_PUBLIC
 *         in your build makefile and rebuilding your software, you can
 *         test the effects of the change to MEMF_SHARED much more
 *         easily. It is also helpful for software that needs to be built
 *         both for the 68k platform and the PowerPC.
 *
 * Note that these two symbol definitions are mutually exclusive!
 */

#define MEMF_ANY        (0UL    ) /* Any type of memory will do */
#define MEMF_PUBLIC     (1UL<< 0)
#define MEMF_CHIP       (1UL<< 1)
#define MEMF_FAST       (1UL<< 2)
#define MEMF_VIRTUAL    (1UL<< 3) /* Memory that is mapped/paged */
#define MEMF_EXECUTABLE (1UL<< 4) /* Memory that contains executable code */
#define MEMF_LOCAL      (1UL<< 8) /* Memory that does not go away at RESET */
#define MEMF_24BITDMA   (1UL<< 9) /* DMAable memory within
                                   * 24 bits of address */
#define MEMF_KICK       (1UL<<10) /* Memory that can be used for KickTags */
#define MEMF_PRIVATE    (1UL<<11) /* Memory that is only _visible_ to the
                                   * allocator task */
#define MEMF_SHARED     (1UL<<12) /* Memory that is visible and accessible
                                   * to all tasks */

#define MEMF_CLEAR      (1UL<<16) /* AllocMem: NULL out area before return */
#define MEMF_LARGEST    (1UL<<17) /* AvailMem: return the largest chunk size */
#define MEMF_REVERSE    (1UL<<18) /* AllocMem: allocate from the top down */
#define MEMF_TOTAL      (1UL<<19) /* AvailMem: return total size of memory */
#define MEMF_HWALIGNED  (1UL<<20) /* AllocMem: Allocate aligned to hardware
                                   *           page size */
#define MEMF_DELAYED    (1UL<<21) /* AllocMem: Delay physical memory mapping */
#define MEMF_CORE_RESIDENT \
                        (1UL<<22) /* Availmem: return only memory that is not
                                   *           paged out */
#define MEMF_NO_EXPUNGE (1UL<<31) /* AllocMem: Do not cause expunge
                                   *           on failure */

/* Change the definition of MEMF_PUBLIC, as requested. */
#ifdef  __DISABLE_MEMF_PUBLIC
#ifndef __REPLACE_MEMF_PUBLIC
#undef MEMF_PUBLIC
#else
#error You can define either __DISABLE_MEMF_PUBLIC or __REPLACE_MEMF_PUBLIC but not both
#endif /* __REPLACE_MEMF_PUBLIC */
#endif /* __DISABLE_MEMF_PUBLIC */

#ifdef __REPLACE_MEMF_PUBLIC
#undef  MEMF_PUBLIC
#define MEMF_PUBLIC MEMF_SHARED
#endif /* __REPLACE_MEMF_PUBLIC */

/*----- Current alignment rules for memory blocks (may increase) -----*/
#define MEM_BLOCKSIZE (16UL)
#define MEM_BLOCKMASK (MEM_BLOCKSIZE-1)


/****** MemHandlerData **********************************************/
/* Note:  This structure is *READ ONLY* and only EXEC can create it!*/
struct MemHandlerData
{
    uint32 memh_RequestSize;  /* Requested allocation size */
    uint32 memh_RequestFlags; /* Requested allocation flags */
    uint32 memh_Flags;        /* Flags (see below) */
};

#ifdef __OBSOLETE_MEMHANDLER_FLAGS__
/* With exec.library 51.48 and higher, this flag is not set anymore */
enum enMemHandlerFlags
{
    MEMHF_RECYCLE = (1L<<0)  /* 0==First time, 1==recycle */
};
#endif

/****** Low Memory handler return values ***************************/
enum enMemHandlerActions
{
    MEM_DID_NOTHING = ( 0), /* Nothing we could do... */
    MEM_ALL_DONE    = (-1), /* We did all we could do */
    MEM_TRY_AGAIN   = ( 1)  /* We did some, try the allocation again */
};

/****** Memory attributes ******************************************/
enum enMemAttrs
{
    MEMATTRF_WRITETHROUGH     = (1L<< 0), /* Stores in this area update cache
                                           * and memory */
    MEMATTRF_CACHEINHIBIT     = (1L<< 1), /* Caches are inhibited in this
                                           * area */
    MEMATTRF_COHERENT         = (1L<< 2), /* Coherency required, stores to
                                           * same region will be serialized */
    MEMATTRF_GUARDED          = (1L<< 3), /* Ensure in-order execute of memory
                                           * accesses */

    MEMATTRF_REFERENCED       = (1L<< 4), /* Page containing memory location
                                           * has been referenced (used) */
    MEMATTRF_CHANGED          = (1L<< 5), /* Page containing memory location
                                           * has been changed */

    /* The following are mutually exclusive */
    MEMATTRF_SUPER_RW         = (0L<< 6),
    MEMATTRF_SUPER_RW_USER_RO = (1l<< 6),
    MEMATTRF_SUPER_RW_USER_RW = (2l<< 6),
    MEMATTRF_SUPER_RO_USER_RO = (3l<< 6),
    MEMATTRF_RW_MASK          = (3l<< 6),

    MEMATTRF_EXECUTE          = (1L<< 9), /* CPU can execute instructions
                                           * from this memory */

    MEMATTRF_NOT_MAPPED       = (1L<<10), /* Special flag: The memory is not
                                           * mapped at all. This flag is only
                                           * used as return value of
                                           * GetMemoryAttr */
    MEMATTRF_RESERVED1        = (1L<<11), /* Used by the system */
    MEMATTRF_RESERVED2        = (1L<<12), /* _NEVER_ use these */
    MEMATTRF_RESERVER3        = (1L<<13),
};

/* Short forms for common cases */
#define MEMATTRF_READ_WRITE MEMATTRF_SUPER_RW_USER_RW
#define MEMATTRF_READ_ONLY  MEMATTRF_SUPER_RO_USER_RO

/****** GetMemoryAttrs flags ******************************************/
enum enGetMemoryAttrsFlags
{
    GMAF_REPORT_CR = (1L<<0)
};

/****** AllocSysObject flags ******************************************/
enum enAllocSysObjectFlags
{
    ASOF_NOTRACK = (1L<<1) /* Used internally to indicate
                            * no tracking of object */
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#elif defined(__SASC)
   #pragma msg 79 pop
#endif

/* Warning: Everything below default alignend */

/****** Trackable ***************************************************/

/*
 * Warning:
 * Do NOT allocate one of those yourself!
 */

struct Trackable
{
    struct Hook        Destructor;
    APTR               Object;
    uint32             Flags;
    struct Trackable * HashChain;
    /* Long word aligned */
};

enum enTrackableFlags
{
    TRACKF_COMPACT = (1L<<0) /* Trackable was allocated by "constructor" */
};

/****** DMA Scatter list ********************************************/

struct DMAEntry
{
    APTR   PhysicalAddress; /* Physically mapped address */
    uint32 BlockLength;     /* Length of the block in physical memory */
};


/****** Named memory scan message ********************************************/

struct SNMMessage
{
	STRPTR      Namespace;
	STRPTR      Name;
	APTR        Memory;
	uint32      Size;
	uint32      Flags;
};

#define SNMF_NAMESPACES_ONLY   (1L << 0)

/****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_MEMORY_H */
