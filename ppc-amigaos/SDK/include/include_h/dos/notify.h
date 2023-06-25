#ifndef DOS_NOTIFY_H
#define DOS_NOTIFY_H
/*
**    $VER: notify.h  54.100 (07.09.2020)
**
**    dos notification definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef EXEC_TASKS_H
#include <exec/tasks.h>
#endif

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

/****************************************************************************/
/*  See; dos/var.h for local and global variables notify definitions.       */
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
/* Do not modify or reuse the NotifyRequest while it is active. */

struct NotifyRequest
{
    CONST_STRPTR nr_Name;         /* The name of object for notification */
    STRPTR       nr_FullName;     /* NOTE: This is set by dos - DO NOT modify. */
    uint32       nr_UserData;     /* For the applications use */
    uint32       nr_Flags;        /* Notify method flags NRF_xxx  */

    union
    {
        struct
        {
            struct MsgPort *nr_Port;       /* for SEND_MESSAGE */
            uint8           nr_MsgPad[4];  /* Reserved */
        }
        nr_Msg;

        struct
        {
            struct Task *   nr_Task;       /* for SEND_SIGNAL */
            uint8           nr_SignalNum;  /* for SEND_SIGNAL */
            uint8           nr_SigPad[3];  /* Reserved */
        }
        nr_Signal;

        struct
        {
            struct Hook *   nr_Hook;       /* for CALL_HOOK */
            uint8           nr_HookPad[4]; /* Reserved */
        }
        nr_CallHook;
    }
    nr_stuff;

    uint32          nr_Reserved[2];    /* Reserved expansion space */

    /* Internal fields for use by dos and handlers */
    uint32          nr_DosPrivate;     /* PRIVATE: DOS use only. */
    APTR            nr_FSPrivate;      /* PRIVATE: Handler use only. */
    uint32          nr_MsgCount;       /* PRIVATE: Handler use only. */
    struct MsgPort *nr_Handler;        /* PRIVATE: Handler port for EndNotify() */
    uint32          nr_Expansion[4];   /* PRIVATE: Expansion space - added V51.30 */
};

/* ------------------------------------------------------------------------ */
/* Flag bit numbers */

#define NRB_SEND_MESSAGE       0
#define NRB_SEND_SIGNAL        1
#define NRB_WAIT_REPLY         3
#define NRB_NOTIFY_INITIAL     4
#define NRB_CALL_HOOK          5
#define NRB_DOS_NOTIFY_ONLY    12 
#define NRB_MAGIC              31	/* PRIVATE - Handler use only.*/


/* --- NotifyRequest Flags ------------------------------------------------ */
/* Notify Methods - the following three are mutually exclusive */

#define NRF_SEND_MESSAGE      (1UL<<NRB_SEND_MESSAGE)
#define NRF_SEND_SIGNAL       (1UL<<NRB_SEND_SIGNAL)
#define NRF_CALL_HOOK         (1UL<<NRB_CALL_HOOK)

/* Do not queue messages for NRF_SEND_MESSAGE method */
#define NRF_WAIT_REPLY        (1UL<<NRB_WAIT_REPLY)

/* Always send an initial notification on setup */
#define NRF_NOTIFY_INITIAL    (1UL<<NRB_NOTIFY_INITIAL)

/* New flag for V52.33+ DOS, specifying this flag prevents the use
 * of filesystem supported notification, even if it is available,
 * it forces usage of the dos.library notification function instead.
 * The dos.library notification function supports all three methods 
 * with both file and directory monitoring. */
#define NRF_DOS_NOTIFY_ONLY   (1UL<<NRB_DOS_NOTIFY_ONLY)


/* PRIVATE - Handler use only. Do NOT set or remove NRF_MAGIC yourself. */
#define NRF_MAGIC             (1UL<<NRB_MAGIC)

/* PRIVATE - Bitmask of flags that are reserved for use by the handler. */
#define NR_HANDLER_MASK        0xffff0000UL
#define NR_HANDLER_FLAGS       NR_HANDLER_MASK	/* old source compatibility */



/****************************************************************************/
/* Message sent to the application if NRF_SEND_MESSAGE is specified. */

struct NotifyMessage
{
    struct Message nm_ExecMessage;
    uint32         nm_Class;
    uint16         nm_Code;
    struct NotifyRequest * nm_NReq; /* Don't modify request while active ! */
    uint32         nm_DoNotTouch;   /* Like it says! For use by handlers   */
    uint32         nm_DoNotTouch2;  /* ditto */
};

/* --- NotifyMessage Class --- */
#define NOTIFY_CLASS    0x40000000

/* --- NotifyMessage Codes --- */
#define NOTIFY_CODE     0x1234



/****************************************************************************/
/* NotifyHook data structure for NRF_CALL_HOOK */

struct NotifyHookMsg
{
    int32         nhm_Size;         /* Size of data structure */
    int32         nhm_Action;       /* What happened (see below) */
    CONST_STRPTR  nhm_Name;         /* The name of the object */
};

/* nhm_Action types */
#define NHM_ACTION_INITIAL    -1    /* Initial invocation */
#define NHM_ACTION_ADD         0    /* Object was added */
#define NHM_ACTION_CHANGE      1    /* Object has changed */
#define NHM_ACTION_DELETE      2    /* Object was removed */



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

#endif /* DOS_NOTIFY_H */
