#define TRUE 1
#define FALSE 0

#include "C_files/video.c"
#include "C_files/keyboard.c"
#include "C_files/builtin.c"

void main() {
	screen_setup();
	loadWelcome();
	while(TRUE){
		typePrompt();
		readCommand();
//		executeCommand();
	}
}

