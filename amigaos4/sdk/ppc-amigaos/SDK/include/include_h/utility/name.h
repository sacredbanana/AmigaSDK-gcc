#ifndef UTILITY_NAME_H
#define UTILITY_NAME_H
/*
**    $VER: name.h 53.29 (10.8.2015)
**
**    Namespace definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
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

/* The named object structure */
struct NamedObject
{
    APTR no_Object; /* Your pointer, for whatever you want */
};

/* Tags for AllocNamedObject() */
enum enAllocNamedObjectTags
{
    ANO_NameSpace = 4000, /* Tag to define namespace */
    ANO_UserSpace = 4001, /* tag to define userspace */
    ANO_Priority  = 4002, /* tag to define priority  */
    ANO_Flags     = 4003  /* tag to define flags     */
};

/* Flags for tag ANO_Flags */
enum enANOFlagBits
{
    NSB_NODUPS = 0,
    NSB_CASE   = 1
};

enum enANOFlags
{
    NSF_NODUPS = (1 << NSB_NODUPS), /* Default allow duplicates */
    NSF_CASE   = (1 << NSB_CASE)    /* Default to caseless...   */
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

#endif /* UTILITY_NAME_H */
