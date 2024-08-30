#ifndef POWERUP_PPCLIB_MEMORY_H
#define POWERUP_PPCLIB_MEMORY_H


/* Allocate Memory with the Pages marked as writethrough
   on the PPC. This means the whole memory size which is allocated
   is aligned to 4k pages. So you better use Pools.
 */
   
#define MEMF_WRITETHROUGHPPC	(1L<<22)	/* WriteThrough Pools */

/* Allocate Memory with the Pages marked as writethrough
   on the PPC. This means the whole memory size which is allocated
   is aligned to 4k pages. So you better use Pools.
   (V46)
 */
   
#define MEMF_WRITETHROUGHM68K	(1L<<23)	/* WriteThrough Pools */

/* Allocate Memory with the Pages marked as NOCACHE (not synchronisized)
   on the PPC. This means the whole memory size which is allocated
   is aligned to 4k pages. So you better use Pools.
   (V46)
 */
   
#define MEMF_NOCACHEPPC		(1L<<24)	/* NoCache Pools */

/* Allocate Memory with the Pages marked as NOCACHE
   on the M68k. This means the whole memory size which is allocated
   is aligned to 4k pages. So you better use Pools.
   (V46)
 */
#define MEMF_NOCACHEM68K	(1L<<25)	/* NoCache Pools */

/* Allocate Memory with the Pages marked as NOCACHE GUARD(synchronisized)
   on the PPC. This means the whole memory size which is allocated
   is aligned to 4k pages. So you better use Pools.
   (V46)
 */
   
#define MEMF_NOCACHESYNCPPC	(1L<<29)	/* NoCache synchronized Pools */

/* Allocate Memory with the Pages marked as NOCACHE synchronisized
   on the M68k. This means the whole memory size which is allocated
   is aligned to 4k pages. So you better use Pools.
 */
#define MEMF_NOCACHESYNCM68K	(1L<<30)	/* NoCache synchronized Pools */



#define MEMF_PPCMASK		(MEMF_NOCACHEPPC |		\
                                 MEMF_NOCACHEM68K |		\
                                 MEMF_NOCACHESYNCPPC |		\
                                 MEMF_NOCACHESYNCM68K |		\
                                 MEMF_WRITETHROUGHPPC |		\
                                 MEMF_WRITETHROUGHM68K)

#endif
