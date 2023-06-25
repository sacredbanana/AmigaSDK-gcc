#ifndef ENVOY_NIPC_H
#define ENVOY_NIPC_H
/*
**    $VER: nipc.h 54.16 (22.08.2022)
**
**    Tags, types and structures for the nipc.library.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**          All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/* Tags for AllocTransactionA() */
#define TRN_Dummy            (TAG_USER + 0xB1100)
#define TRN_AllocReqBuffer   (TRN_Dummy + 1)
#define TRN_AllocRespBuffer  (TRN_Dummy + 2)
#define TRN_ReqDataNIPCBuff  (TRN_Dummy + 3)
#define TRN_RespDataNIPCBuff (TRN_Dummy + 4)

/* Tags for CreateEntityA(), GetEntityAttrsA(), SetEntityAttrsA().
 * Refer to the autodocs for each function -- not all tags are
 * appropriate for each function!
 */
#define ENT_Dummy        (TAG_USER + 0xB1000)
#define ENT_Name         (ENT_Dummy + 1)
#define ENT_Public       (ENT_Dummy + 2)
#define ENT_Signal       (ENT_Dummy + 3)
#define ENT_AllocSignal  (ENT_Dummy + 4)
#define ENT_TimeoutLinks (ENT_Dummy + 5)
#define ENT_NameLength   (ENT_Dummy + 6)
#define ENT_Release      (ENT_Dummy + 7)
#define ENT_Inherit      (ENT_Dummy + 8)


struct Transaction
{
   struct Message trans_Msg;            /* Messages are used as the carrier for local transactions */
   struct Entity *trans_SourceEntity;   /* Filled in by nipc.library */
   struct Entity *trans_DestinationEntity;
                                        /* Filled in by nipc.library */
   UBYTE          trans_Command;        /* A field that's server-proprietary */
   UBYTE          trans_Type;           /* Req, Response */
   ULONG          trans_Error;          /* any error values */
   ULONG          trans_Flags;          /* see below */
   ULONG          trans_Sequence;       /* Used by the library to maintain sequences (nipc internal) */
   APTR           trans_RequestData;    /* ptr to request data buffer */
   ULONG          trans_ReqDataLength;  /* The length of data in the above buffer */
   ULONG          trans_ReqDataActual;  /* The length of valid data in the request buffer */
   APTR           trans_ResponseData;   /* ptr to response data buffer */
   ULONG          trans_RespDataLength; /* The size of the buffer above */
   ULONG          trans_RespDataActual; /* When data is returned in a response, the amount of the buffer used */
   UWORD          trans_Timeout;        /* Number of seconds before a timeout */
   UWORD          trans_Reserved;       /* Reserved for future use */
   ULONG          trans_ClientPrivate;  /* Client specific user data field */
   ULONG          trans_ServerPrivate;  /* Server specific user data field */
};

/*
** Note: The trans_ClientPrivate and trans_ServerPrivate fields do NOT get
** transmitted over the network, and are there for your convenience.  Clients
** should never depend on or modify trans_ServerPrivate, and servers should never
** depend on or modify trans_ClientPrivate.
*/

/* Types */
#define TYPE_REQUEST          0  /* Waiting to be serviced */
#define TYPE_RESPONSE         1  /* Has been serviced */
#define TYPE_SERVICING        2  /* Currently being serviced */
#define TYPE_NOT_ISSUED     255  /* Not yet issued */

/* Flags */
#define TRANSF_REQBUFFERALLOC  1 /* set if FreeTransaction is responsible for freeing the buffer */
#define TRANSF_RESPBUFFERALLOC 2 /* set if FreeTransaction is responsible for freeing the buffer */
#define TRANSF_NOWAIT          4 /* BeginTransaction isn't allowed to Wait() on this transaction */
#define TRANSF_REQUESTTABLE    8 /* The RequestData for this transaction is a table ptr */
#define TRANSF_RESPONSETABLE  16 /* The ResponseData for this transaction is a table ptr */
#define TRANSF_REQNIPCBUFF    32 /* trans_RequestData points to a struct NIPCBuff */
#define TRANSF_RESPNIPCBUFF   64 /* trans_ResponseData points to a struct NIPCBuff */

#define TRANSB_REQBUFFERALLOC  0 /* set if FreeTransaction is responsible for freeing the buffer */
#define TRANSB_RESPBUFFERALLOC 1 /* set if FreeTransaction is responsible for freeing the buffer */
#define TRANSB_NOWAIT          2 /* BeginTransaction isn't allowed to Wait() on this transaction */
#define TRANSB_REQUESTTABLE    3 /* The RequestData for this transaction is a table ptr */
#define TRANSB_RESPONSETABLE   4 /* The ResponseData for this transaction is a table ptr */
#define TRANSB_REQNIPCBUFF     5 /* trans_RequestData points to a struct NIPCBuff */
#define TRANSB_RESPNIPCBUFF    6 /* trans_ResponseData points to a struct NIPCBuff */

