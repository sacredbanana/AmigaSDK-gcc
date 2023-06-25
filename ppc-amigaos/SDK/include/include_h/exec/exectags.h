#ifndef EXEC_EXECTAGS_H
#define EXEC_EXECTAGS_H
/*
**    $VER: exectags.h 53.29 (10.8.2015)
**
**    Defines tag items for various functions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/*
 * Tag items used by AllocSysObject
 */

#define ASO_NoTrack         (TAG_USER +  1) /* Don't track this object (i.e. do not free automatically) */
#define ASO_MemoryOvr       (TAG_USER +  2) /* Memory type override */

/* IORequest */
#define ASOIOR_Size         (TAG_USER + 10) /* Size of the object */
#define ASOIOR_ReplyPort    (TAG_USER + 11) /* ReplyPort to use */
#define ASOIOR_Duplicate    (TAG_USER + 12) /* Source IO request to duplicate */

/* Hook */
#define ASOHOOK_Size        (TAG_USER + 10) /* Size of the object */
#define ASOHOOK_Entry       (TAG_USER + 11) /* The hook's entry */
#define ASOHOOK_Subentry    (TAG_USER + 12) /* The hook's subentry field */
#define ASOHOOK_Data        (TAG_USER + 13) /* The hook's user data */

/* Interrupt */
#define ASOINTR_Size        (TAG_USER + 10) /* Size of the object */
#define ASOINTR_Code        (TAG_USER + 11) /* Code pointer */
#define ASOINTR_Data        (TAG_USER + 12) /* Data pointer */
#define ASOINTR_SoftInt		(TAG_USER + 13) /* Interrupt is used by Cause() */

/* List */
#define ASOLIST_Size        (TAG_USER + 10) /* Size of the object */
#define ASOLIST_Type        (TAG_USER + 11) /* Type to set for the list */
#define ASOLIST_Min         (TAG_USER + 12) /* Create a minlist */

/* DMAEntry array */
#define ASODMAE_Size        (TAG_USER + 10) /* Raw size of the object */
#define ASODMAE_NumEntries  (TAG_USER + 11) /* Number of entries */

/* List node */
#define ASONODE_Size        (TAG_USER + 10) /* Size of the node */
#define ASONODE_Min         (TAG_USER + 11) /* Make it a MinNode */
#define ASONODE_Type        (TAG_USER + 12) /* Node's type */
#define ASONODE_Pri         (TAG_USER + 13) /* Node's priority */
#define ASONODE_Name        (TAG_USER + 14) /* Pointer to a node string */

/* Message port */
#define ASOPORT_Size        (TAG_USER + 10) /* Size of the object */
#define ASOPORT_AllocSig    (TAG_USER + 11) /* Allocate a signal */
#define ASOPORT_Action      (TAG_USER + 12) /* Action at message arrival (see ports.h, enMsgPortActions) */
#define ASOPORT_Pri         (TAG_USER + 13) /* Priority used when the port is added to a list */
#define ASOPORT_Name        (TAG_USER + 14) /* Name for the port */
#define ASOPORT_Signal      (TAG_USER + 15) /* Preallocted signal number */
#define ASOPORT_Target      (TAG_USER + 16) /* MsgPort's target, either a task, or a softint */
#define ASOPORT_Public      (TAG_USER + 17) /* Make the port public */
#define ASOPORT_CopyName    (TAG_USER + 18) /* Copy the name string */


/* Message */
#define ASOMSG_Size         (TAG_USER + 10) /* Size of the object */
#define ASOMSG_ReplyPort    (TAG_USER + 11) /* Reply port */
#define ASOMSG_Length       (TAG_USER + 12) /* Message length */
#define ASOMSG_Name         (TAG_USER + 13) /* Name to put into the node */

/* Signal semaphore */
#define ASOSEM_Size         (TAG_USER + 10) /* Size of the object */
#define ASOSEM_Name         (TAG_USER + 11) /* Name */
#define ASOSEM_Pri          (TAG_USER + 12) /* Node's priority (only used on public semaphores) */
#define ASOSEM_Public       (TAG_USER + 13) /* Semaphore is public and will be added to the system */
#define ASOSEM_CopyName     (TAG_USER + 14) /* Copy the name string */

