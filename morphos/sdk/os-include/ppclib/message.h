#ifndef POWERUP_PPCLIB_MESSAGE_H
#define POWERUP_PPCLIB_MESSAGE_H

#include <utility/tagitem.h>

/* This file should be used under SAS and GCC
 */

#define	PPCPORTTAG_Dummy	(TAG_USER + 0x24000)
#define	PPCPORTTAG_NAME		(PPCPORTTAG_Dummy + 0)
#define	PPCPORTTAG_ERROR	(PPCPORTTAG_Dummy + 1)
/*
 * PPCObtainPort()
 */

/* To define a different network timeout
 * if PPCPORTTAG_MACHINE is used
 * Not supported yet
 */
#define	PPCPORTTAG_TIMEOUT	(PPCPORTTAG_Dummy + 2)
/* To define a machine in the network
 * Not supported yet
 */
#define	PPCPORTTAG_MACHINE	(PPCPORTTAG_Dummy + 3)
/* Search port on the local processor
 * Not supported yet
 */
#define	PPCPORTTAG_LOCAL	(PPCPORTTAG_Dummy + 4)
/* Search port on all processors
 * Not supported yet
 */
#define	PPCPORTTAG_GLOBAL	(PPCPORTTAG_Dummy + 5)


#define	PPCMSGTAG_Dummy		(TAG_USER + 0x25000)
#define	PPCMSGTAG_DATA		(PPCMSGTAG_Dummy + 0)
#define	PPCMSGTAG_DATALENGTH	(PPCMSGTAG_Dummy + 1)
#define	PPCMSGTAG_MSGID		(PPCMSGTAG_Dummy + 2)

/* Returns NT_REPLYMSG or NT_MESSAGE or NT_FREEMSG */
#define	PPCMSGTAG_MSGTYPE	(PPCMSGTAG_Dummy + 3)

#define	PPCPORTERROR_OK		0
#define	PPCPORTERROR_MEMORY	1
#define	PPCPORTERROR_SIGNAL	2
#define	PPCPORTERROR_PORTEXISTS	3
#define	PPCPORTERROR_NOTFOUND	4
#define	PPCPORTERROR_TIMEOUT	5

#define	PPCPORTLISTTAG_Dummy		(TAG_USER + 0x26000)
#define	PPCPORTLISTTAG_EXTENDEDSIGNALS	(PPCPORTLISTTAG_Dummy + 0)
#define	PPCPORTLISTTAG_RECEIVEDSIGNALS	(PPCPORTLISTTAG_Dummy + 1)

#endif
