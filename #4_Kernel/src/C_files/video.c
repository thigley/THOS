#include "video.h"

void setup(){
	CURRENTCOLOR = WHITE;
	vidmem = (char*) VIDEO_ADDRESS;
	OFFSET =0;
	clear();
	OFFSET = 0;
}
void clear(){
	int i;
	for(i = 0; i<W*H*2; i++){
		vidmem[OFFSET++] = ' ';
		vidmem[OFFSET++] = CURRENTCOLOR;
	}
}
void printchar(char x){
	vidmem[OFFSET++] = x;
	vidmem[OFFSET++] = CURRENTCOLOR;
}
void print(char* str){
        while(*str!='\0'){
                printchar(*str);
                *str++;
        }

}
void println(char* str){
	print(str);
	printchar(' ');
	while(OFFSET%(W*2)!=0){
		printchar(' ');
	}
}

