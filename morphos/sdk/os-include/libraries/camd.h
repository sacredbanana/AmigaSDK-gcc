#ifndef LIBRARIES_CAMD_H
#define LIBRARIES_CAMD_H

#include <exec/lists.h>
#include <exec/types.h>
#include <utility/tagitem.h>

enum
{
	CD_Linkages,
	CD_NLocks
};


typedef union
{
	ULONG l[2];
	UBYTE b[4];
} MidiMsg;


#define mm_Msg    l[0]
#define mm_Time   l[1]
#define mm_Status b[0]
#define mm_Data1  b[1]
#define mm_Data2  b[2]
#define mm_Port   b[3]
#define mm_Data   b


#define voicemsg(m,a) (((m)->mm_Status & MS_StatBits) == (a))
#define sysmsg(m)     ((m)->mm_Status >= MS_System)
#define noteon(m)     (voicemsg(m,MS_NoteOn) && (m)->mm_Data2)
#define realtime(m)   ((m)->mm_Status >= MS_RealTime)
#define modemsg(m)    (voicemsg(m,MS_Ctrl) && (m)->mm_Data1 >= MM_Min)


struct MidiCluster
{
	struct Node mcl_Node;
	WORD        mcl_Participants;
	struct List mcl_Receivers;
	struct List mcl_Senders;
	WORD        mcl_PublicParticipants;
	UWORD       mcl_Flags;
};


struct MidiLink
{
	struct Node         ml_Node;
	WORD                ml_Pad;
	struct MinNode      ml_OwnerNode;
	struct MidiNode    *ml_MidiNode;
	struct MidiCluster *ml_Location;
	char               *ml_ClusterComment;
	UBYTE               ml_Flags;
	UBYTE               ml_PortID;
	UWORD               ml_ChannelMask;
	ULONG               ml_EventTypeMask;

	union SysExFilter
	{
		UBYTE            b[4];
		ULONG            sxf_Packed;
	} ml_SysExFilter;

	APTR                ml_ParserData;
	APTR                ml_UserData;
};

#define sxf_Mode b[0]
#define sxf_ID1  b[1]
#define sxf_ID2  b[2]
#define sxf_ID3  b[3]


enum
{
	MLTYPE_Receiver,
	MLTYPE_Sender,
	MLTYPE_NTypes
};


#define MLF_Sender      (1 << 0)
#define MLF_PartChange  (1 << 1)
#define MLF_PrivateLink (1 << 2)
#define MLF_DeviceLink  (1 << 3)

#define MLINK_Base         (TAG_USER + 65)

#define MLINK_Location     (MLINK_Base + 0)
#define MLINK_ChannelMask  (MLINK_Base + 1)
#define MLINK_EventMask    (MLINK_Base + 2)
#define MLINK_UserData     (MLINK_Base + 3)
#define MLINK_Comment      (MLINK_Base + 4)
#define MLINK_PortID       (MLINK_Base + 5)
#define MLINK_Private      (MLINK_Base + 6)
#define MLINK_Priority     (MLINK_Base + 7)
#define MLINK_SysExFilter  (MLINK_Base + 8)
#define MLINK_SysExFilterX (MLINK_Base + 9)
#define MLINK_Parse        (MLINK_Base + 10)
#define MLINK_Reserved     (MLINK_Base + 11)
#define MLINK_ErrorCode    (MLINK_Base + 12)
#define MLINK_Name         (MLINK_Base + 13)

#define SXF_ModeBits  0x04
#define SXF_CountBits 0x03

#define SXFM_Off      0x00
#define SXFM_1Byte    0x00
#define SXFM_3Byte    0x04


struct MidiNode
{
	struct Node     mi_Node;
	UWORD           mi_ClientType;
	struct Image   *mi_Image;
	struct MinList  mi_OutLinks;
	struct MinList  mi_InLinks;
	struct Task    *mi_SigTask;
	struct Hook    *mi_ReceiveHook;
	struct Hook    *mi_ParticipantHook;
	BYTE            mi_ReceiveSigBit;
	BYTE            mi_ParticipantSigBit;
	UBYTE           mi_ErrFilter;
	UBYTE           mi_Alignment[1];
	ULONG          *mi_TimeStamp;
	ULONG           mi_MsgQueueSize;
	ULONG           mi_SysExQueueSize;
};

