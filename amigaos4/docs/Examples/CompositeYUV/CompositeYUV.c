/** Test program for rendering YUV
 *
 * This program will open a window, and render a 2D gradient in YUV format to
 * it using CompositeTags().
 *
 * Copyright (C) 2014 by Hans de Ruiter, all rights reserved.
 *
 * NOTE: This uses code from overlay_test, which is Copyright (C) Richard
 * Drummond 2005-2006.
 */

#include <stdio.h>
#include <string.h>

#include <graphics/composite.h>
#include <intuition/intuition.h>
#include <libraries/Picasso96.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/layers.h>
#include <proto/Picasso96API.h>
#include <proto/utility.h>


// The width of the source bitmap NOTE: Make sure that it's a multiple of 4
#define SOURCE_WIDTH 256

// The width of the source bitmap NOTE: Make sure that it's a multiple of 4
#define SOURCE_HEIGHT 256

// The initial window dimensions
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

// Window size limits
#define WINDOW_MINWIDTH 100
#define WINDOW_MINHEIGHT 100
#define WINDOW_MAXWIDTH 2048
#define WINDOW_MAXHEIGHT 2048

// Buffer size for window title
#define TITLESTR_LEN 512

// Maps YUV pixel format names to pixel format types
typedef struct PixelFormatMapping_s {
	const char *pixelFormatName;
	PIX_FMT pixelFormat;
} PixelFormatMapping;

PixelFormatMapping yuvPixelFormatMappings[] = {
    	{"YUV420p", PIXF_YUV420P},
    	{"YUV410p", PIXF_YUV410P},
    	{"YUV422", PIXF_YUV422CGX},
    	{"YUV422PC", PIXF_YUV422CGX}
    };

unsigned int numYUVPixelFormatMappings =
	sizeof(yuvPixelFormatMappings) / sizeof(PixelFormatMapping);

// A YUV colour value
typedef struct YUV_s {
	int y;
	int u;
	int v;
} YUV_t;

// An RGB colour value
typedef struct RGB_s {
	uint8 r;
	uint8 g;
	uint8 b;
} RGB_t;

// Convert an RGB colour value to a YUV colour value.
static void RGBtoYUV (RGB_t rgb, YUV_t *yuv)
{
    yuv->y = 0.299 * rgb.r + 0.587 * rgb.g + 0.114 * rgb.b;
    yuv->u = (rgb.b - yuv->y) * 0.565 + 128;
    yuv->v = (rgb.r - yuv->y) * 0.713 + 128;
}

/** Render a 256x256 2D-gradient to a YUV Bitmap
 *
 * @param bitMap
 */
