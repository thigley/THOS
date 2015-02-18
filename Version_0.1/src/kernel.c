/* kernel.c */

// Includes
#include "include/Misc.c"
#include "include/Interface.c"
#include "include/Filesystem.c"
#include "include/Programs.c"

void kmain(void)
{
	initfs();
	createfile("test","this is a test");
	shell();
	return;
}

