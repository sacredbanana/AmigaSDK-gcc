/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CDPLAYER_H
#define _INLINE_CDPLAYER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

BYTE __CDEject(__reg("a6") struct Library * , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-30(a6)";
#define CDEject(io_ptr) __CDEject(CDPlayerBase, (io_ptr))

BYTE __CDPlay(__reg("a6") struct Library * , __reg("a0") ULONG starttrack , __reg("a1") ULONG endtrack , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-36(a6)";
#define CDPlay(starttrack, endtrack, io_ptr) __CDPlay(CDPlayerBase, (starttrack), (endtrack), (io_ptr))

BYTE __CDResume(__reg("a6") struct Library * , __reg("a0") BOOL Mode , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-42(a6)";
#define CDResume(Mode, io_ptr) __CDResume(CDPlayerBase, (Mode), (io_ptr))

BYTE __CDStop(__reg("a6") struct Library * , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-48(a6)";
#define CDStop(io_ptr) __CDStop(CDPlayerBase, (io_ptr))

BYTE __CDJump(__reg("a6") struct Library * , __reg("a0") ULONG Blocks , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-54(a6)";
#define CDJump(Blocks, io_ptr) __CDJump(CDPlayerBase, (Blocks), (io_ptr))

BOOL __CDActive(__reg("a6") struct Library * , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-60(a6)";
#define CDActive(io_ptr) __CDActive(CDPlayerBase, (io_ptr))

ULONG __CDCurrentTitle(__reg("a6") struct Library * , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-66(a6)";
#define CDCurrentTitle(io_ptr) __CDCurrentTitle(CDPlayerBase, (io_ptr))

BYTE __CDTitleTime(__reg("a6") struct Library * , __reg("a0") struct CD_Time * cd_time , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-72(a6)";
#define CDTitleTime(cd_time, io_ptr) __CDTitleTime(CDPlayerBase, (cd_time), (io_ptr))

BYTE __CDGetVolume(__reg("a6") struct Library * , __reg("a0") struct CD_Volume * vol , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-78(a6)";
#define CDGetVolume(vol, io_ptr) __CDGetVolume(CDPlayerBase, (vol), (io_ptr))

BYTE __CDSetVolume(__reg("a6") struct Library * , __reg("a0") struct CD_Volume * vol , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-84(a6)";
#define CDSetVolume(vol, io_ptr) __CDSetVolume(CDPlayerBase, (vol), (io_ptr))

BYTE __CDReadTOC(__reg("a6") struct Library * , __reg("a0") struct CD_TOC * toc , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-90(a6)";
#define CDReadTOC(toc, io_ptr) __CDReadTOC(CDPlayerBase, (toc), (io_ptr))

BYTE __CDInfo(__reg("a6") struct Library * , __reg("a0") struct CD_Info * cdi , __reg("a5") struct IOStdReq * io_ptr ) = "\tjsr\t-96(a6)";
#define CDInfo(cdi, io_ptr) __CDInfo(CDPlayerBase, (cdi), (io_ptr))

#endif /* !_INLINE_CDPLAYER_H */
