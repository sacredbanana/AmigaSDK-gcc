/****************************************************************************

                 __   __                                    V/\V.       /\
                |" | |" |                                   mMMnw,      || []
                |  | |  |                                  (o  o)W   () || ||
                |__|_|_"|                                  | /  |Mw  || ||//
                ("  "  \|                                  \ -'_/mw   \\||/
                 \______)                                   ~%%/WM"    \||
 _____    ___     ______  _____  __  _____     ___  __  __/~~__ ~~\    _||
|"("  \()/\" \ ()/"_    )|"(___) ) )|"("  \ ()/\" \(__)/" ) /" ) " \  /_)O
|  )   )/" \  \ (_/"\__/ |  )_  ( ( |  )_  ) /" \  \  /  /|/  / ·\  \/ ,|O
| (___/(  (_\__) _\  \_  | (__)  ) )| (__) |(  (_\__)/  /"/  /   |\   '_|O
|  |  _ \  /  / /" \_/ ) | ")__ ( ( |  )"  ) \  /  //  /|/  / . .|/\__/ ||
|__| (_) \/__/ (______/  |_(___) )_)|_(___/ . \/__/(__/ (__/ .:.:|      ||
                 _____
                |" __ \  Poseidon -- The divine USB stack for Amiga computers
                | (__) ) Version: 3.0 (03.06.04)
                |  __ (  Designed and written by
                |"(__) )   Chris Hodges <hodges@in.tum.de>
                |_____/  Copyright ©2002-2004 Chris Hodges. All rights reserved.

 ****************************************************************************/

/*
 *----------------------------------------------------------------------------
 *                         Includes for poseidon.library
 *----------------------------------------------------------------------------
 *                   By Chris Hodges <hodges@in.tum.de>
 *
 */

#ifndef POSEIDON_H
#define POSEIDON_H

#include <devices/usb.h>
#include <devices/usbhardware.h>
#include <devices/timer.h>
#include <exec/types.h>
#include <exec/libraries.h>
#include <exec/semaphores.h>
#include <exec/errors.h>
#include <dos/dos.h>
#include <utility/tagitem.h>
#include <utility/pack.h>
#include <libraries/iffparse.h>

/* Types for psdGetAttrs() and psdSetAttrs() */

#define PGA_STACK      0x01
#define PGA_USBCLASS   0x02
#define PGA_HARDWARE   0x03
#define PGA_DEVICE     0x04
#define PGA_CONFIG     0x05
#define PGA_INTERFACE  0x06
#define PGA_ENDPOINT   0x07
#define PGA_ERRORMSG   0x08
#define PGA_PIPE       0x09
#define PGA_APPBINDING 0x0a
#define PGA_EVENTNOTE  0x0b
#define PGA_STACKCFG   0x0c
#define PGA_PIPESTREAM 0x0d
#define PGA_LAST       0x0d

/* Tags for psdGetAttrs(PGA_STACK,...) */

#define PA_Dummy             (TAG_USER + 2612)
#define PA_ConfigRead        (PA_Dummy + 0x01)
#define PA_HardwareList      (PA_Dummy + 0x20)
#define PA_ClassList         (PA_Dummy + 0x21)
#define PA_ErrorMsgList      (PA_Dummy + 0x22)
#define PA_GlobalConfig      (PA_Dummy + 0x44)
#define PA_CurrConfigHash    (PA_Dummy + 0x45)
#define PA_SavedConfigHash   (PA_Dummy + 0x46)
#define PA_MemPoolUsage      (PA_Dummy + 0x50)

/* Tags for psdGetAttrs(PGA_ERRORMSG,...) */

#define EMA_Dummy            (TAG_USER  + 103)
#define EMA_Level            (EMA_Dummy + 0x10)
#define EMA_Origin           (EMA_Dummy + 0x11)
#define EMA_Msg              (EMA_Dummy + 0x12)

/* Tags for psdGetAttrs(PGA_USBCLASS,...) */