#define CCType_Sequencer        (1 << 0)
#define CCType_SampleEditor     (1 << 1)
#define CCType_PatchEditor      (1 << 2)
#define CCType_Notator          (1 << 3)
#define CCType_EventProcessor   (1 << 4)
#define CCType_EventFilter      (1 << 5)
#define CCType_EventRouter      (1 << 6)
#define CCType_ToneGenerator    (1 << 7)
#define CCType_EventGenerator   (1 << 8)
#define CCType_GraphicAnimator  (1 << 9)

#define MIDI_Base         (TAG_USER + 65)
#define MIDI_Name         (MIDI_Base + 0)
#define MIDI_SignalTask   (MIDI_Base + 1)
#define MIDI_RecvHook     (MIDI_Base + 2)
#define MIDI_PartHook     (MIDI_Base + 3)
#define MIDI_RecvSignal   (MIDI_Base + 4)
#define MIDI_PartSignal   (MIDI_Base + 5)
#define MIDI_MsgQueue     (MIDI_Base + 6)
#define MIDI_SysExSize    (MIDI_Base + 7)
#define MIDI_TimeStamp    (MIDI_Base + 8)
#define MIDI_ErrFilter    (MIDI_Base + 9)
#define MIDI_ClientType   (MIDI_Base + 10)
#define MIDI_Image        (MIDI_Base + 11)
#define MIDI_ErrorCode    (MIDI_Base + 12)

#define CME_NoMem         801
#define CME_NoSignals     802
#define CME_NoTimer       803
#define CME_BadPrefs      804
#define CME_NoUnit(unit) (820 + (unit))

#define CMB_Note          0
#define CMB_Prog          1
#define CMB_PitchBend     2

#define CMB_CtrlMSB       3
#define CMB_CtrlLSB       4
#define CMB_CtrlSwitch    5
#define CMB_CtrlByte      6
#define CMB_CtrlParam     7
#define CMB_CtrlUndef     8

#define CMB_Mode          9
#define CMB_ChanPress     10
#define CMB_PolyPress     11

#define CMB_RealTime      12
#define CMB_SysCom        13
#define CMB_SysEx         14

#define CMF_Note          (1L << CMB_Note)
#define CMF_Prog          (1L << CMB_Prog)
#define CMF_PitchBend     (1L << CMB_PitchBend)

#define CMF_CtrlMSB       (1L << CMB_CtrlMSB)
#define CMF_CtrlLSB       (1L << CMB_CtrlLSB)
#define CMF_CtrlSwitch    (1L << CMB_CtrlSwitch)
#define CMF_CtrlByte      (1L << CMB_CtrlByte)
#define CMF_CtrlParam     (1L << CMB_CtrlParam)
#define CMF_CtrlUndef     (1L << CMB_CtrlUndef)

#define CMF_Mode          (1L << CMB_Mode)
#define CMF_ChanPress     (1L << CMB_ChanPress)
#define CMF_PolyPress     (1L << CMB_PolyPress)

#define CMF_RealTime      (1L << CMB_RealTime)
#define CMF_SysCom        (1L << CMB_SysCom)
#define CMF_SysEx         (1L << CMB_SysEx)

#define CMF_Ctrl          (CMF_CtrlMSB | CMF_CtrlLSB | CMF_CtrlSwitch | CMF_CtrlByte | CMF_CtrlParam | CMF_CtrlUndef)
#define CMF_Channel       (CMF_Note | CMF_Prog | CMF_PitchBend | CMF_Ctrl | CMF_Mode | CMF_ChanPress | CMF_PolyPress)
#define CMF_All           (CMF_Channel | CMF_RealTime | CMF_SysCom | CMF_SysEx)


#define CMEB_MsgErr       0
#define CMEB_BufferFull   1
#define CMEB_SysExFull    2
#define CMEB_ParseMem     3
#define CMEB_RecvErr      4
#define CMEB_RecvOverflow 5
#define CMEB_SysExTooBig  6

#define CMEF_MsgErr       (1L << CMEB_MsgErr)
#define CMEF_BufferFull   (1L << CMEB_BufferFull)
#define CMEF_SysExFull    (1L << CMEB_SysExFull)
#define CMEF_ParseMem     (1L << CMEB_ParseMem)
#define CMEF_RecvErr      (1L << CMEB_RecvErr)
#define CMEF_RecvOverflow (1L << CMEB_RecvOverflow)
#define CMEF_SysExTooBig  (1L << CMEB_SysExTooBig)

