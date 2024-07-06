#include "demo.h"

#include <proto/intuition.h>
#include <intuition/pointerclass.h>

#ifndef POINTERA_ImageData
#define POINTERA_ImageData (POINTERA_Dummy + 0x07) // ARGB (width * height * sizeof(ULONG))
#endif
#ifndef POINTERA_Width
#define POINTERA_Width     (POINTERA_Dummy + 0x08) // <= 64
#endif
#ifndef POINTERA_Height
#define POINTERA_Height    (POINTERA_Dummy + 0x09) // <= 64
#endif

/*
A simple demo application to show some new features of MUI 5.0.
*/

struct MUI_CustomClass *pointer_mcc;

// a simple smiling pointer image
#define smiley8_Width        15
#define smiley8_Height       15
#define smiley8_Depth        2
#define smiley8_WordWidth    1

static const UWORD smiley8_Data[] =
{
	0x07c0,	/* .....#####...... */
	0x1ff0,	/* ...#########.... */
	0x3ff8,	/* ..###########... */
	0x7ffc,	/* .#############.. */
	0x7ffc,	/* .#############.. */
	0xfffe,	/* ###############. */
	0xfffe,	/* ###############. */
	0xfffe,	/* ###############. */
	0xfffe,	/* ###############. */
	0xfffe,	/* ###############. */
	0x7ffc,	/* .#############.. */
	0x7ffc,	/* .#############.. */
	0x3ff8,	/* ..###########... */
	0x1ff0,	/* ...#########.... */
	0x07c0,	/* .....#####...... */

	0x07c0,	/* .....#####...... */
	0x1830,	/* ...##.....##.... */
	0x2008,	/* ..#.........#... */
	0x4004,	/* .#...........#.. */
	0x4c64,	/* .#..##...##..#.. */
	0x8c62,	/* #...##...##...#. */
	0x8002,	/* #.............#. */
	0x8002,	/* #.............#. */
	0x8002,	/* #.............#. */
	0x8822,	/* #...#.....#...#. */
	0x4444,	/* .#...#...#...#.. */
	0x4384,	/* .#....###....#.. */
	0x2008,	/* ..#.........#... */
	0x1830,	/* ...##.....##.... */
	0x07c0,	/* .....#####...... */
};

#if defined(__amigaos4__)
// a 32bit pointer usable for AmigaOS4
#define SMILEY32_WIDTH       15
#define SMILEY32_HEIGHT      15
#define SMILEY32_DEPTH       32
#define SMILEY32_FORMAT      MUIV_Pixmap_Format_ARGB32
#define SMILEY32_COMPRESSION MUIV_Pixmap_Compression_None
#define SMILEY32_SIZE        900

const unsigned long smiley32[] =
{
	0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x3c000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0x57000000, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0xff000000, 0xff000000, 0xff383800,
	0xff8f8f00, 0xff8f8f00, 0xff8f8f00, 0xff505000, 0xff000000, 0xff000000, 0x10000000, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0xff000000, 0xff3f3f00, 0xffefef00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff636300,
	0xff000000, 0x1f000000, 0x006e5b41, 0x006e5b41, 0xff000000, 0xff3f3f00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff787800, 0xff000000, 0x006e5b41, 0x4a000000, 0xff000000, 0xffefef00,
	0xffffff00, 0xff000000, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xff000000, 0xffffff00, 0xffffff00, 0xff000000, 0x87000000, 0xff000000, 0xff474700, 0xffffff00, 0xffffff00, 0xff000000, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00,
	0xff000000, 0xff000000, 0xffffff00, 0xffffff00, 0xff838300, 0xff000000, 0xff000000, 0xff9b9b00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffefef00, 0xff000000,
	0xff000000, 0xffd1d100, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xff000000, 0xffa8a800, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00,
	0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xff000000, 0xff636300, 0xffffff00, 0xffffff00, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xffffff00,
	0xffffff00, 0xffa8a800, 0xff000000, 0x87000000, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xaf000000, 0x006e5b41, 0xff000000, 0xff838300,
	0xffffff00, 0xffffff00, 0xffffff00, 0xff000000, 0xff000000, 0xff000000, 0xffffff00, 0xffffff00, 0xffffff00, 0xffc3c300, 0xff000000, 0x10000000, 0x006e5b41, 0x2e000000, 0xff000000, 0xff9b9b00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00,
	0xffffff00, 0xffffff00, 0xffc3c300, 0xff000000, 0x57000000, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0x2e000000, 0xff000000, 0xff000000, 0xffa8a800, 0xffffff00, 0xffffff00, 0xffffff00, 0xffb5b500, 0xff000000, 0xff000000, 0x57000000, 0x006e5b41, 0x006e5b41,
	0x006e5b41, 0x006e5b41, 0x006e5b41, 0x006e5b41, 0xa6000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xc0000000, 0x10000000, 0x006e5b41, 0x006e5b41, 0x006e5b41,
};
#endif

/* ------------------------------------------------------------------------- */

struct PointerData
{
	struct BitMap smileBitmap;
	Object *smilePointer;
};

static ULONG Pointer_NEW(UNUSED struct IClass *cl, Object *obj, Msg msg)
{
	if((obj = (Object *)DoSuperMethodA(cl, obj, msg)) != NULL)
	{
		struct PointerData *data = INST_DATA(cl, obj);
		ULONG d;

		// set up our smiling pointer image bitmap
		InitBitMap(&data->smileBitmap, smiley8_Depth, smiley8_Width, smiley8_Height);

		for(d = 0; d < smiley8_Depth; d++)
			data->smileBitmap.Planes[d] = (PLANEPTR)&smiley8_Data[smiley8_WordWidth * smiley8_Height * d];

		// create the pointer image
		data->smilePointer = (Object *)NewObject(NULL, "pointerclass",
			#if defined(__amigaos4__)
			POINTERA_ImageData,   smiley32,
			POINTERA_Width,       SMILEY32_WIDTH,
			POINTERA_Height,      SMILEY32_HEIGHT,
			#endif
			POINTERA_BitMap,      &data->smileBitmap,
			POINTERA_WordWidth,   smiley8_WordWidth,
			POINTERA_XResolution, POINTERXRESN_SCREENRES,
			POINTERA_YResolution, POINTERYRESN_SCREENRESASPECT,
			POINTERA_XOffset,     -(smiley8_Width/2),
			POINTERA_YOffset,     -(smiley8_Height/2),
			TAG_DONE);
	}

	return (ULONG)obj;
}

static ULONG Pointer_DISPOSE(UNUSED struct IClass *cl, Object *obj, Msg msg)
{
	struct PointerData *data = INST_DATA(cl, obj);

	if(data->smilePointer != NULL)
		DisposeObject(data->smilePointer);

	return DoSuperMethodA(cl, obj, msg);
}

static ULONG Pointer_WhichPointerType(struct IClass *cl, Object *obj, struct MUIP_WhichPointerType *msg)
{
	struct PointerData *data = INST_DATA(cl, obj);

	// return a pointer type which will show an
	// arrow pointing into the matching direction
	// and the custom smiling pointer in the center
	if(msg->my <= _top(obj) + _height(obj)/3)
	{
		if(msg->mx <= _left(obj) + _width(obj)/3)
			return MUIV_PointerType_NorthWestResize;
		else if(msg->mx >= _right(obj) - _width(obj)/3)
			return MUIV_PointerType_NorthEastResize;
		else
			return MUIV_PointerType_NorthResize;
	}
	else if(msg->my >= _bottom(obj) - _height(obj)/3)
	{
		if(msg->mx <= _left(obj) + _width(obj)/3)
			return MUIV_PointerType_SouthWestResize;
		else if(msg->mx >= _right(obj) - _width(obj)/3)
			return MUIV_PointerType_SouthEastResize;
		else
			return MUIV_PointerType_SouthResize;
	}
	else
	{
		if(msg->mx <= _left(obj) + _width(obj)/3)
			return MUIV_PointerType_WestResize;
		else if(msg->mx >= _right(obj) - _width(obj)/3)
			return MUIV_PointerType_EastResize;
		else
			return (ULONG)data->smilePointer;
	}
}

DISPATCHER(Pointer_Dispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW:                return(Pointer_NEW(cl, obj, (APTR)msg));
		case OM_DISPOSE:            return(Pointer_DISPOSE(cl, obj, (APTR)msg));
		case MUIM_WhichPointerType: return(Pointer_WhichPointerType(cl, obj, (APTR)msg));
	}

	return DoSuperMethodA(cl, obj, msg);
}

