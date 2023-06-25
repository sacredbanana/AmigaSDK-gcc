/*
 * This assumes that the following symbols are defined:
 * LIBNAME     (Example: "graphics.library")
 * LIBVERSION  (Example: 0)
 * IFACENAME   (Example: "graphics.library.main")
 */
static APTR InitFunction(APTR dummy,
                         ULONG SegList __attribute__((unused)),
                         struct ExecBase *ExecBase)
{
    struct Library *LibBase;
    struct Interface *NewInterface = NULL;
    struct ExecIFace *IExec = (struct ExecIFace *)ExecBase->MainInterface;
    
    LibBase = IExec->OpenLibrary(LIBNAME, LIBVERSION);

    if (LibBase)
    {
        NewInterface = IExec->MakeInterfaceTags(LibBase,
                                                MIT_VectorTable, main_vectors,
                                                MIT_Version,     1,
                                                MIT_Name,        IFACENAME,
                                                TAG_DONE);

        if (NewInterface)
        {
            NewInterface->Data.IExecPrivate = (APTR)IExec;
            IExec->AddInterface(LibBase, NewInterface);
        }
    }

    return(NewInterface);
}

#ifndef USED
#define USED __attibute__((used))
#endif

STATIC CONST USED struct Resident MyResident =
{
    RTC_MATCHWORD,
    (APTR)&MyResident,
    (APTR)(&MyResident+1),
    RTF_NATIVE,
    LIBVERSION, /* Change this to the interface version if you want */
    NT_UNKNOWN,
    -120,
    IFACENAME,
    IFACENAME, /* Change this to &"$VER: foo.library.main 51.1 (13.10.2005)\r\n"[6] if you want */
    InitFunction
};

int32 _start(void);

int32 _start(void)
{
    /* User did try to execute us as standalone program */

    // printf("This program cannot be run in DOS mode :-)\n");
    return 100;
}
