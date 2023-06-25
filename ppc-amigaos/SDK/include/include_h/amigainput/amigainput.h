#ifndef AMIGAINPUT_AMIGAINPUT_H
#define AMIGAINPUT_AMIGAINPUT_H

/*
**    $VER: amigainput.h 54.16 (22.08.2022)
**
**    AmigaInput definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif /* EXEC_NODES_H */

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

typedef uint32 AIN_DeviceID;

typedef struct _AIN_Device
{
   STRPTR       DeviceName;
   uint32       Type;
   uint32       SubType;
   uint32       NumButtons;
   uint32       NumAxes;
   uint32       NumHats;
   AIN_DeviceID DeviceID;
}  AIN_Device;


typedef struct _AIN_DeviceHandle
{
   AIN_DeviceID DeviceID;
} AIN_DeviceHandle;


typedef struct _AIN_InputEvent
{
   struct MinNode Link;
   AIN_DeviceID   ID;
   uint32         TimeStamp;
   uint32         Type;
   uint32         Index;
   int32          Value;
} AIN_InputEvent;

typedef struct _AIN_RequesterResult
{
    uint8  ModName[1024];  
    uint32 UnitNo;         
    uint32 DeviceID;       
} AIN_RequesterResult;

/* Errortypes */

#define AINERR_NOERROR                0
#define AINERR_INACTIVE               1
#define AINERR_NOTSUPPORTED_API       2
#define AINERR_UNKNOWN_DEVICEID       3
#define AINERR_UNKNOWN_PARAMETER      4
#define AINERR_UNKNOWN_ARG            5
#define AINERR_UNKNOWN_TAG            6
#define AINERR_NOMEMORY               7
#define AINERR_ZEROPOINTER            8
#define AINERR_EMPTYCONTEXTLIST       9
#define AINERR_SMALLBUFFER           10
#define AINERR_DOUBLEOBTAIN          11
#define AINERR_NOHANDLE              12
#define AINERR_NO_EVENTMODE          13
#define AINERR_NO_PORT               14
#define AINERR_DRIVERINIT_FAIL       15
#define AINERR_READERROR             16
#define AINERR_OUTOFRANGE            17
#define AINERR_UNSUPPORTED_PARAMETER 18
#define AINERR_WINDOWINCACTIVE       19
#define AINERR_INVALID_ID            20
#define AINERR_NO_DEVICES            21

#define AIN_MAXERROR                 21

/* Controller Classes */

#define AINDT_MOUSE     1
#define AINDT_KEYBOARD  2
#define AINDT_JOYSTICK  3

/* context Paramter */

#define AIN_DUMMY (TAG_USER+0xc00100)

#define AINCC_Port       (AIN_DUMMY +1)
#define AINCC_Window     (AIN_DUMMY +2)
#define AIREQ_Type       (AIN_DUMMY+3)
#define AIREQ_SubType    (AIN_DUMMY+4)
#define AIREQ_MinButtons (AIN_DUMMY+5)
#define AIREQ_MaxButtons (AIN_DUMMY+6)
#define AIREQ_MinAxes    (AIN_DUMMY+7)
#define AIREQ_MaxAxes    (AIN_DUMMY+8)
#define AIREQ_MinHats    (AIN_DUMMY+9)
#define AIREQ_MaxHats    (AIN_DUMMY+10)
#define AIREQ_PubScreen  (AIN_DUMMY+11)

/* Query Parameter */

#define AINQ_NUMAXES         1
#define AINQ_NUMBUTTONS      2
#define AINQ_NUMHATS         3
#define AINQ_AXISNAME        4
#define AINQ_BUTTONNAME      5
#define AINQ_HATNAME         6
#define AINQ_POLLED          7
#define AINQ_AXIS_SYMMETRIC  8
#define AINQ_SUBCLASS        9
#define AINQ_DRIVERVERSION  10
#define AINQ_AXIS_CLASS     11
#define AINQ_AXIS_OFFSET    12
#define AINQ_BUTTON_OFFSET  13
#define AINQ_HAT_OFFSET     14
#define AINQ_LAYOUT_CLASS   15
#define AINQ_DEVNAME        16
#define AINQ_DESCRIPTION    17
#define AINQ_CONNECTED      18
#define AINQ_UNITS          19


/* AXIS_class */

#define AINAS_UNKOWN     0
#define AINAS_XAXIS      1
#define AINAS_YAXIS      2
#define AINAS_ZAXIS      3
#define AINAS_THRUST     4
#define AINAS_WHEEL      5
#define AINAS_ACCEL      6
#define AINAS_BRAKE      7
#define AINAS_SLIDER     8
#define AINAS_DIAL       9
#define AINAS_RUDDER    10
#define AINAS_THROTTLE  11


/* Layout_class */

#define AINLC_UNKOWN       0
#define AINLC_MOUSE        1
#define AINLC_KEYBOARD     2
#define AINLC_JOYSTICK     3
#define AINLC_FLIGHTSTICK  4
#define AINLC_COMPLEXSTICK 5


/* Subclass */

#define AINSUB_UNKNOWN        0
#define AINSUB_NOSUBCLASS     1
#define AINSUB_JOYPAD         2
#define AINSUB_DIGITAL_STICK  3
#define AINSUB_FLIGHTSTICK    4
#define AINSUB_WHEEL          5
#define AINSUB_LIGHTGUN       6

/* Axis Parameter */

#define AINAP_AXIS_MODE       1
#define AINAP_DIGITAL_MODE    2
#define AINAP_DIGITAL_INC     3
#define AINAP_DIGITAL_RESET   4

/* AXIS_MODE */

#define AINAM_FREE    1
#define AINAM_CENTER  2


/* DIGITAL MODE */

#define AINDM_INCREMENTAL  1
#define AINDM_JUMP         2


/* DIGITAL_RESET */

#define AINDR_JUMP  1
#define AINDR_KEEP  2
#define AINDR_FADE  3


/* Device Parameter */

#define AINDP_ACTIVE  1
#define AINDP_EVENT   2


/* Event types */

#define AINET_AXIS    1
#define AINET_BUTTON  2
#define AINET_HAT     3
#define AINET_KEY     4



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

#endif /* AMIGAINPUT_AMIGAINPUT_H */
