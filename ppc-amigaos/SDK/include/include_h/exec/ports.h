#ifndef EXEC_PORTS_H
#define EXEC_PORTS_H
/*
**    $VER: ports.h 53.29 (10.8.2015)
**
**    Message ports and Messages.
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

/****** MsgPort *****************************************************/

struct MsgPort
{
    struct Node mp_Node;
    uint8       mp_Flags;
    uint8       mp_SigBit;  /* signal bit number */
    APTR        mp_SigTask; /* object to be signalled */
    struct List mp_MsgList; /* message linked list  */
};

#define mp_SoftInt mp_SigTask /* Alias */

/* mp_Flags: Port arrival actions (PutMsg) */
enum enMsgPortFlags
{
    PF_ACTION   = 3,     /* Mask */
    PF_SIGALLOC = (1<<7) /* Internal use */
};

enum enMsgPortActions
{
    PA_SIGNAL  = 0, /* Signal task in mp_SigTask */
    PA_SOFTINT = 1, /* Signal SoftInt in mp_SoftInt/mp_SigTask */
    PA_IGNORE  = 2  /* Ignore arrival */
};

/****** Message *****************************************************/

struct Message
{
    struct Node      mn_Node;
    struct MsgPort * mn_ReplyPort; /* message reply port */
    uint16           mn_Length;    /* total message length, in bytes,
                                      (include the size of the Message
                                      structure in the length) */
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

#endif /* EXEC_PORTS_H */
