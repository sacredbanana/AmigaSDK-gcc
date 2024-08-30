#ifndef LIBRARIES_RESOURCE_H
#define LIBRARIES_RESOURCE_H
/*
**    $VER: resource.h 54.16 (22.08.2022)
**
**    resource.library definitions
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

typedef APTR RESOURCEFILE;
typedef ULONG RESOURCEID;

/****************************************************************************/

/* A gadget ID (Tag GA_ID) may contain the ID and the group ID
   ored together. The following definitions must be used to extract
   the original gadget ID (1024 different IDs are possible) and the
   group id (63 different group IDs are possible). */
#define RL_GADGETMASK  0x03FF
#define RL_GROUPMASK   0xFC00
#define RL_GADGETID(x) ((x) & RL_GADGETMASK)
#define RL_GROUPID(x)  (((x) & RL_GROUPMASK) >> 10)

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

#endif /* LIBRARIES_RESOURCE_H */
