#ifndef WORKBENCH_ICON_H
#define WORKBENCH_ICON_H

/*
**    $VER: icon.h 54.16 (22.08.2022)
**
**    External declarations for icon.library
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif

#ifndef   INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
#endif

#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif

/****************************************************************************/

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

#define ICONNAME "icon.library"

/****************************************************************************/

#define ICONA_Dummy                         (TAG_USER+0x9000)

/****************************************************************************/

/* Error reporting (LONG *) */
#define ICONA_ErrorCode                     (ICONA_Dummy+1)

/* Points to the tag item that caused the error (struct TagItem **). */
#define ICONA_ErrorTagItem                  (ICONA_Dummy+75)

/****************************************************************************/

/* Global options for IconControlA() */

/* Screen to use for remapping Workbench icons to (struct Screen *) */
#define ICONCTRLA_SetGlobalScreen           (ICONA_Dummy+2)
#define ICONCTRLA_GetGlobalScreen           (ICONA_Dummy+3)

/* Icon color remapping precision; defaults to PRECISION_ICON (LONG) */
#define ICONCTRLA_SetGlobalPrecision        (ICONA_Dummy+4)
#define ICONCTRLA_GetGlobalPrecision        (ICONA_Dummy+5)

/* Icon frame size dimensions (struct Rectangle *) */
#define ICONCTRLA_SetGlobalEmbossRect       (ICONA_Dummy+6)
#define ICONCTRLA_GetGlobalEmbossRect       (ICONA_Dummy+7)

/* Render image without frame (BOOL) */
#define ICONCTRLA_SetGlobalFrameless        (ICONA_Dummy+8)
#define ICONCTRLA_GetGlobalFrameless        (ICONA_Dummy+9)

/* Enable NewIcons support (BOOL) */
#define ICONCTRLA_SetGlobalNewIconsSupport  (ICONA_Dummy+10)
#define ICONCTRLA_GetGlobalNewIconsSupport  (ICONA_Dummy+11)

/* Enable color icon support (BOOL) */
#define ICONCTRLA_SetGlobalColorIconSupport (ICONA_Dummy+77)
#define ICONCTRLA_GetGlobalColorIconSupport (ICONA_Dummy+78)

/* Set/Get the hook to be called when identifying a file (struct Hook *) */
#define ICONCTRLA_SetGlobalIdentifyHook     (ICONA_Dummy+12)
#define ICONCTRLA_GetGlobalIdentifyHook     (ICONA_Dummy+13)

/* Set/get the maximum length of a file/drawer name supported
 * by icon.library (LONG).
 */
#define ICONCTRLA_SetGlobalMaxNameLength    (ICONA_Dummy+67)
#define ICONCTRLA_GetGlobalMaxNameLength    (ICONA_Dummy+68)

/* Enable marking of left-out icons (BOOL) (V51) */
#define ICONCTRLA_SetGlobalLeftOutMarking   (ICONA_Dummy+96)
#define ICONCTRLA_GetGlobalLeftOutMarking   (ICONA_Dummy+97)

/* Set/get the required visual effect for selected icons (ULONG) (V51) */
#define ICONCTRLA_SetGlobalSelectEffect     (ICONA_Dummy+113)
#define ICONCTRLA_GetGlobalSelectEffect     (ICONA_Dummy+114)

/****************************************************************************/

/* Values for ICONCTRLA_Set/GetGlobalSelectEffect */

/* Darken the icon, by the amount specified in the lowest byte (000000XX) */
#define SEL_DARKEN     0x00000000

/* Brighten the icon, by the amount specified in the lowest byte (000000XX) */
#define SEL_BRIGHTEN   0x01000000

/* Impose a color over the icon image, specified in the lower bytes (00RRGGBB) */
#define SEL_IMPOSE     0x02000000

/* Invert the colors of the icon, as specified in the lowest byte (000000XX) */
#define SEL_NEGATIVE   0x03000000

/* Rotate RGB, as specified in the lowest byte (000000XX): 0 = left, 1 = right */
#define SEL_ROTATERGB  0x04000000

/****************************************************************************/

/* Per icon local options for IconControlA() */

