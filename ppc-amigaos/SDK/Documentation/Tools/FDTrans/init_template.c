/*
 * This assumes that the following symbols are defined:
 * LIBNAME		(Example: "graphics.library")
 * LIBVERSION	(Example: 0)
 * IFACENAME	(Example: "graphics.library.main")
 */
static void InitFunction(APTR dummy, ULONG SegList, struct ExecBase *ExecBase)
{
	struct Library *LibBase;
	struct Interface *NewInterface;
	struct ExecIFace *IExec = (struct ExecIFace *)ExecBase->MainInterface;
	
	LibBase = IExec->OpenLibrary(LIBNAME, LIBVERSION);
	if (LibBase)
	{
		NewInterface = IExec->MakeInterfaceTags(LibBase,
			MIT_VectorTable,	main_vectors,
			MIT_Version,		1,
			MIT_Name,			IFACENAME,
		TAG_DONE);
		if (NewInterface)
		{
			NewInterface->Data.IExecPrivate = (APTR)IExec;
			IExec->AddInterface(LibBase, NewInterface);
		}
	}
}

volatile static struct Resident MyResident =
{
	RTC_MATCHWORD,
	(struct Resident *)&MyResident,
	(struct Resident *)&MyResident+1,
	RTF_NATIVE,
	LIBVERSION,
	NT_UNKNOWN,
	-120,
	IFACENAME,
	IFACENAME,
	InitFunction
};

void _start(void)
{
	// printf("This program cannot be run in DOS mode :-)\n");
}
