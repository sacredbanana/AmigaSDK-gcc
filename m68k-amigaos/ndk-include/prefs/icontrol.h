#ifndef PREFS_ICONTROL_H
#define PREFS_ICONTROL_H
/*
**	$VER: icontrol.h 47.3 (30.8.2021)
**
**	File format for intuition control preferences
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif


/*****************************************************************************/


#define ID_ICTL MAKE_ID('I','C','T','L')


struct IControlPrefs
{
    LONG  ic_Reserved[4];	/* System reserved		*/
    UWORD ic_TimeOut;		/* Verify timeout		*/
    WORD  ic_MetaDrag;		/* Meta drag mouse event	*/
    ULONG ic_Flags;		/* IControl flags (see below)	*/
    UBYTE ic_WBtoFront;		/* CKey: WB to front		*/
    UBYTE ic_FrontToBack;	/* CKey: front screen to back	*/
    UBYTE ic_ReqTrue;		/* CKey: Requester TRUE		*/
    UBYTE ic_ReqFalse;		/* CKey: Requester FALSE	*/

    /* Below is valid if Flags ICB_VERSIONED is set and onward if right version */
#define IC_CURRENTVERSION 2
    UWORD ic_Version;		/* Version of this struct	*/
    UWORD ic_VersionMagic;	/* must be NULL			*/
    UBYTE ic_HoverSlugishness : 3; /* version 2 onward, number of intuiticks to wait when moving fast */
    UBYTE ic_HoverFlags : 5 ;	/* version 2 onward, see below	*/
    UBYTE ic_Pad;
    UBYTE ic_GUIGeometry[4];	/* Titlebar and border geometry	*/
};

/* flags for IControlPrefs.ic_Flags */
#define ICB_COERCE_COLORS    0
#define ICB_COERCE_LACE      1
#define ICB_STRGAD_FILTER    2
#define ICB_MENUSNAP	     3
#define ICB_MODEPROMOTE      4
#define ICB_CORRECT_RATIO    5
/* bits 6..14 are used by OS4 */
#define ICB_OFFSCRNWIN      15
#define ICB_MORESIZEGADGETS 16
#define ICB_RATIO_LSB       17
#define ICB_RATIO_MSB       18
#define ICB_VERSIONED       31

#define ICF_COERCE_COLORS   (1<<ICB_COERCE_COLORS)
#define ICF_COERCE_LACE     (1<<ICB_COERCE_LACE)
#define ICF_STRGAD_FILTER   (1<<ICB_STRGAD_FILTER)
#define ICF_MENUSNAP	    (1<<ICB_MENUSNAP)
#define ICF_MODEPROMOTE     (1<<ICB_MODEPROMOTE)
#define ICF_CORRECT_RATIO   (1<<ICB_CORRECT_RATIO)
/* bits 6..14 are used by OS4 */
#define ICF_OFFSCRNWIN      (1<<ICB_OFFSCRNWIN)
#define ICF_MORESIZEGADGETS (1<<ICB_MORESIZEGADGETS)
#define ICF_RATIO_MASK      (3<<ICB_RATIO_LSB)
#define ICF_RATIO_9_7       (0<<ICB_RATIO_LSB)
#define ICF_RATIO_9_8       (1<<ICB_RATIO_LSB)
#define ICF_RATIO_1_1       (2<<ICB_RATIO_LSB)
#define ICF_RATIO_8_9       (3<<ICB_RATIO_LSB)
#define ICF_VERSIONED       (1<<ICB_VERSIONED)

#define ICF_HF_HOVERGADGETS  (1<<0)
#define ICF_HF_REFLECTHOVER  (1<<1)


#define ID_IEXC MAKE_ID('I','E','X','C')


struct IExceptionPrefs
{
    struct TagItem ie_Tags[0];	/* Relocatable tag list including TAG_END, 0 */
};

/*****************************************************************************/


#endif /* PREFS_ICONTROL_H */