/* Get the icon rendering masks (PLANEPTR) */
#define ICONCTRLA_GetImageMask1             (ICONA_Dummy+14)
#define ICONCTRLA_GetImageMask2             (ICONA_Dummy+15)

/* Transparent image color; set to -1 if opaque */
#define ICONCTRLA_SetTransparentColor1      (ICONA_Dummy+16)
#define ICONCTRLA_GetTransparentColor1      (ICONA_Dummy+17)
#define ICONCTRLA_SetTransparentColor2      (ICONA_Dummy+18)
#define ICONCTRLA_GetTransparentColor2      (ICONA_Dummy+19)

/* Image color palette (struct ColorRegister *) */
#define ICONCTRLA_SetPalette1               (ICONA_Dummy+20)
#define ICONCTRLA_GetPalette1               (ICONA_Dummy+21)
#define ICONCTRLA_SetPalette2               (ICONA_Dummy+22)
#define ICONCTRLA_GetPalette2               (ICONA_Dummy+23)

/* Size of image color palette (LONG) */
#define ICONCTRLA_SetPaletteSize1           (ICONA_Dummy+24)
#define ICONCTRLA_GetPaletteSize1           (ICONA_Dummy+25)
#define ICONCTRLA_SetPaletteSize2           (ICONA_Dummy+26)
#define ICONCTRLA_GetPaletteSize2           (ICONA_Dummy+27)

/* Image data; one by per pixel (UBYTE *) */
#define ICONCTRLA_SetImageData1             (ICONA_Dummy+28)
#define ICONCTRLA_GetImageData1             (ICONA_Dummy+29)
#define ICONCTRLA_SetImageData2             (ICONA_Dummy+30)
#define ICONCTRLA_GetImageData2             (ICONA_Dummy+31)

/* Render image without frame (BOOL) */
#define ICONCTRLA_SetFrameless              (ICONA_Dummy+32)
#define ICONCTRLA_GetFrameless              (ICONA_Dummy+33)

/* Enable NewIcons support (BOOL) */
#define ICONCTRLA_SetNewIconsSupport        (ICONA_Dummy+34)
#define ICONCTRLA_GetNewIconsSupport        (ICONA_Dummy+35)

/* Icon aspect ratio (UBYTE *) */
#define ICONCTRLA_SetAspectRatio            (ICONA_Dummy+36)
#define ICONCTRLA_GetAspectRatio            (ICONA_Dummy+37)

/* Icon dimensions; valid only for palette mapped icon images (LONG) */
#define ICONCTRLA_SetWidth                  (ICONA_Dummy+38)
#define ICONCTRLA_GetWidth                  (ICONA_Dummy+39)
#define ICONCTRLA_SetHeight                 (ICONA_Dummy+40)
#define ICONCTRLA_GetHeight                 (ICONA_Dummy+41)

/* Check whether the icon is palette mapped (LONG *). */
#define ICONCTRLA_IsPaletteMapped           (ICONA_Dummy+42)

/* Get the screen the icon is attached to (struct Screen **). */
#define ICONCTRLA_GetScreen                 (ICONA_Dummy+43)

/* Check whether the icon has a real select image (LONG *). */
#define ICONCTRLA_HasRealImage2             (ICONA_Dummy+44)

/* Check whether the icon is of the NewIcon type (LONG *). */
#define ICONCTRLA_IsNewIcon                 (ICONA_Dummy+79)

/* Check whether this icon was allocated by icon.library
 * or if consists solely of a statically allocated
 * struct DiskObject. (LONG *).
 */
#define ICONCTRLA_IsNativeIcon              (ICONA_Dummy+80)

/* Alias for ICONGETA_UseFriendBitMap (BOOL). (V50) */
#define ICONCTRLA_UseFriendBitMap           ICONGETA_UseFriendBitMap

/* Get the bitmaps of the icon (struct BitMap *). Can be
 * NULL, only valid after an icon has been layouted. (V50)
 */
#define ICONCTRLA_GetBitMap1                (ICONA_Dummy+91)
#define ICONCTRLA_GetBitMap2                (ICONA_Dummy+92)

/* Format of icon image data (supersedes ICONCTRLA_IsPaletteMapped).
 * The possible values are listed below (ULONG). (V51)
 */
