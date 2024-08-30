/*
** monitors.c - Demonstrates how to use MONITORCLASS API.
** Build with: gcc -noixemul -o monitors monitors.c
**
** ©2004-2022 by Jacek Piszczek of MorphOS Development Team
*/
#define INTUI_V50_NOOBSOLETE

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/dos.h>

#include <intuition/intuition.h>
#include <intuition/extensions.h>
#include <intuition/monitorclass.h>
#include <cybergraphx/cybergraphics.h>
#include <dos/dos.h>

#include <clib/alib_protos.h>
#include <stdio.h>

//#define SPEEDTEST

struct IntuitionBase *IntuitionBase = NULL;

#define LIBVERSION(x) ((struct Library *)x)->lib_Version
#define LIBREVISION(x) ((struct Library *)x)->lib_Revision

STRPTR	PixFmts[]=
{
	(STRPTR)"LUT8",
	(STRPTR)"RGB15",
	(STRPTR)"RGBX15",
	(STRPTR)"RGB15PC",
	(STRPTR)"BGR15PC",
	(STRPTR)"RGB16",
	(STRPTR)"BGR16",
	(STRPTR)"RGB16PC",
	(STRPTR)"BGR16PC",
	(STRPTR)"RGB24",
	(STRPTR)"BGR24",
	(STRPTR)"ARGB32",
	(STRPTR)"BGRA32",
	(STRPTR)"RGBA32"
};

