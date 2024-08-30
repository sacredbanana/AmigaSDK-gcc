
/*
** simple blanker example
*/

#define	VERSION	 1
#define	REVISION 0

#define BLANKERLIBNAME  "simple.btd"
#define BLANKERNAME     "Simple"
#define AUTHORNAME      "Guido Mersmann, Michal Wozniak"
#define DESCRIPTION     "This is a simple blanker example"
#define BLANKERID       MAKE_ID('S','I','M','P')

/***************************************************************************/

#include <cybergraphx/cybergraphics.h>
#include <dos/dos.h>
#include <libraries/iffparse.h>
#include <libraries/query.h>
#include <utility/hooks.h>
#include <utility/tagitem.h>
#include <intuition/blankerapi.h>
#include <graphics/rpattr.h>
#include <intuition/intuitionbase.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/timer.h>
#include <proto/diskfont.h>
#include <proto/graphics.h>
#include <proto/utility.h>
#include <proto/cybergraphics.h>

#include <strings.h>

/***************************************************************************/

/*
** macros used later
*/

#define I2S(x) I2S2(x)
#define I2S2(x) #x

/*
** gui defaults
*/

#define DEF_SCREENCOLORBG 0xff3088a0

#define DEF_FONT          "Bitstream Vera Sans"
#define DEF_FONTSTYLE     "b"
#define DEF_FONTSIZE      100
#define DEF_FONTNAME      DEF_FONT "/" I2S(DEF_FONTSIZE) "/" DEF_FONTSTYLE
#define DEF_FONTCOLORFG    0xffffffff
#define DEF_FONTCOLORBG    0xff000000

/* in preview mode we need a smaller font or it looks messy */
#define PREVIEW_FONTSIZE 15 /* in %, settings font size is 100% */

/***************************************************************************/

/* /// Blanker data stuff
**
*/

/***************************************************************************/

/*
** blanker settings window definition
*/

#define nTAG(o)             (BTD_Client + (o))
#define MYTAG_SCREENCOLORBG    nTAG(0)
#define MYTAG_FONTNAME         nTAG(1)
#define MYTAG_FONTCOLORFG      nTAG(2)
#define MYTAG_FONTCOLORBG      nTAG(3)

/***************************************************************************/

static struct BTDColor   OBJ_ScreenColorBG = {{ MYTAG_SCREENCOLORBG, "Screen Background:", BTDPT_COLOR    }, DEF_SCREENCOLORBG };
static struct BTDFont    OBJ_FontName      = {{ MYTAG_FONTNAME     , "Font:"             , BTDPT_FONT     }, DEF_FONTNAME };
static struct BTDColor   OBJ_FontColorFG   = {{ MYTAG_FONTCOLORFG  , "Foreground:"       , BTDPT_COLOR    }, DEF_FONTCOLORFG };
static struct BTDColor   OBJ_FontColorBG   = {{ MYTAG_FONTCOLORBG  , "Background:"       , BTDPT_COLOR    }, DEF_FONTCOLORBG };


struct BTDNode *BlankerGUI[] =
{
	(APTR) &OBJ_ScreenColorBG,
	(APTR) &OBJ_FontName,
	(APTR) &OBJ_FontColorFG,
	(APTR) &OBJ_FontColorBG,
	NULL,
};

/*
** compose strings for multiple usage
*/

UBYTE BlankerVersionID[]   = "$VER: " BLANKERLIBNAME " " I2S(VERSION) "." I2S(REVISION) " (" __AMIGADATE__ ") © " __COPYRIGHTYEAR__ " " AUTHORNAME;
UBYTE BlankerLibName[]     = BLANKERLIBNAME;
UBYTE BlankerName[]        = BLANKERNAME;
UBYTE BlankerAuthor[]      = AUTHORNAME;
UBYTE BlankerDescription[] = DESCRIPTION;

/*
** blanker info struct
*/

struct BTDInfo BlankerInfo =
{
	BTDI_Revision,                 /* API version */
	BLANKERID,                     /* ID for prefs window snapshot */
	BlankerName,                   /* blanker name */
	BlankerDescription,            /* description */
	BlankerAuthor,                 /* author(s) */
	BTDIF_DoNotWait,               /* flags */
	BlankerGUI,                    /* config options */
};

/***************************************************************************/

/*
** lib query tag information
*/

struct TagItem MyBlankerQueryTags[] =
{
	{ QUERYINFOATTR_NAME,        (ULONG) BlankerName },
	{ QUERYINFOATTR_DESCRIPTION, (ULONG) BlankerDescription },
	{ QUERYINFOATTR_AUTHOR,      (ULONG) BlankerAuthor },
	{ QUERYINFOATTR_VERSION,     (ULONG)VERSION},
	{ QUERYINFOATTR_REVISION,    (ULONG)REVISION},
	{ TAG_DONE,0}
};

