#ifndef DOS_MOUNT_H
#define DOS_MOUNT_H
/*
**    $VER: mount.h  54.100 (07.09.2020)
**
**    Data structures used with mounting file systems
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

#ifndef DOS_ERRORS_H
#include <dos/errors.h>
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

/*
 * The type of device to mount
 */

/* A file system, which is associated with a block storage device */
#define MDT_FileSystem  0

/* Any other kind which does not require a block storage device */
#define MDT_Handler     1

/****************************************************************************/

/*
 * Control tags which describe the device MountDevice() should mount
 */

#define MD_Dummy      (TAG_USER+4000)

/* Sector size in bytes (ULONG); must be a multiple of 4 */
#define MD_SectorSize (MD_Dummy+1)

/* Number of surfaces the file system should use (ULONG) */
#define MD_Surfaces   (MD_Dummy+2)

/* Number of sectors that make up a data block (ULONG) */
#define MD_SectorsPerBlock (MD_Dummy+3)

/* Number of sectors that make up a track (ULONG) */
#define MD_SectorsPerTrack (MD_Dummy+4)

/* Number of sectors at the beginning of the partition which
   should not be touched by the file system (ULONG) */
#define MD_Reserved (MD_Dummy+5)

/* Number of sectors at the end of the partition which
   should not be touched by the file system (ULONG) */
#define MD_PreAlloc (MD_Dummy+6)

/* Lowest cylinder number used by the file system (ULONG) */
#define MD_LowCyl   (MD_Dummy+7)

/* Highest cylinder number used by the file system (ULONG) */
#define MD_HighCyl  (MD_Dummy+8)

/* Number of data buffers the file system is to use (ULONG) */
#define MD_NumBuffers (MD_Dummy+9)

/* The type of memory to use for data buffers (ULONG) */
#define MD_BufMemType (MD_Dummy+10)

/* Maximum number of bytes the device driver can transfer
   in a single step (ULONG) */
#define MD_MaxTransfer (MD_Dummy+11)

/* Bit mask which covers the address range which the device driver
   can access (ULONG) */
#define MD_Mask (MD_Dummy+12)

/* File system signature, e.g. ID_DOS_DISK (ULONG) */
#define MD_DOSType (MD_Dummy+13)

/* Transmission speed (bits/second) to be used by the handler (ULONG) */
#define MD_Baud (MD_Dummy+14)

/* Control information for the handler/file system (STRPTR). */
#define MD_Control (MD_Dummy+15)

/* Name of the exec device driver this file system is to use (STRPTR). */
#define MD_Device (MD_Dummy+16)

/* Exec device driver unit number to be used by this file system (ULONG). */
#define MD_Unit (MD_Dummy+17)

/* Flags to use when the file system opens the exec device driver (ULONG). */
#define MD_Flags (MD_Dummy+18)

/* Size of the stack to allocate for the file system (ULONG). */
#define MD_StackSize (MD_Dummy+19)

/* Priority to start the file system process with (LONG). */
#define MD_Priority (MD_Dummy+20)

/* Global vector number (LONG). */
#define MD_GlobVec (MD_Dummy+21)

/* The number to store as the file system startup data (LONG). */
#define MD_StartupNumber (MD_Dummy+22)

/* The string to store as the file system startup data (STRPTR). */
#define MD_StartupString (MD_Dummy+23)

/* Whether the file system parameters should be initialized from the
   FileSystem.resource or not (BOOL). */
#define MD_IgnoreFSR (MD_Dummy+24)

/* Whether the file system should be activated immediately after it
   has been mounted (BOOL). */
#define MD_Activate (MD_Dummy+25)

/* Name of the handler which implements the file system (STRPTR). */
#define MD_Handler (MD_Dummy+26)

/* The segment list which refers to the code which implements the
   file system (BPTR). */
#define MD_SegList (MD_Dummy+27)

/* The port which implements the file system (struct MsgPort *). */
#define MD_Port (MD_Dummy+28)

/* The function which implements the file system (VOID (*)(VOID)). */
#define MD_Entry (MD_Dummy+29)

/****************************************************************************/

/*
 * All error codes defined for MountDevice() can be found in the
 * <dos/errors.h> header file.
 */

/****************************************************************************/

/*
 * Flags for DismountDevice()
 */
 
#define    DMDF_KEEPDEVICE          (1<<0)
#define    DMDF_REMOVEDEVICE        (1<<1)
#define    DMDF_FORCE_DISMOUNT      (1<<2)

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

#endif /* DOS_MOUNT_H */
