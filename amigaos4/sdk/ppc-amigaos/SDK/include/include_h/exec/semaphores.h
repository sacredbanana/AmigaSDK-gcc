#ifndef EXEC_SEMAPHORES_H
#define EXEC_SEMAPHORES_H
/*
**    $VER: semaphores.h 53.29 (10.8.2015)
**
**    Definitions for locking functions.
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

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef   EXEC_TASKS_H
#include <exec/tasks.h>
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

/****** SignalSemaphore *********************************************/

/* Private structure used by ObtainSemaphore() */
struct SemaphoreRequest
{
    struct MinNode sr_Link;
    struct Task *  sr_Waiter;
};

/* Signal Semaphore data structure */
struct SignalSemaphore
{
    struct Node             ss_Link;
    int16                   ss_NestCount;
    struct MinList          ss_WaitQueue;
    struct SemaphoreRequest ss_MultipleLink;
    struct Task *           ss_Owner;
    int16                   ss_QueueCount;
};

/****** Semaphore procure message (for use in V39 Procure/Vacate) ****/
struct SemaphoreMessage
{
    struct Message          ssm_Message;
    struct SignalSemaphore *ssm_Semaphore;
};

enum enSemaphoreRequestType
{
    SM_SHARED    = 1,
    SM_EXCLUSIVE = 0
};

/****** Semaphore (Old Procure/Vacate type, not reliable) ***********/
/* Do not use these semaphores! */
/* Then why have them hanging around ? Using them will generate an exception 
struct Semaphore        
{ 
    struct MsgPort sm_MsgPort;
    WORD           sm_Bids;
};
*/

#define sm_LockMsg mp_SigTask

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

#endif /* EXEC_SEMAPHORES_H */
