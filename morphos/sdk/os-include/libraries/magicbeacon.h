#ifndef LIBRARIES_MAGICBEACON_H
#define LIBRARIES_MAGICBEACON_H

/*************************************************************************/

#ifndef UTILITY_UTILITY_H
# include <utility/tagitem.h>
#endif

/*************************************************************************/

#define MAGICBEACON_NAME       "magicbeacon.library"   /* library name */

/* TAG flags
**
** R - MagicBeacon_ApplicationRegister() call
** G - MagicBeacon_GetAttr#?() call
** S - MagicBeacon_SendBeacon() call
*/


#define MAGICBEACON_APPLICATIONSIGNALNUMBER   (TAG_USER + 0x00000001 )    /* RG - LONG  - register/get the signal in numeric form.
                                                                                          When -1 is specified as signal as signal
                                                                                          will be allocated. */
#define MAGICBEACON_APPLICATIONSIGNALMASK     (TAG_USER + 0x00000002 )    /* RG - IPTR  - register/get the signal in signal mask
                                                                                          form */

/* NOTE:
**
** If none of the signal tags above is used to define a signal for operation during
** application registration process, MAGICBEACON_WAITFORRESULT, FALSE is used for
** all beacons. Therefor the application will never receive any result.
*/

#define MAGICBEACON_APPLICATIONNAME           (TAG_USER + 0x00000003 )    /* RG - STRPTR - Application name ([0-9,a-z,A-Z]) */

#define MAGICBEACON_NOTIFICATIONNAME          (TAG_USER + 0x00000101 )    /* SG - STRPTR - MBN_#? like defined below */
#define MAGICBEACON_MESSAGE                   (TAG_USER + 0x00000102 )    /* SG - STRPTR - Message in system codeset */
#define MAGICBEACON_MESSAGE_UTF8              (TAG_USER + 0x00000103 )    /* SG - STRPTR - Message in utf8 codeset */
#define MAGICBEACON_USERDATA                  (TAG_USER + 0x00000104 )    /* SG - APTR   - Place your application information here */
#define MAGICBEACON_WAITFORRESULT             (TAG_USER + 0x00000105 )    /* S- - BOOL   - Default: TRUE */
#define MAGICBEACON_RESULT                    (TAG_USER + 0x00000106 )    /* -G - IPTR   - NOTIFICATIONRESULT_#? as defined below */


#define NOTIFICATIONRESULT_IGNORED              0      /* user ignored notification */
#define NOTIFICATIONRESULT_CONFIRMED            1      /* user confirmed notification */
#define NOTIFICATIONRESULT_CANCELLED            2      /* user rejected notification */
#define NOTIFICATIONRESULT_NOTDISPLAYED         3      /* message was not displayed (e.g. program quit while
                                                       ** notification still being cached or there was not
                                                       ** enough memory to process the message properly )
                                                       */

/* These are the error values returned by various functions
*/

#define MAGICBEACON_ERROR_NOERROR                0      /* Operation was successful */
#define MAGICBEACON_ERROR_HANDLEMISSING          1      /* The provided handle was NULL */
#define MAGICBEACON_ERROR_OUTOFMEMORY            2      /* There wasn´t enough memory available to process the beacon */
#define MAGICBEACON_ERROR_NAMEMISSING            3      /* MAGICBEACON_NAME is required */
#define MAGICBEACON_ERROR_NAMEINVALID            4      /* MAGICBEACON_NAME or MAGICBEACON_APPLICATIONNAME contain invalid characters */
#define MAGICBEACON_ERROR_NAMEHASWRONGSIZE       5      /* MAGICBEACON_NAME or MAGICBEACON_APPLICATIONNAME has the wrong size ( 3-31 ) */
#define MAGICBEACON_ERROR_MAGICBEACONNOTRUNNING  6      /* Notification couldn´t be send because MagicBeacon application is not running */

/*************************************************************************/

#define MAGICBEACON_APPLICATIONNAME_MAXLENGTH  31       /* MAGICBEACON_APPLICATIONNAME size limit */
#define MAGICBEACON_NOTIFICATIONNAME_MAXLENGTH 31       /* MAGICBEACON_NAME size limit */

