;/* This Example Shows ReAction's bitmap.image
gcc -o BitMapExample2 BitMapExample2.c
quit
*/


/*
**
** Standard includes
**
*/

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>

#include <classes/window.h>
#include <gadgets/button.h>
#include <gadgets/layout.h>
#include <images/bitmap.h>

/*
**
** Defines
**
*/

#define End TAG_END)

enum
{
	GADID_Root,
	GADID_Button,
	GADID_Last
};

/*
**
** Proto types
**
*/

int main( int argc, STRPTR argv[] );

/*
**
** Global values
**
*/

struct Library *		IntuitionBase;
struct IntuitionIFace *	IIntuition;

struct ClassLibrary *	BitMapBase;
Class *					BitMapClass;

struct ClassLibrary *	ButtonBase;
Class *					ButtonClass;

struct ClassLibrary *	LayoutBase;
Class *					LayoutClass;

struct ClassLibrary *	WindowBase;
Class *					WindowClass;

struct Screen *			ScreenAdr;

struct Window *			MainWindow;
uint32					MainWindowBits;
Object *				MainWinObject;

Object *                GUIObjects[ GADID_Last ];

Object *				BMImage1;
Object *				BMImage2;

struct BitMap *			BitMapAdr;

/*
**
** Main Function
**
*/

