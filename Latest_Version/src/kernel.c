#include "C_files/Globals.c"
#include "C_files/video.c"
#include "C_files/builtin.c"
#include "C_files/keyboard.c"

void loadWelcome();
void typePrompt();
void readCommand();
char* nextLine();
char inputLine[50] = {0};
void main() {
	setup();
	loadWelcome();
	while(TRUE){
		typePrompt();
		readCommand();
//		executeCommand();
	}
}

void loadWelcome(){
	println("Welcome to THOS!");
}

void typePrompt(){
	print("# ");
}

void readCommand(){
	char* input = nextLine();
	print("\n");
	print("---Your input was ");
	print(input);
	println("---");
	//int command = getCommand(input);
	//char* param = getParam(input);
}

char* nextLine(){
	int start = OFFSET;
	while(TRUE){
		if(inportb(0x60)==250) continue;
		if(inportb(0x60)&0x80) continue;
		char next = getchar();
		if(next=='\n') break;
		else printchar(next);
	}
	int last = OFFSET;
	int length = (last-start)/2;
	
	int i;
	for(i=0; i<length; i++){
		inputLine[i]= vidmem[start+i*2];
	}
	inputLine[length] = 0;
	return inputLine;
	
}
/*void main() {
	CURRENTBACK = LIGHTBLUE;
	setup();
	loadHello();
	loadMenu();
	while(TRUE){
		if(inportb(0x60)!=250){ 
			if((inportb(0x60)&0x80)){
				if(inportb(0x60)==0xAA||inportb(0x60)==0xFA) shiftkey =0;
				continue;
			}
			if(inportb(0x60)==0x1C){
				runinput();
				loadMenu();
				continue;
			}
			char next =getchar();
			if(next!=0) printchar(next);
//			CURRENTBACK+=0x10;
//			setup();
		}
	}
	for(;;);
}
*/
