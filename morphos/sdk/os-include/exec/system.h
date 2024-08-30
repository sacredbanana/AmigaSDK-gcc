#ifndef EXEC_SYSTEM_H
#define EXEC_SYSTEM_H

/*
	exec system definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#define SYSTEMINFOTYPE_SYSTEM               0x0
#define SYSTEMINFOTYPE_MACHINE              0x1


#define SYSTEMINFOTYPE_PPC_CPUVERSION       0x2
#define SYSTEMINFOTYPE_PPC_CPUREVISION      0x3
#define SYSTEMINFOTYPE_PPC_CPUCLOCK         0x4
#define SYSTEMINFOTYPE_PPC_BUSCLOCK         0x5

#define SYSTEMINFOTYPE_PPC_ICACHEL1SIZE     0x10
#define SYSTEMINFOTYPE_PPC_ICACHEL1LINES    0x11
#define SYSTEMINFOTYPE_PPC_ICACHEL1LINESIZE 0x12
#define SYSTEMINFOTYPE_PPC_DCACHEL1SIZE     0x13
#define SYSTEMINFOTYPE_PPC_DCACHEL1LINES    0x14
#define SYSTEMINFOTYPE_PPC_DCACHEL1LINESIZE 0x15
#define SYSTEMINFOTYPE_PPC_CACHEL1TYPE      0x16
#define SYSTEMINFOTYPE_PPC_CACHEL1FLAGS     0x17

#define SYSTEMINFOTYPE_PPC_ICACHEL2SIZE     0x20
#define SYSTEMINFOTYPE_PPC_ICACHEL2LINES    0x21
#define SYSTEMINFOTYPE_PPC_ICACHEL2LINESIZE 0x22
#define SYSTEMINFOTYPE_PPC_DCACHEL2SIZE     0x23
#define SYSTEMINFOTYPE_PPC_DCACHEL2LINES    0x24
#define SYSTEMINFOTYPE_PPC_DCACHEL2LINESIZE 0x25
#define SYSTEMINFOTYPE_PPC_CACHEL2TYPE      0x26
#define SYSTEMINFOTYPE_PPC_CACHEL2FLAGS     0x27

#define SYSTEMINFOTYPE_PPC_ICACHEL3SIZE     0x30
#define SYSTEMINFOTYPE_PPC_ICACHEL3LINES    0x31
#define SYSTEMINFOTYPE_PPC_ICACHEL3LINESIZE 0x32
#define SYSTEMINFOTYPE_PPC_DCACHEL3SIZE     0x33
#define SYSTEMINFOTYPE_PPC_DCACHEL3LINES    0x34
#define SYSTEMINFOTYPE_PPC_DCACHEL3LINESIZE 0x35
#define SYSTEMINFOTYPE_PPC_CACHEL3TYPE      0x36
#define SYSTEMINFOTYPE_PPC_CACHEL3FLAGS     0x37

#define SYSTEMINFOTYPE_PPC_TLBENTRIES       0x40
#define SYSTEMINFOTYPE_PPC_TLBSETS          0x41

/*
 * PowerPC has a FPU
 */
#define SYSTEMINFOTYPE_PPC_FPU              0x50
/*
 * PowerPC has an Altivec unit
 */
#define SYSTEMINFOTYPE_PPC_ALTIVEC          0x51
/*
 * PowerPC has performance measurement cpu extension
 */
#define SYSTEMINFOTYPE_PPC_PERFMONITOR      0x52
/*
 * PowerPC has datastream cpu extension.
 */
#define SYSTEMINFOTYPE_PPC_DATASTREAM       0x53
/*
 * Reservation Size
 */
#define SYSTEMINFOTYPE_PPC_RESERVATIONSIZE  0x60
/*
 * Bus Timer Ticks
 */
#define SYSTEMINFOTYPE_PPC_BUSTICKS         0x61
/*
 * CPU Temperature in 8.24 fixedpoint, degrees celcius
 */
#define SYSTEMINFOTYPE_PPC_CPUTEMP          0x62
/*
 * PowerPC has Data Address Breakpoint Register (DABR)
 */
#define SYSTEMINFOTYPE_PPC_DABR             0x63

/*
 * MMU Page Size
 */
#define SYSTEMINFOTYPE_PAGESIZE             0x100
/*
 * Number of CPUs, doesn't mean they are all supported by exec
 */
#define SYSTEMINFOTYPE_CPUCOUNT             0x101

/*
 * Global Scheduler statistics (exec 50.42)
 */
#define SYSTEMINFOTYPE_TBCLOCKFREQUENCY         0x200
#define SYSTEMINFOTYPE_UPTIMETICKS              0x201
#define SYSTEMINFOTYPE_LASTSECTICKS             0x202
#define SYSTEMINFOTYPE_RECENTTICKS              0x203
#define SYSTEMINFOTYPE_CPUTIME                  0x204
#define SYSTEMINFOTYPE_LASTSECCPUTIME           0x205
#define SYSTEMINFOTYPE_RECENTCPUTIME            0x206
#define SYSTEMINFOTYPE_VOLUNTARYCSW             0x207
#define SYSTEMINFOTYPE_INVOLUNTARYCSW           0x208
#define SYSTEMINFOTYPE_LASTSECVOLUNTARYCSW      0x209
#define SYSTEMINFOTYPE_LASTSECINVOLUNTARYCSW    0x20a
#define SYSTEMINFOTYPE_LOADAVG1                 0x20b
#define SYSTEMINFOTYPE_LOADAVG2                 0x20c
#define SYSTEMINFOTYPE_LOADAVG3                 0x20d
/* Added in exec 50.45 */
#define SYSTEMINFOTYPE_TASKSCREATED             0x20e
#define SYSTEMINFOTYPE_TASKSFINISHED            0x20f
#define SYSTEMINFOTYPE_LAUNCHTIMETICKS          0x210
#define SYSTEMINFOTYPE_LAUNCHTIMETICKS1978      0x211
#define SYSTEMINFOTYPE_TASKSRUNNING             0x212
#define SYSTEMINFOTYPE_TASKSSLEEPING            0x213

