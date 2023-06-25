#ifndef INTUITION_NOTIFY_H
#define INTUITION_NOTIFY_H
/*
**    $VER: notify.h 54.16 (22.08.2022)
**
**    Intuition notification system includes
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

#ifndef   DEVICES_TIMER_H
#include <devices/timer.h>
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

#define SNA_PubName  (TAG_USER + 0x01) /* public screen to watch,
                                          NULL for all screens */
#define SNA_Notify   (TAG_USER + 0x02) /* see below */
#define SNA_UserData (TAG_USER + 0x03) /* for your use */
#define SNA_SigTask  (TAG_USER + 0x04) /* task to signal */
#define SNA_SigBit   (TAG_USER + 0x05) /* signal bit */
#define SNA_MsgPort  (TAG_USER + 0x06) /* send message to this port */
#define SNA_Priority (TAG_USER + 0x07) /* priority of your request */
#define SNA_Hook     (TAG_USER + 0x08)

/* SNA_Notify (all unassigned bits are reserved for system use) */
#define SNOTIFY_AFTER_OPENSCREEN   (1<<0)  /* screen has been opened */
#define SNOTIFY_BEFORE_CLOSESCREEN (1<<1)  /* going to close screen */
#define SNOTIFY_AFTER_OPENWB       (1<<2)  /* Workbench is open */
#define SNOTIFY_BEFORE_CLOSEWB     (1<<3)  /* Workbench is going to be closed*/
#define SNOTIFY_AFTER_OPENWINDOW   (1<<4)  /* new window */
#define SNOTIFY_BEFORE_CLOSEWINDOW (1<<5)  /* window is going to be closed */
#define SNOTIFY_PUBSCREENSTATE     (1<<6)  /* PubScreenState() */
#define SNOTIFY_LOCKPUBSCREEN      (1<<7)  /* LockPubScreen() */
#define SNOTIFY_SCREENDEPTH        (1<<8)  /* ScreenDepth() */
#define SNOTIFY_AFTER_CLOSESCREEN  (1<<9)  /* notify after CloseScreen() */
#define SNOTIFY_AFTER_CLOSEWINDOW  (1<<10) /* dto. CloseWindow() */
#define SNOTIFY_BEFORE_OPENSCREEN  (1<<11) /* notify before OpenScreen() */
#define SNOTIFY_BEFORE_OPENWINDOW  (1<<12) /* dto. OpenWindow() */
#define SNOTIFY_BEFORE_OPENWB      (1<<13) /* like OPENSCREEN */
#define SNOTIFY_AFTER_CLOSEWB      (1<<14) /* like CLOSESCREEN */
#define SNOTIFY_WAIT_REPLY         (1<<15) /* wait for reply before
                                            * taking action
                                            */
#define SNOTIFY_UNLOCKPUBSCREEN    (1<<16) /* UnlockPubScreen() */

struct ScreenNotifyMessage
{
    struct Message snm_Message;     /* embedded message */
    ULONG          snm_Class;       /* see above */
    ULONG          snm_Code;
    APTR           snm_Object;      /* either a pointer to struct Window
                                     * or struct Screen (READ-ONLY).
                                     * For SNRF_#?PUBSCREEN this the
                                     * name of the public screen
                                     */
    APTR           snm_UserData;    /* SNA_UserData */
    APTR           snm_Request;     /* pointer returned by
                                     * StartScreenNotify()
                                     */
    ULONG          snm_Reserved[5]; /* don't touch! */
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

#endif
