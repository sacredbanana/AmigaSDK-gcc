#ifndef DEVICES_KEYBOARD_H
#define DEVICES_KEYBOARD_H
/*
**    $VER: keyboard.h 54.16 (22.08.2022)
**
**    Keyboard device command definitions
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

#define KBD_READEVENT        (CMD_NONSTD+0)
#define KBD_READMATRIX       (CMD_NONSTD+1)
#define KBD_ADDRESETHANDLER  (CMD_NONSTD+2)
#define KBD_REMRESETHANDLER  (CMD_NONSTD+3)
#define KBD_RESETHANDLERDONE (CMD_NONSTD+4)

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

#endif /* DEVICES_KEYBOARD_H */
