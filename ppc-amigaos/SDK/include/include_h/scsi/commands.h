#ifndef SCSI_COMMANDS_H
#define SCSI_COMMANDS_H

/*
**    $VER: commands.h 54.16 (22.08.2022)
**
**    Operation codes for SCSI-2 and SCSI-3 commands
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

/* scsi/commands.h

    Operation codes for SCSI-2 and SCSI-3 commands

   30 Nov 94   Peter Urbanec    Created file
   10 Jan 95   Peter Urbanec    Added SCSI_ prefix to all commands
   31 Jan 95   Peter Urbanec    Released to public

   07 Apr 99   Andrea Vallinotto Updated with some SCSI-3 commands
   15 Jun 99   Andrea Vallinotto Additional rework, removed redundant
               definitions. Released to public

   25 Apr 02   Andrea Vallinotto Turned #defines into enums for better debugger
               display. Released for inclusion in OS4
*/

/* All device types */
enum SCSI_Generic_CMDs
{
        SCSI_CHANGE_DEFINITION            = 0x40,
        SCSI_COMPARE                      = 0x39,
        SCSI_COPY                         = 0x18,
        SCSI_COPY_AND_VERIFY              = 0x3a,
        SCSI_INQUIRY                      = 0x12,
        SCSI_LOG_SELECT                   = 0x4c,
        SCSI_LOG_SENSE                    = 0x4d,
        SCSI_MODE_SELECT_6                = 0x15,
        SCSI_MODE_SELECT_10               = 0x55,
#define SCSI_MODE_SELECT                    SCSI_MODE_SELECT_6
        SCSI_MODE_SENSE_6                 = 0x1a,
        SCSI_MODE_SENSE_10                = 0x5a,
#define SCSI_MODE_SENSE                     SCSI_MODE_SENSE_6
        SCSI_PERISTENT_RESERVE_IN         = 0x5e,
        SCSI_PERISTENT_RESERVE_OUT        = 0x5f,
        SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL = 0x1e,
        SCSI_READ_BUFFER                  = 0x3c,
        SCSI_RECEIVE_DIAGNOSTIC_RESULTS   = 0x1c,
        SCSI_RELEASE_6                    = 0x17,
        SCSI_RELEASE_10                   = 0x57,
#define SCSI_RELEASE                        SCSI_RELEASE_6
        SCSI_REPORT_DEVICE_IDENTIFIER     = 0xa3,
        SCSI_REPORT_LUNS                  = 0xa0,
        SCSI_REQUEST_SENSE                = 0x03,
        SCSI_RESERVE_6                    = 0x16,
        SCSI_RESERVE_10                   = 0x56,
#define SCSI_RESERVE                        SCSI_RESERVE_6
        SCSI_SEND_DIAGNOSTIC              = 0x1d,
        SCSI_SET_DEVICE_INDENTIFIER       = 0xa4,
        SCSI_TEST_UNIT_READY              = 0x00,
        SCSI_WRITE_BUFFER                 = 0x3b
};

