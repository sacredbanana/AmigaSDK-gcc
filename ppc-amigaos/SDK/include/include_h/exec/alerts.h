#ifndef EXEC_ALERTS_H
#define EXEC_ALERTS_H
/*
**    $VER: alerts.h 53.29 (10.8.2015)
**
**    Alert numbers, as displayed by system crashes.
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

/****************************************************************************/

/*********************************************************************
*
*  Format of the alert error number:
*
*    +-+-------------+----------------+--------------------------------+
*    |D|  SubSysId   |  General Error |    SubSystem Specific Error    |
*    +-+-------------+----------------+--------------------------------+
*     1    7 bits          8 bits                  16 bits
*
*                    D:  DeadEnd alert
*             SubSysId:  indicates ROM subsystem number.
*        General Error:  roughly indicates what the error was
*       Specific Error:  indicates more detail
**********************************************************************/

/**********************************************************************
*
*  Hardware/CPU specific alerts:  They may show without the 8 at the
*  front of the number.  These are CPU/68000 specific.  See 680x0
*  programmer's manuals for more details.
*
**********************************************************************/

#define ACPU_BusErr     0x80000002UL /* Hardware bus fault/access error */
#define ACPU_AddressErr 0x80000003UL /* Illegal address access (ie: odd) */
#define ACPU_InstErr    0x80000004UL /* Illegal instruction */
#define ACPU_DivZero    0x80000005UL /* Divide by zero */
#define ACPU_CHK        0x80000006UL /* Check instruction error */
#define ACPU_TRAPV      0x80000007UL /* TrapV instruction error */
#define ACPU_PrivErr    0x80000008UL /* Privilege violation error */
#define ACPU_Trace      0x80000009UL /* Trace error */
#define ACPU_LineA      0x8000000AUL /* Line 1010 Emulator error */
#define ACPU_LineF      0x8000000BUL /* Line 1111 Emulator error */
#define ACPU_Format     0x8000000EUL /* Stack frame format error */
#define ACPU_Spurious   0x80000018UL /* Spurious interrupt error */
#define ACPU_AutoVec1   0x80000019UL /* AutoVector Level 1 interrupt error */
#define ACPU_AutoVec2   0x8000001AUL /* AutoVector Level 2 interrupt error */
#define ACPU_AutoVec3   0x8000001BUL /* AutoVector Level 3 interrupt error */
#define ACPU_AutoVec4   0x8000001CUL /* AutoVector Level 4 interrupt error */
#define ACPU_AutoVec5   0x8000001DUL /* AutoVector Level 5 interrupt error */
#define ACPU_AutoVec6   0x8000001EUL /* AutoVector Level 6 interrupt error */
#define ACPU_AutoVec7   0x8000001FUL /* AutoVector Level 7 interrupt error */

/*********************************************************************
*
*  General Alerts
*
*  For example: timer.device cannot open math.library would be 0x05038015
*
*       Alert(AN_TimerDev|AG_OpenLib|AO_MathLib);
*
*********************************************************************/

/*------ alert types */
#define AT_DeadEnd      0x80000000UL
#define AT_Recovery     0x00000000UL

/*------ general purpose alert codes */
#define AG_NoMemory     0x00010000UL
#define AG_MakeLib      0x00020000UL
#define AG_OpenLib      0x00030000UL
#define AG_OpenDev      0x00040000UL
#define AG_OpenRes      0x00050000UL
#define AG_IOError      0x00060000UL
#define AG_NoSignal     0x00070000UL
#define AG_BadParm      0x00080000UL
#define AG_CloseLib     0x00090000UL /* usually too many closes */
#define AG_CloseDev     0x000A0000UL /* or a mismatched close */
#define AG_ProcCreate   0x000B0000UL /* Process creation failed */
#define AG_Obsolete     0x000C0000UL /* Obsolete feature used */

/*------ alert objects: */
#define AO_ExecLib      0x00008001UL
#define AO_GraphicsLib  0x00008002UL
#define AO_LayersLib    0x00008003UL
#define AO_Intuition    0x00008004UL
#define AO_MathLib      0x00008005UL
#define AO_DOSLib       0x00008007UL
#define AO_RAMLib       0x00008008UL
#define AO_IconLib      0x00008009UL
#define AO_ExpansionLib 0x0000800AUL
#define AO_DiskfontLib  0x0000800BUL
#define AO_UtilityLib   0x0000800CUL
#define AO_KeyMapLib    0x0000800DUL
#define AO_NewlibLib    0x0000800EUL

#define AO_AudioDev     0x00008010UL
#define AO_ConsoleDev   0x00008011UL
#define AO_GamePortDev  0x00008012UL
#define AO_KeyboardDev  0x00008013UL
#define AO_TrackDiskDev 0x00008014UL
#define AO_TimerDev     0x00008015UL