#define PointerButton(text, type) TextObject, ButtonFrame, MUIA_PointerType, type, MUIA_Text_PreParse, "\33c", MUIA_Text_Contents, text, MUIA_Text_Copy, FALSE, End

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window;

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if (!(pointer_mcc = MUI_CreateCustomClass(NULL, MUIC_Text, NULL, sizeof(struct PointerData), ENTRY(Pointer_Dispatcher))))
		fail(NULL,"Could not create pointer custom class.");

	// set up a specific name for our class
	pointer_mcc->mcc_Class->cl_ID = (ClassID)"Pointers";

	app = ApplicationObject,
		MUIA_Application_Title      , "Pointers",
		MUIA_Application_Version    , "$VER: Pointers 21.3 (24.01.2017)",
		MUIA_Application_Copyright  , "(C) 2015-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of custom pointer images in MUI 5.0",
		MUIA_Application_Base       , "POINTERS",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Custom pointer images",
			MUIA_Window_ID, MAKE_ID('C','P','T','R'),
			WindowContents, ColGroup(3),
				MUIA_Group_SameSize, TRUE,
				Child, PointerButton("normal", MUIV_PointerType_Normal),
				Child, PointerButton("busy", MUIV_PointerType_Busy),
				Child, PointerButton("alias", MUIV_PointerType_Alias),

				Child, PointerButton("cell", MUIV_PointerType_Cell),
				Child, PointerButton("column resize", MUIV_PointerType_ColumnResize),
				Child, PointerButton("context menu", MUIV_PointerType_ContextMenu),

				Child, PointerButton("copy", MUIV_PointerType_Copy),
				Child, PointerButton("cross", MUIV_PointerType_Cross),
				Child, PointerButton("drag and drop", MUIV_PointerType_DragAndDrop),

				Child, PointerButton("east resize", MUIV_PointerType_EastResize),
				Child, PointerButton("east/west resize", MUIV_PointerType_EastWestResize),
				Child, PointerButton("hand", MUIV_PointerType_Hand),

				Child, PointerButton("help", MUIV_PointerType_Help),
				Child, PointerButton("link", MUIV_PointerType_Link),
				Child, PointerButton("menu", MUIV_PointerType_Menu),

				Child, PointerButton("no drop", MUIV_PointerType_NoDrop),
				Child, PointerButton("none", MUIV_PointerType_None),
				Child, PointerButton("north/east resize", MUIV_PointerType_NorthEastResize),

				Child, PointerButton("north/east south/west resize", MUIV_PointerType_NorthEastSouthWestResize),
				Child, PointerButton("north resize", MUIV_PointerType_NorthResize),
				Child, PointerButton("north/south resize", MUIV_PointerType_NorthSouthResize),

				Child, PointerButton("north/west resize", MUIV_PointerType_NorthWestResize),
				Child, PointerButton("north/west south/east resize", MUIV_PointerType_NorthWestSouthEastResize),
				Child, PointerButton("not allowed", MUIV_PointerType_NotAllowed),

				Child, PointerButton("pen", MUIV_PointerType_Pen),
				Child, PointerButton("progress", MUIV_PointerType_Progress),
				Child, PointerButton("rotate", MUIV_PointerType_Rotate),

				Child, PointerButton("row resize", MUIV_PointerType_RowResize),
				Child, PointerButton("rubber", MUIV_PointerType_Rubber),
				Child, PointerButton("scroll all", MUIV_PointerType_ScrollAll),

				Child, PointerButton("select", MUIV_PointerType_Select),
				Child, PointerButton("smudge", MUIV_PointerType_Smudge),
				Child, PointerButton("south/east resize", MUIV_PointerType_SouthEastResize),

				Child, PointerButton("south resize", MUIV_PointerType_SouthResize),
				Child, PointerButton("south/west resize", MUIV_PointerType_SouthWestResize),
				Child, PointerButton("text", MUIV_PointerType_Text),

				Child, PointerButton("vertical text", MUIV_PointerType_VerticalText),
				Child, PointerButton("west resize", MUIV_PointerType_WestResize),
				Child, PointerButton("zoom in", MUIV_PointerType_ZoomIn),

				Child, PointerButton("zoom out", MUIV_PointerType_ZoomOut),
				Child, NewObject(pointer_mcc->mcc_Class, NULL,
					ButtonFrame,
					MUIA_Text_PreParse, "\33c",
					MUIA_Text_Contents, "application defined",
					MUIA_Text_Copy, FALSE,
					TAG_DONE),
				Child, HSpace(0),

				End,
			End,

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	set(window,MUIA_Window_Open,TRUE);

/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just call a single method which does all the dirty work.
*/

	DoMethod(app, MUIM_Application_Run);

	set(window,MUIA_Window_Open,FALSE);


/*
** Shut down...
*/

	MUI_DisposeObject(app);     /* dispose all objects. */
	MUI_DeleteCustomClass(pointer_mcc); /* delete the custom class. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
