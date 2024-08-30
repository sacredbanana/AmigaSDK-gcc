/*
$VER: multimedia.h 55.1 (07.10.2012)
*/

#ifndef CLASSES_MULTIMEDIA_MULTIMEDIA_H
#define CLASSES_MULTIMEDIA_MULTIMEDIA_H

#include <exec/libraries.h>
#include <intuition/classusr.h>
#include <devices/timer.h>
#include <clib/alib_protos.h>

#ifndef MAKE_ID
#define MAKE_ID(a,b,c,d)  ((ULONG) (a)<<24 | (ULONG) (b)<<16 | (ULONG) (c)<<8 | (ULONG) (d))
#endif

/* data object attributes */

#define MMA_Dummy              0x8EDA0000

#define MMA_MediaType          (MMA_Dummy + 1)    /* [I..] ULONG MediaNewObject() */
#define MMA_Priority           (MMA_Dummy + 2)    /* [...] subclasses only! */
#define MMA_Stream             (MMA_Dummy + 3)    /* [I.G] MediaNewObject() */
#define MMA_Recognition        (MMA_Dummy + 4)    /* [I..] MediaNewObject() */
#define MMA_TaskPriority       (MMA_Dummy + 5)    /* [I..] for classes creating subtasks */
#define MMA_ClassName          (MMA_Dummy + 6)    /* [..G] */
#define MMA_ClassDesc          (MMA_Dummy + 7)    /* [..G] */
#define MMA_StreamType         (MMA_Dummy + 8)    /* [I..] MediaNewObject() */
#define MMA_StreamName         (MMA_Dummy + 9)    /* [I..] STRPTR MediaNewObject() */
#define MMA_MimeType           (MMA_Dummy + 10)   /* [..G] STRPTR decoders */
#define MMA_DataFormat         (MMA_Dummy + 11)   /* [I.G] STRPTR general */
#define MMA_ErrorCode          (MMA_Dummy + 12)   /* [I.G] ULONG/ULONG* general */
#define MMA_StreamHandle       (MMA_Dummy + 13)   /* [I..] MediaNewObject() */
#define MMA_UseVectorUnit      (MMA_Dummy + 14)   /* [I..] BOOL for test purposes */
#define MMA_SupportedFormats   (MMA_Dummy + 15)   /* [..G] general */
#define MMA_Ports              (MMA_Dummy + 16)   /* [..G] ULONG general */
#define MMA_StreamSeekable     (MMA_Dummy + 17)   /* [..G] general */
#define MMA_StreamPosBytes     (MMA_Dummy + 18)   /* [..G] */
#define MMA_Mark               (MMA_Dummy + 19)   /* [.SG] processblocks */
#define MMA_StreamPosFrames    (MMA_Dummy + 20)   /* [..G.Q] general */
#define MMA_RecognizeCode      (MMA_Dummy + 21)   /* for subclasses */
#define MMA_ClassType          (MMA_Dummy + 22)   /* for subclasses */
#define MMA_StreamPosTime      (MMA_Dummy + 23)   /* [..G.Q] general */
#define MMA_StreamLength       (MMA_Dummy + 24)   /* [..G.Q] general */
#define MMA_ObjectName         (MMA_Dummy + 25)   /* [I.G.Q] STRPTR general */
#define MMA_BlockAlign         (MMA_Dummy + 26)   /* [..G.Q] internal */
#define MMA_AutoDestruction    (MMA_Dummy + 27)   /* [I....] BOOL internal */
#define MMA_ExtraData          (MMA_Dummy + 28)   /* [..G.Q] demuxer->decoder communication */
#define MMA_TaskName           (MMA_Dummy + 29)   /* for subclasses creating processes */
#define MMA_AudioFormat        (MMA_Dummy + 30)   /* [I....] MediaNewObject() */
#define MMA_VideoFormat        (MMA_Dummy + 31)   /* [I....] MediaNewObject() */
#define MMA_MetaData           (MMA_Dummy + 32)   /* [....Q] struct MetaItem* demuxers usually */
#define MMA_OutputState        (MMA_Dummy + 33)   /* [..G.Q] outputs */
#define MMA_Decode             (MMA_Dummy + 34)   /* [I....] MediaNewObject() */
#define MMA_OutputBytes        (MMA_Dummy + 35)   /* [..G.Q] outputs */
#define MMA_OutputPosition     (MMA_Dummy + 36)   /* [..G.Q] outputs */
#define MMA_MUIGenerator       (MMA_Dummy + 37)   /* subclasses providing GUI */
#define MMA_ArgTemplate        (MMA_Dummy + 38)   /* subclasses providing GUI */
#define MMA_RegGenerator       (MMA_Dummy + 39)   /* subclasses providing GUI */
#define MMA_Arguments          (MMA_Dummy + 40)   /* [I.G.Q] filters, encoders, muxers */
#define MMA_NameSuffixes       (MMA_Dummy + 41)   /* [..G.Q] STRPTR*, muxers */
#define MMA_FormatPriority     (MMA_Dummy + 42)   /* MediaConnectTagList() */
#define MMA_QualityDegradation (MMA_Dummy + 43)   /* MediaConnectTagList() */
#define MMA_DefaultExtension   (MMA_Dummy + 44)   /* STRPTR, muxers */
#define MMA_StrGenerator       (MMA_Dummy + 45)   /* subclasses providing GUI */
#define MMA_AutoConvDepth      (MMA_Dummy + 46)   /* MediaConnectTagList() */
#define MMA_UseBestFormat      (MMA_Dummy + 47)   /* [I....] MediaNewObject() */
#define MMA_URIStreamName      (MMA_Dummy + 48)   /* [I..] STRPTR MediaNewObject() */