/* Direct Access devices */
enum SCSI_DA_CMDs 
{
        SCSI_DA_FORMAT_UNIT          = 0x04,
        SCSI_DA_LOCK_UNLOCK_CACHE    = 0x36,
        SCSI_DA_PRE_FETCH            = 0x34,
        SCSI_DA_READ_6               = 0x08,
        SCSI_DA_READ_10              = 0x28,
        SCSI_DA_READ_CAPACITY        = 0x25,
        SCSI_DA_READ_DEFECT_DATA_10  = 0x37,
#define SCSI_DA_READ_DEFECT_DATA       SCSI_DA_READ_DEFECT_DATA_10
        SCSI_DA_READ_DEFECT_DATA_12  = 0xb7,
        SCSI_DA_READ_LONG            = 0x3e,
        SCSI_DA_REASSIGN_BLOCKS      = 0x07,
        SCSI_DA_REBUILD              = 0x81,
        SCSI_DA_REGENERATE           = 0x82,
        SCSI_DA_REZERO_UNIT          = 0x01,
        SCSI_DA_SEARCH_DATA_EQUAL    = 0x31,
        SCSI_DA_SEARCH_DATA_HIGH     = 0x30,
        SCSI_DA_SEARCH_DATA_LOW      = 0x32,
        SCSI_DA_SEEK_6               = 0x0b,
        SCSI_DA_SEEK_10              = 0x2b,
        SCSI_DA_SET_LIMITS           = 0x33,
        SCSI_DA_START_STOP_UNIT      = 0x1b,
        SCSI_DA_SYNCHRONIZE_CACHE    = 0x35,
        SCSI_DA_VERIFY               = 0x2f,
        SCSI_DA_WRITE_6              = 0x0a,
        SCSI_DA_WRITE_10             = 0x2a,
        SCSI_DA_WRITE_AND_VERIFY     = 0x2e,
        SCSI_DA_WRITE_LONG           = 0x3f,
        SCSI_DA_WRITE_SAME           = 0x41,
        SCSI_DA_XDREAD               = 0x52,
        SCSI_DA_XDWRITE              = 0x50,
        SCSI_DA_XDWRITE_EXTENDED     = 0x80,
        SCSI_DA_XPWRITE              = 0x51
};

/* Sequential access devices */

enum SCSI_Tape_CMDs 
{
        SCSI_SA_ERASE                  = 0x19,
        SCSI_SA_FORMAT_MEDIUM          = 0x04,
        SCSI_SA_LOAD_UNLOAD            = 0x1b,
        SCSI_SA_LOCATE                 = 0x2b,
        SCSI_SA_READ                   = 0x08,
        SCSI_SA_READ_BLOCK_LIMITS      = 0x05,
        SCSI_SA_READ_POSITION          = 0x34,
        SCSI_SA_READ_REVERSE           = 0x0f,
        SCSI_SA_RECOVER_BUFFERED_DATA  = 0x14,
        SCSI_SA_RELEASE_6              = 0x17,
        SCSI_SA_RELEASE_10             = 0x57,
#define SCSI_SA_RELEASE_UNIT             SCSI_SA_RELEASE_6
        SCSI_SA_REPORT_DENSITY_SUPPORT = 0x44,
        SCSI_SA_RESERVE_6              = 0x16,
        SCSI_SA_RESERVE_10             = 0x56,
#define SCSI_SA_RESERVE_UNIT             SCSI_SA_RESERVE_6
        SCSI_SA_REWIND                 = 0x01,
        SCSI_SA_SPACE                  = 0x11,
        SCSI_SA_VERIFY                 = 0x13,
        SCSI_SA_WRITE                  = 0x0a,
        SCSI_SA_WRITE_FILEMARKS        = 0x10
};

/* Printer devices */

enum SCSI_Printer_CMDs 
{
        SCSI_PRT_FORMAT                = 0x04,
        SCSI_PRT_PRINT                 = 0x0a,
        SCSI_PRT_RECOVER_BUFFERED_DATA = 0x14,
        SCSI_PRT_RELEASE_UNIT_6        = SCSI_RELEASE_6,
        SCSI_PRT_RELEASE_UNIT_10       = SCSI_RELEASE_10,
        SCSI_PRT_RESERVE_UNIT_6        = SCSI_RESERVE_6,
        SCSI_PRT_RESERVE_UNIT_10       = SCSI_RESERVE_10,
        SCSI_PRT_SLEW_AND_PRINT        = 0x0b,
        SCSI_PRT_STOP_PRINT            = 0x1b,
        SCSI_PRT_SYNCHRONIZE_BUFFER    = 0x10
};

/* Processor devices */

enum SCSI_CPU_CMDs 
{
        SCSI_CPU_RECEIVE = 0x08,
        SCSI_CPU_SEND    = 0x0a
};

/* Write Once devices */

