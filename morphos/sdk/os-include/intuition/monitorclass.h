#ifndef INTUITION_MONITORCLASS_H
#define INTUITION_MONITORCLASS_H

/*
	intuition monitorclass definitions

	Copyright � 2004-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

/*

	MONITORCLASS introduced 1st in intuition.library 51 is an interface
	that allows obtaining various information about monitors (gfx cards)
	installed in system. You are not allowed to create your own MONITORCLASS
	objects, you may only get attrs and call methods defined below.

	To get the list of monitor objects installed in system please use
	GetMonitorList() function. You may also GetAttr the specific monitor
	of a screen by using GetAttr(SA_MonitorObject,screen,&monitor);

	Once you got a pointer to monitor object you may use it all the time
	without any need for locking any intuition semaphore - once installed
	the monitor cannot be removed from system, so the pointer is guaranteed
	to remain valid all the time.	

*/

#define MONITOR_MAXPIXELFORMATS 14

#define MA_Dummy                        (TAG_USER)
#define MA_MonitorName                  (MA_Dummy + 1)
/* CONST_STRPTR. Returns a pointer to a string with monitor name. Similar to
** SA_MonitorName.
*/

#define MA_Manufacturer                 (MA_Dummy + 2)
/* CONST_STRPTR. Return info about hardware manufacturer */

#define MA_ManufacturerID               (MA_Dummy + 3)
/* ULONG */

#define MA_ProductID                    (MA_Dummy + 4)
/* ULONG */

#define MA_MemorySize                   (MA_Dummy + 5)
/* ULONG. Returns the approx amount of gfx card own's memory */

#define MA_PixelFormats                 (MA_Dummy + 6)
/* ULONG *. Returns a READ ONLY array of size MONITOR_MAXPIXELFORMATS.
** To check which pixel format is supported on the gfx card you check
** the TRUE/FALSE value stored in the array at an offset defined with
** PIXFMT_ define from cybergraphx/cybergraphics.h
**
** EXAMPLE:
** ULONG *pixfmtarray;
** GetAttr(MA_PixelFormats,monitor,&pixfmtarray);
** if (pixfmtarray[PIXFMT_LUT8]) printf("Monitor supports LUT8!\n");
*/

#define MA_TopLeftMonitor               (MA_Dummy + 7)
#define MA_TopMiddleMonitor             (MA_Dummy + 8)
#define MA_TopRightMonitor              (MA_Dummy + 9)
#define MA_MiddleLeftMonitor            (MA_Dummy + 10)
#define MA_MiddleRightMonitor           (MA_Dummy + 11)
#define MA_BottomLeftMonitor            (MA_Dummy + 12)
#define MA_BottomMiddleMonitor          (MA_Dummy + 13)
#define MA_BottomRightMonitor           (MA_Dummy + 14)
/* Object *. Returns a monitor placed in a position relative to the
** current one or NULL if no monitor is present. Use this to obtain
** information about current monitor placement in user's work environment.
** BUGS: the methods returned a modeid instead of a pointer prior to 50.51
*/

#define MA_GammaControl                 (MA_Dummy + 15)
/* BOOL. Check whether a monitor supports gamma control or not */

#define MA_PointerType                  (MA_Dummy + 16)
/* ULONG. Returns the supported pointer type(s) as flags */
#define PointerType_3Plus1              1 /* col 0 transparent, 1-3 visible */
#define PointerType_2Plus1              2 /* col 0 transparent, 2-3 visible, 1 undefined/clear/inverse */
#define PointerType_ARGB                4 /* 32bit ARGB pointer */

#define MA_DriverName                   (MA_Dummy + 17)
/* CONST_STRPTR. Returns the CGX driver name */

#define MA_MemoryClock                  (MA_Dummy + 18)
/* ULONG. Returns card's memory clock in Hz. Will be 0 if unknown */

#define MA_BacklightControl             (MA_Dummy + 19)
/* BOOL. Returns TRUE if lcd backlight level control is available */

#define MA_BacklightLevelSteps          (MA_Dummy + 20)
/* ULONG. Returns the number of steps MA_BacklightLevel supports */

#define MA_BacklightLevel               (MA_Dummy + 21)
/* ULONG. Changes the backlight level. Allowed values are from 0 (backlight disabled)
** up to MA_BacklightLevelSteps - 1
*/

#define MA_EngineClock                  (MA_Dummy + 22)
/* ULONG. Returns card's engine clock in Hz. Will be 0 if unknown */

#define MA_Outputs                      (MA_Dummy + 23)
/* LONG. Returns the number of outputs associated with the monitor. Separate outputs
** are treated as separate monitors by intuition */

#define MA_Output                       (MA_Dummy + 24)
/* LONG. Returns the output number or 1 if this monitor isn't associated with a
** driver capable of handling multiple outputs */