/* TagItem array */
#define ASOTAGS_Size        (TAG_USER + 10) /* Raw size of the object, i.e. in bytes */
#define ASOTAGS_NumEntries  (TAG_USER + 11) /* Number of tagitems */

/* Memory Pool */
#define ASOPOOL_MFlags      (TAG_USER + 10) /* Memory flags/requirements for this pool */
#define ASOPOOL_Puddle      (TAG_USER + 11) /* Size of each puddle */
#define ASOPOOL_Threshold   (TAG_USER + 12) /* Largest alloction size that goes into the puddle */
#define ASOPOOL_Protected   (TAG_USER + 13) /* Protect pool with a semaphore */
#define ASOPOOL_Name        (TAG_USER + 14) /* Name for the pool (for informational purpose only) */
#define ASOPOOL_CopyName    (TAG_USER + 15) /* Copy the name string */
#define ASOPOOL_LockMem     (TAG_USER + 16) /* Lock memory allocated */

/* Item Pool */
#define ASOITEM_MFlags      (TAG_USER + 10) /* Memory flags for the pool */
#define ASOITEM_ItemSize    (TAG_USER + 11) /* Size of individual items */
#define ASOITEM_BatchSize   (TAG_USER + 12) /* Amount of items to be allocated in one batch */
#define ASOITEM_MaxSize     (TAG_USER + 13) /* Maximum amount of items allowed in pool */
#define ASOITEM_GCPolicy    (TAG_USER + 14) /* Garbage collection policy */
#define ASOITEM_GCParameter (TAG_USER + 15) /* Garbage collection parameter */
#define ASOITEM_Constructor (TAG_USER + 16) /* Constructor hook */
#define ASOITEM_Destructor  (TAG_USER + 17) /* Destructor hook */
#define ASOITEM_Protected   (TAG_USER + 18) /* Protect pool with a semaphore */

/* Mutex */
#define ASOMUTEX_Recursive  (TAG_USER + 10) /* Make mutex recursive */

/* ExtMem */
#define ASOEXTMEM_Size          	(TAG_USER + 10) /* Size of extended memory area */
#define ASOEXTMEM_AllocationPolicy	(TAG_USER + 11) /* Allocation policy */

/* Item pool GCPolicy types */
enum enItemPoolGCPolicy
{
    ITEMGC_NONE       = 0,
    ITEMGC_AFTERCOUNT = 1
};

/* Ext Memory allocation policies */
enum enExtMemAllocationPolicy
{
        EXTMEMPOLICY_IMMEDIATE  = 0,
        EXTMEMPOLICY_DELAYED    = 1,
        EXTMEMPOLICY_ACCESS    	= 2
};


/* Kernel memory cache */
#define ASOKMEM_Name        (TAG_USER + 10) /* Name of the cache */
#define ASOKMEM_Type        (TAG_USER + 11) /* Type, private or shared */
#define ASOKMEM_Size        (TAG_USER + 12) /* Object size */
#define ASOKMEM_Alignment   (TAG_USER + 13) /* Object Alignment */
#define ASOKMEM_Constructor (TAG_USER + 14) /* Constructor */
#define ASOKMEM_Destructor  (TAG_USER + 15) /* Destructor */
#define ASOKMEM_Colored     (TAG_USER + 16) /* Use cache slab coloring */
#define ASOKMEM_Compact     (TAG_USER + 17) /* Force cache to be compact, even
                                             * if this means the slab internal
                                             * fragmentation will be above the
                                             * threshold
                                             */

/* Kernel memory cache type */
enum enKMemCacheType
{
	KMEMT_PRIVATE     = 0,
	KMEMT_SHARED      = 1
};


/* Resource map */
#define ASORMAP_Base        (TAG_USER + 10) /* Resource range base */
#define ASORMAP_Size        (TAG_USER + 11) /* Resource range size */
#define ASORMAP_Quantum     (TAG_USER + 12) /* Minimal quantum for one single
                                             * allocation
                                             */
