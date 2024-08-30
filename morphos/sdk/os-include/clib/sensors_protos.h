#ifndef CLIB_SENSORS_PROTOS_H
#define CLIB_SENSORS_PROTOS_H

/*
	sensors.library C prototypes

	Copyright (c) 2010 The MorphOS Development Team / Jacek Piszczek,  All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR AddSensor(struct TagItem *taglist);
void RemoveSensor(APTR sensor, struct TagItem *taglist);
APTR ObtainSensorsList(struct TagItem *taglist);
APTR NextSensor(APTR lastsensor, APTR sensorslist, struct TagItem *taglist);
void ReleaseSensorsList(APTR sensorslist, struct TagItem *taglist);
ULONG GetSensorAttr(APTR sensor, struct TagItem *taglist);
ULONG SetSensorAttr(APTR sensor, struct TagItem *taglist);
APTR StartSensorNotify(APTR sensor, struct TagItem *taglist);
void EndSensorNotify(APTR notify, struct TagItem *taglist);
ULONG GetSensorsCount(struct TagItem *taglist);

#if !defined(USE_INLINE_STDARG)
APTR AddSensorTags(ULONG tag1, ...);
void RemoveSensorTags(APTR sensor, ULONG tag1, ...);
APTR ObtainSensorsListTags(ULONG tag1, ...);
APTR NextSensorTags(APTR lastsensor, APTR sensorslist, ULONG tag1, ...);
void ReleaseSensorsListTags(APTR sensorslist, ULONG tag1, ...);
ULONG GetSensorAttrTags(APTR sensor, ULONG tag1, ...);
ULONG SetSensorAttrTags(APTR sensor, ULONG tag1, ...);
APTR StartSensorNotifyTags(APTR sensor, ULONG tag1, ...);
void EndSensorNotifyTags(APTR notify, ULONG tag1, ...);
ULONG GetSensorsCountTags(ULONG tag1, ...);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_SENSORS_PROTOS_H */
