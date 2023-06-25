#ifndef LIBRARIES_SCREENBLANKER_H
#define LIBRARIES_SCREENBLANKER_H
/*
**  $VER: screenblanker.h 54.16 (22.08.2022)
**
**	Definitions for the screenblanker library system.
**
**  Author: Stefan Robl <stefan@qdev.de>
**
**   (c) Copyright 2005 Amiga, Inc.
**       All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif


/******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

enum enScreenBlankerBlankingModes
{
	SBBM_NoBlanking    = 0,
	SBBM_Preview       = 1,
	SBBM_Blanking      = 2,
	SBBM_DPMS_Standby  = 3,
	SBBM_DPMS_Suspend  = 4,
	SBBM_DPMS_PowerOff = 5
};

struct ScreenBlankerNotificationTask
{
	struct Task *task;
	uint32 signal;
};

enum enScreenBlankerTags
{
	/* ScreenBlankerAttrs() Tags */
	SBATTR_RenderHook                 =  (TAG_USER+1), // set & get   struct Hook *
	SBATTR_RenderRastPort             =  (TAG_USER+2), // get only    struct RastPort *
	SBATTR_BlankingTime               =  (TAG_USER+3), // set & get   uint32
	SBATTR_DPMSStandbyTime            =  (TAG_USER+4), // set & get   uint32
	SBATTR_DPMSSuspendTime            =  (TAG_USER+5), // set & get   uint32
	SBATTR_DPMSPowerOffTime           =  (TAG_USER+6), // set & get   uint32
	SBATTR_ActionNotificationTask     =  (TAG_USER+7), // set & get   struct ScreenBlankerNotificationTask *
	SBATTR_SecondsSinceLastInputEvent =  (TAG_USER+8), // get only    uint32
	SBATTR_IgnoreMouseWhileDPMS       =  (TAG_USER+9), // set & get   BOOL

	/* OpenBlankerModule() Tags */
	OBM_OpenedBlankerModuleInterface  = (TAG_USER+10), // struct BlankerModuleIFace **
};

/******************************************************************************/

#ifdef __cplusplus
}
#endif

/******************************************************************************/

#endif    /*  LIBRARIES_SCREENBLANKER_H  */
