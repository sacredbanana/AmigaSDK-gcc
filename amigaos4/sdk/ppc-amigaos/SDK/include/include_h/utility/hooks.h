#ifndef UTILITY_HOOKS_H
#define UTILITY_HOOKS_H
/*
** Callback hooks
**
** Copyright 1989-2003 Amiga Inc.
**
** Copyright 2003-2019 Trevor Dickinson.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

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

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/*****************************************************************************/

struct Hook;

/* Useful definition for casting function pointers:
 * hook.h_Entry = (HOOKFUNC)AFunction
 */
typedef uint32 (*HOOKFUNC)(struct Hook *, APTR, APTR);

struct Hook
{
    struct MinNode  h_MinNode;     /* General purpose user minnode   */
    HOOKFUNC        h_Entry;       /* CallHookPkt() calls code here  */
    HOOKFUNC        h_SubEntry;    /* General purpose user function  */
    APTR            h_Data;        /* General purpose user data      */
};

/*****************************************************************************/

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

#endif /* UTILITY_HOOKS_H */