static void renderYUVGradient(struct BitMap *bitMap)
{
	PIX_FMT pixelFormat = IGraphics->GetBitMapAttr(bitMap, BMA_PIXELFORMAT);

	/* Just like any other bitmap in video memory, we need to lock
	 * an overlay bitmap.
	 */
	APTR memory;
	uint32 bytesPerRow;
	struct PlanarYUVInfo yuvInfo;

	APTR lock = IGraphics->LockBitMapTags(bitMap,
		LBM_BaseAddress, &memory,
		LBM_BytesPerRow, &bytesPerRow,
		LBM_PlanarYUVInfo, &yuvInfo,
		TAG_END);

	if (lock != NULL)
	{
		/* Get a pointer to the overlay bitmap's pixels.
		 *
		 * This is a uint32 pointer since we deal with 4-byte
		 * macro-pixels.
		 */
		volatile uint32 *pixels = memory;

		if (pixels)
		{
			if(pixelFormat == PIXF_YUV410P)
			{
				int x,y;

				volatile uint8 *pip_y = yuvInfo.YMemory;
				volatile uint8 *pip_u = yuvInfo.UMemory;
				volatile uint8 *pip_v = yuvInfo.VMemory;

				for (y = 0; y < SOURCE_HEIGHT; y++)
				{
					for (x = 0; x < SOURCE_WIDTH; x++)
					{
						/* Construct RGB value for this macro-pixel */
						RGB_t rgb = {
							.r = x,
							.g = 0,
							.b = y
						};

						YUV_t yuv;

						/* Convert RGB colour value to YUV. */
						RGBtoYUV (rgb, &yuv);

						/* Copy macro-pixel to overlay bitmap */
						*pip_y++ = yuv.y;
					}
					pip_y += yuvInfo.YBytesPerRow - SOURCE_WIDTH;
				}

				for (y = 0; y < SOURCE_HEIGHT; y+=4)
				{
					for(x = 0; x < SOURCE_WIDTH; x+=4)
					{
						RGB_t rgb = {
							.r = x,
							.g = 0,
							.b = y
						};

						YUV_t yuv;

						/* Convert RGB colour value to YUV. */
						RGBtoYUV (rgb, &yuv);

						*pip_u++ = yuv.u;
						*pip_v++ = yuv.v;
					}

					pip_u += yuvInfo.UBytesPerRow - SOURCE_WIDTH / 4;
					pip_v += yuvInfo.VBytesPerRow - SOURCE_HEIGHT / 4;
				}
			}
			else if(pixelFormat == PIXF_YUV420P)
			{
				int x,y;

				volatile uint8 *pip_y = yuvInfo.YMemory;
				volatile uint8 *pip_u = yuvInfo.UMemory;
				volatile uint8 *pip_v = yuvInfo.VMemory;

				for (y = 0; y < SOURCE_HEIGHT; y++)
				{
					for (x = 0; x < SOURCE_WIDTH; x++)
					{
						/* Construct RGB value for this macro-pixel */
						RGB_t rgb = {
							.r = x,
							.g = 0,
							.b = y
						};

						YUV_t yuv;

						/* Convert RGB colour value to YUV. */
						RGBtoYUV (rgb, &yuv);

						/* Copy macro-pixel to overlay bitmap */
						*pip_y++ = yuv.y;
					}
					pip_y += yuvInfo.YBytesPerRow - SOURCE_WIDTH;
				}

				for (y = 0; y < SOURCE_HEIGHT; y+=2)
				{
					for(x = 0; x < SOURCE_WIDTH; x+=2)
					{
						RGB_t rgb = {
							.r = x,
							.g = 0,
							.b = y
						};

						YUV_t yuv;

						/* Convert RGB colour value to YUV. */
						RGBtoYUV (rgb, &yuv);

						*pip_u++ = yuv.u;
						*pip_v++ = yuv.v;
					}
					pip_u += yuvInfo.UBytesPerRow - SOURCE_WIDTH / 2;
					pip_v += yuvInfo.VBytesPerRow - SOURCE_HEIGHT / 2;
				}
			}
			else if(pixelFormat == PIXF_YUV422CGX)
			{
				int x, y;

				/* Now render our 2D gradient into the overlay bitmap
				 *
				 * The gradient varies in red intensity horizontally,
				 * blue intensity vertically.
				 */
				for (y = 0; y < SOURCE_HEIGHT; y++)
				{
					/* We go horizontally in 2-pixel steps, since we
					 * we output 2-pixel YUV macro-pixels */
					for (x = 0; x < SOURCE_WIDTH; x += 2)
					{
						/* Construct RGB value for this macro-pixel */
						RGB_t rgb = {
							.r = x,
							.g = 0,
							.b = y
						};

						YUV_t yuv;

						uint8 tmp[4];

						/* Convert RGB colour value to YUV. */
						RGBtoYUV (rgb, &yuv);

						/* Construct PIXF_YUV422CGX macro-pixel. */
						tmp[0] = yuv.y;
						tmp[1] = yuv.u;
						tmp[2] = yuv.y;
						tmp[3] = yuv.v;

						/* Copy macro-pixel to overlay bitmap */
						*pixels = *((uint32 *) &tmp[0]);

						pixels++;
					}
					pixels += bytesPerRow / sizeof(uint32) - SOURCE_WIDTH / 2;
				}
			}
			else if(pixelFormat == RGBFB_YUV422PC)
			{
				int x, y;

				/* Now render our 2D gradient into the overlay bitmap
				 *
				 * The gradient varies in red intensity horizontally,
				 * blue intensity vertically.
				 */
				for (y = 0; y < SOURCE_HEIGHT; y++)
				{
					/* We go horizontally in 2-pixel steps, since we
					 * we output 2-pixel YUV macro-pixels */
					for (x = 0; x < SOURCE_WIDTH; x += 2)
					{
						/* Construct RGB value for this macro-pixel */
						RGB_t rgb = {
							.r = x,
							.g = 0,
							.b = y
						};

						YUV_t yuv;

						uint8 tmp[4];

						/* Convert RGB colour value to YUV. */
						RGBtoYUV (rgb, &yuv);

						/* Construct PIXF_YUV422PC macro-pixel. */
						tmp[0] = yuv.u;
						tmp[1] = yuv.y;
						tmp[2] = yuv.v;
						tmp[3] = yuv.y;

						/* Copy macro-pixel to overlay bitmap */
						*pixels = *((uint32 *) &tmp[0]);

						pixels++;
					}
					pixels += bytesPerRow / sizeof(uint32) - SOURCE_WIDTH / 2;
				}
			}
			else
			{
				printf("ERROR: Unrecognised pixel format %u\n", pixelFormat);
			}
		}
		else
		{
			printf("ERROR: No pointer to pixel data received\n");
		}

		/* All done - unlock bitmap */
		IGraphics->UnlockBitMap(lock);
	}
}

