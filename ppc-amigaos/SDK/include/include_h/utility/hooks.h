#ifndef UTILITY_HOOKS_H
#define UTILITY_HOOKS_H
/*
**    $VER: hooks.h 53.29 (10.8.2015)
**
**    Callback hooks
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
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

struct Hook
{
    struct MinNode  h_MinNode;     /* General purpose user minnode   */
    uint32        (*h_Entry)();    /* CallHookPkt() calls code here  */
    uint32        (*h_SubEntry)(); /* General purpose user function  */
    APTR            h_Data;        /* General purpose user data      */
};

/* Useful definition for casting function pointers:
 * hook.h_SubEntry = (HOOKFUNC)AFunction
 */
typedef unsigned long (*HOOKFUNC)();

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
