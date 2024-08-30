        IFND MMU_CONTEXT_I
MMU_CONTEXT_I   SET     1
;*************************************************************************
;** mmu.library                                                         **
;**                                                                     **
;** a system library for arbitration and control of the MC68K MMUs      **
;**                                                                     **
;** © 1998 THOR-Software, Thomas Richter                                **
;** No commercial use, reassembly, modification without prior, written  **
;** permission of the authors.                                          **
;** Including this library in any commercial software REQUIRES a        **
;** written permission and the payment of a small fee.                  **
;**                                                                     **
;**---------------------------------------------------------------------**
;** context related definitions                                         **
;**                                                                     **
;** $VER: 46.2 (06.08.2016)                                              **
;*************************************************************************

        IFND EXEC_TYPES_I
        INCLUDE "exec/types.i"
        ENDC

;* A context keeps roughly speaking an MMU table. Lovers of unix might
;* want to use the name "process" instead, whereas an exec task or
;* a dos.library process might be called "a thread".
;* All tasks sharing one context share one logical addressing space. *

;* The definition of the context structure: This is something you do
;* not care about. *

        STRUCTURE MMUContext,0
        APTR    ctx_succ                ;struct MMUContext *
        APTR    ctx_pred                ;struct MMUContext *
        ;* private data here. Do not touch, modify, .... *
        LABEL ctx_SIZE

;* The definition of a context window. This structure is used to identify
;* the active context within a MAPP_WINDOW region, and to distinguish
;* multiple distinct windows.

	STRUCTURE ContextWindow,0
	APTR	cwn_Active		;* active context, or NULL
	;* private data below this point. Do not touch. *
	LABEL	cwn_SIZE

;* A mapping node, used to define the address space. This is what you find
;* in the list arbitrated by GetMapping().

;* This structure is stricly READ ONLY *

        STRUCTURE MappingNode,0
        APTR    map_succ                ;struct MappingNode *
        APTR    map_pred                ;struct MappingNode *
        
        ULONG   map_Lower               ;* lower address this node covers. *
        ULONG   map_Higher              ;* higher address, inclusive *
        ULONG   map_Flags               ;* internal use only. *
        ULONG   map_Properties          ;* see below for definitions *

        ;* the next one is a big union. All entries share the same location
        LABEL   map_UserData            ;* your data if this is invalid or swapped *
        LABEL   map_Page                ;* destination page if bundled *
        LABEL   map_Descriptor          ;* pointer to a descriptor, alternatively *
        LABEL   map_Delta               ;* added to the logical address if remapped *
        ULONG   map_Mask                ;* property mask for MAPP_SHARE *

        LABEL   map_SIZE



;* Property types:
;* These define the "property flags" you may assign to memory with
;* SetProperties() and SetPageProperties(). *

MAPP_WRITEPROTECTED     equ     (1<<2)
MAPB_WRITEPROTECTED     equ     2
;* The region is write protected and the segmentation fault exception hooks
;* will be called on a write access. *

MAPP_USED               equ     (1<<3)
MAPB_USED               equ     3
;* Set by the MMU on access, querried by GetPageProperties(). *

MAPP_MODIFIED           equ     (1<<4)
MAPB_MODIFIED           equ     4
;* Set by the MMU on write accesses, querried by GetPageProperties(). *

MAPP_CACHEINHIBIT       equ     (1<<6)
MAPB_CACHEINHIBIT       equ     6
;* Region is cache-inhibited, by default serialized access, precise
;* exception mode *

MAPP_SUPERVISORONLY     equ     (1<<7)
MAPB_SUPERVISORONLY     equ     7
;* Supervisor access only. Note that this is currently implemented by
;* marking the pages as invalid in the user MMU tables, not by setting
;* the supervisor bit. *

MAPP_USERPAGE0          equ     (1<<8)
MAPB_USERPAGE0          equ     8
;* User page attribute 0, used only by 68040, 68060.
;* These bits are available at special pins of the CPU,
;* special hardware might require this. *

MAPP_USERPAGE1          equ     (1<<9)
MAPB_USERPAGE1          equ     9
;* User page attribute 1 *

MAPP_GLOBAL             equ     (1<<10)
MAPB_GLOBAL             equ     10
;* This memory region is global. The MMU library makes currently no
;* effective use of this flag, and it makes only a difference for the
;* 040 and 060 anyhow. *

MAPP_BLANK              equ     (1<<11)
MAPB_BLANK              equ     11
;* There's no memory here. If accessed, the access is quietly tolerated,
;* even though nothing useful should be expected. This is mainly to work
;* around bad software if no enforcer is available. *

MAPP_SINGLEPAGE         equ     (1<<12)
MAPB_SINGLEPAGE         equ     12
;* Give this page a private page descriptor. This flag IS A MUST
;* if you want to use GetPagePropertiesA/SetPagePropertiesA on
;* that page.  *