#define MMA_MAX_ATTR           MMA_URIStreamName

#define MMV_OutputState_Playing              1
#define MMV_OutputState_Paused               2
#define MMV_OutputState_Stopped              3

#define MMV_FormatPriority_Speed             1
#define MMV_FormatPriority_Quality           2
#define MMV_FormatPriority_ForcedQuality     3

/*#### OBSOLETE ####*/

#define MMA_StreamMode_Read        0x0001  /* read only */
#define MMA_StreamMode_Write       0x0002  /* write only, creates new stream */

/*##################*/


/* Special values for MediaFindFilter() tags. */

#define MMV_Find_Any                    0x7FFFFFFF  /* any format will go */
#define MMV_Find_AnyCommon              0x7FFFFFFE  /* any common format */
#define MMV_Find_AnyCommonAudio         0x7FFFFFFD  /* any common audio format */
#define MMV_Find_AnyAudio               0x7FFFFFFC  /* any non-common audio format */

/* methods */

#define MMM_GetPort            (MMA_Dummy + 73)
#define MMM_SignalAtEnd        (MMA_Dummy + 74)  /* outputs */
#define MMM_Pull               (MMA_Dummy + 75)
#define MMM_SetPort            (MMA_Dummy + 76)
#define MMM_AddPort            (MMA_Dummy + 77)
#define MMM_LockObject         (MMA_Dummy + 78)
#define MMM_UnlockObject       (MMA_Dummy + 79)
#define MMM_Setup              (MMA_Dummy + 80)  /* subclasses only */
#define MMM_AddForward         (MMA_Dummy + 81)  /* private */
#define MMM_Play               (MMA_Dummy + 82)  /* output control */
#define MMM_Pause              (MMA_Dummy + 83)  /* output control */
#define MMM_Stop               (MMA_Dummy + 84)  /* output control */
#define MMM_Seek               (MMA_Dummy + 85)
#define MMM_IsMember           (MMA_Dummy + 86)
#define MMM_GetPortFwd         (MMA_Dummy + 87)
#define MMM_SetPortFwd         (MMA_Dummy + 88)
#define MMM_MessageAtEnd       (MMA_Dummy + 89)
#define MMM_Peek               (MMA_Dummy + 92)
#define MMM_Restore            (MMA_Dummy + 93)
#define MMM_ConnectPort        (MMA_Dummy + 94)
#define MMM_DisconnectPort     (MMA_Dummy + 95)
#define MMM_PrePull            (MMA_Dummy + 96)  /* subclasses only */
#define MMM_PostPull           (MMA_Dummy + 97)  /* subclasses only */
#define MMM_PreSeek            (MMA_Dummy + 98)  /* subclasses only */
#define MMM_PostSeek           (MMA_Dummy + 99)  /* subclasses only */
#define MMM_AddMetaItem        (MMA_Dummy + 100) 
#define MMM_Cleanup            (MMA_Dummy + 101) /* subclasses only */

