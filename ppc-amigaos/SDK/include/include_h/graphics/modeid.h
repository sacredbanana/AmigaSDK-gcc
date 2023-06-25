#ifndef GRAPHICS_MODEID_H
#define GRAPHICS_MODEID_H
/*
**    $VER: modeid.h 54.16 (22.08.2022)
**
**    include define file for graphics display mode IDs.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   GRAPHICS_DISPLAYINFO_H
#include <graphics/displayinfo.h>
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

#define INVALID_ID ~0UL

/* With all the new modes that are available under V38 and V39, it is highly
 * recommended that you use either the asl.library screenmode requester,
 * and/or the V39 graphics.library function BestModeIDA().
 *
 * DO NOT interpret the any of the bits in the ModeID for its meaning. For
 * example, do not interpret bit 3 (0x4) as meaning the ModeID is interlaced.
 * Instead, use GetDisplayInfoData() with DTAG_DISP, and examine the DIPF_...
 * flags to determine a ModeID's characteristics. The only exception to
 * this rule is that bit 7 (0x80) will always mean the ModeID is
 * ExtraHalfBright, and bit 11 (0x800) will always mean the ModeID is HAM.
 */

/* normal identifiers */

#define MONITOR_ID_MASK               0xFFFF1000

#define DEFAULT_MONITOR_ID            0x00000000
#define NTSC_MONITOR_ID               0x00011000
#define PAL_MONITOR_ID                0x00021000

/* the following 22 composite keys are for Modes on the default Monitor.
 * NTSC & PAL "flavors" of these particular keys may be made by or'ing
 * the NTSC or PAL MONITOR_ID with the desired MODE_KEY...
 *
 * For example, to specifically open a PAL HAM interlaced ViewPort
 * (or intuition screen), you would use the modeid of
 * (PAL_MONITOR_ID | HAMLACE_KEY)
 */

#define LORES_KEY                     0x00000000
#define HIRES_KEY                     0x00008000
#define SUPER_KEY                     0x00008020
#define HAM_KEY                       0x00000800
#define LORESLACE_KEY                 0x00000004
#define HIRESLACE_KEY                 0x00008004
#define SUPERLACE_KEY                 0x00008024
#define HAMLACE_KEY                   0x00000804
#define LORESDPF_KEY                  0x00000400
#define HIRESDPF_KEY                  0x00008400
#define SUPERDPF_KEY                  0x00008420
#define LORESLACEDPF_KEY              0x00000404
#define HIRESLACEDPF_KEY              0x00008404
#define SUPERLACEDPF_KEY              0x00008424
#define LORESDPF2_KEY                 0x00000440
#define HIRESDPF2_KEY                 0x00008440
#define SUPERDPF2_KEY                 0x00008460
#define LORESLACEDPF2_KEY             0x00000444
#define HIRESLACEDPF2_KEY             0x00008444
#define SUPERLACEDPF2_KEY             0x00008464
#define EXTRAHALFBRITE_KEY            0x00000080
#define EXTRAHALFBRITELACE_KEY        0x00000084
/* New for AA ChipSet (V39) */
#define HIRESHAM_KEY                  0x00008800
#define SUPERHAM_KEY                  0x00008820
#define HIRESEHB_KEY                  0x00008080
#define SUPEREHB_KEY                  0x000080a0
#define HIRESHAMLACE_KEY              0x00008804
#define SUPERHAMLACE_KEY              0x00008824
#define HIRESEHBLACE_KEY              0x00008084
#define SUPEREHBLACE_KEY              0x000080a4
/* Added for V40 - may be useful modes for some games or animations. */
#define LORESSDBL_KEY                 0x00000008
#define LORESHAMSDBL_KEY              0x00000808
#define LORESEHBSDBL_KEY              0x00000088
#define HIRESHAMSDBL_KEY              0x00008808


/* VGA identifiers */

#define VGA_MONITOR_ID                0x00031000

