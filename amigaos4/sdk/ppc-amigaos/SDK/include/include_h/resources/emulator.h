#ifndef RESOURCES_EMULATOR_H
#define RESOURCES_EMULATOR_H
/*
**    $VER: emulator.h 53.29 (10.8.2015)
**
**    Standard C header for Emulator resource
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

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

struct EmulatorResource
{
    struct Node Node;
    APTR        EnterPPC;
    APTR        Enter68K;
    APTR        EnterPPCQuick;
    APTR        Enter68KQuick;
    APTR        EnterPPCQuickSP;
    APTR        EnterPPCNew;
    APTR        EnterPPCDirectly;
    ULONG       PrivateDontMove;
    ULONG       Reserved[3];
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

#endif
