#ifndef SCSI_COMMANDS_H
#define SCSI_COMMANDS_H

/* scsi/commands.h

	Operation codes for SCSI-2 commands

   30 Nov 94   Peter Urbanec    Created file
   10 Jan 95   Peter Urbanec    Added SCSI_ prefix to all commands
   31 Jan 95   Peter Urbanec    Released to public

*/


/* All device types */

#define SCSI_CHANGE_DEFINITION                  0x40
#define SCSI_COMPARE                            0x39
#define SCSI_COPY                               0x18
#define SCSI_COPY_AND_VERIFY                    0x3a
#define SCSI_INQUIRY                            0x12
#define SCSI_LOG_SELECT                         0x4c
#define SCSI_LOG_SENSE                          0x4d
#define SCSI_MODE_SELECT_6                      0x15
#define SCSI_MODE_SELECT_10                     0x55
#define SCSI_MODE_SENSE_6                       0x1a
#define SCSI_MODE_SENSE_10                      0x5a
#define SCSI_READ_BUFFER                        0x3c
#define SCSI_RECEIVE_DIAGNOSTIC_RESULTS         0x1c
#define SCSI_REQUEST_SENSE                      0x03
#define SCSI_SEND_DIAGNOSTIC                    0x1d
#define SCSI_TEST_UNIT_READY                    0x00
#define SCSI_WRITE_BUFFER                       0x3b


/* Direct Access devices */

#define SCSI_DA_CHANGE_DEFINITION               0x40
#define SCSI_DA_COMPARE                         0x39
#define SCSI_DA_COPY                            0x18
#define SCSI_DA_COPY_AND_VERIFY                 0x3a
#define SCSI_DA_FORMAT_UNIT                     0x04
#define SCSI_DA_INQUIRY                         0x12
#define SCSI_DA_LOCK_UNLOCK_CACHE               0x36
#define SCSI_DA_LOG_SELECT                      0x4c
#define SCSI_DA_LOG_SENSE                       0x4d
#define SCSI_DA_MODE_SELECT_6                   0x15
#define SCSI_DA_MODE_SELECT_10                  0x55
#define SCSI_DA_MODE_SENSE_6                    0x1a
#define SCSI_DA_MODE_SENSE_10                   0x5a
#define SCSI_DA_PRE_FETCH                       0x34
#define SCSI_DA_PREVENT_ALLOW_MEDIUM_REMOVAL    0x1e
#define SCSI_DA_READ_6                          0x08
#define SCSI_DA_READ_10                         0x28
#define SCSI_DA_READ_12                         0xa8
#define SCSI_DA_READ_16                         0x88
#define SCSI_DA_READ_BUFFER                     0x3c
#define SCSI_DA_READ_CAPACITY                   0x25
#define SCSI_DA_READ_DEFECT_DATA                0x37
#define SCSI_DA_READ_LONG                       0x3e
#define SCSI_DA_REASSIGN_BLOCKS                 0x07
#define SCSI_DA_RECEIVE_DIAGNOSTIC_RESULTS      0x1c
#define SCSI_DA_RELEASE                         0x17
#define SCSI_DA_REQUEST_SENSE                   0x03
#define SCSI_DA_RESERVE                         0x16
#define SCSI_DA_REZERO_UNIT                     0x01
#define SCSI_DA_SEARCH_DATA_EQUAL               0x31
#define SCSI_DA_SEARCH_DATA_HIGH                0x30
#define SCSI_DA_SEARCH_DATA_LOW                 0x32
#define SCSI_DA_SEEK_6                          0x0b
#define SCSI_DA_SEEK_10                         0x2b
#define SCSI_DA_SEND_DIAGNOSTIC                 0x1d
#define SCSI_DA_SET_LIMITS                      0x33
#define SCSI_DA_START_STOP_UNIT                 0x1b
#define SCSI_DA_SYNCHRONIZE_CACHE               0x35
#define SCSI_DA_TEST_UNIT_READY                 0x00
#define SCSI_DA_VERIFY                          0x2f
#define SCSI_DA_WRITE_6                         0x0a
#define SCSI_DA_WRITE_10                        0x2a
#define SCSI_DA_WRITE_12                        0xaa
#define SCSI_DA_WRITE_16                        0x8a
#define SCSI_DA_WRITE_AND_VERIFY_10             0x2e
#define SCSI_DA_WRITE_AND_VERIFY_16             0x8e
#define	SCSI_DA_SERVICEACTIONIN			0x9e
	#define	SERVICEACTION_CAPACITY16	0x10
	#define	SERVICEACTION_READLONG16	0x11

