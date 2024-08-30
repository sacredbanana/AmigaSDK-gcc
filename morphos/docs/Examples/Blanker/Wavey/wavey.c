#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <tgl/gl.h>
#include <tgl/gla.h>
#include <tgl/glu.h>
#include <intuition/intuition.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/exec.h>
#include <proto/tinygl.h>
#include <proto/timer.h>

#include "context.h"

#define __tglContext ctx->tglcontext
#define TinyGLBase ctx->TinyGLBase
#define TimerBase ctx->TimerBase
#define IntuitionBase ctx->IntuitionBase

struct Data
{
	int step;
	double time;
	struct timeval ptv;
	int timeinitialized;
	struct Screen *basescreen;
	struct Screen *refscreen;

	float *map;
	float *colors;
	int mapwidth, mapheight;
	float factor;
};

#define STEP data->step

#define GETDATA struct Data *data = (struct Data*)ctx->data
void kprintf(char *fmt, ...);

static void UpdateTimer(struct Context *ctx)
{
	GETDATA;

	double t;
	struct timeval tv;

	if (TimerBase->lib_Version >= 52)
		GetUTCSysTime(&tv);
	else
		GetSysTime(&tv);
	t = tv.tv_secs-data->ptv.tv_secs;
	t+= (double)(((int)tv.tv_micro)-((int)data->ptv.tv_micro)) / 1000000;
	if (data->timeinitialized == FALSE)
		data->ptv = tv;

	data->timeinitialized = TRUE;
	data->time = t * 2.5f;
}

/*
 * finds first valid screen we can use as a base. reallocates buffers if screen changes.
 * can only be called when intuition is locked.
 */

static void LookupScreen(struct Context *ctx)
{
	GETDATA;

	/* lookup some valid screen */

	struct Screen *myscr;
	ULONG monitorid = 0;

	if (data->refscreen != NULL)
	{
		GetAttr(SA_DisplayID, data->refscreen, (ULONG*)&monitorid);
		monitorid &= MONITOR_ID_MASK;
	}

	/* find the 1st screen on the monitor will be displayed at, doesn't handle pass-through atm :( */

	if (data->basescreen != NULL)
	{
		for (myscr = IntuitionBase->FirstScreen; myscr != NULL; myscr = myscr->NextScreen)
		{
			if (myscr == data->basescreen)
				return;
		}
	}

	data->basescreen = NULL;

	for (myscr = IntuitionBase->FirstScreen; myscr != NULL; myscr = myscr->NextScreen)
	{
		if (myscr != data->refscreen)
		{
			ULONG mymonid,depth;

			GetAttr(SA_DisplayID, myscr, (ULONG*)&mymonid);
			GetAttr(SA_Depth, myscr, (ULONG*)&depth);

			mymonid	&= MONITOR_ID_MASK;

			if ((data->refscreen ? mymonid == monitorid : TRUE) && (depth > 8))
			{
				if (data->basescreen == NULL || data->basescreen->Width != myscr->Width || data->basescreen->Height != myscr->Height)
				{
					/* (re)allocate memory for distortion map. It's a screen we are distorting divided into STEPxSTEP blocks */

					if (data->map != NULL) FreeVec(data->map);
					if (data->colors != NULL) FreeVec(data->colors);

					data->mapwidth = 2 + (int)ceil(myscr->Width / STEP);
					data->mapheight = 2 + (int)ceil(myscr->Height / STEP);

					data->map = AllocVec(data->mapwidth * data->mapheight * sizeof(float), MEMF_ANY | MEMF_CLEAR);
					data->colors = AllocVec(data->mapwidth * data->mapheight * sizeof(float), MEMF_ANY | MEMF_CLEAR);
					if (data->map != NULL && data->colors != NULL)
						data->basescreen = myscr;

					break;
				}
			}
		}
	}
}

static void calctilesize(int width, int height, int *tsx, int *tsy)
{
	int sx = 512, sy = 512;
	int iter = 7, i;

	/* calculate tile size. max is 512x512. smallest 32x32 */

	for(i=0; i<iter; i++)
	{
		if (sx > 32)
		{
			if (width <= sx / 2)
				sx = sx / 2;
		}

		if (sy > 32)
		{
			if (height <= sy / 2)
				sy = sy / 2;
		}
	}

	*tsx = sx;
	*tsy = sy;
}

/* calculate distortion map. use few trigonometric functions with different frequency etc. */

