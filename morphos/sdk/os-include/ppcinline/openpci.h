/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_OPENPCI_H
#define _PPCINLINE_OPENPCI_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef OPENPCI_BASE_NAME
#define OPENPCI_BASE_NAME OpenPciBase
#endif /* !OPENPCI_BASE_NAME */

#define pci_bus() \
	LP0(30, unsigned short , pci_bus, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_write_config_byte(__p0, __p1, __p2) \
	LP3NR(126, pci_write_config_byte, \
		unsigned char , __p0, d0, \
		unsigned char , __p1, d1, \
		struct pci_dev *, __p2, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_outb(__p0, __p1) \
	LP2NR(42, pci_outb, \
		unsigned char , __p0, d0, \
		unsigned long , __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_outl(__p0, __p1) \
	LP2NR(66, pci_outl, \
		unsigned long , __p0, d0, \
		unsigned long , __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_add_intserver(__p0, __p1) \
	LP2(150, BOOL , pci_add_intserver, \
		struct Interrupt *, __p0, a0, \
		struct pci_dev *, __p1, a1, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_outw(__p0, __p1) \
	LP2NR(54, pci_outw, \
		unsigned short , __p0, d0, \
		unsigned long , __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_write_config_word(__p0, __p1, __p2) \
	LP3NR(132, pci_write_config_word, \
		unsigned char , __p0, d0, \
		unsigned short , __p1, d1, \
		struct pci_dev *, __p2, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_read_config_long(__p0, __p1) \
	LP2(120, unsigned long , pci_read_config_long, \
		unsigned char , __p0, d0, \
		struct pci_dev *, __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_to_hostcpy(__p0, __p1, __p2) \
	LP3NR(72, pci_to_hostcpy, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		unsigned long , __p2, d0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_find_device(__p0, __p1, __p2) \
	LP3(90, struct pci_dev *, pci_find_device, \
		unsigned short , __p0, d0, \
		unsigned short , __p1, d1, \
		struct pci_dev *, __p2, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_freedma_mem(__p0, __p1) \
	LP2NR(168, pci_freedma_mem, \
		APTR , __p0, a0, \
		unsigned long , __p1, d0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_find_class(__p0, __p1) \
	LP2(96, struct pci_dev *, pci_find_class, \
		unsigned long , __p0, d0, \
		struct pci_dev *, __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_rem_intserver(__p0, __p1) \
	LP2NR(156, pci_rem_intserver, \
		struct Interrupt *, __p0, a0, \
		struct pci_dev *, __p1, a1, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define host_to_pcicpy(__p0, __p1, __p2) \
	LP3NR(78, host_to_pcicpy, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		unsigned long , __p2, d0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_logic_to_physic_addr(__p0, __p1) \
	LP2(174, APTR , pci_logic_to_physic_addr, \
		APTR , __p0, a0, \
		struct pci_dev *, __p1, a1, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_allocdma_mem(__p0, __p1) \
	LP2(162, APTR , pci_allocdma_mem, \
		unsigned long , __p0, d0, \
		unsigned long , __p1, d1, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_write_config_long(__p0, __p1, __p2) \
	LP3NR(138, pci_write_config_long, \
		unsigned char , __p0, d0, \
		unsigned long , __p1, d1, \
		struct pci_dev *, __p2, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_to_pcicpy(__p0, __p1, __p2) \
	LP3NR(84, pci_to_pcicpy, \
		void *, __p0, a0, \
		void *, __p1, a1, \
		unsigned long , __p2, d0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_read_config_byte(__p0, __p1) \
	LP2(108, unsigned char , pci_read_config_byte, \
		unsigned char , __p0, d0, \
		struct pci_dev *, __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_inb(__p0) \
	LP1(36, unsigned char , pci_inb, \
		unsigned long , __p0, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_inl(__p0) \
	LP1(60, unsigned long , pci_inl, \
		unsigned long , __p0, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_read_config_word(__p0, __p1) \
	LP2(114, unsigned short , pci_read_config_word, \
		unsigned char , __p0, d0, \
		struct pci_dev *, __p1, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_inw(__p0) \
	LP1(48, unsigned short , pci_inw, \
		unsigned long , __p0, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_set_master(__p0) \
	LP1(144, BOOL , pci_set_master, \
		struct pci_dev *, __p0, a0, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define pci_find_slot(__p0, __p1) \
	LP2(102, struct pci_dev *, pci_find_slot, \
		unsigned char , __p0, d0, \
		unsigned long , __p1, d1, \
		, OPENPCI_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_OPENPCI_H */
