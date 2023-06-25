#ifndef WORKBENCH_STARTUP_H
#define WORKBENCH_STARTUP_H

/*
**    $VER: startup.h 54.16 (22.08.2022)
**
**    workbench startup definitions
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

#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef   DOS_DOS_H
#include <dos/dos.h>
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

struct WBStartup
{
    struct Message   sm_Message;    /* a standard message structure      */
    struct MsgPort * sm_Process;    /* the process descriptor for you    */
    BPTR             sm_Segment;    /* a descriptor for your code        */
    LONG             sm_NumArgs;    /* the number of elements in ArgList */
    char *           sm_ToolWindow; /* description of window             */
    struct WBArg *   sm_ArgList;    /* the arguments themselves          */
};

struct WBArg
{
    BPTR   wa_Lock; /* a lock descriptor              */
    STRPTR wa_Name; /* a string relative to that lock */
};

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

#endif /* WORKBENCH_STARTUP_H */