/** Contains data needed by compositeHookFunc().
 */
typedef struct CompositeHookData_s {
	struct BitMap *srcBitMap; // The source bitmap
	int32 srcWidth, srcHeight; // The source dimensions
	int32 offsetX, offsetY; // The offsets to the destination area relative to the window's origin
	int32 scaleX, scaleY; // The scale factors
	uint32 retCode; // The return code from CompositeTags()
} CompositeHookData;

/** The hook for performing compositing to a rastport.
 *
 * Thanks to Fredrik Wikstrom (a.k.a., salass00) for the example code...
 *
 * @param rastPort pointer to the RastPort to render to
 * @param msg pointer the backfill
 */
ULONG compositeHookFunc(struct Hook *hook, struct RastPort *rastPort, struct BackFillMessage *msg) {
	CompositeHookData *hookData = (CompositeHookData*)hook->h_Data;

	hookData->retCode = IGraphics->CompositeTags(
		COMPOSITE_Src_Over_Dest, hookData->srcBitMap, rastPort->BitMap,
		COMPTAG_SrcWidth,   hookData->srcWidth,
		COMPTAG_SrcHeight,  hookData->srcHeight,
		COMPTAG_ScaleX, 	hookData->scaleX,
		COMPTAG_ScaleY, 	hookData->scaleY,
		COMPTAG_OffsetX,    msg->Bounds.MinX - (msg->OffsetX - hookData->offsetX),
		COMPTAG_OffsetY,    msg->Bounds.MinY - (msg->OffsetY - hookData->offsetY),
		COMPTAG_DestX,      msg->Bounds.MinX,
		COMPTAG_DestY,      msg->Bounds.MinY,
		COMPTAG_DestWidth,  msg->Bounds.MaxX - msg->Bounds.MinX + 1,
		COMPTAG_DestHeight, msg->Bounds.MaxY - msg->Bounds.MinY + 1,
		COMPTAG_Flags,      COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha | COMPFLAG_HardwareOnly,
		TAG_END);

	return 0;
}

/** Composites a bitmap to fill the given window (the window's interior).
 *
 * @param bitmap the bitmap
 * @param window the window to render to
 *
 * @return uint32 the compositing operation's return-code
 */
uint32 fillWindowWithBitMap(struct BitMap *bitMap, struct Window *window)
{
	// Need to composite onto the window's rastport. Since CompositeTags() only renders to bitmaps,
	// we use ILayers->DoHookClipRects().
	CompositeHookData hookData;
	struct Rectangle rect;
	struct Hook hook;

 	rect.MinX = window->BorderLeft;
 	rect.MinY = window->BorderTop;
 	rect.MaxX = window->Width - window->BorderRight - 1;
 	rect.MaxY = window->Height - window->BorderBottom - 1;
 	float destWidth = rect.MaxX - rect.MinX + 1;
 	float destHeight = rect.MaxY - rect.MinY + 1;
 	float scaleX = (destWidth + 0.5f) / SOURCE_WIDTH;
 	float scaleY = (destHeight + 0.5f) / SOURCE_HEIGHT;

	hookData.srcBitMap = bitMap;
	hookData.srcWidth = SOURCE_WIDTH;
	hookData.srcHeight = SOURCE_HEIGHT;
	hookData.offsetX = window->BorderLeft;
	hookData.offsetY = window->BorderTop;
	hookData.scaleX = COMP_FLOAT_TO_FIX(scaleX);
	hookData.scaleY = COMP_FLOAT_TO_FIX(scaleY);
	hookData.retCode = COMPERR_Success;

	hook.h_Entry = (HOOKFUNC)compositeHookFunc;
	hook.h_Data = &hookData;

	ILayers->DoHookClipRects(&hook, window->RPort, &rect);

	return hookData.retCode;
}

/** Prints details on how to use this program.
 *
 * @param progName this program's name (use argv[0])
 */
void printUsage(const char *progName)
{
    printf("Usage: %s <YUV format>\n", progName);
    printf("<YUV format> can be: YUV420p, YUV410p, YUV422, YUV422PC (default = YUV420p)\n");
}

