/* Automatically generated header! Do not Edit! */
#ifndef  CLIB_OPENPCI_PROTOS_H
#define  CLIB_OPENPCI_PROTOS_H

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct pci_dev;
struct Interrupt;


unsigned short pci_bus(void);


struct  pci_dev *pci_find_device( unsigned short vendor, unsigned short device, struct pci_dev *pcidev);
struct  pci_dev *pci_find_class( unsigned long _class,  struct  pci_dev *pcidev);
struct  pci_dev *pci_find_slot( unsigned char bus,  unsigned long devfn);



unsigned char pci_inb(unsigned long address);
void pci_outb(unsigned char value, unsigned long address);


unsigned short pci_inw(unsigned long address);
void pci_outw(unsigned short value, unsigned long address);


unsigned long pci_inl(unsigned long address);
void pci_outl(unsigned long value, unsigned long address);


void pci_to_hostcpy(void *pcimemsrc, void *memdest, unsigned long packetsize);
void host_to_pcicpy(void *memsrc, void *pcimemdest, unsigned long packetsize);
void pci_to_pcicpy(void *pcimemsrc, void *pcimemdest, unsigned long packetsize);


unsigned char pci_read_config_byte(unsigned char registernum,struct  pci_dev *pcidev);
unsigned short pci_read_config_word(unsigned char registernum,struct  pci_dev *pcidev);
unsigned long pci_read_config_long(unsigned char registernum,struct  pci_dev *pcidev);
void pci_write_config_byte(unsigned char registernum, unsigned char val,struct  pci_dev *pcidev);
void pci_write_config_word(unsigned char registernum, unsigned short val,struct  pci_dev *pcidev);
void pci_write_config_long(unsigned char registernum, unsigned long val,struct  pci_dev *pcidev);


BOOL pci_set_master(struct  pci_dev *pcidev);


BOOL pci_add_intserver(struct Interrupt *PciInterrupt, struct pci_dev *pcidev);
void pci_rem_intserver(struct Interrupt *PciInterrupt, struct pci_dev *pcidev);


APTR pci_allocdma_mem(unsigned long size, unsigned long flags);
void pci_freedma_mem(APTR buffer,unsigned long size);


APTR pci_logic_to_physic_addr(APTR PciLogicalAddr, struct pci_dev *pcidev);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	 
