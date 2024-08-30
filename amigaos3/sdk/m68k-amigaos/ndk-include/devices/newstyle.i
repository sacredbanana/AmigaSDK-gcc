	IFND	DEVICES_NEWSTYLE_I
DEVICES_NEWSTYLE_I	SET	1

**	$VER: newstyle.i 47.2 (28.9.2021)
**
**	Declarations for the NSD command interface.
**	For 64 bit extensions, see <devices/trackdisk.h>
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.

        IFND    NSCMD_DEVICEQUERY
        ; Define general new style handling

;------------------------------------------------------------------------
; Simple additions that are missing from the global V40 exec include io.i
; for support of the NewStyleDevice standard.
; Both were introduced for V43

NSCMD_DEVICEQUERY   EQU $4000

; The result
    STRUCTURE NSDeviceQueryResult,0
        ;
        ; Standard information
        ;
        ULONG   nsdqr_DevQueryFormat        ; this is type 0
        ULONG   nsdqr_SizeAvailable         ; bytes available

        ;
        ; Common information (READ ONLY!)
        ;
        UWORD   nsdqr_DeviceType            ; what the device does
        UWORD   nsdqr_DeviceSubType         ; depends on the main type
        APTR    nsdqr_SupportedCommands     ; 0 terminated list of cmd's

        ; May be extended in the future! Check SizeAvailable!
    LABEL nsdqr_SIZEOF

; For nsdqr_DeviceType
NSDEVTYPE_UNKNOWN       EQU 0   ; No suitable category, anything
NSDEVTYPE_GAMEPORT      EQU 1   ; like gameport.device
NSDEVTYPE_TIMER         EQU 2   ; like timer.device
NSDEVTYPE_KEYBOARD      EQU 3   ; like keyboard.device
NSDEVTYPE_INPUT         EQU 4   ; like input.device
NSDEVTYPE_TRACKDISK     EQU 5   ; like trackdisk.device
NSDEVTYPE_CONSOLE       EQU 6   ; like console.device
NSDEVTYPE_SANA2         EQU 7   ; A >=SANA2R2 networking device
NSDEVTYPE_AUDIOARD      EQU 8   ; like audio.device
NSDEVTYPE_CLIPBOARD     EQU 9   ; like clipboard.device
NSDEVTYPE_PRINTER       EQU 10  ; like printer.device
NSDEVTYPE_SERIAL        EQU 11  ; like serial.device
NSDEVTYPE_PARALLEL      EQU 12  ; like parallel.device

;------------------------------------------------------------------------

        IFND    NSCMD_TD_READ64

; Trackdisk specific new style device commands
NSCMD_TD_READ64     EQU $c000
NSCMD_TD_WRITE64    EQU $c001
NSCMD_TD_SEEK64     EQU $c002
NSCMD_TD_FORMAT64   EQU $c003

; Alias to set the upper 32 bits for a 64 bit request
IO_HIGHOFFSET       EQU IO_ACTUAL

        ENDC    ; NSCMD_TD_READ64


        ENDC    ; NSCMD_DEVICEQUERY

	ENDC    ; DEVICES_NEWSTYLE_I