#define UCA_Dummy            (TAG_USER  + 4489)
#define UCA_ClassBase        (UCA_Dummy + 0x10)
#define UCA_ClassName        (UCA_Dummy + 0x11)
#define UCA_UseCount         (UCA_Dummy + 0x12)

/* Tags for psdGetAttrs(PGA_HARDWARE,...) */

#define HA_Dummy             (TAG_USER + 0x2612)
#define HA_DeviceName        (HA_Dummy + 0x10)
#define HA_DeviceUnit        (HA_Dummy + 0x11)
#define HA_ProductName       (HA_Dummy + 0x12)
#define HA_Manufacturer      (HA_Dummy + 0x13)
#define HA_Version           (HA_Dummy + 0x14)
#define HA_Revision          (HA_Dummy + 0x15)
#define HA_Description       (HA_Dummy + 0x16)
#define HA_Copyright         (HA_Dummy + 0x17)
#define HA_DriverVersion     (HA_Dummy + 0x18)
#define HA_DeviceList        (HA_Dummy + 0x20)

/* Tags for psdGetAttrs(PGA_DEVICE,...) */

#define DA_Dummy             (TAG_USER + 42)
#define DA_IsLowspeed        (DA_Dummy + 0x01)
#define DA_IsConnected       (DA_Dummy + 0x02)
#define DA_HasAddress        (DA_Dummy + 0x03)
#define DA_HasDevDesc        (DA_Dummy + 0x04)
#define DA_IsConfigured      (DA_Dummy + 0x05)
#define DA_HasAppBinding     (DA_Dummy + 0x06)
#define DA_IsHighspeed       (DA_Dummy + 0x07)
#define DA_IsDead            (DA_Dummy + 0x08)
#define DA_Address           (DA_Dummy + 0x10)
#define DA_NumConfigs        (DA_Dummy + 0x11)
#define DA_CurrConfig        (DA_Dummy + 0x12)
#define DA_HubDevice         (DA_Dummy + 0x13)
#define DA_UsbVersion        (DA_Dummy + 0x14)
#define DA_Class             (DA_Dummy + 0x15)
#define DA_SubClass          (DA_Dummy + 0x16)
#define DA_Protocol          (DA_Dummy + 0x17)
#define DA_Version           (DA_Dummy + 0x18)
#define DA_VendorID          (DA_Dummy + 0x19)
#define DA_ProductID         (DA_Dummy + 0x1a)
#define DA_Manufacturer      (DA_Dummy + 0x1b)
#define DA_ProductName       (DA_Dummy + 0x1c)
#define DA_SerialNumber      (DA_Dummy + 0x1d)
#define DA_Hardware          (DA_Dummy + 0x1e)
#define DA_Binding           (DA_Dummy + 0x1f)
#define DA_ConfigList        (DA_Dummy + 0x20)
#define DA_LangIDArray       (DA_Dummy + 0x21)
#define DA_CurrLangID        (DA_Dummy + 0x22)
#define DA_BindingClass      (DA_Dummy + 0x23)
#define DA_IDString          (DA_Dummy + 0x24)
#define DA_CloneCount        (DA_Dummy + 0x25)
#define DA_AtHubPortNumber   (DA_Dummy + 0x26)
#define DA_NeedsSplitTrans   (DA_Dummy + 0x27)
#define DA_OrigProductName   (DA_Dummy + 0x28)
#define DA_PowerSupply       (DA_Dummy + 0x30)
#define DA_PowerDrained      (DA_Dummy + 0x31)
#define DA_LowPower          (DA_Dummy + 0x32)
#define DA_InhibitPopup      (DA_Dummy + 0x40)
#define DA_IsNewToMe         (DA_Dummy + 0x41)
#define DA_InhibitClassBind  (DA_Dummy + 0x42)

/* Tags for psdGetAttrs(PGA_CONFIG,...) */

