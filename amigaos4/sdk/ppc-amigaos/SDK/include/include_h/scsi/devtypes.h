#ifndef SCSI_DEVTYPES_H
#define SCSI_DEVTYPES_H

/*
**    $VER: devtypes.h 54.16 (22.08.2022)
**
**    SCSI device types
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

enum SCSI_Device_types
{
    SCSI_TYPE_DIRECTACCESS             = 0,
    SCSI_TYPE_TAPE                     = 1,
    SCSI_TYPE_PRINTER                  = 2,
    SCSI_TYPE_PROCESSOR                = 3,
    SCSI_TYPE_WORM                     = 4,
    SCSI_TYPE_CDROM                    = 5,
    SCSI_TYPE_SCANNER                  = 6,
    SCSI_TYPE_OPTICAL_DISK             = 7,
    SCSI_TYPE_MEDIUM_CHANGER           = 8,
    SCSI_TYPE_COMMUNICATION            = 9,
    SCSI_TYPE_STORAGE_ARRAY            = 0x0C,  // SCC-2 Storage array controller device (e.g., RAID)
    SCSI_TYPE_ENCLOSURE_SERVICES       = 0x0D,  // SES Enclosure services device
    SCSI_TYPE_SIMPLIFIED_DIRECT_ACCESS = 0x0E,  // RBC Simplified direct-access device (e.g., magnetic disk)
    SCSI_TYPE_OPTICAL_CARD_RW          = 0x0F,  // OCRW Optical card reader/writer device
    SCSI_TYPE_BRIDGE_CONTROLLER        = 0x10,  // BCC Bridge Controller Commands
    SCSI_TYPE_OBJECT_STORAGE           = 0x11,  // OSD Object-based Storage Device
    SCSI_TYPE_UNKNOWN                  = 31
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

#endif /* SCSI_DEVTYPES_H */
