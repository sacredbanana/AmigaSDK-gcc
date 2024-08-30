
#include <exec/exec.h>
#include <graphics/rastport.h>
#include <libraries/iffparse.h>
#include <intuition/blankerapi.h>
#include <intuition/screens.h>
#include <libraries/query.h>

#include <proto/exec.h>
#include <proto/utility.h>
#include <proto/graphics.h>
#include <proto/dos.h>

#include "context.h"
#include "version.h"

char MyBlankerName[] = "wavey.btd";
char MyBlankerID[]   = "$VER: " VERS " (" __AMIGADATE__ ") © 2008 Michal Wozniak";

struct TagItem MyBlankerQueryTags[] =
{
	{QUERYINFOATTR_NAME,(ULONG)MyBlankerName},
	{QUERYINFOATTR_DESCRIPTION,(ULONG)MyBlankerID},
	{QUERYINFOATTR_AUTHOR,(ULONG)"Michal Wozniak"},
	{QUERYINFOATTR_VERSION,(ULONG)VERSION},
	{QUERYINFOATTR_REVISION,(ULONG)REVISION},
	{TAG_DONE,0}
};

struct GfxBase *GfxBase;

static struct BTDInfo info =
{
	BTDI_Revision,                                /* API version                  */
	MAKE_ID('W', 'A', 'V', 'E'),                  /* ID for prefs window snapshot */
	"Wavey",                                      /* blanker name                 */
	"Desktop image deformation effect",           /* description                  */
	"Michal Wozniak",                             /* author(s)                    */
	BTDIF_3DBlanker|BTDIF_DoNotWait,              /* flags                        */
	0                                             /* config options               */
};

LONG MyBlankerLibInit()
{
	GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 0);
	return GfxBase != NULL ? TRUE : FALSE;
}

void MyBlankerLibFree()
{
	CloseLibrary((struct Library *)GfxBase);
}

struct BTDInfo *QueryMyBlanker()
{
	return &info;
}

struct Context *InitMyBlanker(struct TagItem *TagList)
{
	struct BTDDrawInfo *BTDDrawInfo;
	struct Context *ctx;
	struct Library *UtilityBase;
	struct Library *IntuitionBase;
	struct Library *TinyGLBase;

	TinyGLBase = OpenLibrary("tinygl.library", 51);
	if (TinyGLBase != NULL)
	{
		UtilityBase = OpenLibrary("utility.library", 50);
		if (UtilityBase != NULL)
		{
			IntuitionBase = OpenLibrary("intuition.library", 51);
			if (IntuitionBase != NULL)
			{
				BTDDrawInfo = (struct BTDDrawInfo *)GetTagData(BTD_DrawInfo, 0, TagList);
				if (BTDDrawInfo != NULL)
				{
					ctx	= AllocVec(sizeof(*ctx), MEMF_CLEAR);
					if (ctx != NULL)
					{
						ctx->treq.tr_node.io_Message.mn_Node.ln_Type = NT_REPLYMSG;
						ctx->treq.tr_node.io_Message.mn_ReplyPort = 0;
						ctx->treq.tr_node.io_Message.mn_Length = sizeof(ctx->treq);
						ctx->treq.tr_node.io_Flags = IOF_QUICK;

						if (OpenDevice("timer.device", UNIT_MICROHZ, (struct IORequest *)&ctx->treq, 0) == 0)
						{
							ctx->BTDDrawInfo = BTDDrawInfo;
							ctx->TinyGLBase = TinyGLBase;
							ctx->TimerBase = (struct Library *)ctx->treq.tr_node.io_Device;
							ctx->IntuitionBase = (struct IntuitionBase*)IntuitionBase;
							ctx->previewmode = GetTagData(BTD_PreviewMode, FALSE, TagList) ? TRUE : FALSE;
							if (blankerinit(ctx, BTDDrawInfo->BDI_Width, BTDDrawInfo->BDI_Height, BTDDrawInfo))
							{
								CloseLibrary(UtilityBase);
								return ctx;
							}

							CloseDevice((struct IORequest *)&ctx->treq);
						}

						FreeVec(ctx);
					}
				}
				CloseLibrary(IntuitionBase);
			}
			CloseLibrary(UtilityBase);
		}
		CloseLibrary(TinyGLBase);
	}

	return 0;
}

void EndMyBlanker(struct Context *ctx)
{
	blankerdeinit(ctx);
	CloseLibrary(ctx->TinyGLBase);
	CloseLibrary((struct Library*)ctx->IntuitionBase);
	CloseDevice((struct IORequest *)&ctx->treq);

	FreeVec(ctx);
}

void AnimMyBlanker(struct Context *ctx)
{
	struct BTDDrawInfo *btddi = ctx->BTDDrawInfo;

	/* render blanker. in case of fullscreen context it will swap the buffers itself */

	blankerdraw(ctx);

	/* in case we are using bitmap for rendering, blit it */

	if (ctx->bitmap != NULL)
	{
		if (btddi->BDI_Screen != NULL)
			WaitBOVP(&btddi->BDI_Screen->ViewPort);


		BltBitMapRastPort(ctx->bitmap, 0, 0, btddi->BDI_RPort, btddi->BDI_Left, btddi->BDI_Top, btddi->BDI_Width, btddi->BDI_Height, 0xc0);
	}
}

ULONG PenCountMyBlanker(struct TagItem *TagList)
{
	return 0;
}
