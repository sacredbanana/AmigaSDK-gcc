#ifndef DEVICES_KEYMAP_H
#define DEVICES_KEYMAP_H
/*
**    $VER: keymap.h 54.16 (22.08.2022)
**
**    key map definitions for keymap.resource
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   LIBRARIES_KEYMAP_H
#include <libraries/keymap.h>
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

/* the structure of keymap.resource */
/* OBSOLETE, use keymap.library     */
struct KeyMapResource
{
    struct Node kr_Node;
    struct List kr_List; /* a list of KeyMapNodes */
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

#endif /* DEVICES_KEYMAP_H */
