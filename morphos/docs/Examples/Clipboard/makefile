
FILES = imageclipwrite  clipcheck htmlclipwrite \
 textclipread textclipreadutf8 textclipwrite htmlclipread 

.PHONY: clean

all: $(FILES)

 clipcheck: clipcheck.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

imageclipwrite: imageclipwrite.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

textclipread:  textclipread.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

textclipreadutf8: textclipreadutf8.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

textclipwrite: textclipwrite.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

htmlclipwrite: htmlclipwrite.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall
	
htmlclipread: htmlclipread.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

clean:
	-rm $(FILES)