#define VGAEXTRALORES_KEY             0x00031004
#define VGALORES_KEY                  0x00039004
#define VGAPRODUCT_KEY                0x00039024
#define VGAHAM_KEY                    0x00031804
#define VGAEXTRALORESLACE_KEY         0x00031005
#define VGALORESLACE_KEY              0x00039005
#define VGAPRODUCTLACE_KEY            0x00039025
#define VGAHAMLACE_KEY                0x00031805
#define VGAEXTRALORESDPF_KEY          0x00031404
#define VGALORESDPF_KEY               0x00039404
#define VGAPRODUCTDPF_KEY             0x00039424
#define VGAEXTRALORESLACEDPF_KEY      0x00031405
#define VGALORESLACEDPF_KEY           0x00039405
#define VGAPRODUCTLACEDPF_KEY         0x00039425
#define VGAEXTRALORESDPF2_KEY         0x00031444
#define VGALORESDPF2_KEY              0x00039444
#define VGAPRODUCTDPF2_KEY            0x00039464
#define VGAEXTRALORESLACEDPF2_KEY     0x00031445
#define VGALORESLACEDPF2_KEY          0x00039445
#define VGAPRODUCTLACEDPF2_KEY        0x00039465
#define VGAEXTRAHALFBRITE_KEY         0x00031084
#define VGAEXTRAHALFBRITELACE_KEY     0x00031085
/* New for AA ChipSet (V39) */
#define VGAPRODUCTHAM_KEY             0x00039824
#define VGALORESHAM_KEY               0x00039804
#define VGAEXTRALORESHAM_KEY          VGAHAM_KEY
#define VGAPRODUCTHAMLACE_KEY         0x00039825
#define VGALORESHAMLACE_KEY           0x00039805
#define VGAEXTRALORESHAMLACE_KEY      VGAHAMLACE_KEY
#define VGAEXTRALORESEHB_KEY          VGAEXTRAHALFBRITE_KEY
#define VGAEXTRALORESEHBLACE_KEY      VGAEXTRAHALFBRITELACE_KEY
#define VGALORESEHB_KEY               0x00039084
#define VGALORESEHBLACE_KEY           0x00039085
#define VGAEHB_KEY                    0x000390a4
#define VGAEHBLACE_KEY                0x000390a5
/* These ModeIDs are the scandoubled equivalents of the above, with the
 * exception of the DualPlayfield modes, as AA does not allow for scandoubling
 * dualplayfield.
 */
#define VGAEXTRALORESDBL_KEY          0x00031000
#define VGALORESDBL_KEY               0x00039000
#define VGAPRODUCTDBL_KEY             0x00039020
#define VGAEXTRALORESHAMDBL_KEY       0x00031800
#define VGALORESHAMDBL_KEY            0x00039800
#define VGAPRODUCTHAMDBL_KEY          0x00039820
#define VGAEXTRALORESEHBDBL_KEY       0x00031080
#define VGALORESEHBDBL_KEY            0x00039080
#define VGAPRODUCTEHBDBL_KEY          0x000390a0

/* a2024 identifiers */

#define A2024_MONITOR_ID              0x00041000

#define A2024TENHERTZ_KEY             0x00041000
#define A2024FIFTEENHERTZ_KEY         0x00049000

/* prototype identifiers (private) */

#define PROTO_MONITOR_ID              0x00051000


/* These monitors and modes were added for the V38 release. */

#define EURO72_MONITOR_ID             0x00061000

