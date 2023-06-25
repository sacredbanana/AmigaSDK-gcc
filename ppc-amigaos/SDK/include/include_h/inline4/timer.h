#ifndef INLINE4_TIMER_H
#define INLINE4_TIMER_H

/*
** This file was auto generated by idltool 51.8.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif

/* Inline macros for Interface "main" */
#define AddTime(dest, src) ITimer->AddTime(dest, src) 
#define SubTime(dest, src) ITimer->SubTime(dest, src) 
#define CmpTime(dest, src) ITimer->CmpTime(dest, src) 
#define ReadEClock(dest) ITimer->ReadEClock(dest) 
#define GetSysTime(dest) ITimer->GetSysTime(dest) 
#define GetUpTime(dest) ITimer->GetUpTime(dest) 
#define MicroDelay(microseconds) ITimer->MicroDelay(microseconds) 

#endif /* INLINE4_TIMER_H */