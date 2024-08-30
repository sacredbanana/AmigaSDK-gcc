#ifndef GADGETS_GETFILE_H
#define GADGETS_GETFILE_H

/*
	getfile.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#pragma pack(2)


/* Attributes defined by getfile.gadget */

#define GETFILE_Dummy           (REACTION_Dummy + 0x60000)
#define GETFILE_TitleText       (GETFILE_Dummy + 1)
#define GETFILE_LeftEdge        (GETFILE_Dummy + 2)
#define GETFILE_TopEdge         (GETFILE_Dummy + 3)
#define GETFILE_Width           (GETFILE_Dummy + 4)
#define GETFILE_Height          (GETFILE_Dummy + 5)
#define GETFILE_File            (GETFILE_Dummy + 6)
#define GETFILE_Drawer          (GETFILE_Dummy + 7)
#define GETFILE_FullFile        (GETFILE_Dummy + 8)
#define GETFILE_FullFileExpand  (GETFILE_Dummy + 9)
#define GETFILE_Pattern         (GETFILE_Dummy + 10)
#define GETFILE_DoSaveMode      (GETFILE_Dummy + 11)
#define GETFILE_DoMultiSelect   (GETFILE_Dummy + 12)
#define GETFILE_DoPatterns      (GETFILE_Dummy + 13)
#define GETFILE_DrawersOnly     (GETFILE_Dummy + 14)
#define GETFILE_FilterFunc      (GETFILE_Dummy + 15)
#define GETFILE_RejectIcons     (GETFILE_Dummy + 16)
#define GETFILE_RejectPattern   (GETFILE_Dummy + 17)
#define GETFILE_AcceptPattern   (GETFILE_Dummy + 18)
#define GETFILE_FilterDrawers   (GETFILE_Dummy + 19)
#define GETFILE_Filelist        (GETFILE_Dummy + 20)
#define GETFILE_LBNodeStructs   (GETFILE_Dummy + 21)
#define GETFILE_ReadOnly        (GETFILE_Dummy + 22)
#define GETFILE_FilePartOnly    (GETFILE_Dummy + 23)


/* getfile.gadget methods */

#define GFILE_REQUEST   (0x620001L)
#define GFILE_FREELIST  (0x620002L)


struct gfileRequest
{
	ULONG          MethodID;
	struct Window *gfile_Window;
};

struct gfileFreelist
{
	ULONG        MethodID;
	struct List *gfile_Filelist;
};


/* Useful macros */

#define gfRequestFile(obj, win)    DoMethod(obj, GFILE_REQUEST, win)
#define gfRequestDir(obj, win)     DoMethod(obj, GFILE_REQUEST, win)
#define gfFreeFilelist(obj, list)  DoMethod(obj, GFILE_FREELIST, list)


#pragma pack()

#endif /* GADGETS_GETFILE_H */
