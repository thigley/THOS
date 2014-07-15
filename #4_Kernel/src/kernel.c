#include "C_files/video.c"
#include "C_files/builtin.c"
#include "C_files/keyboard.c"

void main() {
	setup();
	loadHello();
	loadMenu();
		
	while(1){
		if(inportb(0x60)!=250&&!(inportb(0x60)&0x80)){
			printchar(getchar());
		}
	}
	for(;;);
}