#define	SCSI_DA_SERVICEACTIONOUT		0x9f
	#define	SERVICEACTION_WRITELONG16	0x11


/* Sequential access devices */

#define SCSI_SA_CHANGE_DEFINITION               0x40
#define SCSI_SA_COMPARE                         0x39
#define SCSI_SA_COPY                            0x18
#define SCSI_SA_COPY_AND_VERIFY                 0x3a
#define SCSI_SA_ERASE                           0x19
#define SCSI_SA_INQUIRY                         0x12
#define SCSI_SA_LOAD_UNLOAD                     0x1b
#define SCSI_SA_LOCATE                          0x2b
#define SCSI_SA_LOG_SELECT                      0x4c
#define SCSI_SA_LOG_SENSE                       0x4d
#define SCSI_SA_MODE_SELECT_6                   0x15
#define SCSI_SA_MODE_SELECT_10                  0x55
#define SCSI_SA_MODE_SENSE_6                    0x1a
#define SCSI_SA_MODE_SENSE_10                   0x5a
#define SCSI_SA_PREVENT_ALLOW_MEDIUM_REMOVAL    0x1e
#define SCSI_SA_READ                            0x08
#define SCSI_SA_READ_BLOCK_LIMITS               0x05
#define SCSI_SA_READ_BUFFER                     0x3c
#define SCSI_SA_READ_POSITION                   0x34
#define SCSI_SA_READ_REVERSE                    0x0f
#define SCSI_SA_RECEIVE_DIAGNOSTIC_RESULTS      0x1c
#define SCSI_SA_RECOVER_BUFFERED_DATA           0x14
#define SCSI_SA_RELEASE_UNIT                    0x17
#define SCSI_SA_REQUEST_SENSE                   0x03
#define SCSI_SA_RESERVE_UNIT                    0x16
#define SCSI_SA_REWIND                          0x01
#define SCSI_SA_SEND_DIAGNOSTIC                 0x1d
#define SCSI_SA_SPACE                           0x11
#define SCSI_SA_TEST_UNIT_READY                 0x00
#define SCSI_SA_VERIFY                          0x13
#define SCSI_SA_WRITE                           0x0a
#define SCSI_SA_WRITE_BUFFER                    0x3b
#define SCSI_SA_WRITE_FILEMARKS                 0x10


/* Printer devices */

#define SCSI_PRT_CHANGE_DEFINITION              0x40
#define SCSI_PRT_COMPARE                        0x39
#define SCSI_PRT_COPY                           0x18
#define SCSI_PRT_COPY_AND_VERIFY                0x3a
#define SCSI_PRT_FORMAT                         0x04
#define SCSI_PRT_INQUIRY                        0x12
#define SCSI_PRT_LOG_SELECT                     0x4c
#define SCSI_PRT_LOG_SENSE                      0x4d
#define SCSI_PRT_MODE_SELECT_6                  0x15
#define SCSI_PRT_MODE_SELECT_10                 0x55
#define SCSI_PRT_MODE_SENSE_6                   0x1a
#define SCSI_PRT_MODE_SENSE_10                  0x5a
#define SCSI_PRT_PRINT                          0x0a
#define SCSI_PRT_READ_BUFFER                    0x3c
#define SCSI_PRT_RECEIVE_DIAGNOSTIC_RESULTS     0x1c
#define SCSI_PRT_RECOVER_BUFFERED_DATA          0x14
#define SCSI_PRT_RELEASE_UNIT                   0x17
#define SCSI_PRT_REQUEST_SENSE                  0x03
#define SCSI_PRT_RESERVE_UNIT                   0x16
#define SCSI_PRT_SEND_DIAGNOSTIC                0x1d
#define SCSI_PRT_SLEW_AND_PRINT                 0x0b
#define SCSI_PRT_STOP_PRINT                     0x1b
#define SCSI_PRT_SYNCHRONIZE_BUFFER             0x10
#define SCSI_PRT_TEST_UNIT_READY                0x00
#define SCSI_PRT_WRITE_BUFFER                   0x3b


/* Processor devices */

