#include "../../common.h"

int shiftkey = 0;
int ctrkey = 0;
int optkey = 0;
int capslock = 0;

unsigned char key_scan[] = {
                0, 27,'1','2','3','4','5','6','7','8','9','0','-','=','\b','\t',
                'q','w','e','r','t','y','u','i','o','p','[',']','\n',
                0, //29 control
                'a','s','d','f','g','h','j','k','l',';','\'','`',0, //left shift
                '\\','z','x','c','v','b','n','m',',','.','/', 0, //right shift
                '*',
                0, //alt
                ' ', //space
                0, //caps lock
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//f1-f10
                0, //num lock
                0, //scroll lock
                0, //home
                0, //up
                0, //page up
                '-',
                0, //left
                0,
                0, //right
                '+',
                0, //end
                0, //down
                0, //page down
                0, //insert
                0, //delete
                0, 0, 0,
                0, 0,  //f11-12
                0, //all else undifined
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0       
 };
	unsigned char shift_key_scan[] = {
                0, 27,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t',
                'Q','W','E','R','T','Y','U','I','O','P','{','}','\n',
                0, //29 control
                'A','S','D','F','G','H','J','K','L',':','\"','~',0, //left shift
                '|','Z','X','C','V','B','N','M','<','>','?', 0, //right shift
                '*',
                0, //alt
                ' ', //space
                0, //caps lock
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//f1-f10
                0, //num lock
                0, //scroll lock
                0, //home
                0, //up
                0, //page up
                '-',
                0, //left
                0,
                0, //right
                '+',
                0, //end
                0, //down
                0, //page down
                0, //insert
                0, //delete
                0, 0, 0,
                0, 0,  //f11-12
                0, //all else undifined
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0
 };

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
}
