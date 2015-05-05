#include "../dt/isr.h"
#include "key_queue.c"
int lshiftkey = 0;
int rshiftkey = 0;
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

unsigned char caps_key_scan[] = {
                0, 27,'1','2','3','4','5','6','7','8','9','0','-','=','\b','\t',
                'Q','W','E','R','T','Y','U','I','O','P','[',']','\n',
                0, //29 control
                'A','S','D','F','G','H','J','K','L',';','\'','`',0, //left shift
                '\\','Z','X','C','V','B','N','M',',','.','/', 0, //right shift
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



/* Handles the keyboard interrupt */
static void keyboard_handler(registers_t regs)
{
    unsigned char scancode;

    /* Read from the keyboard's data buffer */
    scancode = inb(0x60);
    /*printint(scancode);
	printchar(' ');
	return;

    /* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if (scancode & 0x80)
    {
        /* You can use this one to see if the user released the
        *  shift, alt, or control keys... */
	if(scancode==0x80+42) lshiftkey = 0;
	else if(scancode==0x80+54) rshiftkey = 0;
	else if(scancode==0x80+29) ctrkey = 0;
	else if(scancode==0x80+56) optkey = 0;
    }
    else
    {
        /* Here, a key was just pressed. Please note that if you
        *  hold a key down, you will get repeated key press
        *  interrupts. */

        /* Just to show you how this works, we simply translate
        *  the keyboard scancode into an ASCII value, and then
        *  display it to the screen. You can get creative and
        *  use some flags to see if a shift is pressed and use a
        *  different layout, or you can add another 128 entries
        *  to the above layout to correspond to 'shift' being
        *  held. If shift is held using the larger lookup table,
        *  you would add 128 to the scancode when you look for it */
        //putch(kbdus[scancode]);
	if(scancode==42) lshiftkey = 1;
	else if(scancode==54) rshiftkey = 1;
	else if(scancode==29) ctrkey = 1;
	else if(scancode==56) optkey = 1;
	else if(scancode==58) capslock = (capslock+1)%5;
	else {
		if(lshiftkey||rshiftkey) 	add_key(scancode,shift_key_scan[scancode]);
		else if(capslock) 		add_key(scancode,caps_key_scan[scancode]);
		else				add_key(scancode,key_scan[scancode]);
	}
    }
}

void keyboard_install()
{
    register_interrupt_handler(IRQ1, &keyboard_handler);
}
