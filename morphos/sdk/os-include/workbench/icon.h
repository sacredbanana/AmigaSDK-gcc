#ifndef WORKBENCH_ICON_H
#define WORKBENCH_ICON_H

/*
	icon.library external declarations

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef GRAPHICS_VIEW_H
# include <graphics/view.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
# include <intuition/imageclass.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DATATYPES_PICTURECLASS_H
# include <datatypes/pictureclass.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


#define ICONNAME  "icon.library"


/*** V44 ***/


#define ICONA_Dummy                          (TAG_USER + 0x9000)
#define ICONA_ErrorCode                      (ICONA_Dummy + 1)

#define ICONCTRLA_SetGlobalScreen            (ICONA_Dummy + 2)
#define ICONCTRLA_GetGlobalScreen            (ICONA_Dummy + 3)

#define ICONCTRLA_SetGlobalPrecision         (ICONA_Dummy + 4)
#define ICONCTRLA_GetGlobalPrecision         (ICONA_Dummy + 5)

#define ICONCTRLA_SetGlobalEmbossRect        (ICONA_Dummy + 6)
#define ICONCTRLA_GetGlobalEmbossRect        (ICONA_Dummy + 7)

#define ICONCTRLA_SetGlobalFrameless         (ICONA_Dummy + 8)
#define ICONCTRLA_GetGlobalFrameless         (ICONA_Dummy + 9)

#define ICONCTRLA_SetGlobalNewIconsSupport   (ICONA_Dummy + 10)
#define ICONCTRLA_GetGlobalNewIconsSupport   (ICONA_Dummy + 11)

#define ICONCTRLA_SetGlobalIdentifyHook      (ICONA_Dummy + 12)
#define ICONCTRLA_GetGlobalIdentifyHook      (ICONA_Dummy + 13)

#define ICONCTRLA_GetImageMask1              (ICONA_Dummy + 14)
#define ICONCTRLA_GetImageMask2              (ICONA_Dummy + 15)

#define ICONCTRLA_SetTransparentColor1       (ICONA_Dummy + 16)
#define ICONCTRLA_GetTransparentColor1       (ICONA_Dummy + 17)
#define ICONCTRLA_SetTransparentColor2       (ICONA_Dummy + 18)
#define ICONCTRLA_GetTransparentColor2       (ICONA_Dummy + 19)

#define ICONCTRLA_SetPalette1                (ICONA_Dummy + 20)
#define ICONCTRLA_GetPalette1                (ICONA_Dummy + 21)
#define ICONCTRLA_SetPalette2                (ICONA_Dummy + 22)
#define ICONCTRLA_GetPalette2                (ICONA_Dummy + 23)

#define ICONCTRLA_SetPaletteSize1            (ICONA_Dummy + 24)
#define ICONCTRLA_GetPaletteSize1            (ICONA_Dummy + 25)
#define ICONCTRLA_SetPaletteSize2            (ICONA_Dummy + 26)
#define ICONCTRLA_GetPaletteSize2            (ICONA_Dummy + 27)

#define ICONCTRLA_SetImageData1              (ICONA_Dummy + 28)
#define ICONCTRLA_GetImageData1              (ICONA_Dummy + 29)
#define ICONCTRLA_SetImageData2              (ICONA_Dummy + 30)
#define ICONCTRLA_GetImageData2              (ICONA_Dummy + 31)

#define ICONCTRLA_SetFrameless               (ICONA_Dummy + 32)
#define ICONCTRLA_GetFrameless               (ICONA_Dummy + 33)

#define ICONCTRLA_SetNewIconsSupport         (ICONA_Dummy + 34)
#define ICONCTRLA_GetNewIconsSupport         (ICONA_Dummy + 35)

#define ICONCTRLA_SetAspectRatio             (ICONA_Dummy + 36)
#define ICONCTRLA_GetAspectRatio             (ICONA_Dummy + 37)

#define ICONCTRLA_SetWidth                   (ICONA_Dummy + 38)
#define ICONCTRLA_GetWidth                   (ICONA_Dummy + 39)
#define ICONCTRLA_SetHeight                  (ICONA_Dummy + 40)
#define ICONCTRLA_GetHeight                  (ICONA_Dummy + 41)

#define ICONCTRLA_IsPaletteMapped            (ICONA_Dummy + 42)
#define ICONCTRLA_GetScreen                  (ICONA_Dummy + 43)
#define ICONCTRLA_HasRealImage2              (ICONA_Dummy + 44)

#define ICONGETA_GetDefaultType              (ICONA_Dummy + 45)
#define ICONGETA_GetDefaultName              (ICONA_Dummy + 46)