/* obsolete */
#define MMM_GetMetaItem        (MMA_Dummy + 102)

/* v 55.11 */
#define MMM_QueryMetaData      (MMA_Dummy + 103)
#define MMM_DisposeMetaData    (MMA_Dummy + 104)

struct mmopGetPort { ULONG MethodID; ULONG Port; ULONG Attribute; ULONG* Storage; };
struct mmopPull { ULONG MethodID; ULONG Port; APTR Buffer; LONG Length; };
struct mmopSetPort { ULONG MethodID; ULONG Port; ULONG Attribute; ULONG Value; };
struct mmopAddPort { ULONG MethodID; ULONG Port; };
struct mmopSetup { ULONG MethodID; ULONG Port; };
struct mmopAddForward { ULONG MethodID; Boopsiobject *FwdObject; ULONG FwdPort; };
struct mmopPlay { ULONG MethodID; ULONG Port; };
struct mmopPause { ULONG MethodID; ULONG Port; };
struct mmopStop { ULONG MethodID; ULONG Port; };
struct mmopSeek { ULONG MethodID; ULONG Port; ULONG Type; QUAD *Position; };
struct mmopGetPortFwd { ULONG MethodID; ULONG Port; ULONG Attribute; ULONG *Storage; };
struct mmopSetPortFwd { ULONG MethodID; ULONG Port; ULONG Attribute; ULONG Value; };
struct mmopRestore { ULONG MethodID; ULONG Port; };
struct mmopConnectPort { ULONG MethodID; ULONG Port; Boopsiobject *DestObj; ULONG DestPort; };
struct mmopDisconnectPort { ULONG MethodID; ULONG Port; };
struct mmopPrePull { ULONG MethodID; ULONG Port; APTR Buffer; LONG Length; };
struct mmopPostPull { ULONG MethodID; ULONG Port; APTR Buffer; LONG Length; };
struct mmopPreSeek { ULONG MethodID; ULONG Port; ULONG Type; QUAD *Position; ULONG TypeMask; };
struct mmopPostSeek { ULONG MethodID; ULONG Port; ULONG Type; QUAD *Position; ULONG Result; };
struct mmopAddMetaItem { ULONG MethodID; ULONG Port; ULONG MetaID; ULONG Importance; APTR Data; ULONG Encoding; };
struct mmopSignalAtEnd { ULONG MethodID; struct Process *SigTask; LONG SigBit; };
struct mmopMessageAtEnd { ULONG MethodID; struct Message *MsgToSend; };
struct mmopCleanup { ULONG MethodID; ULONG Port; };
struct mmopGetMetaItem { ULONG MethodID; ULONG MetaID; ULONG *Importance; APTR Data; ULONG Encoding; ULONG Depth; };
struct mmopQueryMetaData { ULONG MethodID; ULONG Port; ULONG *Items; struct TagItem *Parameters; };
struct mmopDisposeMetaData { ULONG MethodID; struct TagItem *Query; };


/* special values for methods */

#define MMV_SignalAtEnd_Remove  -1

/* MMM_GetPort/SetPort tags */