#define EURO72EXTRALORES_KEY          0x00061004
#define EURO72LORES_KEY               0x00069004
#define EURO72PRODUCT_KEY             0x00069024
#define EURO72HAM_KEY                 0x00061804
#define EURO72EXTRALORESLACE_KEY      0x00061005
#define EURO72LORESLACE_KEY           0x00069005
#define EURO72PRODUCTLACE_KEY         0x00069025
#define EURO72HAMLACE_KEY             0x00061805
#define EURO72EXTRALORESDPF_KEY       0x00061404
#define EURO72LORESDPF_KEY            0x00069404
#define EURO72PRODUCTDPF_KEY          0x00069424
#define EURO72EXTRALORESLACEDPF_KEY   0x00061405
#define EURO72LORESLACEDPF_KEY        0x00069405
#define EURO72PRODUCTLACEDPF_KEY      0x00069425
#define EURO72EXTRALORESDPF2_KEY      0x00061444
#define EURO72LORESDPF2_KEY           0x00069444
#define EURO72PRODUCTDPF2_KEY         0x00069464
#define EURO72EXTRALORESLACEDPF2_KEY  0x00061445
#define EURO72LORESLACEDPF2_KEY       0x00069445
#define EURO72PRODUCTLACEDPF2_KEY     0x00069465
#define EURO72EXTRAHALFBRITE_KEY      0x00061084
#define EURO72EXTRAHALFBRITELACE_KEY  0x00061085
/* New AA modes (V39) */
#define EURO72PRODUCTHAM_KEY          0x00069824
#define EURO72PRODUCTHAMLACE_KEY      0x00069825
#define EURO72LORESHAM_KEY            0x00069804
#define EURO72LORESHAMLACE_KEY        0x00069805
#define EURO72EXTRALORESHAM_KEY       EURO72HAM_KEY
#define EURO72EXTRALORESHAMLACE_KEY   EURO72HAMLACE_KEY
#define EURO72EXTRALORESEHB_KEY       EURO72EXTRAHALFBRITE_KEY
#define EURO72EXTRALORESEHBLACE_KEY   EURO72EXTRAHALFBRITELACE_KEY
#define EURO72LORESEHB_KEY            0x00069084
#define EURO72LORESEHBLACE_KEY        0x00069085
#define EURO72EHB_KEY                 0x000690a4
#define EURO72EHBLACE_KEY             0x000690a5
/* These ModeIDs are the scandoubled equivalents of the above, with the
 * exception of the DualPlayfield modes, as AA does not allow for scandoubling
 * dualplayfield.
 */
#define EURO72EXTRALORESDBL_KEY       0x00061000
#define EURO72LORESDBL_KEY            0x00069000
#define EURO72PRODUCTDBL_KEY          0x00069020
#define EURO72EXTRALORESHAMDBL_KEY    0x00061800
#define EURO72LORESHAMDBL_KEY         0x00069800
#define EURO72PRODUCTHAMDBL_KEY       0x00069820
#define EURO72EXTRALORESEHBDBL_KEY    0x00061080
#define EURO72LORESEHBDBL_KEY         0x00069080
#define EURO72PRODUCTEHBDBL_KEY       0x000690a0


#define EURO36_MONITOR_ID             0x00071000

/* Euro36 modeids can be ORed with the default modeids a la NTSC and PAL.
 * For example, Euro36 SuperHires is
 * (EURO36_MONITOR_ID | SUPER_KEY)
 */

#define SUPER72_MONITOR_ID            0x00081000

/* Super72 modeids can be ORed with the default modeids a la NTSC and PAL.
 * For example, Super72 SuperHiresLace (800x600) is
 * (SUPER72_MONITOR_ID | SUPERLACE_KEY).
 * The following scandoubled Modes are the exception:
 */
#define SUPER72LORESDBL_KEY           0x00081008
#define SUPER72HIRESDBL_KEY           0x00089008
#define SUPER72SUPERDBL_KEY           0x00089028
#define SUPER72LORESHAMDBL_KEY        0x00081808
#define SUPER72HIRESHAMDBL_KEY        0x00089808
#define SUPER72SUPERHAMDBL_KEY        0x00089828
#define SUPER72LORESEHBDBL_KEY        0x00081088
#define SUPER72HIRESEHBDBL_KEY        0x00089088
#define SUPER72SUPEREHBDBL_KEY        0x000890a8


/* These monitors and modes were added for the V39 release. */

#define DBLNTSC_MONITOR_ID            0x00091000

