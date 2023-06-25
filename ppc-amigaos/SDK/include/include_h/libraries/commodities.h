#ifndef LIBRARIES_COMMODITIES_H
#define LIBRARIES_COMMODITIES_H
/*
**    $VER: commodities.h 54.16 (22.08.2022)
**
**    Commodities definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010-2017 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
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

/* object creation macros */

#if defined(__USE_INLINE__)

#define CxFilter(d)         CreateCxObj(CX_FILTER,    (int32)d,      0)
#define CxSender(port,id)   CreateCxObj(CX_SEND,      (int32)port,   (int32)id)
#define CxSignal(task,sig)  CreateCxObj(CX_SIGNAL,    (int32)task,   (int32)sig)
#define CxTranslate(ie)     CreateCxObj(CX_TRANSLATE, (int32)ie,     0)
#define CxDebug(id)         CreateCxObj(CX_DEBUG,     (int32)id,     0)
#define CxCustom(action,id) CreateCxObj(CX_CUSTOM,    (int32)action, (int32)id)

#else

#define CxFilter(d)         ICommodities->CreateCxObj(CX_FILTER,    \
                            (int32)d,      0)
#define CxSender(port,id)   ICommodities->CreateCxObj(CX_SEND,      \
                            (int32)port,   (int32)id)
#define CxSignal(task,sig)  ICommodities->CreateCxObj(CX_SIGNAL,    \
                            (int32)task,   (int32)sig)
#define CxTranslate(ie)     ICommodities->CreateCxObj(CX_TRANSLATE, \
                            (int32)ie,     0)
#define CxDebug(id)         ICommodities->CreateCxObj(CX_DEBUG,     \
                            (int32)id,     0)
#define CxCustom(action,id) ICommodities->CreateCxObj(CX_CUSTOM,    \
                            (int32)action, (int32)id)

#endif

/****************************************************************************/

struct NewBroker
{
    int8            nb_Version;   /* Must be set to NB_VERSION */
    CONST_STRPTR    nb_Name;
    CONST_STRPTR    nb_Title;
    CONST_STRPTR    nb_Descr;
    uint16          nb_Unique;
    uint16          nb_Flags;
    int8            nb_Pri;
    struct MsgPort *nb_Port;
    int16           nb_ReservedChannel;
};

/* constant for NewBroker.nb_Version */
#define NB_VERSION   5  /* Version of NewBroker structure */

/* Sizes for various buffers */
#define CBD_NAMELEN  24
#define CBD_TITLELEN 40
#define CBD_DESCRLEN 40

/* Flags for NewBroker.nb_Unique */
#define NBU_DUPLICATE 0
#define NBU_UNIQUE    1 /* will not allow duplicates           */
#define NBU_NOTIFY    2 /* sends CXM_UNIQUE to existing broker */


// Flags for NewBroker.nb_Flags and CxBrokerCopy.Flags

// Set if commodity is enabled. Always set when creating a new broker.
#define COF_ENABLE    (1 << 1)

// Set if "Show" and "Hide" interface gadgets for this broker are enabled.
#define COF_SHOW_HIDE (1 << 2)

// Set if object cannot be removed.
#define COF_CONSTANT  (1 << 3)

// Set if object accepts broadcasted commands such as CXCMD_LIST_CHG.
#define COF_BROADCAST (1 << 4)

// Set if broker is unique. This flag is read only and only available
// via the CxBrokerCopy structure below.
#define COF_UNIQUE    (1 << 5)


/*****************************************************************************/

/* Fake data types for system private objects */
#ifndef COMMODITIES_BASE_H
typedef int32 CxObj;
typedef int32 CxMsg;
#endif

/* Pointer to a function returning a int32 */
typedef int32 (*PFL)();

/*****************************************************************************/

/* Commodities object types */
#define CX_INVALID    0 /* not a valid object (probably null) */
#define CX_FILTER     1 /* input event messages only          */
#define CX_TYPEFILTER 2 /* obsolete, do not use               */
#define CX_SEND       3 /* sends a message                    */
#define CX_SIGNAL     4 /* sends a signal                     */
#define CX_TRANSLATE  5 /* translates input event into chain  */
#define CX_BROKER     6 /* application representative         */
#define CX_DEBUG      7 /* dumps info to serial port          */
#define CX_CUSTOM     8 /* application provides function      */
#define CX_ZERO       9 /* system terminator node             */
#define CX_HOOK      10 /* app provides hook                  */

/*****************************************************************************/

/* Commodities message types */
#define CXM_IEVENT  (1 << 5)
#define CXM_COMMAND (1 << 6)

/* Only CXM_IEVENT messages are passed through the input network. Other types
 * of messages are sent to an optional port in your broker. This means that
 * you must test the message type in your message handling, if input messages
 * and command messages come to the same port.
 *
 * CXM_IEVENT: Messages of this type rattle around the Commodities input
 *           network. They are sent to you by a Sender object, and passed
 *           to you as a synchronous function call by a Custom object.
 *
 *           The message port or function entry point is stored in the
 *           object, and the ID field of the message will be set to what
 *           you arrange issuing object.
 *
 *           The data section of the message will point to the input event
 *           triggering the message.
 *
 * CXM_COMMAND: These messages are sent to a port attached to your Broker.
 *        They are sent to you when the controller program wants your
 *        program to do something. The ID value identifies the command.
 */

/* ID values associated with a message of type CXM_COMMAND      */
#define CXCMD_DISABLE   (15) /* please disable yourself         */
#define CXCMD_ENABLE    (17) /* please enable yourself          */
#define CXCMD_APPEAR    (19) /* open your window, if you can    */
#define CXCMD_DISAPPEAR (21) /* go dormant                      */
#define CXCMD_KILL      (23) /* go away for good                */
#define CXCMD_LIST_CHG  (27) /* Someone changed the broker list */
#define CXCMD_UNIQUE    (25) /* someone tried to create a broker
                              * with your name. Suggest you appear.
                              */

/*****************************************************************************/

/* Return values for BrokerCommand() (for use by Exchange program) */
#define CMDE_OK        (0)  // Command executed successfully
#define CMDE_NOBROKER  (-1) // Broker was not found
#define CMDE_NOPORT    (-2) // Broker's port was not found
#define CMDE_NOMEM     (-3) // Out of memory

/*****************************************************************************/

struct InputXpression
{
    uint8 ix_Version;    /* must be set to IX_VERSION */
    uint8 ix_Class;      /* class must match exactly  */

    uint16 ix_Code;      /* Bits that we want */
    uint16 ix_CodeMask;  /* Set bits here to indicate which bits in ix_Code
                          * are don't care bits.
                          */
    uint16 ix_Qualifier; /* Bits that we want */
    uint16 ix_QualMask;  /* Set bits here to indicate which bits in
                          * ix_Qualifier are don't care bits
                          */
    uint16 ix_QualSame;   /* synonyms in qualifier */
};

typedef struct InputXpression IX;

/* constant for InputXpression.ix_Version */
#define IX_VERSION 2

/* constants for InputXpression.ix_QualSame */
#define IXSYM_SHIFT 1 /* left- and right- shift are equivalent    */
#define IXSYM_CAPS  2 /* either shift or caps lock are equivalent */
#define IXSYM_ALT   4 /* left- and right- alt are equivalent      */

#define IXSYM_SHIFTMASK (IEQUALIFIER_LSHIFT | IEQUALIFIER_RSHIFT)
#define IXSYM_CAPSMASK  (IXSYM_SHIFTMASK    | IEQUALIFIER_CAPSLOCK)
#define IXSYM_ALTMASK   (IEQUALIFIER_LALT   | IEQUALIFIER_RALT)

/* constant for InputXpression.ix_QualMask */
#define IX_NORMALQUALS 0x7FFF /* avoid RELATIVEMOUSE */

/* matches nothing */
#define NULL_IX(ix) ((ix)->ix_Class == IECLASS_NULL)

/*****************************************************************************/

/* Error returns from CxBroker() */
#define CBERR_OK      0 /* No error                               */
#define CBERR_SYSERR  1 /* System error, no memory, etc           */
#define CBERR_DUP     2 /* uniqueness violation                   */
#define CBERR_VERSION 3 /* didn't understand NewBroker.nb_Version */

/*****************************************************************************/

/* Return values from CxObjError() */
#define COERR_ISNULL     1 /* you called CxObjError(NULL)        */
#define COERR_NULLATTACH 2 /* someone attached NULL to my list   */
#define COERR_BADFILTER  4 /* a bad filter description was given */
#define COERR_BADTYPE    8 /* unmatched type-specific operation  */

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/*****************************************************************************/

/* Returned from the CopyBrokerList() function (V53.4) */

struct CxBrokerCopy
{
    struct Node   Node;        // Embedded Node
    uint32        StructSize;  // Size of this structure
    struct Task  *Owner;       // Task which created the broker
    CONST_STRPTR  Name;        // Name of the broker
    CONST_STRPTR  Title;       // Title of the broker
    CONST_STRPTR  Description; // Short broker description
    uint32        Flags;       // See COF prefixed flags above
};

/*****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* LIBRARIES_COMMODITIES_H */