#define MMA_Port_Object        (MMA_Dummy + 200)  /* [G.] Object* */
#define MMA_Port_Number        (MMA_Dummy + 201)  /* [G.] ULONG */
#define MMA_Port_FormatsTable  (MMA_Dummy + 202)  /* [G.] ULONG* */
#define MMA_Port_Format        (MMA_Dummy + 203)  /* [GS] ULONG */
#define MMA_Port_ConnObject    (MMA_Dummy + 204)  /* [GS] Object* */
#define MMA_Port_ConnNumber    (MMA_Dummy + 205)  /* [GS] ULONG */
#define MMA_Port_Type          (MMA_Dummy + 206)  /* [G.] ULONG */
#define MMA_Port_Forwarding    (MMA_Dummy + 207)  /* [GS] BOOL */

/* media types */

#define MMT_SOUND     0x00000001
#define MMT_PICTURE   0x00000002
#define MMT_VIDEO     0x00000004
#define MMT_DOCUMENT  0x00000008        /* text only or compound */
#define MMT_ANY       0xFFFFFFFF        /* matches any media type (32 media types possible) */

/* recognition type */

#define MMREC_LIGHT  0       /* use fast (but maybe inaccurate) recognition routines */
#define MMREC_HEAVY  1       /* use accurate (but maybe slow) recognition routines */

/* class types */

#define MMCLASS_BASIC           0       /* multimedia.class, processblock.class, multiread.buffer */
#define MMCLASS_DEMUXER         1
#define MMCLASS_DECODER         2
#define MMCLASS_ENCODER         3
#define MMCLASS_MULTIPLEXER     4
#define MMCLASS_OUTPUT          5
#define MMCLASS_FILTER          6
#define MMCLASS_STREAM          7

/* structure describing block port */

struct MediaPort
{
	struct Node     mdp_Node;
	Boopsiobject   *mdp_Object;
	LONG            mdp_Port;
	LONG            mdp_Number;
	ULONG           mdp_Type;
	ULONG           mdp_DataFormat;
	ULONG          *mdp_AvailFormats;
	BOOL            mdp_Forwarding;
	BOOL            mdp_Autoconnect;
	struct MinList  mdp_MetaData;
};

struct MediaPortDesc
{
	ULONG   mdd_Type;
	ULONG  *mdd_FormatTable;
};

/* for mdp_Type */

#define MDP_TYPE_INPUT          1
#define MDP_TYPE_OUTPUT         2

/* invalid port number */

#define MM_NO_PORT              -1

/* enumerated data formats */

/* general */

#define MMF_UNKNOWN              0x00000000
#define MMF_STREAM               0x00000001    /* port interfaces to stream object */
#define MMF_ANY_FORMAT           0xFFFFFFFF    /* wildchar used e.g. by generic buffers */


/* audio */

#define MMF_AUDIOMASK            0x00001000
#define MMF_AUDIOBIT             12

#define IS_AUDIO(x) ((x) & MMF_AUDIOMASK)


/* video */

#define MMF_VIDEOMASK            0x00002000
#define MMF_VIDEOBIT             13

#define IS_VIDEO(x) ((x) & MMF_VIDEOMASK)


/* document */

#define MMF_DOCUMENTMASK         0x00004000
#define MMF_DOCUMENTBIT          14

#define IS_DOCUMENT(x) ((x) & MMF_DOCUMENTMASK)


/* common formats */

#define MMF_COMMONMASK           0x00010000
#define MMF_COMMONBIT            16

#define MMFC_UNKNOWN             (MMF_COMMONMASK | 0)
#define MMFC_AUDIO_INT16         (MMF_COMMONMASK | 1)
#define MMFC_AUDIO_INT32         (MMF_COMMONMASK | 2)
#define MMFC_AUDIO_FLOAT32       (MMF_COMMONMASK | 3)
#define MMFC_VIDEO_ARGB32        (MMF_COMMONMASK | 4)
#define MMFC_VIDEO_ARGB32_MF     (MMF_COMMONMASK | 5)
#define MMFC_VIDEO_GRAY8         (MMF_COMMONMASK | 6)
#define MMFC_VIDEO_CMYK32        (MMF_COMMONMASK | 7)
/* space for more video common formats like 16 bits per component, or YUV */
#define MMFC_DOCUMENT_PLAINTEXT  (MMF_COMMONMASK | 32)  // UCS-4 encoded