/*************************************************************************/

/* Standardized notification names
**
** The list will grow along with the ideas. If you use these, then it is
** required to deliver the information mentioned inside the comment, so
** all applications send informations alike. That is the %m part the user
** can place inside his messages.
**
** If you need to encode this textual part, use the UTF-8 notification
** tag. Once set the mbnm_NotificationMessage and only this field will
** be treated as UTF-8.
**
** In case you need to send a more specific information or something
** completely different, then just define your own notification name,
** but please keep in mind that other applications with the same purpose
** may have a similar need, so choose your name properly.
*/

#define MBN_ERROR                     "Error"                        /* %m          - Error message */
#define MBN_NEWMAIL                   "NewMail"                      /* %m          - EMail summery (multiple mails) or sender and topic information\n */
#define MBN_NEWRSS                    "NewRSS"                       /* %m          - Topic of the feed */
#define MBN_TRACKNEXT                 "TrackNext"                    /* %m          - Title of track */
#define MBN_TRACKLAST                 "TrackLast"                    /* %m          - Application specific message */
#define MBN_NEWPRIVATEMSG             "NewPrivateMSG"                /* %m          - Chat line */
#define MBN_NEWMSG                    "NewMSG"                       /* %m          - Chat line */
#define MBN_CONNECTED                 "Connected"                    /* %m          - Server name */
#define MBN_DISCONNECTED              "Disconnected"                 /* %m          - Server name */
#define MBN_CONNECTIONFAILED          "ConnectionFailed"             /* %m          - Server name */
#define MBN_TRANSFERCOMPLETE          "TransferComplete"             /*             - No message */
#define MBN_TRANSFERDONE              "TransferDone"                 /* %p %d %f %g - Full path with file name */
#define MBN_TRANSFERFAILED            "TransferFailed"               /* %p %d %f %g - Full path with file name */
#define MBN_TRANSFERABORTED           "TransferAborted"              /* %p %d %f %g - Full path with file name */
#define MBN_OPERATIONDONE             "OperationDone"                /* %m          - Name of finished operation (e.g. "Defragmentation complete") */
#define MBN_UPDATEAVAILABLE           "UpdateAvailable"              /* %m          - Name of the available update (e.g. application name) */
#define MBN_WEBNOTIFICATION           "WebNotification"              /* %m          - Message contains plain web notification */
#define MBN_SCREENSHOT                "ScreenShot"                   /* %p %d %f %g - Full path with file name */
#define MBN_WINDOWSHOT                "WindowShot"                   /* %p %d %f %g - Full path with file name */
#define MBN_CLIPBOARDADDED            "ClipboardAdded"               /* %m          - Clipboard unit the data was stored */
#define MBN_CLIPBOARDSCREENSHOT       "ClipboardScreenShot"          /* %m          - Clipboard unit the image was stored */
#define MBN_CLIPBOARDWINDOWSHOT       "ClipboardWindowShot"          /* %m          - Clipboard unit the image was stored */
#define MBN_CLIPBOARDPASSWORD         "ClipboardPassword"            /* %m          - Clipboard unit the password was stored */
#define MBN_CLIPBOARDPASSWORDREMOVED  "ClipboardPasswordRemoved"     /* %m          - Clipboard unit the password was removed from */
#define MBN_CALLINCOMING              "CallIncoming"                 /* %m          - Callers number followed by \n<name>. "0556511223344\nJim Panse\nOptional stuff" */
#define MBN_CALLOUTGOING              "CallOutgoing"                 /* %m          - Called number followed by \n<name>. "0556511223344\nJim Panse\nOptional stuff" */
#define MBN_CALLDONE                  "CallDone"                     /* %m          - Information on the finished call if possible */
#define MBN_WIFICONNECTED             "WiFiConnected"                /* %m          - SSID of the wireless network */
#define MBN_WIFIDISCONNECTED          "WiFiDisconnected"             /* %m          - SSID of the wireless network */
#define MBN_WIFICONNECTIONFAILED      "WiFiConnetionFailed"          /* %m          - SSID of the wireless network */

/*************************************************************************/

#endif /* LIBRARIES_MAGICBEACON_H */
