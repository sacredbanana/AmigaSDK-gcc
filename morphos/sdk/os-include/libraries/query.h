#ifndef LIBRARIES_QUERY_H
#define LIBRARIES_QUERY_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_DEVICES_H
#include <exec/devices.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif


struct QueryPathEntry
{
        char    *Path;
        char    *Pattern;
        ULONG   Flags;
};

#define QUERYPATHFLAGF_ALL                      0x1
#define QUERYPATHFLAGF_DONTFOLLOWSOFTLINKS      0x2

struct QueryPCIMatch
{
        ULONG   Vendor;
        ULONG   VendorMask;
        ULONG   Device;
        ULONG   DeviceMask;
        ULONG   Class;
        ULONG   ClassMask;
        ULONG   SubClass;
        ULONG   SubClassMask;
        ULONG   ProgInfo;
        ULONG   ProgInfoMask;
};

struct QueryDosTypeMatch
{
        ULONG   DosType;
        ULONG   Mask;
};

struct QueryExtDosTypeMatch
{
        ULONG   DosType;
        ULONG   Mask;
        STRPTR  Name;
};


struct QueryUnitID
{
        struct Unit     *Unit;
        ULONG           ID;
};

/*
 * QueryGetAttr(struct QueryInfo*,ULONG Attr);
 */

#define QUERYINFOATTR_Dummy             (TAG_USER +0x01001000)

/*
 * return the name from the object which is needed to reference it
 * Data: (char *)
 */
#define QUERYINFOATTR_NAME              (QUERYINFOATTR_Dummy+0)
/*
 * return the id string from the object, including "$VER: "
 * Data: (char *)
 */
#define QUERYINFOATTR_IDSTRING          (QUERYINFOATTR_Dummy+1)
/*
 * return a description string about the object usage
 * Data: (char *)
 */
#define QUERYINFOATTR_DESCRIPTION       (QUERYINFOATTR_Dummy+2)
/*
 * return a copyright string from the object
 * Data: (char *)
 */
#define QUERYINFOATTR_COPYRIGHT         (QUERYINFOATTR_Dummy+3)
/*
 * return an author string from the object
 * Data: (char *)
 */
#define QUERYINFOATTR_AUTHOR            (QUERYINFOATTR_Dummy+4)
/*
 * return a date string from the object
 * Data: (char *)
 */
#define QUERYINFOATTR_DATE              (QUERYINFOATTR_Dummy+5)
/*
 * obsolete, don't reuse
 * Data: -
 */
#define QUERYINFOATTR_OBSOLETE1         (QUERYINFOATTR_Dummy+6)
/*
 * return the version from the object
 * Data: (ULONG)
 */
#define QUERYINFOATTR_VERSION           (QUERYINFOATTR_Dummy+7)
/*
 * return the revision from the object
 * Data: (ULONG)
 */
#define QUERYINFOATTR_REVISION          (QUERYINFOATTR_Dummy+8)
/*
 * return the release tag string from the object
 * Something like "release","alpha","beta" and so on
 * Data: (char *)
 */
#define QUERYINFOATTR_RELEASETAG        (QUERYINFOATTR_Dummy+9)

#define QUERYINFOATTR_CODETYPE          (QUERYINFOATTR_Dummy+10)
/*
 * give me a filename if it's an external object
 */
#define QUERYINFOATTR_FILENAME          (QUERYINFOATTR_Dummy+11)
/*
 * SegList, usually only valid during the lifetime of the QueryInfo (V51)
 * Only exception would be internal filesystems
 * Data: BPTR
 */
#define QUERYINFOATTR_SEGLIST           (QUERYINFOATTR_Dummy+12)

/*
 * QUERYTYPE_#?
 * This type defines where the object was found.
 * It makes no sense to return this type in a QueryTagList or
 * through GetQueryAttr(), as it's the internal type of an
 * object.
 */
#define QUERYINFOATTR_TYPE              (QUERYINFOATTR_Dummy+13)
/*
 * QUERYSUBTYPE_#?
 * This type defines the real object type
 */
