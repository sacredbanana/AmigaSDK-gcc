#ifndef INTUITION_PLUGINS_H
#define INTUITION_PLUGINS_H
/*
**    $VER: plugins.h 54.16 (22.08.2022)
**
**    Definitions for GUI plugin implementors
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
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


/**************************************/
/*** The Intuition plugin interface ***/
/**************************************/

/* The main structure exported by a GUI plugin library (common part) */

struct GUIPlugin
{
   struct Node     Node;         /* Reserved, don't use             */
   ULONG           Version;      /* Version of the plugin           */
   ULONG           Type;         /* Type of plugin                  */
   ULONG           Attrs;        /* Type-specific attributes        */
   ULONG           Flags;        /* Additional information          */
   struct TagItem *AttrList;     /* Optional list of GUI attributes */
   ULONG           Reserved[4];  /* For future expansion            */

   /* Plugin-specific fields follow here */
};

/* Plugin attributes (flags) */

#define PA_INTERNAL 0x10000000  /* Plugin is implemented
                                   internally by Intuition */


/*********************************************************/
/*** Rendering hooks: common structure and definitions ***/
/*********************************************************/

/* Possible return values from a rendering hook */

#define RCB_OK      0  /* Hook understands this message type    */
#define RCB_UNKNOWN 1  /* Hook does not understand this message */

/* Structure of messages for rendering hooks: */
/* the object is context-specific.            */

struct RenderMsg
{
    ULONG             rm_MethodID;   /* Type of rendering to perform */
    struct RastPort  *rm_RastPort;   /* Where to render to           */
    struct DrawInfo  *rm_DrawInfo;   /* Context information          */
    struct Rectangle  rm_Bounds;     /* Limits of where to render    */
    ULONG             rm_State;      /* How to render                */
    APTR              rm_IAddress;   /* Subsystem-specific data      */
    ULONG             rm_Flags;      /* Subsystem-specific flags     */
    struct TagItem   *rm_TagList;    /* Additional information       */
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

#endif /* INTUITION_PLUGINS_H */
