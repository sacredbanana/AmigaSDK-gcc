#ifndef DOS_DOSTAGS_H
#define DOS_DOSTAGS_H

/*
	dos tag definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#define SYS_Dummy        (TAG_USER + 32)
#define SYS_Input        (SYS_Dummy + 1)
#define SYS_Output       (SYS_Dummy + 2)
#define SYS_Asynch       (SYS_Dummy + 3)
#define SYS_UserShell    (SYS_Dummy + 4)
#define SYS_CustomShell  (SYS_Dummy + 5)

/*** V50 ***/

#define SYS_FilterTags   (SYS_Dummy + 6)   /* filters the tags passed down to CreateNewProc(), default: TRUE */


#define NP_Dummy          (TAG_USER + 1000)
#define NP_Seglist        (NP_Dummy + 1)
#define NP_FreeSeglist    (NP_Dummy + 2)
#define NP_Entry          (NP_Dummy + 3)
#define NP_Input          (NP_Dummy + 4)
#define NP_Output         (NP_Dummy + 5)
#define NP_CloseInput     (NP_Dummy + 6)
#define NP_CloseOutput    (NP_Dummy + 7)
#define NP_Error          (NP_Dummy + 8)
#define NP_CloseError     (NP_Dummy + 9)
#define NP_CurrentDir     (NP_Dummy + 10)
#define NP_StackSize      (NP_Dummy + 11)
#define NP_Name           (NP_Dummy + 12)
#define NP_Priority       (NP_Dummy + 13)
#define NP_ConsoleTask    (NP_Dummy + 14)
#define NP_WindowPtr      (NP_Dummy + 15)
#define NP_HomeDir        (NP_Dummy + 16)
#define NP_CopyVars       (NP_Dummy + 17)
#define NP_Cli            (NP_Dummy + 18)
#define NP_Path           (NP_Dummy + 19)
#define NP_CommandName    (NP_Dummy + 20)
#define NP_Arguments      (NP_Dummy + 21)

#define NP_NotifyOnDeath  (NP_Dummy + 22)
#define NP_Synchronous    (NP_Dummy + 23)
#define NP_ExitCode       (NP_Dummy + 24)
#define NP_ExitData       (NP_Dummy + 25)

/*** V50 ***/

#define NP_SeglistArray   (NP_Dummy + 26)
#define NP_UserData       (NP_Dummy + 27)
#define NP_StartupMsg     (NP_Dummy + 28)  /* struct Message *, ReplyMsg'd at exit */
#define NP_TaskMsgPort    (NP_Dummy + 29)  /* struct MsgPort **, create MsgPort, automagic delete */
#define NP_TaskFlags      (NP_Dummy + 30)  /* UBYTE of initial task tc_Flags */

#define NP_CodeType       (NP_Dummy + 100)
#define NP_PPC_Arg1       (NP_Dummy + 101)
#define NP_PPC_Arg2       (NP_Dummy + 102)
#define NP_PPC_Arg3       (NP_Dummy + 103)
#define NP_PPC_Arg4       (NP_Dummy + 104)
#define NP_PPC_Arg5       (NP_Dummy + 105)
#define NP_PPC_Arg6       (NP_Dummy + 106)
#define NP_PPC_Arg7       (NP_Dummy + 107)
#define NP_PPC_Arg8       (NP_Dummy + 108)
#define NP_PPCStackSize   (NP_Dummy + 109)


#define ADO_Dummy        (TAG_USER + 2000)
#define ADO_FH_Mode      (ADO_Dummy + 1)

#define ADO_DirLen       (ADO_Dummy + 2)
#define ADO_CommNameLen  (ADO_Dummy + 3)
#define ADO_CommFileLen  (ADO_Dummy + 4)
#define ADO_PromptLen    (ADO_Dummy + 5)
#define ADO_CLI_Dir          (ADO_Dummy + 20) /* BSTR (fixed) */
#define ADO_CLI_CommName     (ADO_Dummy + 21) /* BSTR (fixed) */
#define ADO_CLI_CommFile     (ADO_Dummy + 22) /* BSTR (fixed) */
#define ADO_CLI_Prompt       (ADO_Dummy + 23) /* BSTR (fixed) */
#define ADO_CLI_Result2      (ADO_Dummy + 24) /* LONG */
#define ADO_CLI_ReturnCode   (ADO_Dummy + 25) /* LONG */
#define ADO_CLI_FailLevel    (ADO_Dummy + 26) /* LONG */
#define ADO_CLI_Interactive  (ADO_Dummy + 27) /* LONG */
#define ADO_CLI_Background   (ADO_Dummy + 28) /* LONG */
#define ADO_CLI_DefaultStack (ADO_Dummy + 29) /* LONG */

