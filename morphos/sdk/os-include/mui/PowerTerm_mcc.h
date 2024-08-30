/****************************************************************************/
/* PowerTerm.mcc (c) Copyright 2004-2011 by Jacek Piszczek                  */
/****************************************************************************/

#ifndef MUI_PowerTerm_MCC_H
#define MUI_PowerTerm_MCC_H

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#define MUIC_PowerTerm "PowerTerm.mcc"
#define PowerTermObject MUI_NewObject(MUIC_PowerTerm

#define MUISERIALNR_PTERMC 0xfecf
#define TAGBASE_PTERMC                      ((TAG_USER | (MUISERIALNR_PTERMC << 16)) + 2050)

#define MUIM_PowerTerm_Write                (TAGBASE_PTERMC +    16) /* Write to the terminal, supports utf8 if enabled */
#define MUIM_PowerTerm_OutFlush             (TAGBASE_PTERMC +    17) /* Flush the output buffer */
#define MUIM_PowerTerm_Reset                (TAGBASE_PTERMC +    18) /* Reset terminal contents */
#define MUIM_PowerTerm_SelectToClip         (TAGBASE_PTERMC +     8) /* Selected area -> clipboard */
#define MUIM_PowerTerm_PasteFromClip        (TAGBASE_PTERMC +     9) /* Write string from clipboard */
#define MUIM_PowerTerm_SavePlain            (TAGBASE_PTERMC +    19) /* Save history to a file (no styles) */
#define MUIM_PowerTerm_SaveStyle            (TAGBASE_PTERMC +    20) /* Save history to a file (w styles) */
#define MUIM_PowerTerm_SetAbsXY             (TAGBASE_PTERMC +    21) /* Set terminal size (chars) */
#define MUIM_PowerTerm_SavePlainFH          (TAGBASE_PTERMC +    22) /* Save history to a filehandle */
#define MUIM_PowerTerm_SaveStyleFH          (TAGBASE_PTERMC +    23) /* Save history to a filehandle */
#define MUIM_PowerTerm_FlushReview          (TAGBASE_PTERMC +    24) /* Flush the history */
#define MUIM_PowerTerm_Scroll               (TAGBASE_PTERMC +    25) /* Scroll view */
#define MUIM_PowerTerm_AddOut               (TAGBASE_PTERMC +     3) /* Insert data into output buffer, returns ULONG with the amount of copied data */
#define MUIM_PowerTerm_WriteUnicode         (TAGBASE_PTERMC +     7) /* Write a stream of unicode characters into the terminal */
#define MUIM_PowerTerm_Search               (TAGBASE_PTERMC +    10) /* Search in the buffer */
#define MUIM_PowerTerm_Duplicate            (TAGBASE_PTERMC +    14) /* Returns a copy of this object */
#define MUIM_PowerTerm_Select               (TAGBASE_PTERMC +    48) /* Selects whole scrollback */

struct MUIP_PowerTerm_Write                 {ULONG methodid; STRPTR data; ULONG length;};
struct MUIP_PowerTerm_OutFlush              {ULONG methodid;};
struct MUIP_PowerTerm_Reset                 {ULONG methodid;};
struct MUIP_PowerTerm_SelectToClip          {ULONG methodid; ULONG unit;};
struct MUIP_PowerTerm_PasteFromClip         {ULONG methodid; ULONG unit;};
struct MUIP_PowerTerm_SavePlain             {ULONG methodid; STRPTR filename;};
struct MUIP_PowerTerm_SaveStyle             {ULONG methodid; STRPTR filename;};
struct MUIP_PowerTerm_SetAbsXY              {ULONG methodid; ULONG cols; ULONG rows;};
struct MUIP_PowerTerm_SavePlainFH           {ULONG methodid; ULONG fh;};
struct MUIP_PowerTerm_SaveStyleFH           {ULONG methodid; ULONG fh;};
struct MUIP_PowerTerm_FlushReview           {ULONG methodid;};
struct MUIP_PowerTerm_Scroll                {ULONG methodid; LONG offset; ULONG mode;};
struct MUIP_PowerTerm_AddOut                {ULONG methodid; STRPTR data; ULONG length;};
struct MUIP_PowerTerm_WriteUnicode          {ULONG methodid; STRPTR data; ULONG length; ULONG format;}; /* length is in characters, not bytes! */
struct MUIP_PowerTerm_Search                {ULONG methodid; STRPTR searchstring; ULONG mode; ULONG flags;};
struct MUIP_PowerTerm_Duplicate             {ULONG methodid;};
struct MUIP_PowerTerm_Select                {ULONG methodid; ULONG selecttype;};

