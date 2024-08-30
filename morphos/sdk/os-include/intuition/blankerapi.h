#ifndef INTUITION_BLANKERAPI_H
#define INTUITION_BLANKERAPI_H

/*
	intuition blanker api definitions

	Copyright © 2003-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#define BTDPT_BOOLEAN 1
#define BTDPT_INTEGER 2
#define BTDPT_CYCLE   3
#define BTDPT_FILE    4
#define BTDPT_STRING  5
#define BTDPT_FONT    6
#define BTDPT_COLOR   7

#define BTDMAXSTRLEN  128

struct BTDNode                /* this is the generic head for param structure */
{
	Tag              BN_Tag;  /* ID tag for parameter */
	char            *BN_Name; /* parameter name */
	ULONG            BN_Type;
};

struct BTDBoolean             /* struct for boolean parameters */
{
	struct BTDNode   BB_Node;
	LONG             BB_Value; /* boolean value */
};

struct BTDInteger               /* structure for integer params */
{
	struct BTDNode   BI_Node;
	LONG             BI_Value;  /* actual value */
	LONG             BI_Min;    /* minimum value */
	LONG             BI_Max;    /* maximum value */
	LONG             BI_Slider; /* set to TRUE to get a slider */
	STRPTR           BI_Format; /* optional format template, e.g. "%ld %%" */
	struct Hook     *BI_Hook;   /* optional 'Stringify' Hook */
};

/*
**	The 'Stringify' Hook can be used in case BI_Format is not enough. A STRPTR 
**	to a buffer is passed in A2 and an ULONG * to the current slider value in A1. 
**	The hook must return a STRPTR on success or NULL. If NULL is returned 
**	then default formating is used. The available buffer size can be read from 
**	value[1], but its guranteed to be at least 512 bytes.
*/

struct BTDCycle
{
	struct BTDNode   BC_Node;
	LONG             BC_Value;  /* selected item */
	char           **BC_Labels; /* NULL terminated array with labels */
};

struct BTDString
{
	struct BTDNode   BS_Node;
	char             BS_String[BTDMAXSTRLEN];
};

struct BTDFont
{
	struct BTDNode   BF_Node;
	char             BF_Font[BTDMAXSTRLEN];
};

struct BTDFile
{
	struct BTDNode   BF_Node;
	char             BF_File[BTDMAXSTRLEN];
};

struct BTDColor
{
	struct BTDNode   BC_Node;
	ULONG            BC_Value; /* ARGB32 */
};

struct BTDInfo                       /* struct returned by QueryBlanker() */
{
	ULONG            BI_Revision;    /* put BTDI_Revision here */
	ULONG            BI_ID;          /* 4 char ID for your blanker */
	char            *BI_Name;        /* blanker name */
	char            *BI_Description; /* blanker description */
	char            *BI_Author;      /* blanker author(s) */
	ULONG            BI_Flags;       /* blanker requirements */
	struct BTDNode **BI_Params;      /* NULL terminated array with params */
};

#define BTDI_Revision  7L            /* you must ALWAYS use this symbol! */

#define BTDIF_3DBlanker    (1L << 0) /* set this if your blanker needs a screen format supported by 3d drivers */
#define BTDIF_Fast3D       (1L << 1) /* set this if your blanker needs 3d hw accelerated driver */
#define BTDIF_DoNotWait    (1L << 2) /* set this if your blanker will control fps on it's own (by calling WaitBOVP, etc) */

/*
**	NOTE: intuition will always try to pick the best screen mode for your blanker depending on requirements,
**	that doesn't mean you will always get a 3d supported screen, in that case your blanker must return
**	BTDERR_Display error code
**
**	Double/Triple Buffering
**
**	In case you want double or triple buffered display, please ensure that BDI_Screen is set and
**	use standard intuition screen buffering routines as described in AllocScreenBuffer.
**	Be sure to free all screen buffers in your ExitBlanker implementation.
*/

struct BTDDrawInfo
{
	struct RastPort   *BDI_RPort;    /* RastPort with or without layer, the bitmap will never be a CLUT one! */
	struct Screen     *BDI_Screen;   /* In case your renderer needs to know the gfx card, call WaitBOVP. might be NULL! */

	LONG               BDI_Left;     /* position and dimmensions of your draw area */
	LONG               BDI_Top;      /* NOTE: starting with BTDI_Revision 7 this will always be 0,0,screenw,screenh */
	LONG               BDI_Width;
	LONG               BDI_Height;
};

#define BTDERR_Size    1L            /* BTD_Error code: allocated draw space too small */
#define BTDERR_Memory  2L            /* BTD_Error code: not enough memory */
#define BTDERR_Display 3L            /* BTD_Error code: unsupported display mode */

#define BTD_Dummy       (TAG_USER + 'B'*65536L + 'T'*256 + 'D')
#define BTD_DrawInfo    (BTD_Dummy + 1)
#define BTD_Error       (BTD_Dummy + 2)
#define BTD_PreviewMode (BTD_Dummy + 4) /* TRUE if ran from Blanker.mprefs */

#define BTD_Client      (BTD_Dummy + 100)

#endif /* INTUITION_BLANKERAPI_H */
