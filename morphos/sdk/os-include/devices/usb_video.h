#ifndef DEVICES_USB_VIDEO_H
#define DEVICES_USB_VIDEO_H
/*
**	$VER: usb_video.h 2.0 (15.12.07)
**
**	usb definitions include file
**
**	(C) Copyright 2008 Chris Hodges
**	    All Rights Reserved
*/

#include <exec/types.h>

#if defined(__GNUC__)
# pragma pack(1)
#endif

/* Usb Video Requests */
#define UVUDR_SET_CUR             0x01
#define UVUDR_GET_CUR             0x81
#define UVUDR_SET_MIN             0x02
#define UVUDR_GET_MIN             0x82
#define UVUDR_SET_MAX             0x03
#define UVUDR_GET_MAX             0x83
#define UVUDR_SET_RES             0x04
#define UVUDR_GET_RES             0x84
#define UVUDR_GET_LEN             0x85
#define UVUDR_GET_INFO            0x86
#define UVUDR_GET_DEF             0x87

/* Video Ctrl class specific interface descriptor subtypes */
#define UDST_VIDEO_CTRL_HEADER          0x01
#define UDST_VIDEO_CTRL_INPUT_TERMINAL  0x02
#define UDST_VIDEO_CTRL_OUTPUT_TERMINAL 0x03
#define UDST_VIDEO_CTRL_SELECTOR_UNIT   0x04
#define UDST_VIDEO_CTRL_PROCESSING_UNIT 0x05
#define UDST_VIDEO_CTRL_EXTENSION_UNIT  0x06

/* Video Streaming class specific interface descriptor subtypes */
#define UDST_VIDEO_STREAM_INPUT_HEADER        0x01
#define UDST_VIDEO_STREAM_OUTPUT_HEADER       0x02
#define UDST_VIDEO_STREAM_STILL_IMAGE_FRAME   0x03
#define UDST_VIDEO_STREAM_FORMAT_UNCOMPRESSED 0x04
#define UDST_VIDEO_STREAM_FRAME_UNCOMPRESSED  0x05
#define UDST_VIDEO_STREAM_FORMAT_MJPEG        0x06
#define UDST_VIDEO_STREAM_FRAME_MJPEG         0x07
#define UDST_VIDEO_STREAM_FORMAT_MPEG2TS      0x0a
#define UDST_VIDEO_STREAM_FORMAT_DV           0x0c
#define UDST_VIDEO_STREAM_COLORFORMAT         0x0d
#define UDST_VIDEO_STREAM_FORMAT_FRAME_BASED  0x10
#define UDST_VIDEO_STREAM_FRAME_FRAME_BASED   0x11
#define UDST_VIDEO_STREAM_FORMAT_STREAM_BASED 0x12

/* Video MIDI class specific interface descriptor subtypes */

/* Videoclass specific endpoint descriptors subtypes */
#define UDST_VIDEO_EP_GENERAL    0x01
#define UDST_VIDEO_EP_ENDPOINT   0x02
#define UDST_VIDEO_EP_INTERRUPT  0x03

/* Video classes */
#define VIDEO_NO_SUBCLASS     0x00
#define VIDEO_CTRL_SUBCLASS   0x01
#define VIDEO_STREAM_SUBCLASS 0x02
#define VIDEO_IFCOLL_SUBCLASS 0x03

/* USB Video specific stuff */

/* USB Video USB Terminal types */
#define UVUTT_VENDOR           0x0100 /* USB vendor specific */
#define UVUTT_STREAMING        0x0101 /* USB streaming */

/* USB Video Input Terminal types */
#define UVITT_VENDOR           0x0200 /* Input Vendor specific */
#define UVITT_CAMERA           0x0201 /* Camera sensor */
#define UVITT_MEDIA_TRANSPORT  0x0202 /* Sequential media */

/* USB Video Output Terminal types */
#define UVOTT_VENDOR           0x0300 /* Output Vendor specific */
#define UVOTT_DISPLAY          0x0301 /* Generic display */
#define UVOTT_MEDIA_TRANSPORT  0x0302 /* Sequential media */