#define ICONCTRLA_SetImageDataFormat        (ICONA_Dummy+103)
#define ICONCTRLA_GetImageDataFormat        (ICONA_Dummy+104)

/* The module-specific data for an icon. Only for private use by
 * icon loader/saver modules (APTR). (V51)
 */
#define ICONCTRLA_SetIconModuleData         (ICONA_Dummy+105)
#define ICONCTRLA_GetIconModuleData         (ICONA_Dummy+106)

/* Get the format of the file an icon was loaded from. If the icon
 * is not recognized by icon.library nor by any of the icon modules
 * an error will be returned, otherwise a pointer to a read-only
 * string with the file format name (STRPTR *). (V51)
 */
#define ICONCTRLA_GetIconFileFormat         (ICONA_Dummy+111)

/* Generate a scaled version of the icon's imagery. Pass the requested
 * width and height as two UWORDs packed in a single ULONG; you can
 * specify exact sizes or a percentage of the normal sizes by using the
 * ICONSIZE() or ICONSCALE() macros defined below. The scaled imagery
 * will be cached in order to speed up any subsequent DrawIconStateA()
 * calls; you can get rid of it (and free all of its memory) with the
 * ICONCTRLA_RemScaledSize tag. Note: the scaled imagery will reflect
 * the icon's appearance at the time it is generated. It will also be
 * updated after each icon layout, which may be time-consuming if the
 * icon has many scaled sizes attached. Therefore, it is advised you
 * remove any existing scaled size via ICONCTRLA_RemScaledSize as soon
 * as it is no longer needed (ULONG). (V51)
 */
#define ICONCTRLA_AddScaledSize             (ICONA_Dummy+115)

/* Remove a particular scaled version of the icon's imagery, and free
 * all memory associated with it. You should specify the size as two
 * UWORDs (width and height) packed in a single ULONG, just like for
 * the ICONCTRLA_AddScaledSize tag (ULONG). (V51)
 */
#define ICONCTRLA_RemScaledSize             (ICONA_Dummy+116)

/* Alias for ICONGETA_IsDefaultIcon (LONG). */
#define ICONCTRLA_IsDefaultIcon             ICONGETA_IsDefaultIcon

/****************************************************************************/

/* Use these macros to pack width and height values or percentages in a single
 * ULONG, for use with ICONCTRLA_AddScaledSize and ICONCTRLA_RemScaledSize.
 */
#define ICONSIZE(width,height)  ((((UWORD)(width)) << 16) | ((UWORD)(height)))

#define ICONSCALE(xp,yp) ((((UWORD)(0x8000U | ((xp) & 0x7FFFU))) << 16) | \
                           ((UWORD)(0x8000U | ((yp) & 0x7FFFU))))

/****************************************************************************/

/* Icon aspect ratio is not known. */
#define ICON_ASPECT_RATIO_UNKNOWN (0)

/* Pack the aspect ratio into a single byte. */
#define PACK_ICON_ASPECT_RATIO(num,den) (((num) << 4) | (den))

/* Unpack the aspect ratio stored in a single byte. */
#define UNPACK_ICON_ASPECT_RATIO(v,num,den) \
    do                                      \
    {                                       \
        num = (((v) >> 4) & 15);            \
        den = ( (v)       & 15);            \
    }                                       \
    while(0)

/****************************************************************************/

/* Values for ICONCTRLA_Set/GetImageDataFormat */

#define IDFMT_BITMAPPED     (0)  /* Bitmapped icon (planar, legacy) */
#define IDFMT_PALETTEMAPPED (1)  /* Palette mapped icon (chunky, V44+) */
#define IDFMT_DIRECTMAPPED  (2)  /* Direct mapped icon (truecolor, V51+) */

/****************************************************************************/

/* Tags for use with GetIconTagList() */

/* Default icon type to retrieve (LONG) */
#define ICONGETA_GetDefaultType             (ICONA_Dummy+45)

/* Retrieve default icon for the given name (STRPTR) */
#define ICONGETA_GetDefaultName             (ICONA_Dummy+46)

/* Return a default icon if the requested icon
 * file cannot be found (BOOL).
 */
