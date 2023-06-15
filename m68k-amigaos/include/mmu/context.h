/*************************************************************************
 ** mmu.library                                                         **
 **                                                                     **
 ** a system library for arbitration and control of the MC68K MMUs      **
 **                                                                     **
 ** © 1998 THOR-Software, Thomas Richter                                **
 ** No commercial use, reassembly, modification without prior, written  **
 ** permission of the authors.                                          **
 ** Including this library in any commercial software REQUIRES a        **
 ** written permission and the payment of a small fee.                  **
 **                                                                     **
 **---------------------------------------------------------------------**
 ** context related definitions                                         **
 **									**
 ** $VER: 46.2 (06.08.2016)						**
 *************************************************************************/

#ifndef MMU_CONTEXT_H
#define MMU_CONTEXT_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/* A context keeps roughly speaking an MMU table. Lovers of unix might
   want to use the name "process" instead, whereas an exec task or
   a dos.library process might be called "a thread".
   All tasks sharing one context share one logical addressing space. */

/* The definition of the context structure: This is something you do
   not care about. */

struct MMUContext {
        struct MMUContext       *ctx_succ;      /* A doubly linked list */
        struct MMUContext       *ctx_pred;
        /* private data here. Do not touch, modify, .... */     
};

/* The definition of a context window. This structure is used to identify
   the active context within a MAPP_WINDOW region, and to distinguish
   multiple distinct windows.
*/

struct ContextWindow {
	struct MMUContext	*cwn_Active;	/* active context, or NULL */
	/* private data here. Do not touch. */
};


/* A mapping node, used to define the address space. This is what you find
   in the list arbitrated by GetMapping().

   This structure is stricly READ ONLY */

struct MappingNode {
        struct MappingNode     *map_succ;
        struct MappingNode     *map_pred;
        
        ULONG            map_Lower;     /* lower address this node covers. */
        ULONG            map_Higher;    /* higher address, inclusive */
        ULONG            map_Flags;     /* internal use only. */
        ULONG            map_Properties;        /* see below for definitions */
        union {
                void    *map_UserData;  /* your data if this is invalid or swapped */
                void    *map_Page;      /* destination page if bundled */
                LONG    *map_Descriptor;/* pointer to a descriptor, alternatively */
                LONG    map_Delta;      /* added to the logical address if remapped */
		ULONG	map_Mask;	/* property mask for MAPP_SHARED */
        }                map_un;
};



/* Property types:
   These define the "property flags" you may assign to memory with
   SetProperties() and SetPageProperties(). */

#define MAPP_WRITEPROTECTED     (1<<2L)
#define MAPB_WRITEPROTECTED     (2L)
/* The region is write protected and the segmentation fault exception hooks 
   will be called on a write access. */

#define MAPP_USED               (1<<3L)
#define MAPB_USED               (3L)
/* Set by the MMU on access, querried by GetPageProperties(). */

#define MAPP_MODIFIED           (1<<4L)
#define MAPB_MODIFIED           (4L)
/* Set by the MMU on write accesses, querried by GetPageProperties(). */

#define MAPP_CACHEINHIBIT       (1<<6L)
#define MAPB_CACHEINHIBIT       (6L)
/* Region is cache-inhibited, by default serialized access, precise
   exception mode */

#define MAPP_SUPERVISORONLY     (1<<7L)
#define MAPB_SUPERVISORONLY     (7L)
/* Supervisor access only. Note that this is currently implemented by
   marking the pages as invalid in the user MMU tables, not by setting
   the supervisor bit. */

#define MAPP_USERPAGE0          (1<<8L)
#define MAPB_USERPAGE0          (8L)
/* User page attribute 0, used only by 68040, 68060.
   These bits are available at special pins of the CPU,
   special hardware might require this. */

#define MAPP_USERPAGE1          (1<<9L)
#define MAPB_USERPAGE1          (9L)
/* User page attribute 1 */

#define MAPP_GLOBAL             (1<<10L)
#define MAPB_GLOBAL             (10L)
/* This memory region is global. The MMU library makes currently no
   effective use of this flag, and it makes only a difference for the
   040 and 060 anyhow. */

#define MAPP_BLANK              (1<<11L)
#define MAPB_BLANK              (11L)
/* There's no memory here. If accessed, the access is quietly tolerated, 
   even though nothing useful should be expected. This is mainly to work
   around bad software if no enforcer is available. */

#define MAPP_SINGLEPAGE         (1<<12L)
#define MAPB_SINGLEPAGE         (12L)
/* Give this page a private page descriptor. This flag IS A MUST
   if you want to use GetPagePropertiesA/SetPagePropertiesA on
   that page.  */

#define MAPP_COPYBACK           (1<<13L)
#define MAPB_COPYBACK           (13L)
/* MC68040 or MC68060 advanced copyback mode enabled. The library sets this
   by default for all non-chip memory. */

