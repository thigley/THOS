#include "C_files/video.c"
#include "C_files/builtin.c"

void main() {
	setup();
	loadHello();
	loadMenu();
	for(;;){
		CURRENTCOLOR = GREEN;
		print(" 0 1");
	}
}