#define ICONGETA_FailIfUnavailable          (ICONA_Dummy+47)

/* If possible, retrieve a palette mapped icon (BOOL). */
#define ICONGETA_GetPaletteMappedIcon       (ICONA_Dummy+48)

/* Set if the icon returned is a default icon (BOOL *). */
#define ICONGETA_IsDefaultIcon              (ICONA_Dummy+49)

/* Remap the icon to the default screen, if possible (BOOL). */
#define ICONGETA_RemapIcon                  (ICONA_Dummy+50)

/* Generate icon image masks (BOOL). */
#define ICONGETA_GenerateImageMasks         (ICONA_Dummy+51)

/* Label text to be assigned to the icon (STRPTR). */
#define ICONGETA_Label                      (ICONA_Dummy+52)

/* Screen to remap the icon to (struct Screen *). */
#define ICONGETA_Screen                     (ICONA_Dummy+69)

/* Allocate a bitmap for the icon images instead of
 * the traditional planar icon images (BOOL). (V50)
 */
#define ICONGETA_UseFriendBitMap            (ICONA_Dummy+90)

/* Returns the format of the file the icon is loaded from.
 * If the file is in native Amiga format, the returned name
 * will be "Amiga" (STRPTR *). (V51)
 */
#define ICONGETA_FileFormat                 (ICONA_Dummy+112)

/* Request a specific size for the icon to be loaded. If the
 * icon is supplied by an external loader module which supports
 * scaling (e.g. a vector icon loader) the result will be an
 * icon of the requested size. Otherwise, the requested size
 * will be ignored, unless you also pass ICONGETA_ForceScaling
 * with a TRUE value, in which case icon.library will perform
 * a manual bitmap rescaling of the icon's imagery in order
 * to satisfy the request. You can request an exact size, or
 * a percentage of the original size with the SIZEPERC() macro
 * defined below. If you pass -1 (~0UL) for the width, and are
 * also requesting a specific height with ICONGETA_Height (or
 * vice versa), the new size will be calculated so that the
 * original icon's aspect ratio is preserved.
 *
 * Note: once rescaled by icon.library, the original icon image
 * data is lost, and the scaled imagery will be saved the next
 * time the icon is written back do disk. If you need a scaled
 * version of the icon's imagery for rendering purposes only,
 * you might prefer to use ICONDRAWA_Width and ICONDRAWA_Height
 * with DrawIconStateA() instead, which won't affect the normal
 * image data.
 *
 * The default value for both tags is zero, which means not to
 * change the original size on that axis (UWORD). (V51)
 */
#define ICONGETA_Width                      (ICONA_Dummy+117)
#define ICONGETA_Height                     (ICONA_Dummy+118)

/* Tell icon.library to perform a manual bitmap rescaling of
 * the loaded icon if it doesn't already have the size which
 * was requested with ICONGETA_Width and ICONGETA_Height.
 * Defaults to FALSE (BOOL). (V51)
 */
#define ICONGETA_ForceScaling               (ICONA_Dummy+120)

/* Request the type of the actual file whose icon is being loaded
 * by GetIconTagList(), as determined by the global identification
 * hook. If this tag is passed, the file is identified even if it
 * has a real icon. The value of this tag must be a pointer to a
 * text buffer of at least 256 bytes, or NULL (which is ignored).
 * This tag only works with actual files (tools and projects), not
 * volumes, directories or trashcans.
 * If the file cannot get identified, the supplied buffer will
 * contain an empty string (a single NUL byte) on the function's
 * return. Defaults to NULL (STRPTR). (V52)
 */
#define ICONGETA_IdentifyBuffer             (ICONA_Dummy+122)

/* When using ICONGETA_IdentifyBuffer, you can ask not to actually
 * load an icon, but just identify the file with the specified name
 * (which is quicker if all you need is the file type, and doesn't
 * require you to free an icon afterwards). If you pass this tag
 * with a TRUE value, GetIconTagList() will return NULL with a zero
 * error code in ICONA_ErrorCode. Note: this tag will be ignored if
 * a valid buffer is not also passed with ICONGETA_IdentifyBuffer.
 * Defaults to FALSE (BOOL). (V52)
 */
