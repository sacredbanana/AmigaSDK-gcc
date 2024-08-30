#ifndef POWERUP_PPCLIB_TIME_H
#define POWERUP_PPCLIB_TIME_H

#define	PPCTIMERTAG_Dummy		(TAG_USER + 0x24000)

/* PPCCreateTimerObject Tags */

/* ptr to an optional error reason field
 */
#define	PPCTIMERTAG_ERROR		(PPCTIMERTAG_Dummy + 0x0)

/* use the CPU timer to do simple synchron
 * timer based operations
 */
#define	PPCTIMERTAG_CPU			(PPCTIMERTAG_Dummy + 0x1)

/* create a job in a 50Hz timer queue
 * which will send your task a signal after
 * the ticks you specified run to zero.
 * You specify the number of 50Hz ticks
 * with the Tag.
 */
#define	PPCTIMERTAG_50HZ		(PPCTIMERTAG_Dummy + 0x2)

/* The signalmask necessary for the 50Hz
 * timer to signal your task
 */
#define	PPCTIMERTAG_SIGNALMASK		(PPCTIMERTAG_Dummy + 0x3)

/* After the ticks ran down and the task
 * is signaled the timer request is removed from the queue.
 */
#define	PPCTIMERTAG_AUTOREMOVE		(PPCTIMERTAG_Dummy + 0x4)


/* PPCSetTimerObject() Tags */


/* Start Timer,Start Job(add to the joblist) or
 * Start ticks for PPCGetTimerObject()
 */
#define	PPCTIMERTAG_START		(PPCTIMERTAG_Dummy + 0x11)

/* Stop Timer,Stop Job(remove from the joblist) or
 * Stop ticks for PPCGetTimerObject()
 */
#define	PPCTIMERTAG_STOP		(PPCTIMERTAG_Dummy + 0x12)

/* PPCGetTimerObject() Tags */

/* Get ticks per second */
#define	PPCTIMERTAG_TICKSPERSEC		(PPCTIMERTAG_Dummy + 0x13)

/* Get current ticks */
#define	PPCTIMERTAG_CURRENTTICKS	(PPCTIMERTAG_Dummy + 0x14)

/* Get diff ticks after a start and stop */
#define	PPCTIMERTAG_DIFFTICKS		(PPCTIMERTAG_Dummy + 0x15)

/* Get diff microseconds after a start and stop */
#define	PPCTIMERTAG_DIFFMICRO		(PPCTIMERTAG_Dummy + 0x16)

/* Get diff seconds after a start and stop */
#define	PPCTIMERTAG_DIFFSECS		(PPCTIMERTAG_Dummy + 0x17)

/* Get diff minutes after a start and stop */
#define	PPCTIMERTAG_DIFFMINS		(PPCTIMERTAG_Dummy + 0x18)

/* Get diff hours after a start and stop */
#define	PPCTIMERTAG_DIFFHOURS		(PPCTIMERTAG_Dummy + 0x19)

/* Get diff days after a start and stop */
#define	PPCTIMERTAG_DIFFDAYS		(PPCTIMERTAG_Dummy + 0x1a)



#define	PPCTIMERERROR_OK	0
#define	PPCTIMERERROR_MEMORY	1





#endif
