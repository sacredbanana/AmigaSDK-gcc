/** Test program for rendering YUV
 *
 * This program will open a window, render a 2D gradient in YUV format and render
 * a simple animation using it. This tests various CompositeTags() features in
 * combination with the YUV bitmap.
 *
 * Copyright (C) 2014 by Hans de Ruiter, all rights reserved.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <graphics/composite.h>
#include <intuition/intuition.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/layers.h>
#include <proto/utility.h>


// The width of the source bitmap NOTE: Make sure that it's a multiple of 4
#define SOURCE_WIDTH 256

// The width of the source bitmap NOTE: Make sure that it's a multiple of 4
#define SOURCE_HEIGHT 256

// The initial window dimensions
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

// Windwo size limits
#define WINDOW_MINWIDTH 100
#define WINDOW_MINHEIGHT 100
#define WINDOW_MAXWIDTH 2048
#define WINDOW_MAXHEIGHT 2048

// Buffer size for window title
#define TITLESTR_LEN 512

#define SQ(x) ((x) * (x))

// Wait for x number of frames
#define WAIT_FRAMES(x) \
	for(int i =0; i < (x); ++i)									\
	{ 															\
		IGraphics->WaitBOVP(&(window->WScreen->ViewPort)); 		\
		renderBitMapToFitWindow(backBuffer, window);			\
		getUserInput(window, &next, &quit);						\
		if(quit || next) { break; }								\
	}

// BT.601 YUV conversion matrix
static float32 bt601YUVToRGBMatrix[12] = {
				1.0f,  0.0f,          1.402f,        -0.701f,
		 		1.0f, -0.344136286f, -0.7141326286f,  0.529136286f,
		 		1.0f,  1.722f,        0.0f,          -0.866f};

// Maps YUV pixel format names to Picasso96 types
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

/** Render a SOURCE_WIDTH x SOURCE_HEIGHT 2D-gradient to a YUV Bitmap
 *
 * @param bitMap the bitmap to render to (must have a YUV pixel format)
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
			else if(pixelFormat == PIXF_YUV422PC)
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

						/* Construct RGBFB_YUV422PC macro-pixel. */
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

/** Renders a SOURCE_WIDTH x SOURCE_HEIGHT alpha mask.
 *
 * @param bitMap the bitmap to render to (the pixel format must be RGBFB_CLUT or
 * RGBFB_ALPHA8)
 */
static void renderAlphaMask(struct BitMap *bitMap)
{
	PIX_FMT pixelFormat = IGraphics->GetBitMapAttr(bitMap, BMA_PIXELFORMAT);
	if(!(pixelFormat == PIXF_ALPHA8 || pixelFormat == PIXF_CLUT))
	{
		printf("ERROR: %s called with a bitmap of the wrong type\n", __func__);
		return;
	}

	/* Just like any other bitmap in video memory, we need to lock
	 * an overlay bitmap.
	 */
	APTR memory;
	uint32 bytesPerRow;

	APTR lock = IGraphics->LockBitMapTags(bitMap,
		LBM_BaseAddress, &memory,
		LBM_BytesPerRow, &bytesPerRow,
		TAG_DONE);

	if(lock)
	{
		uint8* pixel;
		uint8* currRow;
		currRow = memory;

		float midX = SOURCE_WIDTH / 2.0f;
		float midY = SOURCE_HEIGHT / 2.0f;

		for(int y = 0; y < SOURCE_HEIGHT; ++y)
		{
			float yOffsetNorm = (y - midY) / midY;
			pixel = currRow;
			for(int x = 0; x < SOURCE_WIDTH; ++x)
			{
				float xOffsetNorm = (x - midX) / midX;
				float alpha = 3.0f * (1.0f - (float)(SQ(xOffsetNorm) + SQ(yOffsetNorm)));
				if(alpha < 0.0f) { alpha = 0.0f; }
				if(alpha > 1.0f) { alpha = 1.0f; }
				*pixel = (uint8)(alpha * 255 + 0.5f);
				++pixel;
			}
			currRow += bytesPerRow;
		}

		IGraphics->UnlockBitMap(lock);
	}
	else
	{
		printf("ERROR: Couldn't lock the bitmap\n");
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
		COMPTAG_Flags,      COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha | COMPFLAG_HardwareOnly, // HW only, we don't want software fallback
		TAG_END);

	return 0;
}