#define ICONGETA_IdentifyOnly               (ICONA_Dummy+123)

/* Specify the size limits for the icon to be loaded. It will
 * never end up being larger than the maximum width and height,
 * nor smaller than the minimum width and height (unless it's
 * already smaller than that at its original size, in which
 * case the original size will also become the minimum size).
 * If the icon's size (either original, or requested via the
 * ICONGETA_Width/ICONGETA_Height tags) doesn't respect the
 * specified bounds, the icon image will be scaled up or down
 * accordingly; the expected aspect ratio will be preserved
 * whenever possible.
 * The default value is NULL, which means 8x8 for the minimum
 * width/height and 256x256 for the maximum width/height.
 * The bounds are passed as a Rectangle structure with the
 * minimum sizes in MinX and MinY, and the maximum sizes in
 * MaxX and MaxY (struct Rectangle *). (V53)
 */
#define ICONGETA_SizeBounds                 (ICONA_Dummy+124)

/* Tell icon.library to enforce the minimum size specified with
 * ICONGETA_SizeBounds even when the icon's original size is
 * already smaller than that. This means the icon image may be
 * made larger even if no upscaling was explicitly requested.
 * By default this doesn't happen as icon images designed for a
 * certain size don't usually look very good if scaled up.
 * Defaults to FALSE (BOOL). (V53)
 */
#define ICONGETA_AllowUpscaling             (ICONA_Dummy+126)

/****************************************************************************/

/* Use this macro to pass a percentage to ICONGETA_Width, ICONGETA_Height,
 * ICONDRAWA_Width or ICONDRAWA_Height. Example: SIZEPERC(44) will yield
 * a 44% size (smaller); SIZEPERC(210) a 210% size (larger).
 */
#define SIZEPERC(percentage) (0x8000U | ((percentage) & 0x7FFFU))

/****************************************************************************/

/* Tags for use with PutIconTagList() */

/* Notify Workbench of the icon being written (BOOL) */
#define ICONPUTA_NotifyWorkbench            (ICONA_Dummy+53)

/* Store icon as the default for this type (LONG) */
#define ICONPUTA_PutDefaultType             (ICONA_Dummy+54)

/* Store icon as a default for the given name (STRPTR) */
#define ICONPUTA_PutDefaultName             (ICONA_Dummy+55)

/* When storing a palette mapped icon, don't save the
 * the original planar icon image with the file. Replace
 * it with a tiny replacement image.
 */
#define ICONPUTA_DropPlanarIconImage        (ICONA_Dummy+56)

/* Don't write the chunky icon image data to disk. */
#define ICONPUTA_DropChunkyIconImage        (ICONA_Dummy+57)

/* Don't write the NewIcons tool types to disk. */
#define ICONPUTA_DropNewIconToolTypes       (ICONA_Dummy+58)

/* If this tag is enabled, the writer will examine the
 * icon image data to find out whether it can compress
 * it more efficiently. This may take extra time and
 * is not generally recommended.
 */
#define ICONPUTA_OptimizeImageSpace         (ICONA_Dummy+59)

/* Don't write the entire icon file back to disk,
 * only change the do->do_CurrentX/do->do_CurrentY
 * members.
 */
#define ICONPUTA_OnlyUpdatePosition         (ICONA_Dummy+72)

/* Before writing a palette mapped icon back to disk,
 * icon.library will make sure that the original
 * planar image data is stored in the file. If you
 * don't want that to happen, set this option to
 * FALSE. This will allow you to change the planar icon
 * image data written back to disk.
 */
#define ICONPUTA_PreserveOldIconImages      (ICONA_Dummy+84)

/* Tell icon.library what file format the icon should be
 * saved in, by passing the name of a file format which
 * is supported by some external icon saver module.
 * If an icon saver module for the requested file format
 * is not found, or if it fails to save the icon in that
 * format, the icon will be saved in native Amiga format,
 * unless ICONPUTA_NoFallback is TRUE.
 * You can pass NULL to request the same format of the
 * file the icon was originally loaded from, or ~0UL to
 * explicitly request the native Amiga format. Defaults
 * to NULL (STRPTR). (V51)
 */
#define ICONPUTA_FileFormat                 (ICONA_Dummy+107)