//#define MMFC_MAXFORMAT           (MMF_COMMONMASK | 7)

#define IS_COMMON(x) ((x) & MMF_COMMONMASK)
#define IS_COMMON_AUDIO(x) (((x) >= MMFC_AUDIO_INT16) && ((x) <= MMFC_AUDIO_FLOAT32))
#define IS_COMMON_VIDEO(x) (((x) >= MMFC_VIDEO_ARGB32) && ((x) <= MMFC_VIDEO_CMYK32))
#define IS_COMMON_DOCUMENT(x) ((x) == MMFC_DOCUMENT_PLAINTEXT)

/* error values */

#define MMERR_BASE                  1101

#define MMERR_END_OF_DATA           1101    /* data stream has ended [unexpectedly] */
#define MMERR_OUT_OF_MEMORY         1102    /* memory internal allocation failed */
#define MMERR_NOT_SEEKABLE          1103    /* operation requires seekable stream */
#define MMERR_WRONG_ARGUMENTS       1104    /* wrong arguments to a method */
#define MMERR_NO_STREAM             1105    /* missing src/dest stream for operation */
#define MMERR_WRONG_DATA            1106    /* malformed data in stream [header] */
#define MMERR_NO_STREAM_CLASS       1107    /* wrong stream type specified */
#define MMERR_NO_DECODER            1108    /* no decoder for an encoded format */
#define MMERR_NOT_RECOGNIZED        1109    /* no demultiplexer recognized the format */
#define MMERR_IO_ERROR              1110    /* I/O error in source or destination stream */
#define MMERR_FORMAT_NOT_SUPPORTED  1111    /* unsupported format of raw data */
#define MMERR_BROKEN_PIPE           1112    /* pipe of objects is not continuous */
#define MMERR_NOT_IMPLEMENTED       1113    /* functionality not implemented or not supported*/
#define MMERR_RESOURCE_MISSING      1114    /* missing system resource (library or class usually) */
#define MMERR_END_OF_FRAME          1115    /* end of video frame (used internally) */
#define MMERR_BUFFER_UNDERRUN       1116    /* data buffer in object chain is empty */

#define MMERR_MAX                   1116


/* seek types */

#define MMM_SEEK_BYTES    0     /* Position in bytes.        */
#define MMM_SEEK_FRAMES   1     /* Position in frames.       */
#define MMM_SEEK_TIME     2     /* Position in microseconds. */


/* seek masks */

#define MMM_SEEKMASK_BYTES              1     /* Byte seek only.           */
#define MMM_SEEKMASK_FRAMES_AND_TIME    2     /* Frame seek and time seek. */


/* MMM_PreSeek() return values */   

#define MMM_PRESEEK_DONE                6     /* MMM_PreSeek have done all the job already.  */
#define MMM_PRESEEK_NOT_DONE            7     /* Verification OK, do the seek job.           */
#define MMM_PRESEEK_FAILED              8     /* Fail. Do nothing, just call MMM_PostSeek(). */

/* MMM_PrePull() return values */

#define MMM_PREPULL_FAILED             -1     /* Fail. Do nothing, just call MMM_PostPull(). */
#define MMM_PREPULL_NOT_DONE           -2     /* Verification OK, do processing.             */
                                              /* 0 or positive value means MMM_PrePull() did the job. */

/* MMM_Get/SetPort wrappers */