/***************************************************************************/

/*
** blanker data structure
*/

struct BlankerData
{
/* timer device data */

	struct Library     *bd_timerbase;
	struct timerequest  bd_TimerRequest;

/*  BTDDrawInfo */

	struct Screen      *bd_Screen;
	struct ViewPort    *bd_ViewPort;
	struct RastPort    *bd_RastPort;
	LONG                bd_Width;
	LONG                bd_Height;
	LONG                bd_Left;
	LONG                bd_Top;
	IPTR                bd_PreviewMode;

/* settings */
	IPTR                bd_Settings_ScreenColorBG;
	IPTR                bd_Settings_FontColorFG;
	IPTR                bd_Settings_FontColorBG;

	char                bd_FontName[ BTDMAXSTRLEN + 10 ];
	IPTR                bd_FontSize;
	IPTR                bd_FontStyle;
	struct TextFont    *bd_Font;
/* runtime data */
	IPTR                bd_StopRendering;
};

#define TimerBase    bd->bd_timerbase

/***************************************************************************/

/*
** global stuff
*/

struct Library         *CyberGfxBase;
struct Library         *DiskfontBase;
struct GfxBase         *GfxBase;
struct IntuitionBase   *IntuitionBase;
struct Library         *UtilityBase;
struct DosLibrary      *DOSBase;

/* \\\ */

/* /// BlankerLibFree()
**
*/

/***************************************************************************/

void BlankerLibFree( void )
{
	if( CyberGfxBase ) {
		CloseLibrary( CyberGfxBase );
		CyberGfxBase = NULL;
	}
	if( DiskfontBase ) {
		CloseLibrary( DiskfontBase );
		DiskfontBase = NULL;
	}
	if( UtilityBase ) {
		CloseLibrary( UtilityBase );
		UtilityBase	= NULL;
	}
	if( IntuitionBase ) {
		CloseLibrary( (APTR) IntuitionBase );
		IntuitionBase = NULL;
	}
	if( GfxBase ) {
		CloseLibrary( (APTR) GfxBase );
		GfxBase	= NULL;
	}
	if( DOSBase ) {
		CloseLibrary( (APTR) DOSBase );
		DOSBase	= NULL;
	}
}
/* \\\ */
/* /// BlankerLibInit()
**
*/

/***************************************************************************/

ULONG BlankerLibInit( void )
{
	CyberGfxBase  =        OpenLibrary("cybergraphics.library", 0 );
	DiskfontBase  =        OpenLibrary("diskfont.library"     , 0 );
	UtilityBase   =        OpenLibrary("utility.library"      , 0 );
	IntuitionBase = (APTR) OpenLibrary("intuition.library"    , 0 );
	GfxBase       = (APTR) OpenLibrary("graphics.library"     , 0 );
	DOSBase       = (APTR) OpenLibrary("dos.library"          , 0 );

	if( CyberGfxBase && DiskfontBase && UtilityBase && IntuitionBase && GfxBase && DOSBase ) {
		return( 1 );
	} else {
		BlankerLibFree();
		return( 0 );
	}
}
/* \\\ */
/* /// QueryMyBlanker()
**
*/

/***************************************************************************/

struct BTDInfo *QueryMyBlanker( void )
{

	return( &BlankerInfo );
}

/* \\\ */

/* /// EndMyBlanker()
**
*/

/***************************************************************************/

void EndMyBlanker( struct BlankerData *bd )
{
	if( bd ) {

/* close timer first */

		if( bd->bd_timerbase ) {
			CloseDevice( (struct IORequest *) &bd->bd_TimerRequest );
		}

/* delete message port */

		if( bd->bd_TimerRequest.tr_node.io_Message.mn_ReplyPort ) {
			DeleteMsgPort( bd->bd_TimerRequest.tr_node.io_Message.mn_ReplyPort );
		}

/* if we succeeded opening a font, we need to close it */

		if( bd->bd_Font ) {
			CloseFont( bd->bd_Font );
		}

/* now we free our base structure */

		FreeVec( bd );
	}
}
/* \\\ */
/* /// InitMyBlanker()
**
*/


/***************************************************************************/

struct BlankerData *InitMyBlanker( struct TagItem *TagList )
{
struct BlankerData *bd           = NULL;
struct BTDDrawInfo *BTDDrawInfo  = (struct BTDDrawInfo *) GetTagData( BTD_DrawInfo, 0, TagList );
ULONG              dummy, *error = (ULONG *)              GetTagData( BTD_Error, (ULONG) &dummy, TagList );