/* DOS_DEVICENODE tags */

#define ADO_DN_Name          (ADO_Dummy + 30) /* BSTR */
#define ADO_DN_MsgPort       (ADO_Dummy + 31) /* struct MsgPort* */
#define ADO_DN_Lock          (ADO_Dummy + 32) /* BPTR */
#define ADO_DN_Handler       (ADO_Dummy + 33) /* BSTR */
#define ADO_DN_Seglist       (ADO_Dummy + 34) /* BPTR */
#define ADO_DN_StackSize     (ADO_Dummy + 35) /* ULONG Default: 4096 */
#define ADO_DN_Priority      (ADO_Dummy + 36) /* LONG */
#define ADO_DN_Startup       (ADO_Dummy + 37) /* BSTR */
#define ADO_DN_GlobalVec     (ADO_Dummy + 38) /* BPTR */
/*
 * Only for new devicenodes created by AllocDosObject()
 */
#define ADO_DN_SerialID      (ADO_Dummy + 39) /* BPTR */
/*
 * Value < 0x100 as startup argument
 */
#define ADO_DN_StartupValue  (ADO_Dummy + 40) /* ULONG */
/*
 * New (dos.lib 51.40+) tags
 */
#define ADO_DN_Flags         (ADO_Dummy + 41) /* ULONG */
#define ADO_DN_Status		 (ADO_Dummy + 42) /* ULONG */
#define ADO_DN_ExitNotifyMsg (ADO_Dummy + 43) /* struct Msg* */

/* Run handler only once, do not reload after exit */
#define DNF_STARTONCE		(1 << 0)
/* Free handler seglist after handler exit */
#define DNF_UNLOADSEGLIST	(1 << 1)
/* Remove doslist entry after handler exit */
#define DNF_REMDOSLIST		(1 << 2)

/*
 * Do not depend on a positive result here to retrieve
 * other ADO_FSSM tags. It's only here for information
 * dump purposes. It doesn't mean that future DeviceNode's
 * would keep it.
 * Only useful for GetDosObjectAttr()
 */
#define ADO_FSSM             (ADO_Dummy + 50) /* struct FileSysStartupMsg* */
#define ADO_FSSM_Device      (ADO_Dummy + 51) /* BSTR */
#define ADO_FSSM_Unit        (ADO_Dummy + 52) /* ULONG */
#define ADO_FSSM_Flags       (ADO_Dummy + 53) /* ULONG */

/*
 * Do not depend on a positive result here to retrieve
 * other ADO_DE tags. It's only here for information
 * dump purposes. It doesn't mean that future DeviceNode's
 * would keep it.
 * Only useful for GetDosObjectAttr()
 */
#define ADO_DE               (ADO_Dummy + 60) /* struct DosEnvec* */
#define ADO_DE_TableSize     (ADO_Dummy + 61) /* ULONG Default: DE_BOOTBLOCKS */
#define ADO_DE_SizeBlock     (ADO_Dummy + 62) /* ULONG Default: 512 */
#define ADO_DE_SecOrg        (ADO_Dummy + 63) /* ULONG */
#define ADO_DE_NumHeads      (ADO_Dummy + 64) /* ULONG */
#define ADO_DE_Surfaces      ADO_DE_NumHeads
#define ADO_DE_SecsPerBlk    (ADO_Dummy + 65) /* ULONG Default: 1 */
#define ADO_DE_BlksPerTrack  (ADO_Dummy + 66) /* ULONG */
#define ADO_DE_ReservedBlks  (ADO_Dummy + 67) /* ULONG */
#define ADO_DE_PreFac        (ADO_Dummy + 68) /* ULONG */
#define ADO_DE_PreAlloc      ADO_DE_PreFac
#define ADO_DE_Interleave    (ADO_Dummy + 69) /* ULONG */
#define ADO_DE_LowCyl        (ADO_Dummy + 70) /* ULONG */
#define ADO_DE_UpperCyl      (ADO_Dummy + 71) /* ULONG */
#define ADO_DE_HighCyl       ADO_DE_UpperCyl
#define ADO_DE_NumBuffers    (ADO_Dummy + 72) /* ULONG */
#define ADO_DE_BufMemType    (ADO_Dummy + 73) /* ULONG */
#define ADO_DE_MaxTransfer   (ADO_Dummy + 74) /* ULONG Default: 0xffffffff */
#define ADO_DE_Mask          (ADO_Dummy + 75) /* ULONG Default: 0xffffffff */
#define ADO_DE_BootPri       (ADO_Dummy + 76) /* LONG */
#define ADO_DE_DosType       (ADO_Dummy + 77) /* ULONG */
#define ADO_DE_Baud          (ADO_Dummy + 78) /* ULONG */
#define ADO_DE_Control       (ADO_Dummy + 79) /* BSTR */
#define ADO_DE_BootBlocks    (ADO_Dummy + 80) /* ULONG */