MAPP_COPYBACK           equ     (1<<13)
MAPB_COPYBACK           equ     13
;* MC68040 or MC68060 advanced copyback mode enabled. The library sets this
;* by default for all non-chip memory. *

MAPP_INVALID            equ     (1<<14)
MAPB_INVALID            equ     14
;* The page is invalid. Accessing it results in a segmentation fault, i.e.
;* the library will call the appropriate exception hooks. *

MAPP_REMAPPED           equ     (1<<15)
MAPB_REMAPPED           equ     15
;* Page is redirected to a different memory region. Note that you MUST NOT
;* add this memory to the exec library free memory list because some DMA
;* devices don't support I/O from this region and the MMU library will
;* guru as soon as you try to place MMU tables in remapped memory.
;* This might change in the future. *

MAPP_SWAPPED            equ     (1<<16)
MAPB_SWAPPED            equ     16
;* This page is currently swapped out. If a program accesses this, a
;* swapped-out fault is generated. UserData is available for a swapper
;* daemon, usually the memory.library. *

MAPP_ROM                equ     (1<<17)
MAPB_ROM                equ     17
;* This is read-only memory, but the library tolerates write accesses
;* quietly and no hook is called on writes. Hence, this turns the memory
;* region effectively into a "ROM". *

MAPP_SHARED             equ     (1<<18)
MAPB_SHARED             equ     18
;* Shares the table of the parent context. Only if this context is
;* allocated as child context of a share-able context. *

MAPP_TRANSLATED         equ     (1<<19)
MAPB_TRANSLATED         equ     19
;* This memory region is - probably partially - under control of the
;* transparent translation registers and should not be touched.
;* The mmu library does not handle the transparent translation very well
;* and tries to get rid of them on startup. *

MAPP_REPAIRABLE         equ     (1<<20)
MAPB_REPAIRABLE         equ     20
;* This flag allows invalid or write protected pages to get repaired on
;* a fault by software rather than by swapping in a page.
;* The mmu.library will try to make the written data available to the
;* exception hook, and will try to provide readback data for the input
;* pipeline of the CPU. Note that this is very useful for debugging tools
;* and the like, but causes quite a lot of overhead.
;* Furthermore, MAPP_REPAIRABLE pages do not get user data. *

MAPP_IMPRECISE          equ     (1<<21)
MAPB_IMPRECISE          equ     21
;* If non-cacheable, allow imprecise exception mode *

MAPP_INDIRECT           equ     (1<<22)
MAPB_INDIRECT           equ     22
;* Indirect table pointer to a user-provided table. Note that the mmu library
;* exception handler returns always a pointer to the descriptor pointing to
;* your descriptor, not to your descriptor directly. *

MAPP_BUNDLED            equ     (1<<23)
MAPB_BUNDLED            equ     23
;* Several pages bundled to one physical page in memory, usually done to
;* map out memory. *

MAPP_USER0              equ     (1<<24)
MAPB_USER0              equ     24
MAPP_USER1              equ     (1<<25)
MAPB_USER1              equ     25
MAPP_USER2              equ     (1<<26)
MAPB_USER2              equ     26
MAPP_USER3              equ     (1<<27)
MAPB_USER3              equ     27
;* Strictly for you. Not touched by the library. *

MAPP_NONSERIALIZED      equ     (1<<29)
MAPB_NONSERIALIZED      equ     29
;* If non-cacheable, allow non-serialized access *

MAPP_IO                 equ     (1<<30)
MAPB_IO                 equ     30
;* I/O hardware. Avoid reading/writing this if you can avoid it. *

MAPP_WINDOW             equ     (1<<31)
MAPB_WINDOW             equ     31
;* a window drilled into the context, where another context
;* is then mapped in. *

;* error codes CreateMMUContext may generate: *

CCERR_TRIMMED                   equ     1
;* The MMU table has been trimmed to keep care about the enlarged 
;* table size. THIS IS NOT AN ERROR. *

CCERR_UNALIGNED                 equ     3    
;* The MMU library had to perform some heavy rounding, as for
;* example to MAPP_REMAPPED pages. Therefore, the mapping 
;* might be partially wrong. You possibly do not want to use
;* this setup. *

CCERR_NO_FREE_STORE             equ     103
;* Out of memory. *

CCERR_INVALID_PARAMETERS        equ     513
;* Specified parameters are invalid. *

CCERR_UNSUPPORTED               equ     514         
;* The parameters are valid, but not supported by the 
;* available hardware. *

CCERR_SHARENCOPY                equ     515             
;* tried to share and copy a context simulatenously, 
;* this cannot work. *

CCERR_NOTSHAREABLE              equ     516
;* the selected base context is not shareable. *

CCERR_SHAREOVERLEVELS           equ     517         
;* tried to make a ctx shareable that shares another context
;* already. Sharing does not allow building of trees. *

CCERR_NOPRIVSUPER               equ     518
;* sharing or shared contexts cannot have private supervisors. *

        ENDC    ;       MMU_CONTEXT_I