#define CMEF_All          (CMEF_MsgErr | CMEF_BufferFull | CMEF_SysExFull | CMEF_SysExTooBig | CMEF_ParseMem | CMEF_RecvErr | CMEF_RecvOverflow)

enum
{
	CMSG_Recv,
	CMSG_Link
};

struct cmLink
{
	ULONG cml_MethodID;
	ULONG cml_Action;
};

enum
{
	CACT_Link,
	CACT_Unlink
};

struct ClusterNotifyNode
{
	struct MinNode  cnn_Node;
	struct Task	   *cnn_Task;
	BYTE	          cnn_SigBit;
	UBYTE	          pad[3];
};

#define PackSysExFilter0()            ((ULONG)(SXFM_Off << 24))
#define PackSysExFilter1(id1)         ((ULONG)(SXFM_1Byte | 1) << 24 | (ULONG)(id1) << 16)
#define PackSysExFilter2(id1,id2)     ((ULONG)(SXFM_1Byte | 2) << 24 | (ULONG)(id1) << 16 | (id2) << 8)
#define PackSysExFilter3(id1,id2,id3) ((ULONG)(SXFM_1Byte | 3) << 24 | (ULONG)(id1) << 16 | (id2) << 8 | (id3))
#define PutMidiMsg(ml,msg)            PutMidi((ml),(msg)->l[0])

/*------------------*/
/* MIDI definitions */
/*------------------*/

/* MIDI commands */

#define MS_NoteOff    0x80
#define MS_NoteOn     0x90
#define MS_PolyPress  0xA0
#define MS_Ctrl       0xB0
#define MS_Mode       0xB0
#define MS_Prog       0xC0
#define MS_ChanPress  0xD0
#define MS_PitchBend  0xE0

#define MS_StatBits   0xF0
#define MS_ChanBits   0x0F

#define MS_System     0xF0
#define MS_SysEx      0xF0
#define MS_QtrFrame   0xF1
#define MS_SongPos    0xF2
#define MS_SongSelect 0xF3
#define MS_TuneReq    0xF6
#define MS_EOX        0xF7

#define MS_RealTime   0xF8
#define MS_Clock      0xF8
#define MS_Start      0xFA
#define MS_Continue   0xFB
#define MS_Stop       0xFC
#define MS_ActvSense  0xFE
#define MS_Reset      0xFF


/* MIDI standard controllers */

#define MC_Bank       0x00
#define MC_ModWheel   0x01
#define MC_Breath     0x02
#define MC_Foot       0x04
#define MC_PortaTime  0x05
#define MC_DataEntry  0x06
#define MC_Volume     0x07
#define MC_Balance    0x08
#define MC_Pan        0x0a
#define MC_Expression 0x0b
#define MC_General1   0x10
#define MC_General2   0x11
#define MC_General3   0x12
#define MC_General4   0x13

#define MC_Sustain      0x40
#define MC_Porta        0x41
#define MC_Sustenuto    0x42
#define MC_SoftPedal    0x43
#define MC_Hold2        0x45
#define MC_General5     0x50
#define MC_General6     0x51
#define MC_General7     0x52
#define MC_General8     0x53
#define MC_ExtDepth     0x5b
#define MC_TremoloDepth 0x5c
#define MC_ChorusDepth  0x5d
#define MC_CelesteDepth 0x5e
#define MC_PhaserDepth  0x5f

#define MC_DataIncr     0x60
#define MC_DataDecr     0x61
#define MC_NRPNL        0x62
#define MC_NRPNH        0x63
#define MC_RPNL         0x64
#define MC_RPNH         0x65

#define MC_Max          0x78


/* MIDI multivoice modes */

#define MM_Min          0x79

#define MM_ResetCtrl    0x79
#define MM_Local        0x7a
#define MM_AllOff       0x7b
#define MM_OmniOff      0x7c
#define MM_OmniOn       0x7d
#define MM_Mono         0x7e
#define MM_Poly         0x7f

#define MRP_PBSens      0x0000
#define MRP_FineTune    0x0001
#define MRP_CourseTune  0x0002


/* MIDI time */