enum SCSI_WriteOnce_CMDs 
{
        SCSI_WO_LOCK_UNLOCK_CACHE    = 0x36,
        SCSI_WO_MEDIUM_SCAN          = 0x38,
        SCSI_WO_PRE_FETCH            = 0x34,
        SCSI_WO_READ_6               = 0x08,
        SCSI_WO_READ_10              = 0x28,
        SCSI_WO_READ_12              = 0xa8,
        SCSI_WO_READ_CAPACITY        = 0x25,
        SCSI_WO_READ_LONG            = 0x3e,
        SCSI_WO_REASSIGN_BLOCKS      = 0x07,
        SCSI_WO_REZERO_UNIT          = 0x01,
        SCSI_WO_SEARCH_DATA_EQUAL_10 = 0x31,
        SCSI_WO_SEARCH_DATA_EQUAL_12 = 0xb1,
        SCSI_WO_SEARCH_DATA_HIGH_10  = 0x30,
        SCSI_WO_SEARCH_DATA_HIGH_12  = 0xb0,
        SCSI_WO_SEARCH_DATA_LOW_10   = 0x32,
        SCSI_WO_SEARCH_DATA_LOW_12   = 0xb2,
        SCSI_WO_SEEK_6               = 0x0b,
        SCSI_WO_SEEK_10              = 0x2b,
        SCSI_WO_SET_LIMITS_10        = 0x33,
        SCSI_WO_SET_LIMITS_12        = 0xb3,
        SCSI_WO_START_STOP_UNIT      = SCSI_DA_START_STOP_UNIT,
        SCSI_WO_SYNCHRONIZE_CACHE    = SCSI_DA_SYNCHRONIZE_CACHE,
        SCSI_WO_VERIFY_10            = 0x2f,
        SCSI_WO_VERIFY_12            = 0xaf,
        SCSI_WO_WRITE_6              = 0x0a,
        SCSI_WO_WRITE_10             = 0x2a,
        SCSI_WO_WRITE_12             = 0xaa,
        SCSI_WO_WRITE_AND_VERIFY_10  = 0x2e,
        SCSI_WO_WRITE_AND_VERIFY_12  = 0xae,
        SCSI_WO_WRITE_LONG           = 0x3f
};

/* CD-ROM devices */

enum SCSI_CD_CMDs 
{
        SCSI_CD_LOAD_UNLOAD_CD                = 0xa6,
        SCSI_CD_LOCK_UNLOCK_CACHE             = 0x36,
        SCSI_CD_MECHANISM_STATUS              = 0xbd,
        SCSI_CD_PAUSE_RESUME                  = 0x4b,
        SCSI_CD_PLAY_AUDIO_10                 = 0x45,
        SCSI_CD_PLAY_AUDIO_12                 = 0xa5,
        SCSI_CD_PLAY_AUDIO_MSF                = 0x47,
        SCSI_CD_PLAY_AUDIO_TRACK_INDEX        = 0x48,
        SCSI_CD_PLAY_CD                       = 0xbc,
        SCSI_CD_PLAY_TRACK_RELATIVE_10        = 0x49,
        SCSI_CD_PLAY_TRACK_RELATIVE_12        = 0xa9,
        SCSI_CD_PRE_FETCH                     = 0x34,
        SCSI_CD_READ_CD                       = 0xbe,
        SCSI_CD_READ_CD_MSF                   = 0xb9,
        SCSI_CD_READ_CD_ROM_CAPACITY          = 0x25,
#define SCSI_CD_READ_CD_ROM_RECORDED_CAPACITY   SCSI_CD_READ_CD_ROM_CAPACITY
        SCSI_CD_READ_HEADER                   = 0x44,
        SCSI_CD_READ_SUB_CHANNEL              = 0x42,
        SCSI_CD_READ_TOC_PMA_ATIP             = 0x43,
#define SCSI_CD_READ_TOC                        SCSI_CD_READ_TOC_PMA_ATIP
        SCSI_CD_SCAN                          = 0xba,
        SCSI_CD_SEARCH_DATA_EQUAL_10          = SCSI_WO_SEARCH_DATA_EQUAL_10,
        SCSI_CD_SEARCH_DATA_EQUAL_12          = SCSI_WO_SEARCH_DATA_EQUAL_12,
        SCSI_CD_SEARCH_DATA_HIGH_10           = SCSI_WO_SEARCH_DATA_HIGH_10,
        SCSI_CD_SEARCH_DATA_HIGH_12           = SCSI_WO_SEARCH_DATA_HIGH_12,
        SCSI_CD_SEARCH_DATA_LOW_10            = SCSI_WO_SEARCH_DATA_LOW_10,
        SCSI_CD_SEARCH_DATA_LOW_12            = SCSI_WO_SEARCH_DATA_LOW_12,
        SCSI_CD_SEEK_6                        = 0x0b,
        SCSI_CD_SEEK_10                       = 0x2b,
        SCSI_CD_SET_CD_SPEED                  = 0xbb,
        SCSI_CD_SET_LIMITS_10                 = SCSI_WO_SET_LIMITS_10,
        SCSI_CD_SET_LIMITS_12                 = SCSI_WO_SET_LIMITS_12,
        SCSI_CD_START_STOP_UNIT               = SCSI_DA_START_STOP_UNIT,
        SCSI_CD_STOP_PLAY_SCAN                = 0x4e,
        SCSI_CD_SYNCHRONIZE_CACHE             = SCSI_DA_SYNCHRONIZE_CACHE,
        SCSI_CD_VERIFY_10                     = 0x2f,
        SCSI_CD_VERIFY_12                     = 0xaf
};

