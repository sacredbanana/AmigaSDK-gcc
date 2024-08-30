#ifndef WORKBENCH_ICONMODULE_H
#define WORKBENCH_ICONMODULE_H

/*
**    $VER: iconmodule.h 54.16 (22.08.2022)
**
**    External declarations for generic icon module
**
**    Copyright (C) 1985-2006 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

#define IMA_Dummy                         (TAG_USER+0x440000)

/****************************************************************************/

/* Tags for all icon module functions */

/* Error reporting. (int32 *)
 */
#define IMA_ErrorCode                       (IMA_Dummy+1)

/* FreeList associated to the passed icon, use for all allocations.
 * (struct FreeList *)
 */
#define IMA_FreeList                        (IMA_Dummy+2)

/* Tag list originally passed to the calling icon.library function.
 * (struct TagItem *)
 */
#define IMA_TagList                         (IMA_Dummy+3)

/****************************************************************************/

/* Tags for LoadIconA() */

/* Returns the name of the file format of the loaded icon. (STRPTR *)
 */
#define IMA_LoadFormat                      (IMA_Dummy+4)

/* Desired width for the icon to be loaded. Only useful to modules
 * which support scaling. Don't use this value directly, but filter
 * it first through the WANTED_ICON_WIDTH() macro below. (uint16)
 */
#define IMA_Width                           (IMA_Dummy+5)

/* Desired height for the icon to be loaded. Only useful to modules
 * which support scaling. Don't use this value directly, but filter
 * it first through the WANTED_ICON_HEIGHT() macro below. (uint16)
 */
#define IMA_Height                          (IMA_Dummy+6)

/****************************************************************************/

/* Tags for SaveIconA() */

/* Name of the requested format for saving (if more than one format
 * is supported). May be NULL, which means the same format of the
 * file from which the module loaded the icon originally. (STRPTR)
 */
#define IMA_SaveFormat                      (IMA_Dummy+7)

/****************************************************************************/

/* Tags for ModuleControlA() */

/* Points to the tag item that caused the error. (struct TagItem **)
 */
#define IMA_ErrorTagItem                    (IMA_Dummy+8)

/* Returns a NULL-terminated array of single-word names for the formats
 * supported by the module. Read only! (STRPTR **)
 */
#define IMA_GetFormatNames                  (IMA_Dummy+9)

/* Returns a NULL-terminated array of short descriptions for the formats
 * supported by the module. Read only! (STRPTR **)
 */
#define IMA_GetFormatDescs                  (IMA_Dummy+10)

/* Tells the module icon.library is all set up and ready to use, and
 * passes its library base address to it. (struct Library *)
 */
#define IMA_SetIconBase                     (IMA_Dummy+11)

/* Tells the module icon.library is all set up and ready to use, and
 * passes its interface address to it. (struct IconIFace *)
 */
#define IMA_SetIconIFace                    (IMA_Dummy+12)

/* Tells the module how much additional memory (approximately) should
 * be allocated at most for each icon, to carry around data coming
 * from the original file that isn't useful for the icon itself, but
 * would be desirable to write back to the file when the icon is saved.
 * The size is expressed in bytes, and defaults to 128. (uint32)
 */
#define IMA_SetMaxUnknownDataSize           (IMA_Dummy+13)

/* Returns TRUE if the module supports loading, FALSE otherwise. (uint32 *)
 */
#define IMA_GetLoadSupport                  (IMA_Dummy+14)

/* Returns TRUE if the module supports saving, FALSE otherwise. (uint32 *)
 */
#define IMA_GetSaveSupport                  (IMA_Dummy+15)

/* Returns TRUE if the module supports scaling, FALSE otherwise. (uint32 *)
 */
#define IMA_GetScaleSupport                 (IMA_Dummy+16)

/* Returns the format of the file the icon passed as object was loaded
 * from, if it was loaded by this module. If the icon is not recognized,
 * an error code is returned via IMA_ErrorCode. (STRPTR *)
 */
#define IMA_GetFileFormat                   (IMA_Dummy+17)

/* Returns TRUE if the module supports converting a generic icon to one
 * of its supported file formats. If this is FALSE, the module will only
 * be able to save an icon to disk if the icon was originally loaded by
 * the module itself (typically because some essential format-specific
 * information, which is not carried around by normal icons, is required
 * in order to build the icon file). (uint32 *)
 */
#define IMA_GetConvertSupport               (IMA_Dummy+18)

/****************************************************************************/

#define IMA_LAST_TAG                        (IMA_Dummy+18)

/****************************************************************************/

/* Useful macros for modules supporting icon image scaling */

/* Use these macros to find out what your client actually requested for the
 * icon sizes. Pass the nominal width and height of the icon as the first
 * two parameters, and the "raw" width and height values (those coming from
 * IMA_Width and IMA_Height) as the other two parameters. Also, make sure
 * to adjust the result, if needed, to keep it within legal bounds: an icon
 * cannot be larger than 256 x 256 pixels.
 */

#define WANTED_ICON_WIDTH(nw,nh,rw,rh)                    \
   (((rw) >= 0xFFFFU) && ((rh) >= 0xFFFFU))?              \
      (nw):                                               \
      (((rw) == 0)?                                       \
         (nw):                                            \
         ((((rw) & 0x8000U) && ((rw) < 0xFFFFU))?         \
            (((nw) * ((rw) & 0x7FFFU)) / 100):            \
            (((rw) >= 0xFFFFU)?                           \
               ((((((rh) & 0x8000U) && ((rh) < 0xFFFFU))? \
                     (((nh) * ((rh) & 0x7FFFU)) / 100):   \
                     (((rh) == 0)?                        \
                        (nh):                             \
                        (rh))) * (nw)) / (nh)):           \
               (rw))))

#define WANTED_ICON_HEIGHT(nw,nh,rw,rh)                   \
   (((rw) >= 0xFFFFU) && ((rh) >= 0xFFFFU))?              \
      (nh):                                               \
      (((rh) == 0)?                                       \
         (nh):                                            \
         ((((rh) & 0x8000U) && ((rh) < 0xFFFFU))?         \
            (((nh) * ((rh) & 0x7FFFU)) / 100):            \
            (((rh) >= 0xFFFFU)?                           \
               ((((((rw) & 0x8000U) && ((rw) < 0xFFFFU))? \
                     (((nw) * ((rw) & 0x7FFFU)) / 100):   \
                     (((rw) == 0)?                        \
                        (nw):                             \
                        (rw))) * (nh)) / (nw)):           \
               (rh))))

/****************************************************************************/

/* Structure for icon scaling requests for modules implementing ScaleIcon() */

struct IconScaleRequest
{
   uint16  Version, Size;  /* Allow for future extension */
   uint16  Width, Height;  /* The requested icon size */
   uint16  State;          /* The requested icon state */
   uint16  BytesPerPixel;  /* To be filled in by the module (1 or 4) */
   uint8  *ImageBuffer;    /* To be filled in by the module (CLUT or ARGB) */
};

#define ISR_VERSION (1)  /* Our current structure version */

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

#endif /* WORKBENCH_ICONMODULE_H */