#define CA_Dummy             (TAG_USER + 23)
#define CA_Attrs             (CA_Dummy + 0x01)
#define CA_SelfPowered       (CA_Dummy + 0x02)
#define CA_RemoteWakeup      (CA_Dummy + 0x03)
#define CA_ConfigNum         (CA_Dummy + 0x10)
#define CA_MaxPower          (CA_Dummy + 0x11)
#define CA_ConfigName        (CA_Dummy + 0x12)
#define CA_NumInterfaces     (CA_Dummy + 0x13)
#define CA_Device            (CA_Dummy + 0x14)
#define CA_InterfaceList     (CA_Dummy + 0x20)

/* Tags for psdGetAttrs(PGA_INTERFACE,...) */

#define IFA_Dummy            (TAG_USER + 4711)
#define IFA_InterfaceNum     (IFA_Dummy + 0x10)
#define IFA_AlternateNum     (IFA_Dummy + 0x11)
#define IFA_Class            (IFA_Dummy + 0x12)
#define IFA_SubClass         (IFA_Dummy + 0x13)
#define IFA_Protocol         (IFA_Dummy + 0x14)
#define IFA_InterfaceName    (IFA_Dummy + 0x15)
#define IFA_Config           (IFA_Dummy + 0x16)
#define IFA_Binding          (IFA_Dummy + 0x17)
#define IFA_NumEndpoints     (IFA_Dummy + 0x18)
#define IFA_BindingClass     (IFA_Dummy + 0x19)
#define IFA_IDString         (IFA_Dummy + 0x1a)
#define IFA_EndpointList     (IFA_Dummy + 0x20)
#define IFA_AlternateIfList  (IFA_Dummy + 0x21)

/* Tags for psdGetAttrs(PGA_ENDPOINT,...) */

#define EA_Dummy             (TAG_USER + 1138)
#define EA_IsIn              (EA_Dummy + 0x01)
#define EA_EndpointNum       (EA_Dummy + 0x10)
#define EA_TransferType      (EA_Dummy + 0x11)
#define EA_MaxPktSize        (EA_Dummy + 0x12)
#define EA_Interval          (EA_Dummy + 0x13)
#define EA_Interface         (EA_Dummy + 0x14)

/* Tags for psdGetAttrs(PGA_PIPE,...) */

#define PPA_Dummy            (TAG_USER  + 1234)
#define PPA_Endpoint         (PPA_Dummy + 0x01)
#define PPA_Error            (PPA_Dummy + 0x02)
#define PPA_Actual           (PPA_Dummy + 0x03)
#define PPA_EndpointNum      (PPA_Dummy + 0x04)
#define PPA_DeviceAddress    (PPA_Dummy + 0x05)
#define PPA_IORequest        (PPA_Dummy + 0x06)
#define PPA_NoZeroPktTerm    (PPA_Dummy + 0x07)
#define PPA_NoShortPackets   PPA_NoZeroPktTerm /* obsolete, bad naming */
#define PPA_NakTimeout       (PPA_Dummy + 0x08)
#define PPA_NakTimeoutTime   (PPA_Dummy + 0x09)
#define PPA_AllowRuntPackets (PPA_Dummy + 0x0a)
#define PPA_MaxPktSize       (PPA_Dummy + 0x0b)

/* Tags for application binding and psdGetAttrs(PGA_APPBINDING,...)*/
#define ABA_Dummy            (TAG_USER + 666)
#define ABA_ReleaseHook      (ABA_Dummy + 0x01)
#define ABA_Device           (ABA_Dummy + 0x02)
#define ABA_UserData         (ABA_Dummy + 0x03)
#define ABA_Task             (ABA_Dummy + 0x04)

/* Tags for psdGetAttrs(PGA_EVENTNOTE,...)*/
#define ENA_Dummy            (TAG_USER + 777)
#define ENA_EventID          (ENA_Dummy + 0x01)
#define ENA_Param1           (ENA_Dummy + 0x02)
#define ENA_Param2           (ENA_Dummy + 0x03)

/* Tags for psdGetAttrs(PGA_GLOBALCFG,...) */

