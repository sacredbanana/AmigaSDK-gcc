#ifndef DEVICES_INPUT_H
#define DEVICES_INPUT_H
/*
**    $VER: input.h 54.16 (22.08.2022)
**
**    input device command definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_IO_H
#include <exec/io.h>
#endif

#ifndef   DEVICES_TIMER_H
#include <devices/timer.h>
#endif

#ifndef   DEVICES_GAMEPORT_H
#include <devices/gameport.h>
#endif

#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
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

#define INPUTNAME "input.device"

/****************************************************************************/

/* input.device commands */
#define IND_ADDHANDLER         (CMD_NONSTD+0)
#define IND_REMHANDLER         (CMD_NONSTD+1)
#define IND_WRITEEVENT         (CMD_NONSTD+2)
#define IND_SETTHRESH          (CMD_NONSTD+3)
#define IND_SETPERIOD          (CMD_NONSTD+4)
#define IND_SETMPORT           (CMD_NONSTD+5)
#define IND_SETMTYPE           (CMD_NONSTD+6)
#define IND_SETMTRIG           (CMD_NONSTD+7)
#define IND_SETMDEVICE         (CMD_NONSTD+8)  /* V50 */
#define IND_SETKDEVICE         (CMD_NONSTD+9)  /* V50 */
#define IND_GETMDEVICE         (CMD_NONSTD+10) /* V50 */
#define IND_GETKDEVICE         (CMD_NONSTD+11) /* V50 */
#define IND_ADDNOTIFY          (CMD_NONSTD+12) /* V50 */
#define IND_IMMEDIATEADDNOTIFY (CMD_NONSTD+13) /* V50 */
#define IND_REMOVENOTIFY       (CMD_NONSTD+14) /* V50 */
#define IND_ADDEVENT           (CMD_NONSTD+15) /* V50 */
#define IND_GETTHRESH          (CMD_NONSTD+16) /* V50 */
#define IND_GETPERIOD          (CMD_NONSTD+17) /* V50 */
#define IND_GETHANDLERLIST     (CMD_NONSTD+18) /* V50 */

/****************************************************************************/

/* This is used to configure and query the keyboard
 * and gameport devices
 */
struct InputDeviceOption
{
    STRPTR Name;     /* Device name */
    int32  NameSize; /* Size of name buffer (for queries) */
    int32  Unit;     /* Unit number */
};

/****************************************************************************/

/* Errors produced by input.device */
#define IDERR_BadName          1 /* Device name submitted to
                                    IND_SETKDEVICE or IND_SETMDEVICE
                                    is not valid */
#define IDERR_OutOfMemory      2 /* Not enough memory to perform
                                    requested action */
#define IDERR_NameTooLong      3 /* The device name is too long to
                                    fit into the supplied buffer */
#define IDERR_AlreadyInstalled 4 /* The notification hook you tried to
                                    install is already present */
#define IDERR_NotInstalled     5 /* The notification hook you wanted to
                                    be removed was not even installed */

/****************************************************************************/

/* Messages passed to a notification hook. */

#define IDNOTIFY_Threshold 1

struct IDThresholdNotifyMsg
{
    int32          idnm_Type;      /* Set to IDNOTIFY_Threshold */
    struct TimeVal idnm_Threshold; /* Key repeat threshold */
};

#define IDNOTIFY_Period 2

struct IDPeriodNotifyMsg
{
    int32          idnm_Type;   /* Set to IDNOTIFY_Period */
    struct TimeVal idnm_Period; /* Key repeat period */
};

#define IDNOTIFY_MousePort 3

struct IDMousePortNotifyMsg
{
    int32 idnm_Type;      /* Set to IDNOTIFY_MousePort */
    int32 idnm_MousePort; /* Mouse port number; otherwise
                            identical to gameport.device
                            unit number to obtain mouse
                            events from. */
};

#define IDNOTIFY_MouseType 4

struct IDMouseTypeNotifyMsg
{
    int32 idnm_Type;      /* Set to IDNOTIFY_MouseType */
    int32 idnm_MouseType; /* Controller type, as defined
                             in <devices/gameport.h> by
                             the GPCT_[..] symbols. */
};

#define IDNOTIFY_MouseTrigger 5

struct IDMouseTriggerNotifyMsg
{
    int32                  idnm_Type;    /* Set to IDNOTIFY_MouseTrigger */
    struct GamePortTrigger idnm_Trigger; /* Conditions for a mouse port
                                            report. */
};

#define IDNOTIFY_MouseDevice 6

struct IDMouseDeviceNotifyMsg
{
    int32  idnm_Type; /* Set to IDNOTIFY_MouseDevice */
    STRPTR idnm_Name; /* The name of the gameport.device
                         driver mouse events are obtained
                         from */
    int32  idnm_Unit; /* The mouse port or unit number
                         of the gameport.device driver */
};

#define IDNOTIFY_KeyboardDevice 7

struct IDKeyboardDeviceNotifyMsg
{
    int32  idnm_Type; /* Set to IDNOTIFY_KeyboardDevice */
    STRPTR idnm_Name; /* The name of the keyboard.device
                         driver key events are obtained
                         from. */
    int32  idnm_Unit; /* The unit number of the
                         keyboard.device driver */
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

#endif /* DEVICES_INPUT_H */