/* Tell icon.library to fail if the icon cannot be saved
 * in the requested file format, rather than falling back
 * to saving it in native Amiga format. This tag is ignored
 * if the requested file format is the native Amiga format.
 * Defaults to FALSE (BOOL). (V51)
 */
#define ICONPUTA_NoFallback                 (ICONA_Dummy+108)

/****************************************************************************/

/* For use with the file identification hook. */

struct IconIdentifyMsg
{
    /* Libraries that are already opened for your use. */
    struct Library *       iim_SysBase;
    struct Library *       iim_DOSBase;
    struct Library *       iim_UtilityBase;
    struct Library *       iim_IconBase;

    /* File context information. */
    BPTR                   iim_FileLock;   /* Lock on the object to return an
                                            * icon for. */
    BPTR                   iim_ParentLock; /* Lock on the object's parent
                                            * directory, if available. */
    struct FileInfoBlock * iim_FIB;        /* Deprecated FileInfoBlock, Use
                                            * iim_ExData from V54.3+.
                                            */
    BPTR                   iim_FileHandle; /* If non-NULL, pointer to the file
                                            * to examine, positioned right at
                                            * the first byte, ready for you
                                            * to use.
                                            */
    struct TagItem *       iim_Tags;       /* Tags passed to
                                            * GetIconTagList().
                                            */
    /* Interfaces that are already opened for your use */
    struct ExecIFace *     iim_IExec;
    struct DOSIFace *      iim_IDOS;
    struct UtilityIFace *  iim_IUtility;
    struct IconIFace *     iim_IIcon;

	/* New in V54.3. */
	uint32                 iim_Length; /* Size of this structure. */
	struct ExamineData *   iim_ExData; /* Already initialized for you. */
};

/****************************************************************************/

/* Tags for use with DupDiskObjectA() */

/* Duplicate do_DrawerData (BOOL). */
#define ICONDUPA_DuplicateDrawerData        (ICONA_Dummy+60)

/* Duplicate the Image structures (BOOL). */
#define ICONDUPA_DuplicateImages            (ICONA_Dummy+61)

/* Duplicate the image data (Image->ImageData) itself (BOOL). */
#define ICONDUPA_DuplicateImageData         (ICONA_Dummy+62)

/* Duplicate the default tool (BOOL). */
#define ICONDUPA_DuplicateDefaultTool       (ICONA_Dummy+63)

/* Duplicate the tool types list (BOOL). */
#define ICONDUPA_DuplicateToolTypes         (ICONA_Dummy+64)

/* Duplicate the tool window (BOOL). */
#define ICONDUPA_DuplicateToolWindow        (ICONA_Dummy+65)

/* If the icon to be duplicated is in fact a palette mapped icon
 * which has never been set up to be displayed on the screen,
 * turn the duplicate into that palette mapped icon (BOOL).
 */
#define ICONDUPA_ActivateImageData          (ICONA_Dummy+82)

/* Alias for ICONGETA_UseFriendBitMap (BOOL). (V50) */
#define ICONDUPA_UseFriendBitMap            ICONGETA_UseFriendBitMap

/* Duplicate any scaled versions of the icon's imagery (BOOL). (V51) */
#define ICONDUPA_DuplicateScaledSizes       (ICONA_Dummy+119)

/* Request a specific size for the icon to be duplicated. If the
 * icon was supplied by an external loader module which supports
 * scaling (e.g. a vector icon loader) the result will be a new
 * icon of the requested size. Otherwise, the requested size
 * will be ignored, unless you also pass ICONDUPA_ForceScaling
 * with a TRUE value, in which case icon.library will perform
 * a manual bitmap rescaling of the icon's imagery in order
 * to satisfy the request. You can request an exact size, or
 * a percentage of the original size with the SIZEPERC() macro
 * defined below. If you pass -1 (~0UL) for the width, and are
 * also requesting a specific height with ICONDUPA_Height (or
 * vice versa), the size of the duplicate will be calculated so
 * that the original icon's aspect ratio is preserved.
 *
 * The default value for both tags is zero, which means not to
 * change the original size on that axis (UWORD). (V51)
 */
