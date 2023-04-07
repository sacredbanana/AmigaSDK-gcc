	IFND	DOS_SHELL_I
DOS_SHELL_I	SET	1
**
**	$VER: shell.i 47.1 (29.11.2019)
**
**	DOS structures for the shell interface 
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.

	IFND  EXEC_TYPES_I
	INCLUDE "exec/types.i"
	ENDC

	IFND  EXEC_NODES_I
	INCLUDE "exec/nodes.i"
	ENDC
	
	IFND  UTILITY_TAGITEM_I
	INCLUDE "utility/tagitem.i"
	ENDC
	
	IFND UTILITY_HOOKS_I
	INCLUDE "utility/hooks.i"
	ENDC

	IFND DOS_DOS_I
	INCLUDE "dos/dos.i"
	ENDC

* DOS Processes started from the CLI via RUN or NEWCLI have this additional
* set to data associated with them. This is the extended structure that
* includes additional interfaces to communicate with the shell

 STRUCTURE ExtendedCommandLineInterface,0
	  LONG   cle_Result2	    * Value of IoErr from last command
	  BSTR   cle_SetName	    * Name of current directory
	  BPTR   cle_CommandDir     * Head of the path locklist
	  LONG   cle_ReturnCode     * Return code from last command
	  BSTR   cle_CommandName    * Name of current command
	  LONG   cle_FailLevel      * Fail level (set by FAILAT)
	  BSTR   cle_Prompt	    * Current prompt (set by PROMPT)
	  BPTR   cle_StandardInput  * Default (terminal) CLI input
	  BPTR   cle_CurrentInput   * Current CLI input
	  BSTR   cle_CommandFile    * Name of EXECUTE command file
	  LONG   cle_Interactive    * Boolean, True if prompts required
	  LONG   cle_Background     * Boolean, True if CLI created by RUN
	  BPTR   cle_CurrentOutput  * Current CLI output
	  LONG   cle_DefaultStack   * Stack size to be obtained in long words
	  BPTR   cle_StandardOutput * Default terminal CLI output
	  BPTR   cle_Module         * SegList of currently loaded command
	  STRUCT cle_Hook,h_SIZEOF  * For requesting shell functions
	  APTR   cle_This           * pointer to itself
	  LABEL  cle_SIZEOF	    * CommandLineInterface
	  LONG   cle_Version        * Version of the interface. V47 currently

** A history entry or a line in the history 
** Never allocate yourself, go through the shell methods.

 STRUCTURE HistoryNode,0
	  STRUCT hn_Node,MLN_SIZE
	  APTR   hn_Line            * the expanded line
	  LABEL  hn_SIZEOF


* Tags used by the shell
SHELL_DUMMY              EQU TAG_USER+3000

* for FGetShell: If TRUE, a string including a command is
* requested. Otherwise, only arguments.
SHELL_FGETS_FULL         EQU SHELL_DUMMY+1

* For ADDHIST: The line to add
*
SHELL_ADDH_LINE          EQU SHELL_DUMMY+2

	ENDC  * DOS_SHELL_I

