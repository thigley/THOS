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
void printint(int input){
	char* output = "00000";
	output+=4;
	int i;
	for(i = 1; i < 5; i++){
		*output = '0'+ input%10;
		input/=10;
		output--;
	}
	while(*output=='0'&&i-->1){
		output++;
	}
	print(output);
}
void printhex(int input){
	char* output = "0x0000";
	output+=5;
	int i;
        for(i = 1; i < 4; i++){
                *output = '0'+ input%16;
		if(*output>'9'){
			*output-='0';
			*output%=10;
			*output+='A';
		}
                input/=16;
                output--;
        }
        output-=2;
        print(output);
}
