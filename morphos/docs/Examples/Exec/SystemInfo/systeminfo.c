#include <exec/libraries.h>
#include <exec/system.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <stdio.h>
#include "systeminfo.h"

const char Version[]=VERSTAG;

/* Current known PowerPC CPU versions */
#define	CPU_601		1
#define	CPU_603		3
#define	CPU_604		4
#define	CPU_602		5
#define	CPU_603e	6
#define	CPU_603p	7
#define	CPU_750		8
#define	CPU_604e	9
#define	CPU_604ev	10
#define	CPU_7400	12
#define	CPU_7410	12	/* revision 0x1xxx */
#define	CPU_7450	0x8000
#define	CPU_7455	0x8001
#define	CPU_7457	0x8002
#define	CPU_7447A	0x8003
#define	CPU_7448	0x8004
#define	CPU_5200	0x8011
#define	CPU_750FX	0x7000
#define	CPU_970		0x0039
#define	CPU_970FX	0x003C
#define	CPU_970MP	0x0044

int main(void)
{
struct ExecBase		*SysBase;
struct DosLibrary	*DOSBase;
struct Library		*UtilityBase;
char			System[256];
char			Vendor[256];
char			Revision[256];
char			Buffer[256];
ULONG			Machine;
char			*MachineStr;
ULONG			CPUVersion;
ULONG			CPURevision;
char			*CPUType;
/* Bottom 2 entries should be 64 bit
 * but because of Printf usage i was too lazy:-)
 */
UQUAD			CPUClock;
UQUAD			BUSClock;
ULONG			TLBEntries;
ULONG			TLBSets;
ULONG			CacheL1Type=0;
ULONG			CacheL1Flags=0;
ULONG			ICacheL1Size=0;
ULONG			ICacheL1Lines=0;
ULONG			ICacheL1LineSize=0;
ULONG			DCacheL1Size=0;
ULONG			DCacheL1Lines=0;
ULONG			DCacheL1LineSize=0;
ULONG			CacheL2Type=0;
ULONG			CacheL2Flags=0;
ULONG			ICacheL2Size=0;
ULONG			ICacheL2Lines=0;
ULONG			ICacheL2LineSize=0;
ULONG			DCacheL2Size=0;
ULONG			DCacheL2Lines=0;
ULONG			DCacheL2LineSize=0;
ULONG			CacheL3Type=0;
ULONG			CacheL3Flags=0;
ULONG			ICacheL3Size=0;
ULONG			ICacheL3Lines=0;
ULONG			ICacheL3LineSize=0;
ULONG			DCacheL3Size=0;
ULONG			DCacheL3Lines=0;
ULONG			DCacheL3LineSize=0;
ULONG			FPU=0;
ULONG			Altivec=0;
ULONG			PerfMonitor=0;
ULONG			DataStream=0;
ULONG			ReservationSize=0;
ULONG			BusTicks=0;

  SysBase	=	*((struct ExecBase**) 4);  
  if ((DOSBase=(struct DosLibrary*) OpenLibrary("dos.library",
                                                37)))
  {
	if ((UtilityBase=OpenLibrary("utility.library",
	                             37)))
	{
	  memset(System,0,sizeof(System));
	  memset(Vendor,0,sizeof(Vendor));
	  memset(Revision,0,sizeof(Revision));
	  NewGetSystemAttrs(&System,sizeof(System),SYSTEMINFOTYPE_SYSTEM,TAG_DONE);
	  NewGetSystemAttrs(&Vendor,sizeof(Vendor),SYSTEMINFOTYPE_VENDOR,TAG_DONE);
	  NewGetSystemAttrs(&Revision,sizeof(Revision),SYSTEMINFOTYPE_REVISION,TAG_DONE);
	  NewGetSystemAttrs(&Machine,sizeof(Machine),SYSTEMINFOTYPE_MACHINE,TAG_DONE);
	  NewGetSystemAttrs(&CPUVersion,sizeof(CPUVersion),SYSTEMINFOTYPE_PPC_CPUVERSION,TAG_DONE);
	  NewGetSystemAttrs(&CPURevision,sizeof(CPURevision),SYSTEMINFOTYPE_PPC_CPUREVISION,TAG_DONE);

	  if (Machine==MACHINE_M68k)
	  {
		MachineStr	=	"68k";
	  }
	  else
	  if (Machine==MACHINE_PPC)
	  {
		MachineStr	=	"PowerPC";
	  }
	  else
	  {
		MachineStr	=	"Unknown";
	  }

	  switch (CPUVersion)
	  {
		case  CPU_970MP:
			  CPUType = "970MP";
			  break;
		case  CPU_970FX:
			  CPUType = "970FX";
			  break;
		case  CPU_970:
			  CPUType = "970";
			  break;
		case  CPU_750FX:
			  CPUType = "750FX";
			  break;
		case  CPU_7447A:
			  CPUType = "7447A";
			  break;
		case  CPU_7448:
			  CPUType = "7448";
			  break;
		case  CPU_5200:
			  CPUType = "5200";
			  break;
		case  CPU_7457:
			  CPUType = "7457";
			  break;
		case  CPU_7455:
			  CPUType = "7455";
			  break;
		case  CPU_7450:
			  if (CPURevision > 0x0200)
			  {
				CPUType = "7451";
			  }
			  else
			  {
			  	CPUType = "7450";
			  }
			  break;
		case  CPU_7400:
			  if ((CPURevision & 0x1000)==0x1000)
			  {
				CPUType = "7410";
			  }
			  else
			  {
			  	CPUType = "7400";
			  }
			  break;
		case  CPU_750:
			  if ((CPURevision & 0xf000)==0x2000)
			  {
				if (CPURevision >= 0x2214)
				{
				  CPUType = "750CXE";
				}
				else
				{
				  CPUType = "750CX";
				}
			  }
			  else
			  {
				CPUType = "750";
			  }
			  break;
		case  CPU_604ev:
			  CPUType = "604EV";
			  break;
		case  CPU_604e:
			  CPUType = "604E";
			  break;
		case  CPU_604:
			  CPUType = "604";
			  break;
		case  CPU_603:
			  CPUType = "603";
			  break;
		case  CPU_603e:
			  CPUType = "603E";
			  break;
		case  CPU_603p:
			  CPUType = "603P";
			  break;
		case  CPU_602:
			  CPUType = "602";
			  break;
		case  CPU_601:
			  CPUType = "601";
			  break;
		default:
			  CPUType = "Unknown";
			  break;
	  }

	  Printf("System <%s>\nMachine %ld <%s>\nCPU Version %ld <%s> Revision %ld\n",
	         System,
	         Machine, MachineStr,
	         CPUVersion, CPUType,
	         CPURevision);

	  Printf("Vendor <%s>\nRevision <%s>\n",
	         Vendor,
	         Revision);

	  NewGetSystemAttrs(&CPUClock,sizeof(CPUClock),SYSTEMINFOTYPE_PPC_CPUCLOCK,TAG_DONE);
	  NewGetSystemAttrs(&BUSClock,sizeof(BUSClock),SYSTEMINFOTYPE_PPC_BUSCLOCK,TAG_DONE);
	  /* As the results are 64bit we can't use Printf
	   */
	  sprintf(Buffer,"CPUClock %Ld BUSClock %Ld\n",
	          CPUClock,
	          BUSClock);

	  PutStr(Buffer);

	  if (NewGetSystemAttrs(&TLBEntries,sizeof(TLBEntries),SYSTEMINFOTYPE_PPC_TLBENTRIES,TAG_DONE))
	  {
		if (NewGetSystemAttrs(&TLBSets,sizeof(TLBSets),SYSTEMINFOTYPE_PPC_TLBSETS,TAG_DONE))
		{
		  Printf("TLBEntries %ld TLBSets %ld\n",
		         TLBEntries,
		         TLBSets);
		}
	  }

	  if (NewGetSystemAttrs(&CacheL1Type,sizeof(CacheL1Type),SYSTEMINFOTYPE_PPC_CACHEL1TYPE,TAG_DONE))
	  {
		NewGetSystemAttrs(&CacheL1Flags,sizeof(CacheL1Flags),SYSTEMINFOTYPE_PPC_CACHEL1FLAGS,TAG_DONE);

		Printf("L1Cache: Type 0x%lx Flags 0x%lx\n",
		       CacheL1Type,
		       CacheL1Flags);

		NewGetSystemAttrs(&ICacheL1Size,sizeof(ICacheL1Size),SYSTEMINFOTYPE_PPC_ICACHEL1SIZE,TAG_DONE);
		NewGetSystemAttrs(&ICacheL1Lines,sizeof(ICacheL1Lines),SYSTEMINFOTYPE_PPC_ICACHEL1LINES,TAG_DONE);
		NewGetSystemAttrs(&ICacheL1LineSize,sizeof(ICacheL2LineSize),SYSTEMINFOTYPE_PPC_ICACHEL1LINESIZE,TAG_DONE);
		Printf("IL1Cache: Size %ld Lines %ld LineSize %ld\n",
		       ICacheL1Size,
		       ICacheL1Lines,
		       ICacheL2LineSize);

		NewGetSystemAttrs(&DCacheL1Size,sizeof(DCacheL1Size),SYSTEMINFOTYPE_PPC_DCACHEL1SIZE,TAG_DONE);
		NewGetSystemAttrs(&DCacheL1Lines,sizeof(DCacheL1Lines),SYSTEMINFOTYPE_PPC_DCACHEL1LINES,TAG_DONE);
		NewGetSystemAttrs(&DCacheL1LineSize,sizeof(DCacheL1LineSize),SYSTEMINFOTYPE_PPC_DCACHEL1LINESIZE,TAG_DONE);
		Printf("DL1Cache: Size %ld Lines %ld LineSize %ld\n",
		        DCacheL1Size,
		        DCacheL1Lines,
		        DCacheL1LineSize);
	  }
	  else
	  {
		Printf("L1Cache: <none>\n");
	  }

	  if (NewGetSystemAttrs(&CacheL2Type,sizeof(CacheL2Type),SYSTEMINFOTYPE_PPC_CACHEL2TYPE,TAG_DONE))
	  {
		NewGetSystemAttrs(&CacheL2Flags,sizeof(CacheL2Flags),SYSTEMINFOTYPE_PPC_CACHEL2FLAGS,TAG_DONE);

		Printf("L2Cache: Type 0x%lx Flags 0x%lx\n",
		       CacheL2Type,
		       CacheL2Flags);

		NewGetSystemAttrs(&ICacheL2Size,sizeof(ICacheL2Size),SYSTEMINFOTYPE_PPC_ICACHEL2SIZE,TAG_DONE);
		NewGetSystemAttrs(&ICacheL2Lines,sizeof(ICacheL2Lines),SYSTEMINFOTYPE_PPC_ICACHEL2LINES,TAG_DONE);
		NewGetSystemAttrs(&ICacheL2LineSize,sizeof(ICacheL2LineSize),SYSTEMINFOTYPE_PPC_ICACHEL2LINESIZE,TAG_DONE);
		Printf("IL2Cache: Size %ld Lines %ld LineSize %ld\n",
		       ICacheL2Size,
		       ICacheL2Lines,
		       ICacheL2LineSize);

		NewGetSystemAttrs(&DCacheL2Size,sizeof(DCacheL2Size),SYSTEMINFOTYPE_PPC_DCACHEL2SIZE,TAG_DONE);
		NewGetSystemAttrs(&DCacheL2Lines,sizeof(DCacheL2Lines),SYSTEMINFOTYPE_PPC_DCACHEL2LINES,TAG_DONE);
		NewGetSystemAttrs(&DCacheL2LineSize,sizeof(DCacheL2LineSize),SYSTEMINFOTYPE_PPC_DCACHEL2LINESIZE,TAG_DONE);
		Printf("DL2Cache: Size %ld Lines %ld LineSize %ld\n",
		       DCacheL2Size,
		       DCacheL2Lines,
		       DCacheL2LineSize);
	  }
	  else
	  {
		Printf("L2Cache: <none>\n");
	  }

	  if (NewGetSystemAttrs(&CacheL3Type,sizeof(CacheL3Type),SYSTEMINFOTYPE_PPC_CACHEL3TYPE,TAG_DONE))
	  {
		NewGetSystemAttrs(&CacheL3Flags,sizeof(CacheL3Flags),SYSTEMINFOTYPE_PPC_CACHEL3FLAGS,TAG_DONE);

		Printf("L3Cache: Type 0x%lx Flags 0x%lx\n",
		       CacheL3Type,
		       CacheL3Flags);

		NewGetSystemAttrs(&ICacheL3Size,sizeof(ICacheL3Size),SYSTEMINFOTYPE_PPC_ICACHEL3SIZE,TAG_DONE);
		NewGetSystemAttrs(&ICacheL3Lines,sizeof(ICacheL3Lines),SYSTEMINFOTYPE_PPC_ICACHEL3LINES,TAG_DONE);
		NewGetSystemAttrs(&ICacheL3LineSize,sizeof(ICacheL3LineSize),SYSTEMINFOTYPE_PPC_ICACHEL3LINESIZE,TAG_DONE);
		Printf("IL3Cache: Size %ld Lines %ld LineSize %ld\n",
		       ICacheL3Size,
		       ICacheL3Lines,
		       ICacheL3LineSize);

		NewGetSystemAttrs(&DCacheL3Size,sizeof(DCacheL3Size),SYSTEMINFOTYPE_PPC_DCACHEL3SIZE,TAG_DONE);
		NewGetSystemAttrs(&DCacheL3Lines,sizeof(DCacheL3Lines),SYSTEMINFOTYPE_PPC_DCACHEL3LINES,TAG_DONE);
		NewGetSystemAttrs(&DCacheL3LineSize,sizeof(DCacheL3LineSize),SYSTEMINFOTYPE_PPC_DCACHEL3LINESIZE,TAG_DONE);
		Printf("DL3Cache: Size %ld Lines %ld LineSize %ld\n",
		       DCacheL3Size,
		       DCacheL3Lines,
		       DCacheL3LineSize);
	  }
	  else
	  {
		Printf("L3Cache: <none>\n");
	  }

	  if (NewGetSystemAttrs(&ReservationSize,sizeof(ReservationSize),SYSTEMINFOTYPE_PPC_RESERVATIONSIZE,TAG_DONE))
	  {
		Printf("Reservation Size %ld\n",
		       ReservationSize);
	  }

	  if (NewGetSystemAttrs(&BusTicks,sizeof(BusTicks),SYSTEMINFOTYPE_PPC_BUSTICKS,TAG_DONE))
	  {
		Printf("Timer BusTicks %ld\n",
		       BusTicks);
	  }

	  if (NewGetSystemAttrs(&FPU,sizeof(FPU),SYSTEMINFOTYPE_PPC_FPU,TAG_DONE))
	  {
		if (FPU)
		{
		  Printf(" o FPU Instruction support\n");
		}
	  }

	  if (NewGetSystemAttrs(&Altivec,sizeof(Altivec),SYSTEMINFOTYPE_PPC_ALTIVEC,TAG_DONE))
	  {
		if (Altivec)
		{
		  Printf(" o Altivec Instruction support\n");
		}
	  }

	  if (NewGetSystemAttrs(&PerfMonitor,sizeof(PerfMonitor),SYSTEMINFOTYPE_PPC_PERFMONITOR,TAG_DONE))
	  {
		if (PerfMonitor)
		{
		  Printf(" o Performance Monitor supported\n");
		}
	  }

	  if (NewGetSystemAttrs(&DataStream,sizeof(DataStream),SYSTEMINFOTYPE_PPC_DATASTREAM,TAG_DONE))
	  {
		if (DataStream)
		{
		  Printf(" o DataStream Instruction support\n");
		}
	  }


	  CloseLibrary(UtilityBase);
	}
	CloseLibrary((struct Library *)DOSBase);
  }
  return 0;
}
