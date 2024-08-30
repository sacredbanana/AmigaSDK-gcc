;/* execute me to compile
gcc -o rom_dump rom_dump.c -lauto
quit
*/

/* ROM Dump tool for OS4, (C) Copyright 2004 Ross Vumbaca. */
/* Example code/Freeware! - Version 1.3 */

/* Failings of this program:
 * 
 * - The program should check that the size of the BAR is sufficient to map a ROM into
 * - The program can fail with Radeon chips, but this is due to the chip, not the program
 *
 */

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/expansion.h>
#include <expansion/pci.h>

#include <stdio.h>
#include <stdlib.h>

struct PCIDevice *pcidev = NULL;
struct Library *expansionBase;
struct PCIIFace *IPCI;
struct MMUIFace *IMMU;

void print_usage()
{
  printf("\nOS4 PCI/AGP Card ROM Dump tool 1.2\n");
  printf("(C) Copyright 2004 Ross Vumbaca\n\n");
  printf("This small utilitiy can be used to dump the ROM of your PCI/AGP card.\n");
  printf("The tool requires three command line arguments - the Vendor ID and Device ID of your\n");
  printf("chosen card (in hexadecimal), and a file name to write the ROM image to.\n\n");
  printf("For example, to dump the ROM of the Voodoo 3 AGP card:\n\n");
  printf("rom-dump 121a 0005 rom.image\n\n");
  printf("Thank you to Hans-Joerg Frieden for describing the process of mapping a PCI Card ROM.\n");
  printf("Thank you to Stephane Guillard for helpful suggestions, hints and encouragement.\n");
  printf("Thank you to Thomas Frieden for describing how to modify memory attributes.\n\n");
  printf("WARNING: This program comes with absolutely no guarantees, and can lock up your machine\n");
  printf("in unexpected circumstances. Enjoy!\n\n");
}

void clean_up()
{
  if (pcidev)
  {
    IPCI ->FreeDevice(pcidev);
  }
  IExec->DropInterface((struct Interface *)IPCI);
  IExec->CloseLibrary(expansionBase);
  IExec->DropInterface((struct Interface *)IMMU);
}

int main(int argc, char *argv[])
{
  int i, result; 
  ULONG vendor, device, BAR, rom_size, attrs;
  BPTR rom_file = ZERO;
  APTR oldStack, rom_buffer = 0;
  
  /* Do some command line checking and parsing */
  if (argc != 4)
  {
    print_usage();
    return 5;
  }
 
  vendor = strtoul(argv[1], NULL, 16);
  device = strtoul(argv[2], NULL, 16);
 
  if (vendor == 0 | device == 0)
  {
    print_usage();
    return 5;
  }

  /* Open required OS resources, get handle to specified PCI device. */
  expansionBase = IExec->OpenLibrary("expansion.library", 50L);
  if (!expansionBase)
  {
    printf("\nCould not open expansion.library.\n\n");
    return 20;
  }

  IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)SysBase, "mmu", 1, NULL);
  if (!IMMU)
  {
    printf("\nUnable to obtain MMU interface.\n\n");
    return 20;
  }
  
  IPCI = (struct PCIIFace *)IExec->GetInterface(expansionBase, "pci", 1, NULL);
  if (!IPCI)
  {
    printf("\nUnable to obtain PCI interface.\n\n");
    IExec->CloseLibrary(expansionBase);
    return 20;
  }

  
  /* Look for the given PCI device */
  pcidev = IPCI->FindDeviceTags(
      FDT_VendorID, vendor,
      FDT_DeviceID, device,
      FDT_Index, (ULONG)0,
      TAG_DONE);

  if (!pcidev)
  {
    printf("\nCannot find specified PCI/AGP device.\n\n");
    clean_up();
    return 5;
  }

  /* Open the output file. */
  rom_file = IDOS->Open(argv[3], MODE_NEWFILE);
 
  if (rom_file == ZERO)
  {
    printf("\nError - Cannot open file %s for output.\n\n", argv[3]);
    clean_up();
    return 10;
  }
  
  /* Check the size of the ROM. */
  pcidev->WriteConfigLong(0x30, 0xfffff800);
  __asm volatile ("sync; isync");

  rom_size = pcidev->ReadConfigLong(0x30); 
  __asm volatile ("sync; isync");

  rom_size = (~rom_size) + 1;
  
  if (rom_size == 0)
  {
    printf("\nError - ROM size is 0 bytes.\n\n");
    clean_up();
    IDOS->Close(rom_file);
    return 10;
  }

  /* Allocate RAM buffer to copy ROM into. */
  rom_buffer = IExec->AllocVecTags( rom_size,
      AVT_Type, MEMF_PRIVATE,
      AVT_ClearWithValue, '\0',
      TAG_DONE);

  /* Make sure memory request succeeded. */
  if (rom_buffer == 0)
  {
    clean_up();
    return 10; 
  }
  
  /* Backup the original first BAR value. */
  BAR = pcidev->ReadConfigLong(0x10);
  __asm volatile ("sync; isync");

  BAR = BAR & 0xFFFFFFF0;
  
  /* Disable interrupts so that the program is not disrupted */
  IExec->Disable();
  
  /* Disable the first BAR. */
  pcidev->WriteConfigLong(0x10, 0x00000000);
  __asm volatile ("sync; isync");
  
  /* Copy the BAR address to the ROM BAR, and set enable bit. */
  pcidev->WriteConfigLong(0x30, BAR|1); 
  __asm volatile ("sync; isync");
 
  /* Backup memory attributes of the BAR memory area */
  attrs = IMMU->GetMemoryAttrs((APTR)BAR, 0);  

  /* Enter Supervisor Mode */
  oldStack = IExec->SuperState();
  
  /* Re-map the memory range attributes to read/write, cache inhibited, guarded */
  IMMU->RemapMemory((APTR)BAR, (APTR)BAR, rom_size, MEMATTRF_READ_WRITE|MEMATTRF_CACHEINHIBIT|MEMATTRF_GUARDED);
  
  /* Exit Supervisor Mode */
  IExec->UserState(oldStack);
  
  /* Copy the ROM to the RAM buffer */
  IExec->CopyMem((APTR)BAR, rom_buffer, rom_size);
  
  /* Enter Supervisor Mode again */
  oldStack = IExec->SuperState();
  
  /* Restore the original memory range attributes */
  IMMU->RemapMemory((APTR)BAR, (APTR)BAR, rom_size, attrs);
  
  /* Exit Supervisor Mode */
  IExec->UserState(oldStack);
  
  /* Disable the ROM BAR. */
  pcidev->WriteConfigLong(0x30, 0x00000000);
  __asm volatile ("sync; isync");

  /* Restore the original first BAR value. */
  pcidev->WriteConfigLong(0x10, BAR);
  __asm volatile ("sync; isync");
 
  /* Enable interrupts again */  
  IExec->Enable();

  /* Clean up opened resources. */
  clean_up();

  /* Write the contents of the buffer to the output file. */
  result = IDOS->Write(rom_file, rom_buffer, rom_size);
  
  /* Make sure write succeded. */
  if (result < rom_size)
  {
    printf("\nError - Unable to write output file.\n\n");
    IDOS->Close(rom_file);
    return 10;
  }

  /* Close the output file. */
  IDOS->Close(rom_file);
 
  /* Free the RAM buffer. */
  IExec->FreeVec(rom_buffer);

  return 0;
}

