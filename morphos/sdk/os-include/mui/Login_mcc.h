/****************************************************************************/
/* Login.mcc (c) Copyright 2006 by Ralph Schmidt                            */
/* Registered MUI class, Serial Num: fecd                                   */
/****************************************************************************/

#ifndef MUI_Login_MCC_H
#define MUI_Login_MCC_H

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif



#define MUIC_Login "Login.mcc"
#define LoginObject MUI_NewObject(MUIC_Login

#define TAGBASE_LOGIN	0xfecd0000
/* Attributes */

#define	MA_Login_User		( TAGBASE_LOGIN | 0x0080 )
#define	MA_Login_Passwd		( TAGBASE_LOGIN | 0x0081 )
#define	MA_Login_Action		( TAGBASE_LOGIN | 0x0082 )
#define	MA_Login_Extended	( TAGBASE_LOGIN | 0x0083 )

#define	LOGINACTION_CANCEL		0
#define	LOGINACTION_LOGIN		1
#define	LOGINACTION_REBOOT		2
#define	LOGINACTION_SHUTDOWN	3

#endif /* MUI_Login_MCC_H */