static void calculate_distortion(struct Context *ctx)
{
	GETDATA;
	int i, j;

	float off1 = data->time;
	float off2 = 120 + data->time * 0.3f;
	float factor = data->time * 0.01f;

	if (factor > 1.0f)
		factor = 1.0f;

	for(j = 0; j < data->mapheight; j++)
	{
		float x, y, d;

		/* calculate distortion. not the fastest way to do it but it's only an example */

		y = j;
		for(i = 0; i < data->mapwidth; i++)
		{
			x = i;
			d = 0.05f * sin(x / 4.0f + off1) * cos(y / 5.0f + off2) + 0.04f * sin(x / 12.0f + off1 * 0.3f) + 0.04f * cos(y / 8.0f + off1 * 0.2f);
			d += 0.01f * sin(-x + off1 * 1.4f) * cos(y * 0.8f + off2 * 0.9f);
			data->map[j * data->mapwidth + i] = d * factor;
		}

		/* calculate colors for previous row (we need two rows to do that). all data should be in cache still */

		if (j > 0)
		{
			for(i = 0; i < data->mapwidth - 1; i++)
			{
				float d1 = data->map[(j - 1) * data->mapwidth + i];
				float d2 = data->map[j * data->mapwidth + i + 1];
				float c = 1.0f - factor * 0.5f + (d2 - d1) * 20.0f;

				if (c > 1.0f) c = 1.0f;
				if (c < 0.0f) c = 0.0f;

				data->colors[(j - 1) * data->mapwidth + i] = c;
			}
		}
	}

	data->factor = factor;
}

/* draw distorted system bitmap on screen */

static void drawscreen(struct Context *ctx, struct BitMap *srcbm)
{
	GETDATA;
	int i, j;
	int tilesx, tilesy;
	int tile_sizex, tile_sizey;
	float inv_tile_sizex;
	float inv_tile_sizey;

	int sizex = GetBitMapAttr(srcbm, BMA_WIDTH);
	int sizey = GetBitMapAttr(srcbm, BMA_HEIGHT);

	/* tilesize depends on blitsize (nearest power of 2) */

	calctilesize(sizex, sizey, &tile_sizex, &tile_sizey);
	inv_tile_sizex = 1.0f / tile_sizex;
	inv_tile_sizey = 1.0f / tile_sizey;

	/* number of big tiles */

	tilesx = ceil((float)sizex * inv_tile_sizex);
	tilesy = ceil((float)sizey * inv_tile_sizey);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glDisable(GL_CULL_FACE);

	for (j = 0; j < tilesy; j++)
	{
		for (i = 0; i < tilesx; i++)
		{
			int tsizex, tsizey, ity, itx;

			int	x1 = i * tile_sizex;
			int	y1 = j * tile_sizey;
			int	x2 = x1 + tile_sizex;
			int	y2 = y1 + tile_sizey;

			float u1, u2, v1, v2;

			/* if image is smaller than a tile then clip tile */

			if (x2 > sizex)
				x2 = sizex;
			if (y2 > sizey)
				y2 = sizey;

			/* tilesize for texture (might be smaller than total tile size for whole blit) */

			calctilesize(x2 - x1, y2 - y1, &tsizex, &tsizey);
			u1 = v1 = 0.0f;
			u2 = (float)(x2 - x1) / tsizex;
			v2 = (float)(y2 - y1) / tsizey;

			/* transfer bitmap into the temp texture */

			GLASetAttr(__tglContext, GLA_EXTERNAL_READBUFFER_BITMAP, (ULONG)srcbm);
			glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x1, sizey - y2, tsizex, tsizey, 0);

			/* big tile is splitted into smaller tiles */

			{
				int xsteps = ceil((x2 - x1) / STEP);
				float sx1 = -0.5f + (float)x1 / sizex;
				float sy1 = 0.5f - (float)y1 / sizey;
				float sx2 = -0.5f + (float)x2 / sizex;
				float sy2 = 0.5f - (float)y2 / sizey;
				float tystep = (sy2 - sy1) / ((y2 - y1) / STEP);

				/* steps for x coordinate and texture u coordinate per block */

				float tx, txstep = (sx2 - sx1) / ((x2 - x1) / STEP);
				float tu, tustep = (u2 - u1) / (sx2 - sx1) * txstep;

				for(ity = 0; ity < ceil((y2 - y1) / STEP); ity++)
				{
					float ty1 = sy1 + (float)ity * tystep;
					float ty2 = sy1 + (float)(ity + 1) * tystep;

					/* texture coordinates are 'inverted' in y-axis */

					float tv1 = v2 + (v1 - v2) / (sy2 - sy1) * (ty1 - sy1);
					float tv2 = v2 + (v1 - v2) / (sy2 - sy1) * (ty2 - sy1);

					int offset = data->mapwidth * (j * tile_sizey / STEP + ity) + (i * tile_sizex / STEP);

					tx = sx1; tu = u1;
					glBegin(GL_TRIANGLE_STRIP);

					for(itx = 0; itx <= xsteps; itx++)
					{
						float d = data->map[offset];
						float c = data->colors[offset];
						glColor3f(c, c, c);
						glTexCoord2f(tu, 1 - tv1);
						glVertex3f(tx, ty1, d);

						d = data->map[offset + data->mapwidth];
						c = data->colors[offset + data->mapwidth];
						glColor3f(c, c, c);
						glTexCoord2f(tu, 1 - tv2);
						glVertex3f(tx, ty2, d);

						tx += txstep;
						tu += tustep;
						offset++;
					}
					glEnd();
				}
				glFlush();
			}
		}
	}

	glDisable(GL_TEXTURE_2D);
}

