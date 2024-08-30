#ifndef EXEC_DEVICES_H
#define EXEC_DEVICES_H
/*
**    $VER: devices.h 53.29 (10.8.2015)
**
**    Include file for use by Exec device drivers
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

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

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/****** Device ******************************************************/

struct Device
{
    struct Library dd_Library;
};

/****** Unit ********************************************************/

struct Unit
{
    struct MsgPort unit_MsgPort; /* queue for unprocessed messages */
                                 /* instance of msgport is recommended */
    uint8          unit_flags;
    uint8          unit_pad;
    uint16         unit_OpenCnt; /* number of active opens */
};

enum enUnitFlags
{
    UNITF_ACTIVE = (1<<0),
    UNITF_INTASK = (1<<1)
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

#endif /* EXEC_DEVICES_H */
