#ifndef RESOURCES_FILESYSRES_H
#define RESOURCES_FILESYSRES_H
/*
**    $VER: filesysres.h  54.100 (07.09.2020)
**
**    FileSystem.resource description
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2011 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   DOS_DOS_H
#include <dos/dos.h>
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

#define FSRNAME "FileSystem.resource"

/****************************************************************************/

struct FileSysResource
{
    struct Node  fsr_Node;           /* on resource list */
    STRPTR       fsr_Creator;        /* name of creator of this resource */
    struct List  fsr_FileSysEntries; /* list of FileSysEntry structs */
};

struct FileSysEntry
{
    struct Node fse_Node;       /* on fsr_FileSysEntries list */
                                /* ln_Name is of creator of this entry */
    uint32      fse_DosType;    /* DosType of this FileSystem */
    uint32      fse_Version;    /* ((Version<<16)|Revision) of this FileSystem */
    uint32      fse_PatchFlags; /* Bits set for those of the following that */
                                /*   need to be substituted into a standard */
                                /*   device node for this file system:  */
                                /*   eg: (FSEF_SEGLIST | FSEF_GLOBVEC) to  */
                                /*   substitute SegList & GlobalVec */
    uint32      fse_Type;       /* device node type: DLT_DEVICE (aka zero) */
    APTR        fse_Port;       /* standard dos message port field */
    BPTR        fse_Reserved1;  /* unused for devices, reserved for DOS use only */
    BSTR        fse_Handler;    /* filename to loadseg (if SegList is null) */
    uint32      fse_StackSize;  /* stacksize to use when starting task (in bytes) */
    int32       fse_Priority;   /* task priority when starting task (-128 to 127) */
    BPTR        fse_Startup;    /* startup msg: FileSysStartupMsg for disks */
    BPTR        fse_SegList;    /* code to run to start new task */
    int32       fse_GlobalVec;  /* global vector value for starting handler */
    /*
	** no more entries need exist than those implied by fse_PatchFlags.
    */
};

#define  fse_Task  fse_Port


/****************************************************************************/
/* Field definitions for patchflags. */

#define FSEF_TYPE        (1<<0)
#define FSEF_PORT        (1<<1)
/* #define FSEF_RESERVED1   (1<<2) */
#define FSEF_HANDLER     (1<<3)
#define FSEF_STACKSIZE   (1<<4)
#define FSEF_PRIORITY    (1<<5)
#define FSEF_STARTUP     (1<<6)
#define FSEF_SEGLIST     (1<<7)
#define FSEF_GLOBVEC     (1<<8)



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

#endif /* RESOURCES_FILESYSRES_H */
