void main() {
	// top left of the screen
	char* video_memory = (char*) 0xb8000;
	// at the video memory location, store X
	*video_memory = 'X';
}
