/* kernel.c */

// Includes
#include "include/keyboard/key_queue.h"
#include "include/filesystem/structs.h"
FileSystem filesystem;
#include "include/Misc.c"
#include "include/Interface.c"
#include "include/filesystem/fs_methods.c"
#include "include/Programs.c"
#include "include/keyboard/keyboard.c"


int kmain(/*struct multiboot *mboot_ptr*/)
{
	init_descriptor_tables();
	keyboard_install();
	
	initfs();

	shell();
	return 0xDEADBADA;
}

