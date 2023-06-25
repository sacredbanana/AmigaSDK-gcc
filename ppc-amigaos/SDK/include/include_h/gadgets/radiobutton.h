#ifndef GADGETS_RADIOBUTTON_H
#define GADGETS_RADIOBUTTON_H
/*
**    $VER: radiobutton.h 54.16 (22.08.2022)
**
**    Definitions for the radiobutton.gadget BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#ifndef  LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* Defines for the radiobutton node attributes. */
#define RBNA_Dummy    (TAG_USER+0x020000)

#define RBNA_UserData (RBNA_Dummy+1)
    /* (APTR) User Data. */

#define RBNA_Label   (RBNA_Dummy+2)
    /* (STRPTR) Text string for this MX button. */

#define RBNA_HintInfo (RBNA_Dummy+3)
    /* (STRPTR) Text string for the hint info for this MX button */

#define RBNA_Disabled (RBNA_Dummy+4)
	/* (BOOL) If TRUE, renders this MX button in disabled state */

/*****************************************************************************/

/* Additional attributes defined by the RadioButton class */
#define RADIOBUTTON_Dummy      (REACTION_Dummy + 0x14000)

#define RADIOBUTTON_Labels     (RADIOBUTTON_Dummy+1)
    /* (struct List *) Radio Button Label List. */

#define RADIOBUTTON_Strings    (RADIOBUTTON_Dummy+2)
    /* RESERVED - presently unsupported */

#define RADIOBUTTON_Spacing    (RADIOBUTTON_Dummy+3)
    /* (WORD) Spacing between radio buttons */

#define RADIOBUTTON_Selected   (RADIOBUTTON_Dummy+4)
    /* (WORD) selected radio button (OM_GET/OM_SET/OM_NOTIFY) */

#define RADIOBUTTON_LabelPlace (RADIOBUTTON_Dummy+5)
    /* (WORD) label location (OM_GET/OM_SET) */
    
#define RADIOBUTTON_LabelArray (RADIOBUTTON_Dummy+6)
    /* (STRPTR *) Radio Button Labels */

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* GADGETS_RADIOBUTTON_H */
