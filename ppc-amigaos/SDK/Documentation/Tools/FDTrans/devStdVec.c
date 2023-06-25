
STATIC LONG stub_OpenPPC(ULONG *regarray)
{
	struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
	struct DeviceManagerInterface *Self = (struct DeviceManagerInterface *) ExtLib->ILibrary;

	return Self->Open(
		(struct IORequest *)regarray[REG68K_A1/4],
		(ULONG)regarray[REG68K_D0/4],
		(ULONG)regarray[REG68K_D1/4]);
}
struct EmuTrap stub_Open = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_OpenPPC };

STATIC ULONG stub_ClosePPC(ULONG *regarray)
{
	struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
	struct DeviceManagerInterface *Self = (struct DeviceManagerInterface *) ExtLib->ILibrary;

	return (ULONG) Self->Close((struct IORequest *)regarray[REG68K_A1/4]);
}
struct EmuTrap stub_Close = { TRAPINST, TRAPTYPE, stub_ClosePPC };

STATIC ULONG stub_ExpungePPC(ULONG *regarray)
{
	return 0UL;
}
struct EmuTrap stub_Expunge = { TRAPINST, TRAPTYPE, stub_ExpungePPC };

STATIC ULONG stub_ReservedPPC(ULONG *regarray)
{
	return 0UL;
}
struct EmuTrap stub_Reserved = { TRAPINST, TRAPTYPE, stub_ReservedPPC };

STATIC VOID stub_BeginIOPPC(ULONG *regarray)
{
	struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
	struct DeviceManagerInterface *Self = (struct DeviceManagerInterface *) ExtLib->ILibrary;

	Self->BeginIO((struct IORequest *)regarray[REG68K_A1/4]);
}
struct EmuTrap stub_BeginIO = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_BeginIOPPC };

STATIC VOID stub_AbortIOPPC(ULONG *regarray)
{
	struct Library *Base = (struct Library *) regarray[REG68K_A6/4];
	struct ExtendedLibrary *ExtLib = (struct ExtendedLibrary *) ((ULONG)Base + Base->lib_PosSize);
	struct DeviceManagerInterface *Self = (struct DeviceManagerInterface *) ExtLib->ILibrary;

	Self->AbortIO((struct IORequest *)regarray[REG68K_A1/4]);
}
struct EmuTrap stub_AbortIO = { TRAPINST, TRAPTYPE, (ULONG (*)(ULONG *))stub_AbortIOPPC };