#define MTCQ_FrameL    0x00
#define MTCQ_FrameH    0x10
#define MTCQ_SecL      0x20
#define MTCQ_SecH      0x30
#define MTCQ_MinL      0x40
#define MTCQ_MinH      0x50
#define MTCQ_HourL     0x60
#define MTCQ_HourH     0x70 

#define MTCQ_TypeMask  0x70
#define MTCQ_DataMask  0x0f

#define MTCH_TypeMask  0x60
#define MTCH_HourMask  0x1f

#define MTCT_24FPS         0x00
#define MTCT_25FPS         0x20
#define MTCT_30FPS_Drop    0x40
#define MTCT_30FPS_NonDrop 0x60


/* Vendors (the table is incomplete, should be moved to API) */

#define MID_Sequential     0x01
#define MID_IDP            0x02
#define MID_OctavePlateau  0x03
#define MID_Moog           0x04
#define MID_Passport       0x05
#define MID_Lexicon        0x06
#define MID_Kurzweil       0x07
#define MID_Fender         0x08
#define MID_Gulbransen     0x09
#define MID_AKG            0x0a
#define MID_Voyce          0x0b
#define MID_Waveframe      0x0c
#define MID_ADA            0x0d
#define MID_Garfield       0x0e
#define MID_Ensoniq        0x0f
#define MID_Oberheim       0x10
#define MID_Apple          0x11
#define MID_GreyMatter     0x12
#define MID_PalmTree       0x14
#define MID_JLCooper       0x15
#define MID_Lowrey         0x16
#define MID_AdamsSmith     0x17
#define MID_Emu            0x18
#define MID_Harmony        0x19
#define MID_ART            0x1a
#define MID_Baldwin        0x1b
#define MID_Eventide       0x1c
#define MID_Inventronics   0x1d
#define MID_Clarity        0x1f

#define MID_XAmerica       0x00

#define MIDX_DigitalMusic  0x000007
#define MIDX_Iota          0x000008
#define MIDX_Artisyn       0x00000a
#define MIDX_IVL           0x00000b
#define MIDX_SouthernMusic 0x00000c
#define MIDX_LakeButler    0x00000d
#define MIDX_DOD           0x000010
#define MIDX_PerfectFret   0x000014
#define MIDX_KAT           0x000015
#define MIDX_Opcode        0x000016
#define MIDX_Rane          0x000017
#define MIDX_SpatialSound  0x000018
#define MIDX_KMX           0x000019
#define MIDX_Brenell       0x00001a
#define MIDX_Peavey        0x00001b
#define MIDX_360           0x00001c
#define MIDX_Axxes         0x000020
#define MIDX_CAE           0x000026
#define MIDX_Cannon        0x00002b
#define MIDX_BlueSkyLogic  0x00002e
#define MIDX_Voce          0x000031

#define MID_SIEL           0x21
#define MID_Synthaxe       0x22
#define MID_Hohner         0x24
#define MID_Twister        0x25
#define MID_Solton         0x26
#define MID_Jellinghaus    0x27
#define MID_Southworth     0x28
#define MID_PPG            0x29
#define MID_JEN            0x2a
#define MID_SSL            0x2b
#define MID_AudioVeritrieb 0x2c
#define MID_Elka           0x2f
#define MID_Dynacord       0x30
#define MID_Clavia         0x33
#define MID_Soundcraft     0x39

#define MID_Kawai          0x40
#define MID_Roland         0x41
#define MID_Korg           0x42
#define MID_Yamaha         0x43
#define MID_Casio          0x44
#define MID_Kamiya         0x46
#define MID_Akai           0x47
#define MID_JapanVictor    0x48
#define MID_Mesosha        0x49

#define MID_UNC   0x7d
#define MID_UNRT  0x7e
#define MID_URT   0x7f

#define MiddleC         60
#define DefaultVelocity 64
#define PitchBendCenter 0x2000
#define MClksPerQtr     24
#define MClksPerSP      6
#define MCCenter        64

#define MIDIHiByte(word) ((word) >> 7 & 0x7f)
#define MIDILoByte(word) ((word) & 0x7f)

#define MIDIWord(hi,lo) (((hi) & 0x7f) << 7 | ((lo) & 0x7f))

#define MakeMIDX(id0,id1,id2) ((ULONG)(id0)<<16 | (id1)<<8 | (id2))


#endif /* LIBRARIES_CAMD_H */
