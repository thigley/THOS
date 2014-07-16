int inportb(unsigned int);
void ourportb(unsigned int, unsigned char);
unsigned char getchar();

int inportb(unsigned int port){
        unsigned char ret;

        asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
        return ret;
}

void outportb(unsigned int port, unsigned char value){
	asm volatile ("outb %%al,%%dx": :"d" (port), "a" (value));
}

unsigned char getchar(){
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

	char ret = key_scan[inportb(0x60)];
	outportb(0x60, 250);
	return ret;
}