#define GCA_Dummy            (TAG_USER + 0x1138)
#define GCA_LogInfo          (GCA_Dummy + 0x01)
#define GCA_LogWarning       (GCA_Dummy + 0x02)
#define GCA_LogError         (GCA_Dummy + 0x03)
#define GCA_LogFailure       (GCA_Dummy + 0x04)
#define GCA_SubTaskPri       (GCA_Dummy + 0x10)
#define GCA_BootDelay        (GCA_Dummy + 0x11)
#define GCA_PopupDeviceNew   (GCA_Dummy + 0x20)
#define GCA_PopupDeviceGone  (GCA_Dummy + 0x21)
#define GCA_PopupDeviceDeath (GCA_Dummy + 0x22)
#define GCA_PopupCloseDelay  (GCA_Dummy + 0x23)
#define GCA_PopupActivateWin (GCA_Dummy + 0x30)
#define GCA_PopupWinToFront  (GCA_Dummy + 0x31)
#define GCA_InsertionSound   (GCA_Dummy + 0x40)
#define GCA_RemovalSound     (GCA_Dummy + 0x41)

/* Tags for psdGetAttrs(PGA_PIPESTREAM,...) */
#define PSA_Dummy            (TAG_USER + 0x0409)
#define PSA_MessagePort      (PSA_Dummy + 0x01)
#define PSA_AsyncIO          (PSA_Dummy + 0x02)
#define PSA_NumPipes         (PSA_Dummy + 0x03)
#define PSA_BufferSize       (PSA_Dummy + 0x04)
#define PSA_ShortPktTerm     (PSA_Dummy + 0x05)
#define PSA_ReadAhead        (PSA_Dummy + 0x06)
#define PSA_BufferedRead     (PSA_Dummy + 0x07)
#define PSA_BufferedWrite    (PSA_Dummy + 0x08)
#define PSA_NoZeroPktTerm    (PSA_Dummy + 0x09)
#define PSA_NakTimeout       (PSA_Dummy + 0x0a)
#define PSA_NakTimeoutTime   (PSA_Dummy + 0x0b)
#define PSA_AllowRuntPackets (PSA_Dummy + 0x0c)
#define PSA_TermArray        (PSA_Dummy + 0x0d)
#define PSA_DoNotWait        (PSA_Dummy + 0x0e)
#define PSA_AbortSigMask     (PSA_Dummy + 0x0f)
#define PSA_BytesPending     (PSA_Dummy + 0x10)
#define PSA_Error            (PSA_Dummy + 0x11)
#define PSA_ActivePipe       (PSA_Dummy + 0x12)

/* NumToStr types */

#define NTS_IOERR        1
#define NTS_LANGID       2
#define NTS_TRANSTYPE    3
#define NTS_VENDORID     4
#define NTS_CLASSCODE    5

/* Event Handler stuff */

#define EHMB_ADDHARDWARE 0x01 /* Param1 = phw */
#define EHMB_REMHARDWARE 0x02 /* Param1 = phw */
#define EHMB_ADDDEVICE   0x03 /* Param1 = pd */
#define EHMB_REMDEVICE   0x04 /* Param1 = pd */
#define EHMB_ADDCLASS    0x05 /* Param1 = puc */
#define EHMB_REMCLASS    0x06 /* Param1 = puc */
#define EHMB_ADDBINDING  0x07 /* Param1 = pd */
#define EHMB_REMBINDING  0x08 /* Param1 = pd */
#define EHMB_ADDERRORMSG 0x09 /* Param1 = pem */
#define EHMB_REMERRORMSG 0x0a /* Param1 = pem */
#define EHMB_CONFIGCHG   0x0b /* Param1 = void */
#define EHMB_CLSSCANRDY  0x0c /* Param1 = void */

