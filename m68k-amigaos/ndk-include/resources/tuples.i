	IFND	RESOURCES_TUPLES_I
RESOURCES_TUPLES_I	SET	1
**
**	$VER: tuples.i 47.1 (3.8.2019)
**
**	Tuple defines
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND	EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC

* ======================================================================
* ======================================================================
* ======================================================================
* Tuple TPL_CODEs
* ======================================================================
* ======================================================================
* ======================================================================

CISTPL_NULL	EQU	$00
CISTPL_DEVICE	EQU	$01

** 2-7 reserved for future, upwards compatable device information tuples

** 8-F reserved for future, incompatable device information tuples

CISTPL_CHECKSUM		EQU	$10
CISTPL_LONGLINK_A	EQU	$11
CISTPL_LONGLINK_C	EQU	$12
CISTPL_LINKTARGET	EQU	$13
CISTPL_NO_LINK		EQU	$14
CISTPL_VERS_1		EQU	$15
CISTPL_ALTSTR		EQU	$16
CISTPL_DEVICE_A		EQU	$17
CISTPL_JEDEC_C		EQU	$18
CISTPL_JEDEC_A		EQU	$19

* 1A-3F reserved for future standardization

CISTPL_VERS_2		EQU	$40
CISTPL_FORMAT		EQU	$41
CISTPL_GEOMETRY		EQU	$42
CISTPL_BYTEORDER	EQU	$43
CISTPL_DATE		EQU	$44
CISTPL_BATTERY		EQU	$45
CISTPL_ORG		EQU	$46

* 47-7F reserved for future standardization

* 80-FE Vendor specific

CISTPL_END		EQU	$FF

* ======================================================================
* ======================================================================
* Tuple structure definitions (Level 1)
* ======================================================================
* ======================================================================

* Tuples in attribute memory at EVEN addresses ONLY (offset * 2)
* Use byte size access for tuple data

 STRUCTURE	TUPLE,0
	STRUCT	TPL_CODE,1
	STRUCT	TPL_LINK,1
	LABEL	TUPLE_SIZEOF

 STRUCTURE	TUPLE_NOLINK,0
	STRUCT	TPL_SINGLE,1
	LABEL	TUPLE_NOLINK_SIZEOF


* Control Tuples


* CISTPL_NULL tuple (ignore)

 STRUCTURE	TP_Null,0
	STRUCT	tp_null,TUPLE_NOLINK_SIZEOF
	LABEL	TP_NULL_SIZEOF

* CISTPL_LONGLINK_A or CISTPL_LONGLINK_C (link to next tuple chain)

 STRUCTURE 	TP_LongLink,0
	STRUCT	tp_LongLink,TUPLE_SIZEOF
	STRUCT	TPLL_ADDR,4			;address of list
	LABEL	TP_LongLink_SIZEOF

* CISTPL_LINKTARGET (validate link)

 STRUCTURE	TP_LinkTarget,0
	STRUCT	tp_LinkTarget,TUPLE_SIZEOF
	STRUCT	TPLTG_TAG,3			;'C','I','S'	
	LABEL	TP_LinkTarget_SIZEOF

* CISTPL_NOLINK (no implied CISTPL_LONGLINK_C tuple)

 STRUCTURE	TP_NoLink,0
	STRUCT	tp_NoLink,TUPLE_SIZEOF
	LABEL	TP_NoLink_SIZEOF

* CISTPL_END (end of list tuple)

 STRUCTURE	TP_EndOfList,0
	STRUCT	tp_EndOfList,TUPLE_NOLINK_SIZEOF
	LABEL	TP_EndOfList_SIZEOF

