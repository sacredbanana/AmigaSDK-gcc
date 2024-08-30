#ifndef GRAPH_MCC_H
#define GRAPH_MCC_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define MUIC_Graph	"Graph.mcc"
#define GraphObject	MUI_NewObject(MUIC_Graph

#define MUIA_Graph_MaxEntries      0xfed10005 // ULONG, I*G
#define MUIA_Graph_Max             0xfed10006 // ULONG, ISG
#define MUIA_Graph_DrawBackCurve   0xfed10007 // BOOL, ISG
#define MUIA_Graph_SetMax          0xfed10008 // BOOL, I

#define MUIM_Graph_AddEntry        0xfed10009
struct MUIP_Graph_AddEntry { ULONG methodid; ULONG value; ULONG value_back; };
#define MUIM_Graph_Reset           0xfed1000A
struct MUIP_Graph_Reset { ULONG methodid; };
#define MUIM_Graph_Clone           0xfed10012
struct MUIP_Graph_Clone { ULONG methodid; APTR  target; };


#endif /* GRAPH_MCC_H */