#define AO_CIARsrc      0x00008020UL
#define AO_DiskRsrc     0x00008021UL
#define AO_MiscRsrc     0x00008022UL

#define AO_BootStrap    0x00008030UL
#define AO_Workbench    0x00008031UL
#define AO_DiskCopy     0x00008032UL
#define AO_GadTools     0x00008033UL
#define AO_Unknown      0x00008035UL

/*********************************************************************
*
*   Specific Alerts:
*
*   For example:   exec.library -- corrupted memory list
*
*           ALERT  AN_MemCorrupt        ;8100 0005
*
*********************************************************************/

/*------ exec.library */
#define AN_ExecLib      0x01000000UL
#define AN_ExcptVect    0x01000001UL /* 68000 exception vector checksum (obs.) */
#define AN_BaseChkSum   0x01000002UL /* Execbase checksum (obs.) */
#define AN_LibChkSum    0x01000003UL /* Library checksum failure */
#define AN_IFaceChkSum  0x01000004UL /* Interface checksum failure */

#define AN_MemCorrupt   0x81000005UL /* Corrupt memory list detected in FreeMem */
#define AN_IntrMem      0x81000006UL /* No memory for interrupt servers */
#define AN_InitAPtr     0x01000007UL /* InitStruct() of an APTR source (obs.) */
#define AN_SemCorrupt   0x01000008UL /* A semaphore is in an illegal state
                                        at ReleaseSemaphore() */
#define AN_FreeTwice    0x01000009UL /* Freeing memory already freed */
#define AN_BogusExcpt   0x8100000AUL /* illegal 68k exception taken (obs.) */
#define AN_IOUsedTwice  0x0100000BUL /* Attempt to reuse active IORequest */
#define AN_MemoryInsane 0x0100000CUL /* Sanity check on memory list failed
                                        during AvailMem(MEMF_LARGEST) */
#define AN_IOAfterClose 0x0100000DUL /* IO attempted on closed IORequest */
#define AN_StackProbe   0x0100000EUL /* Stack appears to extend out of range */
#define AN_BadFreeAddr  0x0100000FUL /* Memory header not located. [ Usually an
                                        invalid address passed to FreeMem() ] */
#define AN_BadSemaphore 0x01000010UL /* An attempt was made to use the old
                                        message semaphores. */
#define AN_BadMemory    0x01000011UL /* A bad memory request was made (Realloc
                                        on non-allocated memory) */
#define AN_BadHook      0x01000012UL /* An uninitialized hook was called */

/*------ graphics.library */
#define AN_GraphicsLib  0x02000000UL
#define AN_GfxNoMem     0x82010000UL /* graphics out of memory */
#define AN_GfxNoMemMspc 0x82010001UL /* MonitorSpec alloc, no memory */
#define AN_LongFrame    0x82010006UL /* long frame, no memory */
#define AN_ShortFrame   0x82010007UL /* short frame, no memory */
#define AN_TextTmpRas   0x02010009UL /* text, no memory for TmpRas */
#define AN_BltBitMap    0x8201000AUL /* BltBitMap, no memory */
#define AN_RegionMemory 0x8201000BUL /* regions, memory not available */
#define AN_MakeVPort    0x82010030UL /* MakeVPort, no memory */
#define AN_GfxNewError  0x0200000CUL
#define AN_GfxFreeError 0x0200000DUL

#define AN_GfxNoLCM     0x82011234UL /* emergency memory not available */

#define AN_ObsoleteFont 0x02000401UL /* unsupported font description used */

/*------ layers.library */
#define AN_LayersLib    0x03000000UL
#define AN_LayersNoMem  0x83010000UL /* layers out of memory */

/*------ intuition.library */
#define AN_Intuition    0x04000000UL
#define AN_GadgetType   0x84000001UL /* unknown gadget type */
#define AN_BadGadget    0x04000001UL /* Recovery form of AN_GadgetType */
#define AN_CreatePort   0x84010002UL /* create port, no memory */
#define AN_ItemAlloc    0x04010003UL /* item plane alloc, no memory */
#define AN_SubAlloc     0x04010004UL /* sub alloc, no memory */
#define AN_PlaneAlloc   0x84010005UL /* plane alloc, no memory */
#define AN_ItemBoxTop   0x84000006UL /* item box top < RelZero */
#define AN_OpenScreen   0x84010007UL /* open screen, no memory */
#define AN_OpenScrnRast 0x84010008UL /* open screen, raster alloc, no memory */
#define AN_SysScrnType  0x84000009UL /* open sys screen, unknown type */
#define AN_AddSWGadget  0x8401000AUL /* add SW gadgets, no memory */
#define AN_OpenWindow   0x8401000BUL /* open window, no memory */
#define AN_BadState     0x8400000CUL /* Bad State Return entering Intuition */
#define AN_BadMessage   0x8400000DUL /* Bad Message received by IDCMP */
#define AN_WeirdEcho    0x8400000EUL /* Weird echo causing incomprehension */
#define AN_NoConsole    0x8400000FUL /* couldn't open the Console Device */
#define AN_NoISem       0x04000010UL /* Intuition skipped obtaining a sem */
#define AN_ISemOrder    0x04000011UL /* Intuition obtained a sem in bad order */

/*------ math.library */
#define AN_MathLib      0x05000000UL

/*------ dos.library */
#define AN_DOSLib       0x07000000UL
#define AN_StartMem     0x07010001UL /* no memory at startup */
#define AN_EndTask      0x07000002UL /* EndTask didn't */
#define AN_QPktFail     0x07000003UL /* Qpkt failure */
#define AN_AsyncPkt     0x07000004UL /* Unexpected packet received */
#define AN_FreeVec      0x07000005UL /* Freevec failed */
#define AN_DiskBlkSeq   0x07000006UL /* Disk block sequence error */
#define AN_BitMap       0x07000007UL /* Bitmap corrupt */
#define AN_KeyFree      0x07000008UL /* Key already free */
#define AN_BadChkSum    0x07000009UL /* Invalid checksum */
#define AN_DiskError    0x0700000AUL /* Disk Error */
#define AN_KeyRange     0x0700000BUL /* Key out of range */
#define AN_BadOverlay   0x0700000CUL /* Bad overlay */
#define AN_BadInitFunc  0x0700000DUL /* Invalid init packet for cli/shell */
#define AN_FileReclosed 0x0700000EUL /* A filehandle was closed more than once */
#define AN_NoBootNode   0x0700000FUL /* No bootnode found in eb_MountList */

/*------ ramlib.library */
#define AN_RAMLib       0x08000000UL
#define AN_BadSegList   0x08000001UL /* no overlays in library seglists */

/*------ icon.library */
#define AN_IconLib      0x09000000UL

/*------ expansion.library */
#define AN_ExpansionLib     0x0A000000UL
#define AN_BadExpansionFree 0x0A000001UL /* freed free region */

/*------ diskfont.library */
#define AN_DiskfontLib  0x0B000000UL

/*------ newlib.library */
#define AN_NewlibLib    0x0E000000UL

/*------ audio.device */
#define AN_AudioDev     0x10000000UL

/*------ console.device */
#define AN_ConsoleDev   0x11000000UL
#define AN_NoWindow     0x11000001UL /* Console can't open initial window */

/*------ gameport.device */
#define AN_GamePortDev  0x12000000UL

/*------ keyboard.device */
#define AN_KeyboardDev  0x13000000UL

/*------ trackdisk.device */
#define AN_TrackDiskDev 0x14000000UL
#define AN_TDCalibSeek  0x14000001UL /* calibrate: seek error */
#define AN_TDDelay      0x14000002UL /* delay: error on timer wait */

/*------ timer.device */
#define AN_TimerDev     0x15000000UL
#define AN_TMBadReq     0x15000001UL /* bad request */
#define AN_TMBadSupply  0x15000002UL /* power supply -- no 50/60Hz ticks */

/*------ cybppc.device */
#define AN_CybppcDev    0x16000000UL
#define AN_CybppcNoTerm 0x16000001UL /* no termination */
#define AN_CybppcNoWide 0x16000002UL /* no wide termination */

/*------ cia.resource */
#define AN_CIARsrc      0x20000000UL

/*------ disk.resource */
#define AN_DiskRsrc     0x21000000UL
#define AN_DRHasDisk    0x21000001UL /* get unit: already has disk */
#define AN_DRIntNoAct   0x21000002UL /* interrupt: no active unit */

/*------ misc.resource */
#define AN_MiscRsrc     0x22000000UL

/*------ bootstrap */
#define AN_BootStrap    0x30000000UL
#define AN_BootError    0x30000001UL /* boot code returned an error */

/*------ Workbench */
#define AN_Workbench          0x31000000UL
#define AN_NoFonts            0xB1000001UL
#define AN_WBBadStartupMsg1   0x31000001UL
#define AN_WBBadStartupMsg2   0x31000002UL
#define AN_WBBadIOMsg         0x31000003UL /* Hacker code? */
#define AN_WBReLayoutToolMenu 0xB1010009UL /* GadTools broke? */

/*------ DiskCopy */
#define AN_DiskCopy     0x32000000UL

/*------ toolkit for Intuition */
#define AN_GadTools     0x33000000UL

/*------ System utility library */
#define AN_UtilityLib   0x34000000UL

/*------ For use by any application that needs it */
#define AN_Unknown      0x35000000UL

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_ALERTS_H */
