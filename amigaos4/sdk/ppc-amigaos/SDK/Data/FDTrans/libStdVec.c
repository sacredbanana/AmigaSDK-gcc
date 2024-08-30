
STATIC struct Library * stub_OpenPPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct LibraryManagerInterface *Self = (struct LibraryManagerInterface *) ExtLib->ILibrary;

    return Self->Open(0);
}
STATIC CONST struct EmuTrap stub_Open = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_OpenPPC };

STATIC APTR stub_ClosePPC(ULONG *regarray)
{
    struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
    struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
    struct LibraryManagerInterface *Self = (struct LibraryManagerInterface *) ExtLib->ILibrary;

    return Self->Close();
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
