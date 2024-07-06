/*

		MCC_Tron (c) by kMel, Klaus Melchior

		Registered class of the Magic User Interface.

		Tron_mcc.h

*/


/*** Include stuff ***/

#ifndef TRON_MCC_H
#define TRON_MCC_H

#ifndef LIBRARIES_MUI_H
#include "libraries/mui.h"
#endif


/*** MUI Defines ***/

#define MUIC_Tron "Tron.mcc"
#define TronObject MUI_NewObject(MUIC_Tron



/*** Methods ***/

#define MUIM_Tron_Demo           0x8002000b

/*** Method structs ***/

struct MUIP_Tron_Demo {
	ULONG MethodID;
};


/*** Special method values ***/

#define MUIV_Tron_Demo_Simple                  0


/*** Special method flags ***/



/*** Attributes ***/

#define MUIA_Tron_Running        0x80020040

/*** Special attribute values ***/



/*** Structures, Flags & Values ***/





#endif /* TRON_MCC_H */

/* PrMake.rexx 0.10 (16.2.1996) Copyright 1995 kmel, Klaus Melchior */