	/* make sure we did not get bogus data */

	if( !( BTDDrawInfo && error ) ) {
		return( NULL );
	}

	if( ( BTDDrawInfo->BDI_Width < 40 ) || ( BTDDrawInfo->BDI_Height < 30 ) ) {
		*error = BTDERR_Size;
		return( NULL );
	}

	/* if something goes wrong, it is probably low memory */

	*error = BTDERR_Memory;

	/* we allocate our basic blanker structure */

	if( (bd = AllocVec( sizeof( struct BlankerData ), MEMF_PUBLIC|MEMF_CLEAR) ) ) {

		/* setup timer io request */

		bd->bd_TimerRequest.tr_node.io_Message.mn_Node.ln_Type = NT_REPLYMSG;
		bd->bd_TimerRequest.tr_node.io_Message.mn_ReplyPort    = CreateMsgPort();
		bd->bd_TimerRequest.tr_node.io_Message.mn_Length       = sizeof( bd->bd_TimerRequest );
		bd->bd_TimerRequest.tr_node.io_Flags                   = IOF_QUICK;

		if( !OpenDevice( "timer.device", UNIT_MICROHZ, (struct IORequest *) &bd->bd_TimerRequest, 0 ) ) {
			bd->bd_timerbase = (struct Library *) bd->bd_TimerRequest.tr_node.io_Device;

			/* copy draw info values for easy and quick usage during rendering */

			bd->bd_Screen   = BTDDrawInfo->BDI_Screen;
			bd->bd_ViewPort = BTDDrawInfo->BDI_Screen ? &BTDDrawInfo->BDI_Screen->ViewPort : NULL;
			bd->bd_RastPort = BTDDrawInfo->BDI_RPort;
			bd->bd_Width    = BTDDrawInfo->BDI_Width;
			bd->bd_Height   = BTDDrawInfo->BDI_Height;
			bd->bd_Left     = BTDDrawInfo->BDI_Left;
			bd->bd_Top      = BTDDrawInfo->BDI_Top;

			/* if we later need to know if preview mode is enabled,
			** we can simply check bd_PreviewMode
			*/

			bd->bd_PreviewMode = GetTagData( BTD_PreviewMode, FALSE, TagList );

/* Now we obtain resources needed by our blanker
**
** This is the actual example code you can kill or modify at will.
*/

/* first we obtain and cache some of our settings for later usage
**
** the settings gui is defined in an array above
*/

			bd->bd_Settings_ScreenColorBG = GetTagData( MYTAG_SCREENCOLORBG, (ULONG) DEF_SCREENCOLORBG, TagList );
			bd->bd_Settings_FontColorFG   = GetTagData( MYTAG_FONTCOLORFG, (ULONG) DEF_FONTCOLORFG, TagList );
			bd->bd_Settings_FontColorBG   = GetTagData( MYTAG_FONTCOLORBG, (ULONG) DEF_FONTCOLORBG, TagList );

/*
** same for the mui font name, but it needs some more work
** as it contains style flags and size.
**
** we convert the mui font name provided by settings into
** something usable and store it in our blanker data structure.
** not needed, but could be handy and just eats a few bytes
** which already are allocated. So who cares.
*/

			{ STRPTR fontname, tmp;
				fontname = (char*) GetTagData( MYTAG_FONTNAME, (IPTR) DEF_FONTNAME, TagList );
				if( fontname && fontname[0] ) {
					strcpy( bd->bd_FontName, fontname );
					if( ( tmp = strchr( fontname,'/') ) ) {
						IPTR length = (IPTR) tmp - (IPTR) fontname;

						stccpy( bd->bd_FontName, fontname, length + 1 );
						strcpy( bd->bd_FontName + length,".font" );

						StrToLong( tmp + 1, &bd->bd_FontSize );
					}

					if( strstr( tmp, "/b" ) ) bd->bd_FontStyle |= FSF_BOLD;
					if( strstr( tmp, "/u" ) ) bd->bd_FontStyle |= FSF_UNDERLINED;
					if( strstr( tmp, "/i" ) ) bd->bd_FontStyle |= FSF_ITALIC;
				}

				/* fallback to our default font */
				if( !bd->bd_FontSize ) {
					strcpy( bd->bd_FontName, DEF_FONT );
					bd->bd_FontSize  = DEF_FONTSIZE;
					bd->bd_FontStyle = FSF_BOLD;

				}
				if( bd->bd_PreviewMode ) { /* remember preview mode? smaller font size comes handy */
					bd->bd_FontSize = bd->bd_FontSize * PREVIEW_FONTSIZE / 100;
				}
			}

/* now we open the font */

			{
				struct TextAttr ta;

				ta.ta_Name  = bd->bd_FontName;
				ta.ta_YSize = bd->bd_FontSize;
				ta.ta_Style = bd->bd_FontStyle;
				ta.ta_Flags = 0;

				bd->bd_Font = OpenDiskFont( &ta );
				/* we deal with the success of this during rendering.
				** This blanker deals the font as optional
				*/
			}

/* clear screen with our background, or we may get trash on screen
**
** we use the color we obtained from settings above
*/

			FillPixelArray(
						bd->bd_RastPort, bd->bd_Left, bd->bd_Top,
						bd->bd_Width, bd->bd_Height,
						bd->bd_Settings_ScreenColorBG );

			/* if we get till here, we are done and succeeded and
			** return our blanker data
			*/
			return( bd );
		}
	}
	/* something went wrong. Call shut down to release all data we may have
	** already gathered during init process
	*/
	EndMyBlanker( bd );

