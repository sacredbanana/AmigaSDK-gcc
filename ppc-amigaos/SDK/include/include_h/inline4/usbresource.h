#ifndef INLINE4_USBRESOURCE_H
#define INLINE4_USBRESOURCE_H

/*
** This file was auto generated by idltool 51.3.
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

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* Inline macros for Interface "main" */
#define USBResRegisterFDA(taglist) IUSBResource->USBResRegisterFDA(taglist) 
#if !defined(__cplusplus) && (__GNUC__ >= 3    \
    || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95) \
    || (__STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#define USBResRegisterFD(...) IUSBResource->USBResRegisterFD(__VA_ARGS__) 
#endif
#define USBResUnregisterFD(fdkey) IUSBResource->USBResUnregisterFD(fdkey) 
#define USBResRegisterHCDA(taglist) IUSBResource->USBResRegisterHCDA(taglist) 
#if !defined(__cplusplus) && (__GNUC__ >= 3    \
    || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95) \
    || (__STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#define USBResRegisterHCD(...) IUSBResource->USBResRegisterHCD(__VA_ARGS__) 
#endif
#define USBResUnregisterHCD(hcdkey) IUSBResource->USBResUnregisterHCD(hcdkey) 
#define USBResAddNotify(type, port) IUSBResource->USBResAddNotify(type, port) 
#define USBResRemNotify(subs) IUSBResource->USBResRemNotify(subs) 

#endif /* INLINE4_USBRESOURCE_H */