/** Composites a bitmap to fit the given window (the window's interior).
 * The bitmap is centred and the outside areas are filled with black.
 *
 * @param bitmap the bitmap
 * @param window the window to render to
 *
 * @return uint32 the compositing operation's return-code
 */
uint32 renderBitMapToFitWindow(struct BitMap *bitMap, struct Window *window)
{
	struct Rectangle rect;
	struct Hook hook;
	rect.MinX = window->BorderLeft;
 	rect.MinY = window->BorderTop;
	rect.MaxX = window->Width - window->BorderRight - 1;
 	rect.MaxY = window->Height - window->BorderBottom - 1;

 	float destWidth = window->Width - window->BorderRight - window->BorderLeft;
 	float destHeight = window->Height - window->BorderTop - window->BorderBottom;
 	float scaleX = destWidth / SOURCE_WIDTH;
 	float scaleY = destHeight / SOURCE_HEIGHT;
 	float scale;
 	int32 offsetX, offsetY;
 	if(scaleX < scaleY)
 	{
 		// Display aspect ratio is taller than source image
 		scale = scaleX;
 		offsetX = window->BorderLeft;
 		float newDestHeight = SOURCE_HEIGHT * scale;
 		offsetY = window->BorderTop + (int32) ((destHeight - newDestHeight) / 2);

 		// Fill the outer areas with black
 		IGraphics->RectFillColor(window->RPort, rect.MinX, rect.MinY,
 			rect.MaxX, offsetY - 1, 0xFF000000);
 		IGraphics->RectFillColor(window->RPort, rect.MinX, offsetY + (int32)newDestHeight,
 			rect.MaxX, rect.MaxY, 0xFF000000);

 		// Update the dest height
 		destHeight = newDestHeight;
 	}
 	else
 	{
 		// Display aspect ratio is wider than source image
 		scale = scaleY;
 		float newDestWidth = SOURCE_WIDTH * scale;
 		offsetX = window->BorderLeft + (int32) ((destWidth -  newDestWidth) / 2);
 		offsetY = window->BorderTop;

 		// Fill the outer areas with black
 		IGraphics->RectFillColor(window->RPort, rect.MinX, rect.MinY,
 			offsetX - 1, rect.MaxY, 0xFF000000);
 		IGraphics->RectFillColor(window->RPort, offsetX + (int32)newDestWidth, rect.MinY,
 			rect.MaxX, rect.MaxY, 0xFF000000);

 		// Update the dest width
 		destWidth = newDestWidth;
 	}


	// Need to composite onto the window's rastport. Since CompositeTags() only renders to bitmaps,
	// we use ILayers->DoHookClipRects().
	CompositeHookData hookData;
	hookData.srcBitMap = bitMap;
	hookData.srcWidth = SOURCE_WIDTH;
	hookData.srcHeight = SOURCE_HEIGHT;
	hookData.offsetX = offsetX;
	hookData.offsetY = offsetY;
	hookData.scaleX = COMP_FLOAT_TO_FIX(scale);
	hookData.scaleY = COMP_FLOAT_TO_FIX(scale);
	hookData.retCode = COMPERR_Success;
	rect.MinX = offsetX;
 	rect.MinY = offsetY;
	rect.MaxX = offsetX + (int32)destWidth - 1;
 	rect.MaxY = offsetY + (int32)destHeight - 1;

	hook.h_Entry = (HOOKFUNC)compositeHookFunc;
	hook.h_Data = &hookData;

	ILayers->DoHookClipRects(&hook, window->RPort, &rect);

	return hookData.retCode;
}