#define QUERYINFOATTR_SUBTYPE           (QUERYINFOATTR_Dummy+14)
/*
 * QUERYCLASS_#?
 */
#define QUERYINFOATTR_CLASS             (QUERYINFOATTR_Dummy+15)
/*
 * QUERYSUBCLASS_#?
 */
#define QUERYINFOATTR_SUBCLASS          (QUERYINFOATTR_Dummy+16)
/*
 * Priority
 * Data: LONG
 */
#define QUERYINFOATTR_PRI               (QUERYINFOATTR_Dummy+17)

/*
 * Ptr to
 * ULONG VENDORID, VENDORIDMASK,
 * ULONG DEVICEID, DEVICEIDMASK,
 * ULONG    CLASS, CLASSMASK,
 * ULONG SUBCLASS, SUBCLASSMASK,
 * ULONG PROGINFO, PROGINFOMASK
 * ends with all entries as 0, so you can specify several entries
 */
#define QUERYINFOATTR_PCIMATCH          (QUERYINFOATTR_Dummy+20)
/*
 * Array with DosTypes+Mask the filesystems supports
 * Data = struct QueryDosTypeMatch*
 * must end with a 0
 */
#define QUERYINFOATTR_FS_DOSTYPEMATCH   (QUERYINFOATTR_Dummy+30)
/*
 * Filesystem supports a Startup Argument String(ReadArgs pattern)
 * Data: char *RDArgs Pattern
 */
#define QUERYINFOATTR_FS_STARTUP        (QUERYINFOATTR_Dummy+31)
/*
 * Filesystem supports a Control Argument String(ReadArgs pattern)
 * Data: char *RDArgs Pattern
 */
#define QUERYINFOATTR_FS_CONTROL        (QUERYINFOATTR_Dummy+32)
/*
 * Filesystem supports FSContext
 * Data: Boolean
 */
#define QUERYINFOATTR_FS_FSCONTEXT      (QUERYINFOATTR_Dummy+33)
/*
 * Filesystem's StackSize
 * Data: ULONG
 */
#define QUERYINFOATTR_FS_STACKSIZE      (QUERYINFOATTR_Dummy+34)
/*
 * Filesystem's Globalvec, only valid for an internal filesysentry
 * Data: ULONG
 */
#define QUERYINFOATTR_FS_GLOBALVEC      (QUERYINFOATTR_Dummy+35)
/*
 * Filesystem's SegList
 * Data: void *
 */
#define QUERYINFOATTR_FS_SEGLIST        (QUERYINFOATTR_Dummy+36)
/*
 * Array with DosTypes+Mask+Name the filesystems supports
 * Data = struct QueryExtDosTypeMatch*
 * must end with a 0
 */
#define QUERYINFOATTR_FS_EXTDOSTYPEMATCH (QUERYINFOATTR_Dummy+37)


/*
 * Device max allowed Units
 * Data: ULONG
 */
#define QUERYINFOATTR_DEVICE_UNITS      (QUERYINFOATTR_Dummy+40)
/*
 * Device max allowed Luns
 * Data: ULONG
 */
#define QUERYINFOATTR_DEVICE_LUNS       (QUERYINFOATTR_Dummy+41)
/*
 * Device supports New Format UnitIDs(only needed for scsi devices which support wide)
 * Data: ULONG
 */
#define QUERYINFOATTR_DEVICE_NEWFORMAT  (QUERYINFOATTR_Dummy+42)
/*
 * Device supports a RdArgs String through the flags parameter
 * Data: (char*) ReadArgs mask
 */
#define QUERYINFOATTR_DEVICE_FLAGS_TEMPLATE     (QUERYINFOATTR_Dummy+43)
/*
 * Device's Mask parameter
 * Data: ULONG
 */
#define QUERYINFOATTR_DEVICE_MASK     (QUERYINFOATTR_Dummy+44)
/*
 * Device's MaxTransfer parameter
 * Data: ULONG
 */