#define MediaGetPort(obj, port, attr) ({ ULONG _val = 0; DoMethod(obj, MMM_GetPort, port, attr, (IPTR)&_val); _val; })
#define MediaGetPort64(obj, port, attr) ({ UQUAD _val = 0; DoMethod(obj, MMM_GetPort, port, attr, (IPTR)&_val); _val; })
#define MediaSetPort(obj, port, attr, val) DoMethod(obj, MMM_SetPort, port, attr, val)
#define MediaSetPort64(obj, port, attr, val) ({ UQUAD _val = val; DoMethod(obj, MMM_SetPort, port, attr, (IPTR)&_val); })

/* MMM_Get/SetPortFwd wrappers */

#define MediaGetPortFwd(obj, port, attr) ({ ULONG _val = 0; DoMethod(obj, MMM_GetPortFwd, port, attr, (IPTR)&_val); _val; })
#define MediaGetPortFwd64(obj, port, attr) ({ UQUAD _val = 0; DoMethod(obj, MMM_GetPortFwd, port, attr, (IPTR)&_val); _val; })
#define MediaSetPortFwd(obj, port, attr, val) DoMethod(obj, MMM_SetPortFwd, port, attr, val)
#define MediaSetPortFwd64(obj, port, attr, val) ({ UQUAD _val = val; DoMethod(obj, MMM_SetPortFwd, port, attr, (IPTR)&_val); })


struct DtCodeContext
{
	struct Library  *dcc_SysBase;
	struct Library  *dcc_IntuitionBase;
	struct Library  *dcc_DOSBase;
	struct Library  *dcc_MultimediaBase;
	Boopsiobject    *dcc_Source;
	ULONG            dcc_Port;
};


/* Log levels. */

#define LOG_NONE        0
#define LOG_ERRORS      1
#define LOG_INFO        2
#define LOG_VERBOSE     3


/* Log message with no parameter. */

#define MLOG(level, msg) MediaLog(level, (STRPTR)CLASSNAME, (STRPTR)__FUNCTION__, (STRPTR)msg, NULL)

/* Log message with variable args. */

#if !defined(__STRICT_ANSI__)
#define MLOGV(level, msg, ...) MediaLog(level, (STRPTR)CLASSNAME, (STRPTR)__FUNCTION__, (STRPTR)msg, __VA_ARGS__)
#endif

/* Message structure sent to MediaLogger */

struct MediaError
{
	struct Message Msg;
	ULONG  Level;
	STRPTR AppName;
	STRPTR ClassName;
	STRPTR FunctionName;
	STRPTR EventDescription;
};

#define SETERR(x) SetAttrs(obj, MMA_ErrorCode, x, TAG_END)


/*############################################################################*/
/*### Class specific attributes and methods. #################################*/
/*############################################################################*/

#define MMA_FileOutput_Path         (MMA_Dummy + 1500)  /* [I.G.Q]  STRPTR    */
#define MMA_FileOutput_DosError     (MMA_Dummy + 1501)  /* [I....]  LONG*     */
#define MMA_StreamBuffer_Level      (MMA_Dummy + 1502)  /* [..G.Q]  LONG    bytes buffered    */
#define MMA_StreamBuffer_Blocks     (MMA_Dummy + 1503)  /* [I.G.Q]  LONG    number of blocks in FIFO  */
#define MMA_Shoutcast_DataGap       (MMA_Dummy + 1504)  /* [ISPGQ]  LONG    bytes of stream between metadata */
#define MMA_StreamBuffer_BlockSize  (MMA_Dummy + 1505)  /* [I.G.Q]  LONG    length of FIFO block in bytes */


/*#### OBSOLETE ####*/

#define seterr(x) SETERR(x)

struct mmopData
{
	ULONG   MethodID;
	ULONG   Port;
	APTR    Buffer;
	LONG    Length;
};

struct mmopConnect
{
	ULONG         MethodID;
	ULONG         Port;
	Boopsiobject* DestObj;
	ULONG         DestPort;
};

struct mmopPort
{
	ULONG   MethodID;
	ULONG   Port;
};

/* End of obsolete defines. */


