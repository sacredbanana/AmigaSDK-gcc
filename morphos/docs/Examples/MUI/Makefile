demos = MUI-Demo Balancing Slidorama Virtual BoopsiDoor Class1 Class2 Class3 Class4 EnvBrowser Menus ShowHide InputHandler DragnDrop Animals ListExample ListExample2 WbMan AppWindow Layout Popup Subtask

all: $(demos)

$(demos) : % : %.c demo.h
	gcc -noixemul -o $@ $@.c

clean:
	-rm -rf $(demos)
