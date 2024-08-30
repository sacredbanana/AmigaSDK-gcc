/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SENSORS_H
#define _PPCINLINE_SENSORS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SENSORS_BASE_NAME
#define SENSORS_BASE_NAME SensorsBase
#endif /* !SENSORS_BASE_NAME */

#define StartSensorNotify(__p0, __p1) \
	(((APTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 70))((void*)(SENSORS_BASE_NAME), __p0, __p1))

#define SetSensorAttr(__p0, __p1) \
	(((ULONG (*)(void *, APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 64))((void*)(SENSORS_BASE_NAME), __p0, __p1))

#define GetSensorAttr(__p0, __p1) \
	(((ULONG (*)(void *, APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 58))((void*)(SENSORS_BASE_NAME), __p0, __p1))

#define EndSensorNotify(__p0, __p1) \
	(((void (*)(void *, APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 76))((void*)(SENSORS_BASE_NAME), __p0, __p1))

#define AddSensor(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 28))((void*)(SENSORS_BASE_NAME), __p0))

#define NextSensor(__p0, __p1, __p2) \
	(((APTR (*)(void *, APTR , APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 46))((void*)(SENSORS_BASE_NAME), __p0, __p1, __p2))

#define ReleaseSensorsList(__p0, __p1) \
	(((void (*)(void *, APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 52))((void*)(SENSORS_BASE_NAME), __p0, __p1))

#define GetSensorsCount(__p0) \
	(((ULONG (*)(void *, struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 82))((void*)(SENSORS_BASE_NAME), __p0))

#define RemoveSensor(__p0, __p1) \
	(((void (*)(void *, APTR , struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 34))((void*)(SENSORS_BASE_NAME), __p0, __p1))

#define ObtainSensorsList(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(SENSORS_BASE_NAME) - 40))((void*)(SENSORS_BASE_NAME), __p0))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define StartSensorNotifyTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	StartSensorNotify(__p0, (struct TagItem *)_tags);})

#define SetSensorAttrTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetSensorAttr(__p0, (struct TagItem *)_tags);})

#define GetSensorsCountTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetSensorsCount((struct TagItem *)_tags);})

#define EndSensorNotifyTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	EndSensorNotify(__p0, (struct TagItem *)_tags);})

#define NextSensorTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NextSensor(__p0, __p1, (struct TagItem *)_tags);})

#define ObtainSensorsListTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ObtainSensorsList((struct TagItem *)_tags);})

#define ReleaseSensorsListTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ReleaseSensorsList(__p0, (struct TagItem *)_tags);})

#define AddSensorTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddSensor((struct TagItem *)_tags);})

#define RemoveSensorTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RemoveSensor(__p0, (struct TagItem *)_tags);})

#define GetSensorAttrTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetSensorAttr(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_SENSORS_H */