struct NIPCBuff
{
    struct MinNode nbuff_Link;
    struct MinList nbuff_Entries;

    /* Anything below here is NIPC Private! Do NOT touch */
};

struct NIPCBuffEntry
{
    struct MinNode  nbe_Link;
    ULONG           nbe_Offset;
    ULONG           nbe_Length;
    ULONG           nbe_PhysicalLength;
    UBYTE          *nbe_Data;

    /* Anything below here is NIPC Private! Do NOT touch */
};

/* Currently defined tags for NIPCInquery() */

#define QUERY_IPADDR       (TAG_USER + 0x2000) /* Get machine's IP address (Not guranteed to be supported) */
#define MATCH_IPADDR       (TAG_USER + 0x2001) /* Answer if ti_Data == Machine's IP address */

#define QUERY_REALMS       (TAG_USER + 0x2002) /* Get names of all known realms */
#define MATCH_REALM        (TAG_USER + 0x2003) /* Answer if machine's realm = ti_Data */

#define QUERY_HOSTNAME     (TAG_USER + 0x2004) /* Get hostname */
#define MATCH_HOSTNAME     (TAG_USER + 0x2005) /* Answer if hostname = ti_Data */

#define QUERY_SERVICE      (TAG_USER + 0x2006) /* Get list of services */
#define MATCH_SERVICE      (TAG_USER + 0x2007) /* Answer if service in ti_Data is available */

#define QUERY_ENTITY       (TAG_USER + 0x2008) /* Get list of entities */
#define MATCH_ENTITY       (TAG_USER + 0x2009) /* Answer if entity in ti_Data is available */

#define QUERY_OWNER        (TAG_USER + 0x200A) /* Get machines's owner */
#define MATCH_OWNER        (TAG_USER + 0x200B) /* Answer if owner = ti_Data */

#define QUERY_MACHDESC     (TAG_USER + 0x200C) /* For future use, currently ignored */
#define MATCH_MACHDESC     (TAG_USER + 0x200D) /* For future use, currently ignored */

#define QUERY_ATTNFLAGS    (TAG_USER + 0x200E) /* Get ExecBase->AttnFlags */
#define MATCH_ATTNFLAGS    (TAG_USER + 0x200F) /* Answer if (ti_Data & ExecBase->AttnFlags) */

/* QUERY LIBVERSION and MATCH_LIBVERSION are not yet implemented */
#define QUERY_LIBVERSION   (TAG_USER + 0x2010) /* Get a specific library version number (see nipc.library autodocs) */
#define MATCH_LIBVERSION   (TAG_USER + 0x2011) /* Answer if specific library version >= ti_Data */
/* QUERY LIBVERSION and MATCH_LIBVERSION are not yet implemented */

#define QUERY_CHIPREVBITS  (TAG_USER + 0x2012) /* Get GfxBase->ChipRevBits */
#define MATCH_CHIPREVBITS  (TAG_USER + 0x2013) /* Answer if (ti_Data & GfxBase->ChipRevBits) */

#define QUERY_MAXFASTMEM   (TAG_USER + 0x2014) /* Get amount of Fast ram on a system */
#define MATCH_MAXFASTMEM   (TAG_USER + 0x2015) /* Answer if Maximum Fast ram >= ti_Data */

#define QUERY_AVAILFASTMEM (TAG_USER + 0x2016) /* Get amount of available fast mem */
#define MATCH_AVAILFASTMEM (TAG_USER + 0x2017) /* Answer if Available Fast ram >= ti_Data */

#define QUERY_MAXCHIPMEM   (TAG_USER + 0x2018) /* Get amount if Chip ram on a system */
#define MATCH_MAXCHIPMEM   (TAG_USER + 0x2019) /* Answer if Maximum Chip ram >= ti_Data */

#define QUERY_AVAILCHIPMEM (TAG_USER + 0x2020) /* Get amount of available Chip ram */
#define MATCH_AVAILCHIPMEM (TAG_USER + 0x2021) /* Answer if Available Chip ram >= ti_Data */

#define QUERY_KICKVERSION  (TAG_USER + 0x2022) /* Get KickStart Version */
#define MATCH_KICKVERSION  (TAG_USER + 0x2023) /* Answer if KickStart version >= ti_Data */

#define QUERY_WBVERSION    (TAG_USER + 0x2024) /* Get Workbench Version */
#define MATCH_WBVERSION    (TAG_USER + 0x2025) /* Answer if Workbench version >= ti_Data */

#define QUERY_NIPCVERSION  (TAG_USER + 0x2026) /* Get nipc.library Version */
#define MATCH_NIPCVERSION  (TAG_USER + 0x2027) /* Answer if nipc.library version >= ti_Data */

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


#endif /* ENVOY_NIPC_H */
