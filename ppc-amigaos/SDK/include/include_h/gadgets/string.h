#ifndef GADGETS_STRING_H
#define GADGETS_STRING_H
/*
**    $VER: string.h 54.16 (22.08.2022)
**
**    Definitions for the string.gadget BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

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

/* string.gadget accepts the same tag parameters as the ROM strgclass
 * in addition to those listed below.
 */

#define STRINGA_MinVisible       (REACTION_Dummy+0x0055000)
    /* (UWORD) Minimum character length to domain min size on.
     * In a layout, a nominal domain would be 2 times this value. 
     */

#define STRINGA_HookType         (REACTION_Dummy+0x0055001)
    /* (UWORD) Use which built-in hook function? [IS] */

/* The following tags are new for v45 */

#define STRINGA_RelVerifySpecial (REACTION_Dummy+0x005500a)
    /* (BOOL) new for v45.14: Send IDCMP_GADGETUP whenever the gadget    
     * goes inactive. Don't not use this tag for ENDGADGET like
     * gadgets. 
     */
     
#define STRINGA_GetBlockPos      (REACTION_Dummy+0x0055010)
    /* (ULONG) Returns the position of the first and last character
     * of the marked block. The upper 16bit (WORD) of the long-word contain
     * the start position and the lower 16bit (WORD) the end position.
     * When nothing is marked both values will be -1. [G] 
     * OBSOLETE. Use tag below.
     */

#define STRINGA_Mark             (REACTION_Dummy+0x0055011)
    /* (ULONG) Mark the given block. The upper 16bit of the longword contain
     * the start position and the lower one the end position. If one or both
     * values are -1, the current block will be unmarked. [ISU] 
     */
     
#define STRINGA_AllowMarking     (REACTION_Dummy+0x0055012) 
    /* (BOOL) Enable/disable marking, defaults to TRUE. [ISUG] */
     
#define STRINGA_ASLTags          (REACTION_Dummy+0x0055013)
    /* (struct TagItem *) Used internally by getfile.gadget
     * and the filename expansion code of string.gadget. [IS]
     */

#define STRINGA_MarkActive       (REACTION_Dummy+0x0055014)
    /* Mark contents of gadget when it goes active. Defaults to
     * FALSE. [IS] (V50) 
     */

#define STRINGA_DisablePopup      (REACTION_Dummy+0x0055015)
    /* Disable the right button popup context menu. Defaults to 
     * FALSE. [S] (V53)
     */

#define STRINGA_MinVal            (REACTION_Dummy+0x0055016)
    /* Minimum value for STRINGA_LongVal. [S] (V53.18) */

#define STRINGA_MaxVal            (REACTION_Dummy+0x0055017)
    /* Maximum value for STRINGA_LongVal. [S] (V53.18) */
     
/* Support hook types for STRINGA_HookType */
#define SHK_CUSTOM      0
#define SHK_PASSWORD    1
#define SHK_IPADDRESS   2
#define SHK_FLOAT       3
#define SHK_HEXIDECIMAL 4
#define SHK_TELEPHONE   5
#define SHK_POSTALCODE  6
#define SHK_AMOUNT      7
#define SHK_UPPERCASE   8
#define SHK_HOTKEY      9 /* new for v45 */

#define SHK_HEXADECIMAL SHK_HEXIDECIMAL

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

#endif /* GADGETS_STRING_H */
