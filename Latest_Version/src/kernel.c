#include "C_files/video.c"
#include "C_files/builtin.c"
#include "C_files/keyboard.c"

void main() {
	CURRENTBACK = LIGHTBLUE;
	setup();
	loadHello();
	loadMenu();
	while(1){
		if(inportb(0x60)!=250){ 
			if((inportb(0x60)&0x80)){
				if(inportb(0x60)==0xAA||inportb(0x60)==0xFA) shiftkey =0;
				continue;
			}
			if(inportb(0x60)==0x1C){
				runinput();
				loadMenu();
				continue;
			}
			char next =getchar();
			if(next!=0) printchar(next);
//			CURRENTBACK+=0x10;
//			setup();
		}
	}
	for(;;);
}