#define SCSI_CPU_CHANGE_DEFINITION              0x40
#define SCSI_CPU_COMPARE                        0x39
#define SCSI_CPU_COPY                           0x18
#define SCSI_CPU_COPY_AND_VERIFY                0x3a
#define SCSI_CPU_INQUIRY                        0x12
#define SCSI_CPU_LOG_SELECT                     0x4c
#define SCSI_CPU_LOG_SENSE                      0x4d
#define SCSI_CPU_READ_BUFFER                    0x3c
#define SCSI_CPU_RECEIVE                        0x08
#define SCSI_CPU_RECEIVE_DIAGNOSTIC_RESULTS     0x1c
#define SCSI_CPU_REQUEST_SENSE                  0x03
#define SCSI_CPU_SEND                           0x0a
#define SCSI_CPU_SEND_DIAGNOSTIC                0x1d
#define SCSI_CPU_TEST_UNIT_READY                0x00
#define SCSI_CPU_WRITE_BUFFER                   0x3b


/* Write Once devices */

#define SCSI_WO_CHANGE_DEFINITION               0x40
#define SCSI_WO_COMPARE                         0x39
#define SCSI_WO_COPY                            0x18
#define SCSI_WO_COPY_AND_VERIFY                 0x3a
#define SCSI_WO_INQUIRY                         0x12
#define SCSI_WO_LOCK_UNLOCK_CACHE               0x36
#define SCSI_WO_LOG_SELECT                      0x4c
#define SCSI_WO_LOG_SENSE                       0x4d
#define SCSI_WO_MEDIUM_SCAN                     0x38
#define SCSI_WO_MODE_SELECT_6                   0x15
#define SCSI_WO_MODE_SELECT_10                  0x55
#define SCSI_WO_MODE_SENSE_6                    0x1a
#define SCSI_WO_MODE_SENSE_10                   0x5a
#define SCSI_WO_PRE_FETCH                       0x34
#define SCSI_WO_PREVENT_ALLOW_MEDIUM_REMOVAL    0x1e
#define SCSI_WO_READ_6                          0x08
#define SCSI_WO_READ_10                         0x28
#define SCSI_WO_READ_12                         0xa8
#define SCSI_WO_READ_BUFFER                     0x3c
#define SCSI_WO_READ_CAPACITY                   0x25
#define SCSI_WO_READ_LONG                       0x3e
#define SCSI_WO_REASSIGN_BLOCKS                 0x07
#define SCSI_WO_RECEIVE_DIAGNOSTIC_RESULTS      0x1c
#define SCSI_WO_RELEASE                         0x17
#define SCSI_WO_REQUEST_SENSE                   0x03
#define SCSI_WO_RESERVE                         0x16
#define SCSI_WO_REZERO_UNIT                     0x01
#define SCSI_WO_SEARCH_DATA_EQUAL_10            0x31
#define SCSI_WO_SEARCH_DATA_EQUAL_12            0xb1
#define SCSI_WO_SEARCH_DATA_HIGH_10             0x30
#define SCSI_WO_SEARCH_DATA_HIGH_12             0xb0
#define SCSI_WO_SEARCH_DATA_LOW_10              0x32
#define SCSI_WO_SEARCH_DATA_LOW_12              0xb2
#define SCSI_WO_SEEK_6                          0x0b
#define SCSI_WO_SEEK_10                         0x2b
#define SCSI_WO_SEND_DIAGNOSTIC                 0x1d
#define SCSI_WO_SET_LIMITS_10                   0x33
#define SCSI_WO_SET_LIMITS_12                   0xb3
#define SCSI_WO_START_STOP_UNIT                 0x1b
#define SCSI_WO_SYNCHRONIZE_CACHE               0x35
#define SCSI_WO_TEST_UNIT_READY                 0x00
#define SCSI_WO_VERIFY_10                       0x2f
#define SCSI_WO_VERIFY_12                       0xaf
#define SCSI_WO_WRITE_6                         0x0a
#define SCSI_WO_WRITE_10                        0x2a
#define SCSI_WO_WRITE_12                        0xaa
#define SCSI_WO_WRITE_AND_VERIFY_10             0x2e
#define SCSI_WO_WRITE_AND_VERIFY_12             0xae
#define SCSI_WO_WRITE_BUFFER                    0x3b
#define SCSI_WO_WRITE_LONG                      0x3f


/* CD-ROM devices */

