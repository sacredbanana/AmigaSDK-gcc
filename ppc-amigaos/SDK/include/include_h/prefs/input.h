#ifndef PREFS_INPUT_H
#define PREFS_INPUT_H
/*
**    $VER: input.h 54.16 (22.08.2022)
**
**    File format for input preferences
**
**    (C) Copyright 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef   DEVICES_TIMER_H
#include <devices/timer.h>
#endif

/*****************************************************************************/

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

#define ID_INPT MAKE_ID('I','N','P','T')

struct InputPrefs
{
    TEXT           ip_ObsoleteShortKeymapName[16];
    uint16         ip_PointerTicks;
    struct TimeVal ip_DoubleClick;
    struct TimeVal ip_KeyRptDelay;
    struct TimeVal ip_KeyRptSpeed;
    int16          ip_MouseAccel;
    /* Fields added in V50 */
    uint32         ip_ClassicKeyboard;
    /* Fields added in V50, NUL content before V51 */
    TEXT           ip_KeymapName[64];
    uint32         ip_SwitchMouseButtons;
    /* MousePointerSpeed added with Prefs/Input V51.11.
     * Upper 16 bit dividend, lower 16 bit divisor,
     * 0x00010004 equals old speed 1 (4 PointerTicks),
     * 0x00010002 equals old speed 2 (2 PointerTicks),
     * 0x00010001 equals old speed 3 (1 PointerTick).
     */
    uint32         ip_MousePointerSpeed;
    /* ScrollWheelMultiplier added with Prefs/Input V51.16.
     * You have to add 1 after reading the value, which
     * ensures that a zero in the file results in the default
     * multiplier of 1. -1 results in 0 which disables the wheel.
     */
    int32          ip_ScrollWheelMultiplier;
    int16          ip_SwapAltAmiga;
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

#endif /* PREFS_INPUT_H */
