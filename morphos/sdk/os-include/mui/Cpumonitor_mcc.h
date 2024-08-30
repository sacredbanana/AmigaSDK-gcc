#ifndef CPUMONITOR_PRIVATE_H
#define CPUMONITOR_PRIVATE_H

#ifndef GRAPH_MCC_H
#include <mui/Graph_mcc.h>
#endif

#define MUIC_Cpumonitor "Cpumonitor.mcc"
#define CpumonitorObject MUI_NewObject(MUIC_Cpumonitor

#define MUIA_Cpumonitor_FilterTask    (0xfed10000 + 12) /* ISG STRPTR Defaults to NULL (no filtering) */
#define MUIA_Cpumonitor_LastValue     (0xfed10000 + 13) /* ..G FLOAT                   */
#define MUIA_Cpumonitor_TaskEncounter (0xfed10000 + 14) /* ..G BOOL                    */
#define MUIA_Cpumonitor_DnetcMode     (0xfed10000 + 15) /* ISG BOOL   (not supported)  */
#define MUIA_Cpumonitor_QuickMode     (0xfed10000 + 17) /* ISG BOOL   Defaults to TRUE */

#define MUIV_Cpumonitor_FilterTask_Dnetc 1

#define MUIM_Cpumonitor_Reset          MUIM_Graph_Reset
#define MUIM_Cpumonitor_Clone          MUIM_Graph_Clone

struct MUIP_Cpumonitor_Clone
{
	IPTR methodid;
	APTR target;
};

#endif
