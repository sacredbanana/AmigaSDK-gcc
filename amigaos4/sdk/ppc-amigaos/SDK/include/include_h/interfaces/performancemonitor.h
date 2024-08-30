#ifndef PERFORMANCEMONITOR_INTERFACE_DEF_H
#define PERFORMANCEMONITOR_INTERFACE_DEF_H
 
 
#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif
 
#ifndef UTILITY_UTILITY_H
#include <utility/utility.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct PerformanceMonitorIFace
{
	struct InterfaceData Data;
 
	ULONG APICALL (*Obtain)(struct PerformanceMonitorIFace *Self);
	ULONG APICALL (*Release)(struct PerformanceMonitorIFace *Self);
	void APICALL (*Expunge)(struct PerformanceMonitorIFace *Self);
	struct Interface * APICALL (*Clone)(struct PerformanceMonitorIFace *Self);
        
	uint32 APICALL (*CounterGet)(struct PerformanceMonitorIFace *Self, uint32 whatCount);
	uint32 APICALL (*CounterMatch)(struct PerformanceMonitorIFace *Self, uint32 itemNum);
	BOOL APICALL (*CounterControl)(struct PerformanceMonitorIFace *Self, uint32 whichCount, int32 value, uint32 what);
	
	uint32 APICALL (*EventControl)(struct PerformanceMonitorIFace *Self, struct TagItem *tagList);
	uint32 APICALL (*EventControlTags)(struct PerformanceMonitorIFace *Self,  ...);
	struct Interrupt * APICALL (*SetInterruptVector)(struct PerformanceMonitorIFace *Self, uint32 event, struct Interrupt *handler);

	void APICALL (*Mark)(struct PerformanceMonitorIFace *Self, struct Task *task);
	void APICALL (*Unmark)(struct PerformanceMonitorIFace *Self, struct Task *task);

	uint32 APICALL (*MonitorControl)(struct PerformanceMonitorIFace *Self, struct TagItem *tagList);
	uint32 APICALL (*MonitorControlTags)(struct PerformanceMonitorIFace *Self, ...);
	uint32 APICALL (*Query)(struct PerformanceMonitorIFace *Self, uint32 item);

	void APICALL (*SetSampledAddress)(struct PerformanceMonitorIFace *Self, APTR addr);
	APTR APICALL (*GetSampledAddress)(struct PerformanceMonitorIFace *Self);
	void APICALL (*SetBreakpoint)(struct PerformanceMonitorIFace *Self, uint32 type, APTR instAddr, uint32 instMask, BOOL except);
};


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif
