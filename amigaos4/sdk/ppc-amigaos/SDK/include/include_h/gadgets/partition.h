#ifndef GADGETS_PARTITION_H
#define GADGETS_PARTITION_H
/*
** $VER: partition.h 54.16 (22.08.2022)
**
**  Definitions for the Partition BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**     All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
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

/*****************************************************************************/

/* Partition Node attributes */

#define PARTNA_Dummy       (TAG_USER + 0x5039500)

#define PARTNA_Start       (PARTNA_Dummy + 0x01)
   /* (ULONG) First cylinder of the partition. */

#define PARTNA_End         (PARTNA_Dummy + 0x02)
   /* (ULONG) Last cylinder of the partition. */

#define PARTNA_NodeSize    (PARTNA_Dummy + 0x03)
   /* (ULONG) Size of custom node. */

#define PARTNA_UserData    (PARTNA_Dummy + 0x04)
   /* (APTR) Owner specific data for the node. */

#define PARTNA_Color       (PARTNA_Dummy + 0x05)
   /* (UWORD) Palette color index of the partition. */

#define PARTNA_Pattern     (PARTNA_Dummy + 0x06)
   /* (UWORD *) Fill pattern of the partition. */

#define PARTNA_PatternSize (PARTNA_Dummy + 0x07)
   /* (UWORD) Size of the fill pattern. */

#define PARTNA_RenderHook  (PARTNA_Dummy + 0x08)
   /* (struct Hook *) Render hook for the partition box. */

/*****************************************************************************/

/* Additional attributes defined by the Partition gadget class */

#define PARTITION_Dummy            (REACTION_Dummy + 0x0039000)

#define PARTITION_First            (PARTITION_Dummy + 1)
   /* (ULONG) First usable cylinder (ISG). */

#define PARTITION_Last             (PARTITION_Dummy + 2)
   /* (ULONG) Last usable cylinder (ISG). */

#define PARTITION_PartitionList    (PARTITION_Dummy + 3)
   /* (struct List *) List of partition nodes (ISG). */

#define PARTITION_Active           (PARTITION_Dummy + 4)
   /* (ULONG) Index number of active zone (ISGNU). */

#define PARTITION_ActiveNode       (PARTITION_Dummy + 5)
   /* (struct Node *) Node of active zone, NULL for spaces (N). */

#define PARTITION_Color            (PARTITION_Dummy + 6)
   /* (UWORD) Default palette color index for partitions (ISG). */

#define PARTITION_Pattern          (PARTITION_Dummy + 7)
   /* (UWORD *) Default fill pattern for partitions (ISG). */

#define PARTITION_PatternSize      (PARTITION_Dummy + 8)
   /* (UWORD) Size of the default partitions fill pattern (ISG). */

#define PARTITION_RenderHook       (PARTITION_Dummy + 9)
   /* (struct Hook *) Default render hook for partitions (ISG). */

#define PARTITION_SpaceColor       (PARTITION_Dummy + 10)
   /* (UWORD) Palette color index for empty spaces (ISG). */

#define PARTITION_SpacePattern     (PARTITION_Dummy + 11)
   /* (UWORD *) Fill pattern for empty spaces (ISG). */

#define PARTITION_SpacePatternSize (PARTITION_Dummy + 12)
   /* (UWORD) Size of the spaces fill pattern (ISG). */

#define PARTITION_BackFill         (PARTITION_Dummy + 13)
   /* (struct Hook *) Backfill hook for empty spaces (ISG). */

#define PARTITION_Partition        (PARTITION_Dummy + 14)
   /* (ULONG) Index number of active partition, or ~0 if none (GNU). */

/*****************************************************************************/

/* Methods defined by the Partition gadget class */

#define PM_GETZONEINFO   0x00739001    /* Get information about a zone */
#define PM_GETZONEBOUNDS 0x00739002    /* Find out the bounds of a zone */
#define PM_ADDNODE       0x00739003    /* Create and add a new partition */
#define PM_REMNODE       0x00739004    /* Remove and delete a partition */
#define PM_EDITNODE      0x00739005    /* Change a partition's attributes */
#define PM_MAKENODE      0x00739006    /* Convert a space into a partition */

struct pgpGetZoneInfo
{
   ULONG               MethodID;         /* PM_GETZONEINFO */
   struct GadgetInfo * pgpgzi_GInfo;     /* Required GadgetInfo pointer */
   ULONG               pgpgzi_ZoneIndex; /* Zone to inquire about */
   ULONG *             pgpgzi_Start;     /* Start of the zone */
   ULONG *             pgpgzi_End;       /* End of the zone */
   ULONG *             pgpgzi_Type;      /* Zone type - see below */
   struct Node **      pgpgzi_Partition; /* NULL if empty space */
   struct IBox *       pgpgzi_ZoneBox;   /* Actual box of the zone */
};

#define PGZONE_SPACE     (0)  /* Empty space */
#define PGZONE_PARTITION (1)  /* Real partition */

struct pgpGetZoneBounds
{
   ULONG               MethodID;         /* PM_GETZONEBOUNDS */
   struct GadgetInfo * pgpgzb_GInfo;     /* Required GadgetInfo pointer */
   ULONG               pgpgzb_ZoneIndex; /* Zone to inquire about */
   ULONG *             pgpgzb_MinCyl;    /* Minimum usable cylinder */
   ULONG *             pgpgzb_MaxCyl;    /* Maximum usable cylinder */
   struct Rectangle *  pgpgzb_Bounds;    /* Bounds of the zone in pixels */
};

struct pgpAddNode
{
   ULONG               MethodID;        /* PM_ADDNODE */
   struct GadgetInfo * pgpan_GInfo;     /* Required GadgetInfo pointer */
   struct TagItem    * pgpan_NodeAttrs; /* AllocPartitionNodeA() taglist */
};

struct pgpRemNode
{
   ULONG               MethodID;    /* PM_REMNODE */
   struct GadgetInfo * pgprn_GInfo; /* Required GadgetInfo pointer */
   struct Node *       pgprn_Node;  /* Remove() this node */
};

struct pgpEditNode
{
   ULONG               MethodID;        /* PM_EDITNODE */
   struct GadgetInfo * pgpen_GInfo;     /* Required GadgetInfo pointer */
   struct Node *       pgpen_Node;      /* Modify this node */
   struct TagItem *    pgpen_NodeAttrs; /* SetPartitionNodeAttrsA() taglist */
};

struct pgpMakeNode
{
   ULONG               MethodID;        /* PM_MAKENODE */
   struct GadgetInfo * pgpmn_GInfo;     /* Required GadgetInfo pointer */
   ULONG               pgpmn_ZoneIndex; /* Zone to convert - must be a space! */
   struct TagItem *    pgpmn_NodeAttrs; /* AllocPartitionNodeA() taglist */
};

/*****************************************************************************/

/* Definitions for the PARTITION_RenderHook and PARTNA_RenderHook tags */

/* The different types of messages that a render hook can see */

#define PN_DRAW  0x202L  /* Draw yourself, with state */
#define PN_QUERY 0x203L  /* Report about your properties */

/* Possible return values from a render hook */

#define PNR_OK      0  /* The hook understands this message type */
#define PNR_UNKNOWN 1  /* The hook does not understand this message */

/* States for PNDrawMsg.pndm_State */

#define PNS_NORMAL           0  /* The usual             */
#define PNS_SELECTED         1  /* For selected gadgets  */
#define PNS_NORMALDISABLED   2  /* For disabled gadgets  */
#define PNS_SELECTEDDISABLED 8  /* Disabled and selected */

/* Flags for PNQueryMsg.pnqm_AttrFlags */

#define PNRA_FULLRENDER 0x00000001  /* I render every pixel in my rectangle */

/* Structure of PN_DRAW messages, object is a (struct Node *) */

struct PNDrawMsg
{
    ULONG             pndm_MethodID;   /* PN_DRAW */
    struct RastPort  *pndm_RastPort;   /* Where to render to */
    struct DrawInfo  *pndm_DrawInfo;   /* Useful to have around */
    struct Rectangle  pndm_Bounds;     /* Limits of where to render */
    ULONG             pndm_State;      /* How to render */
};

/* Structure of PN_QUERY messages, object is a (struct Node *) */

struct PNQueryMsg
{
    ULONG             pnqm_MethodID;   /* PN_QUERY */
    struct RastPort  *pnqm_RastPort;   /* Where to render to */
    struct DrawInfo  *pnqm_DrawInfo;   /* Useful to have around */
    struct Rectangle  pnqm_Bounds;     /* Limits of where to render */
    ULONG             pnqm_State;      /* How to render */
    ULONG            *pnqm_AttrFlags;  /* Fill in with your properties */
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

#endif /* GADGETS_PARTITION_H */
