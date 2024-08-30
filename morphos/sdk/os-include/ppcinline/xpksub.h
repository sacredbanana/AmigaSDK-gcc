#ifndef _INLINE_XPKSUB_H
#define _INLINE_XPKSUB_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif

#ifndef XPKSUB_BASE_NAME
#define XPKSUB_BASE_NAME XpkSubBase
#endif

#define XpksPackerInfo() \
	LP0(0x1E, struct XpkInfo *, XpksPackerInfo, \
	, XPKSUB_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpksPackChunk(xpar) \
	LP1(0x24, LONG, XpksPackChunk, struct XpkSubParams *, xpar, a0, \
	, XPKSUB_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpksPackFree(xpar) \
	LP1NR(0x2A, XpksPackFree, struct XpkSubParams *, xpar, a0, \
	, XPKSUB_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpksPackReset(xpar) \
	LP1(0x30, LONG, XpksPackReset, struct XpkSubParams *, xpar, a0, \
	, XPKSUB_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpksUnpackChunk(xpar) \
	LP1(0x36, LONG, XpksUnpackChunk, struct XpkSubParams *, xpar, a0, \
	, XPKSUB_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define XpksUnpackFree(xpar) \
	LP1NR(0x3C, XpksUnpackFree, struct XpkSubParams *, xpar, a0, \
	, XPKSUB_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#endif /*  _INLINE_XPKSUB_H  */