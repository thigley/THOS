#include "../../common.h"

u8int inb(u16int port){
	unsigned char ret;
	asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
	return ret;
}

u16int inw(u16int port){
	u16int ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void outb(u16int port, u8int value){
	asm volatile ("outb %%al,%%dx": :"d" (port), "a" (value));
}
/*
unsigned char getchar(){
	int code = inb(0x60);
	if(code == 0x36 || code == 0x2A) shiftkey=1;
	if(code == 0x3A) capslock = (capslock+1)%2;
	char ret = (shiftkey==0) ? key_scan[code] : shift_key_scan[code];
	outb(0x60, 250);

	return ret;
}

int newInput(){
	if(inb(0x60)==250) return 0;
	if(inb(0x60)&0x80){ 
		if(inb(0x60)==0xAA||inb(0x60)==0xFA){ 
			shiftkey =0;
		} 
		return 0;
	}
	return 1;
}*/
