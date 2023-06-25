#ifndef GRAPHICS_BOARD_H
#define GRAPHICS_BOARD_H
/*
**    $VER: board.h 54.16 (22.08.2022)
**
**    graphics board definitions
**
**    Copyright (c) 2014 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

#define GBD_TagBase                (TAG_USER)

#define GBD_BoardName              (GBD_TagBase + 1)
#define GBD_TotalMemory            (GBD_TagBase + 2)
#define GBD_FreeMemory             (GBD_TagBase + 3)
#define GBD_LargestFreeMemory      (GBD_TagBase + 4)
#define GBD_InternalMemorySize     (GBD_TagBase + 5)
#define GBD_PCIVendorID            (GBD_TagBase + 6)
#define GBD_PCIProductID           (GBD_TagBase + 7)
#define GBD_BoardDriver            (GBD_TagBase + 8)
#define GBD_ChipDriver             (GBD_TagBase + 9)
#define GBD_FreeInternalMemorySize (GBD_TagBase + 10)

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

#endif /* GRAPHICS_BOARD_H */