#define QUERYINFOATTR_DEVICE_MAXTRANSFER   (QUERYINFOATTR_Dummy+45)
/*
 * Device's Unit's OpenDevice ID in appropriate format
 * Data: struct QueryUnitID*
 */
#define QUERYINFOATTR_DEVICE_UNIT_ID     (QUERYINFOATTR_Dummy+46)
/*
 * Device's Unit's UnitID
 * Data: struct QueryUnitID*
 */
#define QUERYINFOATTR_DEVICE_UNIT_UNIT   (QUERYINFOATTR_Dummy+47)
/*
 * Device's Unit's LunID
 * Data: struct QueryUnitID*
 */
#define QUERYINFOATTR_DEVICE_UNIT_LUN    (QUERYINFOATTR_Dummy+48)
/*
 * Device supports a config file with RdArgs format
 * Data: (char*) ReadArgs string
 */
#define QUERYINFOATTR_DEVICE_CONFIG_TEMPLATE     (QUERYINFOATTR_Dummy+49)


/*
 * Net tags
 */
#define QUERYINFOATTR_NET_LINK          (QUERYINFOATTR_Dummy+100)
/*
 * Default IP Frame Type
 */
#define QUERYINFOATTR_NET_IPTYPE        (QUERYINFOATTR_Dummy+102)
/*
 * Default ARP Frame Type
 */
#define QUERYINFOATTR_NET_ARPTYPE       (QUERYINFOATTR_Dummy+103)

/*
 * Language tags
 */

/*
 * Language associated with the object
 * Data: (char*)
 */
#define QUERYINFOATTR_LANG_LANGUAGE     (QUERYINFOATTR_Dummy+150)
/*
 * Language name in english
 * Data: (char*)
 */
#define QUERYINFOATTR_LANG_LANGUAGE_INT (QUERYINFOATTR_Dummy+151)
/*
 * Codepage associated with the object/language (refer to iconv
 * docs for the list of codepages)
 * Data: (char*)
 */
#define QUERYINFOATTR_LANG_CODEPAGE     (QUERYINFOATTR_Dummy+152)

/*
 * Below..all custom attrs start
 */
#define QUERYINFOATTR_CUSTOM            (QUERYINFOATTR_Dummy+0x1000)

/*
 * Custom tags used by the keymaps
 */
#define QUERYINFOATTR_CUSTOM_KEYMAP_UNICODECONVTABLE (QUERYINFOATTR_CUSTOM + 1)
#define QUERYINFOATTR_CUSTOM_KEYMAP_CHARSETCONVTABLE (QUERYINFOATTR_CUSTOM + 2)

/*
 * Custom tags used by the mprefs classes
 */
#define QUERYINFOATTR_CUSTOM_MPREFS_MACHINEPATTERN   (QUERYINFOATTR_CUSTOM + 1)

/***********************************************************************************
 *
 * Obtain Tags
 *
 */

#define QUERYFINDATTR_Dummy                     (TAG_USER +0x01001200)

/*
 * search for an object with this name
 */
#define QUERYFINDATTR_NAME                      (QUERYFINDATTR_Dummy+0)

/*
 * search for an object with this type
 */
#define QUERYFINDATTR_TYPE                      (QUERYFINDATTR_Dummy+1)

/*
 * search for an object with this subtype
 */
#define QUERYFINDATTR_SUBTYPE                   (QUERYFINDATTR_Dummy+2)

/*
 * search for an object with this class
 */
#define QUERYFINDATTR_CLASS                     (QUERYFINDATTR_Dummy+3)

/*
 * search for an object with this subclass
 */
#define QUERYFINDATTR_SUBCLASS                  (QUERYFINDATTR_Dummy+4)

/*
 * define if the search should happen externally(using DOS paths)
 */
#define QUERYFINDATTR_EXTERNAL                  (QUERYFINDATTR_Dummy+10)

/*
 * define a dos path search table
 */
