/* kernel.c */

// Includes
#include "key_queue.h"
#include "include/filesystem/structs.h"
FileSystem filesystem;
#include "include/Misc.c"
#include "include/Interface.c"
#include "include/Filesystem.c"
#include "include/Programs.c"
#include "keyboard.c"

void testFiles(){
	createfile("test","this is a test");
	createfilefull("long_test","This test will be considerably longer than the others. The reason for this is to test the filesystems ability to use multiple blocks. In 'test', all of the data fit into a single block so we weren't able to really see if the system was working. In contrast, this file is long enough (more than 512 bytes) that it will need to be stored in multiple blocks. This will not only test it's own ability to store longer files, but also make sure that the next file has no issues caused by side effects of this longer file.",543,1,1);
	createfilefull("final_test","Boo! I'm a ghost!!!! Fear me! Muhahahaha!",777,0,1);
}
int kmain(struct multiboot *mboot_ptr)
{
	
	init_descriptor_tables();
	asm volatile ("sti");
	keyboard_install();
	clearScreen();
	
	//for(;;);
	
	initfs();
	testFiles();
	shell();
	return 0xDEADBABA;
}

