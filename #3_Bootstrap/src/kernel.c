void main() {
	// top left of the screen
	char* video_memory = (char*) 0xb8000;
	
	char* kernel_string = "Successfully landed in Kernel!";
	
// at the video memory location, store X
	int i;
	for(i =0; i <4*80*2; i++){
		*video_memory++;
	}
	for(i = 0; i < 30; i++){
		*video_memory++ = *kernel_string;
		*kernel_string++;
		*video_memory++ = 0xA;
	}

	for(;;);
}