#define ASORMAP_CacheMax    (TAG_USER + 13) /* Maximum size for quantum caches.
											 * All allocations smaller or equal
											 * to this size will come from
											 * quantum caches
											 */


/* Tags for AllocVecTagList (V51) */
#define AVT_Type            (TAG_USER + 1)
#define AVT_Contiguous      (TAG_USER + 2)
#define AVT_Lock            (TAG_USER + 3)
#define AVT_Alignment       (TAG_USER + 4)
#define AVT_PhysicalAlignment (TAG_USER + 5)
#define AVT_Clear           (TAG_USER + 6)
#define AVT_ClearWithValue	(TAG_USER + 6)
#define AVT_ClearValue		(TAG_USER + 6)
#define AVT_Wait            (TAG_USER + 7)
#define AVT_NoExpunge       (TAG_USER + 8)

/* Tags for AllocNamedMemory (V51) */
#define ANMT_CheckSum       (TAG_USER + 1)
#define ANMT_Error          (TAG_USER + 2)

/* Possible values for ANMT_Error */
enum enAllocNamedMemoryErrors
{
    ANMERROR_NOERROR        = 0,
    ANMERROR_NOMEMORY       = 1,
    ANMERROR_DUPLICATENAME  = 2,
    ANMERROR_PARAMETER      = 3,
};

/* Tags for GetCPUInfo */
#define GCIT_NumberOfCPUs   (TAG_USER +  1)
#define GCIT_Family         (TAG_USER +  2)
#define GCIT_Model          (TAG_USER +  3)
#define GCIT_ModelString    (TAG_USER +  4)
#define GCIT_Version        (TAG_USER +  5)
#define GCIT_VersionString  (TAG_USER +  6)
#define GCIT_FrontsideSpeed (TAG_USER +  7)
#define GCIT_ProcessorSpeed (TAG_USER +  8)
#define GCIT_L1CacheSize    (TAG_USER +  9)
#define GCIT_L2CacheSize    (TAG_USER + 10)
#define GCIT_L3CacheSize    (TAG_USER + 11)
#define GCIT_VectorUnit     (TAG_USER + 12)
#define GCIT_Extensions     (TAG_USER + 13)
#define GCIT_CacheLineSize  (TAG_USER + 14)
#define GCIT_CPUPageSize    (TAG_USER + 15)
#define GCIT_ExecPageSize   (TAG_USER + 16)
#define GCIT_TimeBaseSpeed	(TAG_USER + 17)

/* Family codes */
enum enCPUFamiliy
{
    CPUFAMILY_UNKNOWN = 0,
    CPUFAMILY_60X     = 1,
    CPUFAMILY_7X0     = 2,
    CPUFAMILY_74XX    = 3,
    CPUFAMILY_4XX     = 4,
    CPUFAMILY_PA6T    = 5,
    CPUFAMILY_E300	  = 6,
    CPUFAMILY_E5500   = 7,
};

/* Model codes */
enum enCPUModel
{
    CPUTYPE_UNKNOWN        =  0,
    CPUTYPE_PPC603E        =  1,
    CPUTYPE_PPC604E        =  2,
    CPUTYPE_PPC750CXE      =  3,
    CPUTYPE_PPC750FX       =  4,
    CPUTYPE_PPC750GX       =  5,
    CPUTYPE_PPC7410        =  6,
    CPUTYPE_PPC74XX_VGER   =  7,
    CPUTYPE_PPC74XX_APOLLO =  8,
    CPUTYPE_PPC405LP       =  9,
    CPUTYPE_PPC405EP       = 10,
    CPUTYPE_PPC405GP       = 11,
    CPUTYPE_PPC405GPR      = 12,
    CPUTYPE_PPC440EP       = 13,
    CPUTYPE_PPC440GP       = 14,
    CPUTYPE_PPC440GX       = 15,
    CPUTYPE_PPC440SX       = 16,
    CPUTYPE_PPC440SP       = 17,
    CPUTYPE_PA6T_1682M	   = 18,
    CPUTYPE_PPC460EX       = 19,
    CPUTYPE_PPC5121E	   = 20,
    CPUTYPE_P50XX		   = 21
};