#define SCSI_CD_BLANK                           0xa1
#define SCSI_CD_CLOSE_TRACK                     0x5b
#if 0
#define SCSI_CD_CHANGE_DEFINITION               0x40
#define SCSI_CD_COMPARE                         0x39
#define SCSI_CD_COPY                            0x18
#define SCSI_CD_COPY_AND_VERIFY                 0x3a
#endif
#define SCSI_CD_ERASE                           0x2c
#define SCSI_CD_FORMAT_UNIT                     0x04
#define SCSI_CD_GET_CONFIGURATION               0x46
#define SCSI_CD_GET_EVENT_STATUS_NOTIFICATION   0x4a
#define SCSI_CD_GET_PERFORMANCE                 0xac
#define SCSI_CD_INQUIRY                         0x12
#define SCSI_CD_LOAD_UNLOAD_MEDIUM              0xa6
#if 0
#define SCSI_CD_LOCK_UNLOCK_CACHE               0x36
#define SCSI_CD_LOG_SELECT                      0x4c
#define SCSI_CD_LOG_SENSE                       0x4d
#endif
#define SCSI_CD_MECHANISM_STATUS                0xbd
#if 0
#define SCSI_CD_MODE_SELECT_6                   0x15
#endif
#define SCSI_CD_MODE_SELECT_10                  0x55
#if 0
#define SCSI_CD_MODE_SENSE_6                    0x1a
#endif
#define SCSI_CD_MODE_SENSE_10                   0x5a
#define SCSI_CD_PAUSE_RESUME                    0x4b
#define SCSI_CD_PLAY_AUDIO_10                   0x45
#define SCSI_CD_PLAY_AUDIO_12                   0xa5
#define SCSI_CD_PLAY_AUDIO_MSF                  0x47
#define SCSI_CD_PLAY_AUDIO_TRACK_INDEX          0x48
#define SCSI_CD_PLAY_TRACK_RELATIVE_10          0x49
#define SCSI_CD_PLAY_TRACK_RELATIVE_12          0xa9
#define SCSI_CD_PRE_FETCH                       0x34
#define SCSI_CD_PREVENT_ALLOW_MEDIUM_REMOVAL    0x1e
#define SCSI_CD_READ_6                          0x08
#define SCSI_CD_READ_10                         0x28
#define SCSI_CD_READ_12                         0xa8
#define SCSI_CD_READ_BUFFER                     0x3c
#define SCSI_CD_READ_CD_ROM_CAPACITY            0x25
#define SCSI_CD_READ_HEADER                     0x44
#define SCSI_CD_READ_LONG                       0x3e
#define SCSI_CD_READ_SUB_CHANNEL                0x42
#define SCSI_CD_READ_TOC                        0x43
#define SCSI_CD_RECEIVE_DIAGNOSTIC_RESULT       0x1c
#define SCSI_CD_RELEASE                         0x17
#define SCSI_CD_REQUEST_SENSE                   0x03
#define SCSI_CD_RESERVE                         0x16
#define SCSI_CD_REZERO_UNIT                     0x01
#define SCSI_CD_SEARCH_DATA_EQUAL_10            0x31
#define SCSI_CD_SEARCH_DATA_EQUAL_12            0xb1
#define SCSI_CD_SEARCH_DATA_HIGH_10             0x30
#define SCSI_CD_SEARCH_DATA_HIGH_12             0xb0
#define SCSI_CD_SEARCH_DATA_LOW_10              0x32
#define SCSI_CD_SEARCH_DATA_LOW_12              0xb2
#define SCSI_CD_SEEK_6                          0x0b
#define SCSI_CD_SEEK_10                         0x2b
#define SCSI_CD_SEND_DIAGNOSTIC                 0x1d
#define SCSI_CD_SET_LIMITS_10                   0x33
#define SCSI_CD_SET_LIMITS_12                   0xb3
#define SCSI_CD_START_STOP_UNIT                 0x1b
#define SCSI_CD_SYNCHRONIZE_CACHE               0x35
#define SCSI_CD_TEST_UNIT_READY                 0x00
#define SCSI_CD_VERIFY_10                       0x2f
#define SCSI_CD_VERIFY_12                       0xaf
#define SCSI_CD_WRITE_BUFFER                    0x3b


/* Scanner devices */