#define ICONGETA_FailIfUnavailable           (ICONA_Dummy + 47)
#define ICONGETA_GetPaletteMappedIcon        (ICONA_Dummy + 48)
#define ICONGETA_IsDefaultIcon               (ICONA_Dummy + 49)
#define ICONGETA_RemapIcon                   (ICONA_Dummy + 50)
#define ICONGETA_GenerateImageMasks          (ICONA_Dummy + 51)
#define ICONGETA_Label                       (ICONA_Dummy + 52)

#define ICONPUTA_NotifyWorkbench             (ICONA_Dummy + 53)
#define ICONPUTA_PutDefaultType              (ICONA_Dummy + 54)
#define ICONPUTA_PutDefaultName              (ICONA_Dummy + 55)
#define ICONPUTA_DropPlanarIconImage         (ICONA_Dummy + 56)
#define ICONPUTA_DropChunkyIconImage         (ICONA_Dummy + 57)
#define ICONPUTA_DropNewIconToolTypes        (ICONA_Dummy + 58)
#define ICONPUTA_OptimizeImageSpace          (ICONA_Dummy + 59)

#define ICONDUPA_DuplicateDrawerData         (ICONA_Dummy + 60)
#define ICONDUPA_DuplicateImages             (ICONA_Dummy + 61)
#define ICONDUPA_DuplicateImageData          (ICONA_Dummy + 62)
#define ICONDUPA_DuplicateDefaultTool        (ICONA_Dummy + 63)
#define ICONDUPA_DuplicateToolTypes          (ICONA_Dummy + 64)
#define ICONDUPA_DuplicateToolWindow         (ICONA_Dummy + 65)

#define ICONDRAWA_DrawInfo                   (ICONA_Dummy + 66)

#define ICONCTRLA_SetGlobalMaxNameLength     (ICONA_Dummy + 67)
#define ICONCTRLA_GetGlobalMaxNameLength     (ICONA_Dummy + 68)

#define ICONGETA_Screen                      (ICONA_Dummy + 69)

#define ICONDRAWA_Frameless                  (ICONA_Dummy + 70)
#define ICONDRAWA_EraseBackground            (ICONA_Dummy + 71)

#define ICONPUTA_OnlyUpdatePosition          (ICONA_Dummy + 72)

#define ICONA_Reserved1                      (ICONA_Dummy + 73)
#define ICONA_Reserved2                      (ICONA_Dummy + 74)

#define ICONA_ErrorTagItem                   (ICONA_Dummy + 75)

#define ICONA_Reserved3                      (ICONA_Dummy + 76)

#define ICONCTRLA_SetGlobalColorIconSupport  (ICONA_Dummy + 77)
#define ICONCTRLA_GetGlobalColorIconSupport  (ICONA_Dummy + 78)

#define ICONCTRLA_IsNewIcon                  (ICONA_Dummy + 79)
#define ICONCTRLA_IsNativeIcon               (ICONA_Dummy + 80)

#define ICONA_Reserved4                      (ICONA_Dummy + 81)

#define ICONDUPA_ActivateImageData           (ICONA_Dummy + 82)

#define ICONDRAWA_Borderless                 (ICONA_Dummy + 83)

#define ICONPUTA_PreserveOldIconImages       (ICONA_Dummy + 84)

#define ICONA_Reserved5                      (ICONA_Dummy + 85)
#define ICONA_Reserved6                      (ICONA_Dummy + 86)
#define ICONA_Reserved7                      (ICONA_Dummy + 87)
#define ICONA_Reserved8                      (ICONA_Dummy + 88)

/*** V45 ***/

#define ICONDRAWA_IsLink                     (ICONA_Dummy + 89)


#define ICONA_LAST_TAG  ICONDRAWA_IsLink


#define ICON_ASPECT_RATIO_UNKNOWN (0)

#define PACK_ICON_ASPECT_RATIO(num,den)      (((num)<<4)|(den))
#define UNPACK_ICON_ASPECT_RATIO(v,num,den)  do { num = (((v)>>4)&15); den = ((v)&15); } while(0)


struct IconIdentifyMsg
{
	struct Library       *iim_SysBase;
	struct Library       *iim_DOSBase;
	struct Library       *iim_UtilityBase;
	struct Library       *iim_IconBase;

	BPTR                  iim_FileLock;
	BPTR                  iim_ParentLock;
	struct FileInfoBlock *iim_FIB;
	BPTR                  iim_FileHandle;
	struct TagItem       *iim_Tags;
};


#pragma pack()

#endif /* WORKBENCH_ICON_H */