	/* we failed */

	return( NULL );
}
/* \\\ */
/* /// AnimMyBlanker()
**
*/

/***************************************************************************/

void AnimMyBlanker( struct BlankerData *bd )
{

/* set at least a minimum wait time to lower cpu usage
**
** we just render a static screen, so even the once a second default
** is overkill, but it is just a simple example to play with.
*/

#define EFFECT_SIZE 2  /* outline color frame size */


	bd->bd_TimerRequest.tr_time.tv_micro = 0;
	bd->bd_TimerRequest.tr_time.tv_secs  = 1;
	bd->bd_TimerRequest.tr_node.io_Command = TR_ADDREQUEST;

	DoIO( (struct IORequest *) &bd->bd_TimerRequest );

	/* do stuff here, we get called once a second */

	if( bd->bd_Font && !bd->bd_StopRendering ) { /* we may not have a font to work with */
		struct RastPort  *rp = bd->bd_RastPort;
		struct TextFont  *tf = bd->bd_Font;
		IPTR x, y, pixellength;
		STRPTR text = "Simple Blanker";  /* text we render on screen */
		IPTR length = strlen( text );    /* char length of the text to render */

		/* this is a static text blanker, so just do it once */
		bd->bd_StopRendering++;

		/* for frequently text rendering you should render into an offscreen bitmap
		** and just blit the result over.
		** Doing it this simple causes massive flickering.
		*/

		FillPixelArray(
						bd->bd_RastPort, bd->bd_Left, bd->bd_Top,
						bd->bd_Width, bd->bd_Height,
						bd->bd_Settings_ScreenColorBG );

		/* set font, color and drawmode */

		SetRPAttrs( rp, RPTAG_Font, tf,
					RPTAG_PenMode, FALSE,
					RPTAG_FgColor, bd->bd_Settings_FontColorBG,
					RPTAG_DrMd, JAM1,
					TAG_DONE );

		/* set soft style */

		SetSoftStyle( rp, bd->bd_FontStyle, -1 );

		/* we need to know the width of our text */

		pixellength	= TextLength( rp, text, length );

		/* center our text */
		x = ( bd->bd_Width  - pixellength ) / 2;
		y = ( bd->bd_Height - tf->tf_YSize ) / 2;

		/* take our effect into account */
		y = y + EFFECT_SIZE + tf->tf_Baseline;
		x = x + EFFECT_SIZE;

		/* now we render the text shadow */

		Move( rp, x, y - EFFECT_SIZE );
		Text( rp, text, length );
		Move( rp, x - EFFECT_SIZE, y );
		Text( rp, text, length );
		Move( rp, x + EFFECT_SIZE, y );
		Text( rp, text, length );
		Move( rp, x    , y + EFFECT_SIZE );
		Text( rp, text, length );

		/* add some blur */

		ProcessPixelArray( rp, x - EFFECT_SIZE, y - tf->tf_Baseline - EFFECT_SIZE, pixellength + EFFECT_SIZE * 4, tf->tf_YSize + EFFECT_SIZE * 2, POP_BLUR, 128, NULL );

		/* now we render the real text ontop of that */

		SetRPAttrs(	rp, RPTAG_PenMode, FALSE,
					RPTAG_FgColor, bd->bd_Settings_FontColorFG,
					RPTAG_DrMd, JAM1,
					TAG_DONE );

		Move( rp, x, y );
		Text( rp, text, length );

	}
}
/* \\\ */

