	IFND	DOS_DOS_LIB_I
DOS_DOS_LIB_I	SET	1
**
**	$VER: dos_lib.i 47.1 (8.11.2021)
**
**	Library interface offsets for DOS library
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
**

reserve EQU     4
vsize   EQU     6
count   SET     -vsize*(reserve+1)
LIBENT  MACRO
_LVO\1  EQU     count
count   SET     count-vsize
        ENDM
*
*
*
   LIBENT   Open
   LIBENT   Close
   LIBENT   Read
   LIBENT   Write
   LIBENT   Input
   LIBENT   Output
   LIBENT   Seek
   LIBENT   DeleteFile
   LIBENT   Rename
   LIBENT   Lock
   LIBENT   UnLock
   LIBENT   DupLock
   LIBENT   Examine
   LIBENT   ExNext
   LIBENT   Info
   LIBENT   CreateDir
   LIBENT   CurrentDir
   LIBENT   IoErr
   LIBENT   CreateProc
   LIBENT   Exit
   LIBENT   LoadSeg
   LIBENT   UnLoadSeg
   LIBENT   GetPacket
   LIBENT   QueuePacket
   LIBENT   DeviceProc
   LIBENT   SetComment
   LIBENT   SetProtection
   LIBENT   DateStamp
   LIBENT   Delay
   LIBENT   WaitForChar
   LIBENT   ParentDir
   LIBENT   IsInteractive
   LIBENT   Execute

	ENDC	; DOS_DOS_LIB_I