int main (int argc, const char **argv)
{
    static char titleStr[TITLESTR_LEN];
    PixelFormatMapping *pixelFormat = &(yuvPixelFormatMappings[0]);
    BOOL compositedVideoAvailable = TRUE;

    // Print welcome text
    printf("%s\n\n", argv[0]);
    printf("Composited video test/demo (with overlay fallback).\n");

    // Parse args
    if(argc == 2)
    {
    	if(stricmp(argv[1], "?") == 0)
    	{
    		printUsage(argv[0]);
    		return 0;
    	}

        const char *pixelFormatArg = argv[1];
        unsigned int i = 0;
        for(; i < numYUVPixelFormatMappings; ++i)
        {
            if(stricmp(pixelFormatArg, yuvPixelFormatMappings[i].pixelFormatName) == 0)
            {
                pixelFormat = &(yuvPixelFormatMappings[i]);
                break;
            }
        }
        if(i == numYUVPixelFormatMappings)
        {
            printf("ERROR: %s is an invalide pixel format\n", pixelFormatArg);
            printUsage(argv[0]);
            return 10;
        }
    }
    if(argc > 2)
    {
        printUsage(argv[0]);
        return 10;
    }

    printf("Testing YUV pixel format: %s\n\n", pixelFormat->pixelFormatName);

    // Open the window
    printf("Opening the window\n");
	struct Window *window = NULL;
	snprintf(titleStr, sizeof(titleStr), "Composited video test (pixel format: %s)",
			pixelFormat->pixelFormatName);

	window = IIntuition->OpenWindowTags(NULL,
								WA_Title,				titleStr,
								WA_Activate,			TRUE,
								WA_RMBTrap,				TRUE,
								WA_DragBar,				TRUE,
								WA_DepthGadget,			TRUE,
								WA_SimpleRefresh,		TRUE,
								WA_SizeGadget,			TRUE,
								WA_CloseGadget,			TRUE,
								WA_IDCMP,				IDCMP_REFRESHWINDOW | IDCMP_NEWSIZE | IDCMP_CLOSEWINDOW,
								WA_InnerWidth,			WINDOW_WIDTH,
								WA_InnerHeight,			WINDOW_HEIGHT,
								WA_MinWidth,			WINDOW_MINWIDTH,
								WA_MinHeight,			WINDOW_MINHEIGHT,
								WA_MaxWidth,			WINDOW_MAXWIDTH,
								WA_MaxHeight,			WINDOW_MAXHEIGHT,
								WA_BackFill, 			LAYERS_NOBACKFILL,

								/* You need to specify somehow the screen that the window should appear on. */
					 			WA_PubScreenName, 		"Workbench",
								TAG_DONE);

	if(!window)
	{
		printf("ERROR: Couldn't open window\n");
		return 10;
	}

	// Create the YUV bitmap
	struct BitMap *yuvBitMap;
	yuvBitMap = IGraphics->AllocBitMapTags(SOURCE_WIDTH, SOURCE_HEIGHT, 32,
					BMATags_Displayable, TRUE,
					BMATags_PixelFormat, pixelFormat->pixelFormat,
					TAG_DONE);

	if(!yuvBitMap)
	{
		printf("ERROR: Couldn't allocate %s bitmap\n", pixelFormat->pixelFormatName);
		IIntuition->CloseWindow(window);
		window = NULL;
	}

	// Now draw the gradient into the bitmap
	renderYUVGradient(yuvBitMap);

	// Test if composited video is available
	uint32 errCode = fillWindowWithBitMap(yuvBitMap, window);
	if(errCode)
	{
		// Composited video isn't available
		const char *compositeErrorStr;
		switch(errCode)
		{
		case COMPERR_Success:
			compositeErrorStr = "success";
			break;
		case COMPERR_Incompatible:
			compositeErrorStr = "incompatible bitmap(s) for operation";
			break;
		case COMPERR_Value:
			compositeErrorStr = "success";
			break;
		case COMPERR_SoftwareFallback:
			compositeErrorStr = "operation would fall back to software emulation";
			break;
		case COMPERR_OutOfMemory:
			compositeErrorStr = "out of memory";
			break;
		case COMPERR_Generic:
			compositeErrorStr = "some generic error has occurred";
			break;
		case COMPERR_UnknownOperator:
			compositeErrorStr = "unknown operator specified";
			break;
		case COMPERR_MissingInput:
			compositeErrorStr = "missing a mandatory tag item";
			break;
		default:
			compositeErrorStr = "unknown";
		}
		printf("Composited video isn't available (CompositeTags() returned: %u %s)\n",
			(unsigned int)errCode, compositeErrorStr);

		compositedVideoAvailable = FALSE;
	}

	if(compositedVideoAvailable)
	{
		// The initial render into the window
		fillWindowWithBitMap(yuvBitMap, window);

		// The main Loop
		struct IntuiMessage	*msg;
		BOOL quit = FALSE;
		BOOL refreshWindow = FALSE;
		do
		{
			IExec->WaitPort(window->UserPort);
			while ((msg = (struct IntuiMessage *) IExec->GetMsg (window->UserPort)))
			{
				switch (msg->Class)
				{
				case IDCMP_NEWSIZE:
					// A resize occurred, need to refresh the window
					refreshWindow = TRUE;
					break;
				case IDCMP_REFRESHWINDOW:
					refreshWindow = TRUE;
					break;
				case IDCMP_CLOSEWINDOW:
					// The user says quit!
					quit = TRUE;
					break;
				default:
					; // Do nothing
				}
				IExec->ReplyMsg((struct Message *) msg);

				if(refreshWindow)
				{
					fillWindowWithBitMap(yuvBitMap, window);

					refreshWindow = FALSE;
				}
			}
		} while (!quit);
	}

	IGraphics->FreeBitMap(yuvBitMap);
	yuvBitMap = NULL;
	IIntuition->CloseWindow(window);
	window = NULL;

	if(!compositedVideoAvailable)
	{
		// Composited video isn't available, try to fall back to overlay
		printf("No composited video, so falling back to using a PIP (a.k.a. overlay) window.\n");
		snprintf(titleStr, sizeof(titleStr), "%s Picture-In-Picture (PIP) Window (composited video not available)\n",
			pixelFormat->pixelFormatName);
		window = IP96->p96PIP_OpenTags (P96PIP_SourceFormat,	pixelFormat->pixelFormat,
								P96PIP_SourceWidth,	SOURCE_WIDTH,			/* Width of overlay surface */
								P96PIP_SourceHeight,	SOURCE_HEIGHT,			/* Height of overlay surface */

								/* Standard window tags... */
								WA_Title,				titleStr,
								WA_Activate,			TRUE,
								WA_RMBTrap,			TRUE,
								WA_DragBar,			TRUE,
								WA_DepthGadget,		TRUE,
								WA_SimpleRefresh,		TRUE,
								WA_SizeGadget,			TRUE,
								WA_CloseGadget,		TRUE,
								WA_IDCMP,				IDCMP_CLOSEWINDOW,

								/* Dimensions of the Intuition window that the overlay is attached to.
								 * In this case, these are interpreted the same as WA_InnerWidth and
								 * WA_InnerHeight - that is, the dimensions of the window borders are
								 * added on when the window is opened.
								 * If you omit these, then the window will be opened large enough so that
								 * the overlay will fit unscaled between the window borders.
								 *
								 * Here our window is larger than than the overlay, so the overlay
								 * will be scaled up by default.
								 */
								WA_Width,				WINDOW_WIDTH,
								WA_Height,				WINDOW_HEIGHT,

								/* You need to specify somehow the screen that the window should appear on. */
						 		WA_PubScreenName, 		"Workbench",
						 		TAG_DONE);

		if (window)
		{
			struct BitMap *pipBitMap;
			struct IntuiMessage	*msg;
			BOOL quit = FALSE;

			/* Get a handle on the overlay bitmap. */
			IP96->p96PIP_GetTags (window, P96PIP_SourceBitMap, (ULONG) &pipBitMap, TAG_END); // ##### FIXME! #####

			/* Draw something to the overlay bitmap. */
			renderYUVGradient(pipBitMap);

			/* Wait for user to hit close gadget. */
			do
			{
				IExec->WaitPort (window->UserPort);
				while ((msg = (struct IntuiMessage *) IExec->GetMsg (window->UserPort)))
				{
					switch (msg->Class)
					{
						case IDCMP_CLOSEWINDOW:
							quit = TRUE;
							break;
					}
					IExec->ReplyMsg ((struct Message *) msg);
				}
			} while (!quit);

			/* Close PIP window. */
			IP96->p96PIP_Close (window);
		}
		else
		{
			/* Should interpret and report an error here */
			printf("ERROR: Could not open PIP (a.k.a., overlay) window.\n");
			return 10;
		}
	}

	printf("%s is done. Bye.\n", argv[0]);

	return 0;
}