/* CD-RW devices */

enum SCSI_CDRW_CMDs 
{
        SCSI_CDRW_BLANK                  = 0xa1,
        SCSI_CDRW_CLOSE_TRACK_SESSION    = 0x5B,
        SCSI_CDRW_FORMAT_UNIT            = SCSI_DA_FORMAT_UNIT,
        SCSI_CDRW_READ_BUFFER_CAPACITY   = 0x5c,
        SCSI_CDRW_READ_DISK_INFORMATION  = 0x51,
        SCSI_CDRW_READ_MASTER_QUEUE      = 0x59,
        SCSI_CDRW_READ_TRACK_INFORMATION = 0x52,
        SCSI_CDRW_REPAIR_TRACK           = 0x58,
        SCSI_CDRW_RESERVE_TRACK          = 0x53,
        SCSI_CDRW_SEND_QUEUE_SHEET       = 0x5d,
        SCSI_CDRW_SEND_OPC_INFORMATION   = 0x54,
        SCSI_CDRW_SYNCRONIZE_CACHE       = SCSI_DA_SYNCHRONIZE_CACHE,
        SCSI_CDRW_WRITE_10               = SCSI_DA_WRITE_10
};

/* Scanner devices */

enum SCSI_Scanner_CMDs 
{
        SCSI_SC_GET_DATA_BUFFER_STATUS = 0x34,
        SCSI_SC_GET_WINDOW             = 0x25,
        SCSI_SC_OBJECT_POSITION        = 0x31,
        SCSI_SC_READ                   = SCSI_DA_READ_10,
        SCSI_SC_SCAN                   = 0x1b,
        SCSI_SC_SET_WINDOW             = 0x24,
        SCSI_SC_SEND                   = SCSI_DA_WRITE_10
};

/* Optical memory devices */

