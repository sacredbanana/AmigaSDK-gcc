# simple makefile for intuition source examples

all: alphatest argbpointer monitors transparency window

alphatest: alphatest.c
	ppc-morphos-gcc -o $@ $@.c -noixemul -Wall

argbpointer: argbpointer.c
	ppc-morphos-gcc -o $@ $@.c -noixemul -Wall

monitors: monitors.c
	ppc-morphos-gcc-9 -o $@ $@.c -noixemul -Wall

transparency: transparency.c
	ppc-morphos-gcc -o $@ $@.c -noixemul -Wall

window: window.c
	ppc-morphos-gcc -o $@ $@.c -noixemul -Wall

clean:
	-rm alphatest argbpointer monitors transparency window