#define EHMF_ADDHARDWARE (1L<<EHMB_ADDHARDWARE)
#define EHMF_REMHARDWARE (1L<<EHMB_REMHARDWARE)
#define EHMF_ADDDEVICE   (1L<<EHMB_ADDDEVICE)
#define EHMF_REMDEVICE   (1L<<EHMB_REMDEVICE)
#define EHMF_ADDCLASS    (1L<<EHMB_ADDCLASS)
#define EHMF_REMCLASS    (1L<<EHMB_REMCLASS)
#define EHMF_ADDBINDING  (1L<<EHMB_ADDBINDING)
#define EHMF_REMBINDING  (1L<<EHMB_REMBINDING)
#define EHMF_ADDERRORMSG (1L<<EHMB_ADDERRORMSG)
#define EHMF_REMERRORMSG (1L<<EHMB_REMERRORMSG)
#define EHMF_CONFIGCHG   (1L<<EHMB_CONFIGCHG)
#define EHMF_CLSSCANRDY  (1L<<EHMB_CLSSCANRDY)

/* Configuration stuff */

#define IFFFORM_PSDCFG     MAKE_ID('P','S','D','C')
#define IFFFORM_STACKCFG   MAKE_ID('S','T','K','C')
#define IFFFORM_DEVICECFG  MAKE_ID('D','E','V','C')
#define IFFFORM_CLASSCFG   MAKE_ID('C','L','S','C')
#define IFFFORM_UHWDEVICE  MAKE_ID('U','H','W','D')
#define IFFFORM_USBCLASS   MAKE_ID('U','C','L','S')
#define IFFFORM_CLASSDATA  MAKE_ID('G','C','P','D')
#define IFFFORM_DEVCFGDATA MAKE_ID('D','C','F','G')
#define IFFFORM_DEVCLSDATA MAKE_ID('D','C','P','D')
#define IFFFORM_IFCFGDATA  MAKE_ID('I','C','F','G')
#define IFFFORM_IFCLSDATA  MAKE_ID('I','C','P','D')

#define IFFCHNK_OWNER      MAKE_ID('O','W','N','R')
#define IFFCHNK_NAME       MAKE_ID('N','A','M','E')
#define IFFCHNK_UNIT       MAKE_ID('U','N','I','T')
#define IFFCHNK_OFFLINE    MAKE_ID('O','F','F','L')
#define IFFCHNK_GLOBALCFG  MAKE_ID('G','C','F','G')
#define IFFCHNK_DEVID      MAKE_ID('D','V','I','D')
#define IFFCHNK_IFID       MAKE_ID('I','F','I','D')
#define IFFCHNK_FORCEDBIND MAKE_ID('F','B','N','D')
#define IFFCHNK_POPUP      MAKE_ID('P','O','P','O')
#define IFFCHNK_INSERTSND  MAKE_ID('I','N','S','F')
#define IFFCHNK_REMOVESND  MAKE_ID('R','M','S','F')

/* Private stuff starts here */

/* The library node - private
*/
struct PsdBase
{
    struct Library      ps_Library;       /* standard */
};

struct PsdEventHook
{
    struct Node         peh_Node;         /* Node linkage */
};

struct PsdEventNote
{
    struct Message      pen_Msg;          /* Intertask communication message */
};

struct PsdErrorMsg
{
    struct Node         pem_Node;         /* Node linkage */
};

struct PsdIFFContext
{
    struct Node         pic_Node;         /* Node linkage */
};

struct PsdUsbClass
{
    struct Node         puc_Node;         /* Node linkage */
};

struct PsdAppBinding
{
    struct Node         pab_Node;         /* Node linkage */
};

struct PsdHardware
{
    struct Node         phw_Node;         /* Node linkage */
};

struct PsdDevice
{
    struct Node         pd_Node;          /* Node linkage */
};

struct PsdConfig
{
    struct Node         pc_Node;          /* Node linkage */
};

struct PsdInterface
{
    struct Node         pif_Node;         /* Node linkage */
};

struct PsdEndpoint
{
    struct Node         pep_Node;         /* Node linkage */
};

struct PsdPipe
{
    struct Message      pp_Msg;           /* Intertask communication message */
};

struct PsdPipeStream
{
    struct Node         pps_Node;         /* Node linkage */
};

#endif /* POSEIDON_H */
