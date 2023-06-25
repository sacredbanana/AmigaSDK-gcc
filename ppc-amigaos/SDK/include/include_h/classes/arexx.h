#ifndef CLASSES_AREXX_H
#define CLASSES_AREXX_H
/*
**    $VER: arexx.h 54.16 (22.08.2022)
**
**    arexx.class definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_MEMORY_H
#include <exec/memory.h>
#endif

#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif

#ifndef   DOS_RDARGS_H
#include <dos/rdargs.h>
#endif

#ifndef   REXX_STORAGE_H
#include <rexx/storage.h>
#endif

#ifndef   REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif

#ifndef   REXX_ERRORS_H
#include <rexx/errors.h>
#endif

#ifndef   INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef   INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
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

/* Tags supported by the arexx class */
#define AREXX_Dummy        (REACTION_Dummy+0x30000)

#define AREXX_HostName     (AREXX_Dummy+1) /* (CONST_STRPTR) */
#define AREXX_DefExtension (AREXX_Dummy+2) /* (CONST_STRPTR) */
#define AREXX_Commands     (AREXX_Dummy+3) /* (struct ARexxCmd *) */
#define AREXX_ErrorCode    (AREXX_Dummy+4) /* (uint32 *) */
#define AREXX_SigMask      (AREXX_Dummy+5) /* (uint32) */
#define AREXX_NoSlot       (AREXX_Dummy+6) /* (BOOL) */
#define AREXX_ReplyHook    (AREXX_Dummy+7) /* (struct Hook *) */
#define AREXX_MsgPort      (AREXX_Dummy+8) /* (struct MsgPort *) */

/* Possible error result codes */
#define RXERR_NO_COMMAND_LIST     (1L)
#define RXERR_NO_PORT_NAME        (2L)
#define RXERR_PORT_ALREADY_EXISTS (3L)
#define RXERR_OUT_OF_MEMORY       (4L)

/* I can't spell, don't use this. */
#define AREXX_DefExtention    AREXX_DefExtension

/*****************************************************************************/

/* Methods Supported by the ARexx Class. */
#define AM_HANDLEEVENT  (0x590001) /* ARexx class event-handler. */

#define AM_EXECUTE      (0x590002) /* Execute a host command. */

#define AM_FLUSH        (0x590003) /* Flush rexx port. */

/* AM_EXECUTE message. */
struct apExecute
{
    uint32        MethodID;          /* AM_EXECUTE */
    CONST_STRPTR  ape_CommandString; /* Command string to execute */
    CONST_STRPTR  ape_PortName;      /* Port to send to (usually RXSDIR) */
    int32        *ape_RC;            /* RC pointer */
    int32        *ape_RC2;           /* RC2 pointer */
    STRPTR       *ape_Result;        /* Result pointer */
    BPTR          ape_IO;            /* I/O handle */
};


/*****************************************************************************/

/* An array of these structures must be passed at object-create time. */
struct ARexxCmd
{
    CONST_STRPTR ac_Name;        /* Command name */
    uint16       ac_ID;          /* Unique ID */

    /* NOTE: The function pointed to by ac_Func() will be called
     *       with parameters in CPU registers. Register usage
     *       is as follows:
     *
     *       VOID ac_Func(struct ARexxCmd * cmd, struct RexxMsg * rm)
     *                                       A0                   A1
     */
    VOID (*ac_Func)(struct ARexxCmd *, struct RexxMsg *);

    CONST_STRPTR ac_ArgTemplate; /* DOS-style argument template */
    uint32       ac_Flags;       /* Unused, make NULL */
    uint32      *ac_ArgList;     /* Result of ReadArgs() */
    int32        ac_RC;          /* Primary result */
    int32        ac_RC2;         /* Secondary result */
    STRPTR       ac_Result;      /* RESULT variable */
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

#endif /* CLASSES_AREXX_H */