/* Added in exec 50.54 */
/*
 * read only
 */
#define SYSTEMINFOTYPE_EMULHANDLESIZE           0x217
/*
 * The system's global native exception handler's msgport.
 * Is overruled by task's native exception handler msgports.
 */
#define SYSTEMINFOTYPE_EXCEPTIONMSGPORT         0x218
/*
 * The system's global task exit code.
 * Is overruled by a custom exitcode in task generation.
 */
#define SYSTEMINFOTYPE_TASKEXITCODE             0x219
/*
 * The system's global 68k task exit code.
 * Is overruled by a custom exitcode in task generation.
 */
#define SYSTEMINFOTYPE_TASKEXITCODE_M68K        0x21a

/* Added in exec 50.58 */
/*
 * emulation area start
 * read only
 */
#define SYSTEMINFOTYPE_EMULATION_START          0x230
/*
 * emulation area size
 * read only
 */
#define SYSTEMINFOTYPE_EMULATION_SIZE           0x231
/*
 * module area address
 * read only
 */
#define SYSTEMINFOTYPE_MODULE_START             0x232
/*
 * module area size
 * read only
 */
#define SYSTEMINFOTYPE_MODULE_SIZE              0x233

/* Added in exec 50.67 */
/*
 * The system's global 68k exception handler's msgport.
 * Is overruled by task's native exception 68k handler msgports
 * and that's overruled by the task's 68k traphandler
 */
#define SYSTEMINFOTYPE_EXCEPTIONMSGPORT_68K     0x234
/*
 * The system's global alert handler's msgport.
 */
#define SYSTEMINFOTYPE_ALERTMSGPORT             0x235

/* Added in exec 50.68 */
/*
 * The system vendor string
 */
#define SYSTEMINFOTYPE_VENDOR                   0x236
/*
 * The system revision string
 */
#define SYSTEMINFOTYPE_REVISION                 0x237

/* Added in exec 50.73 */
/*
 * Magic fields in execbase
 */
#define SYSTEMINFOTYPE_MAGIC1                   0x238
#define SYSTEMINFOTYPE_MAGIC2                   0x239
/* Added in exec 51.3 */
#define SYSTEMINFOTYPE_MAXHITCOUNT		0x23a
/* Added in exec 51.13 */
#define SYSTEMINFOTYPE_MAXALERTCOUNT		0x23b
/* Added in exec 51.25 */
#define SYSTEMINFOTYPE_REGUSER                  0x23c

/*
 * Fills 'struct FreeBlocksData' structure, with each struct MemEntry
 * representing single free block. Normally all free blocks in all memory
 * headers are scanned, but SYSTEMINFOTAG_MEMHEADER can be used to limit
 * the scanning to a single memory header. If successfull,
 * NewGetSystemAttrs return TRUE, and then fbd_NumBlocks contains the
 * number of struct MemEntry entries filled.
 *
 * You can also use SYSTEMINFOTAG_HOOK to have your custom hook called
 * rather than having array being filled. The hook is called within
 * Forbid() and the forbid must NOT be broken. The hook is called with:
 *  A0 - struct Hook *
 *  A1 - struct MemEntry *
 *  A2 - struct MemHeader *
 * The hook must return success/failure indicator, returning FALSE causes
 * the NewGetSystemAttrs call to abort instantly and return FALSE.
 */
/* Added in exec 51.32 */
#define SYSTEMINFOTYPE_FREEBLOCKS               0x23d

/* Added in exec 51.38 */
/*
 * CPU name as a string
 * e.g. "603E", "7448", "970FX", "Unknown"
 * read only
 */
#define SYSTEMINFOTYPE_CPUNAME                  0x23e
/*
 * CPU family name as a string
 * e.g. "G1", "G2", "G4", "G5", "Unknown"
 * read only
 */
#define SYSTEMINFOTYPE_CPUFAMILYNAME            0x23f

#define SYSTEMINFOTAG_DUMMY     (TAG_USER + 0x112000)
#define SYSTEMINFOTAG_CPUINDEX  (SYSTEMINFOTAG_DUMMY + 0x0)
#define SYSTEMINFOTAG_MEMHEADER (SYSTEMINFOTAG_DUMMY + 0x1)
#define SYSTEMINFOTAG_HOOK      (SYSTEMINFOTAG_DUMMY + 0x2)

/*
 * Return LONG nonzero value if system implements a new fairer
 * task scheduler.
*/
#define SYSTEMINFOTYPE_NEWSCHEDULER             0x242
#endif
