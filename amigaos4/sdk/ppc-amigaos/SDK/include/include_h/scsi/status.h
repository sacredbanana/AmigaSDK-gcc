#ifndef SCSI_STATUS_H
#define SCSI_STATUS_H

/*
**    $VER: status.h 54.16 (22.08.2022)
**
**    SCSI status codes
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

/* Status codes for SCSI-3 (from SAM, X3.270). */

enum SCSI_Status
{
    SCSI_GOOD                       = 0x00,
    SCSI_CHECK_CONDITION            = 0x02,
    SCSI_CONDITION_MET              = 0x04,
    SCSI_BUSY                       = 0x08,
    SCSI_INTERMEDIATE               = 0x10,
    SCSI_INTERMEDIATE_CONDITION_MET = 0x14,
    SCSI_RESERVATION_CONFLICT       = 0x18,
    SCSI_COMMAND_TERMINATED         = 0x22, /* Considered obsolete in SAM-2.
                                             * Oh well... */
    SCSI_TASK_SET_FULL              = 0x28,
    SCSI_ACA_ACTIVE                 = 0x30
};

/* All other codes are considered reserved. */

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

#endif /* SCSI_STATUS_H */
