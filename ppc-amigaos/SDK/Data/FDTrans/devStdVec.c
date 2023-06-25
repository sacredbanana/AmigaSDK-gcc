
STATIC LONG stub_OpenPPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct DeviceManagerInterface *Self = ExtLib->IDevice;

    return Self->Open(
        (struct IORequest *)regarray[REG68K_A1/4],
        (ULONG)regarray[REG68K_D0/4],
        (ULONG)regarray[REG68K_D1/4]);
}
STATIC CONST struct EmuTrap stub_Open = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_OpenPPC };

STATIC APTR stub_ClosePPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct DeviceManagerInterface *Self = ExtLib->IDevice;

    return Self->Close((struct IORequest *)regarray[REG68K_A1/4]);
}
STATIC CONST struct EmuTrap stub_Close = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_ClosePPC };

STATIC APTR stub_ExpungePPC(ULONG *regarray __attribute__((unused)))
{
    return NULL;
}
STATIC CONST struct EmuTrap stub_Expunge = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_ExpungePPC };

STATIC ULONG stub_ReservedPPC(ULONG *regarray __attribute__((unused)))
{
    return 0UL;
}
STATIC CONST struct EmuTrap stub_Reserved = { TRAPINST, TRAPTYPE, stub_ReservedPPC };

STATIC VOID stub_BeginIOPPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct DeviceManagerInterface *Self = ExtLib->IDevice;

    Self->BeginIO((struct IORequest *)regarray[REG68K_A1/4]);
}
STATIC CONST struct EmuTrap stub_BeginIO = { TRAPINST, TRAPTYPENR, (ULONG (*)(ULONG *))stub_BeginIOPPC };

STATIC LONG stub_AbortIOPPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct DeviceManagerInterface *Self = ExtLib->IDevice;

    /* Old 68k software may expect a return code,
     * AbortIO() was documented to return something in the 1.3
     * autodocs.
     */
    struct IORequest *ior = (struct IORequest *)regarray[REG68K_A1/4];

    Self->AbortIO(ior);
    return ior->io_Error;
}
STATIC CONST struct EmuTrap stub_AbortIO = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_AbortIOPPC };