/**************** METHODS ****************************************************/
#define MM_GetRootBitMap                0x401
/* Obtain driver's root bitmap which can be used as friend bitmap in AllocBitMap()
** call in order to allocate a bitmap in gfx card's memory. The bitmap will be of
** queried pixelformat. The result will be NULL if a pixelformat is unsupported by
** the card (not displayable) or if bitmap allocation failed internaly.
** You must NOT use this bitmap in any other way than for reference with AllocBitMap()
** Do NOT try to FreeBitMap() it!
**
** EXAMPLE:
** struct BitMap *rootbitmap;
** struct BitMap *bitmap = NULL;
**
** DoMethod(monitor,MM_GetRootBitMap,PIXFMT_BGRA32,&rootbitmap);
**
** if (rootbitmap)
** {
**     bitmap = AllocBitMap(width,height,GetBitMapAttr(rootbitmap,BMA_DEPTH),
							BMF_REQUESTVMEM,rootbitmap);
** }
*/

struct msGetRootBitMap
{
	ULONG   MethodID;
	ULONG   PixelFormat;
	ULONG  *Store;
};

#define MM_Query3DSupport               0x402
/* Check whether a gfx card supports hardware 3d acceleration for a given
** pixel format. Store ptr will be filled with one of the MSQUERY3D defines
** below.
*/

struct msQuery3DSupport
{
	ULONG  MethodID;
	ULONG  PixelFormat;
	ULONG *Store;
};

#define MSQUERY3D_UNKNOWN  (0) /* unsupported pixel format or other pb */
#define MSQUERY3D_NODRIVER (1) /* no driver found for this pixel mode  */
#define MSQUERY3D_SWDRIVER (2) /* only software 3d driver available    */
#define MSQUERY3D_HWDRIVER (3) /* hardware acceleration available      */

#define MM_GetDefaultGammaTables        0x403
/* Use this function to obtain the default gamma/brightness/contrast settings
** of a monitor. You should check if gamma control is supported with
** MA_GammaControl attribute. You may change those values per screen as long
** as you are the owner of the screen. Changing it for Ambient screen will
** NOT be supported. It's OK for any of the gammatable pointers to be NULL.
*/

struct msGetDefaultGammaTables
{
	ULONG  MethodID;
	UBYTE *Red; /* pointer to a 256 byte array to fill */
	UBYTE *Green;
	UBYTE *Blue;
};

#define MM_GetDefaultPixelFormat        0x404
/* Use this to get the best pixel format for a given depth. Returns -1 for an
** unsupported depth.
*/

struct msGetDefaultPixelFormat
{
	ULONG MethodID;
	ULONG Depth;
	ULONG *Store;
};

#define MM_GetPointerBounds            0x405
/* Use this to obtain the supported size of a mouse pointer for the given type.
** Returns FALSE if the type isn't supported, otherwise TRUE.
*/

struct msGetPointerBounds
{
	ULONG MethodID;
	ULONG PointerType;
	ULONG *Width;
	ULONG *Height;
};

#define MM_RunBlanker                  0x406
/* Starts a blanker for this monitor (if there is one configured)
*/

#define MM_EnterPowerSaveMode          0x407
/* Starts the monitor power saving routines
*/

#define MM_ExitBlanker                 0x408
/* Aborts a running blanker/power saving mode
*/

#define MM_Authorization               0x409
/* Opens the user password authorization screen, added in 51.68
*/


#define MA_Mode_Dummy                  (TAG_USER)
#define MA_Mode_ModeID                 (MA_Mode_Dummy + 1)
#define MA_Mode_Name                   (MA_Mode_Dummy + 2)
#define MA_Mode_MonitorObject          (MA_Mode_Dummy + 3)
#define MA_Mode_Width                  (MA_Mode_Dummy + 4)
#define MA_Mode_Height                 (MA_Mode_Dummy + 5)
#define MA_Mode_Depth                  (MA_Mode_Dummy + 6)
#define MA_Mode_PixelFormat            (MA_Mode_Dummy + 7)
#define MA_Mode_3DSupport              (MA_Mode_Dummy + 8)

#define MA_Mode_NominalDimensions          (MA_Mode_Dummy + 10)
#define MA_Mode_MaxOverscanDimensions      (MA_Mode_Dummy + 11)
#define MA_Mode_VideoOverscanDimensions    (MA_Mode_Dummy + 12)
#define MA_Mode_TextOverscanDimensions     (MA_Mode_Dummy + 13)
#define MA_Mode_StandardOverscanDimensions (MA_Mode_Dummy + 14)

#define MM_Mode_GetBitsPerColor        (0x450)

struct msmGetBitsPerColor
{
	ULONG  MethodID;
	ULONG *Red;
	ULONG *Green;
	ULONG *Blue;
};

#define MM_Mode_GetRefreshFrequencies  (0x451)

struct msmGetRefreshFrequecies
{
	ULONG  MethodID;
	FLOAT *HorizontalFrequencykHz;
	FLOAT *VerticalFrequencyHz;
};

#define MM_Mode_GetRasterSizeLimits    (0x452)

struct msmGetRasterSizeLimits
{
	ULONG  MethodID;
	ULONG *MinWidth;
	ULONG *MinHeight;
	ULONG *MaxWidth;
	ULONG *MaxHeight;
};

#endif /* INTUITION_MONITORCLASS_H */