#define ICONDUPA_Width                      ICONGETA_Width
#define ICONDUPA_Height                     ICONGETA_Height

/* Tell icon.library to perform a manual bitmap rescaling of
 * the duplicate icon if it doesn't already have the size which
 * was requested with ICONDUPA_Width and ICONDUPA_Height.
 * Defaults to FALSE (BOOL). (V51)
 */
#define ICONDUPA_ForceScaling               ICONGETA_ForceScaling

/* Specify the size limits for the icon to be duplicated. It will
 * never end up being larger than the maximum width and height,
 * nor smaller than the minimum width and height (unless it's
 * already smaller than that at its original size, in which
 * case the original size will also become the minimum size).
 * If the icon's size (either original, or requested via the
 * ICONDUPA_Width/ICONDUPA_Height tags) doesn't respect the
 * specified bounds, the icon image will be scaled up or down
 * accordingly; the expected aspect ratio will be preserved
 * whenever possible.
 * The default value is NULL, which means 8x8 for the minimum
 * width/height and 256x256 for the maximum width/height.
 * The bounds are passed as a Rectangle structure with the
 * minimum sizes in MinX and MinY, and the maximum sizes in
 * MaxX and MaxY (struct Rectangle *). (V53)
 */
#define ICONDUPA_SizeBounds                 ICONGETA_SizeBounds

/* Tell icon.library to enforce the minimum size specified with
 * ICONDUPA_SizeBounds even when the icon's original size is
 * already smaller than that. This means the icon image may be
 * made larger even if no upscaling was explicitly requested.
 * By default this doesn't happen as icon images designed for a
 * certain size don't usually look very good if scaled up.
 * Defaults to FALSE (BOOL). (V53)
 */
#define ICONDUPA_AllowUpscaling             ICONGETA_AllowUpscaling

/****************************************************************************/

/* Tags for use with LayoutIconA() */

/* Alias for ICONGETA_UseFriendBitMap (BOOL). (V50) */
#define ICONLAYA_UseFriendBitMap            ICONGETA_UseFriendBitMap

/****************************************************************************/

/* Tags for use with DrawIconStateA() and GetIconRectangleA(). */

/* Drawing information to use (struct DrawInfo *). */
#define ICONDRAWA_DrawInfo                  (ICONA_Dummy+66)

/* Draw the icon without the surrounding frame (BOOL). */
#define ICONDRAWA_Frameless                 (ICONA_Dummy+70)

/* Erase the background before drawing a frameless icon (BOOL). */
#define ICONDRAWA_EraseBackground           (ICONA_Dummy+71)

/* Draw the icon without the surrounding border and frame (BOOL). */
#define ICONDRAWA_Borderless                (ICONA_Dummy+83)

/* The icon to be drawn refers to a linked object (BOOL). */
#define ICONDRAWA_IsLink                    (ICONA_Dummy+89)

/* Draw the icon label with shadow (BOOL). (V50) */
#define ICONDRAWA_LabelShadow               (ICONA_Dummy+93)

/* Draw the icon label with outline (BOOL). (V50) */
#define ICONDRAWA_LabelOutline              (ICONA_Dummy+94)

/* Special properties of the icon to be drawn (ULONG). (V51) */
#define ICONDRAWA_Properties                (ICONA_Dummy+95)

/* Draw the actual icon image. Defaults to TRUE (BOOL). (V51) */
#define ICONDRAWA_DrawIcon                  (ICONA_Dummy+98)

/* Erase the background before drawing an icon label (BOOL). (V51) */
#define ICONDRAWA_EraseLabelBackground      (ICONA_Dummy+101)

/* Override the transparency value which is used for drawing the
 * icon image in range from 0 to 255 (opaque) (LONG). (V51)
 */
#define ICONDRAWA_Transparency              (ICONA_Dummy+102)