#define QUERYFINDATTR_PATHTABLE                 (QUERYFINDATTR_Dummy+11)

/*
 * define if the global search table should be used
 */
#define QUERYFINDATTR_NOGLOBALPATHTABLE         (QUERYFINDATTR_Dummy+12)

/*
 * define a custom filter hook
 */
#define QUERYFINDATTR_FILTERHOOK                (QUERYFINDATTR_Dummy+13)

/*
 * define a custom filter pattern
 */
#define QUERYFINDATTR_FILTERPATTERN             (QUERYFINDATTR_Dummy+14)


/*
 * Ptr to
 * ULONG VENDORID, VENDORIDMASK,
 * ULONG DEVICEID, DEVICEIDMASK,
 * ULONG    CLASS, CLASSMASK,
 * ULONG SUBCLASS, SUBCLASSMASK,
 * ULONG PROGINFO, PROGINFOMASK
 * ends with all entries as 0, so you can specify several entries
 */
#define QUERYFINDATTR_PCIMATCH                  (QUERYFINDATTR_Dummy+20)
/*
 * define a dostype for what it should search
 */
#define QUERYFINDATTR_FS_DOSTYPE                (QUERYFINDATTR_Dummy+21)



/*********************************************************************************/

/*
 * Type of a query object
 */

/*
 * No legal type, QueryInfo with such type is equal to nil
 */
#define QUERYTYPE_NONE          0
/*
 * a resident list query element
 */
#define QUERYTYPE_RESIDENT      1
/*
 * a library list query element
 */
#define QUERYTYPE_LIBRARY       2
/*
 * a device query element
 */
#define QUERYTYPE_DEVICE        3
/*
 * a filesystem query element
 */
#define QUERYTYPE_FILESYSTEM    4
/*
 * an external load query element
 */
#define QUERYTYPE_DOS           5

/*
 * SubType of a query object
 * This is the real type of the queryinfo object to
 * define how to open it.
 */
#define QUERYSUBTYPE_NONE               0
#define QUERYSUBTYPE_LIBRARY            1
#define QUERYSUBTYPE_DEVICE             2
#define QUERYSUBTYPE_HANDLER            3
#define QUERYSUBTYPE_MUICLASS           4
#define QUERYSUBTYPE_KEYMAP             5
#define QUERYSUBTYPE_OBJCFRAMEWORK      6

/*
 * Class of a query object
 */
#define QUERYCLASS_NONE         0
#define QUERYCLASS_HANDLER      1
#define QUERYCLASS_FILESYSTEM   2

#define QUERYCLASS_DATATYPE     10

#define QUERYCLASS_GRAPHICS     20

#define QUERYCLASS_STORAGE      30

#define QUERYCLASS_NET          40

#define QUERYCLASS_USB          50      /* USB Hardware Devices */
#define QUERYCLASS_USBCLASS     51      /* USB Stack Classes */

#define QUERYCLASS_FIREWIRE     60

#define QUERYCLASS_OBJDATA      70

#define QUERYCLASS_PARALLEL     80

#define QUERYCLASS_SERIAL       90

#define QUERYCLASS_MUI          100

#define QUERYCLASS_MULTIMEDIA   130

#define QUERYCLASS_INTUITION    160
#define QUERYCLASS_INTUITION_SCREENBAR 161

#define QUERYCLASS_PRINTER      190

#define QUERYCLASS_SCANNER      200

#define QUERYCLASS_PREFSCLASS   220

#define QUERYCLASS_AMBIENT      230

/*
 * SubClass of a query object
 */

#define QUERYSUBCLASS_NONE              0

#define QUERYSUBCLASS_STORAGE_SCSI      30
#define QUERYSUBCLASS_STORAGE_IDE       31
#define QUERYSUBCLASS_STORAGE_USB       32
#define QUERYSUBCLASS_STORAGE_FIREWIRE  33
#define QUERYSUBCLASS_STORAGE_DVDRW     34      /* meta device */