#define MUIA_PowerTerm_Scroller             (TAGBASE_PTERMC + 26) /* i.s, scroller object that may be controlled by/used to control term class */
#define MUIA_PowerTerm_OutPtr               (TAGBASE_PTERMC + 27) /* .g., pointer to output buffer */
#define MUIA_PowerTerm_OutLen               (TAGBASE_PTERMC + 28) /* .g., size of output buffer */
#define MUIA_PowerTerm_Emulation            (TAGBASE_PTERMC + 29) /* igs, sets emulation mode */
#define MUIA_PowerTerm_Width                (TAGBASE_PTERMC + 30) /* ig., terminal width */
#define MUIA_PowerTerm_Height               (TAGBASE_PTERMC + 31) /* ig., terminal height */
#define MUIA_PowerTerm_CursorX              (TAGBASE_PTERMC + 32) /* .gs, cursor pos, please use esc codes to set it! */
#define MUIA_PowerTerm_CursorY              (TAGBASE_PTERMC + 33) /* .gs, cusros pos, please use esc codes to set it! */
#define MUIA_PowerTerm_ResizableHistory     (TAGBASE_PTERMC + 34) /* i.., set resize mode, off by default */
#define MUIA_PowerTerm_ClickX               (TAGBASE_PTERMC + 35) /* .g., set when user clicked somewhere in terminal's edit area */
#define MUIA_PowerTerm_ClickY               (TAGBASE_PTERMC + 36) /* .g., never set when user clicked history */
#define MUIA_PowerTerm_Resizable            (TAGBASE_PTERMC + 37) /* i.., if set to FALSE the terminal will have fixed size which must be specified at obj creation */
#define MUIA_PowerTerm_TabSize              (TAGBASE_PTERMC + 45) /* i.., if set, the tabstop table will use the provided tab jump value, 8 for default */
#define MUIA_PowerTerm_TextMarking          (TAGBASE_PTERMC + 46) /* isg, if unset, marking text with mouse is disabled, defaults to TRUE */
#define MUIA_PowerTerm_EatAllInput          (TAGBASE_PTERMC + 47) /* isg, if set, pterm will process rawkeys even if not active, defaults to TRUE */

#define MUIA_PowerTerm_FontWidth            (TAGBASE_PTERMC + 1)  /* .g., font width in pixels, info available between setup/cleanup */
#define MUIA_PowerTerm_FontHeight           (TAGBASE_PTERMC + 2)  /* .g., font height in pixels */
#define MUIA_PowerTerm_WindowTitle          (TAGBASE_PTERMC + 4)  /* .g., window title set by ESC]BEL sequence */
#define MUIA_PowerTerm_IconTitle            (TAGBASE_PTERMC + 5)  /* .g., icon title set by ESC]BEL sequence */
#define MUIA_PowerTerm_MouseTracking        (TAGBASE_PTERMC + 6)  /* .g., if true then the app using the terminal wants to know about mouse events (incl wheel) */
#define MUIA_PowerTerm_UTFEnable            (TAGBASE_PTERMC + 13) /* i.., set to true if your app is able to handle utf */
#define MUIA_PowerTerm_OutEnable            (TAGBASE_PTERMC + 15) /* isg, set to false to disable output (keyboard input), on by default */
#define MUIA_PowerTerm_UnixPaths            (TAGBASE_PTERMC + 16) /* .g., unix paths mode, set by an ESC sequence */