/* GUI generation, tags and values for MediaGetGuiTagList() */

#define MGG_Type                       (MMA_Dummy + 3000)   // also takes class name string
#define MGG_Type_Muxers                1
#define MGG_Type_Filters               2

#define MGG_Media                      (MMA_Dummy + 3001)   // MMT_ flags

#define MGG_Selector                   (MMA_Dummy + 3002)
#define MGG_Selector_List              1
#define MGG_Selector_Cycle             2
#define MGG_Selector_None              3

#define MGG_Selected                   (MMA_Dummy + 3003)   // selected class name
#define MGG_DOSPattern                 (MMA_Dummy + 3004)   // filtering out classes using DOS pattern


/*------------------------------------------------------*/
/* FOR IMPLEMENTORS OF CLASSES PROVIDING GUI GENERATORS */
/*------------------------------------------------------*/

/* structure sent to MUI generators in classes */

struct MUIContext
{
	struct Library*              muc_SysBase;
	struct Library*              muc_IntuitionBase;
	struct Library*              muc_DOSBase;
	struct Library*              muc_MultimediaBase;
	struct Library*              muc_MUIMasterBase;
	struct Library*              muc_LocaleBase;
	struct MUI_CustomClass*      muc_MasterClass;     // returned object must be an instance of this class
	struct MUI_CustomClass*      muc_StorageClass;    // optional storage for localized strings and other stuff
	struct TagItem*              muc_TagList;
};

/* structure sent to argument string generators in classes */

struct StrContext
{
	struct Library*              stc_SysBase;
	struct Library*              stc_IntuitionBase;
	struct Library*              stc_MultimediaBase;
	struct TagItem*              stc_TagList;
	Boopsiobject*                stc_Gui;             // GUI object to extract arguments from
};

/* structure sent to Reggae chain generators in classes */

struct RegContext
{
	struct Library*              rgc_SysBase;
	struct Library*              rgc_IntuitionBase;
	struct Library*              rgc_MultimediaBase;
	struct TagItem*              rgc_TagList;
	STRPTR                       rgc_Arguments;       // Argument string specifying encoder/muxer parameters
	Boopsiobject*                rgc_SourceObject;    // Reggae object used as data source
	LONG                         rgc_SourcePort;      // Port of the data source
};

/* storage methods provided by muc_StorageClass, may be used in GUI generators to store localized strings or other stuff */

#define GGRM_SetString           0x6EDA0001        /* stores a NULL-terminated string */
#define GGRM_SetLocaleString     0x6EDA0002        /* stores a localized version of a NULL-terminated string */

struct GGRP_SetString
{
	ULONG MethodID;
	char* Data;
	IPTR  Id;
};

#define GGRM_GetString           0x6EDA0003

struct GGRP_GetString
{
	ULONG MethodID;
	IPTR  Id;
};

#define GGRA_Catalog             0x6EDA2000      /* [I..], STRPTR, name of locale catalog for the class, for muc_StorageClass */
#define GGRA_Storage             0x6EDA2001      /* [I..], Object*, pointer to instance of muc_StorageClass, passed to constructor of GUI object */
#define GGRA_SelectorName        0x6EDA2002      /* [I.G], defined by class GUI generator, read by MediaGetGuiTagList() */
#define GGRA_FullName            0x6EDA2003      /* [I.G], defined by class GUI generator, read by MediaGetGuiTagList() */
#define GGRA_PageClassName       0x6EDA2004      /* [..G], for object returned by MediaGetGui(), notifable */
#define GGRA_PageShortName       0x6EDA2005      /* [..G], for object returned by MediaGetGui(), notifable */
#define GGRA_PageFullName        0x6EDA2006      /* [..G], for object returned by MediaGetGui(), notifable */
#define GGRA_PageDefExtension    0x6EDA2007      /* [..G], for object returned by MediaGetGui(), notifable */


#endif /* CLASSES_MULTIMEDIA_MULTIMEDIA_H */
