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
	for(i = 0; i<W*H; i++){
		vidmem[OFFSET++] = ' ';
		vidmem[OFFSET++] = makecolor();
	}
}

int makecolor(){
	return(CURRENTBACK<<4) + CURRENTCOLOR;
}

void printchar(char x){
	if(x=='\b'){
		OFFSET-=2;
		vidmem[OFFSET] = ' ';
		return;
	}else if(x=='\n'){
		newline();
		return;
	}else if(x=='\t'){
		OFFSET+=8;
		return;
	}

	vidmem[OFFSET++] = x;
	vidmem[OFFSET++] = makecolor();
}
void print(char* str){
        while(*str!='\0'){
                printchar(*str);
                *str++;
        }

}
void println(char* str){
	print(str);
	newline();
}
void newline(){
	OFFSET+=2;
	while(OFFSET%(W*2)!=0){
                OFFSET+=2;
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