/* Vector unit types */
enum enVectorUnitType
{
    VECTORTYPE_NONE    = 0,
    VECTORTYPE_ALTIVEC = 1,
/* Same as AltiVec    VECTORTYPE_VMX     = 2*/
};


/****************************************************************************/

/*
 * Object types for AllocSysObject
 */
enum enAllocSysObjectTypes
{
    ASOT_IOREQUEST =  0, /* IORequest */
    ASOT_HOOK      =  1, /* Hook */
    ASOT_INTERRUPT =  2, /* Interrupt structure */
    ASOT_LIST      =  3, /* List and MinList */
    ASOT_DMAENTRY  =  4, /* DMAEntry array */
    ASOT_NODE      =  5, /* List node and MinNode */
    ASOT_PORT      =  6, /* Message port */
    ASOT_MESSAGE   =  7, /* Exec Message */
    ASOT_SEMAPHORE =  8, /* Signal Semaphore */
    ASOT_TAGLIST   =  9, /* TagItem list */
    ASOT_MEMPOOL   = 10, /* Memory pool */
    ASOT_ITEMPOOL  = 11, /* Item pool */
    ASOT_RMAP      = 12, /* Resource map */
    ASOT_MUTEX     = 13, /* Mutex */
    ASOT_EXTMEM    = 14, /* Extended memory */
};

/****************************************************************************/

/* Tag items for CreateLibrary */
#define CLT_Vector68K     (TAG_USER +  1)
#define CLT_InitData      (TAG_USER +  2)
#define CLT_InitFunc      (TAG_USER +  3)
#define CLT_Seglist       (TAG_USER +  8)
#define CLT_Interfaces    (TAG_USER +  9)
#define CLT_DataSize      (TAG_USER + 10)
#define CLT_Legacy        (TAG_USER + 11)
#define CLT_NoLegacyIFace (TAG_USER + 12)

/****************************************************************************/

/* Message types for debugger hook */
enum enDebugMessage
{
    DBHMT_EXCEPTION  		= 1,
    DBHMT_REMTASK    		= 2,
    DBHMT_OPENLIB    		= 3,
    DBHMT_CLOSELIB   		= 4,
    DBHMT_ADDTASK    		= 5,
    DBHMT_SHAREDOBJECTOPEN 	= 6,
    DBHMT_SHAREDOBJECTCLOSE	= 7
};

/****************************************************************************/

/* Tags for AddTask/CreateTask */
#define AT_Param1         (TAG_USER + 1)
#define AT_Param2         (TAG_USER + 2)
#define AT_Param3         (TAG_USER + 3)
#define AT_Param4         (TAG_USER + 4)
#define AT_Param5         (TAG_USER + 5)
#define AT_Param6         (TAG_USER + 6)
#define AT_Param7         (TAG_USER + 7)
#define AT_Param8         (TAG_USER + 8)
#define AT_Child          (TAG_USER + 9)

#define CT_LockStack      (TAG_USER + 20)

/****************************************************************************/

/* Tags for NewStackRun */
#define NSR_Dummy         (TAG_USER+500)    /* Offset to avoid Emulate() tag collision. */
#define NSR_StackSize     (NSR_Dummy+1)     /* Initial stack size */
#define NSR_MinStackSize  (NSR_Dummy+2)     /* Absolute minimal stack size */
#define NSR_LockStack     (NSR_Dummy+3)     /* Lock the stack in memory to prevent paging */
#define NSR_Arg1          (NSR_Dummy+10)    /* Parameters passed to the function */
#define NSR_Arg2          (NSR_Dummy+11)
#define NSR_Arg3          (NSR_Dummy+12)
#define NSR_Arg4          (NSR_Dummy+13)
#define NSR_Arg5          (NSR_Dummy+14)
#define NSR_Arg6          (NSR_Dummy+15)

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_EXECTAGS_H */
