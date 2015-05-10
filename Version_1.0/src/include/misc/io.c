/* io.c */

#include "../common.h"

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