/* Specify a size for the icon to be drawn. The first time a
 * particular size is requested, a scaled version of the icon's
 * imagery is generated and cached, in order to speed up any
 * subsequent redraws. When you no longer need to draw the icon
 * at that size, you can dispose of the cached scaled size via
 * IconControlA(), with ICONCTRLA_RemScaledSize.
 * You can specify an exact width or height, or a percentage of
 * the normal icon size with the SIZEPERC() macro defined above;
 * if you pass -1 (~0UL) for the width, and are also requesting
 * a specific height with ICONDRAWA_Height (or vice versa), the
 * new size will be calculated so that the normal icon's aspect
 * ratio is preserved.
 * See also ICONGETA_Width and ICONGETA_Height, which these
 * two tags are an alias of.
 * The default value for both tags is zero, which means not to
 * change the original size on that axis (UWORD). (V51)
 */
#define ICONDRAWA_Width                     ICONGETA_Width
#define ICONDRAWA_Height                    ICONGETA_Height

/* Specify the size limits for the icon to be drawn. It will
 * never be drawn larger than the maximum width and height,
 * nor smaller than the minimum width and height (unless it's
 * already smaller than that at its original size, in which
 * case the original size will also become the minimum size).
 * If the icon's size (either original, or requested via the
 * ICONDRAWA_Width/ICONDRAWA_Height tags) doesn't respect the
 * specified bounds, the icon image will be scaled up or down
 * accordingly; the expected aspect ratio will be preserved
 * whenever possible.
 * The default value is NULL, which means 8x8 for the minimum
 * width/height and 256x256 for the maximum width/height.
 * The bounds are passed as a Rectangle structure with the
 * minimum sizes in MinX and MinY, and the maximum sizes in
 * MaxX and MaxY (struct Rectangle *). (V53)
 */
#define ICONDRAWA_SizeBounds                ICONGETA_SizeBounds

/* Tell icon.library to enforce the minimum size specified with
 * ICONDRAWA_SizeBounds even when the icon's original size is
 * already smaller than that. This means the icon image may be
 * made larger even if no upscaling was explicitly requested.
 * By default this doesn't happen as icon images designed for a
 * certain size don't usually look very good if scaled up.
 * Defaults to FALSE (BOOL). (V53)
 */
#define ICONDRAWA_AllowUpscaling            ICONGETA_AllowUpscaling

/* Specify the size of the (possibly invisible) borders
 * around the icon to be drawn. Overrides the border sizes
 * set via ICONCTRLA_SetGlobalEmbossRect for this single
 * DrawIconStateA() or GetIconRectangleA() call. Pass the
 * pointer to a Rectangle structure, with MinX and MinY
 * (left and top borders) being negative values in the
 * range [-255..-1] and MaxX and MaxY (right and bottom
 * borders) being positive values in the range [1..255].
 * The default value is NULL, which means the global icon
 * border sizes should be used (struct Rectangle *). (V53)
 */
#define ICONDRAWA_Borders                   (ICONA_Dummy+125)

/****************************************************************************/

/* Property flags for ICONDRAWA_Properties */

#define ICON_DRAGGED   0x00000001  /* Icon is being dragged       */
#define ICON_DROPPABLE 0x00000002  /* Icon is over a drop area    */
#define ICON_LEFTOUT   0x00000004  /* Icon has been "left out"    */
#define ICON_POINTED   0x00000008  /* Icon is under mouse pointer */

/****************************************************************************/

/* Reserved tags; don't use! */
#define ICONA_Reserved1                     (ICONA_Dummy+73)
#define ICONA_Reserved2                     (ICONA_Dummy+74)
#define ICONA_Reserved3                     (ICONA_Dummy+76)
#define ICONA_Reserved4                     (ICONA_Dummy+81)
#define ICONA_Reserved5                     (ICONA_Dummy+85)
#define ICONA_Reserved6                     (ICONA_Dummy+86)
#define ICONA_Reserved7                     (ICONA_Dummy+87)
#define ICONA_Reserved8                     (ICONA_Dummy+88)
#define ICONA_Reserved9                     (ICONA_Dummy+99)
#define ICONA_Reserved10                    (ICONA_Dummy+100)
#define ICONA_Reserved11                    (ICONA_Dummy+109)
#define ICONA_Reserved12                    (ICONA_Dummy+110)
#define ICONA_Reserved13                    (ICONA_Dummy+121)

/****************************************************************************/

#define ICONA_LAST_TAG                      (ICONA_Dummy+126)

/****************************************************************************/

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

#endif /* WORKBENCH_ICON_H */
