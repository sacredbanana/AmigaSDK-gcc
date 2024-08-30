#ifndef INTUITION_IMAGECLASS_H
#define INTUITION_IMAGECLASS_H

/*
	intuition image class definitions (V50)

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#pragma pack(2)


#define CUSTOMIMAGEDEPTH (-1)


#define GADGET_BOX(g)  ((struct IBox *) &((struct Gadget *)(g))->LeftEdge)
#define IM_BOX(im)     ((struct IBox *) &((struct Image *)(im))->LeftEdge)
#define IM_FGPEN(im)   ((im)->PlanePick)
#define IM_BGPEN(im)   ((im)->PlaneOnOff)


#define IA_Dummy             (TAG_USER + 0x20000)
#define IA_Left              (IA_Dummy + 1)
#define IA_Top               (IA_Dummy + 2)
#define IA_Width             (IA_Dummy + 3)
#define IA_Height            (IA_Dummy + 4)
#define IA_FGPen             (IA_Dummy + 5)
#define IA_BGPen             (IA_Dummy + 6)
#define IA_Data              (IA_Dummy + 7)
#define IA_LineWidth         (IA_Dummy + 8)

#define SYSIA_Size           (IA_Dummy + 11)
#define SYSIA_Depth          (IA_Dummy + 12)
#define SYSIA_Which          (IA_Dummy + 13)

#define IA_Pens              (IA_Dummy + 14)
#define IA_Resolution        (IA_Dummy + 15)

#define IA_APattern          (IA_Dummy + 16)
#define IA_APatSize          (IA_Dummy + 17)
#define IA_Mode              (IA_Dummy + 18)
#define IA_Font              (IA_Dummy + 19)
#define IA_Outline           (IA_Dummy + 20)
#define IA_Recessed          (IA_Dummy + 21)
#define IA_DoubleEmboss      (IA_Dummy + 22)
#define IA_EdgesOnly         (IA_Dummy + 23)

#define SYSIA_DrawInfo       (IA_Dummy + 24)

#define SYSIA_ReferenceFont  (IA_Dummy + 25)

#define IA_SupportsDisable   (IA_Dummy + 26)
#define IA_FrameType         (IA_Dummy + 27)

/*** V44 ***/

#define IA_Underscore        (IA_Dummy + 28)
#define IA_Scalable          (IA_Dummy + 29)
#define IA_ActivateKey       (IA_Dummy + 30)
#define IA_Screen            (IA_Dummy + 31)
#define IA_Precision         (IA_Dummy + 32)

/*** V50 ***/

#define SYSIA_WithBorder     (IA_FGPen)
#define SYSIA_Style          (IA_BGPen)

#define SYSISTYLE_NORMAL   0
#define SYSISTYLE_GADTOOLS 1


/*** OBSOLETE ***/

#define SYSIA_Pens           (IA_Pens)
#define IA_ShadowPen         (IA_Dummy + 9)
#define IA_HighlightPen      (IA_Dummy + 10)


#define SYSISIZE_MEDRES  (0)
#define SYSISIZE_LOWRES  (1)
#define SYSISIZE_HIRES   (2)


#define DEPTHIMAGE   (0x00)
#define ZOOMIMAGE    (0x01)
#define SIZEIMAGE    (0x02)
#define CLOSEIMAGE   (0x03)
#define SDEPTHIMAGE  (0x05)
#define LEFTIMAGE    (0x0A)
#define UPIMAGE      (0x0B)
#define RIGHTIMAGE   (0x0C)
#define DOWNIMAGE    (0x0D)
#define CHECKIMAGE   (0x0E)
#define MXIMAGE      (0x0F)
#define MENUCHECK    (0x10)
#define AMIGAKEY     (0x11)


#define FRAME_DEFAULT      0
#define FRAME_BUTTON       1
#define FRAME_RIDGE        2
#define FRAME_ICONDROPBOX  3


#define IM_DRAW         0x202
#define IM_HITTEST      0x203
#define IM_ERASE        0x204
#define IM_MOVE         0x205

#define IM_DRAWFRAME    0x206
#define IM_FRAMEBOX     0x207
#define IM_HITFRAME     0x208
#define IM_ERASEFRAME   0x209
#define IM_DOMAINFRAME  0x20A


#define IDS_NORMAL            (0L)
#define IDS_SELECTED          (1L)
#define IDS_DISABLED          (2L)
#define IDS_BUSY              (3L)
#define IDS_INDETERMINATE     (4L)
#define IDS_INACTIVENORMAL    (5L)
#define IDS_INACTIVESELECTED  (6L)
#define IDS_INACTIVEDISABLED  (7L)
#define IDS_SELECTEDDISABLED  (8L)

/* Typo fix */

#define IDS_INDETERMINANT  IDS_INDETERMINATE


struct impFrameBox
{
	ULONG            MethodID;
	struct IBox     *imp_ContentsBox;
	struct IBox     *imp_FrameBox;
	struct DrawInfo *imp_DrInfo;
	ULONG            imp_FrameFlags;
};

#define FRAMEF_SPECIFY  (1<<0)


struct impDraw
{
	ULONG            MethodID;
	struct RastPort *imp_RPort;

	struct
	{
		WORD X;
		WORD Y;
	}                imp_Offset;

	ULONG            imp_State;
	struct DrawInfo *imp_DrInfo;

	struct
	{
		WORD Width;
		WORD Height;
	}                imp_Dimensions;
};

struct impErase
{
	ULONG            MethodID;
	struct RastPort *imp_RPort;

	struct
	{
		WORD X;
		WORD Y;
	}                imp_Offset;

	struct
	{
		WORD Width;
		WORD Height;
	}                imp_Dimensions;
};

struct impHitTest
{
	ULONG MethodID;

	struct
	{
		WORD X;
		WORD Y;
	}     imp_Point;

	struct
	{
		WORD Width;
		WORD Height;
	}     imp_Dimensions;
};


struct impDomainFrame
{
	ULONG            MethodID;
	struct DrawInfo *imp_DrInfo;
	struct RastPort *imp_RPort;
	LONG             imp_Which;
	struct IBox      imp_Domain;
	struct TagItem  *imp_Attrs;
};


#define IDOMAIN_MINIMUM  (0)
#define IDOMAIN_NOMINAL  (1)
#define IDOMAIN_MAXIMUM  (2)


#pragma pack()

#ifndef INTUITION_IOBSOLETE_H
# include <intuition/iobsolete.h>
#endif

#endif /* INTUITION_IMAGECLASS_H */