/* USB Video External Terminal types */
#define UVETT_VENDOR           0x0400 /* External Vendor specific */
#define UVETT_COMPOSITE_CONNECTOR 0x0401 /* Composite video connector */
#define UVETT_SVIDEO_CONNECTOR 0x0402 /* S-video connector */
#define UVETT_COMPONENT_CONNECTOR 0x0403 /* Component video connector */

/* VideoControl Interface Control Selectors */
#define UVVCCS_VIDEO_POWER_MODE_CONTROL   0x01
#define UVVCCS_REQUEST_ERROR_CODE_CONTROL 0x02

#if 0
/* USB Video Spec 1.0 stuff */
struct UsbVideoHeaderDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x01) */
    UBYTE bcdADC0;             /* Low byte of spec version (0x00) */
    UBYTE bcdADC1;             /* High byte of spec version (0x01) */
    UBYTE wTotalLength0;       /* Total length of all descriptors (low byte) */
    UBYTE wTotalLength1;       /* Total length of all descriptors (high byte) */
    UBYTE bInCollection;       /* The number of Video/MidiStreaming */
    UBYTE baInterfaceNr[1];    /* Interface number of the first VideoStreaming or MIDIStreaming interface */
};

struct UsbVideoInputTermDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x02) */
    UBYTE bTerminalID;         /* unique ID */
    UWORD wTerminalType;       /* Terminal Type */
    UBYTE bAssocTerminal;      /* Associated Output Terminal ID */
    UBYTE bNrChannels;         /* Number of logical output channels in the output terminal */
    UWORD wChannelConfig;      /* Spacial location */
    UBYTE iChannelNames;       /* String descriptor */
    UBYTE iTerminal;           /* String descriptor */
};

struct UsbVideoOutputTermDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x03) */
    UBYTE bTerminalID;         /* unique ID */
    UWORD wTerminalType;       /* Terminal Type */
    UBYTE bAssocTerminal;      /* Associated Output Terminal ID */
    UBYTE bSourceID;           /* ID of the Unit or Terminal to which this Terminal is connected. */
    UBYTE iTerminal;           /* String descriptor */
};

/* this data structure is of no use, as it's highly variable in size */
struct UsbVideoMixerUnitDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x04) */
    UBYTE bUnitID;             /* unique ID */
    UBYTE bNrInPins;           /* Number of Input Pins */
    UBYTE baSourceID[0];       /* ID of the Unit or Terminal to which the nth Input Pin of this Mixer Unit is connected. */
    UBYTE bNrChannels;         /* Number of logical output channels in the Mixer's output video channel cluster. */
    UWORD wChannelConfig;      /* Spatial location */
    UBYTE iChannelNames;       /* String descriptor */
    UBYTE bmControls[0];       /* Controls bitmap */
    UBYTE iMixer;              /* String descriptor */
};

/* this data structure is of no use, as it's highly variable in size */
struct UsbVideoSelectorUnitDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x05) */
    UBYTE bUnitID;             /* unique ID */
    UBYTE bNrInPins;           /* Number of Input Pins */
    UBYTE baSourceID[0];       /* ID of the Unit or Terminal to which the nth Input Pin of this Selector Unit is connected. */
    UBYTE iSelector;           /* String descriptor */
};

/* this data structure is of no use, as it's highly variable in size */
struct UsbVideoFeatureUnitDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x06) */
    UBYTE bUnitID;             /* unique ID */
    UBYTE bSourceID;           /* ID of the Unit or Terminal to which this Terminal is connected. */
    UBYTE bControlSize;        /* Size in bytes of an element of the control array */
    UBYTE bmaControls[0];      /* Controls matrix */
    UBYTE iFeature;            /* String descriptor */
};

/* this data structure is of no use, as it's highly variable in size */
struct UsbVideoProcessingUnitDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x07) */
    UBYTE bUnitID;             /* unique ID */
    UWORD wProcessType;        /* type of processing */
    UBYTE bNrInPins;           /* Number of Input Pins */
    UBYTE baSourceID[0];       /* ID of the Unit or Terminal to which the nth Input Pin of this Processing Unit is connected. */
    UBYTE bNrChannels;         /* Number of logical output channels in the Mixer's output video channel cluster. */
    UWORD wChannelConfig;      /* Spatial location */
    UBYTE iChannelNames;       /* String descriptor */
    UBYTE bControlSize;        /* Size in bytes of an element of the control array */
    UBYTE bmControls[0];       /* Controls bitmap */
    UBYTE iProcessing;         /* String descriptor */
};

