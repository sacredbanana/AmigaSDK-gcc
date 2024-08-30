
FILES = playaudio_memory playaudio_message playaudio_signal sinewave http_simple\
 http_static http_dynamic mediafault  mediagetgui

.PHONY: clean

all: $(FILES)

playaudio_memory: playaudio_memory.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

playaudio_message:  playaudio_message.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

playaudio_signal: playaudio_signal.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

sinewave: sinewave.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

http_simple: http_simple.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

http_static: http_static.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

http_dynamic: http_dynamic.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

mediafault: mediafault.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall
	
mediagetgui: mediagetgui.c
	ppc-morphos-gcc -o $@ $< -noixemul -Wall

clean:
	-rm $(FILES)
