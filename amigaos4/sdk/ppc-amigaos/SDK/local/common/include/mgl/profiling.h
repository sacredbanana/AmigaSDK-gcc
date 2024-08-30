#ifndef _MGL_PROFILING_H_
#define _MGL_PROFILING_H_

/*
**
** Profiling
**
*/

#ifdef MGL_PROFILING

#include <proto/timer.h>

extern struct Device *TimerBase;
extern struct TimerIFace *ITimer;

typedef struct {
	struct EClockVal mark;         /* EClock stamp for elapsed time */
	uint32 numCalls;     /* Number of calls */
	uint32 totEClocks;   /* total EClock ticks */
	uint32 minEClocks;
	uint32 maxEClocks;
} MGLProfileItem;

typedef struct {
	float64         clockScale;
	uint32          profileCnt;
	const char**    profileNames;
	MGLProfileItem* profileData;
} MGLProfile;

// Ultra low latency replacement for ReadEClockVal
static inline void dbg_ReadEClock(struct EClockVal* mark)
{
	register uint32 tbcUpper0, tbcUpper1, tbcLower;
	do {
		__asm volatile (
			"mftbu %0\n\t"
			"mftb  %1\n\t"
			"mftbu %2"
			: "=r"(tbcUpper0), "=r"(tbcLower), "=r"(tbcUpper1)
		);
	} while (tbcUpper0 != tbcUpper1);
	mark->ev_hi = tbcUpper0;
	mark->ev_lo = tbcLower;
}

extern void dbg_CreateProfiling(MGLProfile*);  /* Creates MGLProfileItem set */
extern void dbg_DestroyProfiling(MGLProfile*); /* Destroy MGLProfileItem set */
extern void dbg_EndProfiling(MGLProfileItem*); /* Stop profiling */
extern void dbg_LogProfiling(MGLProfile*);     /* Dump profile data */
extern void dbg_ClearProfiling(MGLProfile*);   /* Clear profile data */

#define EMBED_PROFILE_INFO    MGLProfile mglProfile;
#define CREATE_PROFILE()      dbg_CreateProfiling(&context->mglProfile);
#define DESTROY_PROFILE()     dbg_DestroyProfiling(&context->mglProfile);
//#define PROFILE_ENTRY(f)      ITimer->ReadEClock(&(context->mglProfile.profileData[(f)].mark));
#define PROFILE_ENTRY(f)      dbg_ReadEClock(&(context->mglProfile.profileData[(f)].mark));

#define PROFILE_EXIT(f)       dbg_EndProfiling(&(context->mglProfile.profileData[(f)]));
#define LOG_PROFILE()         dbg_LogProfiling(&(context->mglProfile));
#define CLEAR_PROFILE()       dbg_ClearProfiling(&(context->mglProfile));
#define PROFILE_COUNT_ONLY(f) context->mglProfile.profileData[(f)].numCalls++;

#define PROFILE_PROTO GLcontext context,
#define PROFILE_PARAM context,

/*
#define PROFILE_ENTRY(f)
#define PROFILE_EXIT(f)
#define LOG_PROFILE()
#define CLEAR_PROFILE()
#define PROFILE_COUNT_ONLY(f)
*/
#else

#define EMBED_PROFILE_INFO
#define CREATE_PROFILE()
#define DESTROY_PROFILE()
#define PROFILE_ENTRY(f)
#define PROFILE_EXIT(f)
#define LOG_PROFILE()
#define CLEAR_PROFILE()
#define PROFILE_COUNT_ONLY(f)

#define PROFILE_PROTO 
#define PROFILE_PARAM

#endif

#endif