* CISTPL_CHECKSUM

 STRUCTURE	TP_CheckSum,0
	STRUCT	tp_CheckSum,TUPLE_SIZEOF
	STRUCT	TPLCKS_ADDR,2			;(LSB first)
	STRUCT	TPLCKS_LEN,2			;(LSB first
	STRUCT	TPLCKS_CS,1			;byte checksum
	LABEL	TP_CheckSum_SIZEOF

* CISTPL_ALTSTR (variable length tuple)

 STRUCTURE	TP_AltStr,0
	STRUCT	tp_AltStr,TUPLE_SIZEOF
	STRUCT	TPLALTSTR_ESC,0			;variable length

* CISTPL_VERS_1 (card-manufacturer information)

 STRUCTURE	TP_Vers_1,0
	STRUCT	tp_Vers_1,TUPLE_SIZEOF
	STRUCT	TPLLV1_MAJOR,1			;major version number
	STRUCT	TPLLV1_MINOR,1			;minor version number
	STRUCT	TPLLV1_INFO,0			;variable length
						;$FF marks end of list


* ======================================================================
* ======================================================================
* CISTPL_DEVICE, CISTPL_DEVICE_A, CISTPL_JEDEC, CISTPL_JEDEC_A
* ======================================================================
* ======================================================================
*
* CISTPL_DEVICE or CISTPL_DEVICE_A (variable length tuple)

 STRUCTURE	TP_Device,0
	STRUCT	tp_Device,TUPLE_SIZEOF
	STRUCT	TP_DEVICE_INFO1,1
	STRUCT	TP_DEVICE_INFO2,1
	STRUCT	TP_DEVICE_INFO3,1
	STRUCT	TP_DEVICE_INFO4,1
        STRUCT	TP_Device_MINSIZEOF

* CISTPL_JEDEC_C or CISTPL_JEDEC_A (variable length tuple)

 STRUCTURE	TP_Jedec,0
	STRUCT	tp_Jedec,TUPLE_SIZEOF



*
* Byte	7	6	5	4	3	2	1	0
* ---------------------------------------------------------------------
* 0	Device Type Code		WPS	Device Speed
*
* 1	Extended Device Speed (if Device Speed Code if speed code
*	equals $E, else omitted)
*
* 2	Additional Extended Device Speed (if bit 7 of Extended Device
*	Speed is 1, else omitted)
*
* 3	Extended Device Type (if Device Type Code equal $E, else
*	ommitted)
*

DSPEED_MASK		EQU	%00000111

* $0 (reserved, do not use)

DSPEED_250NS		EQU	1
DSPEED_200NS		EQU	2
DSPEED_150NS		EQU	3
DSPEED_100NS		EQU	4

* $5-$6 (reserved)

DSPEED_EXT		EQU	7

*
* Extended speed byte layout
*
*
* Byte	7	6	5	4	3	2	1	0
* ---------------------------------------------------------------------
* 	EXT	Speed Mantissa			Speed Exponent
*

DSPEED_UNSPECIFIED	EQU	$00		;1 nsec?

DSPEED_EXT_MAN_1.0		EQU	1
DSPEED_EXT_MAN_1.2		EQU	2
DSPEED_EXT_MAN_1.3		EQU	3
DSPEED_EXT_MAN_1.5		EQU	4
DSPEED_EXT_MAN_2.0		EQU	5
DSPEED_EXT_MAN_2.5		EQU	6
DSPEED_EXT_MAN_3.0		EQU	7
DSPEED_EXT_MAN_3.5		EQU	8
DSPEED_EXT_MAN_4.0		EQU	9
DSPEED_EXT_MAN_4.5		EQU	$a
DSPEED_EXT_MAN_5.0		EQU	$b
DSPEED_EXT_MAN_5.5		EQU	$c
DSPEED_EXT_MAN_6.0		EQU	$d
DSPEED_EXT_MAN_7.0		EQU	$e
DSPEED_EXT_MAN_8.0		EQU	$f

DSPEED_EXT_EXP_I0NSEC		EQU	1
DSPEED_EXT_EXP_100NSEC		EQU	2
DSPEED_EXT_EXP_1MICROSEC	EQU	3
DSPEED_EXT_EXP_10USEC		EQU	4
DSPEED_EXT_EXP_100USEC		EQU	5
DSPEED_EXT_EXP_1MSEC		EQU	6
DSPEED_EXT_EXP_10MSEC		EQU	7

DSPEED_EXT_MAN_MASK		EQU	%01111000
DSPEED_EXT_MAN_SHIFT		EQU	3

DSPEED_EXT_EXP_MASK		EQU	%00000111

* Device Type field values (value in upper 4 bits of byte)

DTYPE_MASK		EQU	%11110000
DTYPE_SHIFT		EQU	4

DTYPE_NULL		EQU	$0
DTYPE_ROM		EQU	$1
DTYPE_OTPROM		EQU	$2
DTYPE_EPROM		EQU	$3
DTYPE_EEPROM		EQU	$4
DTYPE_FLASH		EQU	$5
DTYPE_SRAM		EQU	$6
DTYPE_DRAM		EQU	$7
DTYPE_IO		EQU	$D
DTYPE_EXTEND		EQU	$E

* Device write-protect

DWPROTECT_B		EQU	3
DWPROTECT_F		EQU	%00001000

* Device Size Byte
*
* Byte	7	6	5	4	3	2	1	0
* ---------------------------------------------------------------------
* 	# of address units -1 			Size code
*
* 	(1-32 units of size X)
*

DSIZE_MASK		EQU	%00000111

DSIZE_IGNORE		EQU	0		;entire ID block is invalid

DSIZE_512		EQU	512
DSIZE_2K		EQU	2*1024
DSIZE_8K		EQU	8*1024
DSIZE_32K		EQU	32*1024
DSIZE_128K		EQU	128*1024
DSIZE_512K		EQU	512*1024
DSIZE_2M		EQU	2*1024*1024
DSIZE_RESERVED		EQU	0

DUNITS_MASK		EQU	%11111000
DUNITS_SHIFT		EQU	3


* End marker for Device ID, and size (if found early, ignore this tuple)

DEND_MARKER		EQU	$FF



* ======================================================================
* ======================================================================
* CISTPL_VERS_2 tuple
* ======================================================================
* ======================================================================

* CISTPL_VERS_2 (introduce information pertaining to the logical
* organization of disk data on the card)

 STRUCTURE	TP_Vers_2,0
	STRUCT	tp_Vers_2,TUPLE_SIZEOF
	STRUCT	TPLLV2_VERS,1			;should be 0
	STRUCT	TPLLV2_COMPLY,1			;should be 0
	STRUCT	TPLLV2_DINDEX,2			;(LSB first)
	STRUCT	TPLLV2_RSV6,1			;reserved (must be 0)
	STRUCT	TPLLV2_RSV7,1			;reserved (must be 0)
	STRUCT	TPLLV2_VSPEC8,1			;vendor specific or 0
	STRUCT	TPLLV2_VSPEC9,1			;vendor specific or 0
	STRUCT	TPLLV2_NHDR,1			;# of copies of CIS on device
						;(should be 1 for now)

	STRUCT	TPLLV2_OEM,0			;vendor name, and info message

***	STRUCT	TPLLV2_INFO,0			;variable length


* ======================================================================
* ======================================================================
* CISTPL_DATE and CISTPL_BATTERY tuple
* ======================================================================
* ======================================================================
*
* CISTPL_DATE (date, and time card was formatted)

 STRUCTURE	TP_Date,0
	STRUCT	tp_Date,TUPLE_SIZEOF
	STRUCT	TPLDATE_TIME,2
	STRUCT	TPLDATE_DAY,2
	LABEL	TP_Date_SIZEOF


* CISTPL_BATTERY (date when battery was replaced, and date which it is
* expected that it will need to be replaced)

 STRUCTURE      TP_Battery,0
        STRUCT  tp_Battery,TUPLE_SIZEOF
        STRUCT  TPLBATT_RDAY,2
        STRUCT  TPLBATT_XDAY,2
        LABEL   TP_Battery_SIZEOF


*
* Byte	7	6	5	4	3	2	1	0
* ---------------------------------------------------------------------
* TIME	MMM (lo)		SSS
* 	HHH					MMM (hi)
*
* DAY	MON (lo)		DAY
*	YYY							MON (hi)
*
*
* if both fields are 0, date, and time were unknown when card was inited
*

DATE_TIME_MMM_LO_MASK		EQU	%11100000
DATE_TIME_MMM_LO_SHIFT		EQU	5

DATE_TIME_SSS_MASK		EQU	%00011111

DATE_TIME_HHH_MASK		EQU	%11111000
DATE_TIME_HHH_SHIFT		EQU	3

DATE_DAY_MON_LO_MASK		EQU	%11100000
DATE_DAY_MON_LO_SHIFT		EQU	5

DATE_DAY_DAY_MASK		EQU	%00011111

DATE_DAY_YYY_MASK		EQU	%11111110
DATE_DAY_YYY_SHIFT		EQU	1

DATE_DAY_MON_HI_MASK		EQU	%00000001


* ======================================================================
* ======================================================================
* CISTPL_FORMAT tuple
* ======================================================================
* ======================================================================
*
* CISTPL_FORMAT (define data recording region - usually all of the card)
*
* Variable length tuple - TUPLE_LINK will normally be 20 ($14), however
* if the format tuple is specifying a memory-like format, the value may
* be as little as 12 ($c) as bytes 13-21 MUST be zero for memory like
* formats.  If error-detecting codes are not used, then the TPLFMT_EDCLOC
* field may be omitted.

 STRUCTURE      TP_Format,0
        STRUCT  tp_Format,TUPLE_SIZEOF
        STRUCT  TPLFMT_TYPE,1
        STRUCT  TPLFMT_EDC,1
        STRUCT  TPLFMT_OFFSET,4			;(32 bit, LSB first)
        STRUCT  TPLFMT_NBYTES,4			;(32 bit, LSB first)

* variable length tuple based on TPLFMT_TYPE

* ---------------------------------------------------------------------
* For TPLFMT_DISK:
* ---------------------------------------------------------------------

* TPLFMT_BKSZ specifies the number of data bytes in each block in the
* partition.  Value does NOT include error check bytes.  Value MUST be
* a power of 2 between 128 and 2048; 512 should be used if possible.
* Value is a 16 bit quantity (LSB first).

	STRUCT	TPLFMT_BKSZ,0			;(power of 2, LSB first)


* ---------------------------------------------------------------------
* For TPLFMT_MEM:
* ---------------------------------------------------------------------

	STRUCT	TPLFMT_FLAGS,1			;control bits
	STRUCT	TPLFMT_RESERVED,1		;reserved


* ---------------------------------------------------------------------
* For TPLFMT_DISK:
* ---------------------------------------------------------------------

* TPLFMT_NBLOCKS * (TPLFMT_BKSZ + TPLFMT_EDCLEN) MUST be <= TPLFMT_NBYTES

	STRUCT	TPLFMT_NBLOCKS,0		;(32 bit, LSB first)

* ---------------------------------------------------------------------
* For TPLFMT_MEM:
* ---------------------------------------------------------------------

* Address at which this memory partition should be mapped if so
* indicated by TPLFMT_FLAGS

	STRUCT 	TPLFMT_ADDRESS,4

* ---------------------------------------------------------------------
* For TPLFMT_MEM and TPLFMT_DISK
* ---------------------------------------------------------------------

* location of error detection code.  If zero, the code is interleaved
* with the data blocks.  If non-zero, the error-detection code is stored
* in a linear table starting at specified address on the card.  If using
* PCC, the first byte of the field contains the check code: bytes 19-21
* must be zero if present.
*
* if a liner table, it shall have TPLFMT_NBLOCKS entries, containing the
* error-detection code for each data block.  Each entry in the table shall
* be TPLFMT_EDCLEN bytes long.  The value stored in TPLFMT_ENDLOC shall
* be at least TPLFMT_OFFSET, and shall be no greater than:
* TPLFMT_OFFSET + TPLFMT_NBYTES - (TPLFMT_EDCLEN * TPLFMT_NBLOCK)
*

	STRUCT	TPLFMT_EDCLOC,4
	LABEL	TP_Format_SIZEOF		;maximum size


TPLFMTTYPE_DISK		EQU	0	;disk like format
TPLFMTTYPE_MEM		EQU	1	;memory like format

* 2-$7f reserved

* $80-$FF vendor specific

TPLFMTTYPE_VS_B		EQU	7
TPLFMTTYPE_VS_F		EQU	(1<<TPLFMTTYPE_VS_B)

* Byte	7	6	5	4	3	2	1	0
* ---------------------------------------------------------------------
* 3	TPLFMT_EDC				EDC Length
* 
* or
* 
* 3	RFU	Error Detection Code type	EDC Length
*


TPLFMT_EDC_MASK		EQU	%01111000
TPLFMT_EDC_SHIFT	EQU	3

* bit 7 is reserved for future use

TPLFMT_EDC_RFU_B	EQU	7
TPLFMT_EDC_RFU_F	EQU	(1<<TPLFMT_EDC_RFU_B)

TPLFMTEDC_NONE		EQU	0
TPLFMTEDC_CHSUM		EQU	1
TPLFMTEDC_CRC		EQU	2
TPLFMTEDC_PCC		EQU	3

* 4-7 reserved

* $8-$F vendor specific

TPLFMTEDC_VS_B		EQU	7
TPLFMTEDC_VS_F		EQU	(1<<TPLFMTEDC_VS_B)

* length field (3 bits)

TPLFMT_LENGTH_MASK	EQU	%00000111

*
* For TPLFMTTYPE_MEM:
*
* Byte	7	6	5	4	3	2	1	0
* ---------------------------------------------------------------------
* 12	Reserved					AUTO	ADDR

TPLFMT_FLAGS_ADDR_B	EQU	0
TPLFMT_FLAGS_ADDR_F	EQU	(1<<TPLFMT_FLAGS_ADDR_B)

TPLFMT_FLAGS_AUTO_B	EQU	1
TPLFMT_FLAGS_AUTO_F	EQU	(1<<TPLFMT_FLAGS_AUTO_B)


* ======================================================================
* ======================================================================
* CISTPL_GEOMETRY tuple
* ======================================================================
* ======================================================================
*
* CISTPL_GEOMETRY (shall appear in partition tuples for disk-like
* partitions).  It provides instructions to OS's that require all
* mass-storage devices be divided into cylinders, tracks, and sectors.
*
* The product:
*
* TPLGEO_NCYL * TPLGEO_TPC * TPLGEO_SPT must be <= TPLFMT_NBLOCKS
*

 STRUCTURE	TP_Geometry,0
	STRUCT	tp_Geometry,TUPLE_SIZEOF
	STRUCT	TPLGEO_SPT,1			;sectors per track
	STRUCT	TPLGEO_TPC,1			;tracks per cylinder
	STRUCT	TPLGEO_NCLI,2			;number of cylinders
						;(LSB first)
	LABEL	TP_Geometry_SIZEOF

* ======================================================================
* ======================================================================
* CISTPL_BYTEORDER tuple
* ======================================================================
* ======================================================================
*
* CISTPL_BYTEORDER shall only appear in a partition tuple set for a
* memory-like partition.  It specifies two parameters: the order for
* multi-byte data, and the order in which bytes map into words (for 16
* bit or wider cards).
*

 STRUCTURE	TP_ByteOrder,0
	STRUCT	tp_ByteOrder,TUPLE_SIZEOF
	STRUCT	TPLBYTE_ORDER,1
	STRUCT	TPLBYTE_MAP,1
	LABEL	TP_ByteOrder_SIZEOF

TPLBYTEORD_LOW		EQU	0		;little-endian
TPLBYTEORD_HIGH		EQU	1		;big-endian

* 2-$7f reserved

* $80-$FF vendor specific

TPLBYTEORD_VS_B		EQU	7
TPLBYTEORD_VS_F		EQU	(1<<TPLBYTEORD_VS_B)


TPLBYTEMAP_LOW		EQU	0		;byte 0 of a word is LSB
TPLBYTEMAP_HIGH		EQU	1		;byte 0 of a word is MSB

* 2-$7f reserved
* $80-$FF vendor specific

TPLBYTEMAP_VS_B		EQU	7
TPLBYTEMAP_VS_F		EQU	(1<<TPLBYTEMAP_VS_B)

* ======================================================================
* ======================================================================
* CISTPL_ORG tuple
* ======================================================================
* ======================================================================
*
* CISTPL_ORG appears in the list of partition specific tuples that
* follows each format tuple. 

 STRUCTURE	TP_Organization,0
	STRUCT	tp_Organization,TUPLE_SIZEOF
	STRUCT	TPLORG_TYPE,1
	STRUCT	TPLORG_DESC,0			;variable size

TPLORGTYPE_FS		EQU	0		;partition contains FS
TPLORGTYPE_APP		EQU	1		;app specific info
TPLORGTYPE_ROMCODE	EQU	2		;partition has executable
						;code images.
* 3-$7F reserved
* $80-$FF vendor specific

TPLORGTYPE_VS_B		EQU	7
TPLORGTYPE_VS_F		EQU	(1<<TPLORGTYPE_VS_B)


	ENDC	; RESOURCES_TUPLES_I
