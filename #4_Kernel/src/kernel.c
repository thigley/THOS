#include "C_files/video.c"
#include "C_files/builtin.c"
#include "C_files/keyboard.c"

void main() {
	CURRENTBACK = BACKLIGHTBLUE;
	setup();
//	setupscancodes();
	loadHello();
	loadMenu();
//	print("USER:~/");
	while(1){
		if(inportb(0x60)!=250&&!(inportb(0x60)&0x80)){
			if(inportb(0x60)==0x1C){
				selectedop =1;
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