/* this data structure is of no use, as it's highly variable in size */
struct UsbVideoExtensionUnitDesc10
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x08) */
    UBYTE bUnitID;             /* unique ID */
    UWORD wExtensionCode;      /* vendor specific */
    UBYTE bNrInPins;           /* Number of Input Pins */
    UBYTE baSourceID[0];       /* ID of the Unit or Terminal to which the nth Input Pin of this Mixer Unit is connected. */
    UBYTE bNrChannels;         /* Number of logical output channels in the Mixer's output video channel cluster. */
    UWORD wChannelConfig;      /* Spatial location */
    UBYTE iChannelNames;       /* String descriptor */
    UBYTE bControlSize;        /* Size in bytes of an element of the control array */
    UBYTE bmControls[0];       /* Controls bitmap */
    UBYTE iExtension;          /* String descriptor */
};
 
/* USB Video Spec 2.0 stuff */
struct UsbVideoHeaderDesc20
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x01) */
    UBYTE bcdADC0;             /* Low byte of spec version (0x00)*/
    UBYTE bcdADC1;             /* High byte of spec version (0x02) */
    UBYTE bCategory;           /* Primary use of the video function */
    UWORD wTotalLength;        /* Total length of all descriptors */
    UBYTE bmControls;          /* Latency control (%00=n/a,%01=read only, %11=r/w) */
};

struct UsbVideoInputTermDesc20
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x02) */
    UBYTE bTerminalID;         /* unique ID */
    UWORD wTerminalType;       /* Terminal Type */
    UBYTE bAssocTerminal;      /* Associated Output Terminal ID */
    UBYTE bCSourceID;          /* ID of the Clock Entity */
    UBYTE bNrChannels;         /* Number of logical output channels in the output terminal */
    UBYTE bmChannelConfig[4];  /* Bitmap of spacial location */
    UBYTE iChannelNames;       /* String descriptor */
    UBYTE bmControls;          /* Various controls */
    UBYTE iTerminal;           /* String descriptor */
};

/* generic video stuff */
struct UsbVideoGeneralIFDesc
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x01) */
    UBYTE bTerminalLink;       /* Terminal linked to this interface */
    UBYTE bDelay;              /* Delay in frames */
    UBYTE wFormatTag0;         /* Data Format (low byte) */
    UBYTE wFormatTag1;         /* Data Format (high byte) */
};

struct UsbVideoType1FormatDesc
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x24) */
    UBYTE bDescriptorSubType;  /* Subtype (0x02) */
    UBYTE bFormatType;         /* Format Type I (0x01) */
    UBYTE bNrChannels;         /* Number of physical channels */
    UBYTE bSubframeSize;       /* Number of bytes occubied by one video subframe (1-4) */
    UBYTE bBitResolution;      /* Number of bits used in a subframe */
    UBYTE bSamFreqType;        /* 0 = continuous freq, otherwise number of discrete freqs */
    UBYTE tSamFreq0[3];        /* first sampling freq (or lower range) */
};

struct UsbVideoGeneralEPDesc
{
    UBYTE bLength;             /* Size of this descriptor */
    UBYTE bDescriptorType;     /* Descriptor Type (0x25) */
    UBYTE bDescriptorSubType;  /* Subtype (0x01) */
    UBYTE bmAttributes;        /* bit 0: Sampling freq, bit 1: Pitch, bit 7 = MaxPktsOnly */
    UBYTE bLockDelayUnits;     /* 0=undef, 1=ms, 2=PCM samples */
    UBYTE wLockDelay0;         /* Delay until locked (low byte) */
    UBYTE wLockDelay1;         /* Delay until locked (high byte) */
};
#endif


#if defined(__GNUC__)
# pragma pack()
#endif

#endif /* DEVICES_USB_VIDEO_H */