#define DBLNTSCLORES_KEY              0x00091000
#define DBLNTSCLORESFF_KEY            0x00091004
#define DBLNTSCLORESHAM_KEY           0x00091800
#define DBLNTSCLORESHAMFF_KEY         0x00091804
#define DBLNTSCLORESEHB_KEY           0x00091080
#define DBLNTSCLORESEHBFF_KEY         0x00091084
#define DBLNTSCLORESLACE_KEY          0x00091005
#define DBLNTSCLORESHAMLACE_KEY       0x00091805
#define DBLNTSCLORESEHBLACE_KEY       0x00091085
#define DBLNTSCLORESDPF_KEY           0x00091400
#define DBLNTSCLORESDPFFF_KEY         0x00091404
#define DBLNTSCLORESDPFLACE_KEY       0x00091405
#define DBLNTSCLORESDPF2_KEY          0x00091440
#define DBLNTSCLORESDPF2FF_KEY        0x00091444
#define DBLNTSCLORESDPF2LACE_KEY      0x00091445
#define DBLNTSCHIRES_KEY              0x00099000
#define DBLNTSCHIRESFF_KEY            0x00099004
#define DBLNTSCHIRESHAM_KEY           0x00099800
#define DBLNTSCHIRESHAMFF_KEY         0x00099804
#define DBLNTSCHIRESLACE_KEY          0x00099005
#define DBLNTSCHIRESHAMLACE_KEY       0x00099805
#define DBLNTSCHIRESEHB_KEY           0x00099080
#define DBLNTSCHIRESEHBFF_KEY         0x00099084
#define DBLNTSCHIRESEHBLACE_KEY       0x00099085
#define DBLNTSCHIRESDPF_KEY           0x00099400
#define DBLNTSCHIRESDPFFF_KEY         0x00099404
#define DBLNTSCHIRESDPFLACE_KEY       0x00099405
#define DBLNTSCHIRESDPF2_KEY          0x00099440
#define DBLNTSCHIRESDPF2FF_KEY        0x00099444
#define DBLNTSCHIRESDPF2LACE_KEY      0x00099445
#define DBLNTSCEXTRALORES_KEY         0x00091200
#define DBLNTSCEXTRALORESHAM_KEY      0x00091a00
#define DBLNTSCEXTRALORESEHB_KEY      0x00091280
#define DBLNTSCEXTRALORESDPF_KEY      0x00091600
#define DBLNTSCEXTRALORESDPF2_KEY     0x00091640
#define DBLNTSCEXTRALORESFF_KEY       0x00091204
#define DBLNTSCEXTRALORESHAMFF_KEY    0x00091a04
#define DBLNTSCEXTRALORESEHBFF_KEY    0x00091284
#define DBLNTSCEXTRALORESDPFFF_KEY    0x00091604
#define DBLNTSCEXTRALORESDPF2FF_KEY   0x00091644
#define DBLNTSCEXTRALORESLACE_KEY     0x00091205
#define DBLNTSCEXTRALORESHAMLACE_KEY  0x00091a05
#define DBLNTSCEXTRALORESEHBLACE_KEY  0x00091285
#define DBLNTSCEXTRALORESDPFLACE_KEY  0x00091605
#define DBLNTSCEXTRALORESDPF2LACE_KEY 0x00091645

#define DBLPAL_MONITOR_ID             0x000a1000