enum SCSI_OptiMem_CMDs 
{
        SCSI_OM_ERASE_10             = 0x2c,
        SCSI_OM_ERASE_12             = 0xac,
        SCSI_OM_FORMAT_UNIT          = 0x04,
        SCSI_OM_LOCK_UNLOCK_CACHE    = 0x36,
        SCSI_OM_MEDIUM_SCAN          = 0x38,
        SCSI_OM_PRE_FETCH            = 0x34,
        SCSI_OM_READ_6               = 0x08,
        SCSI_OM_READ_10              = 0x28,
        SCSI_OM_READ_12              = 0xa8,
        SCSI_OM_READ_CAPACITY        = 0x25,
        SCSI_OM_READ_DEFECT_DATA_10  = 0x37,
        SCSI_OM_READ_DEFECT_DATA_12  = 0xb7,
        SCSI_OM_READ_GENERATION      = 0x29,
        SCSI_OM_READ_LONG            = 0x3e,
        SCSI_OM_READ_UPDATED_BLOCK   = 0x2d,
        SCSI_OM_REASSIGN_BLOCKS      = 0x07,
        SCSI_OM_REZERO_UNIT          = 0x01,
        SCSI_OM_SEARCH_DATA_EQUAL_10 = 0x31,
        SCSI_OM_SEARCH_DATA_EQUAL_12 = 0xb1,
        SCSI_OM_SEARCH_DATA_HIGH_10  = 0x30,
        SCSI_OM_SEARCH_DATA_HIGH_12  = 0xb0,
        SCSI_OM_SEARCH_DATA_LOW_10   = 0x32,
        SCSI_OM_SEARCH_DATA_LOW_12   = 0xb2,
        SCSI_OM_SEEK_6               = 0x0b,
        SCSI_OM_SEEK_10              = 0x2b,
        SCSI_OM_SET_LIMITS_10        = 0x33,
        SCSI_OM_SET_LIMITS_12        = 0xb3,
        SCSI_OM_START_STOP_UNIT      = 0x1b,
        SCSI_OM_SYNCHRONIZE_CACHE    = SCSI_DA_SYNCHRONIZE_CACHE,
        SCSI_OM_UPDATE_BLOCK         = 0x3d,
        SCSI_OM_VERIFY_10            = 0x2f,
        SCSI_OM_VERIFY_12            = 0xaf,
        SCSI_OM_WRITE_6              = 0x0a,
        SCSI_OM_WRITE_10             = 0x2a,
        SCSI_OM_WRITE_12             = 0xaa,
        SCSI_OM_WRITE_AND_VERIFY_10  = 0x2e,
        SCSI_OM_WRITE_AND_VERIFY_12  = 0xae,
        SCSI_OM_WRITE_LONG           = 0x3f
};

/* Medium changer devices */

enum SCSI_MChanger_CMDs 
{
        SCSI_MC_EXCHANGE_MEDIUM                = 0xa6,
        SCSI_MC_INITIALIZE_ELEMENT_STATUS      = 0x07,
        SCSI_MC_MOVE_MEDIUM                    = 0xa5,
        SCSI_MC_MOVE_MEDIUM_ATTACHED           = 0xa7,
        SCSI_MC_POSITION_TO_ELEMENT            = 0x2b,
        SCSI_MC_READ_ELEMENT_STATUS            = 0xb8,
        SCSI_MC_READ_ELEMENT_STATUS_ATTACHED   = 0xb4,
        SCSI_MC_RELEASE_ELEMENT_6              = SCSI_RELEASE_6,
        SCSI_MC_RELEASE_ELEMENT_10             = SCSI_RELEASE_10,
        SCSI_MC_REQUEST_VOLUME_ELEMENT_ADDRESS = 0xb5,
        SCSI_MC_RESERVE_ELEMENT_6              = SCSI_RESERVE_6,
        SCSI_MC_RESERVE_ELEMENT_10             = SCSI_RESERVE_10,
        SCSI_MC_REZERO_UNIT                    = 0x01,
        SCSI_MC_SEND_VOLUME_TAG                = 0xb6
/* WARNING: =0xa5 and =0xb8 should be used on sequential devices only. */
};

/* Communications devices */

enum SCSI_Communication_CMDs 
{
        SCSI_COM_GET_MESSAGE_6   = 0x08,
        SCSI_COM_GET_MESSAGE_10  = 0x28,
        SCSI_COM_GET_MESSAGE_12  = 0xa8,
        SCSI_COM_SEND_MESSAGE_6  = 0x0a,
        SCSI_COM_SEND_MESSAGE_10 = 0x2a,
        SCSI_COM_SEND_MESSAGE_12 = 0xaa
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

#endif /* SCSI_COMMANDS_H */
