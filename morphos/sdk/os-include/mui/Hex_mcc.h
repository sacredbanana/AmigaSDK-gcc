#ifndef __HEX_MCC_H_
#define __HEX_MCC_H_

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define MUISERIALNR_PTERMC 0xfecf

#define MUIC_Hex  "Hex.mcc"
#define HexObject MUI_NewObject(MUIC_Hex

#define TAGBASE_HEXMCC            ((TAG_USER | (MUISERIALNR_PTERMC << 16)) + 20000)

#define MUIA_Hex_File               (TAGBASE_HEXMCC + 1)
#define MUIA_Hex_ReadOnly           (TAGBASE_HEXMCC + 2)
#define MUIA_Hex_HasUndo            (TAGBASE_HEXMCC + 3)
#define MUIA_Hex_HasRedo            (TAGBASE_HEXMCC + 4)
#define MUIA_Hex_Modified           (TAGBASE_HEXMCC + 5)
#define MUIA_Hex_Rows               (TAGBASE_HEXMCC + 6)
#define MUIA_Hex_FirstRow           (TAGBASE_HEXMCC + 8)
#define MUIA_Hex_VisibleRows        (TAGBASE_HEXMCC + 9)
#define MUIA_Hex_CursorSize         (TAGBASE_HEXMCC + 10) /* 1/2/4 bytes */
#define MUIA_Hex_Sleep              (TAGBASE_HEXMCC + 11)
#define MUIA_Hex_MarkChanged        (TAGBASE_HEXMCC + 12)
#define MUIA_Hex_SelectedAnnotation (TAGBASE_HEXMCC + 13)
#define MUIA_Hex_CursorChanged      (TAGBASE_HEXMCC + 14)
#define MUIA_Hex_Editing            (TAGBASE_HEXMCC + 15)

#define MUIV_Hex_SelectedAnnotation_None -1

#define MUIM_Hex_Read                    (TAGBASE_HEXMCC + 1)
#define MUIM_Hex_Write                   (TAGBASE_HEXMCC + 2)

#define MUIM_Hex_Undo                    (TAGBASE_HEXMCC + 10)
#define MUIM_Hex_Redo                    (TAGBASE_HEXMCC + 11)
#define MUIM_Hex_Apply                   (TAGBASE_HEXMCC + 12)

#define MUIM_Hex_Load                    (TAGBASE_HEXMCC + 20)
#define MUIM_Hex_LoadMemory              (TAGBASE_HEXMCC + 21)
#define MUIM_Hex_LoadAbstract            (TAGBASE_HEXMCC + 22)
#define MUIM_Hex_AbstractDataChanged     (TAGBASE_HEXMCC + 23)

#define MUIM_Hex_AddAnnotation           (TAGBASE_HEXMCC + 30)
#define MUIM_Hex_RemoveAnnotation        (TAGBASE_HEXMCC + 31)
#define MUIM_Hex_RemoveAnnotations       (TAGBASE_HEXMCC + 32)
#define MUIM_Hex_GetMessageForAnnotation (TAGBASE_HEXMCC + 33)
#define MUIM_Hex_ShowAnnotation          (TAGBASE_HEXMCC + 34)

#define MUIM_Hex_GetMarked               (TAGBASE_HEXMCC + 50)
#define MUIM_Hex_GetCursor               (TAGBASE_HEXMCC + 51)
#define MUIM_Hex_SetCursor               (TAGBASE_HEXMCC + 52)
#define MUIM_Hex_GetCursorBytes          (TAGBASE_HEXMCC + 53)
#define MUIM_Hex_GetLength               (TAGBASE_HEXMCC + 54)
#define MUIM_Hex_SetMarked               (TAGBASE_HEXMCC + 55)
#define MUIM_Hex_HitTest                 (TAGBASE_HEXMCC + 56)

#define MUIM_Hex_SetVisibleOffset        (TAGBASE_HEXMCC + 60)
#define MUIM_Hex_GetVisibleOffset        (TAGBASE_HEXMCC + 61)

#define MUIM_Hex_ReadData                (TAGBASE_HEXMCC + 62)
#define MUIM_Hex_ReadDataCompleted       (TAGBASE_HEXMCC + 63)
#define MUIM_Hex_ReadDataReply           (TAGBASE_HEXMCC + 64)

#define MUIM_Hex_BeginEditing            (TAGBASE_HEXMCC + 65)
#define MUIM_Hex_Edit                    (TAGBASE_HEXMCC + 66)

struct MUIP_Hex_Read { ULONG MethodID; UQUAD *Offset; ULONG *Output; ULONG Size; };
struct MUIP_Hex_Write { ULONG MethodID; UQUAD *Offset; UBYTE *ModifiedBytes; ULONG Count; };

struct MUIP_Hex_Load { ULONG MethodID; CONST_STRPTR file; };
struct MUIP_Hex_LoadMemory { ULONG MethodID; UBYTE *Memory; ULONG Length; ULONG Copy; };
struct MUIP_Hex_LoadAbstract { ULONG MethodID; UQUAD *Length; UQUAD *DisplayOffset; };
struct MUIP_Hex_AbstractDataChanged { ULONG MethodID; UQUAD *Offset; UQUAD *Length; };

struct MUIP_Hex_AddAnnotation { ULONG MethodID; UQUAD *Offset; UQUAD *EndOffset; ULONG xRGB; ULONG UniqueID; };
struct MUIP_Hex_RemoveAnnotation { ULONG MethodID; ULONG UniqueID; };
struct MUIP_Hex_GetMessageForAnnotation { ULONG MethodID; ULONG UniqueID; };
struct MUIP_Hex_ShowAnnotation { ULONG MethodID; ULONG UniqueID; };

struct MUIP_Hex_GetMarked { ULONG MethodID; UQUAD *Offset; UQUAD *EndOffset; };
struct MUIP_Hex_SetMarked { ULONG MethodID; UQUAD *Offset; UQUAD *EndOffset; ULONG SuppressNotification; };
struct MUIP_Hex_GetCursor { ULONG MethodID; UQUAD *CursorPosition; ULONG *BytesAtCursor; };
struct MUIP_Hex_SetCursor { ULONG MethodID; UQUAD *CursorPosition; ULONG SuppressNotification; };
struct MUIP_Hex_GetCursorBytes { ULONG MethodID; ULONG *BytesAtCursor; ULONG ByteCount; };
struct MUIP_Hex_GetLength { ULONG MethodID; UQUAD *Length; };
struct MUIP_Hex_HitTest { ULONG MethodID; LONG X; LONG Y; UQUAD *Offset; };

struct MUIP_Hex_SetVisibleOffset { ULONG MethodID; UQUAD *Offset; ULONG SuppressNotification; };
struct MUIP_Hex_GetVisibleOffset { ULONG MethodID; UQUAD *Offset; };

struct MUIP_Hex_ReadData { ULONG MethodID; UQUAD *Offset; UBYTE *Output; ULONG Size; ULONG ReplyMethodID; };
struct MUIP_Hex_ReadDataCompleted { ULONG MethodID; LONG Size; ULONG ReplyMethodID; };
struct MUIP_Hex_ReadDataReply { ULONG MethodID; ULONG Size; };

struct MUIP_Hex_Edit { ULONG MethodID; UQUAD *Offset; const UBYTE *Data; ULONG Size; };

/* */

#endif