/*
 * Used by AllocDosObject's FSContext creation to find the
 * right filesystem's seglist with the dostype through Query.
 * So you either define a seglist by ADO_DN_Seglist or let
 * dos search it by the DosType.
 *
 * Don't mix this up with ADO_DE_DosType
 */
#define ADO_FS_DosType       (ADO_Dummy + 90) /* ULONG */

#define ADO_VN_Name          (ADO_Dummy + 100) /* BSTR */
#define ADO_VN_MsgPort       (ADO_Dummy + 101) /* struct MsgPort* */
#define ADO_VN_Lock          (ADO_Dummy + 102) /* BPTR */
#define ADO_VN_LockList      (ADO_Dummy + 103) /* struct Lock* */
#define ADO_VN_Date          (ADO_Dummy + 104) /* struct DateStamp* */
#define ADO_VN_DiskType      (ADO_Dummy + 105) /* ULONG */


#define ADO_AN_Name          (ADO_Dummy + 120) /* BSTR */
#define ADO_AN_MsgPort       (ADO_Dummy + 121) /* struct MsgPort* */
#define ADO_AN_Lock          (ADO_Dummy + 122) /* BPTR */
#define ADO_AN_Type          (ADO_Dummy + 123) /* ULONG */
#define ADO_AN_AssignName    (ADO_Dummy + 124) /* char* */
#define ADO_AN_AssignList    (ADO_Dummy + 125) /* struct AssignList* */



/* GetDosObjectAttr() uses this to store variable size entries.
 *
 * BSTR
 *
 * To query size of the buffer required for the string, set
 * dab_Ptr to NULL. After the call dab_Len will contain the
 * required size, including the terminating 0.
 *
 * To get the string set dab_Ptr to point to buffer of dab_Len
 * bytes. The resulting string is always 0-terminated, even
 * if the string is truncated.
 */
struct DosAttrBuffer
{
	APTR  dab_Ptr;
	ULONG dab_Len;
};


/*** V50 ***/

#define ADDS_Dummy       (TAG_USER + 3000)
#define ADDS_Name        (ADDS_Dummy + 1)  /* Segment name */
#define ADDS_Seglist     (ADDS_Dummy + 2)  /* Seglist for this segment */
#define ADDS_Filename    (ADDS_Dummy + 3)  /* Name of the file to load when needed. Ignored if Seglist is given. */
#define ADDS_Type        (ADDS_Dummy + 4)  /* Segment type */

#define FNDS_Dummy       (TAG_USER + 3100)
#define FNDS_Name        (FNDS_Dummy + 1)  /* Segment name */
#define FNDS_From        (FNDS_Dummy + 2)  /* Segment to start from */
#define FNDS_System      (FNDS_Dummy + 3)  /* Look for a system segment ? */
#define FNDS_Load        (FNDS_Dummy + 4)  /* Load the seglist if needed ? (Default: TRUE) */
#define FNDS_MatchPattern (FNDS_Dummy + 5)  /* Pattern to match segment name against, from ParsePatternNoCase (dos 50.69) */

/*** V51 ***/

#define FSCONTEXTTAG_Dummy              (TAG_USER + 3200)
/*
 * Pass a custom handler seglist. This handler MUST be able
 * to handle the fscontext filesystem extension
 */
#define FSCONTEXTTAG_SEGLIST            (FSCONTEXTTAG_Dummy + 0x1)
#define FSCONTEXTTAG_PRIORITY           (FSCONTEXTTAG_Dummy + 0x2)
#define FSCONTEXTTAG_STACKSIZE          (FSCONTEXTTAG_Dummy + 0x3)
#define FSCONTEXTTAG_STARTUPSTRING      (FSCONTEXTTAG_Dummy + 0x4)
#define FSCONTEXTTAG_STARTUPVALUE       (FSCONTEXTTAG_Dummy + 0x5)
#define FSCONTEXTTAG_FSSM               (FSCONTEXTTAG_Dummy + 0x6)
/*
 * A matching filesystem is searched through query.library
 */
