/*
** Window.c - Demonstrates how to open a window with scrollers and arrows properly.
** Build with: gcc -noixemul -o window window.c
**
** This code will work on both V50 and V39+ intuition.
**
** The INTUITIONV50 code works only on MorphOS. The <50 code works on both V39 and V50
** and should work without any problems with any patches like VisualPrefs, etc. Do note
** that V50 code doesn't need to use struct Image or struct Gadget, just BOOPSI calls.
**
** ©2003-2008 by Jacek Piszczek of MorphOS Development Team
*/

#include <proto/exec.h>
#include <proto/intuition.h>

#include <intuition/intuition.h>
#include <intuition/imageclass.h>
#include <intuition/gadgetclass.h>
#include <intuition/extensions.h>
#include <intuition/screens.h>

struct ExecBase *SysBase = NULL;
struct IntuitionBase *IntuitionBase = NULL;

Object *makearrow(ULONG type,Object *previous,struct Screen *screen);
Object *makeprop(ULONG freedom,Object *previous,struct Screen *screen);
Object *disposearrow(Object *gadget);
Object *disposeprop(Object *gadget);

#define INTUITIONV50 (((struct Library *)IntuitionBase)->lib_Version >= 50)

int main(void)
{
	SysBase = *((struct ExecBase**) 4);

	if ((IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",39)))
	{
		struct Window *window = NULL;
		struct Screen *screen = LockPubScreen(NULL);
		struct DrawInfo *dinfo = NULL;
		BOOL working = TRUE;

		Object *firstgadget = NULL, *gadget = NULL, *propgadget;

		if (!screen) goto fail;

		if (!(dinfo = GetScreenDrawInfo(screen))) goto fail;

		if (!(gadget = firstgadget = makearrow(UPIMAGE,0,screen))) goto fail;
		if (!(gadget = makearrow(DOWNIMAGE,gadget,screen))) goto fail;
		if (!(gadget = makearrow(LEFTIMAGE,gadget,screen))) goto fail;
		if (!(gadget = makearrow(RIGHTIMAGE,gadget,screen))) goto fail;
		if (!(gadget = propgadget = makeprop(FREEHORIZ,gadget,screen))) goto fail;
		if (!(gadget = makeprop(FREEVERT,gadget,screen))) goto fail;

		window = OpenWindowTags(0,WA_PubScreen,screen,
		                          WA_Title,"window.c",
		                          WA_Width,200,
		                          WA_Height,200,
		                          WA_MaxWidth,-1,
		                          WA_MaxHeight,-1,
		                          WA_Flags,WFLG_SIZEGADGET|
		                                   WFLG_SIZEBRIGHT|
		                                   WFLG_SIZEBBOTTOM|
		                                   WFLG_CLOSEGADGET|
		                                   WFLG_DEPTHGADGET|
		                                   WFLG_DRAGBAR,
		                          WA_IDCMP,IDCMP_CLOSEWINDOW|
		                                   IDCMP_REFRESHWINDOW,
		                          WA_SimpleRefresh,TRUE,
		                          (INTUITIONV50) ? WA_SkinInfo : TAG_IGNORE,0,
		                          WA_Gadgets,firstgadget,
		                          TAG_DONE);

		if (!window) goto fail;

		while (working)
		{
			struct IntuiMessage *imsg;

			WaitPort(window->UserPort);

			while ((imsg = (struct IntuiMessage *)GetMsg(window->UserPort)))
			{
				switch (imsg->Class)
				{
					case IDCMP_CLOSEWINDOW:
						working = FALSE;
						break;

					case IDCMP_REFRESHWINDOW:
						BeginRefresh(window);
						EndRefresh(window,TRUE);
						break;
				}

				ReplyMsg((struct Message *)imsg);
			}
		}


fail:
		if (window)
		{
			RemoveGList(window,(struct Gadget *)firstgadget,-1);
			CloseWindow(window);
		}
		
		//kill gadgets
		{
			WORD gadgetno;

			gadget = firstgadget;

			for (gadgetno = 0; gadgetno < 4; gadgetno ++)
			{
				gadget = disposearrow(gadget);
			}

			if (propgadget) gadget = disposeprop(propgadget);
			if (gadget) disposeprop(gadget);
		}

		if (dinfo) FreeScreenDrawInfo(screen,dinfo);
		if (screen) UnlockPubScreen(NULL,screen);
		CloseLibrary((struct Library *)IntuitionBase);
	}

	return 0;
}

Object *makearrow(ULONG type,Object *previous,struct Screen *screen)
{
	struct DrawInfo *dri = NULL;
	Object *button = NULL;
	Object *image = NULL;
	ULONG w,h,relright,relbottom;
	ULONG sizew,sizeh;

	if (!(dri = GetScreenDrawInfo(screen))) return NULL;

	/* Create the image we need */

	image = NewObject(NULL,SYSICLASS,
	                       SYSIA_DrawInfo,dri,
	                       SYSIA_Which,type,
	                       TAG_DONE);

	if (!image)
	{
		FreeScreenDrawInfo(screen,dri);

		return NULL;
	}

	/* get default size for this screen */

	GetAttr(IA_Width,image,&w);
	GetAttr(IA_Height,image,&h);

	/* now we need to find out sizegad size to place our gadgets properly */

	if (INTUITIONV50)
	{

		sizew = GetSkinInfoAttr(dri, SI_BorderRightSize, NULL);
		sizeh = GetSkinInfoAttr(dri, SI_BorderBottomSize, NULL);

	} else {
		Object *sizeimage = NewObject(NULL,SYSICLASS,
		                                   SYSIA_DrawInfo,dri,
		                                   SYSIA_Which,SIZEIMAGE,
		                                   TAG_DONE);
		if (!sizeimage)
		{
			/* NewObject failed = we're low on mem */
			DisposeObject(image);

			FreeScreenDrawInfo(screen,dri);

			return NULL;
		}

		GetAttr(IA_Width,sizeimage,&sizew);
		GetAttr(IA_Height,sizeimage,&sizeh);

		DisposeObject(sizeimage);
	}

	/* let's calculate button position now */

	/* NOTE: it is safe to assume that UP/DOWN & LEFT/RIGHT arrows have the same dimmensions
	** this cannot be changed for design & compatibility issues and is true for both
	** V40 and V50 Intuition.
	*/

	switch (type)
	{
		case UPIMAGE:
			relright  = - w + 1;
			relbottom = - (h * 2) - sizeh + 1;
			break;

		case DOWNIMAGE:
			relright  = - w + 1;
			relbottom = - h - sizeh + 1;
			break;

		case LEFTIMAGE:
			relright  = - (w * 2) - sizew + 1;
			relbottom = - h + 1;
			break;

		case RIGHTIMAGE:
			relright  = - w - sizew + 1;
			relbottom = - h + 1;
			break;
	}

	button = NewObject(NULL,BUTTONGCLASS,
	                        GA_DrawInfo,dri,
	                        GA_RelRight,relright,
	                        GA_RelBottom,relbottom,
	                        GA_Width,w,
	                        GA_Height,h,
	                        GA_Image,image,
	                        GA_Previous,previous,
	                        TAG_DONE);

	if (!button) DisposeObject(image);

	FreeScreenDrawInfo(screen,dri);

	return button;
}

Object *makeprop(ULONG freedom,Object *previous,struct Screen *screen)
{
	struct DrawInfo *dri = NULL;
	Object *button = NULL;
	ULONG w,h,relright,relbottom,relwidth,relheight,top;

	if (!(dri = GetScreenDrawInfo(screen))) return NULL;

	relwidth = relheight = 0;

	if (INTUITIONV50)
	{
		top = GetSkinInfoAttr(dri, SI_BorderTopTitle, NULL);

		relwidth -= GetSkinInfoAttr(dri, SI_BorderRightSize, NULL) +
		            GetSkinInfoAttr(dri, SI_BottomArrowBox, NULL) + 4;
		relheight -= GetSkinInfoAttr(dri, SI_BorderBottomSize, NULL) +
		             GetSkinInfoAttr(dri, SI_RightArrowBox, NULL) + top + 2;

		w = GetSkinInfoAttr(dri,SI_RightPropWidth, NULL); relright = - w - 1;
		h = GetSkinInfoAttr(dri,SI_BottomPropHeight, NULL); relbottom = - h - 1;

	} else {
		ULONG imw,imh;
		Object *image = NewObject(NULL,SYSICLASS,
		                               SYSIA_DrawInfo,dri,
		                               SYSIA_Which,SIZEIMAGE,
		                               TAG_DONE);
		if (!image)
		{
			/* NewObject failed = we're low on mem */

			FreeScreenDrawInfo(screen,dri);

			return NULL;
		}

		/* calculate sizeimage size 1st */

		GetAttr(IA_Width,image,&imw);
		GetAttr(IA_Height,image,&imh);

		DisposeObject(image);

		top = screen->WBorTop + dri->dri_Font->tf_YSize + 1;

		relwidth -= imw;
		relheight -= imh + top;

		w = imw - 4;

		/* Standard V40 size gadget doesn't have 1:1 aspect. In case we have a non 1:1 gadget we
		need to adjust vertical scroller size properly */

		if (imw != imh) w -= 4;

		relright = - w - 1;

		if (imw != imh) relright -= 2;

		h = imh - 4;
		relbottom = - h - 1;

		/* now for arrow size */

		image = NewObject(NULL,SYSICLASS,
		                       SYSIA_DrawInfo,dri,
		                       SYSIA_Which,(freedom == FREEHORIZ) ? LEFTIMAGE : UPIMAGE,
		                       TAG_DONE);
		if (!image)
		{
			/* NewObject failed = we're low on mem */

			FreeScreenDrawInfo(screen,dri);

			return NULL;
		}

		GetAttr(IA_Width,image,&imw);
		GetAttr(IA_Height,image,&imh);

		DisposeObject(image);

		relwidth -= (imw * 2) + 4;
		relheight -= (imh * 2) + 2;
	}

	switch (freedom)
	{
		case FREEVERT:
			button = NewObject(NULL,PROPGCLASS,
			                        GA_Previous,previous,
			                        GA_Top,top + 1,
			                        GA_Width,w,
			                        GA_RelHeight,relheight,
			                        GA_RelRight,relright,
			                        PGA_Freedom,freedom,
			                        PGA_Borderless,TRUE,
			                        PGA_NewLook, TRUE,
			                        PGA_Total,1,
			                        PGA_Visible,1,
			                        TAG_DONE);
			break;

		case FREEHORIZ:
			button = NewObject(NULL,PROPGCLASS,
			                        GA_Previous,previous,
			                        GA_Left,3,
			                        GA_Height,h,
			                        GA_RelWidth,relwidth,
			                        GA_RelBottom,relbottom,
			                        PGA_Freedom,freedom,
			                        PGA_Borderless,TRUE,
			                        PGA_NewLook, TRUE,
			                        PGA_Total,1,
			                        PGA_Visible,1,
			                        TAG_DONE);
			break;
	}

	FreeScreenDrawInfo(screen,dri);

	return button;
}

Object *disposearrow(Object *gadget)
{
	Object *nextgadget;
	Object *image;

	if (!gadget) return 0;

	if (INTUITIONV50)
	{
		GetAttr(GA_Next,gadget,(ULONG*)&nextgadget);
		GetAttr(GA_Image,gadget,(ULONG*)&image);
		if (image) DisposeObject(image);
	} else {
		nextgadget = (Object *)((struct Gadget *)gadget)->NextGadget;
		image = (Object *)((struct Gadget *)gadget)->GadgetRender;
		if (image) DisposeObject(image);
	}

	DisposeObject(gadget);

	return nextgadget;
}

Object *disposeprop(Object *gadget)
{
	Object *nextgadget;

	if (!gadget) return 0;

	if (INTUITIONV50)
	{
		GetAttr(GA_Next,gadget,(ULONG*)&nextgadget);
	} else {
		nextgadget = (Object *)((struct Gadget *)gadget)->NextGadget;
	}

	DisposeObject(gadget);

	return nextgadget;
}

