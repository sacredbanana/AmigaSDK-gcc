#ifndef LIBRARIES_OPENURL_H
#define LIBRARIES_OPENURL_H

/*
**  $VER: openurl.h 6.3 (17.4.2005)
**  Includes Release 6.3
**
**  openurl.library - universal URL display and browser
**  launcher library
**
**  Written by Troels Walsted Hansen <troels@thule.no>
**  Placed in the public domain.
**
**  Developed by:
**  - Alfonso Ranieri <alforan@tin.it>
**  - Stefan Kost <ensonic@sonicpulse.de>
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack(2)
  #elif defined(__VBCC__)
    #pragma amiga-align
  #endif
#endif

/**************************************************************************/
/*
** Names
*/

#define OPENURLNAME "openurl.library"
#define OPENURLVER  6

/**************************************************************************/
/*
** Tags
*/

#define URL_Tagbase                  TAG_USER

#define URL_Show                     (URL_Tagbase + 1) /* ULONG - show/uniconify browser */
#define URL_BringToFront             (URL_Tagbase + 2) /* ULONG - bring browser to front */
#define URL_NewWindow                (URL_Tagbase + 3) /* ULONG - open URL in new window */
#define URL_Launch                   (URL_Tagbase + 4) /* ULONG - launch browser when not running */
#define URL_PubScreenName            (URL_Tagbase + 5) /* STRPTR - name of public screen to launch at */

#define URL_GetPrefs_Default         (URL_Tagbase + 20)
#define URL_SetPrefs_Save            (URL_Tagbase + 30)

#define URL_GetAttr_Version          (URL_Tagbase + 60)
#define URL_GetAttr_Revision         (URL_Tagbase + 61)
#define URL_GetAttr_VerString        (URL_Tagbase + 62)
#define URL_GetAttr_PrefsVer         (URL_Tagbase + 63)
#define URL_GetAttr_HandlerVersion   (URL_Tagbase + 64)
#define URL_GetAttr_HandlerRevision  (URL_Tagbase + 65)
#define URL_GetAttr_HandlerVerString (URL_Tagbase + 66)

/**************************************************************************/

#define REXX_CMD_LEN       64
#define NAME_LEN           32
#define PATH_LEN          256
#define PORT_LEN           32

#define SHOWCMD_LEN       REXX_CMD_LEN
#define TOFRONTCMD_LEN    REXX_CMD_LEN
#define OPENURLCMD_LEN    REXX_CMD_LEN
#define OPENURLWCMD_LEN   REXX_CMD_LEN
#define WRITEMAILCMD_LEN  (REXX_CMD_LEN * 2)

/**************************************************************************/
/*
** Version 4 Prefs
*/

#define PREFS_VERSION ((UBYTE)4)

struct URL_Prefs
{
	UBYTE          up_Version;         /* always check this version number! */
	struct MinList up_BrowserList;     /* list of struct URL_BrowserNodes */
	struct MinList up_MailerList;      /* V3 - list of struct URL_MailerNodes */
	struct MinList up_FTPList;         /* V4 - list of struct URL_MailerNodes */

	ULONG          up_Flags;           /* V2 - flags, see below            */
	
	ULONG          up_DefShow;         /* these BOOLs are the defaults for */
	ULONG          up_DefBringToFront; /* the similarly named tags         */
	ULONG          up_DefNewWindow;    /* they are all new with Version 2  */
	ULONG          up_DefLaunch;
};

/* up_Flags */
enum
{
    UPF_ISDEFAULTS  = 1<<0, /* V2 - structure contains the default settings             */
    UPF_PREPENDHTTP = 1<<1, /* V3 - prepend "http://" to URLs w/o scheme                */
    UPF_DOMAILTO    = 1<<2, /* V3 - mailto: URLs get special treatment                  */
    UPF_DOFTP       = 1<<3, /* V4 - ftp:// URLs get special treatment                   */
};

/**************************************************************************/
/*
** Common #?_Flags values
*/

enum
{
    UNF_DISABLED = 1<<1,  /* The entry is disabled */

    UNF_NEW      = 1<<16, /* Reserved for OpenURL preferences application */
    UNF_NTALLOC  = 1<<17, /* Reserved for OpenURL preferences application */
};

/**************************************************************************/
/*
** Browsers
*/

struct URL_BrowserNode
{
	struct MinNode ubn_Node;
	ULONG          ubn_Flags;                        /* flags, see below */
	TEXT           ubn_Name[NAME_LEN];               /* name of webbrowser */
	TEXT           ubn_Path[PATH_LEN];               /* complete path to browser */
	TEXT           ubn_Port[PORT_LEN];               /* webbrowser arexx port */
	TEXT           ubn_ShowCmd[SHOWCMD_LEN];         /* command to show/uniconify browser */
	TEXT           ubn_ToFrontCmd[TOFRONTCMD_LEN];   /* command to bring browser to front */
	TEXT           ubn_OpenURLCmd[OPENURLCMD_LEN];   /* command to open url */
	TEXT           ubn_OpenURLWCmd[OPENURLWCMD_LEN]; /* command to open url in new window */
};

/* ubn_Flags */
enum
{
    UBNF_URLONCMDLINE = 1<<0,    /* if set, browser supports getting an URL on
                                    the commandline when launched. obsolete as
                                    of V3 - use %u on commandline instead */
};

/**************************************************************************/
/*
** Mailers
*/

struct URL_MailerNode
{
	struct MinNode umn_Node;
	ULONG          umn_Flags;                          /* flags, none defined */
	TEXT           umn_Name[NAME_LEN];                 /* name of mailer */
	TEXT           umn_Path[PATH_LEN];                 /* complete path to mailer */
	TEXT           umn_Port[PORT_LEN];                 /* mailer arexx port */
	TEXT           umn_ShowCmd[SHOWCMD_LEN];           /* command to show/uniconify mailer */
	TEXT           umn_ToFrontCmd[TOFRONTCMD_LEN];     /* command to bring mailer to front */
	TEXT           umn_WriteMailCmd[WRITEMAILCMD_LEN]; /* command to write mail */
};

/**************************************************************************/
/*
** FTPs
*/

struct URL_FTPNode
{
	struct MinNode ufn_Node;
	ULONG          ufn_Flags;                        /* flags, see below */
	TEXT           ufn_Name[NAME_LEN];               /* name of ftp client */
	TEXT           ufn_Path[PATH_LEN];               /* complete path to ftp client */
	TEXT           ufn_Port[PORT_LEN];               /* webbrowser arexx port */
	TEXT           ufn_ShowCmd[SHOWCMD_LEN];         /* command to show/uniconify ftp client */
	TEXT           ufn_ToFrontCmd[TOFRONTCMD_LEN];   /* command to bring ftp client to front */
	TEXT           ufn_OpenURLCmd[OPENURLCMD_LEN];   /* command to open url */
	TEXT           ufn_OpenURLWCmd[OPENURLWCMD_LEN]; /* command to open url in new window */
};

/* ufn_Flags */
enum
{
    UFNF_REMOVEFTP = 1<<0,    /* if set, ftp:// ise removed from the URL */
};

/**************************************************************************/

#if defined(__PPC__)
  #if defined(__GNUC__)
    #pragma pack()
  #elif defined(__VBCC__)
    #pragma default-align
  #endif
#endif

#endif /* LIBRARIES_OPENURL_H */