/** Generates a matrix that converts from YUV to RGB and adjusts the saturation at
 * the same time.
 *
 * @param saturation the saturation to use
 * @param matrixOut pointer to the output matrix (a 3x4 matrix in row-major order)
 */
void generateYUVSaturationMatrix(float32 saturation, float32* matrixOut)
{
	matrixOut[0] = bt601YUVToRGBMatrix[0];
	matrixOut[1] = saturation * bt601YUVToRGBMatrix[1];
	matrixOut[2] = saturation * bt601YUVToRGBMatrix[2];
	matrixOut[3] = saturation * bt601YUVToRGBMatrix[3];
	matrixOut[4] = bt601YUVToRGBMatrix[4];
	matrixOut[5] = saturation * bt601YUVToRGBMatrix[5];
	matrixOut[6] = saturation * bt601YUVToRGBMatrix[6];
	matrixOut[7] = saturation * bt601YUVToRGBMatrix[7];
	matrixOut[8] = bt601YUVToRGBMatrix[8];
	matrixOut[9] = saturation * bt601YUVToRGBMatrix[9];
	matrixOut[10] = saturation * bt601YUVToRGBMatrix[10];
 	matrixOut[11] = saturation * bt601YUVToRGBMatrix[11];
}

/** Checks for user input without blocking.
 * The user can do only two things, push space to skip to the next test, or click
 * on the close button to quit.
 *
 * @param window pointer to the window that we're checking events for
 * @param userReqNext pointer to where the "user requests next" state will be written.
 * This will be set to TRUE when the user has pushed the space bar.
 * @param userReqQuit pointer to where the "user requests quit" state will be written.
 * This will be set to TRUE when the user has clicked on the close gadget
 *
 * @return BOOL TRUE if there was user input; FALSE if not
 */
BOOL getUserInput(struct Window *window, BOOL *userReqNext, BOOL * userReqQuit)
{
	BOOL gotInput = FALSE;
	BOOL quit = FALSE;
	BOOL next = FALSE;
	struct IntuiMessage	*msg;
	while ((msg = (struct IntuiMessage *) IExec->GetMsg (window->UserPort)))
	{
		switch (msg->Class)
		{
		case IDCMP_VANILLAKEY:
			if(msg->Code == ' ')
			{
				next = TRUE;
				gotInput = TRUE;
			}
			break;
		case IDCMP_CLOSEWINDOW:
			// The user says quit!
			quit = TRUE;
			gotInput = TRUE;
			break;
		default:
			; // Do nothing
		}
		IExec->ReplyMsg((struct Message *) msg);
	}

	if(gotInput)
	{
		if(userReqNext) { *userReqNext = next; }
		if(userReqQuit) { *userReqQuit = quit; }
	}

	return gotInput;
}

/** Prints details on how to use this program.
 *
 * @param progName this program's name (use argv[0])
 */
void printUsage(const char *progName)
{
    printf("Usage: %s <YUV format>\n", progName);
    printf("<YUV format> ca be: YUV420p, YUV410p, YUV422, YUV422PC (default = YUV420p)\n");
}