#define SCSI_SC_CHANGE_DEFINITION               0x40
#define SCSI_SC_COMPARE                         0x39
#define SCSI_SC_COPY                            0x18
#define SCSI_SC_COPY_AND_VERIFY                 0x3a
#define SCSI_SC_GET_DATA_BUFFER_STATUS          0x34
#define SCSI_SC_GET_WINDOW                      0x25
#define SCSI_SC_INQUIRY                         0x12
#define SCSI_SC_LOG_SELECT                      0x4c
#define SCSI_SC_LOG_SENSE                       0x4d
#define SCSI_SC_MODE_SELECT_6                   0x15
#define SCSI_SC_MODE_SELECT_10                  0x55
#define SCSI_SC_MODE_SENSE_6                    0x1a
#define SCSI_SC_MODE_SENSE_10                   0x5a
#define SCSI_SC_OBJECT_POSITION                 0x31
#define SCSI_SC_READ                            0x28
#define SCSI_SC_READ_BUFFER                     0x3c
#define SCSI_SC_RECEIVE_DIAGNOSTIC_RESULTS      0x1c
#define SCSI_SC_RELEASE_UNIT                    0x17
#define SCSI_SC_REQUEST_SENSE                   0x03
#define SCSI_SC_RESERVE_UNIT                    0x16
#define SCSI_SC_SCAN                            0x1b
#define SCSI_SC_SET_WINDOW                      0x24
#define SCSI_SC_SEND                            0x2a
#define SCSI_SC_SEND_DIAGNOSTIC                 0x1d
#define SCSI_SC_TEST_UNIT_READY                 0x00
#define SCSI_SC_WRITE_BUFFER                    0x3b


/* Optical memory devices */

#define SCSI_OM_CHANGE_DEFINITION               0x40
#define SCSI_OM_COMPARE                         0x39
#define SCSI_OM_COPY                            0x18
#define SCSI_OM_COPY_AND_VERIFY                 0x3a
#define SCSI_OM_ERASE_10                        0x2c
#define SCSI_OM_ERASE_12                        0xac
#define SCSI_OM_FORMAT_UNIT                     0x04
#define SCSI_OM_INQUIRY                         0x12
#define SCSI_OM_LOCK_UNLOCK_CACHE               0x36
#define SCSI_OM_LOG_SELECT                      0x4c
#define SCSI_OM_LOG_SENSE                       0x4d
#define SCSI_OM_MEDIUM_SCAN                     0x38
#define SCSI_OM_MODE_SELECT_6                   0x15
#define SCSI_OM_MODE_SELECT_10                  0x55
#define SCSI_OM_MODE_SENSE_6                    0x1a
#define SCSI_OM_MODE_SENSE_10                   0x5a
#define SCSI_OM_PRE_FETCH                       0x34
#define SCSI_OM_PREVENT_ALLOW_MEDIUM_REMOVAL    0x1e
#define SCSI_OM_READ_6                          0x08
#define SCSI_OM_READ_10                         0x28
#define SCSI_OM_READ_12                         0xa8
#define SCSI_OM_READ_BUFFER                     0x3c
#define SCSI_OM_READ_CAPACITY                   0x25
#define SCSI_OM_READ_DEFECT_DATA_10             0x37
#define SCSI_OM_READ_DEFECT_DATA_12             0xb7
#define SCSI_OM_READ_GENERATION                 0x29
#define SCSI_OM_READ_LONG                       0x3e
#define SCSI_OM_READ_UPDATED_BLOCK              0x2d
#define SCSI_OM_REASSIGN_BLOCKS                 0x07
#define SCSI_OM_RECEIVE_DIAGNOSTIC_RESULTS      0x1c
#define SCSI_OM_RELEASE                         0x17
#define SCSI_OM_REQUEST_SENSE                   0x03
#define SCSI_OM_RESERVE                         0x16
#define SCSI_OM_REZERO_UNIT                     0x01
#define SCSI_OM_SEARCH_DATA_EQUAL_10            0x31
#define SCSI_OM_SEARCH_DATA_EQUAL_12            0xb1
#define SCSI_OM_SEARCH_DATA_HIGH_10             0x30
#define SCSI_OM_SEARCH_DATA_HIGH_12             0xb0
#define SCSI_OM_SEARCH_DATA_LOW_10              0x32
#define SCSI_OM_SEARCH_DATA_LOW_12              0xb2
#define SCSI_OM_SEEK_6                          0x0b
#define SCSI_OM_SEEK_10                         0x2b
#define SCSI_OM_SEND_DIAGNOSTIC                 0x1d
#define SCSI_OM_SET_LIMITS_10                   0x33
#define SCSI_OM_SET_LIMITS_12                   0xb3
#define SCSI_OM_START_STOP_UNIT                 0x1b
#define SCSI_OM_SYNCHRONIZE_CACHE               0x35
#define SCSI_OM_TEST_UNIT_READY                 0x00
#define SCSI_OM_UPDATE_BLOCK                    0x3d
#define SCSI_OM_VERIFY_10                       0x2f
#define SCSI_OM_VERIFY_12                       0xaf
#define SCSI_OM_WRITE_6                         0x0a
#define SCSI_OM_WRITE_10                        0x2a
#define SCSI_OM_WRITE_12                        0xaa
#define SCSI_OM_WRITE_AND_VERIFY_10             0x2e
#define SCSI_OM_WRITE_AND_VERIFY_12             0xae
#define SCSI_OM_WRITE_BUFFER                    0x3b
#define SCSI_OM_WRITE_LONG                      0x3f


