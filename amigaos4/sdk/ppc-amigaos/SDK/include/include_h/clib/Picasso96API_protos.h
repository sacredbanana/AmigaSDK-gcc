#ifndef CLIB_PICASSO96API_PROTOS_H
#define CLIB_PICASSO96API_PROTOS_H

/*
**    $Id: Picasso96API_protos.h,v 1.7 2010-01-31 01:28:53 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   LIBRARIES_PICASSO96_H
#include <libraries/Picasso96.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

struct Screen *p96OpenScreenTagList(struct TagItem *Tags);
struct Screen *p96OpenScreenTags(ULONG Tags, ...);
BOOL p96CloseScreen(struct Screen *screen);

ULONG p96BestModeIDTagList(struct TagItem *Tags);
ULONG p96BestModeIDTags(ULONG Tags, ...);
ULONG p96RequestModeIDTagList(struct TagItem *Tags);
ULONG p96RequestModeIDTags(ULONG Tags, ...);

struct List *p96AllocModeListTagList(struct TagItem *Tags);
struct List *p96AllocModeListTags(ULONG Tags, ...);
void p96FreeModeList(struct List *ModeList);

ULONG p96GetModeIDAttr(ULONG DisplayID, ULONG attribute_number);

struct BitMap *p96AllocBitMap(ULONG SizeX, ULONG SizeY, ULONG Depth, ULONG Flags, struct BitMap *friend_bitmap, RGBFTYPE RGBFormat);
void p96FreeBitMap(struct BitMap *bm);
ULONG p96GetBitMapAttr(struct BitMap *bm, ULONG attribute_number);

LONG p96LockBitMap(struct BitMap *bm, UBYTE *buf, ULONG size);
void p96UnlockBitMap(struct BitMap *bm, LONG lock);

void p96WritePixelArray(struct RenderInfo *ri, UWORD SrcX, UWORD SrcY, struct RastPort *rp, UWORD DestX, UWORD DestY, UWORD SizeX, UWORD SizeY);
void p96ReadPixelArray(struct RenderInfo *ri, UWORD DestX, UWORD DestY, struct RastPort *rp, UWORD SrcX, UWORD SrcY, UWORD SizeX, UWORD SizeY);

ULONG p96WritePixel(struct RastPort *rp, UWORD x, UWORD y, ULONG color);
ULONG p96ReadPixel(struct RastPort *rp, UWORD x, UWORD y);

void p96RectFill(struct RastPort *rp, UWORD MinX, UWORD MinY, UWORD MaxX, UWORD MaxY, ULONG ARGB);

void p96WriteTrueColorData(struct TrueColorInfo *tci, UWORD SrcX, UWORD SrcY, struct RastPort *rp, UWORD DestX, UWORD DestY, UWORD SizeX, UWORD SizeY);
void p96ReadTrueColorData(struct TrueColorInfo *tci, UWORD DestX, UWORD DestY, struct RastPort *rp, UWORD SrcX, UWORD SrcY, UWORD SizeX, UWORD SizeY);

struct Window *p96PIP_OpenTagList(struct TagItem *Tags);
struct Window *p96PIP_OpenTags(ULONG Tags, ...);
BOOL p96PIP_Close(struct Window *Window);
LONG p96PIP_SetTagList(struct Window *Window, struct TagItem *Tags);
LONG p96PIP_SetTags(struct Window *Window, ULONG Tags, ...);
LONG p96PIP_GetTagList(struct Window *Window, struct TagItem *Tags);
LONG p96PIP_GetTags(struct Window *Window, ULONG Tags, ...);

/* obsolete, no longer needed (GetMsg and ReplyMsg will do from now on...)
struct IntuiMessage *p96PIP_GetIMsg(struct MsgPort *Port);
void p96PIP_ReplyIMsg(struct IntuiMessage *IntuiMessage);
*/

LONG p96GetRTGDataTagList(struct TagItem *tags);
LONG p96GetRTGDataTags(ULONG Tags, ...);
LONG p96GetBoardDataTagList(ULONG board_number, struct TagItem *tags);
LONG p96GetBoardDataTags(ULONG board_number, ULONG Tags, ...);

ULONG p96EncodeColor(RGBFTYPE RGBFormat, ULONG Color);

/* new, do not use!!! */
int p96WriteYUVPixels(APTR pixels, SHORT SrcX, SHORT SrcY, struct BitMap *bm, SHORT DestX, SHORT DestY, SHORT SizeX, SHORT SizeY, struct TagItem *Tags);
int p96WriteYUVPixelsTags(APTR pixels, SHORT SrcX, SHORT SrcY, struct BitMap *bm, SHORT DestX, SHORT DestY, SHORT SizeX, SHORT SizeY, ULONG Tags, ...);

BOOL p96LockBitMapToBoard(struct BitMap *bm, ULONG board_number, UBYTE *buf, ULONG size);
void p96UnlockBitMapFromBoard(struct BitMap *bm, BOOL modified); 

#endif /* CLIB_PICASSO96API_PROTOS_H */
