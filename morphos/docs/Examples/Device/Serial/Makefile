
CC= ppc-morphos-gcc
RM= rm
#CC= gcc

CFLAGS= -O2 -mcpu=604e

all: serial.device.elf 8n1.device.elf

8n1.device.elf: 8n1.o
	$(CC) -nostdlib -noixemul -o $@ $< -labox -lgcc -lc

8n1.o: serial.c
	$(CC) '-DDEVNAME="8n1.device"' $(CFLAGS) -c -o $@ $<

serial.device.elf: serial.o
	$(CC) -nostdlib -noixemul -o $@ $< -labox -lgcc -lc

serial.o: serial.c
	$(CC) '-DDEVNAME="serial.device"' $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o 8n1.device.elf serial.device.elf