#define MUIA_PowerTerm_8Bit                 (TAGBASE_PTERMC + 38) /* isg, activate 8 bit mode, off by default */
#define MUIA_PowerTerm_EightBit             MUIA_PowerTerm_8Bit
#define MUIA_PowerTerm_CRasCRLF             (TAGBASE_PTERMC + 39) /* isg, parse cr as crlf, off by default */
#define MUIA_PowerTerm_SwapDELBS            (TAGBASE_PTERMC + 40) /* isg, swap DEL and BS, off by default */
#define MUIA_PowerTerm_LFasCRLF             (TAGBASE_PTERMC + 41) /* isg, parse lf as crlf, off by default */
#define MUIA_PowerTerm_Wrap                 (TAGBASE_PTERMC + 42) /* isg, activate character wrap, off by default, on with resizablehistory */
#define MUIA_PowerTerm_DestructiveBS        (TAGBASE_PTERMC + 43) /* isg, use destructive backspace, off by default */
#define MUIA_PowerTerm_DELasBS              (TAGBASE_PTERMC + 44) /* isg, parse delete as backspace, off by default */
#define MUIA_PowerTerm_LocalAlt             (TAGBASE_PTERMC + 11) /* isg, local alt handling, alt key mask used for local key mapping */
#define MUIA_PowerTerm_SaveSettings         (TAGBASE_PTERMC + 12) /* *s*, all emulation tweaks set after this tag will be set as default and restored on term reset */

#define MUIV_PowerTerm_Emulation_ANSI       0 /* ANSI X3.64 1979, obsolete */
#define MUIV_PowerTerm_Emulation_VT100      1 /* DEC VT100, obsolete  */
#define MUIV_PowerTerm_Emulation_TTY        2 /* Direct text output, obsolete */
#define MUIV_PowerTerm_Emulation_XTerm      3 /* XTerm compatible */
#define MUIV_PowerTerm_Emulation_Amiga      4 /* Amiga con-handler */

#define MUIV_PowerTerm_Scroll_Normal        0 /* scroll by x lines, negative offset = scroll up */
#define MUIV_PowerTerm_Scroll_Page          1 /* scroll by x pages */
#define MUIV_PowerTerm_Scroll_Home          2 /* scroll to top */
#define MUIV_PowerTerm_Scroll_End           3 /* scroll to bottom */

#define MUIV_PowerTerm_WriteUnicode_UTF8    1
#define MUIV_PowerTerm_WriteUnicode_U16BE   2 /* UNICODE 16 bit/char, big endian */
#define MUIV_PowerTerm_WriteUnicode_U16LE   3
#define MUIV_PowerTerm_WriteUnicode_U32BE   4
#define MUIV_PowerTerm_WriteUnicode_U32LE   5

#define MUIV_PowerTerm_Search_ASCII         0
#define MUIV_PowerTerm_Search_UTF8          1
#define MUIV_PowerTerm_Search_U16BE         2 /* UNICODE 16 bit/char, big endian */
#define MUIV_PowerTerm_Search_U16LE         3
#define MUIV_PowerTerm_Search_U32BE         4
#define MUIV_PowerTerm_Search_U32LE         5

#define MUIF_PowerTerm_Search_Direction_Up     (0)
#define MUIF_PowerTerm_Search_Direction_Down   (1)
#define MUIF_PowerTerm_Search_Continue         (1 << 1)
#define MUIF_PowerTerm_Search_MakeVisible      (1 << 2)
#define MUIF_PowerTerm_Search_Mark             (1 << 3)
#define MUIF_PowerTerm_Search_MarkWord         (1 << 4)
#define MUIF_PowerTerm_Search_MarkLine         (1 << 5)

#define MUIV_PowerTerm_LocalAlt_Both        0 /* use both alt keys for local key mapping */
#define MUIV_PowerTerm_LocalAlt_Left        1
#define MUIV_PowerTerm_LocalAlt_Right       2
#define MUIV_PowerTerm_LocalAlt_None        3 /* send both alt keys to remote */

#define MUIV_PowerTerm_Select_None 0
#define MUIV_PowerTerm_Select_All  1

#endif /* MUI_PowerTerm_MCC_H */
