#include "C_files/video.c"
#include "C_files/builtin.c"

void main() {
	setup();
	loadHello();
	loadMenu();
	int i = 0;
//	while(i<100){
//		CURRENTCOLOR = GREEN;
//		printhex(i++);
//		printchar(inb(0x60));
//	}

//register unsigned int iax __asm__("ax");
//unsigned int i_ax;

	while(inportb(0x60)==250);
		
while(1){
	printint(inportb(0x60));
	printchar(' ');
}
	for(;;);
}

int inportb(unsigned int port){
        unsigned char ret;

        asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
	return ret;
}
