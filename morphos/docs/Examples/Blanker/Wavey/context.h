#ifndef BLANKER_CONTEXT_H
#define BLANKER_CONTEXT_H

#include <intuition/screens.h>
#include <exec/libraries.h>
#include <intuition/blankerapi.h>
#include <intuition/intuitionbase.h>
#include <graphics/rastport.h>

struct Context
{
	struct BTDDrawInfo *BTDDrawInfo;
	struct Library *TinyGLBase;
	struct IntuitionBase *IntuitionBase;
	struct BitMap *bitmap;
	void *tglcontext;
	int width, height;
	void *data;
	struct Library *TimerBase;
	struct timerequest treq;
	int previewmode;
};

int blankerinit(struct Context *ctx, int width, int height, struct BTDDrawInfo *btddi);
void blankerdeinit(struct Context *ctx);
void blankerdraw(struct Context *ctx);

#endif
