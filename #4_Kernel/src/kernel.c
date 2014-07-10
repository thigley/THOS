#include "C_files/video.c"
void main() {
	// top left of the screen
	setup();
	clear();
	setup();
	
	char* kernel_string = "Successfully landed in Kernel!";
	
	while(*kernel_string!='\0'){
		*video_memory++ = *kernel_string;
		*kernel_string++;
		*video_memory++ = LIGHTGREEN;
	}

	for(;;);
}