int main( int argc, STRPTR argv[] )
{
uint32 result;
uint32 flags;
uint16 code;
BOOL running;

	BitMapBase		= NULL;
	BitMapClass		= NULL;
	ButtonBase		= NULL;
	ButtonClass		= NULL;
	IntuitionBase	= NULL;
	IIntuition		= NULL;
	LayoutBase		= NULL;
	LayoutClass		= NULL;
	WindowBase		= NULL;
	WindowClass		= NULL;
	ScreenAdr		= NULL;
	BMImage1		= NULL;
	BMImage2		= NULL;

	// Open Resources

	IntuitionBase = IExec->OpenLibrary( "intuition.library", 53 );
	IIntuition = (struct IntuitionIFace *)IExec->GetInterface( IntuitionBase, "main", 1, NULL );

	if ( IIntuition == NULL )
	{
		goto bailout;
	}

	BitMapBase = IIntuition->OpenClass( "images/bitmap.image", 53, &BitMapClass );

	if ( BitMapBase == NULL )
	{
		goto bailout;
	}

	ButtonBase = IIntuition->OpenClass( "gadgets/button.gadget", 53, &ButtonClass );

	if ( ButtonBase == NULL )
	{
		goto bailout;
	}

	LayoutBase = IIntuition->OpenClass( "gadgets/layout.gadget", 53, &LayoutClass );

	if ( LayoutBase == NULL )
	{
		goto bailout;
	}

	WindowBase = IIntuition->OpenClass( "window.class", 53, &WindowClass );

	if ( WindowBase == NULL )
	{
		goto bailout;
	}

	ScreenAdr = IIntuition->LockPubScreen( NULL );

	if ( ScreenAdr == NULL )
	{
		goto bailout;
	}

	/*
	 * Make an image out of an IFF file.
	 * The image will be included in the window layout, and is
	 * used to clip two other images from
	 */

	BMImage1 = IIntuition->NewObject( BitMapClass, NULL,
		BITMAP_SourceFile,	"PROGDIR:buttons.iff",
		BITMAP_OffsetX,		0,
		BITMAP_OffsetY,		0,
		BITMAP_Width,		577,
		BITMAP_Height,		30,
		BITMAP_Screen,		ScreenAdr,
	End;

	if ( BMImage1 == NULL )
	{
		goto bailout;
	}

	/* Get the bitmap of the image */

	IIntuition->GetAttrs( BMImage1,
		BITMAP_BitMap, &BitMapAdr,
		TAG_END
	);

	// Create Window

	MainWinObject = IIntuition->NewObject( WindowClass, NULL,
		WA_Activate,						TRUE,
		WA_CloseGadget,						TRUE,
		WA_DepthGadget,						TRUE,
		WA_DragBar,							TRUE,
		WA_IDCMP,							IDCMP_RAWKEY,
		WA_SizeGadget,						TRUE,
		WA_ScreenTitle,						"ReAction AmigaOS",
		WA_Title,							"ReAction BitMap Example",
		WINDOW_Position,					WPOS_CENTERSCREEN,
		WINDOW_Layout,						GUIObjects[ GADID_Root ] = IIntuition->NewObject( LayoutClass, NULL,
			LAYOUT_Orientation,				LAYOUT_ORIENT_VERT,
			LAYOUT_HorizAlignment,			LALIGN_CENTER,

			LAYOUT_AddImage,				BMImage1,
			CHILD_NoDispose,				TRUE,

			LAYOUT_AddChild,				GUIObjects[ GADID_Button ] = IIntuition->NewObject( ButtonClass, NULL,
				GA_ReadOnly,				TRUE,
				GA_Image,					BMImage2 = IIntuition->NewObject( BitMapClass, NULL,
					BITMAP_BitMap,			BitMapAdr,
					BITMAP_OffsetX,			0,
					BITMAP_OffsetY,			0,
					BITMAP_Width,			120,
					BITMAP_Height,			30,
					BITMAP_SelectBitMap,	BitMapAdr,
					BITMAP_SelectOffsetX,	30,
					BITMAP_SelectOffsetY,	0,
					BITMAP_SelectWidth,		120,
					BITMAP_SelectHeight,	30,
					BITMAP_Masking,			TRUE,
				End,
			End,
			CHILD_WeightedWidth,			0,
			CHILD_WeightedHeight,			0,

		End,
	End;

	if ( MainWinObject == NULL )
	{
		goto bailout;
	}

	// Open Window

	MainWindow = (struct Window *)IIntuition->IDoMethod( MainWinObject, WM_OPEN );

	if ( MainWindow	== NULL )
	{
		goto bailout;
	}

	IIntuition->GetAttrs( MainWinObject,
		WINDOW_SigMask,	&MainWindowBits,
		TAG_END
	);

	// Main loop wait for events

	running = TRUE;

	while( running == TRUE )
	{
		flags = IExec->Wait( MainWindowBits | SIGBREAKF_CTRL_C );

		if ( flags & SIGBREAKF_CTRL_C )
		{
			running = FALSE;
			break;
		}

		if ( flags & MainWindowBits )
		{
			while(( result = IIntuition->IDoMethod( MainWinObject, WM_HANDLEINPUT, &code )) != WMHI_LASTMSG )
			{
				switch( result & WMHI_CLASSMASK )
				{
					case WMHI_CLOSEWINDOW:
					{
						running = FALSE;
						break;
					}

					case WMHI_RAWKEY:
					{
						switch( code )
						{
							case 0x45: // Esc
							{
								running = FALSE;
								break;
							}

							default:
							{
								break;
							}
						}
						break;
					}

					default:
					{
						break;
					}
				}
			}
		}
	}

bailout:

	// Dispose resources

	if ( MainWinObject )
	{
		IIntuition->DisposeObject( MainWinObject );
	}

	/*
	 * Dispose the images ourselves as button.gadget doesn't
	 * do this for its GA_Image...
	 */
	IIntuition->DisposeObject( BMImage2 );
	IIntuition->DisposeObject( BMImage1 );

	IIntuition->UnlockPubScreen( NULL, ScreenAdr );

	IIntuition->CloseClass( WindowBase );
	IIntuition->CloseClass( LayoutBase );
	IIntuition->CloseClass( ButtonBase );
	IIntuition->CloseClass( BitMapBase );

	IExec->DropInterface( (struct Interface *)IIntuition );
	IExec->CloseLibrary( IntuitionBase );

	return( 0 );
}
