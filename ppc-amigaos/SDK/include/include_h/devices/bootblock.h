#ifndef DEVICES_BOOTBLOCK_H
#define DEVICES_BOOTBLOCK_H
/*
**    $VER: bootblock.h 54.16 (22.08.2022)
**
**    floppy BootBlock definition
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

struct BootBlock
{
    UBYTE bb_id[4];    /* 4 character identifier */
    LONG  bb_chksum;   /* boot block checksum (balance) */
    LONG  bb_dosblock; /* reserved for DOS patch */
};

#define BOOTSECTS   2 /* 1K bootstrap */

#define BBID_DOS    { 'D', 'O', 'S', '\0' }
#define BBID_KICK   { 'K', 'I', 'C', 'K' }

#define BBNAME_DOS  0x444F5300 /* 'DOS\0' */
#define BBNAME_KICK 0x4B49434B /* 'KICK' */

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


#endif /* DEVICES_BOOTBLOCK_H */