#define FSCONTEXTTAG_DOSTYPE            (FSCONTEXTTAG_Dummy + 0x7)

#define FSCONTEXTINFOTAG_Dummy          (TAG_USER + 3300)
#define FSCONTEXTINFOTAG_NAME           (FSCONTEXTINFOTAG_Dummy + 0x1)

#define SEGLISTTAG_Dummy                (TAG_USER + 3400)
/*
 * return the ObjData object when it exists or NULL.
 */
#define SEGLISTTAG_OBJDATA              (SEGLISTTAG_Dummy + 0x1)
/*
 * return the seglist type, one of SEGLISTTYPE_*.
 *
 * V51.52
 */
#define SEGLISTTAG_SEGLISTTYPE          (SEGLISTTAG_Dummy + 0x2)

#define SEGLISTTYPE_ELF                 1
#define SEGLISTTYPE_POWERUP             2
#define SEGLISTTYPE_AMIGA               3

/*
 * specify that segment index is the hunk number, starting from 0.
 *
 * V51.52
 */
#define SEGLISTTAG_DOS_SEGINDEX         (SEGLISTTAG_Dummy + 0x3)

/*
 * specify that the segment index is the elf segment number,
 * starting from 1.
 *
 * V51.52
 */
#define SEGLISTTAG_ELF_SEGINDEX         (SEGLISTTAG_Dummy + 0x4)
/*
 * return segment start address for segment specified by
 * either SEGLISTTAG_DOS_SEGINDEX or SEGLISTTAG_ELF_SEGINDEX.
 * note that SEGLISTTAG_ELF_SEGINDEX segments might return a
 * NULL pointer, so be prepared for this.
 *
 * V51.52
 */
#define SEGLISTTAG_SEGSTART             (SEGLISTTAG_Dummy + 0x5)
/*
 * return segment data size for segment specified by
 * either SEGLISTTAG_DOS_SEGINDEX or SEGLISTTAG_ELF_SEGINDEX.
 *
 * V51.52
 */
#define SEGLISTTAG_SEGSIZE              (SEGLISTTAG_Dummy + 0x6)
/*
 * return ELF segment type (ELF SHT_*). Only applicable for ELF.
 *
 * V51.54
 */
#define SEGLISTTAG_ELF_SEGTYPE          (SEGLISTTAG_Dummy + 0x7)
/*
 * return ELF segment file offset. Only applicable for ELF.
 *
 * V51.54
 */
#define SEGLISTTAG_ELF_SEGOFFSET        (SEGLISTTAG_Dummy + 0x8)
/*
 * return ELF segment flags. Meaning depends on segment type.
 * Refer to ELF documentation for details. Only applicable for ELF.
 *
 * V51.54
 */
#define SEGLISTTAG_ELF_SEGFLAGS         (SEGLISTTAG_Dummy + 0x9)
/*
 * return ELF segment alignment. 0 and 1 mean unaligned.
 * Only applicable for ELF.
 *
 * V51.54
 */
#define SEGLISTTAG_ELF_SEGADDRALIGN     (SEGLISTTAG_Dummy + 0xa)
/*
 * return ELF segname name. Only applicable for ELF.
 *
 * V51.54
 */
#define SEGLISTTAG_ELF_SEGNAME          (SEGLISTTAG_Dummy + 0xb)


/*
 * QueryCLIDataTagList tags (V51.51)
 */
#define CLIDATATAG_Dummy                (TAG_USER + 3500)
/*
 * Return only CLI matching the given CLI number (returns 0 or 1 entries)
 */
#define CLIDATATAG_CLINumber            (CLIDATATAG_Dummy + 0x1)
/*
 * Return only CLIs matching the given command (0 to n entries possible)
 */
#define CLIDATATAG_CommandName          (CLIDATATAG_Dummy + 0x2)
/*
 * When ti_Data is TRUE, return results sorted by CLI number
 * (default to FALSE)
 */
#define CLIDATATAG_Sorted               (CLIDATATAG_Dummy + 0x3)

#endif /* DOS_DOSTAGS_H */
