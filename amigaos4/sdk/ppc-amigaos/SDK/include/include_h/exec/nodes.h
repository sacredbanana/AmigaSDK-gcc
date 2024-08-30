#ifndef EXEC_NODES_H
#define EXEC_NODES_H
/*
**    $VER: nodes.h 53.29 (10.8.2015)
**
**    Nodes & Node type identifiers.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
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
#endif

/****************************************************************************/

/*
 *  List Node Structure.  Each member in a list starts with a Node
 */

struct Node
{
    struct Node * ln_Succ; /* Pointer to next (successor) */
    struct Node * ln_Pred; /* Pointer to previous (predecessor) */
    uint8         ln_Type;
    int8          ln_Pri;  /* Priority, for sorting */
    STRPTR        ln_Name; /* ID string, null terminated */
}; /* Note: word aligned */

/* minimal node -- no type checking possible */
struct MinNode
{
    struct MinNode *mln_Succ;
    struct MinNode *mln_Pred;
};

/*
** Note: Newly initialized IORequests, and software interrupt structures
** used with Cause(), should have type NT_UNKNOWN.  The OS will assign a type
** when they are first used.
*/

/*----- Node Types for LN_TYPE -----*/
enum enNodeTypes
{
    NT_UNKNOWN      =   0,
    NT_TASK         =   1,  /* Exec task */
    NT_INTERRUPT    =   2,
    NT_DEVICE       =   3,
    NT_MSGPORT      =   4,
    NT_MESSAGE      =   5,  /* Indicates message currently pending */
    NT_FREEMSG      =   6,
    NT_REPLYMSG     =   7,  /* Message has been replied */
    NT_RESOURCE     =   8,
    NT_LIBRARY      =   9,
    NT_MEMORY       =  10,
    NT_SOFTINT      =  11,  /* Internal flag used by SoftInits */
    NT_FONT         =  12,
    NT_PROCESS      =  13,  /* AmigaDOS Process */
    NT_SEMAPHORE    =  14,
    NT_SIGNALSEM    =  15,  /* signal semaphores */
    NT_BOOTNODE     =  16,
    NT_KICKMEM      =  17,
    NT_GRAPHICS     =  18,
    NT_DEATHMESSAGE =  19,

    /* New additions in V50 */
    NT_EXTINTERRUPT =  20,  /* Native interrupt */
    NT_EXTSOFTINT   =  21,  /* Native soft interrupt */
    NT_VMAREA       =  22,  /* Internal use only */
    NT_VMAREA_PROXY =  23,  /* Internal use only */
    NT_CLASS        =  24,  /* Class */
    NT_INTERFACE    =  25,  /* Interface */    

    /* New additions in V51 */
    NT_KMEMCACHE    =  26,  /* Internal use only */ 
    NT_RESERVED1    =  27,
    
    /* New additions in V53 */
    NT_FILESYSTEM   =  28,  /* For new style Vector-Port based Filesystems */

    /* New additions in V54 */
    NT_PAGE	    =  40,

    NT_ELFHANDLE    =  41,
    NT_SOLIBHANDLE  =  42,

    NT_USER         = 254,  /* User node types work down from here */
    NT_EXTENDED     = 255
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_NODES_H */
