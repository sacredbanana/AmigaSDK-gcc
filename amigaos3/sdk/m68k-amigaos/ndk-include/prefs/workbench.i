	IFND	PREFS_WORKBENCH_I
PREFS_WORKBENCH_I	SET	1
**
**	$VER: workbench.i 47.1 (2.8.2019)
**
**	File format for workbench control preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

;---------------------------------------------------------------------------

	IFND EXEC_TYPES_I
	INCLUDE "exec/types.i"
	ENDC

	IFND LIBRARIES_IFFPARSE_I
	INCLUDE "libraries/iffparse.i"
	ENDC

;---------------------------------------------------------------------------

ID_WBNC		equ	'WBNC'

;---------------------------------------------------------------------------

    STRUCTURE WorkbenchPrefs,0
	ULONG	wbp_DefaultStackSize		; in bytes
	ULONG	wbp_TypeRestartTime		; in seconds
	ULONG	wbp_IconPrecision		; PRECISION_#? values
	STRUCT	wbp_EmbossRect,ra_SIZEOF
	BOOL	wbp_Borderless
	LONG	wbp_MaxNameLength
	BOOL	wbp_NewIconsSupport
	BOOL	wbp_ColorIconSupport
    LABEL WorkbenchPrefs_SIZEOF

* The following includes extensions from V45/Os 3.9 *
						    
    STRUCTURE WorkbenchExtendedPrefs,WorkbenchPrefs_SIZEOF
	ULONG	wbe_IconMemoryType		; exec MEMF_xxxx, obsolete
	BOOL	wbe_LockPens			; if TRUE, locks pens 4..7 with predefined colors
	BOOL	wbe_DisableTitleBar
	BOOL	wbe_DisableVolumeGauge
	/* new for V47 */
	UWORD   wbe_TitleUpdateDelay    ; in milliseconds
	ULONG   wbe_CopyBufferSize      ; in bytes
	ULONG   wbe_Flags               ; assorted options
	LABEL WorkbenchExtendedPrefs_SIZEOF
    
;---------------------------------------------------------------------------

ID_WBHD		equ	'WBHD'

;---------------------------------------------------------------------------

    STRUCTURE WorkbenchHiddenDevicePrefs,0
	UBYTE	whdp_Name			; first char of C String including NULL char
    LABEL WorkbenchHiddenDevicePrefs_SIZEOF

;---------------------------------------------------------------------------

/* New for V47 */
ID_WBTF		equ	'WBTF'

;---------------------------------------------------------------------------

    STRUCTURE WorkbenchTitleFormatPrefs,0
    UBYTE	wtfp_Format
    LABEL WorkbenchTitleFormatPrefs_SIZEOF

;---------------------------------------------------------------------------


	ENDC	; PREFS_WORKBENCH_I
