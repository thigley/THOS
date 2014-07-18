#include "C_files/video.c"
#include "C_files/builtin.c"
#include "C_files/keyboard.c"

void main() {
	CURRENTBACK = BACKLIGHTBLUE;
	setup();
//	setupscancodes();
	loadHello();
	loadMenu();
	while(1){
		if(inportb(0x60)!=250&&!(inportb(0x60)&0x80)){
			if(inportb(0x60)==0x1C){
				runinput();
				loadMenu();
				continue;
			}
			printchar(getchar());
//			CURRENTBACK+=0x10;
//			setup();
		}
	}
	for(;;);
}

