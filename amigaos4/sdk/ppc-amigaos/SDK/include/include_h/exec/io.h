#ifndef EXEC_IO_H
#define EXEC_IO_H
/*
**    $VER: io.h 53.29 (10.8.2015)
**
**    Message structures used for device communication
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
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

struct IORequest
{
    struct Message  io_Message;
    struct Device * io_Device;  /* device node pointer  */
    struct Unit *   io_Unit;    /* unit (driver private)*/
    uint16          io_Command; /* device command */
    uint8           io_Flags;
    int8            io_Error;   /* error or warning num */
};

struct IOStdReq
{
    struct Message  io_Message;
    struct Device * io_Device;  /* device node pointer  */
    struct Unit *   io_Unit;    /* unit (driver private)*/
    uint16          io_Command; /* device command */
    uint8           io_Flags;
    int8            io_Error;   /* error or warning num */
    uint32          io_Actual;  /* actual number of bytes transferred */
    uint32          io_Length;  /* requested number bytes transferred*/
    APTR            io_Data;    /* points to data area */
    uint32          io_Offset;  /* offset for block structured devices */
};

/* library vector offsets for device reserved vectors */
enum enDeviceLibraryReserved
{
    DEV_BEGINIO = (-30),
    DEV_ABORTIO = (-36)
};

/* io_Flags defined bits */
#define IOB_QUICK 0
#define IOF_QUICK (1<<IOB_QUICK)

enum enDefaultDeviceCommands
{
    CMD_INVALID = 0,
    CMD_RESET   = 1,
    CMD_READ    = 2,
    CMD_WRITE   = 3,
    CMD_UPDATE  = 4,
    CMD_CLEAR   = 5,
    CMD_STOP    = 6,
    CMD_START   = 7,
    CMD_FLUSH   = 8,

    CMD_NONSTD  = 9
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

#endif /* EXEC_IO_H */