int main (int argc, const char **argv)
{
	int retCode = 0;
    static char titleStr[TITLESTR_LEN];
    PixelFormatMapping *pixelFormat = &(yuvPixelFormatMappings[0]);
    BOOL compositedVideoAvailable = TRUE;
    struct BitMap *yuvBitMap = NULL;
    struct BitMap *alphaMask = NULL;
    struct BitMap *backBuffer = NULL;
    struct Window *window = NULL;

    // Print welcome text
    printf("%s\n\n", argv[0]);
    printf("Composited video extended test/demo.\n");
    printf("This tests various different CompositeTags() features with YUV source bitmaps.\n");

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
								WA_IDCMP,				IDCMP_CLOSEWINDOW | IDCMP_VANILLAKEY,
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
	yuvBitMap = IGraphics->AllocBitMapTags(SOURCE_WIDTH, SOURCE_HEIGHT, 32,
					BMATags_Displayable, TRUE,
					BMATags_PixelFormat, pixelFormat->pixelFormat,
					TAG_DONE);

	if(!yuvBitMap)
	{
		printf("ERROR: Couldn't allocate %s bitmap\n", pixelFormat->pixelFormatName);
		retCode = 10;
		goto CLEAN_UP;
	}

	// Test if composited video is available
	// This simply performs a test render to the window. If it fails, then we
	// know that the graphics card displaying the window doesn't support
	// composited video.
	uint32 errCode = renderBitMapToFitWindow(yuvBitMap, window);
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

	if(!compositedVideoAvailable)
	{
		printf("ERROR: Composited video isn't available. Quitting now.\n");
		retCode = 10;
		goto CLEAN_UP;
	}

	// Now draw the gradient into the bitmap
	// NOTE: We do this here, because Picasso96 currently doesn't page planar YUV bitmaps in and out
	// properly. The composited video test ensures that the bitmap is moved into VRAM
	renderYUVGradient(yuvBitMap);

	// Generate the alpha mask
	alphaMask = IGraphics->AllocBitMapTags(SOURCE_WIDTH, SOURCE_HEIGHT, 8,
					BMATags_Displayable, TRUE,
					BMATags_PixelFormat, PIXF_ALPHA8,
					TAG_DONE);
	renderAlphaMask(alphaMask);

	// Create the back-buffer
	// Our animation is going to be the same size as the source bitmap
	backBuffer = IGraphics->AllocBitMapTags(SOURCE_WIDTH, SOURCE_HEIGHT, 32,
 					BMATags_Displayable, TRUE,
					BMATags_PixelFormat, PIXF_A8R8G8B8,
					TAG_DONE);
	if(!backBuffer)
	{
		printf("ERROR: Couldn't allocate back-buffer\n");
		retCode = 10;
		goto CLEAN_UP;
	}

	// Render the first frame (complete darkness)
	struct RastPort backBufferRP;
	IGraphics->InitRastPort(&backBufferRP);
	backBufferRP.BitMap = backBuffer;
	IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
	renderBitMapToFitWindow(backBuffer, window);

	// The main Loop
	// Just doing a very unsophisticated VBlank timed animation
	BOOL quit = FALSE;
	BOOL next = FALSE;
	while(!quit)
	{
		// -- The external alpha override test --
		printf("External alpha override test\n");
		{
			float alpha = 0.0f;

			// Fade in the YUV bitmap
			while(!quit && !next)
			{
				// Render this frame
				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcAlpha, COMP_FLOAT_TO_FIX(alpha),
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly | COMPFLAG_SrcAlphaOverride,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				alpha += 1.0f / 60.0f; // Up to 1.0 in 60 frames
				if(alpha >= 1.0f)
				{
					alpha = 1.0f;
					next = TRUE;
				}

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;

			WAIT_FRAMES(60)
			next = FALSE;

			// Fade out the YUV bitmap
			alpha = 1.0f;
			while(!quit && !next)
			{
				// Render this frame
				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcAlpha, COMP_FLOAT_TO_FIX(alpha),
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly | COMPFLAG_SrcAlphaOverride,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				alpha -= 1.0f / 60.0f; // Up to 1.0 in 60 frames
				if(alpha <= 0.0f)
				{
					alpha = 0.0f;
					next = TRUE;
				}

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;
		}
		if(quit) { break; }


		// -- The alpha mask & alpha factor test --
		printf("Alpha mask & alpha factor test\n");
		{
			float alpha = 0.0f;

			// Fade in the YUV bitmap
			while(!quit && !next)
			{
				// Render this frame
				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcAlphaMask, alphaMask,
						COMPTAG_SrcAlpha, COMP_FLOAT_TO_FIX(alpha),
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				alpha += 1.0f / 60.0f; // Up to 1.0 in 60 frames
				if(alpha >= 1.0f)
				{
					alpha = 1.0f;
					next = TRUE;
				}

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;

			WAIT_FRAMES(60)
			next = FALSE;

			// Fade out the YUV bitmap
			while(!quit && !next)
			{
				// Render this frame
				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcAlphaMask, alphaMask,
						COMPTAG_SrcAlpha, COMP_FLOAT_TO_FIX(alpha),
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				alpha -= 1.0f / 60.0f; // Up to 1.0 in 60 frames
				if(alpha <= 0.0f)
				{
					alpha = 0.0f;
					next = TRUE;
				}

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;
		}
		if(quit) { break; }


		// -- COMPTAG_SrcYUVStandard test --
		printf("COMPTAG_SrcYUVStandard test (switching between BT.601 & BT.709)\n");
		{
			BOOL useBT709 = FALSE;
			int counter = 0;
			int counterMax = 3 * 60; // 180 frames
			int subCounter = 0;
			int framesToSwitch = counterMax / 6;

			while(!quit && !next)
			{
				// Render this frame

				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcYUVStandard, (useBT709 ? COMPYUV_BT709 : COMPYUV_BT601),
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly | COMPFLAG_SrcAlphaOverride,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				++counter;
				++subCounter;
				if(subCounter == framesToSwitch)
				{
					subCounter = 0;
					useBT709 = !useBT709;
				}
				if(counter > counterMax) { next = TRUE; }

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;
		}
		if(quit) { break; }


		// -- Custom YUV conversion matrix test --
		printf("Custom YUV conversion matrix test (adjusting saturation)\n");
		{
			float32 yuvMatrix[12];
			float32 saturation = 1.0;
			while(!quit && !next)
			{
				// Render this frame
				generateYUVSaturationMatrix(saturation, yuvMatrix);
				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcYUVMatrix, yuvMatrix,
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				saturation -= 1.0f / 60.0f; // Up to 1.0 in 60 frames
				if(saturation <= 0.0f)
				{
					saturation = 0.0f;
					next = TRUE;
				}

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;

			WAIT_FRAMES(60)
			next = FALSE;

			// Fade out the YUV bitmap
			while(!quit && !next)
			{
				// Render this frame
				generateYUVSaturationMatrix(saturation, yuvMatrix);
				IGraphics->RectFillColor(&backBufferRP, 0, 0, SOURCE_WIDTH - 1, SOURCE_HEIGHT - 1, 0xFF000000);
				IGraphics->CompositeTags(COMPOSITE_Src_Over_Dest, yuvBitMap, backBuffer,
						COMPTAG_SrcYUVMatrix, yuvMatrix,
						COMPTAG_Flags, COMPFLAG_SrcFilter | COMPFLAG_IgnoreDestAlpha |
							COMPFLAG_HardwareOnly,
						TAG_DONE);

				// Wait for the next vertical blanking period, and render the next frame
				IGraphics->WaitBOVP(&(window->WScreen->ViewPort));
				renderBitMapToFitWindow(backBuffer, window);

				// Update the animation
				saturation += 1.0f / 60.0f; // Up to 1.0 in 60 frames
				if(saturation >= 1.0f)
				{
					saturation = 1.0f;
					next = TRUE;
				}

				// Get and react to user input
				getUserInput(window, &next, &quit);
			}
			next = FALSE;
		}
		if(quit) { break; }

	}

CLEAN_UP:

	IGraphics->FreeBitMap(backBuffer);
	backBuffer = NULL;

	IGraphics->FreeBitMap(alphaMask);
	alphaMask = NULL;

	IGraphics->FreeBitMap(yuvBitMap);
	yuvBitMap = NULL;

	if(window)
	{
		IIntuition->CloseWindow(window);
		window = NULL;
	}

	printf("%s is done. Bye.\n", argv[0]);

	return retCode;
}

