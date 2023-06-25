#ifndef EXEC_LISTS_H
#define EXEC_LISTS_H
/*
**    $VER: lists.h 53.29 (10.8.2015)
**
**    Definitions and macros for use with Exec lists
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
 *  Full featured list header.
 */
struct List
{
    struct Node * lh_Head;
    struct Node * lh_Tail;
    struct Node * lh_TailPred;
    uint8         lh_Type;
    uint8         l_pad;
}; /* word aligned */

/*
 * Minimal List Header - no type checking
 */
struct MinList
{
    struct MinNode * mlh_Head;
    struct MinNode * mlh_Tail;
    struct MinNode * mlh_TailPred;
}; /* longword aligned */

/****************************************************************************/

/*
 *      Check for the presence of any nodes on the given list.  These
 *      macros are even safe to use on lists that are modified by other
 *      tasks.  However; if something is simultaneously changing the
 *      list, the result of the test is unpredictable.
 *
 *      Unless you first arbitrated for ownership of the list, you can't
 *      _depend_ on the contents of the list.  Nodes might have been added
 *      or removed during or after the macro executes.
 *
 *              if( IsListEmpty(list) )         printf("List is empty\n");
 */
#define IsListEmpty(x) \
    ( (struct List *)((x)->lh_TailPred) == (struct List *)(x) )

#define IsMinListEmpty(x) \
    ( (struct MinList *)((x)->mlh_TailPred) == (struct MinList *)(x) )


#define IsMsgPortEmpty(x) \
    ( IsListEmpty((&(x)->mp_MsgList)) )

/****************************************************************************/

/*
 *      Initialize a list header
 */
#define NEWLIST(x)                                       \
  do{                                                    \
        (x).lh_Head     = (struct Node *) &(x).lh_Tail;  \
        (x).lh_Tail     = NULL;                          \
        (x).lh_TailPred = (struct Node *) &(x).lh_Head;  \
    }while(0)

/*
 *      Initialize a list header with type
 */
#define NEWLISTTYPE(x, t)                               \
  do{                                                   \
        NEWLIST(x);                                     \
        (x).lh_Type     = t;                            \
    }while(0)
/*
 *      Initialize a minlist header
 */
#define NEWMINLIST(x)                                        \
  do{                                                        \
        (x).mlh_Head     = (struct MinNode *) &(x).mlh_Tail; \
        (x).mlh_Tail     = NULL;                             \
        (x).mlh_TailPred = (struct MinNode *) &(x).mlh_Head; \
    }while(0)

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

#endif /* EXEC_LISTS_H */