#define QUERYSUBCLASS_NET_ETHERNET      40	/* IEEE 802.3 */
#define QUERYSUBCLASS_NET_PPP           41
#define QUERYSUBCLASS_NET_PPTP          42
#define QUERYSUBCLASS_NET_WLAN          43	/* IEEE 802.11 */

#define QUERYSUBCLASS_USB_UHCI          90
#define QUERYSUBCLASS_USB_OHCI          91
#define QUERYSUBCLASS_USB_EHCI          92

#define QUERYSUBCLASS_OBJDATA_ELF       100
#define QUERYSUBCLASS_OBJDATA_HUNK      101
#define QUERYSUBCLASS_OBJDATA_COFF      102

#define QUERYSUBCLASS_SERIAL_RS232      200
#define QUERYSUBCLASS_SERIAL_MODEM      201
#define QUERYSUBCLASS_SERIAL_IRDA       202
#define QUERYSUBCLASS_SERIAL_USB        203
#define QUERYSUBCLASS_SERIAL_BLUETOOTH  204

#define QUERYSUBCLASS_HANDLER_CON       1000

#define QUERYSUBCLASS_FILESYSTEM_CD     2000
#define QUERYSUBCLASS_FILESYSTEM_MASSSTORAGE 2001

#define QUERYSUBCLASS_MULTIMEDIA_ENCODER 3000
#define QUERYSUBCLASS_MULTIMEDIA_DECODER 3001
#define QUERYSUBCLASS_MULTIMEDIA_STREAM  3002
#define QUERYSUBCLASS_MULTIMEDIA_OUTPUT  3003
#define QUERYSUBCLASS_MULTIMEDIA_DEMUXER 3004
#define QUERYSUBCLASS_MULTIMEDIA_MUXER   3005
#define QUERYSUBCLASS_MULTIMEDIA_BASIC   3006
#define QUERYSUBCLASS_MULTIMEDIA_FILTER  3007

#define QUERYSUBCLASS_INTUITION_BLANKERAPI 4000

#define QUERYSUBCLASS_USBCLASS_KEYBOARD    10000
#define QUERYSUBCLASS_USBCLASS_MOUSE       10001
#define QUERYSUBCLASS_USBCLASS_HID         10002
#define QUERYSUBCLASS_USBCLASS_HUB         10003
#define QUERYSUBCLASS_USBCLASS_PRINTER     10004
#define QUERYSUBCLASS_USBCLASS_SERIAL      10005
#define QUERYSUBCLASS_USBCLASS_STORAGE     10006
#define QUERYSUBCLASS_USBCLASS_BLUETOOTH   10007
#define QUERYSUBCLASS_USBCLASS_MIDI        10008
#define QUERYSUBCLASS_USBCLASS_MODEM       10009 /* isn't this the same as SERIAL? */
#define QUERYSUBCLASS_USBCLASS_ETHERNET    10010
#define QUERYSUBCLASS_USBCLASS_WLAN        10011
#define QUERYSUBCLASS_USBCLASS_AUDIO       10012

#define QUERYSUBCLASS_PREFSCLASS_SYSTEM    20000
#define QUERYSUBCLASS_PREFSCLASS_INPUT     20001
#define QUERYSUBCLASS_PREFSCLASS_UI        20002
#define QUERYSUBCLASS_PREFSCLASS_AUDIO     20003
#define QUERYSUBCLASS_PREFSCLASS_NETWORK   20004
#define QUERYSUBCLASS_PREFSCLASS_DEVICES   20005
#define QUERYSUBCLASS_PREFSCLASS_FS        20006
#define QUERYSUBCLASS_PREFSCLASS_INTERNET  20007

#define QUERYSUBCLASS_AMBIENT_PANEL        30000

#define QUERYSUBCLASS_SCANNER_SANE         40000

/*
 * Net Link Types used by tunnel devices
 * like PPP
 */

#define QUERYNETLINK_SANA2      0
#define QUERYNETLINK_SERIAL     1

#endif /* LIBRARIES_QUERY_H */
