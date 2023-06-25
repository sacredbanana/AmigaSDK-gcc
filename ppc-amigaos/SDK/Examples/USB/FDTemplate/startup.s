
        ;   TAG.ASM
        ;
        ;   Library tag.  This replaces the normal startup code, c.o,
        ;   but still must perform certain startup functions such as
        ;   the clearing of BSS and small-data model setup & auto
        ;   calls.  HOWEVER, we do not include any resident startup
        ;   code meaning you CANNOT compile the shared library -r
        ;   (which doesn't make sense to do anyway).
        ;
        ;   Further, no C startup or exit functions are included
        ;   since this is a library, not a normal program.  Refer
        ;   to the source code LIB/AMIGA/C.A for a fully operational
        ;   startup module.

;Prototype ALibReserved();

        section text,code

        xref    __LibAutoInit      ; Library AutoInit structure
        xref    __LibNameString    ; Library name
        xref    __LibVersionString ; Library description string

        xref    @LibInit          ; System general library functions
        xref    @LibOpen
        xref    @LibClose
        xref    @LibExpunge


        xdef    _ALibReserved   ; An unused  system-reserved function entry.

;-----------------------------------------------------------
;| Return an error if someone tried to run us as a program |
;-----------------------------------------------------------

        moveq   #-1,d0
        rts

;--------------------------------------------
;| RomTag structure for "exec" and "ramlib" |
;--------------------------------------------

RomTag: dc.w    $4AFC   ;RTC_MATCHWORD
        dc.l    RomTag  ;Pointer to beginning
        dc.l    EndCode ;Not sure it matters
        dc.b    128     ;flags (RTF_AUTOINIT)
        dc.b    1       ;version
        dc.b    9       ;NT_LIBRARY
        dc.b    0       ;priority (doesn't matter)
        dc.l    __LibNameString     ;Name of library
        dc.l    __LibVersionString  ;ID string
        dc.l    __LibAutoInit       ;Pointer to AutoInit description

        ds.w    0
EndCode:

        END