#define DBLPALLORES_KEY               0x000a1000
#define DBLPALLORESFF_KEY             0x000a1004
#define DBLPALLORESHAM_KEY            0x000a1800
#define DBLPALLORESHAMFF_KEY          0x000a1804
#define DBLPALLORESEHB_KEY            0x000a1080
#define DBLPALLORESEHBFF_KEY          0x000a1084
#define DBLPALLORESLACE_KEY           0x000a1005
#define DBLPALLORESHAMLACE_KEY        0x000a1805
#define DBLPALLORESEHBLACE_KEY        0x000a1085
#define DBLPALLORESDPF_KEY            0x000a1400
#define DBLPALLORESDPFFF_KEY          0x000a1404
#define DBLPALLORESDPFLACE_KEY        0x000a1405
#define DBLPALLORESDPF2_KEY           0x000a1440
#define DBLPALLORESDPF2FF_KEY         0x000a1444
#define DBLPALLORESDPF2LACE_KEY       0x000a1445
#define DBLPALHIRES_KEY               0x000a9000
#define DBLPALHIRESFF_KEY             0x000a9004
#define DBLPALHIRESHAM_KEY            0x000a9800
#define DBLPALHIRESHAMFF_KEY          0x000a9804
#define DBLPALHIRESLACE_KEY           0x000a9005
#define DBLPALHIRESHAMLACE_KEY        0x000a9805
#define DBLPALHIRESEHB_KEY            0x000a9080
#define DBLPALHIRESEHBFF_KEY          0x000a9084
#define DBLPALHIRESEHBLACE_KEY        0x000a9085
#define DBLPALHIRESDPF_KEY            0x000a9400
#define DBLPALHIRESDPFFF_KEY          0x000a9404
#define DBLPALHIRESDPFLACE_KEY        0x000a9405
#define DBLPALHIRESDPF2_KEY           0x000a9440
#define DBLPALHIRESDPF2FF_KEY         0x000a9444
#define DBLPALHIRESDPF2LACE_KEY       0x000a9445
#define DBLPALEXTRALORES_KEY          0x000a1200
#define DBLPALEXTRALORESHAM_KEY       0x000a1a00
#define DBLPALEXTRALORESEHB_KEY       0x000a1280
#define DBLPALEXTRALORESDPF_KEY       0x000a1600
#define DBLPALEXTRALORESDPF2_KEY      0x000a1640
#define DBLPALEXTRALORESFF_KEY        0x000a1204
#define DBLPALEXTRALORESHAMFF_KEY     0x000a1a04
#define DBLPALEXTRALORESEHBFF_KEY     0x000a1284
#define DBLPALEXTRALORESDPFFF_KEY     0x000a1604
#define DBLPALEXTRALORESDPF2FF_KEY    0x000a1644
#define DBLPALEXTRALORESLACE_KEY      0x000a1205
#define DBLPALEXTRALORESHAMLACE_KEY   0x000a1a05
#define DBLPALEXTRALORESEHBLACE_KEY   0x000a1285
#define DBLPALEXTRALORESDPFLACE_KEY   0x000a1605
#define DBLPALEXTRALORESDPF2LACE_KEY  0x000a1645


/* Use these tags for passing to BestModeID() (V39) */

#define SPECIAL_FLAGS \
    (DIPF_IS_DUALPF | DIPF_IS_PF2PRI | DIPF_IS_HAM | DIPF_IS_EXTRAHALFBRITE)

#define BIDTAG_DIPFMustHave    0x80000001 /* mask of the DIPF_ flags the
                                           * ModeID must have
                                           * Default - NULL */
#define BIDTAG_DIPFMustNotHave 0x80000002 /* mask of the DIPF_ flags the
                                           * ModeID must not have
                                           * Default - SPECIAL_FLAGS */
#define BIDTAG_ViewPort        0x80000003 /* ViewPort for which a ModeID
                                           * is sought.
                                           * Default - NULL */
#define BIDTAG_NominalWidth    0x80000004 /* \ together make the aspect ratio */
#define BIDTAG_NominalHeight   0x80000005 /* / and override the
                                           * vp->Width/Height.
                                           * Default - SourceID
                                           * NominalDimensionInfo, or
                                           * vp->DWidth/Height, or (640 * 200),
                                           * in that preferred order.
                                           */
#define BIDTAG_DesiredWidth    0x80000006 /* \ Nominal Width and Height of */
#define BIDTAG_DesiredHeight   0x80000007 /* / the returned ModeID.
                                           * Default - same as Nominal */
#define BIDTAG_MinDepth        0x80000008 /* ModeID must support this depth.
                                           * Default - 
                                           * vp->RasInfo->BitMap->Depth or 1 */
#define BIDTAG_Depth           0x80000008 /* Deprecated alias for BIDTAG_MinDepth */
#define BIDTAG_MonitorID       0x80000009 /* ModeID must use this monitor.
                                           * Default - use best monitor
                                           * available */
#define BIDTAG_SourceID        0x8000000a /* instead of a ViewPort.
                                           * Default - VPModeID(vp) if
                                           * BIDTAG_ViewPort is specified,
                                           * else leave the DIPFMustHave and
                                           * DIPFMustNotHave values untouched.
                                           */
#define BIDTAG_RedBits         0x8000000b /* \                            */
#define BIDTAG_BlueBits        0x8000000c /* } Match up from the database */
#define BIDTAG_GreenBits       0x8000000d /* /                            */
                                          /* Default - 4 */
#define BIDTAG_GfxPrivate      0x8000000e /* Private */
#define BIDTAG_MaxDepth        0x8000000f /* Maximum depth ModeID must have. */

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

#endif /* GRAPHICS_MODEID_H */