/* Medium changer devices */

#define SCSI_MC_CHANGE_DEFINITION               0x40
#define SCSI_MC_EXCHANGE_MEDIUM                 0xa6
#define SCSI_MC_INITIALIZE_ELEMENT_STATUS       0x07
#define SCSI_MC_INQUIRY                         0x12
#define SCSI_MC_LOG_SELECT                      0x4c
#define SCSI_MC_LOG_SENSE                       0x4d
#define SCSI_MC_MODE_SELECT_6                   0x15
#define SCSI_MC_MODE_SELECT_10                  0x55
#define SCSI_MC_MODE_SENSE_6                    0x1a
#define SCSI_MC_MODE_SENSE_10                   0x5a
#define SCSI_MC_MOVE_MEDIUM                     0xa5
#define SCSI_MC_POSITION_TO_ELEMENT             0x2b
#define SCSI_MC_PREVENT_ALLOW_MEDIUM_REMOVAL    0x1e
#define SCSI_MC_READ_BUFFER                     0x3c
#define SCSI_MC_READ_ELEMENT_STATUS             0xb8
#define SCSI_MC_RECEIVE_DIAGNOSTIC_RESULTS      0x1c
#define SCSI_MC_RELEASE                         0x17
#define SCSI_MC_REQUEST_VOLUME_ELEMENT_ADDRESS  0xb5
#define SCSI_MC_REQUEST_SENSE                   0x03
#define SCSI_MC_RESERVE                         0x16
#define SCSI_MC_REZERO_UNIT                     0x01
#define SCSI_MC_SEND_DIAGNOSTIC                 0x1d
#define SCSI_MC_SEND_VOLUME_TAG                 0xb6
#define SCSI_MC_TEST_UNIT_READY                 0x00
#define SCSI_MC_WRITE_BUFFER                    0x3b


/* Communications devices */

#define SCSI_COM_CHANGE_DEFINITION              0x40
#define SCSI_COM_GET_MESSAGE_6                  0x08
#define SCSI_COM_GET_MESSAGE_10                 0x28
#define SCSI_COM_GET_MESSAGE_12                 0xa8
#define SCSI_COM_INQUIRY                        0x12
#define SCSI_COM_LOG_SELECT                     0x4c
#define SCSI_COM_LOG_SENSE                      0x4d
#define SCSI_COM_MODE_SELECT_6                  0x15
#define SCSI_COM_MODE_SELECT_10                 0x55
#define SCSI_COM_MODE_SENSE_6                   0x1a
#define SCSI_COM_MODE_SENSE_10                  0x5a
#define SCSI_COM_READ_BUFFER                    0x3c
#define SCSI_COM_RECEIVE_DIAGNOSTIC_RESULTS     0x1c
#define SCSI_COM_REQUEST_SENSE                  0x03
#define SCSI_COM_SEND_DIAGNOSTIC                0x1d
#define SCSI_COM_SEND_MESSAGE_6                 0x0a
#define SCSI_COM_SEND_MESSAGE_10                0x2a
#define SCSI_COM_SEND_MESSAGE_12                0xaa
#define SCSI_COM_TEST_UNIT_READY                0x00
#define SCSI_COM_WRITE_BUFFER                   0x3b

#endif /* SCSI_COMMANDS_H */