int main(void)
{
	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",51);

	/* MONITORCLASS is supported since 51 */

	if (IntuitionBase)
	{

		/* 1st let's determine how many monitors we have */

		Object **monitors = GetMonitorList(NULL);

		if (monitors)
		{
			struct Screen *pubscr = NULL;
			LONG monitor = 0;

			/* now let's scan through all installed monitors and print some
			info about them */

			while (monitors[monitor])
			{
				CONST_STRPTR monitorname = NULL;
				CONST_STRPTR monitormanufacturer = NULL;
				ULONG manid, productid;
				ULONG memorysize;
				ULONG *pixelformats = NULL;
				ULONG output, outputs = 0;
				
				GetAttr(MA_MonitorName,monitors[monitor],(ULONG*)&monitorname);

				/* both strings should never be NULL, but a check won't hurt */
				if (monitorname) printf("Found monitor %s\n",monitorname);
				
				GetAttr(MA_Manufacturer,monitors[monitor],(ULONG*)&monitormanufacturer);

				if (monitormanufacturer) printf("%s\n",monitormanufacturer);

				GetAttr(MA_ManufacturerID,monitors[monitor],&manid);
				GetAttr(MA_ProductID,monitors[monitor],&productid);

				printf("Vendor ID 0x%lx, Product ID 0x%lx\n",manid,productid);

				GetAttr(MA_MemorySize,monitors[monitor],&memorysize);

				printf("Card equipped with %ld bytes of memory\n",memorysize);

				GetAttr(MA_Output, monitors[monitor], &output);
				GetAttr(MA_Outputs, monitors[monitor], &outputs);
				
				if (0 == output)
					printf("Driver supports %ld outputs, this monitor represents the main output head\n", outputs);
				else
					printf("Driver supports %ld outputs, this monitor represents auxillary output head %ld\n", outputs, output);

				GetAttr(MA_PixelFormats,monitors[monitor],(ULONG*)&pixelformats);

				if (pixelformats)
				{
					LONG fmt;

					printf("Supported pixel formats are:");

					for (fmt = 0; fmt < MONITOR_MAXPIXELFORMATS; fmt++)
					{
						if (pixelformats[fmt]) printf(" %s",PixFmts[fmt]);
					}

					printf("\n");

					printf("3d is supported on following pixel formats:");

					for (fmt = 0; fmt < MONITOR_MAXPIXELFORMATS; fmt ++)
					{
						if (pixelformats[fmt])
						{
							ULONG state = 0;

							DoMethod(monitors[monitor],MM_Query3DSupport,fmt,&state);

							switch (state)
							{
								case MSQUERY3D_SWDRIVER:
									printf(" %s (SW)",PixFmts[fmt]);
									break;

								case MSQUERY3D_HWDRIVER:
									printf(" %s (HW)",PixFmts[fmt]);
									break;
							}
						}
					}

					printf("\n");

					#ifdef SPEEDTEST
					for (fmt = 0; fmt < MONITOR_MAXPIXELFORMATS; fmt ++)
					{
						if (pixelformats[fmt])
						{
							struct BitMap *rootbitmap;
							struct BitMap *bm1,*bm2;

							DoMethod(monitors[monitor],MM_GetRootBitMap,fmt,&rootbitmap);

							if (rootbitmap)
							{
								printf("Probing internal blitter speed for pixel format %s\n",PixFmts[fmt]);

								bm1 = AllocBitMap(256,256,GetBitMapAttr(rootbitmap,BMA_DEPTH),BMF_REQUESTVMEM,rootbitmap);
								bm2 = AllocBitMap(256,256,GetBitMapAttr(rootbitmap,BMA_DEPTH),BMF_REQUESTVMEM,rootbitmap);

								/* NOTE: this code does not check if the bitmaps really are in VMEM
								it's not really precise as well :) */
								if (bm1 && bm2)
								{
									struct DateStamp ds1,ds2;
									QUAD time1,time2;
									ULONG loopcnt,time;

									DateStamp(&ds1);

									for (loopcnt = 0; loopcnt < 10000; loopcnt ++)
									{
										BltBitMap(bm1,0,0,bm2,0,0,256,256,0xC0,0xFFFFFFFF);
									}

									DateStamp(&ds2);

									time1 = (ds1.ds_Minute * 60 * TICKS_PER_SECOND) + ds1.ds_Tick;
									time2 = (ds2.ds_Minute * 60 * TICKS_PER_SECOND) + ds2.ds_Tick;

									time = time2 - time1;

									printf("Did 10000 256*256 blits in %ld ticks\n",time);
								}

								if (bm1) FreeBitMap(bm1);
								if (bm2) FreeBitMap(bm2);
							}
						}
					}
					#endif
				}

				if (LIBVERSION(IntuitionBase) > 60 || (LIBVERSION(IntuitionBase) == 60 && LIBREVISION(IntuitionBase) >= 34))
				{
					Object **modes = GetMonitorModesList(monitors[monitor], NULL);
					if (modes)
					{
						int modei = 0;
						while (modes[modei])
						{
							Boopsiobject *mode = modes[modei++];
							CONST_STRPTR name = NULL;
							ULONG modeid = INVALID_ID;
							ULONG width = 0;
							ULONG height = 0;
							ULONG depth = 8;
							ULONG pixelfmt = PIXFMT_ARGB32;
							ULONG support3d = MSQUERY3D_UNKNOWN;

							GetAttr(MA_Mode_Name, mode, (ULONG*)&name);
							GetAttr(MA_Mode_ModeID, mode, (ULONG*)&modeid);
							GetAttr(MA_Mode_Width, mode, (ULONG*)&width);
							GetAttr(MA_Mode_Height, mode, (ULONG*)&height);
							GetAttr(MA_Mode_Depth, mode, (ULONG*)&depth);
							GetAttr(MA_Mode_PixelFormat, mode, (ULONG*)&pixelfmt);
							GetAttr(MA_Mode_3DSupport, mode, (ULONG*)&support3d);
							
							printf("Mode: '%s'\n", name);
							printf("\tModeID: %08lx Width: %ld Height: %ld Depth: %ld\n", 
								modeid, width, height, depth);
							printf("\tPixel format: %s. Hardware 3D support: %s\n", PixFmts[pixelfmt], support3d == MSQUERY3D_HWDRIVER ? "yes" : "no");

							ULONG rbits = 0, gbits = 0, bbits = 0;
							DoMethod(mode, MM_Mode_GetBitsPerColor, &rbits, &gbits, &bbits);
							printf("\tBits per Color: R=%ld G=%ld B=%ld\n", rbits, gbits, bbits);

							float horiz = 0, vert = 0;
							DoMethod(mode, MM_Mode_GetRefreshFrequencies, &horiz, &vert);
							printf("\tRefresh Horizontal: %.02fkHz Vertical %.02fHz\n", horiz, vert);

							ULONG rminw, rminh, rmaxw, rmaxh;
							DoMethod(mode, MM_Mode_GetRasterSizeLimits, &rminw, &rminh, &rmaxw, &rmaxh);
							printf("\tMinimal screen size: %ldx%ld. Maximal screen size: %ldx%ld\n", rminw, rminh, rmaxw, rmaxh);

							struct Rectangle *nominal = NULL;
							GetAttr(MA_Mode_NominalDimensions, mode, (ULONG *)&nominal);
							if (nominal)
								printf("\tNominal overscan: %d %d %d %d\n", nominal->MinX, nominal->MinY, nominal->MaxX, nominal->MaxY);

							printf("\n");
						}
						FreeMonitorModesList(modes);
					}
					else
					{
						printf("Failed obtaining modes list!\n");
					}
				}

				printf("---\n");
				monitor++;
			}

			/* free resources */
			FreeMonitorList(monitors);

			/* OK, we're done with installed monitors, let's check on which monitor
			our default public screen is opened on.*/

			if ((pubscr = LockPubScreen(NULL)))
			{
				Object *monitor;
				char *monitorname;

				GetAttr(SA_MonitorObject,pubscr,(ULONG*)&monitor);
				GetAttr(SA_MonitorName,pubscr,(ULONG*)&monitorname);

				if (monitor && monitorname)
				{
					printf("Default public screen is opened on %s (0x%lx)\n",monitorname,(ULONG)monitor);
				}

				UnlockPubScreen(NULL,pubscr);
			}

		} else {
			printf("Whoops!? No monitors installed?! We must be running out of mem.\n");
		}

	} else {
		printf("Intuition library is too old\n");
	}
	
	if (IntuitionBase) CloseLibrary((struct Library *)IntuitionBase);

	return 0;
}