#define MAPP_INVALID            (1<<14L)
#define MAPB_INVALID            (14L)
/* The page is invalid. Accessing it results in a segmentation fault, i.e.
   the library will call the appropriate exception hooks. */

#define MAPP_REMAPPED           (1<<15L)
#define MAPB_REMAPPED           (15L)
/* Page is redirected to a different memory region. Note that you MUST NOT
   add this memory to the exec library free memory list because some DMA
   devices don't support I/O from this region and the MMU library will
   guru as soon as you try to place MMU tables in remapped memory. 
   This might change in the future. */

#define MAPP_SWAPPED            (1<<16L)
#define MAPB_SWAPPED            (16L)
/* This page is currently swapped out. If a program accesses this, a 
   swapped-out fault is generated. UserData is available for a swapper 
   daemon, usually the memory.library. */

#define MAPP_ROM                (1<<17L)
#define MAPB_ROM                (17L)
/* This is read-only memory, but the library tolerates write accesses 
   quietly and no hook is called on writes. Hence, this turns the memory
   region effectively into a "ROM". */

#define MAPP_SHARED             (1<<18L)
#define MAPB_SHARED             (18L)
/* Shares the table of the parent context. Only if this context is
   allocated as child context of a share-able context. */

#define MAPP_TRANSLATED         (1<<19L)
#define MAPB_TRANSLATED         (19L)
/* This memory region is - probably partially - under control of the 
   transparent translation registers and should not be touched. 
   The mmu library does not handle the transparent translation very well
   and tries to get rid of them on startup. */

#define MAPP_REPAIRABLE         (1<<20L)
#define MAPB_REPAIRABLE         (20L)
/* This flag allows invalid or write protected pages to get repaired on
   a fault by software rather than by swapping in a page. 
   The mmu.library will try to make the written data available to the 
   exception hook, and will try to provide readback data for the input 
   pipeline of the CPU. Note that this is very useful for debugging tools 
   and the like, but causes quite a lot of overhead.
   Furthermore, MAPP_REPAIRABLE pages do not get user data. */

#define MAPP_IMPRECISE          (1<<21L)
#define MAPB_IMPRECISE          (21L)
/* If non-cacheable, allow imprecise exception mode */

#define MAPP_INDIRECT           (1<<22L)
#define MAPB_INDIRECT           (22L)
/* Indirect table pointer to a user-provided table. Note that the mmu library
   exception handler returns always a pointer to the descriptor pointing to
   your descriptor, not to your descriptor directly. */

#define MAPP_BUNDLED            (1<<23L)
#define MAPB_BUNDLED            (23L)
/* Several pages bundled to one physical page in memory, usually done to 
   map out memory. */

#define MAPP_USER0              (1<<24L)
#define MAPB_USER0              (24L)
#define MAPP_USER1              (1<<25L)
#define MAPB_USER1              (25L)
#define MAPP_USER2              (1<<26L)
#define MAPB_USER2              (26L)
#define MAPP_USER3              (1<<27L)        
#define MAPB_USER3              (27L)
/* Strictly for you. Not touched by the library. */

#define MAPP_NONSERIALIZED      (1<<29L)
#define MAPB_NONSERIALIZED      (29L)
/* If non-cacheable, allow non-serialized access */

#define MAPP_IO           	(1<<30L)
#define MAPB_IO           	(30L)
/* I/O hardware. Avoid reading/writing this if you can avoid it. */

#define MAPP_WINDOW             (1<<31L)
#define MAPB_WINDOW		(31L)
/* A window other contexts can map their mapping into. */


/* error codes CreateMMUContext may generate: */

#define CCERR_TRIMMED   		1	
/* The MMU table has been trimmed to keep care about the enlarged 
   table size. THIS IS NOT AN ERROR. */

#define CCERR_UNALIGNED         	3    
/* The MMU library had to perform some heavy rounding, as for
   example to MAPP_REMAPPED pages. Therefore, the mapping 
   might be partially wrong. You possibly do not want to use
   this setup. */

#define CCERR_NO_FREE_STORE     	103
/* Out of memory. */

#define CCERR_INVALID_PARAMETERS	513
/* Specified parameters are invalid. */

#define CCERR_UNSUPPORTED		514         
/* The parameters are valid, but not supported by the 
   available hardware. */

#define	CCERR_SHARENCOPY		515             
/* tried to share and copy a context simulatenously, 
   this cannot work. */

#define CCERR_NOTSHAREABLE		516
/* the selected base context is not shareable. */

#define CCERR_SHAREOVERLEVELS		517         
/* tried to make a ctx shareable that shares another context
   already. Sharing does not allow building of trees. */

#define CCERR_NOPRIVSUPER		518
/* sharing or shared contexts cannot have private supervisors. */

#endif