static void draw_wavey(struct Context *ctx)
{
	GETDATA;
	ULONG lock;

	UpdateTimer(ctx);

	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	lock = LockIBase(NULL);
	LookupScreen(ctx);

	if (data->basescreen != NULL)
	{
		/* calculate distortion map and draw distorted screen bitmap. */

		calculate_distortion(ctx);
		glTranslatef(0,0,-0.5f + data->factor * 0.02f);

		drawscreen(ctx, data->basescreen->RastPort.BitMap);
	}
	UnlockIBase(lock);

	glPopMatrix();

	GLASwapBuffers(__tglContext);
}

static int init_wavey(struct Context *ctx, struct BTDDrawInfo *btddi)
{
	GETDATA;

	data->refscreen = btddi->BDI_Screen;

	/* grid size depends on the mode: fullscreen or preview */

	data->step = ctx->previewmode ? 32 : 16;

	/* initial timer run */

	UpdateTimer(ctx);

	/* initialize simple display */

	glViewport(0, 0, ctx->width, ctx->height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90.0f, 1.0f, 0.01f, 200.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return TRUE;
}

void blankerdraw(struct Context *ctx)
{
	draw_wavey(ctx);
}

int blankerinit(struct Context *ctx, int width, int height, struct BTDDrawInfo *btddi)
{
	ctx->data = AllocVec(sizeof(struct Data), MEMF_ANY | MEMF_CLEAR);
	if (ctx->data == NULL)
		return NULL;

	__tglContext = GLInit();

	if (__tglContext != NULL)
	{
		int success = FALSE;
		struct BitMap *bm = NULL;

		if (btddi->BDI_Screen != NULL)
		{
			/* use multibuffered screen context. no need for depthbuffer */

			struct TagItem tags[] = {
				{TGL_CONTEXT_SCREEN, (ULONG)btddi->BDI_Screen},
				{TGL_CONTEXT_NODEPTH, TRUE},
				{NULL, NULL}};

			success = GLAInitializeContext(__tglContext, tags);
		}
		else
		{
			/* use offscreen bitmap context */

			bm = AllocBitMap(width, height, btddi->BDI_RPort->BitMap->Depth, BMF_MINPLANES|BMF_DISPLAYABLE|BMF_3DTARGET, btddi->BDI_RPort->BitMap);
			if (bm != NULL)
			{
				struct TagItem tags[] = {
					{TGL_CONTEXT_BITMAP, (ULONG)bm},
					{TGL_CONTEXT_NODEPTH, TRUE},
					{NULL, NULL}};

				success = GLAInitializeContext(__tglContext, tags);
			}
		}

		if (success)
		{
			ctx->bitmap = bm;
			ctx->width = width;
			ctx->height = height;

			if (init_wavey(ctx, btddi))
				return TRUE;

			GLADestroyContext(__tglContext);
		}

		if (bm != NULL)
			FreeBitMap(bm);

		GLClose(__tglContext);

		FreeVec(ctx->data);
	}

	return FALSE;
}

void blankerdeinit(struct Context *ctx)
{
	GETDATA;

	GLADestroyContext(__tglContext);
	GLClose(__tglContext);

	if (ctx->bitmap != NULL)
		FreeBitMap(ctx->bitmap);

	if (data->map != NULL) FreeVec(data->map);
	if (data->colors != NULL) FreeVec(data->colors);
	FreeVec(data);
}

